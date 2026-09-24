#include "global.h"
#include "data.h"

extern u8 gIsLinkRace;
extern u8 gUnk_020253C4;
extern u8 gUnk_0202539C;

extern u8 gUnk_0806C6B0[];
extern u8 gUnk_0806C6BC[];
extern u8 gUnk_0806C6C8[];
extern u8 gUnk_0806C6D4[];
extern u8 gUnk_0806C6E0[];

extern void DrawTextCentered(u32 a, u32 b, u32 c);
extern u32 GetString(u32 a);

void sub_08004C44(u8 arg)
{
    u8 r4 = arg;

    if (gIsLinkRace != 0) {
        switch (gUnk_020253C4) {
        case 0:
            DrawTextCentered((u32)gUnk_0806C6B0, 6, 1);
            break;
        case 1:
            DrawTextCentered((u32)gUnk_0806C6BC, 6, 1);
            break;
        case 2:
            DrawTextCentered((u32)gUnk_0806C6C8, 6, 1);
            break;
        case 3:
            DrawTextCentered((u32)gUnk_0806C6D4, 6, 1);
            break;
        }
    } else {
        DrawTextCentered((u32)gUnk_0806C6E0, 6, 1);
    }
    if (r4 == 1 || (gUnk_0202539C & 8)) {
        DrawTextCentered(GetString(0x81), 8, 1);
    } else {
        DrawTextCentered((u32)gUnk_0806C6E8, 8, 1);
    }
    if (r4 == 0 || (gUnk_0202539C & 8)) {
        DrawTextCentered(GetString(0x80), 0xA, 1);
    } else {
        DrawTextCentered((u32)gUnk_0806C6E8, 0xA, 1);
    }
}
