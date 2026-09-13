/*
sub_0800383C (84 b) — QUARANTINED, one register permutation away.

Instruction stream, size, branch structure, pool (0x0000FFFF) all match.
The ONLY diff is which of r2/r3/r4 three locals call home:

  target: count-narrow->r6, t->r3 (pool), s->r2 (adds r2,r0 = s=src), value->r4 (ldrh)
  ours:   count-narrow->r6, t->r4 (pool), s->r3, value->r2
  (dst stays r1, i stays r5 in both; a pure 3-cycle t/s/value.)

Diagnosis (old_agbcc -dl/-dg): all six are global allocnos; sorted by
QTY_CMP_PRI = floor_log2(refs)*refs/len:
  s     4*16/36 = 1.778   (allocated 1st)
  dst   4*16/40 = 1.600   (2nd; copy-pref keeps r1)
  value 3*12/31 = 1.161   (3rd -> takes r2)
  t     4*18/64 = 1.125   (4th -> r4)
Target needs t before value AND s to land on r2 (it does when count's
allocno is absent — tested by replacing the count use with a literal:
s->r2, value->r3, t->r4 — so count's allocno/pref chain is what bumps
s off r2 and value off r3).

Swept (~25 shapes, all leave the permutation unchanged):
- separate `u16 *s = src` local vs using the param directly (param form
  emits the copy at the very top, before count's narrowing — target has
  it after t's pool load, so the s-local shape is positionally right)
- merging the run counter into t (`t = *s++; while (t) ...`) vs a
  separate n local
- t/value/i as u32/s32 (breaks prologue widths)
- all 24 declaration orders of (t, s, value, i) — qty creation follows
  first SET, declaration order is a no-op
- 60-combo sweep: inner loop forms (while(t!=0)/while(t)/for(;t!=0;t--)),
  *dst++ vs *dst;dst++, i++/++i/i=i+1, value==t vs t==value
- decomposed *s++ into *s; s+=1, t = -1 spelling, while-form outer loop
- `count > i` operand swap (flips cmp operand order, wrong)
- constant-valued locals (u16 one=1 / zero=0) for the bcfef4c trick —
  they stay live and add a movs+push instead of folding

PRI math: flipping t above value needs t refs 18->20 or len 64-><=62
(exact tie at 62 then breaks right by qty number), or value refs 12->11
or len 31->33; none reachable without changing instructions.
*/

#include "global.h"

void sub_0800383C(u16 *src, u16 *dst, u16 count)
{
    u16 t = 0xFFFF;
    u16 *s = src;
    u16 value = *s++;
    u16 i;

    for (i = 1; i < count; i++) {
        *dst++ = value;
        if (value == t) {
            t = *s++;
            i++;
            while (t != 0) {
                *dst++ = value;
                t--;
            }
        }
        t = value;
        value = *s++;
    }
}
