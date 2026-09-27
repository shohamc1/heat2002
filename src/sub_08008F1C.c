#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"
#include "car.h"

extern struct Car *gCarOrder[];
extern u32 gUnk_0202CB14;
extern u8 gUnk_083681B0[];
extern u32 *gUnk_083C9574[];
extern u32 *gUnk_083C97B4[];
extern s32 gUnk_08368170[];


/* InitCar: this file's old prototype takes a sixth argument the matched
   definition drops; call through a function pointer with the old signature. */
void InitRaceCars(u32 a1)
{
    u8 a;
    u32 eed0;
    u32 *p;
    struct Car **pp;
    u32 i;
    u32 off;
    struct Car *car;

    u32 d;
    register u32 sh asm("r1");
    register u32 v0 asm("r0");
    register u32 obj asm("r0");

    s16 out[4];
    register u32 garbage asm("r1");

    /* sub_08004944: this file's old prototype differs from the matched definition; call through the old one */
    ((void (*)(u32))sub_08004944)(a1);
    a = a1;
    BuildStartingGrid(a);
    gUnk_0202CAF0 = 0;
    eed0 = gUnk_0202EED0;
    sub_08008D70();
    if (gUnk_0200215C[0] == 0) {
        pp = gCarOrder;
        p = gUnk_0202A3F0;
        i = 0;
        do {
            ((void (*)(u8, u32, u32, u32, u32, u32))InitCar)(i, (u32)*pp, p[0] << 16, p[1] << 16, p[2] << 8,
                         *pp++ - gCars + eed0);
            p += 3;
            i++;
        } while (i != 0x18);
    } else {
        p = gUnk_0202A3F0;
        i = 0;
        off = 0;
        do {
            ((void (*)(u8, u32, u32, u32, u32, u32))InitCar)(i, off + (u32)gCars, p[0] << 16, p[1] << 16, p[2] << 8,
                         i + eed0);
            p += 3;
            off += 400;
            i++;
        } while (i != 0x18);
    }
    if (gUnk_0200215C[0] == 0x0E || gUnk_0200215C[0] == 0x09 || gUnk_0200215C[0] == 0x0D
        || gUnk_0200215C[0] == 0x11) {
        car = gCarOrder[0];
        d = *(u16 *)gUnk_083C9E74[gTrackId * 12 + 5] * gUnk_083681B0[gTrackId] / 100;
        sub_0800BD98(d, out, (u16 *)gUnk_083C9574[gTrackId * 12 + 5],
                     (void *)gUnk_083C97B4[gTrackId * 12 + 5]);
        v0 = *(s32 *)&out[0];
        sh = v0 << 16;
        car->posX = sh;
        car->posZ = *(s32 *)&out[2] << 16;
        car->velX = 0;
        car->velZ = 0;
        car->speed = 0;
        car->heading = 0;
        if (gTrackId == 1)
            sub_0800BEA4(gCarOrder, garbage, car->unk04, 0x46, 1);
        else
            sub_0800BEA4(gCarOrder, garbage, car->unk04, 0x64, 1);
    }
    if (gUnk_0200215C[0] == 0x0F) {
        car = gCarOrder[0];
        d = *(u16 *)gUnk_083C9E74[gTrackId * 12 + 5] * gUnk_08368170[gUnk_0202ED70] / 100;
        sub_0800BD98(d, out, (u16 *)gUnk_083C9574[gTrackId * 12 + 5],
                     (void *)gUnk_083C97B4[gTrackId * 12 + 5]);
        car->posX = *(s32 *)&out[0] << 16;
        car->posZ = *(s32 *)&out[2] << 16;
        car->velX = 0;
        car->velZ = 0;
        car->speed = 0;
        car->heading = 0;
        if (gUnk_0202ED70 == 6)
            goto l_inner;
        if (gUnk_0202ED70 == 0xA)
            goto l_inner;
        if (gUnk_0202ED70 == 0xB)
            goto l_inner;
        if (gUnk_0202ED70 == 0xC)
            goto l_50;
        if (gUnk_0202ED70 == 0xE)
            goto l_inner;
        if (gUnk_0202ED70 != 0xF)
            goto l_180;
l_inner:
        if (gUnk_0202ED70 == 0xC)
            goto l_50;
        if (gUnk_0202ED70 == 6) {
            obj = (u32)gCarOrder;
            sub_0800BEA4((struct Car **)obj, 0, 0, 0x28, 1);
            goto l_1d0;
        }
        if (gUnk_0202ED70 == 0xB)
            goto l_50;
        if (gUnk_0202ED70 != 0xE)
            goto l_16c;
l_50:
        obj = (u32)gCarOrder;
        sub_0800BEA4((struct Car **)obj, 0, 0, 0x50, 1);
        goto l_1d0;
l_16c:
        gCarOrder[0] = gCars;
        sub_0800BEA4(gCarOrder, 0, 0, 0x32, 0);
        goto l_1d0;
l_180:
        if (gUnk_0202ED70 == 3) {
            sub_0800BEA4(gCarOrder, 0, 0, 0x14, 1);
            goto l_1d0;
        }
        if (gUnk_0202ED70 == 0xD) {
            sub_0800BEA4(gCarOrder, 0, 0, 0x4B, 1);
            goto l_1d0;
        }
        if (gUnk_0202ED70 == 2) {
            sub_0800BEA4(gCarOrder, 0, 0, 0x32, 1);
            goto l_1d0;
        }
        sub_0800BEA4(gCarOrder, 0, 0, 0x32, 0);
l_1d0:
        gUnk_0202CAE8 = 0;
        gUnk_0202CB14 = 0;
        sub_08008D20();
    }
}
