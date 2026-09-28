# NASCAR Heat 2002 (GBA) — binary reconnaissance

## Executive summary

| Item | Result |
|---|---:|
| ROM | `baserom.gba` |
| Size | 4,194,304 bytes (`0x400000`) |
| SHA-1 | `0eb1fa43d8b0f8a6fb1e3ac04f7bba92c7cbac96` |
| Marked functions in `asm/rom.s` | **743** |
| Explicitly rendered instructions in those functions | **51,034** |
| `bl`-leaf / non-leaf functions | **304 / 439** |
| Header branch target | **`0x080000C0`** |
| Strongest first decompilation candidate | **`DummyUiFontLoad [sub_08006734]`**: 1 instruction, leaf, 38 distinct callers |

`baserom.gba` and the current `nascar-heat.gba` are both 4,194,304 bytes, have the stated SHA-1, and compare byte-for-byte equal.

## Methodology and scope

1. The parser discarded everything through the exact line `@ End embedded Luvdis macros` (line 34) before looking for starts. It then accepted only indented invocations of:
   - `thumb_func_start`
   - `non_word_aligned_thumb_func_start`
   - `arm_func_start`
2. This finds **743 real macro invocations**: 735 `thumb_func_start` and 8 `non_word_aligned_thumb_func_start`; there are no real `arm_func_start` invocations. No function named `name` was admitted. As an independent check, `arm-none-eabi-nm` and `readelf` each report exactly 743 `sub_08...` function symbols in the linked ELF.
3. The superficially plausible count 745 comes from counting every line containing the substring `thumb_func_start`: it includes the two Thumb-related `.macro ... name` definition lines in the preamble. Thus **743**, rather than 745, is the correct inventory of call sites in this file.
4. A function body was taken from its start invocation to the next start invocation (or EOF). An “instruction” is an explicitly rendered mnemonic line. Labels, comments, macro lines, alignment, literal pools, and `.byte`/`.2byte`/`.4byte` data were excluded.
5. “Leaf” means exactly what the task requests: no explicit `bl` mnemonic in the rendered body. There are no explicit `blx` mnemonics. Indirect transfers (`bx rN`, `mov pc, rN`), tail branches, BIOS `swi`, and calls encoded inside raw data directives are not treated as `bl` calls.
6. The call graph includes direct `bl target` edges only when `target` is one of the 743 marked starts. In-degree is the number of **distinct marked caller functions**, not the number of call sites. Out-degree is the number of **distinct marked callees**.

### Important limitation

`asm/rom.s` reproduces the entire ROM, but substantial ranges—including some executable code—remain emitted as raw `.byte` or `.2byte` directives. Consequently, the instruction sizes and direct-call graph below describe the **marked, explicitly decoded function inventory**, not every executable instruction in the ROM. In particular, 53 rendered `bl` sites target 19 labels that are not marked function starts, and calls hidden in raw byte regions cannot be recovered by the textual parser. A few isolated start markers inside asset-like byte runs also look like false discoveries; these are called out below rather than silently removed.

## 1. Function inventory

### Size statistics

| Statistic | Instructions |
|---|---:|
| Minimum | **1** |
| Maximum | **1,505** (`sub_08015364`) |
| Median | **36** |
| Mean | **68.69** |
| Total | **51,034** |

There are 21 one-instruction marked bodies. Nineteen are return-only stubs (`bx lr` or `mov pc, lr`); two suspicious non-word-aligned markers consist only of a `push` followed by raw bytes.

### Histogram

| Explicit instruction count | Functions | Share |
|---:|---:|---:|
| 1–5 | 58 | 7.81% |
| 6–10 | 55 | 7.40% |
| 11–20 | 105 | 14.13% |
| 21–50 | 235 | 31.63% |
| 51–100 | 168 | 22.61% |
| >100 | 122 | 16.42% |
| **Total** | **743** | **100.00%** |

### Leaf status

| Class | Functions | Share |
|---|---:|---:|
| No explicit `bl` (“leaf”) | **304** | **40.92%** |
| At least one explicit `bl` | **439** | **59.08%** |

### 25 smallest leaf functions

Ties are ordered by address. The caller column is included to distinguish merely easy stubs from high-leverage candidates.

