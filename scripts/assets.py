#!/usr/bin/env python3
"""Extract the ROM's data assets from baserom.gba into build/assets/.

Each assets/*.json file lists assets as {"path", "start", "size"} plus an
optional "type" and "options" (zeldaret/tmc's format, with "start" written
as a ROM address). The asm pulls each file in with `.incbin`, so the game's
data stays out of git and a build needs your own baserom.gba.

`extract` copies each asset's raw bytes to build/assets/PATH. They keep the
.bin name: they're the GBA's own formats (m4a song bytecode, PCM samples
with their header, RL/LZ77 graphics streams), not MIDI, AIFF or PNG yet.

`convert` writes an editable file next to each .bin -- .mid for "midi"
songs (agb2mid), .aif for "aif" samples (aif2pcm), .png for "rl"/"lz"
graphics (gbagfx) -- then converts it back and checks that the result
matches the .bin byte for byte. It needs the tools from `make tools`;
`make convert` builds them and runs this.

The PNGs are greyscale (no palette identified yet): gbagfx maps a color
index to 255-index both ways, so the round trip is exact without knowing
the palette. Its width is in 8-pixel tiles and must divide the tile count
exactly, or the PNG grows a partial row of padding tiles that convert back
to extra bytes. `options` carries "bitDepth" (4 or 8) and "width" (tiles);
without them convert picks 4bpp and the widest width up to 16 tiles that
divides. `options {"raw": true}` keeps a stream as .bin only: the blob at
0x080C0000 came from a weaker compressor than gbagfx's, so it has no
round-trip to check.

`blank` writes each asset as zero fill of its listed size, for a build with
no baserom.gba (CI). The code still links at its real addresses, and `mask`
zeroes the same ranges in any ROM, so `make check-code` can compare the
build against the retail ROM's code without the ROM being present.

Usage:
    python3 scripts/assets.py extract
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
TOOLS = ROOT / "tools" / "bin"


def assets():
    for config in sorted((ROOT / "assets").glob("*.json")):
        yield from json.loads(config.read_text())


def run(*cmd):
    subprocess.run([str(c) for c in cmd], check=True, capture_output=True)


def extract():
    if not BASEROM.exists():
        sys.exit("baserom.gba is missing: copy your own ROM to the repo root")
    rom = BASEROM.read_bytes()
    for asset in assets():
        start = int(asset["start"], 16) - ROM_BASE
        path = OUT / asset["path"]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(rom[start:start + asset["size"]])


def blank():
    """Zero-fill every asset at its listed size, for a build with no ROM."""
    for asset in assets():
        path = OUT / asset["path"]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(bytes(asset["size"]))


def mask(rom_in, rom_out):
    """Copy a ROM with every asset's range zeroed."""
    rom = bytearray(Path(rom_in).read_bytes())
    for asset in assets():
        start = int(asset["start"], 16) - ROM_BASE
        rom[start:start + asset["size"]] = bytes(asset["size"])
    Path(rom_out).write_bytes(rom)


def rebuild_song(mid, asset, flags, tmp):
    """mid2agb the MIDI, then assemble and link it at the song's address."""
    opts = asset["options"]
    s = tmp / "song.s"
    run(TOOLS / "mid2agb", mid, s, *flags, "-V", opts["V"])
    # mid2agb writes pret preproc's `label::` (a global label) and a .rodata
    # section; plain gas wants `label:`, and -Ttext places only .text.
    src = s.read_text().replace("::", ":").replace(".section .rodata", ".text")
    s.write_text(f".equ voicegroup000, {opts['voicegroup']}\n{src}")
    obj, elf, out = tmp / "song.o", tmp / "song.elf", tmp / "song.bin"
    run("arm-none-eabi-as", "-I", ROOT / "tools" / "tmc", "-o", obj, s)
    run("arm-none-eabi-ld", f"-Ttext={asset['start']}", "-o", elf, obj)
    run("arm-none-eabi-objcopy", "-O", "binary", elf, out)
    return out


def convert_graphics(asset, raw, tmp):
    """gbagfx round trip: .rl/.lz -> .4bpp/.8bpp -> .png -> back."""
    kind, opts = asset["type"], asset.get("options", {})
    depth = opts.get("bitDepth", 4)
    src = tmp / f"blob.{kind}"
    src.write_bytes(raw.read_bytes())
    flat = tmp / f"blob.{depth}bpp"
    run(TOOLS / "gbagfx", src, flat)
    tiles = flat.stat().st_size // (depth * 8)
    width = opts.get("width") or max(w for w in range(1, 17) if tiles % w == 0)
    if tiles % width:
        sys.exit(f"{asset['path']}: width {width} doesn't divide {tiles} tiles")
    png = raw.with_suffix(".png")
    run(TOOLS / "gbagfx", flat, png, "-width", width)
    back_flat = tmp / f"back.{depth}bpp"
    run(TOOLS / "gbagfx", png, back_flat)
    back = tmp / f"back.{kind}"
    run(TOOLS / "gbagfx", back_flat, back)
    # gbagfx pads a compressed stream up to 4 bytes; the .bin is the bare
    # stream, so accept zero fill after it but nothing else
    data, want = back.read_bytes(), raw.read_bytes()
    return data[:len(want)] == want and not any(data[len(want):])


def convert():
    done = {"midi": 0, "aif": 0, "graphics": 0}
    raw_kept, bad = [], []
    with tempfile.TemporaryDirectory() as t:
        tmp = Path(t)
        for asset in assets():
            kind, raw = asset.get("type"), OUT / asset["path"]
            if kind == "aif":
                aif = raw.with_suffix(".aif")
                run(TOOLS / "aif2pcm", raw, aif)
                back = tmp / "sample.bin"
                run(TOOLS / "aif2pcm", aif, back)
            elif kind == "midi":
                opts = asset["options"]
                header = int(asset["start"], 16) - ROM_BASE + opts["headerOffset"]
                flags = ["-E", "-P", opts["priority"]]
                if "reverb" in opts:
                    flags += ["-R", opts["reverb"]]
                mid = raw.with_suffix(".mid")
                run(TOOLS / "agb2mid", BASEROM, hex(header), BASEROM, mid, *flags)
                back = rebuild_song(mid, asset, flags, tmp)
            elif kind in ("rl", "lz") and asset.get("options", {}).get("raw"):
                raw_kept.append(asset["path"])
                continue
            elif kind in ("rl", "lz"):
                done["graphics"] += 1
                if not convert_graphics(asset, raw, tmp):
                    bad.append(asset["path"])
                continue
            else:
                continue
            done[kind] += 1
            if back.read_bytes() != raw.read_bytes():
                bad.append(asset["path"])
    print(f"converted {done['midi']} songs to .mid, {done['aif']} samples to .aif, "
          f"{done['graphics']} graphics blobs to .png")
    if raw_kept:
        print(f"kept raw (no round-trip): {', '.join(raw_kept)}")
    if bad:
        sys.exit("these don't convert back exactly:\n  " + "\n  ".join(bad))
    print("every one converts back byte for byte")


if __name__ == "__main__":
    modes = {"extract": extract, "blank": blank, "convert": convert, "mask": mask}
    args = {"mask": 2}
    if len(sys.argv) < 2 or sys.argv[1] not in modes \
            or len(sys.argv) - 2 != args.get(sys.argv[1], 0):
        sys.exit(__doc__)
    modes[sys.argv[1]](*sys.argv[2:])
