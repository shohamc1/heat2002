<!-- parsed 1158 functions; 780 decompiled, 221 remaining targets, 158 non-targets -->
<!-- luvdis blocks not tracked by the project (skipped): sub_08000B1C, sub_0833A1DC, sub_083647F8, sub_08364800, sub_08364804, sub_08364808 -->
<!-- NOTE: sub_080000C0 not in rom_reference.s -->
<!-- NOTE: sub_08000104 not in rom_reference.s -->
<!-- NOTE: sub_08339780 not in rom_reference.s -->
<!-- NOTE: sub_083397C4 not in rom_reference.s -->
<!-- NOTE: sub_08363FC8 not in rom_reference.s -->
<!-- NOTE: sub_08363FF4 not in rom_reference.s -->
<!-- NOTE: sub_083640B0 not in rom_reference.s -->
# Function twins — remaining functions vs. already-decompiled ones

Method: every function's instruction stream from `build/rom_reference.s` (the ROM itself, so decompiled and remaining functions share one format), normalized so a relocated copy matches its original: branch targets become offsets from function start, pool loads and `bl` targets are masked (pool values recorded separately), registers and small immediates kept. Validated on the known pair `sub_08343EA8`/`sub_0800D684`, which normalizes identical.

Caveats: 'exact' means identical modulo call targets and pool constants — port the twin's C, then rename the called functions and globals it references (the high 0x0834 module keeps its own copies of both). 'moved' pool constants are the copy's own data addresses; 'same' plus exact tokens is a literal duplicate.

Regenerate after any batch of matches: `make disasm && python3 scripts/find_twins.py > docs/function-twins.md`.

## Summary — 0 exact copies, 17 near matches

Of 221 remaining game-code functions, 0 are instruction-identical (modulo relocated pool/call targets) to an already-decompiled function, and 17 are ≥80% similar. 3 are trivial (<6 tokens).

## Exact copies (start here — the twin's C is nearly the whole answer)

0 real exact copies (0 bytes). 'moved' pool constants = the copy points at its own module's data/globals — port the twin's C and rename the globals; 'same' = a literal duplicate, port verbatim (check the call targets).

| remaining | decompiled twin(s) | bytes | pool constants |
|---|---|---|---|

## Near matches (≥0.80 similarity, not exact)

17 functions at ≥0.80 similarity, 1088 bytes — differing tokens is the number of instruction/operand tokens that must change in the twin's C.

| remaining | best twin | similarity | differing tokens | bytes |
|---|---|---|---|---|
| `sub_08000214` | `sub_08000260` | 0.92 | 2 | 10 |
| `sub_083398D4` | `sub_08000260` | 0.92 | 2 | 10 |
| `sub_0833DBE0` | `sub_0833DBC8` | 0.93 | 4 | 18 |
| `sub_08009C00` | `sub_08009BB4` | 0.97 | 6 | 72 |
| `sub_08341690` | `sub_08009BB4` | 0.97 | 6 | 72 |
| `sub_08000478` | `sub_08005560` | 0.85 | 6 | 16 |
| `sub_08339B38` | `sub_08005560` | 0.85 | 6 | 16 |
| `sub_08000444` | `sub_08005560` | 0.80 | 8 | 16 |
| `sub_08339B04` | `sub_08005560` | 0.80 | 8 | 16 |
| `sub_080101BC` | `sub_080100CC` | 0.93 | 19 | 88 |
| `sub_0801021C` | `sub_080100CC` | 0.92 | 21 | 88 |
| `sub_08013114` | `sub_0800F22C` | 0.93 | 23 | 110 |
| `sub_08012F1C` | `sub_080144F4` | 0.88 | 38 | 122 |
| `sub_080149A4` | `sub_0800F22C` | 0.88 | 41 | 122 |
| `sub_08013A7C` | `sub_08013878` | 0.86 | 42 | 104 |
| `sub_0801303C` | `sub_08013878` | 0.85 | 44 | 104 |
| `sub_08014400` | `sub_08013878` | 0.85 | 44 | 104 |

## Families among the remaining (identical to each other)

72 families: decompile the first column once and its relatives are 4632 bytes of porting, not reverse engineering.

