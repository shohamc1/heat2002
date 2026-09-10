#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_020020DC;
extern u32 gUnk_083FDE18;
extern void sub_080019B4(u32 a);
extern void sub_080045D8(void);
extern void sub_08007344(void);
extern void sub_080073D8(void);
extern void sub_08004484(void);
extern void sub_080047DC(void);
extern void sub_08015304(void);
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08006734(u32 a);
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_08006950(u32 a, u32 b, u32 c);
extern void sub_08004238(void *a, u32 b);
extern void sub_08016E30(void);
extern void sub_0800048C(void);
extern void sub_0800420C(u32 a, u32 b);
void sub_080164A8(void)
{
    u8 buf[0x200];
    u16 keys;
    sub_080019B4(0x02001F60);
    sub_080019B4(0x02001F20);
    sub_080045D8();
    sub_08007344();
    sub_080073D8();
    sub_08004484();
    sub_080047DC();
    sub_08015304();
    gUnk_020020DC = 0;
    sub_08011C9C(1, buf);
    sub_08006734(gUnk_083FDE18);
    sub_08016558(0x75);
    sub_080065A8();
    sub_08006950(sub_08016558(0x75), 0x0A, 1);
    sub_08004238(buf, 0x0F);
    do {
        sub_08016E30();
        sub_0800048C();
        sub_08006950(sub_08016558(0x0F), 0x0F, 1);
    } while (!(*(u16 *)0x020005CC & 8));
    sub_0800420C(0, 0x0F);
}
