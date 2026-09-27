#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern s32 gUnk_0203DD4C;
extern s32 gUnk_0203DD0C;
extern s32 gUnk_0203DE04;
extern s32 gUnk_0203DCF8;
extern s32 gUnk_0203DE08;
extern s32 gUnk_0203DE0C;


void sub_083405F0(struct Car *car, u8 b)
{
    s32 *caec, *cbe4;
    s32 t, spd, v1, v2;

    gUnk_0203DD38 = b;
    sub_08340530((u32)car, b);
    if (car == gModule_Cars
        && (car->tireWear0 > 0x7D000 || car->tireWear1 > 0x7D000
            || car->tireWear2 > 0x7D000 || car->tireWear3 > 0x7D000)) {
        gUnk_0203DD4C = 0x40;
        gUnk_0203DD0C = 0x80;
        gUnk_0203D4E4 = 0x11F40;
        caec = &gUnk_0203DD0C;
    } else {
        t = -car->speed >> 12;
        if (t < 0)
            t = 0;
        if (b != 0 && gUnk_020390EC == 0) {
            gUnk_0203DD4C = gUnk_0203D4E0;
            gUnk_0203DD0C = gUnk_0203DDFC;
            gUnk_0203D4E4 = gUnk_0203D4DC;
            caec = &gUnk_0203DD0C;
        } else {
            gUnk_0203DD4C = (gUnk_0203DCF4 * (0xFF - t) + gUnk_0203D4E0 * t) >> 8;
            gUnk_0203DD0C = (gUnk_0203DDE4 * (0xFF - t) + gUnk_0203DDFC * t) >> 8;
            gUnk_0203D4E4 = gUnk_0203D4DC;
            caec = &gUnk_0203DD0C;
        }
    }
    if (car == gModule_Cars || gUnk_020390EC != 0) {
        if (car->unk170 != 0) {
            gUnk_0203DD4C >>= 1;
            *caec <<= 1;
            gUnk_0203D4E4 >>= 1;
        }
        if (car->unk171 != 0)
            *caec >>= 1;
    }
    gUnk_0203DE04 = ((car->heading >> 8) - 0x40) & 0xFF;
    gUnk_0203DCF8 = spd = (*(s16 *)&car->yawRate) << 7;
    gUnk_0203DE08 = (v1 = spd * -gUnk_0200C3E8[((car->heading >> 8) - 0x40) & 0xFF]) >> 8;
    gUnk_0203DE0C = (v2 = spd * gUnk_0200C3E8[(((car->heading >> 8) - 0x40) & 0xFF) + 0x40]) >> 8;
    if (car->unk160 != 0) {
        gUnk_0203D51C = car->velX + (v1 >> 9);
        gUnk_0203D4F4 = car->velZ + (v2 >> 9);
    } else {
        gUnk_0203D51C = car->velX + (v1 >> 8);
        gUnk_0203D4F4 = car->velZ + (v2 >> 8);
    }
    gUnk_0203DDF4 = *caec;
    gUnk_0203DD2C = gUnk_0203DE04;
    gUnk_0203DE10 = ((((car->unk12C >> 8) - 0x40) & 0xFF) >> 2) << 2;
    sub_08340964(0,(struct Unk08340964 *)car);
    if (car->unk160 != 0) {
        gUnk_0203D51C = car->velX - (gUnk_0203DE08 >> 1);
        gUnk_0203D4F4 = car->velZ - (gUnk_0203DE0C >> 1);
    } else {
        gUnk_0203D51C = car->velX - gUnk_0203DE08;
        gUnk_0203D4F4 = car->velZ - gUnk_0203DE0C;
    }
    gUnk_0203DDF4 = gUnk_0203DD4C;
    gUnk_0203DD2C = (*(cbe4 = &gUnk_0203DE04) + 0x80) & 0xFF;
    gUnk_0203DE10 = *cbe4 & 0xFF;
    sub_08340964(1,(struct Unk08340964 *)car);
    caec = &car->unk13C;
    if (*caec != 0) {
        car->forceX += (*caec >> 8) * gUnk_0200C3E8[*cbe4 + 0x40];
        car->forceZ += (*caec >> 8) * gUnk_0200C3E8[*cbe4];
    }
    if (car->drag != 0) {
        car->forceX -= ((car->drag >> 8) * gUnk_0200C3E8[*cbe4 + 0x40]) >> 4;
        car->forceZ -= ((car->drag >> 8) * gUnk_0200C3E8[*cbe4]) >> 4;
    }
}
