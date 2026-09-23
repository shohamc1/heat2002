#!/usr/bin/env python3
"""Extract the ROM's data assets from baserom.gba into build/assets/.

Each assets/*.json file lists assets as {"path", "start", "size"} plus an
optional "type" and "options" (zeldaret/tmc's format, with "start" written
as a ROM address). The asm pulls each file in with `.incbin`, so the game's
data stays out of git and a build needs your own baserom.gba.

`extract` copies each asset's raw bytes to build/assets/PATH. They keep the
.bin name: they're the GBA's own formats (m4a song bytecode, PCM samples
with their header), not MIDI or AIFF yet.

`convert` writes an editable file next to each .bin -- .mid for "midi"
songs (agb2mid), .aif for "aif" samples (aif2pcm) -- then converts it back
and checks that the result matches the .bin byte for byte. It needs the
tools from `make tools`; `make convert` builds them and runs this.

Usage:
    python3 scripts/assets.py extract
    python3 scripts/assets.py convert
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


def convert():
    done, bad = {"midi": 0, "aif": 0}, []
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
            else:
                continue
            done[kind] += 1
            if back.read_bytes() != raw.read_bytes():
                bad.append(asset["path"])
    print(f"converted {done['midi']} songs to .mid, {done['aif']} samples to .aif")
    if bad:
        sys.exit("these don't convert back exactly:\n  " + "\n  ".join(bad))
    print("every one converts back byte for byte")


if __name__ == "__main__":
    modes = {"extract": extract, "convert": convert}
    if len(sys.argv) != 2 or sys.argv[1] not in modes:
        sys.exit(__doc__)
    modes[sys.argv[1]]()
