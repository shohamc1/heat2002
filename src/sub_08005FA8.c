#include "global.h"
#include "variables.h"
#include "car.h"
#include "data.h"


void UpdateRaceTimers(void);
void DrawTime(u32 a, u16 b, u16 c, u16 d);
void sub_08005A2C(u32 a);
void sub_08005AF0(s32 a);
void DrawTireWear(void *a);
void sub_08005AA0(void *a);
void sub_08005AEC(void *a);
void sub_08004980(void *a);

void sub_08005FA8(void)
{
    u32 base;
    u32 obj;
    struct Car *car;
    s32 v;

    UpdateRaceTimers();
    base = gUnk_08364B08[0];
    obj = base + 0x448;
    DrawTime(obj, gUnk_02025218[0], gUnk_020251FC[0], gUnk_020253CC[0]);
    obj = base + 0x488;
    if (gUnk_0202F030 != 0)
        DrawTime(obj, gUnk_02025380[gTrackId], gUnk_02025200[gTrackId], gUnk_020253A0[gTrackId]);
    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId[0]];
    else
        car = gCars;
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    sub_08005A2C(v);
    sub_08005AF0(car->fuel << 8);
    DrawTireWear(car);
    sub_08005AA0(car);
    sub_08005AEC(car);
    sub_08004980(car);
}
