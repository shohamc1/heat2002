#!/usr/bin/env python3
"""Boot the ROM and a shifted build in mGBA and check they behave the same.

`make shift-test` links a second ROM from the same objects with padding
inserted after crt0, so almost every function and data table moves. If any
pointer were still a raw number, the shifted ROM would read the wrong bytes.

Each ROM runs in mGBA with its GDB stub on, at unthrottled speed. A
breakpoint on RLUnCompVram and LZ77UnCompVram stops the game at every
graphics decompression, a moment that is the same in both builds. At each
stop the script records which symbol the source argument points into, and at
every CHECKPOINT-th stop it hashes the display registers, palette, VRAM and
OAM and saves a PNG of the screen. The test passes when both builds load the
same assets in the same order and every hash matches.

It first steps 600 frames one at a time (a breakpoint on VBlankIntr) and
compares the screen and all of work RAM every 100 frames. RAM words may differ
only by a ROM pointer that moved with the shift. A raw pointer stays equal in
RAM, so the RAM check doesn't find one directly: it finds the game state that
diverges once the wrong bytes are read, and the load and screen checks find
the rest. Without baserom.gba the game stops loading after the boot logos, so
the frame checkpoints are most of what CI tests.

    python3 scripts/shift_test.py BASE.elf BASE.gba SHIFT.elf SHIFT.gba
    python3 scripts/shift_test.py --selftest

Set MGBA to the emulator binary if it isn't the macOS app or on PATH.
"""

import bisect
import hashlib
import os
import shutil
import socket
import struct
import subprocess
import sys
import tempfile
import time
import zlib
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "build" / "shift-test"
FRAMES = 600  # frames stepped one at a time from boot
FRAME_CHECKPOINT = 100
HITS = 300  # decompression stops, after the frames
CHECKPOINT = 50
IDLE = 15  # seconds with no load before the run counts as finished
BREAKPOINTS = ("RLUnCompVram", "LZ77UnCompVram")
# Speed limits off: free running is about 20 times real time.
MGBA_ARGS = ["-C", "audioSync=0", "-C", "videoSync=0", "-C", "fpsTarget=6000"]


def find_mgba():
    for c in (os.environ.get("MGBA"), "/Applications/mGBA.app/Contents/MacOS/mGBA",
              shutil.which("mgba-qt"), shutil.which("mgba")):
        if c and Path(c).exists():
            return c
    sys.exit("mGBA not found; set MGBA to its binary")


def unpack(data):
    """Undo the GDB protocol's escapes (}x) and run-length encoding (c*n)."""
    out = bytearray()
    i = 0
    while i < len(data):
        c = data[i]
        if c == 0x7D:
            out.append(data[i + 1] ^ 0x20)
            i += 2
        elif c == 0x2A:
            out += bytes([out[-1]]) * (data[i + 1] - 29)
            i += 2
        else:
            out.append(c)
            i += 1
    return bytes(out)


