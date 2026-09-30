#!/usr/bin/env python3
"""Extract the ROM's data assets from baserom.gba into build/assets/.

Each assets/*.json file lists assets as {"path", "start", "size"} plus an
optional "type" and "options" (zeldaret/tmc's format, with "start" written
as a ROM address). The asm pulls each file in with `.incbin`, so the game's
data stays out of git and a build needs your own baserom.gba.

`extract` copies each asset's raw bytes to build/assets/PATH. They keep the
.bin name: they're the GBA's own formats (m4a song bytecode, PCM samples
with their header, RL/LZ77 graphics streams), not MIDI, AIFF or PNG yet.
It skips "midi" songs and "aif" samples: the build makes those from their
editable files. A "screen", "tiles", "bitmap" or "pal" it builds from
its editable .png or .pal the same way (see below), after unpacking that
file when it's missing.

`unpack FILE` writes one song's or one sample's editable file: assets/PATH
with .mid (agb2mid) or .aif (aif2pcm) in place of .bin. The editable files
are the sound's source. `make` unpacks a file only when it's missing, and
`unpack` never overwrites one, so your edits survive every build. They stay
out of git (.gitignore), since the ROM's data is copyrighted.

`song MID OUT` turns a song's .mid into the assembly that
data/sound/sounds.s includes in place: mid2agb with the song's options from assets/*.json, so
the song's pointers resolve where it links. `make` turns a sample's .aif
back into its .bin with aif2pcm alone.

`list` prints the editable file of every song, sample, picture and
palette.

A "screen" asset is one full-screen 240x160 background: an editable
indexed .png (256 colours) that `unpack` writes from the ROM only when
it's missing. `extract` builds the ROM's four blobs from the .png alone,
in the layout the ROM stores them: the 256-colour palette, the 15x10
metatile map, the metatile table (four tile indices per 2x2 metatile,
top-left, top-right, bottom-left, bottom-right) and the 8bpp tiles. The
converter is the original tool's algorithm: scan the 2x2 metatiles row
by row, give each new metatile the next metatile index and each new 8x8
tile within it the next tile index, with no flips and no palette bits.
The PNG must stay indexed with all 256 palette entries: its palette
order is the ROM's. `options` carries the ROM's metatile and tile
counts. An edit that changes them resizes the table and tiles, and the
rest of the ROM moves by a multiple of 4 bytes; the loaders copy 650
tiles' worth whatever the count, and a screen needs at most 600.
`"sharedTable": true` marks the four screens that DrawBackdropMetatileMap
draws through gSharedMetatileTileTable (tile N at N) instead of their own
table: those must keep all 600 tiles unique.

A "pal" asset is one palette blob as an editable JASC .pal text file
(assets/graphics/palettes/NAME.pal, the format graphics editors call
"Microsoft Palette"): one `R G B` line per colour, in the ROM's order.
`unpack` writes it from the ROM only when it's missing; `extract` reads
it back into the BGR555 halfwords the ROM holds. The colour count is
the blob's, so adding or removing a line fails the build. A few ROM
colours set the GBA's unused bit 15, which no .pal line can hold:
`options {"bit15": [INDEX, ...]}` lists them, and `extract` sets the bit
on those colours again, whatever their edited value.

A "tiles" asset is one uncompressed tile sheet as an editable indexed
.png (assets/graphics/tiles/NAME.png): the tiles in reading order,
`width` tiles to a row, `bitDepth` 4 or 8, coloured by the pal asset
its `palette` option names (the .png is only a picture of the sheet;
the palette itself is edited in that .pal file). A ragged last row is
padded with blank tiles (colour 0). `maxTiles` is how many tiles the
game's loader copies (256 for the three sheets it's set on): painting a
new tile into the padding, or into rows added below, grows the sheet up
to that many and moves the rest of the ROM. Without it, the padding must
stay blank.

A "bitmap" asset is a full-screen mode-4 background (240x160, 8bpp
linear pixels, 256 colours) whose gfx the ROM stores as one RL stream:
ShowBootSplash2 and ShowBootSplash3 draw the two there are. `unpack`
decompresses the stream into the editable .png; `extract` recompresses
the picture with the original tool's RL algorithm. A shorter stream is
zero-padded to the ROM's slot, as the BIOS never reads past the size in
its header. A bigger one grows the slot in whole words and moves the
rest of the ROM, which the shiftable build allows (`make shift-test`);
the build then no longer matches, as with any edit.
The picture's palette is the 512 bytes before the stream and stays a
separate "pal" asset: the .png's colours are a preview.

A "copy" asset is one blob of the high module (or island) that the ROM
also holds in the main program: its data/*.s fragment `.incbin`s the
original's build output directly, with an offset and length when the
module holds a slice of it, and `.space` for the zero padding between
two blobs. One edit to a shared file changes both GBAs; there is
nothing to extract — the entry exists to mask its range and to
zero-fill it in CI. Its `options.sources` list records the chain
(path, or path@offset@length, or null for padding) for the reader.

A "track" asset is one blob of a racing track's map data (12 tracks,
0x0807CE30-0x0829EAE0 plus the high module's track-7 copy), built from
the editable files in its folder, assets/tracks/NAME/ (NAME from the
track's text: hooley_downs ... infogrames_super_speedway):
NAME.tmx holds the three RLE map layers as CSV (A = BG3's metatile map,
B = BG2's, cells = the collision cell map, each layer its own size);
tiles_0.png and tiles_2.png are the two char blocks' 4bpp tile sheets,
indexed pictures of the track's whole 256-colour palette (a 4bpp tile
paints with one 16-colour bank, and the palette blob builds from
tiles_0.png's — the two sheets must keep it equal); metatiles_a,
metatiles_b and surfaces are the metatile tables and the surface table,
kept as the binary data they are (entries carry flips and palette banks
no picture can regenerate). `unpack` writes the folder's files only when
missing; the tileset .pngs the .tmx points at are previews it redraws.
At build time each map layer re-encodes with the ROM's own RLE (the
encoder every one of the 35 streams round-trips through), the stream
lengths land in gTrackData through the .len files it INCBINs, and the
module's raw track-7 maps build from the same .tmx, so one edit changes
both GBAs. A layer's rectangle is its stride x ceil(count/stride); the
cells past the ROM's recorded count are display-only padding, and the
dead tail bytes a few blobs hold past their stream (non-zero on three)
follow the stream as metadata. LoadTrackTiles copies fixed 0x8000/0x4000
bytes and over-reads into the following blobs on many tracks, so the
part files keep the ROM's blob order.

The same folders hold each track's GEOMETRY (the lanes, waypoints and
walls of issue #4 part 2): three object layers in the .tmx (lanes as
polylines per distinct lane, walls as one polyline per wall chain with
its per-record steerAngle bytes as a "steer" property, waypoints as
2-point lines with "kind"/"countdown"), the binary side files
scripts/track_geometry.py documents (wall_cells, lane_cells_N,
lane_terms, lane_fixups, lane_lengths, lane_orphan_N), and the
derivations that module verifies against the ROM at build inputs: the
WallRec normals, AABBs and angle bytes, and the LaneSeg chain and
distance arithmetic regenerate from the object layers; the spatial
indexes do not (their membership rule was never recovered) and stay
binary.

A "gen" asset's bytes come from a script, not the ROM:
`options.generator` names a host script that `extract` and `blank`
both run (usage `SCRIPT OUT.bin`). It needs no baserom.gba, so CI
builds the real bytes, and `mask` leaves its range unmasked —
`make check-code` then holds the generator to the committed hash, and
a host library that computes one byte differently fails the build.

`convert` writes an editable .png next to each "rl"/"lz" graphics .bin
(gbagfx), then converts it back and checks that the result matches the
.bin byte for byte. It needs the tools from `make tools`; `make convert`
builds them and runs this.

Without a palette the PNGs are greyscale: gbagfx maps a color index to
255-index both ways, so the round trip is exact without knowing the
palette. Its width is in 8-pixel tiles and must divide the tile count
exactly, or the PNG grows a partial row of padding tiles that convert back
to extra bytes. `options` carries "bitDepth" (4 or 8) and "width" (tiles);
without them convert picks 4bpp and the widest width up to 16 tiles that
divides. "palette" is the ROM address of a GBA palette for the PNG,
"bitmap" marks linear (mode 3-5) pixels, and "overrun" is how far the
stream's last run writes past its size (see convert_graphics).
`options {"raw": true}` keeps a stream as .bin only: the blob at
0x080C0000 came from a weaker compressor than gbagfx's, so it has no
round-trip to check.

`blank` writes each asset as zero fill of its listed size, for a build with
no baserom.gba (CI); a song's assembly becomes a `.space` of that size,
with the song's label at its header. The
code still links at its real addresses, and `mask` zeroes the same ranges
in any ROM, so `make check-code` can compare the build against the retail
ROM's code without the ROM being present.

Usage:
    python3 scripts/assets.py extract
    python3 scripts/assets.py unpack FILE
    python3 scripts/assets.py song MID OUT
    python3 scripts/assets.py list
    python3 scripts/assets.py blank
    python3 scripts/assets.py convert
    python3 scripts/assets.py mask ROM_IN ROM_OUT
"""

import json
import struct
import subprocess
import sys
import tempfile
import zlib
from pathlib import Path

# the lane/wall/waypoint derivations live beside this file; assets.py
# drives the pack/unpack, track_geometry holds the byte-exact formulas
sys.path.insert(0, str(Path(__file__).resolve().parent))
import track_geometry as geo

ROOT = Path(__file__).resolve().parent.parent
ROM_BASE = 0x08000000
BASEROM = ROOT / "baserom.gba"
OUT = ROOT / "build" / "assets"
EDIT = ROOT / "assets"
TOOLS = ROOT / "tools" / "bin"
# Asset types the build makes from an editable file, and that file's suffix.
EDITABLE = {"midi": ".mid", "aif": ".aif", "screen": ".png", "pal": ".pal",
            "tiles": ".png", "bitmap": ".png"}
