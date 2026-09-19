# LanePerm report (decomp-permuter sweep on sub_0800D684)

Time-box: ~50 min. Two permuter instances: the sanctioned one on
`nonmatchings/sub_0800D684/` (`-j8`) plus a second seed on a copy of the
same inputs in `/tmp/laneperm/perm2` (`-j6`). Every output dir was
re-scored with `filediff.py`/`d684tool.py` (never trusted the permuter's
own score). Mid-run the baseline was rebased by Main; both instances were
restarted from the new `src/sub_0800D684.c`.

Baselines: old 2010/6/1059 -> new 2010/4/959 (Main's rebase).

## Variants that changed the score

| variant (from -> to) | source change | size/hunks/sdiff |
|---|---|---|
| new baseline -> `output-1120-1` | hit2 block: `sd = 0;` then **insert `dz = 4;`**, and both `>> 4` in that block's `sub_0800E708(...)` args -> `>> dz` (dz is an existing `s32` local, dead there; `>> dz` with dz==4 is identical behaviour) | 2010/**4**/**949** (was 2010/4/959) |
| hand-applied to `/tmp/laneperm/v1120.c` | same edit, re-scored independently | 2010/**4**/**949** (confirms) |
| `output-1130-1` | `k2 = edgeq + v[1];` -> `k2 = v[1] + edgeq;` | 2010/4/969 (worse) |
| `output-1105-2` | `k0 = gUnk_083FDA2C[(*cc).d].f1;` -> `k0 = (*(&gUnk_083FDA2C[(*cc).d])).f1;` | 2006/5/1293 (worse) |
| `output-1080-3` | same site, `(*(gUnk_083FDA2C + (*cc).d)).f1` | 2006/7/1408 (worse) |
| old base, best of 14 dirs: `output-1060-1` | temp-var scaffolding in the post-loop block | 2006/7/1393 vs 2010/6/1059 (worse) |

## Best file

`/tmp/laneperm/v1120.c` = current `src/sub_0800D684.c` + the `dz` edit
above: **size 2010, hunks 4, sdiff 949**, `match: false`.
Raw permuter candidate kept at
`nonmatchings/sub_0800D684/output-1120-1/source.c` (same 2010/4/949).

Hunk list is unchanged (still T52 `ldr r7,=pa; adds r1,r7,#0`, O264
`adds r6,r4,#0`, O598, O617) - the gain is 10 sdiff of register
recolours, not a shape fix.

## What I learned

The permuter's metric tracks filediff closely but not monotonically: on
the old base its best scores (1060-1085) all re-scored *worse* than the
baseline, because it prices a reorder at 60 while filediff charges the
two instructions at 100+100 - so it happily "improves" by moving
instructions, which is exactly the metric that must not move. Its one
real win came from replacing an immediate (`>> 4`) with a value carried
in an existing dead local (`dz = 4; ... >> dz`), i.e. it found a *new
free variable carrier* at the post-loop `sub_0800E708` site; that is the
same class of lever as the known `cc`/`pa`/`pb` reload mechanisms, so
"give the allocator a different live range to rematerialise from" is
worth mining at the O598/O617 sites. Automation built along the way and
left in `/tmp/laneperm/`: `scan.py` (polls output dirs and re-scores
them), `combine2.py` (greedy hill-climb over *combinations* of permuter
mutations - needs the printer-formatted base from `permuter.py --debug`,
which is the only sane way to read `diff.txt`, since it is not a diff
against `base.c`).
