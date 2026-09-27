#include "global.h"
#include "variables.h"

struct Unk08341DA0 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u16 unk34;
    u16 respawnHeading;
    u16 respawnWaypoint;
    u16 unk3A;
    s16 unk3C;
    u8 pad3E[0xA4 - 0x3E];
    s32 cornerX[4];
    s32 cornerZ[4];
    s32 nextCornerX[4];
    s32 nextCornerZ[4];
};

extern s32 gUnk_020277B4[]; /* 0x020277B4 */
extern s32 gUnk_020277C4[]; /* 0x020277C4 */

void sub_08341DA0(struct Unk08341DA0 *obj)
{
    s32 sin;
    s32 cos;
    s32 i;
    u32 idx;
    s32 a;
    s32 b;

    idx = obj->unk34 >> 8;
    sin = gModule_SinTable[idx];
    cos = gModule_SinTable[idx + 0x40];
    for (i = 0; i != 4; i++) {
        a = gUnk_020277B4[i];
        b = gUnk_020277C4[i];
        obj->cornerX[i] = (cos * a - sin * b) >> 8;
        obj->cornerZ[i] = (sin * a + cos * b) >> 8;
        obj->cornerX[i] += obj->unk0;
        obj->cornerZ[i] += obj->unk8;
    }

    idx = (obj->unk34 + obj->unk3C) >> 8 & 0xFF;
    sin = gModule_SinTable[idx];
    cos = gModule_SinTable[idx + 0x40];
    for (i = 0; i != 4; i++) {
        a = gUnk_020277B4[i];
        b = gUnk_020277C4[i];
        obj->nextCornerX[i] = (cos * a - sin * b) >> 8;
        obj->nextCornerZ[i] = (sin * a + cos * b) >> 8;
        obj->nextCornerX[i] += obj->unk0 + obj->unkC;
        obj->nextCornerZ[i] += obj->unk8 + obj->unk14;
    }
}
