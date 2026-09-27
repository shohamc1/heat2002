#include "global.h"
#include "functions.h"
#include "car.h"

struct EntityBA38 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8 pad04[4];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x18 - 0x0C];
    /* 0x18 */ s32 unk18;
};

extern s32 gCamera[];        /* 0x02002100 */

u32 WorldToScreen(s32 x, s32 y, s32 *out);

void sub_0800BA38(struct EntityBA38 *e)
{
    struct Car *car;
    s32 pos[2];
    s32 x, y;
    s32 xlo, xhi, ylo, yhi;
    u8 i;

    if ((WorldToScreen(e->unk00, e->unk08, pos) << 0x18) != 0)
    {
        x = pos[0] - 0x78;
        x = x + gCamera[6];
        y = pos[1] - 0x50;
        y = y + gCamera[7];
        pos[0] = x << 0x10;
        pos[1] = y << 0x10;
    }
    xlo = e->unk00 + 0xFFF40000;
    xhi = e->unk00 + 0xC0000;
    ylo = e->unk08 + 0xFFF40000;
    yhi = e->unk08 + 0xC0000;
    car = gCars;
    i = 0;
    do {
        if (car->unk7C == 0)
        {
            if (car->posX > xlo && car->posX < xhi
                && car->posZ > ylo && car->posZ < yhi)
                car->unk160 = 0x32;
        }
        i++;
    } while (i != 8);
    e->unk18 = e->unk18 - 1;
    if (e->unk18 == 0)
    {
        RemoveTask((u32)e);
        FreeTask((u32)e);
    }
}