# Every "screen" is a 240x160 background: 15x10 metatiles of 2x2 8x8 tiles.
SCREEN_W, SCREEN_H = 240, 160


def assets():
    """Every asset entry. A config file is a list of entries, except the
    one that also carries per-track layout metadata (assets/tracks.json),
    which is a dict with the entries under "assets" and the metadata under
    "tracks" (see tracks_meta)."""
    for config in sorted((ROOT / "assets").glob("*.json")):
        data = json.loads(config.read_text())
        yield from data["assets"] if isinstance(data, dict) else data


def tracks_meta():
    """{folder name: track metadata} from the dict-shaped asset config.
    Each track's metadata names it, sizes its three map layers (the
    stride and cell count the .tmx layer holds, the ROM blob's size and
    halfword length, the dead tail bytes past the stream, and the true
    final entry where the module's raw maps carry it), and caps its two
    tile sheets at what LoadTrackTiles copies."""
    out = {}
    for config in sorted((ROOT / "assets").glob("*.json")):
        data = json.loads(config.read_text())
        if isinstance(data, dict):
            out.update(data.get("tracks", {}))
    return out


def track_entries():
    """{track folder: {part: asset entry}} for every "track" asset."""
    groups = {}
    for asset in assets():
        if asset.get("type") == "track":
            opts = asset["options"]
            groups.setdefault(opts["track"], {})[opts["part"]] = asset
    return groups


def run(*cmd):
    done = subprocess.run([str(c) for c in cmd], capture_output=True, text=True)
    if done.returncode:
        sys.exit(f"{' '.join(map(str, cmd))}\n{done.stdout}{done.stderr}")


def editable(asset):
    return EDIT / Path(asset["path"]).with_suffix(EDITABLE[asset["type"]])


def built(asset):
    """The file under build/assets/ that data/*.s includes for the asset."""
    path = OUT / asset["path"]
    if asset.get("type") == "midi":
        return path.with_suffix(".s")
    if asset.get("type") == "pal":
        return path.with_suffix(".pal.bin")
    return path.with_suffix(".tiles.bin") if asset.get("type") == "tiles" else path


def find(path):
    """The asset whose editable file is `path`."""
    path = Path(path).resolve()
    for asset in assets():
        if asset.get("type") in EDITABLE and editable(asset) == path:
            return asset
    sys.exit(f"{path}: no asset in assets/*.json has this editable file")


def screen_part(asset, part):
    """One of a screen's blobs under build/assets/ ("pal", "map", "table"
    or "tiles"), built from the .png whatever its edit."""
    return (OUT / asset["path"]).with_suffix(f".{part}.bin")


def screen_blob_sizes(asset):
    """Each blob's size: a 512-byte palette, a 15x10 u16 map, a u16[4]
    table row per metatile, 64 bytes per 8bpp tile, and optionally the
    dead bytes the ROM holds past the tiles (the Licensed By Nintendo
    screen's 32) — the one part the picture cannot rebuild, so `extract`
    copies it from the ROM."""
    opts = asset["options"]
    sizes = {"pal": 512, "map": 2 * 150,
             "table": 8 * opts["metatiles"], "tiles": 64 * opts["tiles"]}
    if opts.get("tail"):
        sizes["tail"] = opts["tail"]
    return sizes


def screen_blobs(asset, rom):
    """A screen's four blobs straight out of the ROM."""
    start = int(asset["start"], 16) - ROM_BASE
    sizes = screen_blob_sizes(asset)
    pal, map_ = rom[start:start + 512], rom[start + 512:start + 812]
    mid = start + 512 + sizes["map"]
    table = rom[mid:mid + sizes["table"]]
    tiles = rom[mid + sizes["table"]:mid + sizes["table"] + sizes["tiles"]]
    return {"pal": pal, "map": map_, "table": table, "tiles": tiles}


