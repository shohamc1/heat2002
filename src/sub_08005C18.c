#include "global.h"
extern u8 gUnk_0200215C;
extern u32 gUnk_08364B08[];
extern u8 gUnk_0806C76C[];
void sub_0800649C(u32,u32,u32);
void DrawBigDigit(u32,u8);
void DrawRacePosition(s32 arg)
{
    u16 *q;
    u16 *p;
    if (gUnk_0200215C == 0x0A || gUnk_0200215C == 0x02)
        return;
    if (arg == 0x64 || gUnk_0200215C == 5) {
        p = (u16 *)gUnk_08364B08[0];
        p[0x16] = 0xE047;
        p[0x17] = 0xE047;
        p[0x18] = 0xE047;
        p[0x19] = 0xE047;
        p[0x1A] = 0xE047;
        p[0x1B] = 0xE047;
        p[0x1C] = 0xE047;
        p[0x1D] = 0xE047;
        q = p + 0x36;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q = 0xE047;
        return;
    }
    sub_0800649C((u32)gUnk_0806C76C, 0x16, 0);
    if (arg <= 9) {
        register u16 *w asm("r0");
        p = (u16 *)gUnk_08364B08[0];
        p[0x1C] = 0xE047;
        p[0x1D] = 0xE047;
        w = p + 0x3C;
        *w++ = 0xE047;
        *w = 0xE047;
        w -= 0x23;
        DrawBigDigit((u32)w, (u8)arg);
    } else if (arg <= 0x13) {
        DrawBigDigit(gUnk_08364B08[0] + 0x34, 1);
        DrawBigDigit(gUnk_08364B08[0] + 0x38, (u8)(arg - 0x0A));
    } else {
        DrawBigDigit(gUnk_08364B08[0] + 0x34, 2);
        DrawBigDigit(gUnk_08364B08[0] + 0x38, (u8)(arg - 0x14));
    }
}
