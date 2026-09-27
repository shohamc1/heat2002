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

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x10);
    ((void (*)(void))sub_080065A8)();
    walk = gCarOrder;
    i = 0;
    pm = &m;
    ps = &s;
    pf = &f;
    do {
        ptr = (u8 *)*walk;
        SplitMilliseconds(*(u32 *)(ptr + 0x16C), pm, ps, pf);
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
            buf[6] = (*pf / 100) % 10 + 0x30;
            buf[7] = (*pf / 10) % 10 + 0x30;
            buf[8] = 0;
            DrawText(buf, 0x14, i + 4, 1);
        }
        walk++;
        i++;
    } while (i != 0x18);
    gUnk_0202539C++;
}
