#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"


struct EntEFA0 {
    u8 f0;
    u8 f1;
    s8 f2;
    u8 f3;
};

/* gLinkPlayerSlots is u8[] in variables.h; the wrapper keeps the array
   subscript expansion for the order-sensitive uses below. */
struct EFA0s4 {
    struct EntEFA0 r[4];
};

extern u8 gText_EmptySlot[];


void sub_08012228(void)
{
    u8 unused[0x28];
    u8 i;
    u8 flag;
    s8 v;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(0xC4);
    ((void (*)(void))DrawBigText)();
    for (i = 0; i != 4; i++) {
        flag = ((struct EFA0s4 *)gLinkPlayerSlots)->r[i].f2 != -1;
        DrawText(GetString(i + 0x53), 1, 2 * i + 7, flag);
        v = ((struct EFA0s4 *)gLinkPlayerSlots)->r[i].f2;
        if (v == 0) {
            DrawText(GetString(0x58), 0x14, 2 * i + 7, flag);
        } else if (v == 1) {
            DrawText(GetString(0x57), 0x14, 2 * i + 7, flag);
        } else {
            DrawText(gText_EmptySlot, 0x14, 2 * i + 7, flag);
        }
    }
}
