#include "global.h"
#include "variables.h"
#include "car.h"

void sub_0833E1F4(void);
void sub_0833DDB8(u32 a, u16 b, u16 c, u16 d);
void sub_0833E528(u32 a);
void sub_0833E5EC(s32 a);
void sub_0833E94C(void *a);
void sub_0833E59C(void *a);
void sub_0833E5E8(void *a);
void sub_0833D9EC(void *a);

void sub_0833EAA4(void)
{
    u32 base;
    u32 obj;
    struct Car *car;
    s32 v;

    sub_0833E1F4();
    base = gModule_TextLayerMapPtr[0];
    obj = base + 0x448;
    sub_0833DDB8(obj, gModule_LapMin[0], gModule_LapSec[0], gModule_LapMs[0]);
    obj = base + 0x488;
    if (gUnk_0203E1E0[0] != 0)
        sub_0833DDB8(obj, gModule_TrackRecordMin[gModule_TrackId], gModule_TrackRecordSec[gModule_TrackId], gModule_TrackRecordMs[gModule_TrackId]);
    if (gModule_IsLinkRace != 0)
        car = &gModule_Cars[gModule_LinkPlayerId];
    else
        car = gModule_Cars;
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    sub_0833E528(v);
    sub_0833E5EC(car->fuel << 8);
    sub_0833E94C(car);
    sub_0833E59C(car);
    sub_0833E5E8(car);
    sub_0833D9EC(car);
}

void sub_0833EB8C(void)
{
}
