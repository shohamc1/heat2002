/*
sub_08003F84 — QUARANTINED after 11 match.py iterations (budget 10).

STATUS: instruction sequence matches the ROM exactly except:
1) Loop tail (ours 144 bytes vs target 148, 2 insns short):
     target: movs r2,#1 / add r9,r2 / movs r0,#0x80 / lsls r0,#1 / cmp r9,r0 / bne
     ours:   movs r0,#1 / add r8,r0 / adds r0,#0xFF / cmp r8,r0 / bne
   GCC's combine folds the compare const as (1 + 255) reusing the increment's
   #1 register (r0). Target kept the #1 in r2 and built 256 fresh via 0x80<<1.
   Reload's scratch choice (r0 vs r2 for the #1) is the root cause; no source
   shape found that forces r2.
2) High-register permutation of the three channel values:
     target: r(red)=sl(10), g(green)=r8, i=r9   [alloc order g, i, r]
     ours:   i=r8, r=r9, g=sl                   [alloc order i, r, g]
   Everything else (a=r6, ps IV=r5, pd IV=r4, bp=r7, all instruction order,
   all masks/shifts/pool) matches byte-for-byte.

Allocator analysis (old_agbcc -dl, global.c allocno_compare):
pri = floor_log2(REG_NREFS)*REG_NREFS/live_length*10000*size.
Verified v7: pri(pd)=3*11/58=.569, ps=3*11/60=.550, a=3*8/46=.522,
bp=2*7/38=.368, i=2*7/68=.206, r=2*5/82=.122, g=1*3/35=.086 ->
order pd,ps,a,bp,i,r,g == observed v7 assignment. Target needs
order pd,ps,a,bp,g,i,r, i.e. pri(g) must rise into (.206,.368) or pri(i)
and pri(r) must drop below g's .086.

Swept (all keep instruction order unless noted):
- v: u32 (lsrs) vs s32 (asrs) — u32 required.
- mask constant: 0x7C0000 wrong (my arithmetic error); 0x1F0000 correct
  (GCC materializes as movs #0xF8; lsls #13).
- full-expression statements (v2/v3): constants load after shifts — wrong order.
- r as single statement `r = v & 0x1F0000;` (v2/v8) vs init+&= (v4): both emit
  const early + park in home + late apply (old_agbcc const hoisting) — either ok.
- m = 0x1F local: needed so 31 is loaded once before the 0x1F0000 const
  (matches movs r0,#31 first); const-left operand order changes nothing.
- bp <<= 16 (in-place, matches lsls r7 in place); g must stay a separate
  local (lsls r2 + mov r8 form).
- loop: pointer walk (v4: wrong pd/ps/a allocation), array i*3 (v6: pd/ps/a/bp
  correct), separate k index stride 3 (v8-10: same as v6), for vs do-while vs
  ++i in condition: all identical output. for-increment order (k+=3,i++) vs
  (i++,k+=3) controls IV-increment-before-i-increment order (target: IVs first).
- LICM form ((gp<<16) inline in loop, v11): GCC does NOT hoist it; keeps shift
  in-loop and flips subtract operand order — worse.
- REG_NREFS counts pre-CSE mentions (measured: i keeps T=7 even when arrays
  indexed by k; r keeps T=5): no source shape found that lowers them, and none
  that raises g's T from 3 to 4-6 (needed .206<pri(g)<.368 with L=35).

Next ideas if revisited: find a source giving g 4+ RTL mentions (the missing
lever); or force the #1 increment scratch to r2 (e.g. keep a value live in
r0/r1 at the loop tail whose load the compiler cannot remove).

Restore this file to src/ as-is to re-run: python3 scripts/match.py sub_08003F84
*/

#include "global.h"

extern s32 gUnk_02022E20[];
extern s32 gUnk_02023A20[];
extern u16 gUnk_02022E18;
extern u8 gUnk_02022E14;

void sub_08003F84(s32 a, u32 b)
{
    u32 v = b << 16;
    u32 m = 0x1F;
    s32 r = v & 0x1F0000;
    u32 gp = m & (v >> 21);
    u32 bp = m & (v >> 26);
    s32 g;
    u32 i;
    u32 k;

    g = gp << 16;
    bp <<= 16;
    i = 0;
    k = 0;
    do {
        gUnk_02023A20[k] = (r - gUnk_02022E20[k]) / a;
        gUnk_02023A20[k + 1] = (g - gUnk_02022E20[k + 1]) / a;
        gUnk_02023A20[k + 2] = ((s32)bp - gUnk_02022E20[k + 2]) / a;
        k += 3;
    } while (++i != 256);
    gUnk_02022E18 = a;
    gUnk_02022E14 = 1;
}