| # | Function | Address | Instructions | Distinct marked callers |
|---:|---|---:|---:|---:|
| 1 | `DummyHudHook [sub_08005AEC]` | `0x08005AEC` | 1 | 0 |
| 2 | `DummyUiFontLoad` | `0x08006734` | 1 | **38** |
| 3 | `sub_0800B614` | `0x0800B614` | 1 | 1 |
| 4 | `sub_0800BA34` | `0x0800BA34` | 1 | 1 |
| 5 | `sub_0800E708` | `0x0800E708` | 1 | 1 |
| 6 | `sub_0800E730` | `0x0800E730` | 1 | 1 |
| 7 | `sub_08011D2C` | `0x08011D2C` | 1 | 1 |
| 8 | `sub_08012384` | `0x08012384` | 1 | 1 |
| 9 | `sub_08014BA0` | `0x08014BA0` | 1 | 0 |
| 10 | `sub_080172C4` | `0x080172C4` | 1 | 3 |
| 11 | `sub_0801A568` | `0x0801A568` | 1 | 3 |
| 12 | `sub_0801A56C` | `0x0801A56C` | 1 | 3 |
| 13 | `sub_08120E3A` † | `0x08120E3A` | 1 | 0 |
| 14 | `sub_08248272` † | `0x08248272` | 1 | 0 |
| 15 | `sub_0833D9E8` | `0x0833D9E8` | 1 | 2 |
| 16 | `sub_0833E5E8` | `0x0833E5E8` | 1 | 0 |
| 17 | `sub_08341280` | `0x08341280` | 1 | 1 |
| 18 | `sub_08342DE4` | `0x08342DE4` | 1 | 1 |
| 19 | `sub_08343138` | `0x08343138` | 1 | 1 |
| 20 | `sub_08344680` | `0x08344680` | 1 | 1 |
| 21 | `sub_08344C4C` | `0x08344C4C` | 1 | 3 |
| 22 | `sub_08016E0C` | `0x08016E0C` | 2 | 2 |
| 23 | `sub_08016E10` | `0x08016E10` | 2 | **24** |
| 24 | `sub_08016E1C` | `0x08016E1C` | 2 | 1 |
| 25 | `sub_08016E28` | `0x08016E28` | 2 | 7 |

† `sub_08120E3A` and `sub_08248272` are not sound decompilation candidates despite their measured size. Each is a non-word-aligned marker in a long data-like `.byte` run, renders only a `push`, has no rendered epilogue, and has no marked caller. Their one-instruction result is evidence of incomplete/false decoding, not a genuine one-instruction routine.

## 2. Entry-point analysis

### Header branch

The first four ROM bytes are `2E 00 00 EA`, or ARM word `0xEA00002E`:

```text
ARM B target = instruction_address + 8 + sign_extend(imm24 << 2)
             = 0x08000000 + 8 + (0x2E << 2)
             = 0x080000C0
```

The actual entry is therefore **`0x080000C0`**.

### What is present there

`asm/rom.s` does not give `0x080000C0` a function-start macro or a local label. It lies inside the raw `.byte` block beginning at `_08000000`. Independent ARM/Thumb disassembly gives this startup path:

| Address | Observed action |
|---:|---|
| `0x080000C0` | Set CPSR mode to IRQ (`0x12`). |
| `0x080000C8` | Load IRQ stack pointer `sp = 0x03007FA0`. |
| `0x080000CC` | Set CPSR mode to System (`0x1F`). |
| `0x080000D4` | Load System stack pointer `sp = 0x03007E00`. |
| `0x080000D8`–`0x080000E0` | Store `0x08000104` at `0x03007FFC`, the GBA IRQ vector hook. |
| `0x080000E4`–`0x080000EC` | Load `0x0800020D` and `bx` to it; bit 0 selects Thumb, so execution continues at `0x0800020C`. |
| `0x080000F0` | If control returns, branch back to `0x080000C0`. |

`0x08000104` is an ARM interrupt dispatcher. It reads the interrupt registers around `0x04000200`, selects a pending interrupt, acknowledges it, switches processor mode, and indirect-calls a handler from the table based at `0x02000590`. It restores the saved state before returning with `bx lr`.

At `0x0800020C`, raw Thumb code executes:

