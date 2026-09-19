# `sub_0800D684` continuation — all campaigns after the third pass

Date: 2026-09-18. Docs/evidence only. No source, compiler, ROM, linker, asm,
Makefile or SHA authority file in the main repository was changed by the work
recorded here, and none was changed writing this file.

Read alongside:

- [`sub_0800D684-HANDOFF.md`](sub_0800D684-HANDOFF.md) — current state + protected hashes.
- [`sub_0800D684-FOURTH-PASS.md`](sub_0800D684-FOURTH-PASS.md) + [`sub_0800D684-FOURTH-PASS-6DIFF.patch`](sub_0800D684-FOURTH-PASS-6DIFF.patch) — fourth pass.
- [`sub_0800D684-BEST291.patch`](sub_0800D684-BEST291.patch), [`sub_0800D684-STRUCTURAL2707.patch`](sub_0800D684-STRUCTURAL2707.patch), [`sub_0800D684-GENERIC-RELOAD-LOOKAHEAD.patch`](sub_0800D684-GENERIC-RELOAD-LOOKAHEAD.patch).

Source lineage (each step verified by hash, see §evidence index):

```
8cafede9  src/sub_0800D684.c                       (third-pass draft, unchanged in main)
  -> 12f7f36e  fourth-pass 6diff (table f0-only alias + post_e_unshifted + cc carrier)
  -> fab3dabb  + branch-local empty r1 clobber before sub_0800BA34, + first-half edge-2 carrier drop
  -> ef631193  fourbase with pre-loop `d0 = (s32)pa` instead of `k2 = (s32)pa`
  -> 5623424d  postloop-direct-w: `d0 = (s32)cc->c; w = d0;`  ->  `w = (s32)cc->c;`   [BEST 291]
  -> 157d1155  pre-loop carrier replaced by a block-scope pcall (rotates the web to target)
  -> efad23f8  + `register s32 *pcall __asm__("r7")` pin and `flagp = &flag` (frame 68, target web)
  -> 22207d11  cell 1: first-half edge-index-3 guard reads `(k2 + 0x1C00)` directly
  -> 700ae325  cell 2 cumulative: drop the two second-half `d1 = (e = ...)` wrappers
  -> ac18d079  + input-only `__asm__ volatile ("" : : "r" (w));` before the addr pin
  -> 27079a24  + unk55 `register u8 *addr55 asm("r0")` shape                  [STRUCTURAL, 2010 B]
```

Independent companion: `27079a24` is reached end-to-end from `5623424d` by
[`sub_0800D684-STRUCTURAL2707.patch`](sub_0800D684-STRUCTURAL2707.patch).

---

## Group 1 — fourth pass (link, do not duplicate)

Fourth pass is already documented. Pointers only:

- [`sub_0800D684-FOURTH-PASS.md`](sub_0800D684-FOURTH-PASS.md) — asymmetric table ledger.
- [`sub_0800D684-FOURTH-PASS.patch`](sub_0800D684-FOURTH-PASS.patch) and
  [`sub_0800D684-FOURTH-PASS-6DIFF.patch`](sub_0800D684-FOURTH-PASS-6DIFF.patch).

Best retained alternative `12f7f36ef27deeeb87b460490b772c0566565df5698f0b28c0a10cdf599eae04`
(`candidates/final-6diff.c` in the carriers lane; `final-6diff.c` also copied into
the address lane): 2006 bytes, **908 raw** byte differences, **6 normalized
operations of which 5 are code and 1 is a pool-data row**.

The six normalized hunks: pre-loop `pa` call copy; extra register copy at first-half
edge index 2; extra divide-argument copy at edge index 2; missing `unk55` address
copy; a valid reload-CSE elision of one zero before `sub_0800BA34`; and one
pool-data row (row 743 / `0x0800DC8E`, alignment padding, not a pool entry).
The candidate reproduces the target's table operation order with different
registers. Symmetric `ptr`/element/`k2`/`k3` table forms and the paired
divisor/`w`-carrier forms for corrected second-half edge index 2 were rejected
(2002/1344-1350, or 2006/900-1029).

**Superseded claims.** The third-pass handoff's "exhaustive sweep", "no live lead
remains", "root cause identified", and "959/959 instructions (exact)" statements
are historical. The 959 figure is a raw disassembly-row count including literal
pools and zero-fill pads, not an instruction count. The register-priority
mechanism named in the third pass was later measured properly (§8, §9) and is a
live line of work, not a dead end.

## Group 2 — fifth-pass source trials under the stock compiler

All on the `12f7f36e` (6-diff) base unless stated. Counts are distinct
candidates actually compiled; repeated or no-op recompiles are not counted.

