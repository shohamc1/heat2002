#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"


void sub_080150F4(void)
{
    u8 buf[0x28];
    u16 m, s, f;
    u32 *walk;
    u8 *ptr;
    u16 *pm, *ps, *pf;
    u8 i;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x10);
    ((void (*)(void))DrawBigText)();
    walk = gCarOrder;
    i = 0;
    pm = &m;
    ps = &s;
    pf = &f;
    do {
        ptr = (u8 *)*walk;
        SplitMilliseconds(*(u32 *)(ptr + 0x16C), pm, ps, pf);
        if (ptr == (u8 *)gCars && (gMenuBlinkCounter & 0x10) != 0) {
            DrawText(gText_BlankRow36, 1, i + 4, 1);
        } else {
            DrawText(GetDriverName(ptr[0x162]), 1, i + 4, 1);
            buf[0] = (m / 10) % 10 + 0x30;
            buf[1] = m % 10 + 0x30;
            buf[2] = 0x3A;
            buf[3] = (s / 10) % 10 + 0x30;
            buf[4] = s % 10 + 0x30;
            buf[5] = 0x3A;
            buf[6] = (*pf / 100) % 10 + 0x30;
            buf[7] = (*pf / 10) % 10 + 0x30;
            buf[8] = 0;
            DrawText(buf, 0x14, i + 4, 1);
        }
        walk++;
        i++;
    } while (i != 0x18);
    gMenuBlinkCounter++;
}