| decompile first | then get for near-free | bytes |
|---|---|---|
| `sub_08006094` | `sub_0833EB90` | 286 |
| `sub_0800306C` | `sub_0833C5B0` | 258 |
| `sub_0800B8EC` | `sub_08342FF0` | 256 |
| `sub_08005FA8` | `sub_0833EAA4` | 186 |
| `sub_0800B46C` | `sub_08342C3C` | 178 |
| `sub_0800E640` | `sub_08364730` | 168 |
| `sub_08001B28` | `sub_0833B1E8` | 160 |
| `sub_0800C98C` | `sub_0800CA20`, `sub_083432F4`, `sub_08343388` | 136 |
| `sub_08002258` | `sub_0833B918` | 112 |
| `sub_080022CC` | `sub_0833B98C` | 112 |
| `sub_0800592C` | `sub_0833E428` | 110 |
| `sub_0800AE94` | `sub_083427DC` | 110 |
| `sub_08003E84` | `sub_0833D188` | 106 |
| `sub_080020F4` | `sub_0833B7B4` | 104 |
| `sub_080021D0` | `sub_0833B890` | 104 |
| `sub_080059A8` | `sub_0833E4A4` | 104 |
| `sub_08004568` | `sub_0833D764` | 98 |
| `sub_08004504` | `sub_0833D700` | 94 |
| `sub_08005808` | `sub_0833E304` | 90 |
| `sub_0800F85C` | `sub_083448F4` | 90 |
| `sub_0800A478` | `sub_08341F08` | 84 |
| `sub_08001280` | `sub_0833A940` | 72 |
| `sub_08009C00` | `sub_08341690` | 72 |
| `sub_080013B0` | `sub_0833AA70` | 70 |
| `sub_08001BD0` | `sub_0833B290` | 68 |
| `sub_0800A5E4` | `sub_08342030` | 68 |
| `sub_08001234` | `sub_0833A8F4` | 66 |
| `sub_08004E58` | `sub_0833DAD8` | 66 |
| `sub_080024CC` | `sub_0833BB8C` | 62 |
| `sub_08002340` | `sub_0833BA00` | 54 |
| `sub_08000224` | `sub_083398E4` | 52 |
| `sub_08003DF4` | `sub_0833D0F8` | 52 |
| `sub_08003E28` | `sub_0833D12C` | 52 |
| `sub_080089EC` | `sub_08340B5C` | 48 |
| `sub_08010134` | `sub_08010164` | 44 |
| `sub_0800A008` | `sub_08341A98` | 42 |
| `sub_080032AC` | `sub_0833C7F0` | 40 |
| `sub_08003E5C` | `sub_0833D160` | 40 |
| `sub_0800133C` | `sub_08001374`, `sub_0833A9FC`, `sub_0833AA34` | 38 |
| `sub_080020CC` | `sub_0833B78C` | 36 |
| `sub_08008B40` | `sub_08340CB0` | 36 |
| `sub_08008B6C` | `sub_08340CDC` | 36 |
| `sub_0800BA0C` | `sub_08343110` | 36 |
| `sub_08003D6C` | `sub_0833D070` | 32 |
| `sub_08002238` | `sub_0833B8F8` | 30 |
| `sub_08003EF0` | `sub_0833D1F4` | 28 |
| `sub_080057E8` | `sub_0833E2E4` | 28 |
| `sub_0800B5D4` | `sub_08342DA4` | 28 |
| `sub_08007950` | `sub_0833FFA8` | 26 |
| `sub_08000328` | `sub_083399E8` | 24 |
| `sub_08001134` | `sub_0833A7F4` | 24 |
| `sub_08002618` | `sub_0833BCD8` | 24 |
| `sub_080031B0` | `sub_0833C6F4` | 22 |
| `sub_08000340` | `sub_08339A00` | 20 |
| `sub_08002514` | `sub_0833BBD4` | 18 |
| `sub_08002528` | `sub_0833BBE8` | 18 |
| `sub_0800253C` | `sub_0833BBFC` | 18 |
| `sub_08002550` | `sub_0833BC10` | 18 |
| `sub_08002564` | `sub_0833BC24` | 18 |
| `sub_08002590` | `sub_0833BC50` | 18 |
| `sub_080025A4` | `sub_0833BC64` | 18 |
| `sub_08000444` | `sub_08339B04` | 16 |
| `sub_08000478` | `sub_08339B38` | 16 |
| `sub_08009BA4` | `sub_08341634` | 16 |
| `sub_0800792C` | `sub_0833FF84` | 14 |
| `sub_08002578` | `sub_0833BC38` | 12 |
| `sub_08002584` | `sub_0833BC44` | 12 |
| `sub_08000214` | `sub_083398D4` | 10 |
| `sub_0800DFC0` | `sub_08364190` | 10 |
| `sub_0800020C` | `sub_083398CC` | 6 |
| `sub_080032DC` | `sub_080045D0`, `sub_0833C820`, `sub_0833D7CC` | 6 |
| `sub_083434AC` | `sub_083434B4` | 6 |
