#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

struct Car137C {
    u8 pad[0x16C];
    u32 unk16C;
    u8 pad2[0x190 - 0x170];
};

extern struct Car137C gCars[];
extern struct Car137C *gCarOrder[];
extern u8 gUnk_0829F2F0[];


void sub_0801137C(void)
{
    u8 buf[0x28];
    u16 q1, q2, q3;
    struct Car137C **p;
    struct Car137C *car;
    u8 i;
    u16 tile;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x5B);
    ((void (*)(void))sub_080065A8)();
    p = gCarOrder;
    for (i = 0; i != gNumLinkPlayers[0]; i++) {
        car = *p;
        SplitMilliseconds(car->unk16C, &q1, &q2, &q3);
        if (car == &gCars[gLinkPlayerId[0]] && (gUnk_0202539C & 0x10)) {
            DrawText(gUnk_0829F2F0, 4, 2 * i + 4, 1);
        } else {
            DrawText((u8 *)(GetString(i + 0xC0)), 1, 2 * i + 4, 1);
            tile = 0x53 + (car - gCars);
            DrawText((u8 *)(GetString(tile)), 6, 2 * i + 4, 1);
            buf[0] = (u16)(q1 / 10) % 10 + 0x30;
            buf[1] = q1 % 10 + 0x30;
            buf[2] = 0x3A;
            buf[3] = (u16)(q2 / 10) % 10 + 0x30;
            buf[4] = q2 % 10 + 0x30;
            buf[5] = 0x3A;
            buf[6] = (u16)(q3 / 100) % 10 + 0x30;
            buf[7] = (u16)(q3 / 10) % 10 + 0x30;
            buf[8] = 0;
            DrawText(buf, 0x12, 2 * i + 4, 1);
        }
        p++;
    }
    gUnk_0202539C++;
}
