#include "global.h"
#include "data.h"
#include "m4a.h"
#include "variables.h"

struct Unk080087F4 {
    u8 pad0[0x8C];
    s32 tireWear0;
    s32 tireWear1;
    s32 tireWear2;
    s32 tireWear3;
    u8 pad9C[0x140 - 0x9C];
    s32 forceX;
    s32 forceZ;
    s32 torque;
    u8 pad14C[0x180 - 0x14C];
    u8 torqueDampTimer;
};


void sub_0800B764(u8 a, u8 b);

void sub_080087F4(u8 which, struct Unk080087F4 *obj)
{
    s32 cos;
    s32 sin;
    s32 prod;
    s32 dist;
    s32 idx;
    register s32 m asm("r2");
    register s32 mm asm("r0");
    s32 ti;
    s32 t;
    s32 *pa;

    cos = gSinTable[((gTireForceAngle + 0x40) & 0xFF) + 0x40];
    sin = gSinTable[(gTireForceAngle + 0x40) & 0xFF];
    prod = cos * gTireContactVelX + sin * gTireContactVelZ;
    dist = prod >> 8;
    if (which != 0) {
        if (gDamagePitsEnabled != 0) {
            obj->tireWear0 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
            obj->tireWear1 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
        }
        if (dist < -gTireSlipLimit) {
            dist = -gTireSlipLimit / 2;
            sub_0800B764(gCurrentCarIndex, 2);
            if (gIsLinkRace == 0) {
                if (gCurrentCarIndex == 0)
                    goto e2check;
                goto tail;
            }
            if (gCurrentCarIndex != gLinkPlayerId[0])
                goto tail;
        } else if (dist > gTireSlipLimit) {
            dist = gTireSlipLimit / 2;
            sub_0800B764(gCurrentCarIndex, 3);
            if (gIsLinkRace == 0) {
                if (gCurrentCarIndex == 0)
                    goto e2check;
                goto tail;
            }
            if (gCurrentCarIndex != gLinkPlayerId[0])
                goto tail;
        } else {
            goto tail;
        }
e2check:
        if (gOptions[3] != 0 && gIsDemo == 0 && gRaceEndState == 0)
            m4aSongNumStart(0xB);
    } else {
        if (gDamagePitsEnabled != 0) {
            obj->tireWear2 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
            obj->tireWear3 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
        }
    }
tail:
    m = dist * gUnk_0202CBD4;
    m >>= 8;
    m = -m;
    pa = &obj->forceX;
    *pa += (m * cos) >> 8;
    pa = &obj->forceZ;
    *pa += (sin * m) >> 8;
    ti = gTireForceAngle;
    ti += 0x40;
    ti -= gUnk_0202CB0C;
    ti &= 0xFF;
    mm = gSinTable[ti] * m;
    m = mm >> 8;
    m <<= 7;
    t = m;
    if (m < 0)
        t = m + 0x7FFF;
    m = t >> 15;
    if (obj->torqueDampTimer != 0) {
        obj->torqueDampTimer--;
        obj->torque += t >> 16;
    } else {
        obj->torque += m;
    }
}
