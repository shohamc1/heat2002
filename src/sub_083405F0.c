#include "global.h"
#include "functions.h"

struct Car {
    s32 unk00;                          /* 0x00 */
    u8 pad04[8];
    s32 unk0C;                          /* 0x0C */
    u8 pad10[4];
    s32 unk14;                          /* 0x14 */
    u8 pad18[0x2C - 0x18];
    s32 unk2C;                          /* 0x2C */
    u8 pad30[4];
    u16 unk34;                          /* 0x34 */
    u8 pad36[0x3C - 0x36];
    s16 unk3C;                          /* 0x3C */
    u8 pad3E[0x8C - 0x3E];
    s32 unk8C;                          /* 0x8C */
    s32 unk90;                          /* 0x90 */
    s32 unk94;                          /* 0x94 */
    s32 unk98;                          /* 0x98 */
    u8 pad9C[0x12C - 0x9C];
    s32 unk12C;                         /* 0x12C */
    u8 pad130[0x13C - 0x130];
    s32 unk13C;                         /* 0x13C */
    s32 unk140;                         /* 0x140 */
    s32 unk144;                         /* 0x144 */
    s32 unk148;                         /* 0x148 */
    s32 unk14C;                         /* 0x14C */
    u8 pad150[0x160 - 0x150];
    u16 unk160;                         /* 0x160 */
    u8 pad162[0x170 - 0x162];
    u8 unk170;                          /* 0x170 */
    u8 unk171;                          /* 0x171 */
    u8 pad172[0x190 - 0x172];
};

extern u8 gUnk_0203DD38;
extern struct Car gUnk_0203D520[];
extern u8 gUnk_020390EC;
extern u8 gUnk_0203D4E0;
extern u8 gUnk_0203DDFC;
extern u32 gUnk_0203D4DC;
extern u8 gUnk_0203DCF4;
extern u8 gUnk_0203DDE4;
extern s32 gUnk_0203DD4C;
extern s32 gUnk_0203DD0C;
extern s32 gUnk_0203D4E4;
extern s32 gUnk_0203DE04;
extern s32 gUnk_0203DCF8;
extern s32 gUnk_0203DE08;
extern s32 gUnk_0203DE0C;
extern s32 gUnk_0203D51C;
extern s32 gUnk_0203D4F4;
extern s32 gUnk_0203DDF4;
extern s32 gUnk_0203DD2C;
extern s32 gUnk_0203DE10;
extern s16 gUnk_0200C3E8[];


void sub_083405F0(struct Car *car, u8 b)
{
    s32 *caec, *cbe4;
    s32 t, spd, v1, v2;

    gUnk_0203DD38 = b;
    sub_08340530((u32)car, b);
    if (car == gUnk_0203D520
        && (car->unk8C > 0x7D000 || car->unk90 > 0x7D000
            || car->unk94 > 0x7D000 || car->unk98 > 0x7D000)) {
        gUnk_0203DD4C = 0x40;
        gUnk_0203DD0C = 0x80;
        gUnk_0203D4E4 = 0x11F40;
        caec = &gUnk_0203DD0C;
    } else {
        t = -car->unk2C >> 12;
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
    if (car == gUnk_0203D520 || gUnk_020390EC != 0) {
        if (car->unk170 != 0) {
            gUnk_0203DD4C >>= 1;
            *caec <<= 1;
            gUnk_0203D4E4 >>= 1;
        }
        if (car->unk171 != 0)
            *caec >>= 1;
    }
    gUnk_0203DE04 = ((car->unk34 >> 8) - 0x40) & 0xFF;
    gUnk_0203DCF8 = spd = car->unk3C << 7;
    gUnk_0203DE08 = (v1 = spd * -gUnk_0200C3E8[((car->unk34 >> 8) - 0x40) & 0xFF]) >> 8;
    gUnk_0203DE0C = (v2 = spd * gUnk_0200C3E8[(((car->unk34 >> 8) - 0x40) & 0xFF) + 0x40]) >> 8;
    if (car->unk160 != 0) {
        gUnk_0203D51C = car->unk0C + (v1 >> 9);
        gUnk_0203D4F4 = car->unk14 + (v2 >> 9);
    } else {
        gUnk_0203D51C = car->unk0C + (v1 >> 8);
        gUnk_0203D4F4 = car->unk14 + (v2 >> 8);
    }
    gUnk_0203DDF4 = *caec;
    gUnk_0203DD2C = gUnk_0203DE04;
    gUnk_0203DE10 = ((((car->unk12C >> 8) - 0x40) & 0xFF) >> 2) << 2;
    sub_08340964(0,(struct Unk08340964 *)car);
    if (car->unk160 != 0) {
        gUnk_0203D51C = car->unk0C - (gUnk_0203DE08 >> 1);
        gUnk_0203D4F4 = car->unk14 - (gUnk_0203DE0C >> 1);
    } else {
        gUnk_0203D51C = car->unk0C - gUnk_0203DE08;
        gUnk_0203D4F4 = car->unk14 - gUnk_0203DE0C;
    }
    gUnk_0203DDF4 = gUnk_0203DD4C;
    gUnk_0203DD2C = (*(cbe4 = &gUnk_0203DE04) + 0x80) & 0xFF;
    gUnk_0203DE10 = *cbe4 & 0xFF;
    sub_08340964(1,(struct Unk08340964 *)car);
    caec = &car->unk13C;
    if (*caec != 0) {
        car->unk140 += (*caec >> 8) * gUnk_0200C3E8[*cbe4 + 0x40];
        car->unk144 += (*caec >> 8) * gUnk_0200C3E8[*cbe4];
    }
    if (car->unk14C != 0) {
        car->unk140 -= ((car->unk14C >> 8) * gUnk_0200C3E8[*cbe4 + 0x40]) >> 4;
        car->unk144 -= ((car->unk14C >> 8) * gUnk_0200C3E8[*cbe4]) >> 4;
    }
}
