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
editable files. A "screen" it builds from its editable .png the same way
(see below), after unpacking the picture when it's missing.

`unpack FILE` writes one song's or one sample's editable file: assets/PATH
with .mid (agb2mid) or .aif (aif2pcm) in place of .bin. The editable files
are the sound's source. `make` unpacks a file only when it's missing, and
`unpack` never overwrites one, so your edits survive every build. They stay
out of git (.gitignore), since the ROM's data is copyrighted.

`song MID OUT` turns a song's .mid into the assembly that data/*.s
includes in place: mid2agb with the song's options from assets/*.json, so
the song's pointers resolve where it links. `make` turns a sample's .aif
back into its .bin with aif2pcm alone.

`list` prints the editable file of every song, sample and screen.

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
order is the ROM's. `options` carries the screen's metatile and tile
counts, which fix the blob sizes, so an edit that adds unique metatiles
or tiles no longer fits and fails the build.

A "pal" asset is one palette blob as an editable JASC .pal text file
(assets/graphics/palettes/NAME.pal, the format graphics editors call
"Microsoft Palette"): one `R G B` line per colour, in the ROM's order.
`unpack` writes it from the ROM only when it's missing; `extract` reads
it back into the BGR555 halfwords the ROM holds. The colour count is
the blob's, so adding or removing a line fails the build.

`convert` writes an editable .png next to each "rl"/"lz" graphics .bin
(gbagfx), then converts it back and checks that the result matches the
.bin byte for byte. It needs the tools from `make tools`; `make convert`
builds them and runs this.

The PNGs are greyscale (no palette identified yet): gbagfx maps a color
index to 255-index both ways, so the round trip is exact without knowing
the palette. Its width is in 8-pixel tiles and must divide the tile count
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

ROOT = Path(__file__).resolve().parent.parent
ROM_BASE = 0x08000000
BASEROM = ROOT / "baserom.gba"
OUT = ROOT / "build" / "assets"
EDIT = ROOT / "assets"
TOOLS = ROOT / "tools" / "bin"
# Asset types the build makes from an editable file, and that file's suffix.
EDITABLE = {"midi": ".mid", "aif": ".aif", "screen": ".png", "pal": ".pal"}
# Every "screen" is a 240x160 background: 15x10 metatiles of 2x2 8x8 tiles.
SCREEN_W, SCREEN_H = 240, 160


def assets():
    for config in sorted((ROOT / "assets").glob("*.json")):
        yield from json.loads(config.read_text())


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
    return path.with_suffix(".pal.bin") if asset.get("type") == "pal" else path


def find(path):
    """The song, sample or screen whose editable file is `path`."""
    path = Path(path).resolve()
    for asset in assets():
        if asset.get("type") in EDITABLE and editable(asset) == path:
            return asset
    sys.exit(f"{path}: no song, sample or screen in assets/*.json has this file")


def screen_part(asset, part):
    """One of a screen's blobs under build/assets/ ("pal", "map", "table"
    or "tiles"), built from the .png whatever its edit."""
    return (OUT / asset["path"]).with_suffix(f".{part}.bin")


def screen_blob_sizes(asset):
    """Each blob's size: a 512-byte palette, a 15x10 u16 map, a u16[4]
    table row per metatile and 64 bytes per 8bpp tile."""
    opts = asset["options"]
    return {"pal": 512, "map": 2 * 150,
            "table": 8 * opts["metatiles"], "tiles": 64 * opts["tiles"]}


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
    plte = bytearray()
    for color in struct.unpack("<256H", palette):
        plte += bytes(bgr555_to_rgb8(color))
    rows = b"".join(b"\0" + pixels[y * SCREEN_W:(y + 1) * SCREEN_W]
                    for y in range(SCREEN_H))
    path.write_bytes(b"\x89PNG\r\n\x1a\n"
                     + png_chunk(b"IHDR", struct.pack(">IIBBBBB",
                                                      SCREEN_W, SCREEN_H, 8, 3, 0, 0, 0))
                     + png_chunk(b"PLTE", bytes(plte))
                     + png_chunk(b"IDAT", zlib.compress(rows, 9))
                     + png_chunk(b"IEND", b""))