def compose_screen(blobs):
    """The 240x160 picture a screen's map, table and tiles draw."""
    map_, table, tiles = blobs["map"], blobs["table"], blobs["tiles"]
    px = bytearray(SCREEN_W * SCREEN_H)
    for i in range(150):
        metatile = struct.unpack_from("<H", map_, 2 * i)[0]
        for s in range(4):  # top-left, top-right, bottom-left, bottom-right
            sx = (i % 15) * 16 + (s & 1) * 8
            sy = (i // 15) * 16 + (s >> 1) * 8
            tile = struct.unpack_from("<H", table, 8 * metatile + 2 * s)[0]
            for y in range(8):
                row = (sy + y) * SCREEN_W + sx
                src = 64 * tile + 8 * y
                px[row:row + 8] = tiles[src:src + 8]
    return bytes(px)


def split_screen(pixels, palette):
    """The converter the original tool ran, in reverse: the palette, map,
    table and tiles the ROM holds, rebuilt from the picture alone. Scan the
    2x2 metatiles row by row; give each new metatile the next metatile
    index, and each new tile within it the next tile index."""
    map_, table, tiles = bytearray(300), bytearray(), bytearray()
    metatiles, tile_ids = {}, {}
    for i in range(150):
        cell = []
        for s in range(4):
            sx = (i % 15) * 16 + (s & 1) * 8
            sy = (i // 15) * 16 + (s >> 1) * 8
            pat = b"".join(pixels[(sy + y) * SCREEN_W + sx:
                                  (sy + y) * SCREEN_W + sx + 8]
                           for y in range(8))
            if pat not in tile_ids:
                tile_ids[pat] = len(tile_ids)
                tiles += pat
            cell.append(tile_ids[pat])
        if tuple(cell) not in metatiles:
            metatiles[tuple(cell)] = len(metatiles)
            table += struct.pack("<4H", *cell)
        struct.pack_into("<H", map_, 2 * i, metatiles[tuple(cell)])
    return {"pal": palette, "map": bytes(map_), "table": bytes(table),
            "tiles": bytes(tiles)}


def png_chunk(tag, data):
    return (len(data).to_bytes(4, "big") + tag + data
            + (zlib.crc32(tag + data) & 0xFFFFFFFF).to_bytes(4, "big"))


def bgr555_to_rgb8(color):
    """A GBA palette entry as the 8-bit RGB a PNG holds it."""
    def up(v):
        return v << 3 | v >> 2
    return up(color & 31), up(color >> 5 & 31), up(color >> 10 & 31)


def write_indexed_png(path, pixels, w, h, palette):
    """Write an 8-bit indexed PNG: `pixels` are palette indices, the
    palette BGR555 halfwords in the PNG's order."""
    plte = bytearray()
    for color in struct.unpack(f"<{len(palette) // 2}H", palette):
        plte += bytes(bgr555_to_rgb8(color))
    rows = b"".join(b"\0" + pixels[y * w:(y + 1) * w] for y in range(h))
    path.write_bytes(b"\x89PNG\r\n\x1a\n"
                     + png_chunk(b"IHDR", struct.pack(">IIBBBBB",
                                                      w, h, 8, 3, 0, 0, 0))
                     + png_chunk(b"PLTE", bytes(plte))
                     + png_chunk(b"IDAT", zlib.compress(rows, 9))
                     + png_chunk(b"IEND", b""))


def read_indexed_png(path, w, h, colors):
    """Read an indexed PNG of exactly w*h pixels (any height when h is
    None) with `colors` palette entries: (linear indices, BGR555 palette). Only what an editor keeps
    of an indexed PNG: 1, 2, 4 or 8-bit indices (editors save a
    16-colour picture at 4 bits), every palette entry, no interlacing."""
    data = path.read_bytes()
    if data[:8] != b"\x89PNG\r\n\x1a\n":
        sys.exit(f"{path}: not a PNG")
    chunks, pos = {}, 8
    while pos + 12 <= len(data):
        length = int.from_bytes(data[pos:pos + 4], "big")
        tag, body = data[pos + 4:pos + 8], data[pos + 8:pos + 8 + length]
        pos += 12 + length
        if tag == b"IDAT":
            chunks.setdefault(b"IDAT", []).append(body)
        elif tag not in chunks:
            chunks[tag] = body
        if tag == b"IEND":
            break
    width, height, depth, color, _, _, interlace = \
        struct.unpack(">IIBBBBB", chunks[b"IHDR"])
    plte = chunks.get(b"PLTE", b"")
    if width != w or height != (h or height):
        sys.exit(f"{path}: {width}x{height}, want {w}x{h or height}")
    h = height
    if color != 3 or depth not in (1, 2, 4, 8):
        sys.exit(f"{path}: want an indexed PNG (save it in indexed mode):\n"
                 "its palette order is the ROM's")
    if interlace:
        sys.exit(f"{path}: interlaced; save it without interlacing")
    if len(plte) != 3 * colors:
        sys.exit(f"{path}: {len(plte) // 3} palette entries, want {colors}\n"
                 "(an editor trimmed the unused tail; keep every entry)")
    packed = zlib.decompress(b"".join(chunks[b"IDAT"]))
    stride = (w * depth + 7) // 8
    pixels, prev = bytearray(w * h), bytearray(stride)
    pos = 0
    for y in range(h):
        # Undo the per-row filter, whatever the editor chose (RFC 2083).
        # An indexed pixel is at most one byte, so filters work bytewise.
        filter_, row = packed[pos], bytearray(packed[pos + 1:pos + 1 + stride])
        pos += 1 + stride
        if filter_ > 4:
            sys.exit(f"{path}: bad PNG row filter {filter_}")
        for x in range(stride):
            a, b, c = row[x - 1] if x else 0, prev[x], prev[x - 1] if x else 0
            if filter_ == 1:
                row[x] = (row[x] + a) & 0xFF
            elif filter_ == 2:
                row[x] = (row[x] + b) & 0xFF
            elif filter_ == 3:
                row[x] = (row[x] + (a + b) // 2) & 0xFF
            elif filter_ == 4:
                pa, pb, pc = abs(b - c), abs(a - c), abs(a + b - 2 * c)
                guess = a if pa <= pb and pa <= pc else (b if pb <= pc else c)
                row[x] = (row[x] + guess) & 0xFF
        prev = row
        if depth < 8:  # unpack the indices, leftmost pixel in the high bits
            mask = (1 << depth) - 1
            row = bytes(row[x * depth // 8] >> (8 - depth - x * depth % 8) & mask
                        for x in range(w))
        pixels[y * w:(y + 1) * w] = row
    palette = bytearray(2 * colors)
    for i in range(colors):
        r, g, b = plte[3 * i:3 * i + 3]
        struct.pack_into("<H", palette, 2 * i,
                         r >> 3 | (g >> 3) << 5 | (b >> 3) << 10)
    return bytes(pixels), bytes(palette)


def write_jasc_pal(path, palette):
    """Write a palette blob (BGR555 u16s) as a JASC .pal text file, the
    format every graphics editor's colour picker reads and writes."""
    colors = struct.unpack(f"<{len(palette) // 2}H", palette)
    lines = ["JASC-PAL", "0100", str(len(colors))]
    lines += [f"{r} {g} {b}" for r, g, b in map(bgr555_to_rgb8, colors)]
    path.write_text("\r\n".join(lines) + "\r\n")


def read_jasc_pal(path, size):
    """Read a JASC .pal back into BGR555 u16s, exactly `size` bytes."""
    lines = path.read_text().splitlines()
    try:
        count = int(lines[2].split()[0])
    except (IndexError, ValueError):
        sys.exit(f"{path}: not a JASC-PAL file (want JASC-PAL / 0100 / N)")
    colors, out = lines[3:], bytearray()
    if lines[0].strip() != "JASC-PAL" or lines[1].strip() != "0100" \
            or len(colors) != count:
        sys.exit(f"{path}: says {count} colors but has {len(colors)} lines")
    for line in colors:
        rgb = line.split()
        if len(rgb) != 3:
            sys.exit(f"{path}: '{line.strip()}' is not an R G B colour")
        r, g, b = (int(v) for v in rgb)
        if max(r, g, b) > 255:
            sys.exit(f"{path}: '{line.strip()}' is out of range")
        out += struct.pack("<H", r >> 3 | (g >> 3) << 5 | (b >> 3) << 10)
    if len(out) != size:
        sys.exit(f"{path}: {count} colors, the ROM holds {size // 2}")
    return bytes(out)


def write_screen_png(path, pixels, palette):
    """Write a screen's picture as an 8-bit indexed PNG: the palette order
    is the ROM's, so the file edits straight back into its blobs."""
    write_indexed_png(path, pixels, SCREEN_W, SCREEN_H, palette)


def read_screen_png(path):
    """Read a screen's picture back."""
    return read_indexed_png(path, SCREEN_W, SCREEN_H, 256)


def rl_decompress(data):
    """A BIOS RLUnCompVram stream: 0x30, the size, then packets. A flag
    with the high bit set repeats the next byte (flag&0x7F)+3 times; a
    clear flag copies that many literals plus one."""
    size = data[1] | data[2] << 8 | data[3] << 16
    out, pos = bytearray(), 4
    try:
        while len(out) < size:
            flag = data[pos]
            pos += 1
            if flag & 0x80:
                out += data[pos:pos + 1] * ((flag & 0x7F) + 3)
                pos += 1
            else:
                out += data[pos:pos + (flag & 0x7F) + 1]
                pos += (flag & 0x7F) + 1
    except IndexError:
        sys.exit("bad RL stream: packet runs past the end")
    return bytes(out[:size])


def rl_compress(src):
    """The original tool's RL compressor: literals until three equal
    bytes, then one run. 653 of the ROM's 672 streams are exactly this;
    the rest are the documented "overrun" and "raw" ones. No padding: the
    ROM's streams end where their last packet ends."""
    out = bytearray([0x30, len(src) & 0xFF, len(src) >> 8 & 0xFF,
                     len(src) >> 16])
    pos = 0
    while True:
        compress = False
        start, length = pos, 0
        while pos < len(src) and length < 0x80:
            compress = pos + 2 < len(src) \
                and src[pos] == src[pos + 1] == src[pos + 2]
            if compress:
                break
            pos += 1
            length += 1
        if length:
            out.append(length - 1)
            out += src[start:start + length]
        if compress:
            data, run = src[pos], 0
            while run < 0x82 and pos + run < len(src) and src[pos + run] == data:
                run += 1
            out.append(0x80 | (run - 3))
            out.append(data)
            pos += run
        if pos == len(src):
            return bytes(out)


def bitmap_part(asset):
    """A bitmap screen's blob: the RL stream of its 240x160 8bpp picture.
    Its palette is a separate asset, which the .png only previews."""
    return (OUT / asset["path"]).with_suffix(".gfx.bin")


def build_bitmap(asset):
    """Build a bitmap screen's stream from its editable .png alone. A
    stream that fits the ROM's slot is zero-padded to it, so nothing
    moves; a bigger one grows the slot in whole words, so everything
    after it moves by a multiple of 4 and keeps its alignment."""
    png = editable(asset)
    pixels, _ = read_indexed_png(png, SCREEN_W, SCREEN_H, 256)
    stream = rl_compress(pixels)
    room = asset["size"]
    if len(stream) > room:
        room += -(-(len(stream) - room) // 4) * 4
    path = bitmap_part(asset)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(stream + bytes(room - len(stream)))


def unpack_bitmap(asset, rom, out):
    """Write a bitmap screen's editable .png: the RL stream decompressed
    to linear mode-4 pixels. The picture's palette is the 512 bytes
    before the stream, and only previews: the palette is its own "pal"
    asset."""
    start = int(asset["start"], 16) - ROM_BASE
    pixels = rl_decompress(rom[start:start + asset["size"]])
    write_indexed_png(out, pixels, SCREEN_W, SCREEN_H, rom[start - 512:start])


def tiles_layout(asset):
    """(depth, tiles per row, tile count) of a tiles sheet. The blob is
    8*depth bytes per tile: 32 at 4bpp, 64 at 8bpp."""
    opts = asset["options"]
    depth = opts.get("bitDepth", 4)
    return depth, opts["width"], asset["size"] // 8 // depth


# --- Track maps -----------------------------------------------------------

# A track's own blobs sit together in the ROM in an order the asset entry
# records (it varies by track), then the cell map and surface table of all
# 12 tracks follow as one run. The names here are the part names the build
# writes under build/assets/tracks/NAME/ and the editable files unpack
# writes under assets/tracks/NAME/: tiles_0.png (bg2Tiles, char block 0)
# and tiles_2.png (bg3Tiles, char block 2) carry the track's whole
# 256-colour palette; metatiles_a/metatiles_b are the layers' metatile
# tables and surfaces the surface table, kept as the binary data they are;
# NAME.tmx holds the three RLE map layers as CSV. A metatile is 32 bytes:
# 16 u16 tilemap entries (tile index, flips, palette bank) for a 4x4 block
# of 8x8 tiles, so a picture cannot regenerate the tables — they stay data.
TRACK_EDITABLE = ("tmx", "png", "png", "metatiles_a", "metatiles_b", "surfaces")


def rle16_values(data):
    """The map a track layer's RLE stream decodes to, as u16 values: what
    RleDecode16 writes, plus its final word when that word is a value it
    read but never wrote. A stream that ends on a run-count word instead
    makes the decoder write one extra copy of the run's value and read one
    word past the blob (never using it), so there the written values alone
    are the map. Either way the list re-encodes byte for byte (checked on
    all 35 streams)."""
    words = struct.unpack(f"<{len(data) // 2}H", data)
    out, prev, i = [], 0xFFFF, 0
    value = words[i]
    i += 1
    while i < len(words):
        out.append(value)
        if value == prev:
            out += [value] * words[i]
            i += 1
            if i == len(words):
                return out
        prev = value
        value = words[i]
        i += 1
    return out + [words[-1]]


def rle16_encode(values):
    """The encoder the ROM's streams came from (verified against all 35):
    write each value; when one equals the value before it, the next word
    counts the extra copies. Runs cap at 0xFFFF extra copies."""
    out, prev, i = [], 0xFFFF, 0
    while i < len(values):
        v = values[i]
        out.append(v)
        i += 1
        if v == prev:
            j = i
            while j < len(values) and values[j] == v and j - i < 0xFFFF:
                j += 1
            out.append(j - i)
            i = j
        prev = v
    return struct.pack(f"<{len(out)}H", *out)


def unpack_4bpp(data):
    """A 4bpp tile blob as one pixel value (0-15) per byte."""
    return bytes(v for b in data for v in (b & 15, b >> 4))


def pack_4bpp(pixels):
    """Pixel values (0-15, two per byte) back into a 4bpp tile blob."""
    if any(v > 15 for v in pixels):
        sys.exit("a tile pixel is over colour 15: a 4bpp sheet holds "
                 "colours 0-15 only")
    return bytes(pixels[2 * i] | pixels[2 * i + 1] << 4
                 for i in range(len(pixels) // 2))


def track_sheet_size(count):
    """(width, height) of a track tile sheet's PNG: 16 tiles to a row."""
    rows = -(-count // 16)
    return 16 * 8, rows * 8


def unpack_track_tiles(out, blob, palette):
    """Write one char block's 4bpp tiles as an indexed .png: the tiles in
    reading order, 16 to a row, coloured by the track's whole palette
    (a 4bpp tile paints with one 16-colour bank of it, so the picture
    previews bank 0 and shows the rest of the palette for reference).
    A ragged last row is padded with blank tiles to fill the rectangle."""
    w, h = track_sheet_size(len(blob) // 32)
    px = unpack_4bpp(blob) + bytes(w * h - 2 * len(blob))
    write_indexed_png(out, px, w, h, palette)


def build_track_tiles(png, min_tiles=0):
    """Read a track tile sheet back into its 4bpp blob, up to its last
    non-blank tile (blank padding never reaches the ROM; `min_tiles` is
    the ROM slot's tile count, so a round trip of the retail sheet keeps
    its ragged size). LoadTrackTiles copies a fixed 0x8000/0x4000 bytes,
    and the ROM's own sheets run past that (track 1's bg3Tiles holds 519
    tiles against a 512-tile copy), so growth past the slot is allowed:
    it moves the rest of the ROM, as any edit does."""
    px, palette = read_indexed_png(png, 16 * 8, None, 256)
    if len(px) % 64 or (len(px) // 8) % 16:
        sys.exit(f"{png}: the width must stay 16 tiles (128 pixels) and "
                 "the height a multiple of 8 pixels")
    used = max(1 + max((i for i in range(len(px) // 64)
                        if any(px[i * 64:(i + 1) * 64])), default=-1), 0)
    used = max(used, min_tiles)
    return pack_4bpp(px[:64 * used]), palette


def metatile_entries(blob):
    """A metatile table as one 16-entry list per metatile (u16 tilemap
    entries: tile index, flips, palette bank)."""
    return [struct.unpack_from("<16H", blob, 32 * i)
            for i in range(len(blob) // 32)]


def render_metatile_sheet(metatiles, tiles, palette, columns=16):
    """A metatile table as an indexed .png for viewing in the track's
    .tmx: metatile n at (n % columns, n // columns), each drawn from its
    16 tilemap entries over the layer's 4bpp tiles and the track palette.
    The build never reads this picture back; metatiles_a/metatiles_b are
    the data."""
    pixels_ = unpack_4bpp(tiles)
    count = len(metatiles)
    w, h = columns * 32, -(-count // columns) * 32
    px = bytearray(w * h)
    for m, entries in enumerate(metatiles):
        mx, my = (m % columns) * 32, (m // columns) * 32
        for s, entry in enumerate(entries):
            tile, bank = entry & 0x3FF, entry >> 12 & 15
            flip_x, flip_y = entry & 0x400, entry & 0x800
            sx, sy = mx + (s % 4) * 8, my + (s // 4) * 8
            for y in range(8):
                row = pixels_[tile * 64:(tile + 1) * 64][y * 8:y * 8 + 8]
                if flip_x:
                    row = row[::-1]
                dy = 7 - y if flip_y else y
                off = (sy + dy) * w + sx
                px[off:off + 8] = bytes(min(v + bank * 16, 255) for v in row)
    return bytes(px), w, h, palette


def write_tmx(path, name, layers, tilesets, objects=()):
    """The track's editable Tiled map: one CSV layer per entry of `layers`
    (name, tileset, values, width, height; row-major, `width` to a row —
    each layer carries its own size, the cell map is taller than the
    visual layers) and one tileset per entry of `tilesets` (name, tile
    count, image). The tileset images are the previews
    render_metatile_sheet draws; Tiled only displays them."""
    width, height = layers[0][3], layers[0][4]
    # Tiled numbers layers and object groups from one counter and objects
    # from another, map-wide: the next free ids follow them
    nobjects = sum(len(objs) for _, objs in objects)
    lines = ['<?xml version="1.0" encoding="UTF-8"?>',
             f'<map version="1.10" orientation="orthogonal" '
             f'renderorder="right-down" width="{width}" height="{height}" '
             f'tilewidth="32" tileheight="32" infinite="0" '
             f'nextlayerid="{len(layers) + len(objects) + 1}" '
             f'nextobjectid="{nobjects + 1}">']
    first = 1
    for tname, count, image in tilesets:
        lines.append(f' <tileset firstgid="{first}" name="{tname}" '
                     f'tilewidth="32" tileheight="32" tilecount="{count}" '
                     f'columns="16">')
        lines.append(f'  <image source="{image}" width="512" '
                     f'height="{-(-count // 16) * 32}"/>')
        lines.append(' </tileset>')
        first += count
    gids = {}
    first = 1
    for tname, count, image in tilesets:
        gids[tname] = first
        first += count
    for i, (lname, tname, values, width, height) in enumerate(layers):
        if len(values) != width * height:
            sys.exit(f"{path}: layer {lname} holds {len(values)} values, "
                     f"the map is {width}x{height}")
        base = gids[tname]
        rows = [",".join(str(v + base) for v in
                         values[r * width:(r + 1) * width])
                for r in range(height)]
        lines.append(f' <layer id="{i + 1}" name="{lname}" '
                     f'width="{width}" height="{height}">')
        lines.append('  <data encoding="csv">')
        lines += [",\n".join(rows)]
        lines.append('  </data>')
        lines.append(' </layer>')
    # the geometry: one object group per entry of `objects` (name,
    # objects); each object is (name, points, props) — a polyline in
    # world coordinates (one unit = one pixel), its points absolute
    oid = 0
    for gi, (gname, objs) in enumerate(objects):
        lines.append(f' <objectgroup id="{len(layers) + gi + 1}" '
                     f'name="{gname}">')
        for oname, points, props in objs:
            oid += 1
            x, y = points[0]
            rel = " ".join(f"{px - x},{py - y}" for px, py in points)
            lines.append(f'  <object id="{oid}" name="{oname}" '
                         f'x="{x}" y="{y}">')
            lines.append(f'   <polyline points="{rel}"/>')
            if props:
                lines.append('   <properties>')
                for key, value in props:
                    lines.append(f'    <property name="{key}" '
                                 f'value="{value}"/>')
                lines.append('   </properties>')
            lines.append('  </object>')
        lines.append(' </objectgroup>')
    lines.append('</map>')
    path.write_text("\n".join(lines) + "\n")


def read_tmx(path):
    """The editable .tmx back: {layer name: values}, with each CSV gid
    mapped through its layer's tileset to the ROM's index. Only what
    write_tmx emits plus whatever Tiled rewrites on save: uncompressed
    CSV layers."""
    import xml.etree.ElementTree as ET
    root = ET.parse(path).getroot()
    tilesets = {t.get("name"): int(t.get("firstgid")) for t in
                root.findall("tileset")}
    want = {"A": "metatiles_a", "B": "metatiles_b", "cells": "cells"}
    layers = {}
    for layer in root.findall("layer"):
        dims = (int(layer.get("width")), int(layer.get("height")))
        data = layer.find("data")
        name = layer.get("name")
        if name not in want or data is None \
                or data.get("encoding") != "csv" \
                or data.get("compression"):
            continue
        gids = [int(v) for v in data.text.replace("\n", "").split(",")]
        base = tilesets.get(want[name])
        if base is None:
            sys.exit(f"{path}: no tileset named {want[name]}")
        values = []
        for gid in gids:
            if gid & 0xF0000000:
                sys.exit(f"{path}: layer {name} has a flipped tile; the "
                         "ROM map holds plain metatile indices")
            if gid == 0:
                sys.exit(f"{path}: layer {name} has an empty cell; paint "
                         f"every cell (tileset {want[name]})")
            values.append(gid - base)
        if min(values) < 0:
            sys.exit(f"{path}: layer {name} uses a tile from the wrong "
                     f"tileset; it draws with {want[name]}")
        layers[name] = (values, dims)
    missing = {"A", "B"} - set(layers)
    if missing:
        # the cell layer is a track's to have or not (track 7 has none)
        sys.exit(f"{path}: no layer named {', '.join(sorted(missing))}")
    objects = {}
    for group in root.findall("objectgroup"):
        objs = []
        for obj in group.findall("object"):
            poly = obj.find("polyline")
            if poly is None:
                sys.exit(f"{path}: object {obj.get('name')} in "
                         f"{group.get('name')} is not a polyline")
            x, y = float(obj.get("x")), float(obj.get("y"))
            pts = []
            for pair in poly.get("points").split():
                dx, dy = (float(v) for v in pair.split(","))
                pts.append((int(x + dx), int(y + dy)))
            props = {pr.get("name"): pr.get("value")
                     for pr in obj.findall("./properties/property")}
            objs.append((obj.get("name"), pts, props))
        objects[group.get("name")] = objs
    return layers, objects


def track_layer_files(meta, parts):
    """The editable files of a track with these part blobs, in a fixed
    order: the .tmx (tile layers and geometry object layers), the two
    tile sheets, the two metatile tables, the surface table, and the
    geometry's binary side files (the spatial indexes, the lane
    terminator pointers and projScale fixups, the wall cell pool, and
    the unreferenced authoring leftovers). A file whose part the track
    lacks (track 7's surfaces) is left out, so make never waits on it."""
    files = [f"{meta['name']}.tmx", "tiles_0.png", "tiles_2.png",
             "metatiles_a", "metatiles_b"]
    if "surfaceTable" in parts:
        files.append("surfaces")
    if "wall_recs" in parts:
        files.append("wall_cells")
    files += ["lane_terms", "lane_fixups", "cell_index_crc"]
    if "lane_lengths" in parts:
        files.append("lane_lengths")
    files += [f"lane_cells_{g['slot']}" for g in meta["lanes"]]
    files += [f"lane_orphan_{i}" for i in meta.get("orphanParts", [])]
    return files


def track_parts_blobs(meta, blobs):
    """The whole track from its part blobs, as the editable .tmx holds it:
    each map layer's values padded to its rectangle. The cells past the
    ROM's stream are display-only (the build encodes the recorded count);
    a layer whose true final entry is known — the module's raw track-7
    maps carry it — pads with that value."""
    layers = {}
    for part, lname in (("bg3Map", "A"), ("bg2Map", "B"),
                        ("cellMap", "cells")):
        if part not in blobs:
            continue
        m = meta["layers"][part]
        # only the stream's own halfwords: the dead tail bytes past them
        # would decode as one more (huge) run
        values = rle16_values(blobs[part][:2 * m["len"]])
        width, height = m["stride"], -(-m["count"] // m["stride"])
        pad = m["tail"] if m["tail"] is not None else values[-1]
        layers[lname] = values + [pad] * (width * height - len(values))
    return layers


def unpack_track(meta, blobs, out):
    """Write a track's editable files from its part blobs. Every file is
    written only when missing: an existing one is the user's, edits and
    all. The tileset pictures the .tmx points at are previews that
    extract draws from the built parts (draw_track_previews)."""
    name = meta["name"]
    out.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=out) as t:
        tmp, done = Path(t), []
        tmx = f"{name}.tmx"
        geo_layers, geo_files = unpack_track_geometry(meta, blobs)
        for fname, data in geo_files.items():
            if not (out / fname).exists():
                (tmp / fname).write_bytes(data)
                done.append(fname)
        if "lane_lengths" in blobs and not (out / "lane_lengths").exists():
            (tmp / "lane_lengths").write_bytes(blobs["lane_lengths"])
            done.append("lane_lengths")
        if not (out / tmx).exists():
            layers = track_parts_blobs(meta, blobs)
            counts = {"metatiles_a": len(blobs["bg3Metatiles"]) // 32,
                      "metatiles_b": len(blobs["bg2Metatiles"]) // 32,
                      "cells": len(blobs.get("surfaceTable", b"")) // 16}
            tilesets = [("metatiles_a", counts["metatiles_a"], "metatiles_a.png"),
                        ("metatiles_b", counts["metatiles_b"], "metatiles_b.png")]
            tmx_layers = []
            for lname, tset, part in (("A", "metatiles_a", "bg3Map"),
                                      ("B", "metatiles_b", "bg2Map"),
                                      ("cells", "cells", "cellMap")):
                if lname not in layers:
                    continue
                m = meta["layers"][part]
                stride = m["stride"]
                tmx_layers.append((lname, tset, layers[lname], stride,
                                   -(-m["count"] // stride)))
            if "cells" in layers:
                tilesets.append(("cells", counts["cells"], "cells.png"))
            write_tmx(tmp / tmx, name, tmx_layers, tilesets, geo_layers)
            done.append(tmx)
        for part, fname in (("bg2Tiles", "tiles_0.png"),
                            ("bg3Tiles", "tiles_2.png")):
            if part in blobs and not (out / fname).exists():
                unpack_track_tiles(tmp / fname, blobs[part], blobs["palette"])
                done.append(fname)
        for part, fname in (("bg3Metatiles", "metatiles_a"),
                            ("bg2Metatiles", "metatiles_b"),
                            ("surfaceTable", "surfaces")):
            if part in blobs and not (out / fname).exists():
                (tmp / fname).write_bytes(blobs[part])
                done.append(fname)
        for fname in done:
            (tmp / fname).rename(out / fname)



# --- Track geometry -------------------------------------------------------

def unpack_track_geometry(meta, blobs):
    """The geometry object layers (waypoints, lanes, walls) and the
    binary side files' contents, from the track's geometry part blobs.
    Returns (object layers for the .tmx, {file name: bytes})."""
    obj_layers, files = [], {}
    if "segs" in blobs:  # the waypoint gates, one 2-point line each
        objs = []
        for i in range(len(blobs["segs"]) // 0x18):
            w = blobs["segs"][i * 0x18:(i + 1) * 0x18]
            objs.append((str(i),
                         [struct.unpack_from("<2i", w, 0),
                          struct.unpack_from("<2i", w, 8)],
                         [("kind", struct.unpack_from("<H", w, 16)[0]),
                          ("countdown", w[0x14])]))
        obj_layers.append(("waypoints", objs))
    if "wall_recs" in blobs:  # one polyline per wall chain
        nv = len(blobs["wall_verts"]) // 8
        words = struct.unpack_from(f"<{nv * 2}i", blobs["wall_verts"])
        verts = list(zip(words[::2], words[1::2]))
        nc = len(blobs["wall_recs"]) // 0x20
        pairs = [struct.unpack_from("<2H", blobs["wall_recs"], i * 0x20)
                 for i in range(nc)]
        chains, cur = [], [pairs[0][0], pairs[0][1]]
        for i in range(1, nc):
            if pairs[i][0] == cur[-1]:
                cur.append(pairs[i][1])
            else:
                chains.append(cur)
                cur = [pairs[i][0], pairs[i][1]]
        chains.append(cur)
        objs, idx = [], 0
        for ci, ch in enumerate(chains):
            nrec = len(ch) - 1
            steer = ",".join(str(blobs["wall_recs"][(idx + r) * 0x20 + 0x1C])
                             for r in range(nrec))
            idx += nrec
            objs.append((str(ci), [verts[i] for i in ch],
                         [("steer", steer)]))
        obj_layers.append(("walls", objs))
        files["wall_cells"] = blobs["wall_lists"] + blobs["wall_grid"]
        crcs = [("walls", blobs["wall_verts"] + blobs["wall_recs"])]
    else:
        crcs = []
    lanes = []
    for g in meta["lanes"]:
        slot = g["slot"]
        flat = struct.unpack(f"<{g['points'] * 2}H",
                             blobs[f"lane_points_{slot}"])
        pts = list(zip(flat[::2], flat[1::2]))
        segs = blobs[f"lane_segs_{slot}"]
        nrec = len(segs) // 0x14 - 1  # the terminator record links nothing
        pairs = [struct.unpack_from("<2B", segs, i * 0x14)
                 for i in range(nrec)]
        skips = [(a, b) for a, b in pairs if b != a + 1 and b != 0]
        props = ([("skips", " ".join(f"{a}-{b}" for a, b in skips))]
                 if skips else [])
        lanes.append((str(slot), pts, props))
        files[f"lane_cells_{slot}"] = (blobs[f"lane_lists_{slot}"]
                                       + blobs[f"lane_grid_{slot}"])
        crcs.append((f"lane_{slot}", blobs[f"lane_points_{slot}"]
                     + blobs[f"lane_segs_{slot}"]))
    if lanes:
        obj_layers.append(("lanes", lanes))
    # per lane: the terminator u32, and the projScale bytes the tool
    # wrote against its own formula (kept so the build reproduces them)
    terms, fixups = [], bytearray()
    fixups += struct.pack("<B", len(meta["lanes"]))
    for g in meta["lanes"]:
        slot = g["slot"]
        segs = blobs[f"lane_segs_{slot}"]
        terms.append(struct.unpack_from("<I", segs, len(segs) - 4)[0])
        nrec = len(segs) // 0x14
        pairs = [struct.unpack_from("<2B", segs, i * 0x14)
                 for i in range(nrec)]
        skips = [(a, b) for a, b in pairs if b != a + 1 and b != 0]
        flat = struct.unpack(f"<{g['points'] * 2}H",
                             blobs[f"lane_points_{slot}"])
        pts = list(zip(flat[::2], flat[1::2]))
        got, _ = geo.pack_lane_segs(pts, skips, {}, 0)
        lane_fix = [struct.pack("<HB", i, segs[i * 0x14 + 2])
                    for i in range(nrec)
                    if segs[i * 0x14 + 2] != got[i * 0x14 + 2]]
        fixups += struct.pack("<BB", slot, len(lane_fix)) + b"".join(lane_fix)
    files["lane_terms"] = b"".join(struct.pack("<I", t) for t in terms)
    # the geometry each retail cell index was built for; see
    # build_track_geometry
    files["cell_index_crc"] = "".join(
        f"{name} {zlib.crc32(data):08X}\n" for name, data in crcs).encode()
    files["lane_fixups"] = bytes(fixups)
    for i in meta.get("orphanParts", []):
        files[f"lane_orphan_{i}"] = blobs[f"lane_orphan_{i}"]
    return obj_layers, files


def parse_skips(value):
    """A "skips" property ("101-103 17-19") back to (from, to) pairs."""
    if not value:
        return []
    return [tuple(int(v) for v in link.split("-"))
            for link in value.split()]


def read_lane_fixups(folder):
    """The projScale fixups {slot: {record: value}} from lane_fixups:
    u8 lane count, then per lane (u8 slot, u8 n, (u16 record, u8 value)*)
    with record indices local to the lane."""
    raw = (folder / "lane_fixups").read_bytes()
    out, pos = {}, 1
    for _ in range(raw[0]):
        slot, n = raw[pos], raw[pos + 1]
        pos += 2
        out[slot] = {struct.unpack_from("<HB", raw, pos + 3 * i)[0]:
                     raw[pos + 3 * i + 2] for i in range(n)}
        pos += 3 * n
    return out


def check_lane(folder, slot, pts, skips):
    """Stop with a message on a lane the records can't hold: u16 point
    coordinates, u8 point indices, and no zero-length segment (its
    length divides the per-segment scales)."""
    if len(pts) > 256:
        sys.exit(f"{folder}: lane {slot} has {len(pts)} points; its records "
                 "hold u8 point indices, so 256 is the most")
    for i, (x, y) in enumerate(pts):
        if not (0 <= x <= 0xFFFF and 0 <= y <= 0xFFFF):
            sys.exit(f"{folder}: lane {slot} point {i} at ({x}, {y}) is "
                     "outside 0-65535; lane points are u16")
    for a, b in geo.lane_chain(len(pts), skips):
        if pts[a] == pts[b]:
            sys.exit(f"{folder}: lane {slot} links two identical points "
                     f"(points {a} and {b}, at {pts[a]}); remove one")


def read_index_crc(folder):
    """{"walls" or "lane_N": CRC-32} from cell_index_crc: the geometry
    bytes (vertices and records, or points and segment records) each
    retail cell index was built for. A missing file matches nothing."""
    f = folder / "cell_index_crc"
    if not f.exists():
        return {}
    return {name: int(crc, 16) for name, crc in
            (line.split() for line in f.read_text().splitlines() if line)}


def build_track_geometry(meta, folder, paths, sizes, objects):
    """Build the geometry part blobs from the .tmx's object layers and
    the binary side files: every derived field through track_geometry's
    formulas, the steer bytes, terminator pointers and cell pools from
    the editable files."""
    for path in paths.values():
        path.parent.mkdir(parents=True, exist_ok=True)
    index_crc = read_index_crc(folder)
    for oname in objects:
        if oname not in ("waypoints", "walls", "lanes"):
            sys.exit(f"{folder}: unknown object layer {oname}")
    if "segs" in paths:
        segs = b""
        for name, pts, props in objects.get("waypoints", []):
            if len(pts) != 2:
                sys.exit(f"{folder}: waypoint {name} is not a 2-point line")
            segs += geo.pack_seg(pts[0], pts[1], int(props.get("kind", 0)),
                                 int(props.get("countdown", 0)))
        paths["segs"].write_bytes(segs)
    if "wall_verts" in paths:
        chains = []
        for name, pts, props in objects.get("walls", []):
            if len(pts) < 2:
                sys.exit(f"{folder}: wall chain {name} needs 2+ points")
            steer = [int(v) & 0xFF
                     for v in props.get("steer", "").split(",") if v != ""]
            if len(steer) != len(pts) - 1:
                sys.exit(f"{folder}: wall {name} has {len(pts) - 1} records "
                         f"but {len(steer)} steer bytes")
            for i in range(len(pts) - 1):
                if pts[i] == pts[i + 1]:
                    sys.exit(f"{folder}: wall {name} has two identical points "
                             f"in a row (points {i} and {i + 1}, at "
                             f"{pts[i]}); remove one")
            chains.append((pts, steer))
        verts, recs = bytearray(), bytearray()
        for chain, steer in chains:
            base = len(verts) // 8
            for x, z in chain:
                verts += struct.pack("<2i", x, z)
            for i, st in enumerate(steer):
                v0, v1 = chain[i], chain[i + 1]
                nx, nz = geo.wall_normal(v0, v1, st)
                recs += geo.pack_wall_rec(base + i, base + i + 1,
                                          v0, v1, st, nx, nz)
        paths["wall_verts"].write_bytes(verts)
        paths["wall_recs"].write_bytes(recs)
        # the record count gTrackWallTables INCBINs, so a chain that gains
        # or loses a point moves the count with the records
        paths["wall_recs"].with_name("wall_count.bin").write_bytes(
            struct.pack("<I", len(recs) // 0x20))
        if index_crc.get("walls") == zlib.crc32(verts + recs):
            cells = (folder / "wall_cells").read_bytes()
            grid = sizes["wall_grid"]
            lists, grid = cells[:len(cells) - grid], cells[len(cells) - grid:]
        else:
            print(f"{folder.name}: the walls changed; rebuilding their "
                  "cell index", file=sys.stderr)
            lists, grid = geo.wall_cell_index(
                [struct.unpack_from("<2i", verts, i)
                 for i in range(0, len(verts), 8)],
                [struct.unpack_from("<2H", recs, i)
                 for i in range(0, len(recs), 0x20)])
        paths["wall_lists"].write_bytes(lists)
        paths["wall_grid"].write_bytes(grid)
    terms = list(struct.unpack(
        f"<{len((folder / 'lane_terms').read_bytes()) // 4}I",
        (folder / "lane_terms").read_bytes()))
    by_lane = read_lane_fixups(folder)
    totals = {}
    for gi, g in enumerate(meta["lanes"]):
        slot = g["slot"]
        objs = {o[0]: o for o in objects.get("lanes", [])}
        if str(slot) not in objs:
            sys.exit(f"{folder}: no lane object named {slot}")
        pts = objs[str(slot)][1]
        check_lane(folder, slot, pts,
                   parse_skips(dict(objs[str(slot)][2]).get("skips", "")))
        segs, totals[g["lengthAt"]] = geo.pack_lane_segs(
            pts, parse_skips(dict(objs[str(slot)][2]).get("skips", "")),
            by_lane.get(slot, {}), terms[gi])
        points = struct.pack(f"<{len(pts) * 2}H",
                             *[c for pt in pts for c in pt])
        paths[f"lane_points_{slot}"].write_bytes(points)
        paths[f"lane_segs_{slot}"].write_bytes(segs)
        if index_crc.get(f"lane_{slot}") == zlib.crc32(points + segs):
            cells = (folder / f"lane_cells_{slot}").read_bytes()
            lists, grid = cells[:-2 * 48 * 48], cells[-2 * 48 * 48:]
        else:
            print(f"{folder.name}: lane {slot} changed; rebuilding its "
                  "cell index", file=sys.stderr)
            lists, grid = geo.lane_cell_index(
                pts, [struct.unpack_from("<2B", segs, i)
                      for i in range(0, len(segs) - 0x14, 0x14)])
        paths[f"lane_lists_{slot}"].write_bytes(lists)
        paths[f"lane_grid_{slot}"].write_bytes(grid)
    if "lane_lengths" in paths:
        # each lane's length word is its computed total, so moving a lane's
        # points moves the length the AI and the challenge start read; the
        # other words are authoring leftovers nothing reads, kept as data
        lengths = bytearray((folder / "lane_lengths").read_bytes())
        for at, total in totals.items():
            struct.pack_into("<H", lengths, at, total)
        paths["lane_lengths"].write_bytes(lengths)
    for i in meta.get("orphanParts", []):
        paths[f"lane_orphan_{i}"].write_bytes(
            (folder / f"lane_orphan_{i}").read_bytes())


def build_track(meta, folder, paths, sizes):
    """Build a track's part blobs from its editable files alone, plus the
    three stream-length files (u16 halfword counts) that the gTrackData
    table INCBINs, so an edit to a map layer changes the table's lengths
    with the stream. A stream that shrank keeps its ROM slot: the dead
    tail bytes the ROM holds past a stream are metadata and follow it,
    then zero fill. One that grew gets whole words added and moves the
    rest of the ROM, as any edit does. The module's raw maps of track 7
    are the .tmx rectangles themselves, one byte per cell."""
    name = meta["name"]
    layers, objects = read_tmx(folder / f"{name}.tmx")
    build_track_geometry(meta, folder, paths, sizes, objects)
    for part, lname in (("bg3Map", "A"), ("bg2Map", "B"),
                        ("cellMap", "cells")):
        if part not in paths:
            continue
        if lname not in layers:
            sys.exit(f"{folder / (name + '.tmx')}: no layer named {lname}")
        m = meta["layers"][part]
        width, height = m["stride"], -(-m["count"] // m["stride"])
        values, dims = layers[lname]
        if dims != (width, height):
            sys.exit(f"{folder / (name + '.tmx')}: layer {lname} is "
                     f"{dims[0]}x{dims[1]}, the map is {width}x{height}")
        if len(values) != width * height:
            sys.exit(f"{folder / (name + '.tmx')}: layer {lname} holds "
                     f"{len(values)} cells, the map is {width}x{height}")
        if part == "cellMap":
            values_allowed = len((folder / "surfaces").read_bytes()) // 16
        else:
            table = (folder / ("metatiles_a" if part == "bg3Map"
                               else "metatiles_b")).read_bytes()
            values_allowed = len(table) // 32
        if max(values) >= values_allowed:
            sys.exit(f"{folder / (name + '.tmx')}: layer {lname} uses "
                     f"index {max(values)}, the table holds {values_allowed}")
        stream = rle16_encode(values[:m["count"]])
        room = m["size"]
        if len(stream) + len(m["pad"]) > room:
            room += -(-(len(stream) + len(m["pad"]) - room) // 4) * 4
        paths[part].parent.mkdir(parents=True, exist_ok=True)
        paths[part].write_bytes(stream + bytes(m["pad"])
                                + bytes(room - len(stream) - len(m["pad"])))
        paths[part].with_suffix(".len").write_bytes(
            struct.pack("<H", len(stream) // 2))
    for part in ("module_bg3Map", "module_bg2Map"):
        if part not in paths:
            continue
        lname = "A" if part.endswith("bg3Map") else "B"
        values = layers[lname][0]
        if max(values) > 0xFF:
            sys.exit(f"{folder / (name + '.tmx')}: layer {lname} holds "
                     f"{max(values)}, over the u8 the module's raw map holds")
        paths[part].write_bytes(bytes(values))
    sheets = {}
    for part, png in (("bg2Tiles", "tiles_0.png"), ("bg3Tiles", "tiles_2.png")):
        if part in paths:
            sheets[part] = build_track_tiles(folder / png,
                                             sizes.get(part, 0) // 32)
    if {"bg2Tiles", "bg3Tiles"} <= set(sheets) \
            and sheets["bg2Tiles"][1] != sheets["bg3Tiles"][1]:
        sys.exit(f"{folder / 'tiles_0.png'} and tiles_2.png carry different "
                 "palettes; the ROM holds one palette per track — edit the "
                 "two sheets' colours together")
    for part, (blob, palette) in sheets.items():
        paths[part].parent.mkdir(parents=True, exist_ok=True)
        paths[part].write_bytes(blob)
        # the sheet's last 16 tiles: the high module's copy of track 7's
        # data starts that far into the sheet before it (track 6's bg2Tiles)
        paths[part].with_name(f"{part}_tail.bin").write_bytes(blob[-512:])
        if part == "bg2Tiles" and "palette" in paths:
            paths["palette"].write_bytes(palette)
    for part, fname in (("bg3Metatiles", "metatiles_a"),
                        ("bg2Metatiles", "metatiles_b"),
                        ("surfaceTable", "surfaces")):
        if part in paths:
            paths[part].write_bytes((folder / fname).read_bytes())


def pal_asset(asset):
    """The pal asset a tiles sheet's `palette` option names."""
    for other in assets():
        if other["path"] == asset["options"]["palette"]:
            return other
    sys.exit(f"{asset['path']}: no pal asset named {asset['options']['palette']}")


def pal_colors(asset, rom, count):
    """The first `count` colours of a sheet's palette, from that palette's
    own editable file, unpacking it if a fresh clone doesn't have it."""
    source = pal_asset(asset)
    unpack_asset(source, rom)
    data = read_jasc_pal(editable(source), source["size"])
    if len(data) < 2 * count:
        sys.exit(f"{asset['path']}: {source['path']} holds {len(data) // 2} "
                 f"colours, the sheet needs {count}")
    return data[:2 * count]


def unpack_tiles(asset, rom, out):
    """Write a sheet's editable .png: the tiles in reading order, `width`
    to a row, the padding cells of a ragged last row blank (colour 0)."""
    depth, width, count = tiles_layout(asset)
    start = int(asset["start"], 16) - ROM_BASE
    data = rom[start:start + asset["size"]]
    rows = -(-count // width)
    w, h = width * 8, rows * 8
    px = bytearray(w * h)
    for t in range(count):
        tx, ty = t % width, t // width
        for y in range(8):
            base = t * 8 * depth + y * depth
            src = data[base:base + depth]
            row = (bytes(v for b in src for v in (b & 15, b >> 4))
                   if depth == 4 else src)
            off = (ty * 8 + y) * w + tx * 8
            px[off:off + 8] = row
    write_indexed_png(out, px, w, h, pal_colors(asset, rom, 1 << depth))


def build_tiles(asset):
    """Build a sheet's blob from its editable .png alone. With `maxTiles`,
    a tile painted past the ROM's last one (in the padding, or in rows
    added below) grows the sheet up to that tile, and blank cells before
    it become blank tiles."""
    depth, width, count = tiles_layout(asset)
    limit = asset["options"].get("maxTiles", count)
    png = editable(asset)
    px, _ = read_indexed_png(png, width * 8, None, 1 << depth)
    tiles = []
    for i in range(len(px) // 64):
        tile = bytearray()
        for y in range(8):
            off = (i // width * 8 + y) * width * 8 + i % width * 8
            row = px[off:off + 8]
            tile += (bytes(row[2 * k] | row[2 * k + 1] << 4 for k in range(4))
                     if depth == 4 else bytes(row))
        tiles.append(bytes(tile))
    used = max([count] + [i + 1 for i, t in enumerate(tiles) if any(t)])
    if len(px) // (width * 8) % 8 or used > limit:
        sys.exit(f"{png}: {used} tiles, the game loads {limit}: leave the "
                 f"cells past tile {limit - 1} blank (colour 0), and keep "
                 "the height a multiple of 8")
    if len(tiles) < count:
        sys.exit(f"{png}: {len(tiles)} cells, the sheet has {count} tiles")
    data = b"".join(tiles[:used])
    path = built(asset)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(data)


def build_screen(asset):
    """Build a screen's blobs under build/assets/ from its editable .png:
    the only input, so editing the picture edits the ROM."""
    png = editable(asset)
    pixels, palette = read_screen_png(png)
    blobs = split_screen(pixels, palette)
    for part, size in screen_blob_sizes(asset).items():
        if part == "tail":  # dead bytes after the tiles, not from the picture
            continue
        if len(blobs[part]) != size and asset["options"].get("sharedTable"):
            what = "metatiles" if part == "table" else "tiles"
            have = len(blobs[part]) // (8 if part == "table" else 64)
            want = asset["options"][what]
            sys.exit(f"{png}: the picture has {have} unique {what}, but the "
                     f"game draws it with the shared table, which needs "
                     f"all {want}: keep every 8x8 tile unique")
        path = screen_part(asset, part)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(blobs[part])


def song_flags(opts):
    flags = ["-E", "-P", opts["priority"]]
    if "reverb" in opts:
        flags += ["-R", opts["reverb"]]
    return flags


def generate(asset):
    """Run a "gen" asset's generator into its build/assets/ path."""
    path = OUT / asset["path"]
    path.parent.mkdir(parents=True, exist_ok=True)
    run(sys.executable, ROOT / asset["options"]["generator"], path)


def draw_track_previews(meta, blobs, out):
    """Redraw the tileset pictures the .tmx points at (metatiles_a.png,
    metatiles_b.png, cells.png) from the track's built parts, so they
    show your edits; each only when it is older than an editable file.
    Tiled only displays them; the build never reads them."""
    stamp = max((out / f).stat().st_mtime
                for f in track_layer_files(meta, blobs) if (out / f).exists())
    for pname, mpart, tpart in (("metatiles_a.png", "bg3Metatiles", "bg3Tiles"),
                                ("metatiles_b.png", "bg2Metatiles", "bg2Tiles")):
        if mpart not in blobs:
            continue
        p = out / pname
        if p.exists() and p.stat().st_mtime >= stamp:
            continue
        px, w, h, pal = render_metatile_sheet(
            metatile_entries(blobs[mpart]), blobs[tpart], blobs["palette"])
        write_indexed_png(p, px, w, h, pal)
    if "surfaceTable" in blobs:
        p = out / "cells.png"
        if not p.exists() or p.stat().st_mtime < stamp:
            values = len(blobs["surfaceTable"]) // 16
            colors = bytearray(512)
            for i in range(min(values, 256)):
                struct.pack_into("<H", colors, 2 * i,
                                 (i * 37 + 8) & 31 | ((i * 73 + 12) & 31) << 5
                                 | ((i * 19 + 4) & 31) << 10)
            px = b"".join(bytes([i & 0xFF]) * 1024 for i in range(values))
            write_indexed_png(p, px, 32 * 16, -(-values // 16) * 32,
                              bytes(colors))


def extract_tracks(rom):
    """Unpack every track's editable folder (only the files missing) and
    build its part blobs from the editable files: the round trip must
    land on the same bytes the blobs came from."""
    metas = tracks_meta()
    for name, parts in sorted(track_entries().items()):
        blobs = {part: rom[int(a["start"], 16) - ROM_BASE:
                           int(a["start"], 16) - ROM_BASE + a["size"]]
                 for part, a in parts.items()}
        unpack_track(metas[name], blobs, EDIT / "tracks" / name)
        build_track(metas[name], EDIT / "tracks" / name,
                    {p: OUT / a["path"] for p, a in parts.items()},
                    {p: a["size"] for p, a in parts.items()})
        built = {p: (OUT / a["path"]).read_bytes() for p, a in parts.items()
                 if (OUT / a["path"]).exists()}
        draw_track_previews(metas[name], built, EDIT / "tracks" / name)
        # a track with no such stream (track 7's cell map) still owes the
        # table its length: zero
        for part, m in metas[name]["layers"].items():
            path = OUT / "tracks" / name / f"{part}.len"
            if not path.exists():
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(struct.pack("<H", m["len"]))


def extract():
    if not BASEROM.exists():
        sys.exit("baserom.gba is missing: copy your own ROM to the repo root")
    rom = BASEROM.read_bytes()
    for asset in assets():
        kind = asset.get("type")
        if kind in ("midi", "aif", "copy", "gen", "track"):
            if kind == "gen":
                generate(asset)
            continue
        if kind == "screen":
            # The .png is the source: unpack it if a fresh clone doesn't
            # have it yet (never over one that exists), then build the
            # blobs from the picture alone. A screen with a tail also
            # copies that many dead ROM bytes after its tiles.
            unpack_asset(asset, rom)
            build_screen(asset)
            if asset.get("options", {}).get("tail"):
                start = int(asset["start"], 16) - ROM_BASE
                sizes = screen_blob_sizes(asset)
                path = screen_part(asset, "tail")
                path.write_bytes(rom[start + asset["size"] - sizes["tail"]:
                                     start + asset["size"]])
            continue
        if kind == "pal":
            # The .pal text file is the source, same rule as a screen.
            unpack_asset(asset, rom)
            path = built(asset)
            path.parent.mkdir(parents=True, exist_ok=True)
            data = bytearray(read_jasc_pal(editable(asset), asset["size"]))
            for i in asset.get("options", {}).get("bit15", []):
                data[2 * i + 1] |= 0x80
            path.write_bytes(data)
            continue
        if kind == "tiles":
            unpack_asset(asset, rom)
            build_tiles(asset)
            continue
        if kind == "bitmap":
            unpack_asset(asset, rom)
            build_bitmap(asset)
            continue
        start = int(asset["start"], 16) - ROM_BASE
        path = OUT / asset["path"]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(rom[start:start + asset["size"]])
    extract_tracks(rom)


def unpack(path):
    """Write one asset's editable file (.mid, .aif, .png, .pal, or any
    file of a track's folder) from baserom.gba, unless the file already
    exists: then it's the user's, edits and all."""
    p = Path(path).resolve()
    try:
        inside = p.relative_to(EDIT / "tracks")
    except ValueError:
        inside = None
    if inside is not None:
        rom = BASEROM.read_bytes() if BASEROM.exists() else None
        if rom is None:
            sys.exit("baserom.gba is missing: copy your own ROM to the repo root")
        name = inside.parts[0]
        parts = track_entries()[name]
        blobs = {part: rom[int(a["start"], 16) - ROM_BASE:
                           int(a["start"], 16) - ROM_BASE + a["size"]]
                 for part, a in parts.items()}
        unpack_track(tracks_meta()[name], blobs, EDIT / "tracks" / name)
        return
    unpack_asset(find(path))


def unpack_asset(asset, rom=None):
    out = editable(asset)
    if out.exists():
        return
    if rom is None:
        if not BASEROM.exists():
            sys.exit("baserom.gba is missing: copy your own ROM to the repo root")
        rom = BASEROM.read_bytes()
    out.parent.mkdir(parents=True, exist_ok=True)
    start = int(asset["start"], 16) - ROM_BASE
    # Convert in a temporary folder, so a failed run leaves no partial file
    # that a later build would take for the user's.
    with tempfile.TemporaryDirectory(dir=out.parent) as t:
        tmp = Path(t) / out.name
        if asset["type"] == "midi":
            opts = asset["options"]
            header = hex(start + opts["headerOffset"])
            run(TOOLS / "agb2mid", BASEROM, header, BASEROM, tmp, *song_flags(opts))
        elif asset["type"] == "screen":
            blobs = screen_blobs(asset, rom)
            write_screen_png(tmp, compose_screen(blobs), blobs["pal"])
        elif asset["type"] == "pal":
            write_jasc_pal(tmp, rom[start:start + asset["size"]])
        elif asset["type"] == "tiles":
            unpack_tiles(asset, rom, tmp)
        elif asset["type"] == "bitmap":
            unpack_bitmap(asset, rom, tmp)
        else:
            raw = Path(t) / "sample.bin"
            raw.write_bytes(rom[start:start + asset["size"]])
            run(TOOLS / "aif2pcm", raw, tmp)
        tmp.rename(out)


def song(mid, out):
    """mid2agb a song's .mid into assembly that data/sound/sounds.s can
    include."""
    asset = find(mid)
    opts = asset["options"]
    out = Path(out)
    group = f"voicegroup_{int(opts['voicegroup'], 16):08X}"
    with tempfile.TemporaryDirectory() as t:
        s = Path(t) / "song.s"
        run(TOOLS / "mid2agb", mid, s, *song_flags(opts), "-V", opts["V"],
            "-L", out.stem)
        src = s.read_text()
    # mid2agb writes pret preproc's `label::` (a global label) and its own
    # .rodata section; plain gas wants `label:`, and the song must stay in
    # the including fragment's section, at its place in the ROM. That
    # section is Thumb code to gas, which pads a bare `.align` with NOPs;
    # the ROM pads with zeros.
    src = (src.replace("::", ":").replace("\t.section .rodata\n", "")
           .replace("\t.align\t2\n", "\t.align\t2, 0\n")
           .replace('"sound/MPlayDef.s"', '"tools/tmc/sound/MPlayDef.s"')
           .replace("voicegroup000", group))
    out.write_text(src)


def list_editable():
    for asset in assets():
        if asset.get("type") in EDITABLE:
            print(editable(asset).relative_to(ROOT))
    metas = tracks_meta()
    for name, parts in track_entries().items():
        for f in track_layer_files(metas[name], parts):
            print((EDIT / "tracks" / name / f).relative_to(ROOT))


def blank():
    """Zero-fill every asset at its listed size, for a build with no ROM."""
    for asset in assets():
        if asset.get("type") == "copy":
            continue  # the fragment incbins the source's own zero fill
        if asset.get("type") == "gen":
            generate(asset)  # needs no ROM, so CI builds the real bytes
            continue
        if asset.get("type") == "screen":
            for part, size in screen_blob_sizes(asset).items():
                path = screen_part(asset, part)
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(bytes(size))
            continue
        if asset.get("type") == "bitmap":
            path = bitmap_part(asset)
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(bytes(asset["size"]))
            continue
        path = built(asset)
        path.parent.mkdir(parents=True, exist_ok=True)
        if path.suffix == ".s":
            # The song table (src/sound/tables.c, another object) names each
            # song's header label, so it must be global even zero-filled.
            head = asset["options"]["headerOffset"]
            path.write_text(f"\t.space {head}\n\t.global {path.stem}\n"
                            f"{path.stem}:\n\t.space {asset['size'] - head}\n")
        else:
            path.write_bytes(bytes(asset["size"]))
    # The stream-length files carry the retail halfword counts whatever the
    # blobs hold: gTrackData is C, so its bytes are real in a CI build too.
    for name, meta in tracks_meta().items():
        folder = OUT / "tracks" / name
        folder.mkdir(parents=True, exist_ok=True)
        for part, m in meta["layers"].items():
            (folder / f"{part}.len").write_bytes(struct.pack("<H", m["len"]))
        # the geometry side files carry real bytes in CI too: the lanes
        # build from them, and the region's pointer tables are C, so the
        # parts must link at their retail sizes
        (folder / "lane_terms").write_bytes(b"".join(
            struct.pack("<I", t) for t in meta.get("terms", [])))
        fixups = bytearray([len(meta.get("lanes", []))])
        lanes_with = {}
        for slot, rec, value in meta.get("fixups", []):
            lanes_with.setdefault(slot, []).append((rec, value))
        for g in meta.get("lanes", []):
            fx = lanes_with.get(g["slot"], [])
            fixups += struct.pack("<BB", g["slot"], len(fx))
            for rec, value in fx:
                fixups += struct.pack("<HB", rec, value)
        (folder / "lane_fixups").write_bytes(bytes(fixups))
        for fname, size in meta.get("geometrySizes", {}).items():
            (folder / fname).write_bytes(bytes(size))
    # the wall counts gTrackWallTables INCBINs, from the retail record
    # sizes, and the sheet tails the module's copy fragment incbins
    for name, parts in track_entries().items():
        for part in ("bg2Tiles", "bg3Tiles"):
            if part in parts:
                (OUT / "tracks" / name / f"{part}_tail.bin").write_bytes(
                    bytes(512))
        if "wall_recs" in parts:
            (OUT / "tracks" / name / "wall_count.bin").write_bytes(
                struct.pack("<I", parts["wall_recs"]["size"] // 0x20))


def mask(rom_in, rom_out):
    """Copy a ROM with every asset's range zeroed, except a "gen" asset's:
    its bytes are reproducible without the ROM, so check-code compares
    the generator's output against the retail bytes for real."""
    rom = bytearray(Path(rom_in).read_bytes())
    for asset in assets():
        if asset.get("type") == "gen":
            continue
        start = int(asset["start"], 16) - ROM_BASE
        rom[start:start + asset["size"]] = bytes(asset["size"])
    Path(rom_out).write_bytes(rom)


def tile_order(data, width, depth, inverse=False):
    """Reorder a linear bitmap (rows of `width` tiles) into 8x8 tiles, or
    back. gbagfx only reads tiles; mode 3-5 bitmaps are linear."""
    row = width * depth                    # bytes in one 8-pixel tile row
    out = bytearray(len(data))
    for i in range(len(data) // (depth * 8)):
        ty, tx = divmod(i, width)
        for y in range(8):
            lin = (ty * 8 + y) * row + tx * depth
            til = i * depth * 8 + y * depth
            if inverse:
                out[lin:lin + depth] = data[til:til + depth]
            else:
                out[til:til + depth] = data[lin:lin + depth]
    return bytes(out)


def convert_graphics(asset, raw, tmp):
    """gbagfx round trip: .rl/.lz -> .4bpp/.8bpp -> .png -> back."""
    kind, opts = asset["type"], asset.get("options", {})
    depth = opts.get("bitDepth", 4)
    # "overrun": the stream's last run writes this many bytes past the size
    # in its header. The BIOS stops at the size; gbagfx rejects the stream.
    # The original tool compressed that many extra copies of the last byte.
    over = opts.get("overrun", 0)
    data = raw.read_bytes()
    size = int.from_bytes(data[1:4], "little")
    src = tmp / f"blob.{kind}"
    src.write_bytes(data[:1] + (size + over).to_bytes(3, "little") + data[4:])
    flat = tmp / f"blob.{depth}bpp"
    run(TOOLS / "gbagfx", src, flat)
    flat.write_bytes(flat.read_bytes()[:size])
    tiles = flat.stat().st_size // (depth * 8)
    width = opts.get("width") or max(w for w in range(1, 17) if tiles % w == 0)
    if tiles % width:
        sys.exit(f"{asset['path']}: width {width} doesn't divide {tiles} tiles")
    if opts.get("bitmap"):
        flat.write_bytes(tile_order(flat.read_bytes(), width, depth))
    png, extra = raw.with_suffix(".png"), []
    if "palette" in opts:
        pal = tmp / "blob.gbapal"
        start = int(opts["palette"], 16) - ROM_BASE
        pal.write_bytes(BASEROM.read_bytes()[start:start + (2 << depth)])
        extra = ["-palette", pal]
    run(TOOLS / "gbagfx", flat, png, "-width", width, *extra)
    back_flat = tmp / f"back.{depth}bpp"
    run(TOOLS / "gbagfx", png, back_flat)
    if opts.get("bitmap"):
        back_flat.write_bytes(tile_order(back_flat.read_bytes(), width, depth, True))
    if over:
        pixels = back_flat.read_bytes()
        back_flat.write_bytes(pixels + pixels[-1:] * over)
    back = tmp / f"back.{kind}"
    run(TOOLS / "gbagfx", back_flat, back)
    if over:
        stream = back.read_bytes()
        back.write_bytes(stream[:1] + size.to_bytes(3, "little") + stream[4:])
    # gbagfx pads a compressed stream up to 4 bytes; the .bin is the bare
    # stream, so accept zero fill after it but nothing else
    data, want = back.read_bytes(), raw.read_bytes()
    return data[:len(want)] == want and not any(data[len(want):])


def convert():
    done, raw_kept, bad = 0, [], []
    with tempfile.TemporaryDirectory() as t:
        tmp = Path(t)
        for asset in assets():
            kind, raw = asset.get("type"), OUT / asset["path"]
            if kind not in ("rl", "lz"):
                continue
            if asset.get("options", {}).get("raw"):
                raw_kept.append(asset["path"])
                continue
            done += 1
            if not convert_graphics(asset, raw, tmp):
                bad.append(asset["path"])
    print(f"converted {done} graphics blobs to .png")
    if raw_kept:
        print(f"kept raw (no round-trip): {', '.join(raw_kept)}")
    if bad:
        sys.exit("these don't convert back exactly:\n  " + "\n  ".join(bad))
    print("every one converts back byte for byte")


if __name__ == "__main__":
    modes = {"extract": extract, "unpack": unpack, "song": song, "list": list_editable,
             "blank": blank, "convert": convert, "mask": mask}
    args = {"unpack": 1, "song": 2, "mask": 2}
    if len(sys.argv) < 2 or sys.argv[1] not in modes \
            or len(sys.argv) - 2 != args.get(sys.argv[1], 0):
        sys.exit(__doc__)
    modes[sys.argv[1]](*sys.argv[2:])
