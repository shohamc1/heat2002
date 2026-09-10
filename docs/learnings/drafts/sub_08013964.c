/* MISMATCH: identical except the ROM pushes/pops r6 (30 b5 vs 70 b5,
   30 bc vs 70 bc). Every other byte matches.
   NEW: the bare `return;` (no value, in a function returning s8) is what
   makes the early exit branch straight to the epilogue with no `movs r0, #0`.
   `return 0;` / `return r;` both emit `movs r0,#0; b end` plus a mid-function
   literal pool. */
#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_0202EF00[];
extern s8 sub_08016634(void);
extern s8 sub_08013878(void);
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08013908(u32 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_08016658(void);
extern void sub_0800048C(void);
extern void sub_08000458(void);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);
s8 sub_08013964(void)
{
    u8 buf[0x200];
    s8 sel;
    if (sub_08016634() != 0) {
        if (sub_08013878() == 0)
            return;
    }
    sub_08011C9C(6, buf);
    sub_08013908(0);
    sub_08004238(buf, 0x0F);
    sub_08016658();
    sub_08013908(1);
    sel = 0x40;
    do {
        sub_0800048C();
        if (gKeysPressed & 9)
            sel = 0;
        sub_08000458();
    } while (sel == 0x40);
    if (gUnk_0202EF00[3] != 0)
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return sel;
}
