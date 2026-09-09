# Decompilation tickets

One file per function, worked lowest number first. A ticket is done when
`make check` still prints `MATCH` with the function implemented in C.

**Read [`../learnings/parked.md`](../learnings/parked.md) before picking a
target.** Several small-looking leaves are already known not to match, and
five entries in the 743 count are not functions at all.

204 / 743 functions are matched. The three tickets below are the only ones
ever written; everything after DECOMP-003 has been worked in parallel
batches (see `docs/learnings/parked.md` for what resists and why). New
single-function work should pick from the remaining asm fragments, lowest
address or highest caller count first.

| Ticket | Target | Insns | Callers | Status |
|---|---|---:|---:|---|
| [DECOMP-001](DECOMP-001-sub_08006734.md) | `sub_08006734` | 1 | 38 | done |
| [DECOMP-002](DECOMP-002-sub_08016558.md) | `sub_08016558` | 6 | 51 | done |
| [DECOMP-003](DECOMP-003-sub_0800048C.md) | `sub_0800048C` | 17 | 40 | done |

Candidate queue (from `docs/recon.md`, not yet ticketed):

| Target | Insns | Leaf | Callers | Note |
| --- | ---: | :---: | ---: | --- |
| ~~`sub_0800793C`~~ | 9 | yes | 11 | done |
| ~~`sub_0833FF94`~~ | 9 | yes | 11 | done |
| ~~`sub_0800F3A4`~~ | 12 | yes | 11 | done |
| ~~`sub_080045D8`~~ | 9 | yes | 8 | done |
| ~~`sub_08016E10`~~ | 2 | yes | 24 | done — `swi 0x0B` via inline asm |
| ~~`sub_08016E28`~~ | 2 | yes | 7 | done — `swi 21` |
| ~~`sub_080172C4`~~ | 1 | yes | 3 | done — `__div0`, `__attribute__((naked))` |

Write new tickets with the same shape: why this function (with numbers),
the target asm, concrete steps, a done-when checklist, and honest risks.
