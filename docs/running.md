# Running the game

Two different questions get conflated here. Separating them:

1. **During decomp** — can we run a partially-decompiled build?
2. **After decomp** — can we compile the C natively and run the game on a PC,
   using the ROM only for its assets?

## 1. During decomp: there is nothing to substitute

While the build matches, the output is *bit-identical* to retail:

```
$ cmp nascar-heat.gba baserom.gba && echo identical
identical
```

Zero differing bytes. "Substituting our code into the retail ROM" is a no-op —
our code **is** the retail ROM's bytes. Boot `nascar-heat.gba` in any emulator
and you are booting retail, because the two files cannot be told apart.

This is also why the linker rejects a half-finished extraction:

```
arm-none-eabi-ld: build/src/probe.o: in function `sub_08006734':
  multiple definition of `sub_08006734';
  build/asm/rom.o:(.text+0x6734): first defined here
```

Adding C without removing the assembly is a hard error, not a silent
double-definition. The decomp loop is a *swap*, never an overlay: delete the
function from `asm/rom.s`, link the C object at the same address.

So during decomp there is no "hybrid ROM" step and no separate testing story.
Byte-identical output is behaviorally identical by construction; the SHA-1 is
the test.

### If the match is ever lost

Then the question becomes real, because the ROM is no longer retail. At that
point build it, boot it in mGBA next to `baserom.gba`, and compare. Nobody has
done this yet because there has never been a non-matching build.

## 2. After decomp: a native port

This is the more interesting goal and it is achievable, but the ROM's shape
determines how much work it is.

The ROM is **96% data**:

| | Bytes | Share |
|---|---:|---:|
| Code (3 regions from `docs/recon.md`) | 165,212 | 3.9% |
| Data / assets | 4,029,092 | 96.1% |

So a native build needs the ROM as an **asset pack**, exactly as you describe:
compile the C for x86-64/ARM64, load tracks, cars, audio, and tables from the
original ROM at runtime. That is the standard approach for finished decomps
(ship code, require the user's own ROM), and it keeps the project legally clean
since no copyrighted data is redistributed.

What stands between here and there:

- **Hardware access must be abstracted.** The code writes GBA MMIO directly —
  DMA registers at `0x040000xx`, VRAM at `0x06000000`, key input at `0x04000130`,
  the IRQ vector at `0x03007FFC`. Every one of those needs a backend (SDL,
  or similar) instead of a raw store. Recon already found the crt0 doing exactly
  this at `0x080000C0`.
- **The IRQ model must be emulated or replaced.** `sub_08000380` DMA-copies the
  handler to work RAM and repoints `0x03007FFC`. A native port needs an event
  loop where the game expects VBlank interrupts.
- **Endianness and word size are fine; alignment is not.** ARM7TDMI is
  little-endian like x86-64, but the code assumes 32-bit `int`/pointers and
  performs unaligned-sensitive tricks. Struct layouts read out of ROM data must
  be byte-exact.
- **`asm/rom.s` must be fully gone.** A native target cannot link Thumb assembly.
  Every one of the 743 functions has to become C first — including the libgcc
  helpers and BIOS wrappers, which get replaced by host equivalents rather than
  translated.
- **Asset formats must be understood.** Byte-matching code does not decode the
  96%. Locating and parsing the track/model/audio tables is a separate research
  effort that matching does not advance at all.

### Order of operations

The native port is a **downstream** project, not a parallel one:

```
743/743 functions matching   ->   asm/rom.s empty
        ->   swap GBA MMIO for a HAL   ->   native build
```

Attempting it earlier means maintaining two divergent builds while the C is
still changing shape under you. The matching build is the ground truth that
makes the port trustworthy; give that up early and there is nothing left to
check the port against.

## Current status

Run `python3 scripts/progress.py` for the live figure.