```text
0x0800020C  push {lr}
0x0800020E  bl   0x08002638
0x08000212  b    0x0800020E
```

Thus the first marked game-side target is `sub_08002638`.

### Direct startup call trace

`sub_08002638` has 73 rendered instructions and eight distinct direct callees, in this order:

| Callee | Instructions | What is directly observable |
|---|---:|---|
| `sub_08016E2C` | 2 | `swi #1; bx lr` (`RegisterRamReset`). |
| `sub_08000380` | 37 | Calls `sub_08000430`; installs/copies the IRQ machinery. |
| `sub_0800048C` | 16 | Leaf; reads `0x04000130`, inverts the key bits, and updates halfwords at `0x020005C8`/`0x020005CC`. |
| `sub_080003F8` | 7 | Leaf; installs a callback pointer at `0x02000580`, with `0x0800042D` as fallback. |
| `sub_08003F4C` | 26 | Leaf; expands one 15-bit value into 256 three-word entries at `0x02022E20`. |
| `sub_0800420C` | 19 | Calls `sub_08003F84`, then repeatedly calls `sub_08000458` and `sub_08004144`. |
| `sub_08000458` | 12 | Calls `sub_08000430`, executes `swi #2`, and waits on a flag at `0x02000DD0`. |
| `sub_08015364` | 1,505 | Called forever at `0x080026D4`; contains 196 rendered `bl` sites and 76 distinct marked callees. |

One level deeper, `sub_08000380` DMA-copies code beginning at `0x08000104` to `0x020005D0`, changes the vector at `0x03007FFC` to `0x020005D0`, writes `0x4014` to `0x04000204`, and initializes the handler table at `0x02000590`. This confirms that the ARM block at `0x08000104` is the installed IRQ dispatcher rather than ordinary game logic.

A separate raw Thumb routine at `0x08000214` calls a DMA-based RAM clear routine at `0x08000224`, then calls the first marked function, `sub_08000260`. `sub_08000260` in turn calls `sub_08000274`, `sub_0800029C`, and `sub_08000300`. No direct path from the active header entry to `0x08000214` was observed, so it should not be inserted into the active trace without further evidence.

### Startup identification

The sequence is a clear **AGB crt0/startup pattern**: standard header branch, separate IRQ/System stack initialization, IRQ vector installation at `0x03007FFC`, ARM-to-Thumb interworking through an odd address, a Thumb main-entry veneer, and an ARM IRQ dispatcher later copied to work RAM.

## 3. Direct call graph

### Aggregate graph

| Metric | Result |
|---|---:|
| Marked vertices | 743 |
| Explicit `bl` sites in marked bodies | 2,803 |
| Sites resolving to marked starts | 2,750 |
| Sites resolving only to unmarked labels | 53 (19 distinct targets) |
| Distinct marked-to-marked edges | 1,616 |
| Functions with in-degree 0 / >0 | 110 / 633 |
| Functions with marked out-degree 0 / >0 | 317 / 426 |
| Median in-degree / out-degree | 1 / 1 |
| Mean in-degree / out-degree | 2.175 / 2.175 |
| Maximum out-degree | 76 (`sub_08015364`) |

The 317 zero-out-degree vertices exceed the 304 `bl`-leaf functions because 13 functions contain `bl` instructions but call only unmarked labels.

### Top 20 by distinct marked callers

Repeated calls from one function count once in “callers” and separately in “BL sites.” Ties are broken by ascending address. The cutoff falls inside an eight-way tie at in-degree 11; the four lower-address entries are shown to keep the table at exactly 20 rows.

