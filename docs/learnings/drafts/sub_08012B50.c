/* MISMATCH: 108 bytes, correct size, ONE instruction-pair swap.
   ROM narrows b (r1->r7) before a (r4 in place); we do a then b.
   Cause found: agbcc's assign_parms (function.c:4246) emits every parm's
   copy in the main stream and defers every parm conversion to
   `conversion_insns`, flushed after the loop -- so conversions always come
   out in DECLARATION order. K&R with reversed declarations does not change
   DECL_ARGUMENTS order; insn scheduling is off (-fno-schedule-insns changes
   nothing).
   Getting b first needs a's narrowing to come from the BODY, not from
   assign_parms: `u8 sub_08012B50(u32 arg, u8 b)` with `a = arg;` orders it
   right (09 06 0f 0e first) but a body conversion never produces the ROM's
   copy+in-place `adds r4, r0, #0 / lsls r4,r4,#24 / lsrs r4,r4,#24` -- it
   emits `lsls r0,r0,#24 / lsrs r4,r0,#24` (temp in r0, no copy). Only a
   parm conversion emits the in-place form. */
#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08012AF8(u8 a, u8 b);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_08012B50(s8 a, u8 b)
{
    u8 buf[0x200];
    s8 sel;
    sub_08011C9C(3, buf);
    sub_08012AF8(a, b);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08012AF8(a, b);
        if (gKeysPressed & 1)
            sel = a;
        sub_08000458();
    } while (sel == 0x40);
    sub_0800420C(0, 0x0F);
    return sel;
}
