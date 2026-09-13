/* sub_08016F80 -- draft. Remaining diff vs ROM (108/120 bytes, structure matches):
   1) AND order in DISPCNT setup: ROM `ands r4,r3` (masked-value dest, const second),
      all reachable shapes give `ands r3,r4` (const dest). Tried: local v, in-place
      &=, operand swap in |, extern volatile symbols vs casts.
   2) guard read: ROM `adds r1,#2; ldrh r1,[r1]` (real pointer bump, direct [r1]);
      every C shape gives `ldrh rX,[rX,#2]` (offset form) -- the offset is legal for
      HImode (<64) so find_best_addr folds p++ into the offset.
   3) spin mask: ROM re-materializes 0x8000 INSIDE the spin (movs+lsls+adds r1,r0,#0)
      with its own DE pool load outside; CSE merges guard+spin mask pseudos into one
      global allocno so the spin reuses the guard's r2 via `adds r0,r2,#0`.
   dma/src/dst store shape, IE save/restore, push set, and overall branch layout
   all match. */
#include "global.h"

extern u32 gUnk_0202F240;
extern volatile u32 gUnk_040000D4[];
extern volatile u32 gUnk_040000D8;
extern volatile u16 gUnk_040000DC_16[];
extern volatile u16 gUnk_040000DE;

void sub_08016F80(u32 src, u32 dst, u16 cnt)
{
    u16 saved;
    volatile u16 *disp;
    volatile u16 *p;
    u16 v;

    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    disp = (volatile u16 *)0x04000204;
    v = *disp;
    v &= 0xF8FF;
    *disp = ((u16 *)gUnk_0202F240)[3] | v;
    gUnk_040000D4[0] = src;
    gUnk_040000D8 = dst;
    *(volatile u32 *)gUnk_040000DC_16 = 0x80000000 | cnt;
    p = gUnk_040000DC_16;
    p++;
    if (*p & 0x8000) {
        do { } while (gUnk_040000DE & 0x8000);
    }
    *(volatile u16 *)0x04000208 = saved;
}
