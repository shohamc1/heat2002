# Decompilation tickets

One file per function, worked lowest number first. A ticket is done when
`make check` still prints `MATCH` with the function implemented in C.

| Ticket | Target | Insns | Callers | Status |
|---|---|---:|---:|---|
| [DECOMP-001](DECOMP-001-sub_08006734.md) | `sub_08006734` | 1 | 38 | done |
| [DECOMP-002](DECOMP-002-sub_08016558.md) | `sub_08016558` | 6 | 51 | done |
| [DECOMP-003](DECOMP-003-sub_0800048C.md) | `sub_0800048C` | 17 | 40 | done |

Candidate queue (from `docs/recon.md`, not yet ticketed):

| Target | Insns | Leaf | Callers | Note |
| --- | ---: | :---: | ---: | --- |
| `sub_0800793C` | 9 | yes | 11 | leaf, no calls |
| `sub_0833FF94` | 9 | yes | 11 | leaf, no calls |
| `sub_0800F3A4` | 12 | yes | 11 | leaf, no calls |
| `sub_080045D8` | 9 | yes | 8 | leaf, no calls |
| `sub_08016E10` | 2 | yes | 24 | `swi #11` BIOS wrapper — needs inline asm |
| `sub_08016E28` | 2 | yes | 7 | `swi #21` BIOS wrapper |
| `sub_080172C4` | 1 | yes | 3 | `__div0` divide-by-zero hook |

Write new tickets with the same shape: why this function (with numbers),
the target asm, concrete steps, a done-when checklist, and honest risks.
