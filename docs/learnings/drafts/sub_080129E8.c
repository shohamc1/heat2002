/* MISMATCH (new function, not previously attempted): instruction-for-
   instruction identical except the ROM pushes r7 and sets `movs r7, #0`
   (00 27) after narrowing the parameter, then never reads r7. That extra
   quantity also shifts the allocation: ROM sel=r5, arg=r6; ours arg=r5,
   sel=r6.
   Tried: dead `s8 v = 0;` (DCE removes it), `v = 0` with `sel = v` and
   `while (sel != v)` (v stays live in r8, +8 bytes), `v++` in the loop
   (removed), an unused second parameter assigned 0 (removed). A store that
   is never read does not survive old_agbcc's DCE by any shape tried. */
#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08012984(u8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_080129E8(u8 arg)
{
    u8 buf[0x200];
    s8 sel;
    sub_08011C9C(3, buf);
    sub_08012984(arg);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08012984(arg);
        if (gKeysPressed & 1)
            sel = 0;
        sub_08000458();
    } while (sel != 0);
    sub_0800420C(0, 0x0F);
    return sel;
}