| Rank | Function | Address | Distinct callers (in) | BL sites | Distinct callees (out) | Instructions |
|---:|---|---:|---:|---:|---:|---:|
| 1 | `sub_08016558` | `0x08016558` | **51** | 159 | 0 | 6 |
| 2 | `sub_08000458` | `0x08000458` | **48** | 78 | 1 | 12 |
| 3 | `sub_080065A8` | `0x080065A8` | **42** | 42 | 0 | 189 |
| 4 | `sub_0800420C` | `0x0800420C` | **41** | 60 | 3 | 19 |
| 5 | `sub_08004238` | `0x08004238` | **41** | 42 | 3 | 17 |
| 6 | `sub_0800048C` | `0x0800048C` | **40** | 46 | 0 | 16 |
| 7 | `sub_08006950` | `0x08006950` | **39** | 120 | 0 | 61 |
| 8 | `DummyUiFontLoad` | `0x08006734` | **38** | 38 | 0 | 1 |
| 9 | `sub_08001208` | `0x08001208` | **36** | 77 | 1 | 17 |
| 10 | `sub_08017230` | `0x08017230` | **26** | 78 | 1 | 72 |
| 11 | `sub_08011C9C` | `0x08011C9C` | **24** | 25 | 4 | 59 |
| 12 | `sub_08016E10` | `0x08016E10` | **24** | 51 | 0 | 2 |
| 13 | `sub_08344BB8` | `0x08344BB8` | **16** | 60 | 1 | 72 |
| 14 | `sub_080063BC` | `0x080063BC` | **14** | 69 | 0 | 40 |
| 15 | `sub_08011D38` | `0x08011D38` | **14** | 16 | 1 | 51 |
| 16 | `sub_0800F328` | `0x0800F328` | **13** | 13 | 2 | 53 |
| 17 | `sub_080044A4` | `0x080044A4` | **11** | 12 | 0 | 23 |
| 18 | `sub_080078E4` | `0x080078E4` | **11** | 11 | 0 | 30 |
| 19 | `sub_0800793C` | `0x0800793C` | **11** | 11 | 0 | 8 |
| 20 | `sub_0800F3A4` | `0x0800F3A4` | **11** | 12 | 0 | 11 |

The other in-degree-11 functions at the cutoff are `sub_080172C8`, `sub_0801B734`, `sub_0833FF44`, and `sub_0833FF94`.

### Runtime/library routines identifiable from shape

Names are stripped, so the identities below are behavioral matches, not recovered symbols.

#### Compiler arithmetic helpers

| Marked function(s) | Instr. each | Caller count(s) | Probable conventional identity | Shape evidence |
|---|---:|---:|---|---|
| `sub_08017230`, `sub_08344BB8` | 72 | 26, 16 | signed 32-bit divide (`__divsi3`) | Normalizes operand signs, builds a quotient with shift/subtract, reapplies quotient sign, and invokes a divide-by-zero hook. |
| `sub_080172C8`, `sub_08344C50` | 102 | 11, 7 | signed 32-bit remainder (`__modsi3`) | Same division core but preserves/re-signs the remainder in `r0`. |
| `sub_08017498`, `sub_08344DA8` | 95 | 7, 1 | unsigned 32-bit remainder (`__umodsi3`) | Unsigned shift/subtract remainder loop and divide-by-zero hook. |
| `sub_08017398`, `sub_08344D20` | 54 | 3, 2 | 64-bit multiply (`__muldi3`) | Splits words into 16-bit halves, combines partial products, and returns a two-register result. |
| `sub_08017408`, `sub_08344D90` | 11 | 1, 0 | 64-bit negate (`__negdi2`) | Two-word negation with carry correction. |
| `sub_0801A6FC` | 41 | 3 | count leading zeros (`__clzsi2`) | Binary 16/8/4/2/1-bit tests returning a count from 0 through 32. |
| `sub_0801CCD4` | 38 | 2 | 64-bit logical right shift (`__lshrdi3`) | Shifts a value in `r1:r0` by `r2`, including the crossing-32-bit case. |
| `sub_080172C4`, `sub_08344C4C` | 1 | 3, 3 | divide-by-zero hook (`__div0`) | Each is an empty return and is reached by the division helpers’ zero-divisor paths. |

The unsigned divide companion begins at unmarked label `_08017420`, is emitted as raw bytes, and behaviorally matches `__udivsi3`. It has 25 rendered call sites from eight distinct marked callers, but it is not one of the 743 graph vertices because there is no function-start macro. Raw ranges `_080171F8`, `_08017200`, `_08017214`, and `_08344B80` contain regular `bx rN; nop` sequences characteristic of compiler interworking/call-via-register veneers; they are likewise excluded as vertices.

The opcode sequences of each primary/late arithmetic pair above are identical in length and order. This is direct evidence of duplicated runtime code in two executable regions.

#### Software floating-point support

