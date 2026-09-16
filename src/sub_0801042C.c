#include "global.h"
#include "gba/compat.h"

extern u16 gKeysHeld;
extern u8 gUnk_02001F20[];
extern u8 gUnk_020020B4;
extern u8 gUnk_0202EF00[];
extern u16 *gUnk_08364B08;
extern void sub_08001208(u16 a);
extern void sub_08000458(void);
extern void sub_08010680(u32 a);
extern u16 sub_08011C44(u32 r, u32 g, u32 b);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern u32 sub_08016558(u16 idx);
extern void sub_08006950(u32 a, u32 b, u32 c);
extern void sub_080013A0(void *a, u32 b);
extern void sub_0800420C(u32 a, u32 b);

u8 sub_0801042C(void)
{
    u16 buf[0x100];
    s32 n;
    u16 i;
    u8 j;

    n = 0xBB8;
    if (gUnk_0202EF00[2] != 0)
        sub_08001208(1);
    gUnk_020020B4 = 1;
    sub_08000458();
    REG_BG2CNT = BGCNT_PRIORITY(1) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_DISPCNT = 0xA8 << 3;
    CpuCopy16(0x082A0130, VRAM, 0xA280);
    CpuCopy16(0x0833338C, BG_SCREEN_ADDR(24), 0x2000);
    sub_08010680(0x0829FB54);
    i = 0;
    do {
        gUnk_08364B08[i] = 0;
        i++;
    } while (i != 0x380);
    CpuCopy16(0x0829F954, (u32)buf, 0x200);
    CpuCopy16(0x08332BC8, (u32)&buf[0xF0], 0x20);
    CpuCopy16(0x08332BC8, (u32)&buf[0xE0], 0x20);
    buf[0xEA] = sub_08011C44(0x34, 0x34, 0x34);
    buf[0xEB] = sub_08011C44(0x24, 0x24, 0x24);
    buf[0xEC] = sub_08011C44(0x0E, 0x0E, 0x0E);
    buf[0xED] = sub_08011C44(0, 0, 0);
    sub_08004238(buf, 0x0F);
    j = 0;
    while (!(gKeysHeld & 8) && n != 0) {
        sub_0800048C();
        i = 0;
        do {
            gUnk_08364B08[i] = 0;
            i++;
        } while (i != 0x380);
        if ((j & 0x1F) <= 0x0E)
            sub_08006950(sub_08016558(0x0F), 0x10, 1);
        j++;
        if ((gKeysHeld & 8) && gUnk_0202EF00[3] != 0)
            sub_08001208(9);
        sub_08000458();
        n--;
    }
    if (n == 0)
        sub_080013A0(gUnk_02001F20, 2);
    sub_0800420C(0, 0x0F);
    if (n == 0)
        return 1;
    return 0;
}
