#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

extern u8 gUnk_0829F354[];
extern u8 gUnk_0829F368[];


void DrawOptionsMenu(u32 a)
{
    u8 *p;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x34);
    ((void (*)(void))sub_080065A8)();

    DrawText((u8 *)(GetString(0x35)), 3, 5, a == 0);

    DrawText((u8 *)(GetString(0x38)), 3, 7, a == 1);

    DrawText((u8 *)(GetString(0x3A)), 3, 9, a == 2);

    DrawText((u8 *)(GetString(0x3B)), 3, 0xB, a == 3);

    DrawText((u8 *)(GetString(0xBF)), 3, 0xD, a == 4);
    p = gUnk_0829F354;
    DrawText(p, 3, 0xF, a == 5);
    p = gUnk_0829F368;
    DrawText(p, 0x15, 5, a == 0);
    DrawText((u8 *)(GetString(gOptions[0] + 0x3D)), 0x15, 5, a == 0);
    DrawText((u8 *)(GetString(gOptions[1] + 0xB6)), 0x15, 7, a == 1);
    DrawText((u8 *)(GetString(gOptions[2] + 0x41)), 0x15, 9, a == 2);
    DrawText((u8 *)(GetString(gOptions[3] + 0x41)), 0x15, 0xB, a == 3);
    DrawText((u8 *)(GetString(gOptions[4] + 0x41)), 0x15, 0xD, a == 4);
}
