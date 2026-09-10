/* MISMATCH: the ROM saves r8 AND r9 (mov r7,r9; mov r6,r8; push {r6,r7})
   but only ever uses r8; that extra allocated register also shifts b/c/sel
   from our r6/r5/r7 to the ROM's r7/r6/r5. Ours needs one callee-saved
   register fewer. A fourth unused u32 parameter does not do it: assign_parms
   emits the copy but DCE deletes it before allocation, so regs_ever_live
   is never set. Same wall as sub_08013964's phantom r6. */
#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08012A4C(u32 a, u32 b, u32 c);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_08012A80(u32 a, u32 b, u32 c)
{
    u8 buf[0x200];
    s8 sel;
    sub_08011C9C(3, buf);
    sub_08012A4C(a, b, c);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08012A4C(a, b, c);
        if (gKeysPressed & 1)
            sel = 0;
        sub_08000458();
    } while (sel != 0);
    sub_0800420C(0, 0x0F);
    return sel;
}