The block around `0x0801B5EC`–`0x0801C630` is also runtime-shaped. `sub_0801B734` (95 instructions) extracts a 64-bit IEEE-754 sign, 11-bit exponent, and 52-bit fraction, uses exponent `0x7FF` to distinguish infinity/NaN, normalizes subnormals, and writes an internal classification/sign/exponent/significand structure. `sub_0801B5EC` (137 instructions) performs the inverse packing and rounding operation. The analogous 32-bit routines are `sub_0801C440` (59 instructions, unpack/classify) and `sub_0801C388` (84 instructions, round/pack), visibly using exponent `0xFF`, fraction mask `0x007FFFFF`, and sign bit 31. Nearby marked and raw-byte routines operate on those intermediate structures with multiword shifts and arithmetic. This establishes a software floating-point support family, but the stripped symbols and raw-byte boundaries do not justify assigning exact conventional helper names to every member.

#### Memory primitives

| Function | Instructions | Distinct callers | Behavioral match |
|---|---:|---:|---|
| `sub_0801A42C` | 47 | 2 | `memcpy`: aligned word-copy fast path, byte tail, returns original destination. |
| `sub_0801A48C` | 68 | 1 | `memmove`: overlap test and backward copy when needed, otherwise forward word/byte copy. |
| `sub_0801A514` | 41 | 2 | `memset`: replicates the low byte across a word, writes 16-byte/4-byte blocks, then a byte tail. |

#### BIOS service wrappers

These are system-library wrappers rather than compiler arithmetic, but their shapes and high reuse make them relevant decompilation targets.

| Primary function | Duplicate, if present | BIOS SWI | Service indicated by the GBA BIOS ABI |
|---|---|---:|---|
| `sub_08016E0C` | `sub_08344B60` | `0x0C` | `CpuFastSet` |
| `sub_08016E10` | `sub_08344B64` | `0x0B` | `CpuSet` |
| `sub_08016E14` | `sub_08344B68` | `0x04` | `IntrWait` |
| `sub_08016E1C` | — | `0x12` | `LZ77UnCompVram` |
| `sub_08016E20` | — | `0x25` | `MultiBoot` |
| `sub_08016E28` | `sub_08344B70` | `0x15` | `RLUnCompVram` |
| `sub_08016E2C` | — | `0x01` | `RegisterRamReset` |
| `sub_08016E30` | `sub_08344B74` | `0x05` | `VBlankIntrWait` |

## 4. Code regions and marker-free gaps

There is a natural separation in adjacent function-start distances: the largest gap inside a dense run is `0x0FCC`, while the next larger gap is `0x447E`. Using `0x1000` (4 KiB) as the split threshold produces the following marker regions.

| First–last marked start | Marked functions | Rendered instructions | Start-to-start span | Assessment from bytes/disassembly |
|---|---:|---:|---:|---|
| `0x08000260`–`0x0801CCD4` | **529** | **37,777** | `0x1CA74` (117,364 B) | Primary dense executable region after crt0. |
| `0x08026DB6` | 1 | 4 | — | Isolated, truncated-looking marker in raw data. |
| `0x080462B2` | 1 | 2 | — | Isolated, truncated-looking marker in raw data. |
| `0x08120E3A`–`0x08121316` | 2 | 9 | `0x4DC` (1,244 B) | Two suspicious partial decodes inside a long data-like run. |
| `0x08248272` | 1 | 1 | — | Isolated, truncated-looking marker in raw data. |
| `0x0824C6F0` | 1 | 2 | — | Isolated, truncated-looking marker in raw data. |
| `0x0827B7CA` | 1 | 4 | — | Isolated, truncated-looking marker in raw data. |
| `0x08339920`–`0x08344DA8` | **202** | **12,997** | `0xB488` (46,216 B) | Dense secondary executable region. |
| `0x0836419C`–`0x083647FC` | **5** | **238** | `0x660` (1,632 B) | Small executable island after another ARM startup. |

The seven isolated markers account for only 22 rendered instructions. They should not be used as evidence that the surrounding hundreds of kilobytes are executable.

### Large adjacent-start gaps

These are start-to-start deltas, not asserted function extents: a small prefix can belong to the function at the left edge. The interiors are overwhelmingly represented by raw data directives.

