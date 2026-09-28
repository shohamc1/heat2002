#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

extern u8 gText_ViewLicensingInfo[];
extern u8 gText_BlankRow12_4[];


void DrawOptionsMenu(u32 a)
{
    u8 *p;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x34);
    ((void (*)(void))DrawBigText)();

    DrawText(GetString(0x35), 3, 5, a == 0);

    DrawText(GetString(0x38), 3, 7, a == 1);

    DrawText(GetString(0x3A), 3, 9, a == 2);

    DrawText(GetString(0x3B), 3, 0xB, a == 3);

    DrawText(GetString(0xBF), 3, 0xD, a == 4);
    p = gText_ViewLicensingInfo;
    DrawText(p, 3, 0xF, a == 5);
    p = gText_BlankRow12_4;
    DrawText(p, 0x15, 5, a == 0);
    DrawText(GetString(gOptions[0] + 0x3D), 0x15, 5, a == 0);
    DrawText(GetString(gOptions[1] + 0xB6), 0x15, 7, a == 1);
    DrawText(GetString(gOptions[2] + 0x41), 0x15, 9, a == 2);
    DrawText(GetString(gOptions[3] + 0x41), 0x15, 0xB, a == 3);
    DrawText(GetString(gOptions[4] + 0x41), 0x15, 0xD, a == 4);
}