| family | cells | outcome |
|---|---:|---|
| pre-carrier x first-edge-chain combinations (`/tmp/d684-sixth-uY9kyw/pa/candidates/fifth-pass/`) | 16 | Only the branch-local empty `r1` clobber before `sub_0800BA34` restores the target's three zero immediates (source `f78cfc6b82f7d9939434f6590624bea878d634fad86b53feb88c69fe6871238d`), but it emits 2010 bytes and introduces an extra `mov r8, r9` (`hit2 = w` split copy) at `0x0800DCD6`. Combining it with the first-edge-chain **drop** clears the extra copy: `fab3dabb166adf547a0e7490025752f1cc88ac563c854d038810baf61c3b9ba1`, 2006 bytes, raw 851, **4 actual code groups**. |
| divisor forms (`…/pa/candidates/fifth-pass-divisor/`) | 5 | narrow `r1` divisor / `w`-carrier forms; no structural gain (2006/900-1077, or worse). |
| explicit signed-div helper `sub_08017230(s32,s32)` and `__attribute__((const))` metadata rival | 3 + 3 | first-half 2006/840, second-half 2006/861, both 2006/850 — but the explicit call is evaluated *before* the stack stores while the target stores then shifts, so the lower raw count is not a structural improvement. `const` annotation reproduced the unannotated results exactly: no ordering or metadata gain. |
| unk55 forms (`…/pa/candidates/fifth-pass-unk55/`) | 8 | `d0`/`e`/`u`/`w` before/after, assign-in-load, load-`d0`-then-`d1`-expr: all neutral or worse. |
| fresh-numerator forms (`…/pa/candidates/fifth-pass-numerator/`) | 3 | neutral. |
| alias remove / early hit2 / move hit2 (on the clobber state) | 3 | 1998/1529, 1978/1852, 2006/932 — rejected. |
| carrier follow-ups on the 4-group source | 3 | narrow r1 divisor 2006/1077; `unk55` address through `d0` 1994; chain-drop + pre-call `d0` carrier 2010 — rejected. |
| coupled address/byte pins (`addr55 asm("r0")`, `value55 asm("r1")`, together and separately, with/without clobber) | 4 | 2014 bytes, ~1401-1402 raw, 6 ops. The address pin does produce the target address/copy sequence, but the byte lands in `r3` and the rest recolors; a byte pin gives `ldrb r1` then copies into the ordinary local. |
| flag-pointer block-local `u8 *flagp = &flag` (1st, 2nd, both calls) | 3 | all optimize to the unchanged 2006/851/4. Integer carriers were worse (2034/1835/40, 2010/1229/6). |

Retained by the fifth pass: `fab3dabb…` (stock 2006/raw851) and, under the frozen
generic compiler, 2006/raw915 with **2 actual code groups + 2 pool-boundary
padding rows** (not 4 code groups). Baseline invariants preserved in every cell:
the intentionally uninitialized `a2` stack read and the
`gUnk_083FDA2C[...].f1 = gUnk_083FDA2C[...].f1` self-store. Empty-asm steering was
used only as an input/clobber identity constraint, never as an invented output.

## Group 3 — compiler rivals (all rejected or unadopted)

