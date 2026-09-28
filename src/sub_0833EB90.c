#include "global.h"
#include "variables.h"
#include "car.h"


void sub_0833E1F4(void);
void sub_0833DDB8(u16 *dest, s32 a, s32 b, s32 c);
void sub_0833E528(u32 a1);
void sub_0833E714(s32 arg);
void sub_0833E7FC(s32 a, s32 b);
void sub_0833E5EC(s32 arg);
void sub_0833E94C(struct Car *p);
void sub_0833E59C(struct Car *p);
void sub_0833E5E8(struct Car *p);
void ModuleUpdateTrackCues(struct Car *p);

void sub_0833EB90(void)
{
    struct Car *car;
    u16 *dest;
    s32 v;

    if (gModule_IsLinkRace != 0)
        car = &gModule_Cars[gModule_LinkPlayerId];
    else
        car = &gModule_Cars[0];
    sub_0833E1F4();
    dest = (u16 *)(gModule_TextLayerMapPtr[0] + 0x4C6);
    sub_0833DDB8(dest, gModule_LapMin[0], gModule_LapSec[0], gModule_LapMs[0]);
    if (gModule_GameMode[0] == 0x0E || gModule_GameMode[0] == 0x02) {
        dest = (u16 *)(gModule_TextLayerMapPtr[0] + 0x486);
        if (gUnk_0203E1E0[0] != 0)
            sub_0833DDB8(dest,
                         gModule_TrackRecordMin[gModule_TrackId],
                         gModule_TrackRecordSec[gModule_TrackId],
                         gModule_TrackRecordMs[gModule_TrackId]);
    }
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    sub_0833E528(v);
    if (gModule_GameMode[0] != 2 && gModule_GameMode[0] != 0x0E) {
        sub_0833E714(car->racePosition + 1);
        if (car->lapStartedFlag != 0 || (u8)(gModule_GameMode[0] - 3) <= 1)
            sub_0833E7FC((*(s8 *)&car->lap) + 1, gUnk_02039194);
        else
            sub_0833E7FC(999, gUnk_02039194);
        sub_0833E5EC((*(u32 *)&car->fuel) << 8);
        sub_0833E94C(car);
        sub_0833E59C(car);
        sub_0833E5E8(car);
    }
    ModuleUpdateTrackCues(car);
}