| Previous marked start | Next marked start | Delta | Approx. size |
|---:|---:|---:|---:|
| `0x0801CCD4` | `0x08026DB6` | `0xA0E2` | 41,186 B (40.22 KiB) |
| `0x08026DB6` | `0x080462B2` | `0x1F4FC` | 128,252 B (125.25 KiB) |
| `0x080462B2` | `0x08120E3A` | `0xDAB88` | 895,880 B (874.88 KiB) |
| `0x08121316` | `0x08248272` | `0x126F5C` | **1,208,156 B (1.152 MiB)** |
| `0x08248272` | `0x0824C6F0` | `0x447E` | 17,534 B (17.12 KiB) |
| `0x0824C6F0` | `0x0827B7CA` | `0x2F0DA` | 192,730 B (188.21 KiB) |
| `0x0827B7CA` | `0x08339920` | `0xBE156` | 778,582 B (760.33 KiB) |
| `0x08344DA8` | `0x0836419C` | `0x1F3F4` | 127,988 B (124.99 KiB) |
| `0x083647FC` | ROM end `0x08400000` | `0x9B804` | 636,932 B (622.00 KiB) |

The large middle ranges are therefore likely dominated by data/assets, subject to two concrete exceptions: executable payloads are embedded near the end of the ROM.

- `0x08339780` begins with an exact 52-byte match to the primary ARM startup sequence at `0x080000C0`; its raw IRQ/Thumb prelude leads into the dense `0x08339920` marker cluster.
- The exact 156-byte Nintendo logo sequence occurs twice in the ROM: at the primary header’s `0x08000004` and at `0x08363EEC`, immediately after an ARM branch at `0x08363EE8`. ARM startup code follows, with marked functions beginning at `0x0836419C`.
- The late cluster also contains opcode-for-opcode duplicates of the primary BIOS and libgcc-style helper families described above.

Those byte-level facts establish that the two late islands are executable code; they do not establish what game feature uses them.

## 5. Decompilation recommendation

### First choice: `DummyUiFontLoad`

Decompile **`DummyUiFontLoad` first**.

- **1 instruction:** `bx lr`.
- **Leaf:** no `bl`, no dependencies, no state access.
- **38 distinct callers / 38 call sites:** eighth-highest in-degree in the entire marked graph.
- Among the other valid one-instruction return stubs, none has more than three marked callers. This is therefore not merely the easiest class of function; it is an extreme outlier in leverage within that class.

If the sole objective were absolute caller coverage, `sub_08016558` would win with 51 callers. The recommended first commit instead gives up only 13 callers in exchange for reducing the body from six instructions to one, making it the lowest-risk end-to-end test of the C/assembler/linker matching workflow.

### Ranked next five

| Overall rank | Function | Instructions | Leaf | Distinct callers | BL sites | Why it follows |
|---:|---|---:|:---:|---:|---:|---|
| 2 | `sub_08016558` | 6 | Yes | **51** | 159 | Highest in-degree overall; a leaf consisting only of argument narrowing, a table address calculation, one load, and return. |
| 3 | `sub_08016E10` | 2 | Yes | **24** | `swi #11; bx lr`; extremely small and twelfth-highest in-degree overall. |
| 4 | `sub_0800048C` | 16 | Yes | **40** | Sixth-highest in-degree; larger than the wrappers but still a short, straight-line leaf. |
| 5 | `sub_08344B64` | 2 | Yes | 8 | Exact late-region duplicate of `sub_08016E10`; the matching approach should transfer directly. |
| 6 | `sub_08016E28` | 2 | Yes | 7 | Another two-instruction BIOS wrapper (`swi #21; bx lr`) with seven distinct callers and 23 call sites. |

The ranking deliberately balances, rather than conflates, two goals:

- **Easiest:** return-only and two-instruction SWI wrappers minimize code-generation uncertainty. The SWI wrappers may still require inline assembly or an established BIOS-call idiom in C.
- **Highest leverage:** `sub_08016558` and `sub_0800048C` touch 51 and 40 distinct callers respectively, but have more register/type/literal-pool choices to match.

This is why `DummyUiFontLoad` is the clear first function, while `sub_08016558` is the clear next target once the extraction pipeline is proven.