| rival | D684 result | corpus | disposition |
|---|---|---|---|
| `REG_EQUIV` live-length penalty `*2 -> *1` (`local-alloc.c`) | 6-diff target unchanged (2006/908/6), original 8caf unchanged | **384/462 match, 78 broken** | rejected; broad damage, zero benefit. Broken list in `…/d684-fifth/regression.md` and `logs/alt-broken-functions.tsv` |
| reset `last_spill_reg` per basic block | 2010 bytes, raw 1453, 13 normalized ops | not expanded | rejected |
| revert production `calls.c` precompute patch (isolated old-gate CC1 `1a065598…`) | no effect: 8caf 2006/662/8; 6-diff 2006/908/6, identical linked hash | 461/462 — only `sub_08003738` breaks | supports keeping the narrow address-constant patch; do not re-run this cell |
| broad lookahead4 (`675ec764…`) | 2006, raw 918, fixes **both** edge-2 divisor copies; 2 code + 2 padding rows | 462/462 | superseded |
| refined same-block lookahead, frozen "safe" (`73d390ff…`) | 6-diff 2006/908; 4-base (clobber) 2006/**raw 915**, 4 normalized rows = 2 code + 2 padding | 462/462 | frozen and published, **not adopted**; no corpus blast-radius signal distinguishes it from broad lookahead4 |

The lookahead fixes the divisor-stack setup on both edges. It does **not** fix the
generated flag-pointer address reload (target `r0`, candidate `r6`): that reload has
no same-source future hard-argument copy, so it is ineligible without inventing a
hard-`r0` preference, which was deliberately not tested.

## Group 4 — provenance and measurement corrections

- `make -B CC1=/ABSOLUTE/compiler build/src/sub_0800D684.o` is required. The
  Makefile uses `CC1 := …`, so an exported environment `CC1` is ignored.
- `scripts/match.py` `main()` rebuilds with the Makefile compiler. Use
  `match.compare()` on an already-compiled object, or a direct standalone link at
  `0x0800D684`, when scoring a private compiler. Several earlier probe scripts
  compiled with a private compiler and then invoked `match.py` main — those
  conclusions are invalid about the private compiler.
- Compare the fixed **2006-byte** target slice, and report the **symbol size**
  (`nm`) separately from the object `.text` size (up to 2008 with end alignment).
- Masked/normalized/hex-normalized comparisons are diagnostics. A masked zero is
  not a match; register recolouring can swing them arbitrarily.
- The 959-row figure is not an instruction count.
- Main `src/sub_0800D684.c` and its drafts copy stayed `8cafede9…`; no commits and
  no staging were made.

## Group 5 — rejected synthesis worker (authority violation, never reuse)

Worker `4fe2a47a-…` produced a private compiler at
`/tmp/d684-exp-20260917-160143/lanes/carriers/private-tools/worker-lookahead-chain`
containing explicit **function-name and UID specific hard-register rewriting**
(`current_function_name` compared against `sub_0800D684`, then RTL replacement).
That is out of authority, not a compiler finding. **All of its outputs are
rejected**, including the reported 196-byte difference score.

Its `worker_*.py` scripts also commonly compiled with that private compiler and
then invoked `scripts/match.py` main (stock rebuild), so their provenance is
invalid; some probes additionally overwrote live `d0`/`u` with an address. Do not
copy them without dataflow review.

Containment snapshot: `/tmp/d684-parent-containment-jlwamA` (main hashes/status/diff
and `rejected-targeted-reload.patch`). Main and the frozen `73d390ff…` artifact
were rechecked uncontaminated.

## Group 6 — donor/exclusion corrections

- Earlier compiler matrix cell mislabeled `clobber_pre_d0.c`
  `130677caff5047d9cd014045e50309b9672b8370f5db7ad91ef2e625fe3abad0` as
  "four-base + pre_d0". That donor still contained the first-edge `k1 = e; d1 = k1`
  chain, so its 2014 result does **not** refute the corrected donor.
- Corrected donor `fifth-chain-followups/chain_pre_d0.c`
  `ef631193c8a9fca176ad64dbf3218260bf0380221f4f7c5a67412963decee501` removes that
  chain: generic compiler 2006 bytes, raw **337** (object `4cd89fdc…`, linked
  `08279b5b…`).
- The step to best 291 is one source line: `d0 = (s32)((struct Unk0802CC90 *)e)->c; w = d0;`
  becomes `w = (s32)((struct Unk0802CC90 *)e)->c;`.
- `postloop-direct-both.c` `1bf239c14fbcdc889f89590148afc267f2dfc9b92038c9b19f81b94faec1dd86`
  additionally removes the `u0` alias but produces a byte-identical object, so the
  minimal source was kept and the current best **retains** `u0`.

## Group 7 — address-lane pin cells on the 291 base

Base `5623424d…` (2006/raw291). The only edit in each cell is the unk55
address/byte pair.

| cell | source SHA256 | object | bytes | raw | normalized |
|---|---|---|---:|---:|---|
| `pins_addr_noclobber` `66ee1d29…` | `66ee1d29d696d28bf1c5c13f5d6e44ab17e69e0e3139de2de90ced5e2b288cb0` | `8e26914a…` | 2010 | 566 | 8/364 |
| `pins_both_noclobber` `4f806ed2…` | `4f806ed2e65974ba8a6a2dc0739810ff70d32d121cb5497ea2f0c47677371ab2` | `8e26914a…` (same object) | 2010 | 566 | 8/364 |
| `pins_addr_clobber` `b453a9ba…` | `b453a9baf704443b0ff3337d8937fdd822e68ba1c2cbe401abc11872ed221dfe` | `2a9773a6…` (= earlier byte-before-d1 family) | 2010 | 570 | 8/364 |
| `pins_both_clobber` `f01be1d9…` | `f01be1d92344534c7bc83ea731a165984b02bf7f8c4ca7a79aef29e6bbc4b242` | `45190927…` | 2014 | 742 | 21/546 |

Mechanism facts:

- The `asm("r1")` byte pin is **redundant** once the address is pinned without the
  r1 clobber.
- The `66ee` cell reproduces the target **shape** exactly (address transient in
  `r0`, byte in `r1`, address copied to the keeper) but the keeper is `r5`
  (target `r6`) and the base `u` is `r6` (target `r7`) — a global +1 rotation.
- Cost: +2 bytes of the target-faithful copy and +2 bytes of one extra
  `mov r8, r9` (`hit2 = w` split copy). Zero-fill pads relocate but are not code.
- **Correction to the earlier belief:** the previously reported pin cells were not
  live across calls just because the pinned local was declared at function scope;
  what distinguishes them is the base and pin set, not declaration scope.
- Extra `hit2 = w` copy traced to **global** allocation: `w` (pseudo 44) home
  `r8 -> r9` while `hit2` (417) keeps `r8`, i.e. a home mismatch, not local-alloc.
- Alias removal on `5623`/`66ee` regresses hard: raw 1822 / 1827, symbol `0x7da`
  (2010), whole post-loop recoloured. Rejected.
- The "move `hit2 = (struct Ent *)w;` earlier" proposal was **NOT RUN**. No
  combined alias cell exists.

## Group 8 — global register priority, and the web rotation

`global.c`: `pri = floor_log2(n_refs) * n_refs / live_length * 10000 * size`
(`size` is one here). Allocatable non-call-used pool on Thumb is `r4..r10`
(seven registers), scanned in register-number order.

Actual `-dg` map for the best 291 source (verified against the report):

| C object | refs | live_length | pri | 5623 home | target home |
|---|---:|---:|---:|---|---|
| `e` | 53 | 172 | 15406 | r4 | r4 |
| `d1` | 67 | 357 | 11260 | r5 | r6 |
| `u` | 63 | 506 | 6225 | r6 | r7 |
| `d0` | 59 | 494 | 5971 | r7 | r5 |
| `w` | 50 | 427 | 5855 | r8 | r8 |
| `v1hold` | 8 | 41 | 5853 | r9 | r9 |
| `cursor` | 37 | 448 | 4129 | r10 | r10 |

Required permutation is a priority flip of `d0` against `{d1, u}`. `d0` is a
single pseudo whose whole-function priority is dragged down by the pre-loop
carrier defect `d0 = (s32)pa`.

**Preserved artifact:** replacing only the pre-loop carrier with a block-scope
`pcall` short local
(`pa/candidates/registers-web-precall-drop.c`, `157d11558e1afe4a02d3630608b657404dc0aaac993603781c0322be8de5e5f0`)
cuts pseudo 35's lifetime 494 -> 244 (refs 59 -> 57), priority 5971 -> 11680, and
yields exactly the target homes `d0=5, d1=6, u=7, w=8, v1hold=9, e=4, cursor=10`.
Result: **2006 bytes, raw 914**, 4 real code-shape slots (pre-loop pair, unk55
pair) plus layout/pairing slots. Object `029d954f…`, linked `bc98c1f9…`.

Carriers tried and measured as negative: fresh block-scope and function-scope
pointer (copy-propagated to the constant), `u = (s32)pa` (u -> r10), `w = (s32)pa`
(w -> r10), `e = (s32)pa`, `k2 = (s32)pa`, pre-`u`/`w`/`e`/`k2`/fresh-pointer
forms, and reference-count boosting. **No impossibility claim** — a pre-loop-only
value cannot reach `r7` for the forms tested because `find_reg` only avoids
registers of conflicting allocnos, which is a boundary of the tested forms.

## Group 9 — r7 pre-loop pin: traced root, and the approved flagp fix

The narrow `register s32 *pcall __asm__("r7")` + empty-asm keep-alive pin produces
the target initial `pa` pair and the target web, but spills `cursor`: frame
68 -> 72, size 2022, 26 normalized ops.

Traced root (pass dumps):

- `thumb.h`: `FRAME_POINTER_REGNUM 7`, virtual; `-O2` omits the frame pointer;
  `global_alloc` strips conflicts between allocnos and eliminable registers, so
  `r7` is normally allocatable.
- `.rtl`, `.jump`, `.cse` are identical for the `fp+16` chain. **`gcse` diverges
  first.** Control hoists one `(plus (r7) 16)` value (pseudo 735) plus ten copies;
  the pin, by writing hard `r7` in the pre-loop, splits the value numbering of
  every fp-relative address, so gcse can no longer carry a loop-invariant `fp+16`
  value: five separate in-loop computations instead.
- At global-alloc pseudo 735 goes refs 18 -> 32, live 872 -> 293, priority
  825 -> **5460**, outranking `cursor` (31) at 4129 -> 4065; 735's preferred LO_REGS
  class is exhausted so it falls to ALL_REGS and takes `r10`; cursor is spilled.
- The measured seven-register pool is exactly saturated, so an eighth long-lived
  value has nowhere to go.

Approved probe: `u8 *flagp;` beside `u8 flag;`, `flagp = &flag;` immediately after
`flag = 0;` and **before** the r7 pin, and exactly the eight in-loop
`sub_0800D64C(..., &flag, ...)` arguments replaced by `flagp` — one declaration,
one assignment, eight argument substitutions, nothing else.

`pa/candidates/registers-web-precall-pin-flagp.c`
`efad23f8676962fa88380373aca524d2e71781739353f7f7be430b1925e28e4b`
(object `c482b8e2…`, linked `5e8a02da…`): **2006 bytes, raw 551**, frame back to 68,
cursor home r10, target web, target initial pair byte-identical, flag-pointer
pseudo spilled (home -1) and rematerialised per call at priority 796. Every local
stays `sp`-relative (r7 is only ever an entity-pointer base, never a frame base),
which is what makes the hard-r7 write safe *on this target*.

## Group 10 — combinations, and the priority tie that decides them

| combo | source SHA256 | bytes | raw | effect |
|---|---|---:|---:|---|
| `157d1155` + `66ee` unk55 (`address8-regweb157_pin66ee.c`) | `6a02c87424e73220356827dcd3bcd0871a83b402b164e191e966e19875c496da` | 2010 | 1175 | best *mechanism* result on the 157 base: correct value routing and target-exact local unk55 triple; no raw gain |
| `efad23f8` + `66ee` unk55 (`address9-efad_pin66ee.c`) | `0092d964e08b8f6f814fac47e62e12f8f42ca6e00d974dd25646b371d173396f` | 2014 | 1105 | keeps target homes and the exact local triple, but the loop's r8/r9 roles swap (`w` -> r9, `hit2` stays r8) and the split `mov r8, r9` high copy returns |

Mechanism: the unk55 address pin lengthens `w`'s live range by one instruction
(427 -> 428) with refs unchanged at 50. Priority key goes
`5*50*10000/427 = 5854` -> `5*50*10000/428 = 5841`, while `v1hold` sits at
`3*8*10000/41 = 5853.7`. **The key crosses**, the two pseudos swap allocation
order, and `w` moves `r8 -> r9` while `hit2` stays `r8`.

An earlier worker dropped the `floor_log2` factor and reported "no crossing".
That was wrong: with the plain ratio the pair does not cross, but the plain ratio
is not the sort key. Corrected arithmetic reproduces 5854/5853 exactly on both
bases.

## Group 11 — `w` input-asm: restoring the order without a lifetime move

On top of `0092d964…` (which stays immutable), an input-only
`__asm__ volatile ("" : : "r" (w));` immediately **before** the pinned address
block:

- `w` refs 50 -> **51**, live 428 -> 429, key 5841 -> **5944**; `v1hold` unchanged
  at 5853 — the order is restored, `w` = r8, `v1hold` = r9, and the extra
  `mov r8, r9` disappears (`has_mov_r8_r9=False`).
- The address-lane proposal to move `hit2 = (struct Ent *)w;` earlier was **not
  run** and is superseded by this working asm cell.

Published diagnostic: `address10-wref-asm-after-pinbase.c`
`ac18d07913722ea4ae70c3ef6359da78e57bae8323d6c26f125ce97db88d3a2d`,
object `cdf9b32cda098a815428e751a0281cdca79cb637951e635f95d8adb2b1a450de`,
linked `c210b5ffeeab729cf75b8834cd9a61d8190bd7fbb4738426969d8aec7fd45862`,
**2010 bytes, raw 1094**, frame 68, 33 pool words, 7 zero pads, no `mov r8, r9`.
Still not a match.

## Group 12 — edge-carrier removals on the `efad23f8` base

| cell | source SHA256 | result |
|---|---|---|
| cell 1: first-half edge index 3 guard reads `(k2 + 0x1C00)` directly, no `d1 =` wrapper | `22207d110fa02f796e8adea84df4d9e1d7a4cb28e35d3439876d1ed258a8d9f6` | 2006 bytes, raw 562; accumulator back in `k2`'s `r1` like the target; the *constant* scratch moves from `r0` to `r6` |
| cell 2 cumulative: drop both second-half `d1 = (e = ...)` wrappers at edge 0 and 1 | `700ae32504b4b866fe6ade6e93999782030d1dbbb20f1978c47527c928a896fb` | 2006 bytes, raw 568; `e` value back in `r4` (`adds r4,r4,r6`, `cmp r4,#0`, `muls r0,r4`, `subs r4,r1,r0`, `lsls r0,r4,#16` all match); main web retained |

`combine` is the first pass that folds the carrier chain, so the arithmetic is
emitted straight into `d1`'s register and every later `e` use reads `d1`. Deadness
was verified by hand over the overwrite matrix: the carrier value is read only by
its own guard in the same block, and every later `d1` read is preceded by an
unconditional overwrite (matrix rows for the first half, `pb`/`pa` rows for the
second half, the trig-table load and then the unk55 address for the post-loop).

Global effects: `d1` refs 67 -> 63 -> 47 with priority 11260 -> 8898 -> 7389;
`e` priority 19903. Neither cell improves the raw or slot count (562/122 and
568/128 against `efad23f8`'s 551/112). They are **family-correctness** leads: the
remaining difference at those sites is only the constant/scratch register, which
is reload state (§14).

## Group 13 — latest structural combo (preserved alongside the 291 best)

`address11-cum700_wref_pin66ee.c`
`27079a2460fe14cc7ea120917db887ee8e399d67a7366e16d78bee091955d074` =
`700ae325…` (cumulative edge-carrier removal) + `w` input asm + short `addr55
asm("r0")` / no-clobber unk55 shape.

- object `b8211ea2dbff351e030242e3fab481e419fb49d891f6c1fcd55359fb3ff5c487`,
  linked `a91f3ebeaec11a0b0eb32e2d06465e17be27d162d49caa061934b5e2233433e6`,
  **2010 bytes, raw 1111**, frame 68, symbol `0x7da`, 33 pool words, 7 zero pads.
- Correct simultaneously: initial `pa` copy, local unk55 triple, global web
  (`u`=r7, `d0`=r5, `d1`=r6), edge value families, `w`=r8 / `v1hold`=r9, and **no**
  extra `hit2` copy.
- Still +4 bytes of layout (target-faithful copy + a relocated pad) plus many
  scratch-register differences. Raw 1111 is dominated by tail displacement.
- **Not a replacement for the 291 source** — it is worse on raw. Keep both axes;
  combine regressions only after an actual code improvement lands.

## Group 14 — scratch-register family, and the unfinished hint trace

Observed family: ours materialises pool constants and comparison temporaries in
free `r6` where the target uses `r0`/`r1`; e.g. the first-half edge-index-3
constant `7168` (`movs r6,#224; lsls r6,r6,#5; adds r1,r1,r6` vs target
`movs r0,…; lsls r0,r0,#5; adds r1,r1,r0`) and the `&flag` materialisation
(`add r6, sp, #32` vs target `add r0, sp, #32`).

Mechanism facts (traced, not conjectured):

- These are **reload-generated** insns (`emit_reload_insns`), not allocated
  pseudos and not regmove output: UIDs > 2000, absent from `.lreg`/`.greg`.
- `order_regs_for_reload` builds the candidate list once per insn chain; the
  function-global `last_spill_reg` round-robin (`reload1.c`, reset once per
  function) makes the choice phase-dependent. The same expression
  `(plus sp 32)` is rematerialised at ten sites with a *varying* register
  sequence in one build.
- Basic block 41's live-pseudo sets are byte-identical between controls, so local
  availability did not change — the phase did.
- **Do not call this unreachable, and do not explain it by source quantity
  alone.** It is compiler state.

Hint trace (trace-only builds, byte-equivalence controlled):

| artifact | SHA256 |
|---|---|
| `pa/registers-lane-20260917/hint-trace/bin/old_agbcc.look_diag` | `7d7fe48f94c7cfc6c36d41d570999cc4d108fb9208e84efb610b52407ba8ef4c` |
| `…/bin/old_agbcc.stock_diag` | `1e277317a42dac66c84cc53c5ef1d9ee8ebe8d4b6252e526e542226351efe85c` |
| `logs/*.hintlog` (4 files) | see §evidence index — 171 `HT` and 86 `HTA` records each |
| `.i` inputs for look vs stock | byte-identical per source (`cumulative700` `31c0edfe…`, `efad23f8` `ba07273e…`) |

- Reload-created register-writing insns: lookahead 150 vs stock 150 (`efad23f8`),
  149 vs 149 (`cumulative700`); the **first 42 choices are identical**, then
  choice #42 (uid 2253/2248, the `w` ABI hint `r0 -> r1`) diverges and drags
  downstream choices with it: 12 further divergences on `cumulative700`, 14 on
  `efad23f8` (`logs/lookahead-phase-compare.txt`).
- **The trace is unfinished.** The parser's last printed summary
  (`logs/hint-state-summary.txt`) reports `accepted reloads look=0 stock=0` and
  `hinted selections = 0` for both sources — a parsing failure/incompleteness, not
  evidence that zero hints occurred; the raw logs contain 171/86 records per file.
  The internal-state analysis timed out before completion. Do not cite the zeros.
- Proposed but **NOT implemented and NOT tested**: a generic rival that honours
  the hint *without* advancing the fallback cursor. Only with parent approval and
  no `r0`/function-specific bias.

## Group 15 — layout accounting: known bugs, and the cross-pool lead (provisional)

The scratch layout audit is **invalid as printed** and its counts must not be
quoted. Known bugs in `address/experiments/address_span_audit12.py` and
`address12-span-audit.log`:

1. Pool spans end 2 bytes early (`[D9F8,DA26)`, `[DC90,DCB2)`, `[DD64,DD76)`,
   `[DE2C,DE46)`), so the last halfword of the pool's last word is not read.
2. The script iterates 2 bytes at a time but calls each 2-byte unit a "word", so
   it prints 23/17/9/13 = **62 "words"** where the real totals are 12/9/5/7 =
   **33 words = 132 bytes**.
3. The printed total is 2004, not 2006/2010; the combo accounting uses the wrong
   target spans.
4. Zero-halfword counting is **not** an instruction proof: several target zeros
   (`0x800DA06`, `0x800DA0E`, `0x800DCA6`) are the high halves of literal-pool
   words, not pads.

Corrected spans, verified read-only against `asm/rom_0800D684.s` label runs
during this docs pass:

| pool | target span (exclusive end) | bytes | 32-bit words |
|---|---|---:|---:|
| 1 | `0x0800D9F8 .. 0x0800DA28` | 48 | 12 |
| 2 | `0x0800DC90 .. 0x0800DCB4` | 36 | 9 |
| 3 | `0x0800DD64 .. 0x0800DD78` | 20 | 5 |
| 4 | `0x0800DE2C .. 0x0800DE48` | 28 | 7 |
| total | | **132** | **33** |

All 33 pool values are identical between target and the structural combo; pools
2-4 are simply shifted by +4.

**Cross-pool flag use (provisional, independently re-read here).** From the raw
target asm (`asm/rom_0800D684.s` lines around `_0800D9EC`/`_0800DA28`) and the
structural combo's linked disassembly
(`/tmp/d684-sixth-uY9kyw/address/logs/address11-cum700_wref_pin66ee.ours.dis`
lines 422-449):

```
target:  D9F0 ldr r0,[sp,#0x1C]
         D9F2 ldr r1,[pc,#40]  @ (0x800da1c)
         D9F4 cmp r0, r1
         D9F6 b.n 0x0800DA28
         D9F8 ...48-byte pool...
         DA28 blt _0800DA70          <- consumes the flags set across the pool
ours:    D9F0 ldr r0,[sp,#28]
         D9F2 ldr r1,[pc,#40]
         D9F4 b.n 0x0800DA28
         D9F6 movs r0,r0             <- zero alignment pad (0x0000)
         D9F8 ...same 48-byte pool...
         DA28 cmp r0, r1             <- compare moved to the post-pool block
         DA2A blt.n 0x0800DA72
```

Both branches are 2-byte `b.n`, so this is the compare moving across the pool,
not a branch-width change. It accounts for **one** of the combo's two interior
zero pads; it does **not** account for the whole +4 individually, and it is **not**
the parked `sub_08001150` case — that one was a dead write-back / globalizer
issue, not a proven literal-pool flag issue. Whether the remaining +4 is exactly
two alignment pads is **not** validated: the audit must repair its arithmetic
first, and any nonzero-halfword count is not an instruction proof.

## Group 16 — workflow, provider and infrastructure history

- OpenAI/Codex lane hit quota exhaustion; the Surplus-Luna lane failed with an
  invalid encrypted-reasoning payload. Both waves were interrupted by those
  provider failures, and one register-web and one address lane then timed out at
  the 7200000 ms bound. The user then authorized `surplus/deepseek-v4.1-flash`,
  which works; no CLI agents, no external provider fallback, no child delegation.
- A docs-writer attempt failed before any edit: the provider rejected the
  `developer` role message. The parent then set only `compat.supportsDeveloperRole
  = false` in the Surplus extension (outside the ROM repository, with a backup and
  a validated registration) and re-ran the same protocol. This run is that retry.
- The user's earlier `NotSurplus` extension also lives outside the ROM repository.
  Neither config change touches the ROM repo.
- Latest two experiment lanes timed out at 2 hours; the compiler provenance audit
  completed. **No independent fresh final review of the latest structural combo
  exists** because the wave was blocked.
- No permuter is running. The user killed 42 orphaned permuter workers in an
  earlier continued pass and explicitly forbade restarting it.
- Treat all subagent reports as evidence plus the corrections in this file, not as
  authority. The parent owns synthesis.

---

## Negative campaigns, grouped

Rejected by regression cost:

- `REG_EQUIV` live-length penalty `2 -> 1`: 78/462 corpus functions broken, D684
  unchanged.
- revert production `calls.c` precompute: no D684 effect, `sub_08003738` broken.

Rejected by target result:

- reset `last_spill_reg` per block (2010/1453/13).
- alias remove / alias early / move-hit2 cells (1998/1529, 1978/1852, 2006/932;
  and on the address lane 1822/1827 raw).
- explicit `sub_08017230` div-call probes and the `const`-annotation rival.
- address/byte hard pins (with and without clobber) at 2014/1401-1402.
- flag pointer and integer carriers (`k1=(s32)&flag` 2034/1835/40, etc.).
- `unk55` before/after carrier and cast forms (9 cells).
- 16 pre-carrier / first-edge-chain combinations except the branch-local r1
  clobber (which alone is 2010 and needs the chain drop to reach 2006/851).

Rejected on authority (never reuse):

- the targeted `worker-lookahead-chain` compiler (function/UID templating) and all
  its outputs, including the 196-diff score;
- `worker_*.py` probe conclusions that scored a private compiler through
  `match.py` main;
- unsafe probes that overwrote live `d0`/`u` with the unk55 address;
- prior stale permuter variants.

Superseded claims (do not restate as current):

- "959 instructions": raw disassembly rows, not instructions.
- "exhaustive sweep / no live lead / root cause identified" (third pass): the
  register web, edge families and scratch family have all moved since.
- the "no priority crossing" claim: missing `floor_log2` factor; corrected in §10.
- the layout audit's 62-word/124-byte pool totals and 2004 total: see §15.

## Artifact index

Scratch roots (all under `/tmp`, i.e. recoverable only from here and from the
patches preserved in this directory):

| root | contents |
|---|---|
| `/tmp/d684-exp-20260917-160143/lanes/carriers` | fourth/fifth-pass sources (`candidates/`), stock trials, `private-tools/worker-lookahead-chain` (**quarantined**) |
| `/tmp/d684-exp-20260917-160143/lanes/postloop` | fifth-pass regression lane: baseline corpus TSV, penalty1 and no-precompute corpora, pool-row audit |
| `/tmp/d684-exp-20260917-160143/lanes/reload` | compiler lane: `experiments/fifth-reload-lookahead-safe/{old_agbcc.published,patch.published}`, matrix cells, dump traces |
| `/tmp/d684-sixth-uY9kyw/pa` | register-web lane: `candidates/`, `registers-lane-20260917/` (harness, probes, dumps, hint-trace, logs) |
| `/tmp/d684-sixth-uY9kyw/address` | address lane: `candidates/`, `logs/` (linked bins + disasm per cell), `experiments/address*_audit12.py` (**arithmetic invalid**) |
| `/tmp/d684-sixth-uY9kyw/audit` | provenance gates: `clean-compiler-published/` (clean rebuild, patches, hashes), 462 corpus TSVs, whole-ROM logs |
| `/tmp/d684-parent-containment-jlwamA` | rejected targeted-reload compiler snapshot |
| `/tmp/d684-handoff-update-yQRXWw` | this docs pass snapshot: `HANDOFF.before.md`, `main-status.before`, `main-preexisting.diff`, `protected.sha256` |

Key artifact hashes (all re-checked read-only while writing this file):

```
5623424d…  pa/candidates/postloop-direct-w.c                    (best 291 source)
27079a24…  address/candidates/address11-cum700_wref_pin66ee.c    (structural)
ef631193…  pa/candidates/fifth-chain-followups/chain_pre_d0.c
157d1155…  pa/candidates/registers-web-precall-drop.c
efad23f8…  pa/candidates/registers-web-precall-pin-flagp.c
22207d11…  pa/candidates/registers-web-precall-pin-flagp-cell1.c
700ae325…  pa/candidates/registers-web-precall-pin-flagp-nod1carrier.c
ac18d079…  address/candidates/address10-wref-asm-after-pinbase.c
0092d964…  address/candidates/address9-efad_pin66ee.c
6a02c874…  address/candidates/address8-regweb157_pin66ee.c
66ee1d29…  address/candidates/address6-pins_addr_noclobber.c
10c29db5…  object of 5623 under the frozen generic compiler
6d5729b6…  linked 2006-byte candidate of 5623
4832bcab…  linked 2006-byte target slice
73d390ff…  frozen generic lookahead compiler
0a63b08e…  its patch (== clean lookahead.patch)
1bb68c02…  clean rebuild of the same compiler
b94fe93e…  clean complete-source.diff (preserved here)
9681a2e7…  patched reload1.c after that patch
da0f688f…  production reload1.c
```

Report files and their corrections live in
[`sub_0800D684-HANDOFF.md`](sub_0800D684-HANDOFF.md) § artifact index. The three
most load-bearing corrections to carry forward: the 959-row figure is not an
instruction count; the mixed-base probe table in the earlier surplus address
report must be read by source hash (some rows are `ef631` raw337, not `5623`
raw291); and the layout audit's pool arithmetic is invalid until repaired.

## Next untried work (recorded, not executed)

1. **Repair the read-only layout accounting** using the 33 full 32-bit pools and
   code/alignment spans, then verify the cross-pool compare lead (§15). Read-only;
   no build.
2. **Finish the internal hint-state trace parser**, then decide only with parent
   approval whether the generic "preserve the fallback cursor" rival is worth a
   cell — with no `r0`- or function-specific bias.
3. **Keep both axes** (best 291 and structural `27079a24`); combine regressions
   only after an actual code improvement lands. The clean compiler already gates
   462/462; re-run the whole corpus only when *compiler behaviour* changes, not per
   source experiment.
4. **On an exact 2006 MATCH:** independent semantic and provenance review, private
   extraction respecting trailing data and shared pools, then whole-ROM
   `make check`. No production adoption from a near-miss.