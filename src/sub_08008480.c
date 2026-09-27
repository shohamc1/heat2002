#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern s32 gUnk_0202CB2C;
extern s32 gUnk_0202CAEC;
extern s32 gUnk_0202CBE4;
extern s32 gUnk_0202CAD8;
extern s32 gUnk_0202CBE8;
extern s32 gUnk_0202CBEC;


void sub_08008480(struct Car *car, u8 b)
{
    s32 *caec, *cbe4;
    s32 t, spd, v1, v2;

    gUnk_0202CB18 = b;
    sub_080083C0((u32)car, b);
    if (car == gCars
        && (car->tireWear0 > 0x7D000 || car->tireWear1 > 0x7D000
            || car->tireWear2 > 0x7D000 || car->tireWear3 > 0x7D000)) {
        gUnk_0202CB2C = 0x40;
        gUnk_0202CAEC = 0x80;
        gUnk_0202A518 = 0x11F40;
        caec = &gUnk_0202CAEC;
    } else {
        t = -car->speed >> 12;
        if (t < 0)
            t = 0;
        if (b != 0 && gIsLinkRace == 0) {
            gUnk_0202CB2C = gUnk_0202A514;
            gUnk_0202CAEC = gUnk_0202CBDC;
            gUnk_0202A518 = gUnk_0202A510;
            caec = &gUnk_0202CAEC;
        } else {
            gUnk_0202CB2C = (gUnk_0202CAD4 * (0xFF - t) + gUnk_0202A514 * t) >> 8;
            gUnk_0202CAEC = (gUnk_0202CBC4 * (0xFF - t) + gUnk_0202CBDC * t) >> 8;
            gUnk_0202A518 = gUnk_0202A510;
            caec = &gUnk_0202CAEC;
        }
    }
    if (car == gCars || gIsLinkRace != 0) {
        if (car->unk170 != 0) {
            gUnk_0202CB2C >>= 1;
            *caec <<= 1;
            gUnk_0202A518 >>= 1;
        }
        if (car->unk171 != 0)
            *caec >>= 1;
    }
    gUnk_0202CBE4 = ((car->heading >> 8) - 0x40) & 0xFF;
    gUnk_0202CAD8 = spd = (*(s16 *)&car->yawRate) << 7;
    gUnk_0202CBE8 = (v1 = spd * -gUnk_0801CD08[((car->heading >> 8) - 0x40) & 0xFF]) >> 8;
    gUnk_0202CBEC = (v2 = spd * gUnk_0801CD08[(((car->heading >> 8) - 0x40) & 0xFF) + 0x40]) >> 8;
    if (car->unk160 != 0) {
        gUnk_0202A54C = car->velX + (v1 >> 9);
        gUnk_0202A528 = car->velZ + (v2 >> 9);
    } else {
        gUnk_0202A54C = car->velX + (v1 >> 8);
        gUnk_0202A528 = car->velZ + (v2 >> 8);
    }
    gUnk_0202CBD4 = *caec;
    gUnk_0202CB0C = gUnk_0202CBE4;
    gUnk_0202CBF0 = ((((car->unk12C >> 8) - 0x40) & 0xFF) >> 2) << 2;
    sub_080087F4(0,(struct Unk080087F4 *)car);
    if (car->unk160 != 0) {
        gUnk_0202A54C = car->velX - (gUnk_0202CBE8 >> 1);
        gUnk_0202A528 = car->velZ - (gUnk_0202CBEC >> 1);
    } else {
        gUnk_0202A54C = car->velX - gUnk_0202CBE8;
        gUnk_0202A528 = car->velZ - gUnk_0202CBEC;
    }
    gUnk_0202CBD4 = gUnk_0202CB2C;
    gUnk_0202CB0C = (*(cbe4 = &gUnk_0202CBE4) + 0x80) & 0xFF;
    gUnk_0202CBF0 = *cbe4 & 0xFF;
    sub_080087F4(1,(struct Unk080087F4 *)car);
    caec = &car->unk13C;
    if (*caec != 0) {
        car->forceX += (*caec >> 8) * gUnk_0801CD08[*cbe4 + 0x40];
        car->forceZ += (*caec >> 8) * gUnk_0801CD08[*cbe4];
    }
    if (car->drag != 0) {
        car->forceX -= ((car->drag >> 8) * gUnk_0801CD08[*cbe4 + 0x40]) >> 4;
        car->forceZ -= ((car->drag >> 8) * gUnk_0801CD08[*cbe4]) >> 4;
    }
}
