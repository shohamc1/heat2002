#include "global.h"
#include "data.h"

extern u8 gUnk_0202539C;

extern u8 gUnk_0806C6FC[];

extern void DrawTextCentered(u32 a, u32 b, u32 c);
extern u32 GetString(u32 a);

void sub_08004D1C(u8 arg)
{
    u8 r4 = arg;

    if (r4 != 3) {
        DrawTextCentered(GetString(0x66), 6, 1);
    } else {
        DrawTextCentered((u32)gUnk_0806C6FC, 6, 1);
    }
    if (r4 == 1 || (gUnk_0202539C & 8)) {
        DrawTextCentered(GetString(0x68), 8, 1);
    } else {
        DrawTextCentered((u32)gUnk_0806C6E8, 8, 1);
    }
    if (r4 == 0 || (gUnk_0202539C & 8)) {
        DrawTextCentered(GetString(0x67), 0xA, 1);
    } else {
        DrawTextCentered((u32)gUnk_0806C6E8, 0xA, 1);
    }
}
