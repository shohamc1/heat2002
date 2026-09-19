# `sub_0800D684` fourth-pass closeout

Date: 2026-09-17. This is a docs-only closeout; the alternative remains unintegrated and nonmatching.

## Fixed facts

- Target address: `0x0800D684`; function target size: **2006 bytes**.
- A generated full `.text` may be **2008 bytes** because of two alignment zeros; that is not the function target size. Disassembly row counts include literal-pool data and are not instruction counts.
- `baserom.gba` SHA256: `814356b2bc6b542d9134c01291739a584ea11f92948bc62469611856375ed628`.
- `tools/agbcc/old_agbcc` SHA256: `41fbd1a673a41c396c4759eff330d9ffb7fc833d261152f9409f839d11a8a4aa`.
- Current baseline source SHA256: `8cafede905ca5066173c8dbb604537336675c3e7d777bfbbddedb8647384f91c`.
- Retained alternative source: `candidates/final-alternative.c` in the carriers scratch lane; SHA256 `ba4fb0dbe2e2a2afe7046a9da30cd9aa97f6223ee1c1344ec763133806e68fad`. Its concise fourth-pass banner marks the inherited long historical header and nonmatching status.

Fresh builds of both baseline and alternative produced `2006/2006` candidate/target bytes. Neither matched:

| source | result | prefix byte differences | normalized operations/lines |
|---|---|---:|---:|
| baseline | `MISMATCH (2006 bytes @ 0x0800d684)` | 662 | 8/8 |
| alternative | `MISMATCH (2006 bytes @ 0x0800d684)` | 900 | 8/8 |

The alternative differs from baseline only in two source regions: (1) second-half edge-index-2 call scheduling, changing `fraction = e << 16; call(..., fraction / w)` to `fraction = e; call(..., (fraction << 16) / w)`; and (2) the proven post-loop cc integer carrier `e = (s32)cc`, using that carrier for cc fields/indexing. The cc carrier removes the redundant post-loop cc pool reload locally, but causes broad register recoloring and is not a match.

## Fourth-pass asymmetric table ledger

The missed hypothesis was tested from the exact-size `post_e_unshifted` alternative base. Each variant assigned a table pointer or existing scalar immediately after the trig loads and before the cc index read, but routed only one table field through that alias; the other field retained the original direct spelling. Six fresh variants were tested:

| candidate | source hunk | size | prefix diffs | normalized ops/lines |
|---|---|---:|---:|---:|
| `candidates/asym-table/ptr_f0_only.c` | `table = gUnk_083FDA2C`; `k1 = table[ccd].f0`; original direct `k0` | 2006 | 908 | 6/6 |
| `candidates/asym-table/ptr_f1_only.c` | same pointer assignment; original `k1`; `k0 = table[ccd].f1` | 2002 | 1350 | 7/9 |
| `candidates/asym-table/k2_f0_only.c` | `k2 = (s32)gUnk_083FDA2C`; cast only for `k1`; original direct `k0` | 2006 | 846 | 9/9 |
| `candidates/asym-table/k2_f1_only.c` | same scalar assignment; original `k1`; cast only for `k0` | 2002 | 1350 | 7/9 |
| `candidates/asym-table/k3_f0_only.c` | `k3 = (s32)gUnk_083FDA2C`; cast only for `k1`; original direct `k0` | 2034 | 1838 | 69/285 |
| `candidates/asym-table/k3_f1_only.c` | same scalar assignment; original `k1`; cast only for `k0` | 2002 | 1344 | 7/9 |

`ptr_f0_only` and `k2_f0_only` were the best new source-only leads by normalized/raw metrics, but neither matched. `ptr_f0_only` **does reproduce the target table operation order**, with different registers; it does not reproduce the surrounding register allocation. The target sequence is `ldr table; ldrb cc->d; scale; add index; ldr f0; add table,#4; add index; ldr f1`.

The `ptr_f0_only` result is retained separately as the stronger structural lead. Its bannered source is `/tmp/d684-exp-20260917-160143/lanes/carriers/candidates/final-6diff.c`, SHA256 `12f7f36ef27deeeb87b460490b772c0566565df5698f0b28c0a10cdf599eae04`; durable source-delta patch: [`sub_0800D684-FOURTH-PASS-6DIFF.patch`](sub_0800D684-FOURTH-PASS-6DIFF.patch). Relative to the original baseline, its full source delta is: add the short fourth-pass banner; add `struct Pt2 *table`; retain the `fraction = e` edge-index-2 spelling and post-loop `e = (s32)cc` carrier from `post_e_unshifted`; assign `table = gUnk_083FDA2C` after the trig loads and before the cc index; read only `k1`/`f0` through `table[ccd]`; and retain the original direct `k0`/`f1` read. It is 2006 bytes, 908 raw prefix differences, and 6 normalized operations/lines, so it remains unintegrated/nonmatching.

