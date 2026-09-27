#include "global.h"
#include "data.h"
#include "functions.h"

struct Car {
    s32 posX;                          /* 0x00 */
    u8 pad04[8];
    s32 velX;                          /* 0x0C */
    u8 pad10[4];
    s32 velZ;                          /* 0x14 */
    u8 pad18[0x2C - 0x18];
    s32 speed;                          /* 0x2C */
    u8 pad30[4];
    u16 heading;                          /* 0x34 */
    u8 pad36[0x3C - 0x36];
    s16 yawRate;                          /* 0x3C */
    u8 pad3E[0x8C - 0x3E];
    s32 tireWear0;                          /* 0x8C */
    s32 tireWear1;                          /* 0x90 */
    s32 tireWear2;                          /* 0x94 */
    s32 tireWear3;                          /* 0x98 */
    u8 pad9C[0x12C - 0x9C];
    s32 unk12C;                         /* 0x12C */
    u8 pad130[0x13C - 0x130];
    s32 unk13C;                         /* 0x13C */
    s32 forceX;                         /* 0x140 */
    s32 forceZ;                         /* 0x144 */
    s32 torque;                         /* 0x148 */
    s32 drag;                         /* 0x14C */
    u8 pad150[0x160 - 0x150];
    u16 unk160;                         /* 0x160 */
    u8 pad162[0x170 - 0x162];
    u8 unk170;                          /* 0x170 */
    u8 unk171;                          /* 0x171 */
    u8 pad172[0x190 - 0x172];
};

extern u8 gUnk_0202CB18;
extern struct Car gCars[];
extern u8 gIsLinkRace;
extern u8 gUnk_0202A514;
extern u8 gUnk_0202CBDC;
extern u32 gUnk_0202A510;
extern u8 gUnk_0202CAD4;
extern u8 gUnk_0202CBC4;
extern s32 gUnk_0202CB2C;
extern s32 gUnk_0202CAEC;
extern s32 gUnk_0202A518;
extern s32 gUnk_0202CBE4;
extern s32 gUnk_0202CAD8;
extern s32 gUnk_0202CBE8;
extern s32 gUnk_0202CBEC;
extern s32 gUnk_0202A54C;
extern s32 gUnk_0202A528;
extern s32 gUnk_0202CBD4;
extern s32 gUnk_0202CB0C;
extern s32 gUnk_0202CBF0;


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
    gUnk_0202CAD8 = spd = car->yawRate << 7;
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
