#include "global.h"

extern u8 gUnk_0202EDD8;
extern u32 gUnk_083FDD8C[];

extern u32 GetString(u16 idx);
extern void sub_080065A8(void);
extern void DrawText(u32 p, u32 a1, u32 a2, u8 a3);

void sub_080127E4(s8 a)
{
    GetString(0x14);
    sub_080065A8();
    if (a != 0) {
        DrawText(GetString(0x17), 0, 9, 1);
        DrawText(GetString(0x18), 0, 0xA, 1);
        DrawText(GetString(0x19), 0, 0xB, 1);
        DrawText(gUnk_083FDD8C[gUnk_0202EDD8], 0, 0xD, 1);
    } else {
        DrawText(GetString(0x15), 0, 0xD, 1);
        DrawText(GetString(0x16), 0, 0xE, 1);
    }
}