Its six normalized hunks are five code differences (register-copy differences are semantically redundant) plus one pool-data artifact: (1) pre-loop `pa` call copy; (2) an extra register copy at the **first-half edge index 2** region near target `0x0800D8A6`; (3) an extra divide-argument copy at edge-index 2; (4) missing `unk55` address copy; (5) valid reload-CSE elision of one zero before `sub_0800BA34`; and (6) a pool-data row near the literal pool, not an instruction. The candidate reproduces the target table operation order with different registers. The earlier symmetric pointer/element/scalar table forms remain rejected: they either fold both reads into a direct `[base,#4]` load and shorten to 2002 bytes or worsen the global allocation. The paired divisor/w-carrier forms for corrected **second-half edge index 2** were also rejected: `w_k1`, `w_k3`, and `w_edgeq` were neutral at 2006/900/8, while `w_k2` worsened to 1029/12.

## Reload and comparator corrections

The prior scratch runners scored unconditionally after invoking `match.py`. They now run `make -B build/src/sub_0800D684.o`, check return code zero, and only then run matcher/scorer. Prior logs contain only successful `MISMATCH` rows and no compile-error markers; no score was withdrawn. Final compile logs explicitly report `compile_rc=0` for both baseline and alternative.

The missing third zero at the `sub_0800BA34` setup is valid reload-CSE elimination in the existing compiler pipeline. It is not an unsafe carrier read, spill, or stale-object artifact; no compiler behavior patch was used.

Use `scripts/match.py` for exact bytes and `experiments/score_all.py` only with fixed target length 2006. Normalized/fixed-window metrics are diagnostic only and cannot establish a match when layout shifts.

## Whole-ROM and integration status

In the carriers scratch lane, the target source was backed up to a unique `/tmp` path, removed together with its object, and `make check` was run. It returned `MATCH`; the source was restored and the target object removed afterward. No integration or extraction was attempted. The main source remains the original untracked baseline. No ROM, SHA1 authority, linker, compiler, or assembly file was changed.

Relevant artifacts and commands:

- Prior evidence: `/Users/shohamc1/.pi/agent/sessions/--Users/shohamc1-heat2002-gba--/subagent-artifacts/outputs/113c379b-f30e-41f3-96e0-2cf0880c4cb2/d684-openai/evidence.md`
- Reload diagnostics: `/Users/shohamc1/.pi/agent/sessions/--Users/shohamc1-heat2002-gba--/subagent-artifacts/outputs/113c379b-f30e-41f3-96e0-2cf0880c4cb2/d684-openai/reload.md`
- Carrier combinations: `/Users/shohamc1/.pi/agent/sessions/--Users/shohamc1-heat2002-gba--/subagent-artifacts/outputs/113c379b-f30e-41f3-96e0-2cf0880c4cb2/d684-openai/combinations.md`
- Fourth-pass scratch report: `/Users/shohamc1/.pi/agent/sessions/--Users-shohamc1-heat2002-gba--/subagent-artifacts/outputs/01517863-afbc-4428-9c24-2033792af231/d684-closeout/repair.md`
- Scratch root: `/tmp/d684-exp-20260917-160143/lanes/carriers`
- Durable source-delta patches: [`sub_0800D684-FOURTH-PASS.patch`](sub_0800D684-FOURTH-PASS.patch) and [`sub_0800D684-FOURTH-PASS-6DIFF.patch`](sub_0800D684-FOURTH-PASS-6DIFF.patch)
- Exact commands: `make -B build/src/sub_0800D684.o`; `python3 scripts/match.py sub_0800D684`; `python3 experiments/score_all.py`; `make check` with `src/sub_0800D684.c` excluded.

The observed remaining differences are interactions between `pa`/`cc` lifetimes and short-lived edge temporaries, together with call-setup sequencing; this is evidence, not proof of one root cause. Continuation should focus only on a genuinely new source-level mechanism for those interactions and remaining call setup. Do not repeat the symmetric/asymmetric table or divisor forms above, and do not introduce a compiler behavior patch without explicit approval.
