#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"


void sub_08014104(u8 a)
{
    u8 buf[0x28];
    u32 *walk;
    u8 *ptr;
    u16 *t;
    u8 off;
    u8 i;
    u8 z;
    u8 *p;

    off = a * 15;
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x32);
    ((void (*)(void))sub_080065A8)();
    walk = (u32 *)((u8 *)gCarOrder + off * 4);
    i = 0;
    p = buf;
    z = 0;
    do {
        DrawText(gUnk_0829F44C, 1, i + 4, 1);
        if (walk < gSeasonRaceIndex) {
            ptr = (u8 *)*walk;
            if (ptr == (u8 *)gCars && (gMenuBlinkCounter & 0x10) != 0) {
                DrawText(gText_BlankRowMenu, 1, i + 4, 1);
            } else {
                DrawText((u8 *)GetDriverName(ptr[0x162]), 1, i + 4, 1);
                t = (u16 *)(ptr + 0x164);
                p[0] = (*t / 1000) % 10 + 0x30;
                p[1] = (*t / 100) % 10 + 0x30;
                p[2] = (*t / 10) % 10 + 0x30;
                p[3] = *t % 10 + 0x30;
                p[4] = z;
                DrawText(buf, 0x1A, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    gMenuBlinkCounter++;
    if (gMenuBlinkCounter & 8) {
        if (a == 0)
            DrawText(gText_PageNextArrow, 0x1A, 0x13, 1);
        else
            DrawText(gText_PagePrevArrow, 0x1A, 0x13, 1);
    } else {
        DrawText(gText_PageNoArrowBlank, 0x1A, 0x13, 1);
    }
}
