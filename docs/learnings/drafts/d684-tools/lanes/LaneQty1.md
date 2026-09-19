# LaneQty1 report — call-setup blocks (blocks 42/48 and their mirror family)

**Result: no variant beat the baseline. Best = `/tmp/LaneQty1/v0.c` (unchanged), 2010 B / 2 hunks / sdiff 602.**
No candidate reached `(hunks, sdiff) < (2, 602)`; every score-moving variant moved it up.

## 1. Block ↔ source map (verified, replaces the brief's guess)

`old_agbcc -dl` writes `<file>.i.lreg`, which contains *both* flow's per-register
"used N times ... in block B" lines **and** the RTL with `;; Start of basic block B`
markers. That gives an exact block↔RTL map, and the RTL's `(set (reg:SI 3 r3) (const_int N))`
(4th call argument) plus the neg/ashift/div pattern identifies each call site:

| block | source line | call | 5th arg | decl'd qtys (`-dl`) |
|---|---|---|---|---|
| 27 | 786 | `(a1,a2,cursor,0,...)` | `&gUnk_0202CC90` (**literal**) | **4**: 175(LC7 ld),177(-u),178(e<<16),183(quot) |
| 32 | 792 | `(a1,a2,cursor,1,...)` | `cc` | 2: 201(e<<16), 205(quot) |
| 37 | 800 | `(a1,a2,cursor,2,...)` | `cc` | 2: 223, 227 |
| **42** | **807** | **`(a1,a2,cursor,3,cc,&flag,-w,(e<<16)/-w)`** | `cc` | **3**: 244(`-w`),245(e<<16),250(quot) |
| **48** | **829** | **`(cursor,a2,a1,0,cc,&flag,-u,(e<<16)/-u)`** | `cc` | **3**: 314,315,320 |
| 53 | 835 | `(cursor,a2,a1,1,...)` | `cc` | 2: 338, 342 |
| 58 | 841 | `(cursor,a2,a1,2,...)` | `cc` | 2: 360, 364 |
| 63 | 847 | `(cursor,a2,a1,3,...)` | `&gUnk_0202CC90` (**literal**) | **4**: 381(LC7 ld),383(-w),384,389 |

The *absolute* quantity count is set by the 5th argument: the **literal**
`&gUnk_0202CC90` creates one extra local quantity (a fresh pseudo for the pool
load, RTL `reg = mem/u(*.LC7)`), the live variable `cc` does not (it is live-in,
so reload rematerialises it with no local qty). Hence 4 qty (qsort path) for
blocks 27/63 and 3 qty (hand-rolled `case 3`) for 42/48.

**Blocks 42 and 48 — the assigned targets — are already register-exact.** The block-42
setup (`800d90c ldr r1,[pc] / str r1,[sp,#0] / add r2,sp,#32 / str r2,[sp,#4] /
mov r3,r8 / negs r1,r3 / str r1,[sp,#8] / lsls r0,r4,#16 / bl / str r0,[sp,#12]`)
matches the target *line for line*, and so does block 48's
(`800d9cc ldr r3 / str r3 / add r0,sp,#32 / str r0 / negs r1,r7 / str r1`).
The only nearby diff is `800d902`/`800d9d8`-class recolours belonging to the
*preceding* bound-check block and to the global pseudo for `e` (`r4` vs `r6`),
i.e. nothing a local-alloc qty change can reach.

The recolours the brief attributes to 42/48 are really at **27 (4 lines, 20 pts),
32 (2, 10), 53 (2, 10), 63 (6, 30)**:
* b27 (800d80e–800d814): ours `ldr r0/str r0/add r1,sp,#32/str r1` vs target `r3/str r3/add r0/str r0`
* b32 (800d864/866), b53 (800da54/56): ours `add r6,sp,#32` vs target `add r0,sp,#32`
* b63 (800dafc–800db06): ours `r0,r1,r2` for (literal,`&flag`,`-w`) vs target `r1,r2,r3`

## 2. The `case 3` premise is false

`local-alloc.c:1355-1370`: `case 3` runs `cmp(0,1)`, `cmp(1,2)` (+`EXCHANGE(2,1)`),
then falls into `case 2`'s `cmp(0,1)`. `(0,1)(1,2)(0,1)` **is** a complete 3-element
sorting network (bubble pass 1 pushes the max to index 2, pass 2 fixes 0/1); the
fall-through merely repeats a comparison that the second exchange has already made
true (`qty_compare` returns 0 on ties, so it leaves the order alone). The 3-qty path
therefore allocates in strictly decreasing `QTY_CMP_PRI` order, exactly like the
qsort path's primary key — there is no non-monotonic allocation to exploit, and the
experiments below agree: making a 3-qty block into a 4-qty block (or vice versa)
never buys the target's rotation.

## 3. Score-changing variants (all worse; `-dl` qty counts as `b27/b32/b37/b42/b48/b53/b58/b63`)

