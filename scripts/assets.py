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
editable files.

`unpack FILE` writes one song's or one sample's editable file: assets/PATH
with .mid (agb2mid) or .aif (aif2pcm) in place of .bin. The editable files
are the sound's source. `make` unpacks a file only when it's missing, and
`unpack` never overwrites one, so your edits survive every build. They stay
out of git (.gitignore), since the ROM's data is copyrighted.

`song MID OUT` turns a song's .mid into the assembly that data/*.s
includes in place: mid2agb with the song's options from assets/*.json, so
the song's pointers resolve where it links. `make` turns a sample's .aif
back into its .bin with aif2pcm alone.

`list` prints the editable file of every song and sample.

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
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ROM_BASE = 0x08000000
BASEROM = ROOT / "baserom.gba"
OUT = ROOT / "build" / "assets"
EDIT = ROOT / "assets"
TOOLS = ROOT / "tools" / "bin"
# Asset types the build makes from an editable file, and that file's suffix.
EDITABLE = {"midi": ".mid", "aif": ".aif"}


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
    return path.with_suffix(".s") if asset.get("type") == "midi" else path


def find(path):
    """The song or sample whose editable file is `path`."""
    path = Path(path).resolve()
    for asset in assets():
        if asset.get("type") in EDITABLE and editable(asset) == path:
            return asset
    sys.exit(f"{path}: no song or sample in assets/*.json has this file")


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
        if asset.get("type") in EDITABLE:
            continue
        start = int(asset["start"], 16) - ROM_BASE
        path = OUT / asset["path"]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(rom[start:start + asset["size"]])


def unpack(path):
    """Write one song's .mid or one sample's .aif from baserom.gba, unless
    the file already exists: then it's the user's, edits and all."""
    asset = find(path)
    out = editable(asset)
    if out.exists():
        return
    if not BASEROM.exists():
        sys.exit("baserom.gba is missing: copy your own ROM to the repo root")
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
        else:
            raw = Path(t) / "sample.bin"
            raw.write_bytes(BASEROM.read_bytes()[start:start + asset["size"]])
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
