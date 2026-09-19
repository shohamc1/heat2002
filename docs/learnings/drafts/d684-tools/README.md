# d684-tools

Experiment tooling for `sub_0800D684`, copied out of `/tmp/d684v5` so it
survives scratch cleanup. Usage and conventions: `../sub_0800D684-NEXT.md`.

- `d684tool.py` — isolated compile + score + aligned disassembly. Never writes
  to the repo. Defaults to a workdir under `/tmp/d684v5`; pass `--workdir`.
- `filediff.py` — **the primary score** (2026-09-19). Field-level diff against
  the target: 100 per instruction-shape difference, 5 per register recolour,
  1 per immediate/offset. `--list` prints worst-first. A byte match needs
  `sdiff == 0` **and** `size == 2006`; `hunks == 0` alone is not enough
  because it masks register names.
- `ndiff.py` — register-aware differing-line count and list (registers kept,
  immediates masked). Coarser than `filediff.py` but easier to read.
- `hill.py` — hill-climb harness over a mutation list (declaration
  permutations etc.); writes `best.c` + `log.jsonl`. Reusable pattern for any
  generated mutation family.
- `corpus_check.sh` — whole-ROM `make -B check` with `src/sub_0800D684.c`
  moved aside and restored on every exit path.
- `search.py` — cartesian search over curated source levers
  (`SEARCH_BASE=<base.c> python3 search.py -j8 --out ...`).
- `dials.py` — inserts semantically neutral self-store/re-read perturbations
  before every statement and scores each.
- `diag_rotation.sh` — rebuilds cc1 with reload's `last_spill_reg` starting at
  a different index; restores the tree on exit. Diagnostic only.
- `reload_trace.patch` — `git apply` inside `tools/agbcc` to build a cc1 that
  prints reload's per-chain spill order, live sets, use counts, picks and
  allocations (`RT_UID=<insn uid>` selects the chain dump; `RT_FREE4`,
  `RT_ADD4` are the set experiments). Build with
  `make -C tools/agbcc/gcc old -j8`, then `d684tool.py check --cc
  tools/agbcc/gcc/old_agbcc`. Restore with `git checkout --` afterwards.
- `reload_set.patch` — the same, extended with a full spill-set override:
  `RT_SET="0,1,2,3,4,6"` / `RT_ADDSET=` / `RT_DELSET=` rewrite
  `used_spill_regs` at `finish_spills`.  Used by the seventh pass to force all
  511 non-empty subsets of r0-r8 and prove the last two hunks are not a
  spill-set artefact (`{0,1,2,3,6}` natural = 2010/2 hunks; `{0,1,2,3,4,6}`
  = 2006 bytes but 12 hunks; no subset below 2).
- `LANES.md` — brief handed to each subagent lane.

All of them need the repo's `tools/agbcc/old_agbcc` and the ROM, and should be
run with the repo as cwd.