def read_screen_png(path):
    """Read a screen's picture back: (linear palette indices, BGR555
    palette). Only what an editor keeps of an indexed PNG: 8-bit indices,
    all 256 palette entries, no interlacing."""
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
    w, h, depth, color, _, _, interlace = struct.unpack(">IIBBBBB", chunks[b"IHDR"])
    plte = chunks.get(b"PLTE", b"")
    if (w, h) != (SCREEN_W, SCREEN_H):
        sys.exit(f"{path}: {w}x{h}, want {SCREEN_W}x{SCREEN_H}")
    if color != 3 or depth != 8:
        sys.exit(f"{path}: want an 8-bit indexed PNG (save it in indexed\n"
                 "mode): its palette order is the ROM's")
    if interlace:
        sys.exit(f"{path}: interlaced; save it without interlacing")
    if len(plte) != 3 * 256:
        sys.exit(f"{path}: {len(plte) // 3} palette entries, want 256\n"
                 "(an editor trimmed the unused tail; keep every entry)")
    packed = zlib.decompress(b"".join(chunks[b"IDAT"]))
    pixels, prev = bytearray(w * h), bytearray(w)
    pos = 0
    for y in range(h):
        # Undo the per-row filter, whatever the editor chose (RFC 2083).
        filter_, row = packed[pos], bytearray(packed[pos + 1:pos + 1 + w])
        pos += 1 + w
        if filter_ > 4:
            sys.exit(f"{path}: bad PNG row filter {filter_}")
        for x in range(w):
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
        pixels[y * w:(y + 1) * w] = row
        prev = row
    palette = bytearray(512)
    for i in range(256):
        r, g, b = plte[3 * i:3 * i + 3]
        struct.pack_into("<H", palette, 2 * i,
                         r >> 3 | (g >> 3) << 5 | (b >> 3) << 10)
    return bytes(pixels), bytes(palette)


def build_screen(asset):
    """Build a screen's blobs under build/assets/ from its editable .png:
    the only input, so editing the picture edits the ROM."""
    png = editable(asset)
    pixels, palette = read_screen_png(png)
    blobs = split_screen(pixels, palette)
    for part, size in screen_blob_sizes(asset).items():
        if len(blobs[part]) != size:
            what = "metatiles" if part == "table" else "tiles"
            have = len(blobs[part]) // (8 if part == "table" else 64)
            want = asset["options"][what]
            sys.exit(f"{png}: the picture has {have} unique {what}, but the "
                     f"ROM has room for {want}: a screen's blobs are a "
                     "fixed size")
        path = screen_part(asset, part)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(blobs[part])


def song_flags(opts):
    flags = ["-E", "-P", opts["priority"]]
    if "reverb" in opts:
        flags += ["-R", opts["reverb"]]
    return flags


def extract():
    if not BASEROM.exists():
        sys.exit("baserom.gba is missing: copy your own ROM to the repo root")
    rom = BASEROM.read_bytes()
    for asset in assets():
        kind = asset.get("type")
        if kind in ("midi", "aif"):
            continue
        if kind == "screen":
            # The .png is the source: unpack it if a fresh clone doesn't
            # have it yet (never over one that exists), then build the
            # blobs from the picture alone.
            unpack_asset(asset, rom)
            build_screen(asset)
            continue
        if kind == "pal":
            # The .pal text file is the source, same rule as a screen.
            unpack_asset(asset, rom)
            path = built(asset)
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(read_jasc_pal(editable(asset), asset["size"]))
            continue
        start = int(asset["start"], 16) - ROM_BASE
        path = OUT / asset["path"]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(rom[start:start + asset["size"]])


def unpack(path):
    """Write one song's .mid, one sample's .aif or one screen's .png from
    baserom.gba, unless the file already exists: then it's the user's,
    edits and all."""
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
        else:
            raw = Path(t) / "sample.bin"
            raw.write_bytes(rom[start:start + asset["size"]])
            run(TOOLS / "aif2pcm", raw, tmp)
        tmp.rename(out)


def song(mid, out):
    """mid2agb a song's .mid into assembly that data/*.s can include."""
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


def blank():
    """Zero-fill every asset at its listed size, for a build with no ROM."""
    for asset in assets():
        if asset.get("type") == "screen":
            for part, size in screen_blob_sizes(asset).items():
                path = screen_part(asset, part)
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(bytes(size))
            continue
        path = built(asset)
        path.parent.mkdir(parents=True, exist_ok=True)
        if path.suffix == ".s":
            # The song table names each song's header label.
            head = asset["options"]["headerOffset"]
            path.write_text(f"\t.space {head}\n{path.stem}:\n"
                            f"\t.space {asset['size'] - head}\n")
        else:
            path.write_bytes(bytes(asset["size"]))


def mask(rom_in, rom_out):
    """Copy a ROM with every asset's range zeroed."""
    rom = bytearray(Path(rom_in).read_bytes())
    for asset in assets():
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