| # | exact edit (old → new) | qtys before → after | size | hunks | sdiff |
|---|---|---|---|---|---|
| base | — | 4/2/2/**3**/**3**/2/2/4 | 2010 | 2 | **602** |
| L847cc | L847 `3, &gUnk_0202CC90,` → `3, cc,` | b63 4→3 | 2010 | **4** | 804 |
| L786cc | L786 `0, &gUnk_0202CC90,` → `0, cc,` | b27 4→3 | 2014 | 6 | 1143 |
| L807lit | L807 `3, cc,` → `3, &gUnk_0202CC90,` | b42 3→4 | 2014 | 4 | 1008 |
| L829lit | L829 `0, cc,` → `0, &gUnk_0202CC90,` | b48 3→4 | 2014 | 4 | 1013 |
| L786cc+L847cc | both literals → `cc` | b27 3, b63 3 | 2010 | 6 | 1130 |
| L807lit+L829lit | both `cc` → literal | b42 4, b48 4 | 2014 | 4 | 1058 |
| L847cc+L829lit | as above | b63 3, b48 4 | 2010 | 4 | 854 |
| L786cc+L807lit | as above | b27 3, b42 4 | 2014 | 6 | 1188 |
| all4swap | all four swapped | 3/2/2/4/4/2/2/3 | 2010 | 6 | 1225 |
| b42_k1e | L799-800: insert `k1 = e;` then `(e << 16) / -w` → `(k1 << 16) / -w` | b42 3→**0** (split) | 2038 | 40 | 5804 |
| b42_d1e | same, carrier `d1 = e;` | b42 3→0 | 2018 | 8 | 1774 |
| b42_k2e | same, carrier `k2 = e;` | b42 3→0 | 2014 | 10 | 1705 |
| b42_k3neg | insert `k3 = -w;`, pass `k3, (e << 16) / k3` | b42 3→0 | 2034 | 39 | 5887 |
| b42_self | insert `k2 = k2;` before the L807 call | b42 3→18, b48 3→1, b53 2→1 | **1986** | 10 | 5518 |
| b63_k1e | L846-847: `k1 = e;` + `(k1 << 16) / -w` | b63 4→0 | 2034 | 21 | 3522 |
| b63_k3neg | L846-847: `k3 = -w;` + `k3, (e << 16)/k3` | b63 4→0 | 2034 | 38 | 5630 |
| b27_k1e / b27_k3neg | same on L785-786 | b27 4→0, b32/37/53/58 2→4 | 2046/2050 | 62/66 | 28866/30060 |
| A_b47_flat | L844-845 → `if ((u32)(edgeq + v2 + 0x1C00) <= 0x3800)` (drop `d1 =`) | b63 4→2 | 2046 | 8 | 2729 |
| A_b41_flat | L805-806 → `if ((u32)(k2 + 0x1C00) <= 0x3800)`, L807 `d1`→`k2` | b42 3→1 | 2050 | 9 | 5527 |
| A_both_flat | both of the above | b42 1, b63 2 | 2086 | 14 | 7637 |
| M1/M6 | L797-798 deleted (or kept), L800 `(d1 << 16)` → `(k2 << 16)` | b42 3 (unchanged) | **2006** | 6 | 1138 |
| M7 | L841 `(e << 16)` → `(k0 << 16)` (carrier kept) | all unchanged | 2010 | 2 | 677 |
| M2 | L844 deleted, L841 `(e << 16)` → `(k0 << 16)` | b63 4→2 | 1998 | 7 | 2040 |
| b42_u16 / b48_u16 | `(e << 16)` → `(e * 65536)` | unchanged | 2010 | 2 | 602 (inert) |
| M8_k1shift_keep | L800 `(d1 << 16)` → `(k1 << 16)`, carrier kept | unchanged | 2010 | 2 | 602 (inert) |

### Inert family (byte-identical output, 2010/2/602, qtys unchanged)
`B_b42_noCarrier` (delete `k1 = e;` / `d1 = k1;`, keep `(d1 << 16)`) ·
`B_b42_d1e` (replace them with `d1 = e;`) · `B_b42_k1e` (`k1 = e;` + `(k1 << 16)`) ·
`C_b48_carrier` (add `k1 = e; d1 = k1;` before L844) · `C_b48_carrier2` (`d1 = e;` before L844) ·
`M8_k1shift_keep`.  So the whole carrier spelling family is a no-op for this score.

### Directions not covered / negative space
* Argument-order permutation is impossible in C (the list is fixed); forcing
  evaluation order of the 8th arg via a hoisted local always *moved the division
  out of the call-setup block* (b42/b63 qty count → 0, size +24), i.e. it is not
  stream-preserving.
* The `&flag` remats that dominate the mirror diffs (`add r6,sp,#32` vs
  `add r0,sp,#32`) are pseudo 734 = `sp+32`, rematerialised by **reload** from a
  rotating scratch pool, not local-alloc; no local qty edit can reach them.
* Only two shape-level diffs remain in the whole function (100 pts each): our extra
  `ldr r2,[pc,#300]` at `800db64` and `ldr r0,[pc,#256]` at `800db90` — two extra
  post-loop `cc` remats, outside this lane's blocks. Our deliberate 2010-byte stream
  comes from the `(d1 << 16)` spelling at L800: `(k2 << 16)` reaches the target's
  2006 bytes but costs 4 extra hunks (M1, above).

## 4. Learning (one paragraph)

The three-quantity lead does not hold: `local-alloc.c`'s hand-rolled `case 3`
sequence is a correct bubble sort (with one redundant comparison), so 3-qty blocks
allocate in exactly the same priority order as the qsort path, and block count
changes do move the score but only *up*. Mapping the `-dl` block numbers to source
(via the `.i.lreg` RTL, not guesswork) shows the two assigned call-setup blocks,
42 = L807 and 48 = L829, already agree with the ROM **line for line** on every
register operand; the quantity count there (3) is set by passing the live variable
`cc` instead of the literal `&gUnk_0202CC90`, which would make it 4. The recolours
that remain in this family (blocks 27/32/53/63, 70 of the 602 points) all come from
reload's rotating scratch pool (`&flag` → `r6` vs `r0`, the literal → `r0` vs `r3`,
`-w` → `r2` vs `r3`), which changes only via the register-pressure/live-set
prefix of the whole function — not via any spelling of these eight calls, carrier,
copy, self-assignment or quantity count (30+ score-changing variants, all worse;
8 further spellings proved byte-inert).