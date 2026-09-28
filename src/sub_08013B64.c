#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u8 gText_BlankRow[];

void sub_08013B64(u8 a)
{
    u8 buf[0x28];
    u16 m, s, f;
    u8 i;
        u32 *walk;
        u8 *ptr;
        u8 off;

    off = a * 15;
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x31);
    ((void (*)(void))DrawBigText)();
    walk = (u32 *)((u8 *)gCarOrder + off * 4);
    i = 0;
    do {
        ptr = (u8 *)*walk;
        DrawText(gText_BlankRow, 0, i + 4, 1);
        if (walk < gSeasonRaceIndex) {
            SplitMilliseconds(*(u32 *)(ptr + 0x16C), &m, &s, &f);
            if (ptr != (u8 *)gCars || (gMenuBlinkCounter & 0x10) == 0) {
                buf[0] = ((i + off + 1) / 10) % 10 + 0x30;
                buf[1] = (i + off + 1) % 10 + 0x30;
                buf[2] = 0x2E;
                buf[3] = 0;
                DrawText(buf, 0, i + 4, 1);
                DrawText(GetDriverName(ptr[0x162]), 3, i + 4, 1);
                buf[0] = (m / 10) % 10 + 0x30;
                buf[1] = m % 10 + 0x30;
                buf[2] = 0x3A;
                buf[3] = (s / 10) % 10 + 0x30;
                buf[4] = s % 10 + 0x30;
                buf[5] = 0x3A;
                buf[6] = (f / 100) % 10 + 0x30;
                buf[7] = (f / 10) % 10 + 0x30;
                buf[8] = 0;
                DrawText(buf, 0x16, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    if ((gMenuBlinkCounter & 8) != 0) {
        if (a == 0)
            DrawText(gText_PageNextArrow, 0x1A, 0x13, 1);
        else
            DrawText(gText_PagePrevArrow, 0x1A, 0x13, 1);
    } else {
        DrawText(gText_PageNoArrowBlank, 0x1A, 0x13, 1);
    }
    gMenuBlinkCounter++;
}