class Stub:
    """Just enough of a GDB remote client to drive mGBA's stub."""

    def __init__(self, mgba, rom, port=2345):
        # A private folder keeps the runs out of your mGBA settings, and a
        # copy of the ROM in it means mGBA starts with no .sav file (the game
        # reads its EEPROM at boot) and never writes one next to your files.
        self.home = tempfile.mkdtemp(prefix="mgba-")
        local = Path(self.home) / Path(rom).name
        shutil.copyfile(rom, local)
        env = dict(os.environ, XDG_CONFIG_HOME=self.home, HOME=self.home, SDL_AUDIODRIVER="dummy")
        self.proc = subprocess.Popen([mgba, *MGBA_ARGS, "-g", str(local)], env=env,
                                     stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        deadline = time.time() + 30
        while True:
            try:
                self.sock = socket.create_connection(("127.0.0.1", port), timeout=120)
                break
            except OSError:
                if time.time() > deadline or self.proc.poll() is not None:
                    self.close()
                    sys.exit(f"mGBA's GDB stub didn't start for {rom}")
                time.sleep(0.2)
        self.buf = b""

    def packet(self):
        while True:
            i = self.buf.find(b"$")
            j = self.buf.find(b"#", i + 1) if i >= 0 else -1
            if i >= 0 and j >= 0 and len(self.buf) >= j + 3:
                data, self.buf = self.buf[i + 1 : j], self.buf[j + 3 :]
                self.sock.sendall(b"+")
                return unpack(data)
            chunk = self.sock.recv(65536)
            if not chunk:
                sys.exit("mGBA closed the GDB connection")
            self.buf += chunk

    def send(self, body):
        body = body.encode()
        self.sock.sendall(b"$" + body + b"#%02x" % (sum(body) & 0xFF))

    def cmd(self, body):
        self.send(body)
        reply = self.packet()
        # Skip a late stop reply or console output; "OK" is a real answer.
        while reply[:1] in (b"S", b"T") or (reply[:1] == b"O" and reply != b"OK"):
            reply = self.packet()
        return reply

    def resume_until_stop(self):
        self.send("c")
        return self.packet()

    def r0(self):
        return struct.unpack("<I", bytes.fromhex(self.cmd("g")[:8].decode()))[0]

    def read(self, addr, n):
        out = b""
        while n:
            k = min(n, 0x100)  # mGBA answers E06 to larger reads
            reply = self.cmd(f"m{addr:x},{k:x}")
            if reply.startswith(b"E"):
                sys.exit(f"memory read at {addr:#x} failed: {reply.decode()}")
            out += bytes.fromhex(reply.decode())
            addr, n = addr + k, n - k
        return out

    def close(self):
        if getattr(self, "sock", None):
            self.sock.close()
        self.proc.terminate()
        try:
            self.proc.wait(10)
        except subprocess.TimeoutExpired:
            self.proc.kill()
        shutil.rmtree(self.home, ignore_errors=True)


class Symbols:
    """Name an address as symbol+offset from the ELF's own symbol table."""

    def __init__(self, elf):
        out = subprocess.run(["arm-none-eabi-nm", "-n", elf], capture_output=True, text=True,
                             check=True).stdout
        rows = [line.split() for line in out.splitlines()]
        self.rows = [(int(a, 16), n) for a, t, n in (r for r in rows if len(r) == 3)
                     if t not in "aAN" and not n.startswith(("$", "."))]
        self.addrs = [a for a, _ in self.rows]
        self.by_name = {n: a for a, n in self.rows}

    def name(self, value):
        i = bisect.bisect_right(self.addrs, value) - 1
        if i < 0:
            return hex(value)
        addr, name = self.rows[i]
        return f"{name}+{value - addr:#x}"


def render(io, pal, vram, oam):
    """The screen from text or bitmap BGs and regular sprites; no blending."""
    h16 = lambda b, o: struct.unpack_from("<H", b, o)[0]
    rgb = lambda c: bytes(((c & 31) << 3, ((c >> 5) & 31) << 3, ((c >> 10) & 31) << 3))
    dispcnt, w, h = h16(io, 0), 240, 160
    mode = dispcnt & 7
    frame = [[(rgb(h16(pal, 0)), 4, 9)] * w for _ in range(h)]

    def put(x, y, colour, prio, rank):
        if (prio, rank) < frame[y][x][1:]:
            frame[y][x] = (rgb(colour), prio, rank)

    if mode in (3, 4) and dispcnt & 0x400:
        prio, page = h16(io, 0xC) & 3, 0xA000 if dispcnt & 0x10 else 0
        for y in range(h):
            for x in range(w):
                if mode == 3:
                    put(x, y, h16(vram, (y * w + x) * 2), prio, 2)
                elif vram[page + y * w + x]:
                    put(x, y, h16(pal, vram[page + y * w + x] * 2), prio, 2)
    for bg in {0: (0, 1, 2, 3), 1: (0, 1)}.get(mode, ()):
        if not dispcnt & (0x100 << bg):
            continue
        cnt = h16(io, 8 + bg * 2)
        hofs, vofs = h16(io, 0x10 + bg * 4) & 511, h16(io, 0x12 + bg * 4) & 511
        prio, cbase, sbase = cnt & 3, ((cnt >> 2) & 3) * 0x4000, ((cnt >> 8) & 31) * 0x800
        mw, mh = (256, 512)[(cnt >> 14) & 1], (256, 512)[cnt >> 15]
        for y in range(h):
            sy = (y + vofs) % mh
            for x in range(w):
                sx = (x + hofs) % mw
                block = sx // 256 + (sy // 256) * (mw // 256)
                e = h16(vram, sbase + block * 0x800 + ((sy % 256) // 8 * 32 + (sx % 256) // 8) * 2)
                tx, ty = (7 - sx & 7) if e & 0x400 else sx & 7, (7 - sy & 7) if e & 0x800 else sy & 7
                if cnt & 0x80:
                    o = cbase + (e & 0x3FF) * 64 + ty * 8 + tx
                    i = vram[o] if o < 0x10000 else 0
                    colour = h16(pal, i * 2)
                else:
                    o = cbase + (e & 0x3FF) * 32 + ty * 4 + tx // 2
                    i = (vram[o] >> (tx & 1) * 4) & 15 if o < 0x10000 else 0
                    colour = h16(pal, ((e >> 12) * 16 + i) * 2)
                if i:
                    put(x, y, colour, prio, 2 + bg)
    if dispcnt & 0x1000:
        sizes = ((8, 8), (16, 16), (32, 32), (64, 64), (16, 8), (32, 8), (32, 16), (64, 32),
                 (8, 16), (8, 32), (16, 32), (32, 64))
        for n in range(127, -1, -1):
            a0, a1, a2 = struct.unpack_from("<HHH", oam, n * 8)
            if (a0 & 0x300) == 0x200 or a0 >> 14 == 3:
                continue
            sw, sh = sizes[(a0 >> 14) * 4 + (a1 >> 14)]
            y0, x0 = a0 & 255, a1 & 511
            y0, x0 = y0 - 256 if y0 >= 160 else y0, x0 - 512 if x0 >= 240 else x0
            bpp8, tile, prio, bank = a0 & 0x2000, a2 & 0x3FF, (a2 >> 10) & 3, a2 >> 12
            hflip = a1 & 0x1000 and not a0 & 0x100
            vflip = a1 & 0x2000 and not a0 & 0x100
            for py in range(sh):
                for px in range(sw):
                    x, y = x0 + px, y0 + py
                    if not (0 <= x < w and 0 <= y < h):
                        continue
                    sx, sy = (sw - 1 - px) if hflip else px, (sh - 1 - py) if vflip else py
                    step = 2 if bpp8 else 1
                    row = sy // 8 * (sw // 8 * step if dispcnt & 0x40 else 32)
                    t = (tile + row + sx // 8 * step) & 1023
                    if bpp8:
                        i = vram[0x10000 + t * 32 + (sy & 7) * 8 + (sx & 7)]
                        colour = h16(pal, 0x200 + i * 2)
                    else:
                        i = (vram[0x10000 + t * 32 + (sy & 7) * 4 + (sx & 7) // 2] >> (sx & 1) * 4) & 15
                        colour = h16(pal, 0x200 + (bank * 16 + i) * 2)
                    if i:
                        put(x, y, colour, prio, 1)
    return [[p[0] for p in row] for row in frame]


def png(rows, path):
    raw = b"".join(b"\0" + b"".join(row) for row in rows)

    def chunk(kind, data):
        return (struct.pack(">I", len(data)) + kind + data
                + struct.pack(">I", zlib.crc32(kind + data) & 0xFFFFFFFF))

    header = struct.pack(">IIBBBBB", len(rows[0]), len(rows), 8, 2, 0, 0, 0)
    path.write_bytes(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", header)
                     + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))


# InitIntrHandlers copies 0x800 bytes of ROM from IntrMain to EWRAM. Past
# IntrMain's own code that copy is whatever follows it in the ROM, which is
# exactly what the shift moves, so it's skipped.
RAM_SKIP = (0x020005D0, 0x02000DD0)


def shift_of(base, shifted):
    """(first moved base address, ROM end, delta) from the two symbol tables.
    Only names defined once count: every object has its own
    `.gcc2_compiled.`, and pairing two of those gives a false delta."""
    once = Counter(n for _, n in base.rows)
    moved = sorted((a, shifted.by_name[n] - a) for a, n in base.rows
                   if once[n] == 1 and n in shifted.by_name
                   and 0x08000000 <= a < 0x0A000000
                   and shifted.by_name[n] != a)
    if not moved:
        sys.exit("the two ELFs have the same addresses: nothing was shifted")
    start, delta = moved[0]
    return start, max(a for a, _ in base.rows if a < 0x0A000000), delta


def moved_pointer(base, shifted):
    """Whether two words are one ROM pointer: the same symbol+offset in each
    build. An edited asset that grows moves each later region by its own
    amount, so a single delta can't describe the shift."""
    def moved(a, b):
        return (0x08000000 <= a < 0x0A000000 and 0x08000000 <= b < 0x0A000000
                and base.name(a) == shifted.name(b))
    return moved


def ram_diffs(base, shifted, moved):
    """RAM addresses whose words differ other than by a moved ROM pointer."""
    out = []
    for i, (a, b) in enumerate(zip(base, shifted)):
        if a == b or moved(a, b):
            continue
        addr = 0x02000000 + i * 4 if i < 0x10000 else 0x03000000 + (i - 0x10000) * 4
        if not RAM_SKIP[0] <= addr < RAM_SKIP[1]:
            out.append(addr)
    return out


def state(stub):
    """Display registers, palette, VRAM, OAM, and work RAM as words."""
    display = (stub.read(0x04000000, 0x60), stub.read(0x05000000, 0x400),
               stub.read(0x06000000, 0x18000), stub.read(0x07000000, 0x400))
    ram = stub.read(0x02000000, 0x40000) + stub.read(0x03000000, 0x8000)
    return display, list(struct.unpack(f"<{len(ram) // 4}I", ram))


def run(mgba, elf, rom, tag):
    """Loads per decompression stop, and {checkpoint: (screen hash, RAM)}."""
    syms = Symbols(elf)
    vblank = syms.by_name["VBlankIntr"]
    stub = Stub(mgba, rom)
    loads, hashes, frames = [], {}, 0

    def checkpoint(key):
        display, ram = state(stub)
        hashes[key] = (hashlib.sha1(b"".join(display)).hexdigest(), ram)
        png(render(*display), OUT / f"{tag}_{key}.png")
        print(f"  {tag} {key}: screen {hashes[key][0][:12]}", flush=True)

    try:
        for addr in (vblank, *(syms.by_name[n] for n in BREAKPOINTS)):
            if stub.cmd(f"Z0,{addr:x},2") != b"OK":
                sys.exit(f"mGBA refused a breakpoint at {addr:#x}")
        stub.sock.settimeout(IDLE)
        while len(loads) < HITS:
            if frames == FRAMES:
                stub.cmd(f"z0,{vblank:x},2")
                frames += 1
            try:
                stub.resume_until_stop()
            except socket.timeout:
                # No load for IDLE seconds of unthrottled play: without
                # baserom.gba the game stops loading after the boot logos.
                stub.sock.settimeout(30)
                stub.sock.sendall(b"\x03")
                stub.packet()
                print(f"  {tag}: no load after stop {len(loads)}", flush=True)
                break
            regs = bytes.fromhex(stub.cmd("g")[:128].decode())
            src, dst = struct.unpack_from("<II", regs)
            pc = struct.unpack_from("<I", regs, 60)[0]
            if pc == vblank:
                frames += 1
                if frames % FRAME_CHECKPOINT == 0:
                    checkpoint(f"frame{frames:04d}")
                continue
            loads.append((syms.name(src), dst))
            if len(loads) % CHECKPOINT == 0:
                checkpoint(f"load{len(loads):04d}")
    finally:
        stub.close()
    return loads, hashes


def main():
    if len(sys.argv) != 5:
        sys.exit(__doc__)
    base_elf, base_rom, shift_elf, shift_rom = sys.argv[1:]
    mgba = find_mgba()
    OUT.mkdir(parents=True, exist_ok=True)
    base_syms, shift_syms = Symbols(base_elf), Symbols(shift_elf)
    shift = shift_of(base_syms, shift_syms)
    moved = moved_pointer(base_syms, shift_syms)
    print(f"shift test: {shift[2]:#x} bytes from {shift[0]:#x}; {FRAMES} frames, then up to "
          f"{HITS} loads per build; mGBA {mgba}")
    base = run(mgba, base_elf, base_rom, "base")
    time.sleep(1)  # let the first stub release its port
    shifted = run(mgba, shift_elf, shift_rom, "shift")
    failed = False
    if len(base[0]) != len(shifted[0]):
        print(f"base made {len(base[0])} loads, shifted made {len(shifted[0])}")
        failed = True
    bad = [i + 1 for i, (a, b) in enumerate(zip(base[0], shifted[0])) if a != b]
    for i in bad[:10]:
        print(f"load {i}: base read {base[0][i - 1]}, shifted read {shifted[0][i - 1]}")
    for key in sorted(set(base[1]) | set(shifted[1])):
        a, b = base[1].get(key), shifted[1].get(key)
        if a is None or b is None:
            print(f"{key}: only one build reached it")
            failed = True
            continue
        if a[0] != b[0]:
            print(f"{key}: screens differ; see {OUT}/base_{key}.png and shift_{key}.png")
            failed = True
        diffs = ram_diffs(a[1], b[1], moved)
        if diffs:
            print(f"{key}: {len(diffs)} RAM words differ")
            for addr in diffs[:8]:
                i = (addr - 0x02000000 if addr < 0x03000000 else 0x40000 + addr - 0x03000000) // 4
                print(f"  {addr:#010x}: base {a[1][i]:#010x}, shifted {b[1][i]:#010x}")
            failed = True
    if bad or failed:
        sys.exit("SHIFT TEST FAILED")
    print(f"SHIFT TEST OK: {len(base[0])} loads and {len(base[1])} checkpoints match "
          f"(screens in {OUT})")


def _selftest():
    assert unpack(b"0*\"") == b"0" * 6, unpack(b"0*\"")
    assert unpack(b"a}\x5db") == b"a}b"
    stub = Stub.__new__(Stub)
    stub.buf, stub.sock = b"$S05#b8$OK#9a", type("Sock", (), {"sendall": lambda self, b: None})()
    stub.send = lambda body: None
    assert stub.cmd("Z0,0,2") == b"OK", "a stop reply must be skipped and OK kept"
    rows = [[b"\x10\x20\x30"] * 2] * 2
    with tempfile.TemporaryDirectory() as tmp:
        path = Path(tmp) / "t.png"
        png(rows, path)
        data = path.read_bytes()
        assert data.startswith(b"\x89PNG") and b"IEND" in data
    def shift(a, b):
        return 0x0800020C <= a <= 0x083FFF00 and b == a + 0x104
    base = [0x08001000, 0x08070000, 0x00000005, 0x08000104] + [0] * 0x11FFC
    good = [0x08001104, 0x08070000, 0x00000005, 0x08000104] + [0] * 0x11FFC
    assert ram_diffs(base, good, shift) == [], "a moved pointer or an equal word is fine"
    bad = good[:2] + [0x00000006] + good[3:]
    assert ram_diffs(base, bad, shift) == [0x02000008], "diverged state must differ"
    skipped = base[:0x174] + [1] + base[0x175:]
    assert ram_diffs(base, skipped, shift) == [], "the IntrMain copy is skipped"
    print("selftest ok")


if __name__ == "__main__":
    if sys.argv[1:] == ["--selftest"]:
        _selftest()
    else:
        main()
