#include "global.h"

extern u16 gUnk_020004A0;
extern volatile u8 gUnk_02000494;
extern u8 gUnk_02000498;
extern u16 gUnk_02000496;
extern u16 *volatile gUnk_0200049C;
void sub_08016ED8(u16 *a)
{
    u16 *p;

    gUnk_020004A0 = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000200 |= 8 << gUnk_02000494;
    *(volatile u16 *)0x04000208 = 1;
    gUnk_02000498 = 0;
    gUnk_02000496 = *a++;
    p = gUnk_0200049C;
    *p = *a;
    p++;
    gUnk_0200049C = p;
    *p = a[1];
    p--;
    gUnk_0200049C = p;
}

/* QUARANTINED (restored notes — mv overwrote earlier version):
 * sub_08016ED8 (100b) — MISMATCH, exactly 4 instructions, all in the
 * `8 << gUnk_02000494` operand of the REG_200 (0x04000200) |= :
 *   target: ldr r1,=gUnk_02000494; ldrb r1,[r1]; movs r2,#8;
 *           lsls r2,r1; ldrh r1,[r4]
 *   ours:   ldr r1,=gUnk_02000494; ldrb r2,[r1]; movs r1,#8;
 *           lsls r1,r2; ldrh r2,[r4]
 * (orrs r1,r2 / strh match from there on). `a` (param) lives in r0
 * across the whole prologue in both, so the free pool is {r1,r2}.
 * Everything else in the function matches, incl. the *a++ walk and the
 * gUnk_0200049C++/-- writeback driven by `u16 *volatile`.
 * Swept: volatile/non-volatile extern for gUnk_02000494
 *   (non-volatile hoists `movs #8` ahead of the ldrb — wrong order,
 *    though it then reuses the address reg: ldrb r2,[r2]);
 * *(volatile u8 *)0x02000494 cast; volatile-qualified access of a
 * non-volatile extern; |= vs REG = 8<<x | REG; (u32) cast on shift
 * operand; u8/u16/s32/s8 temp locals (each shifts the early REG_208
 * address reg r3->r4 and breaks the matching prologue);
 * extern volatile u8 gUnk_02000490[] + [4] indexing (gives
 * ldrb r2,[r1,#4] with a 0x02000490 pool entry — wrong bytes);
 * volatile u8 *q pointer local (pushes an extra callee-saved reg).
 */
