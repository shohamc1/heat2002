#include "global.h"
#include "gba/io_reg.h"
#include "car.h"

void sub_08342154(s32 *a, u16 keys)
{
    s32 t;
    u32 v;
    s32 x;

    ((u8 *)a)[0x84] = 1;
    if (a == (s32 *)gModule_Cars && a[0xB] > 0) {
        if (!(keys & (DPAD_RIGHT | DPAD_LEFT)))
            a[75] = (a[75] + ((u16 *)a)[0x1A]) / 2;
        if (keys & DPAD_LEFT)
            a[75] = ((u16 *)a)[0x1A] - 0x1400;
        if (keys & DPAD_RIGHT) {
            a[75] = ((u16 *)a)[0x1A] + 0x1400;
        }
        return;
    }
    if (keys & (DPAD_RIGHT | DPAD_LEFT)) {
        u8 cur = ((u8 *)a)[0x110];
        if ((s8)((u8 *)a)[0x110] >= 0)
            ((u8 *)a)[0x110] = cur + 1;
    } else {
        if (((u8 *)a)[0x110] != 0)
            ((u8 *)a)[0x110] = ((u8 *)a)[0x110] - 1;
    }
    v = ((u8 *)a)[0x110];
    t = (v * 3 >> 2) + 0x100;
    x = -(a[0xB]) >> 12;
    if (x < 0)
        x = 0;
    x = 0xFF - x;
    t += x * 2;
    if (keys & DPAD_LEFT) {
        a[75] -= t;
        ((u8 *)a)[0x84] = 0;
    } else if (keys & DPAD_RIGHT) {
        a[75] += t;
        ((u8 *)a)[0x84] = 2;
    }
}
