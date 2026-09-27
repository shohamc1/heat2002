#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u32 gCarOrder[];
extern u32 gUnk_0202F020[];

void sub_08014C60(u8 a)
{
    u8 buf[0x28];
    u16 m, s, f;
    u32 *walk;
    u8 *ptr;
    u8 i;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x13);
    ((void (*)(void))sub_080065A8)();
    walk = (u32 *)((u8 *)gCarOrder + (u8)(a * 15) * 4);
    i = 0;
    do {
        DrawText(gUnk_0829F44C, 1, i + 4, 1);
        if (walk < gUnk_0202F020) {
            ptr = (u8 *)*walk;
            SplitMilliseconds(*(u32 *)(ptr + 0x16C), &m, &s, &f);
            if (ptr == (u8 *)gCars && (gUnk_0202539C & 0x10) != 0) {
                DrawText(gUnk_0829F44C, 1, i + 4, 1);
            } else {
                DrawText((u8 *)GetDriverName(ptr[0x162]), 1, i + 4, 1);
                buf[0] = (m / 10) % 10 + 0x30;
                buf[1] = m % 10 + 0x30;
                buf[2] = 0x3A;
                buf[3] = (s / 10) % 10 + 0x30;
                buf[4] = s % 10 + 0x30;
                buf[5] = 0x3A;
                buf[6] = (f / 100) % 10 + 0x30;
                buf[7] = (f / 10) % 10 + 0x30;
                buf[8] = 0;
                DrawText(buf, 0x14, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    if ((gUnk_0202539C & 8) != 0) {
        if (a == 0)
            DrawText(gUnk_0829F440, 0x1A, 0x13, 1);
        else
            DrawText(gUnk_0829F444, 0x1A, 0x13, 1);
    } else {
        DrawText(gUnk_0829F448, 0x1A, 0x13, 1);
    }
    gUnk_0202539C++;
}
