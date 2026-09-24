#include "global.h"

extern u8 gUnk_020253C4;

extern u8 gUnk_0806C714[];
extern u8 gUnk_0806C720[];
extern u8 gUnk_0806C72C[];
extern u8 gUnk_0806C738[];

extern void DrawTextCentered(u32 a, u32 b, u32 c);
extern u32 GetString(u32 a);

void sub_080051E4(void)
{
    DrawTextCentered(GetString(0x96), 8, 1);
    switch (gUnk_020253C4) {
    case 0:
        DrawTextCentered((u32)gUnk_0806C714, 9, 1);
        break;
    case 1:
        DrawTextCentered((u32)gUnk_0806C720, 9, 1);
        break;
    case 2:
        DrawTextCentered((u32)gUnk_0806C72C, 9, 1);
        break;
    case 3:
        DrawTextCentered((u32)gUnk_0806C738, 9, 1);
        break;
    }
}
