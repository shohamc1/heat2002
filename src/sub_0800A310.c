#include "global.h"
#include "data.h"

struct Unk0800A310 {
    u32 posX;
    u32 unk4;
    u32 posZ;
    u32 velX;
    u32 unk10;
    u32 velZ;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 speed;
    u32 unk30;
    u16 heading;
    u16 respawnHeading;
    u16 respawnWaypoint;
    u16 unk3A;
    s16 yawRate;
    u8 pad3E[0xA4 - 0x3E];
    s32 cornerX[4];
    s32 cornerZ[4];
    s32 nextCornerX[4];
    s32 nextCornerZ[4];
};

extern s32 gCornerOffsetX[]; /* 0x08368270 */
extern s32 gCornerOffsetZ[]; /* 0x08368280 */

void ComputeCarCorners(struct Unk0800A310 *obj)
{
    s32 sin;
    s32 cos;
    s32 i;
    u32 idx;
    s32 a;
    s32 b;

    idx = obj->heading >> 8;
    sin = gSinTable[idx];
    cos = gSinTable[idx + 0x40];
    for (i = 0; i != 4; i++) {
        a = gCornerOffsetX[i];
        b = gCornerOffsetZ[i];
        obj->cornerX[i] = (cos * a - sin * b) >> 8;
        obj->cornerZ[i] = (sin * a + cos * b) >> 8;
        obj->cornerX[i] += obj->posX;
        obj->cornerZ[i] += obj->posZ;
    }

    idx = (obj->heading + obj->yawRate) >> 8 & 0xFF;
    sin = gSinTable[idx];
    cos = gSinTable[idx + 0x40];
    for (i = 0; i != 4; i++) {
        a = gCornerOffsetX[i];
        b = gCornerOffsetZ[i];
        obj->nextCornerX[i] = (cos * a - sin * b) >> 8;
        obj->nextCornerZ[i] = (sin * a + cos * b) >> 8;
        obj->nextCornerX[i] += obj->posX + obj->velX;
        obj->nextCornerZ[i] += obj->posZ + obj->velZ;
    }
}
