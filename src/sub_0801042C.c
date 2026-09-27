#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

extern const u8 gUnk_082A0130[];
extern const u8 gUnk_0829FB54[];
extern const u8 gUnk_0829F954[];


u8 TitleScreen(void)
{
    u16 buf[0x100];
    s32 n;
    u16 i;
    u8 j;

    n = 0xBB8;
    if (gOptions[2] != 0)
        m4aSongNumStart(1);
    gUnk_020020B4 = 1;
    WaitForVBlank();
    REG_BG2CNT = BGCNT_PRIORITY(1) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_DISPCNT = 0xA8 << 3;
    CpuCopy16((u32)gUnk_082A0130, VRAM, 0xA280);
    CpuCopy16((u32)gUnk_0833338C, BG_SCREEN_ADDR(24), 0x2000);
    sub_08010680((u16 *)((u32)gUnk_0829FB54));
    i = 0;
    do {
        *(u16 *)(*(volatile u32 *)&gUnk_08364B08[0] + 2 * i) = 0;
        i++;
    } while (i != 0x380);
    CpuCopy16((u32)gUnk_0829F954, (u32)buf, 0x200);
    CpuCopy16((u32)gUnk_08332BC8, (u32)&buf[0xF0], 0x20);
    CpuCopy16((u32)gUnk_08332BC8, (u32)&buf[0xE0], 0x20);
    buf[0xEA] = RgbFromPercent(0x34, 0x34, 0x34);
    buf[0xEB] = RgbFromPercent(0x24, 0x24, 0x24);
    buf[0xEC] = RgbFromPercent(0x0E, 0x0E, 0x0E);
    buf[0xED] = RgbFromPercent(0, 0, 0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    j = 0;
    while (!(gKeysHeld & 8) && n != 0) {
        ReadKeys();
        i = 0;
        do {
            *(u16 *)(*(volatile u32 *)&gUnk_08364B08[0] + 2 * i) = 0;
            i++;
        } while (i != 0x380);
        if ((j & 0x1F) <= 0x0E)
            DrawTextCenteredHighlight((u8 *)(GetString(0x0F)), 0x10, 1);
        j++;
        if ((gKeysHeld & 8) && gOptions[3] != 0)
            m4aSongNumStart(9);
        WaitForVBlank();
        n--;
    }
    if (n == 0)
        m4aMPlayFadeOut(gUnk_02001F20, 2);
    FadeToColor(0, 0x0F);
    if (n == 0)
        return 1;
    return 0;
}
