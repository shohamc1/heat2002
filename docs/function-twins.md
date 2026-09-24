<!-- parsed 1158 functions; 1001 decompiled, 0 remaining targets, 158 non-targets -->
<!-- luvdis blocks not tracked by the project (skipped): sub_08000B1C, sub_0833A1DC, sub_083647F8, sub_08364800, sub_08364804, sub_08364808 -->
<!-- NOTE: sub_080000C0 not in rom_reference.s -->
<!-- NOTE: sub_08000104 not in rom_reference.s -->
<!-- NOTE: sub_08339780 not in rom_reference.s -->
<!-- NOTE: sub_083397C4 not in rom_reference.s -->
<!-- NOTE: sub_08363FC8 not in rom_reference.s -->
<!-- NOTE: sub_08363FF4 not in rom_reference.s -->
<!-- NOTE: sub_083640B0 not in rom_reference.s -->
# Function twins — remaining functions vs. already-decompiled ones

Method: every function's instruction stream from `build/rom_reference.s` (the ROM itself, so decompiled and remaining functions share one format), normalized so a relocated copy matches its original: branch targets become offsets from function start, pool loads and `bl` targets are masked (pool values recorded separately), registers and small immediates kept. Validated on the known pair `sub_08343EA8`/`CollideCars`, which normalizes identical.

Caveats: 'exact' means identical modulo call targets and pool constants — port the twin's C, then rename the called functions and globals it references (the high 0x0834 module keeps its own copies of both). 'moved' pool constants are the copy's own data addresses; 'same' plus exact tokens is a literal duplicate.

Regenerate after any batch of matches: `make disasm && python3 scripts/find_twins.py > docs/function-twins.md`.

## Summary — 0 exact copies, 0 near matches

Of 0 remaining game-code functions, 0 are instruction-identical (modulo relocated pool/call targets) to an already-decompiled function, and 0 are ≥80% similar. 0 are trivial (<6 tokens).

## Exact copies (start here — the twin's C is nearly the whole answer)

0 real exact copies (0 bytes). 'moved' pool constants = the copy points at its own module's data/globals — port the twin's C and rename the globals; 'same' = a literal duplicate, port verbatim (check the call targets).

| remaining | decompiled twin(s) | bytes | pool constants |
|---|---|---|---|

## Near matches (≥0.80 similarity, not exact)

0 functions at ≥0.80 similarity, 0 bytes — differing tokens is the number of instruction/operand tokens that must change in the twin's C.

| remaining | best twin | similarity | differing tokens | bytes |
|---|---|---|---|---|

## Families among the remaining (identical to each other)

None.
