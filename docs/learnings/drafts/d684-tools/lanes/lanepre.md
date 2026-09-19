# LanePre report (pre-loop region). Rebased on v2 = 2010 / 4 hunks / sdiff 949.
**No variant improved on the baseline.** Best file `/tmp/lanepre/v2.c` (= current src copy).
~1200 candidate sources scored (740 pre-loop orderings + ~110 spelling variants).

| variant (exact old -> new) | size | hunks | sdiff |
|---|---|---|---|
| baseline (`v2.c`) | 2010 | 4 | 949 |
| reorder: best of 604 ordered perms + 600 random interleavings of the 9 pre-loop stmts (`CD24=`, `flag=`, `cursor=`, `pa=`, `pb=`, `cc=`, dial, `k2=`, call) | 2010 | 7 | 1394 |
| `gUnk_0202CD24 = 0x200000; flag = 0;` -> `flag = 0; gUnk_0202CD24 = 0x200000;` | 2010 | 6 | 1550 |
| `flag = 0;` placed before both the CD24 store and `cursor = base;` | 2010 | 6 | 1750 |
| `count = ...90; if (...DC != 0) count = ...AC;` -> ternary `...DC != 0 ? ...AC : ...90` (and `if/else` form) | 2018 | 12 | 3517 |
| `k2 = (s32)pa; sub_0800D5D4(a1, (s32 *)k2);` -> `sub_0800D5D4(a1, pa);` (or `pp = pa; ... pp`) | 2010 | 5 | 1149 |
| prologue -> `d0 = self->unk08; edgeq = other->unk08; dz = d0 - edgeq;` | 2010 | 4 | 959 |
| prologue -> `dz -= other->unk08;` (drop edgeq) | 2010 | 4 | 1089 |
| prologue -> `d1 = self->unk08; dz = d1;` carrier | 2010 | 4 | 1299 |
| prologue `dx = self->unk00; ... dx -= other->unk00;` -> `dx = self->unk00 - cursor->unk00;` | 2014 | 8 | 1383 |
| `self=` group moved before the `dx=` group | 2014 | 10 | 2268 |
| `a1->unk175 = a1->unk175;` deleted | 2010 | 4 | 974 |
| `if (a1 == base)` -> `if (base == a1)` | 2010 | 4 | 959 |
| `if (a1->unk7D != 0 && gUnk_020020DC != 0)` -> operands swapped | 2006 | 7 | 1593 |
| `u8 i;` -> `s32 i;` | 2006 | 7 | 1347 |
| `u8 flag;` -> `s8 flag;` / `u8 count;` -> `s16 count;` | 2014 | 6/12 | 1254/1927 |
| `a2 = (s32)pa;` added before the call (a2 is read in-loop) / call still `k2` | 2014/2010 | 29/39 | 3530/5273 |

Ties at 2010/4/949 (byte-identical code) -- the region is spelling-insensitive: ~25
call-arg forms (carriers k0/k1/k2/k3/d0/d1/e/u/w/v1hold/lim3800/fraction/edgeq/dx;
`(s32*)`, `(s32*)(void*)`, `(s32)(void*)`, `&pa[0]`, `&gUnk_0202CCB0[0]`, `pa + 0`,
`gUnk_0202CCB0`, `(s32*)(k2 = (s32)pa)`, `&((s32*)k2)[0]`, `(s32*)(u8*)k2`,
`(s32*)(u32)k2`, extra `s32 *pp`, `u32 *pa`); `w`/`e`/`self`/`other`/`a1` prologue carriers
incl. `dz = self->unk08; d0 = dz;`; addenda `lim3800 = k2;`, `x = k2;`; `count` as `s32`;
`if (x)` vs `if (x != 0)`; `&x[0]`/`(void*)` casts for `base`,`pb`,`cc`;
`(s32)cursor + 0x190` / `+ 400`; `void`->`s32` prototype with dead result copy.

## Learned
The pre-loop text is a hard local optimum and not spelling-sensitive: only the presence of
the `k2 = (s32)pa` copy changes anything, and every spelling keeping it emits the identical
stream. Pre-reload RTL is `156:(set 39 47) 159:(set r0 a1) 161:(set r1 39) [REG_DEAD 39,
REG_EQUAL gUnk_0202CCB0]; call 163`, which gives the ROM's `ldr r7,=pa; adds r1,r7,#0` iff
pseudo 39 (k2) is NOT allocated r1. It is r1 here because global_alloc pass 0 finds
`hard_reg_copy_preferences[39] = {r1}` (local-alloc `qty_phys_copy_sugg` from `r1 = 39`)
free; the ROM's r7 means k2 either lost r1 to a conflicting allocno or was call-crossing
(`used1 = call_used_reg_set` -> callee-saved). Both follow from the whole function's allocno
order, so hunk 52's copy and all residual pre-loop recolours (0x18F const r1/r6; flag+count
r2/r3 vs r3/r6; `d0` load r0/r5; pa remat r0/r6; -0x1C00 const r0/r6) are downstream of the
still-differing loop/post-loop regions (same root cause as the r4/r6-vs-r7 theme; e.g.
`w = self->unk08;` was catastrophic on v1 but now ties). Every attempt to force it from my
region explodes (a2 live 29 hunks; ternary count 12; `s32 i` 7), so the pre-loop text should
be left as-is and its recolours re-checked after the other lanes land.
