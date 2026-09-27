#include "global.h"
#include "variables.h"
#include "car.h"

extern u32 gUnk_08364B08[];

void UpdateRaceTimers(void);
void DrawTime(u16 *dest, s32 a, s32 b, s32 c);
void sub_08005A2C(u32 a1);
void DrawRacePosition(s32 arg);
void DrawLapCounter(s32 a, s32 b);
void sub_08005AF0(s32 arg);
void DrawTireWear(struct Car *p);
void sub_08005AA0(struct Car *p);
void sub_08005AEC(struct Car *p);
void sub_08004980(struct Car *p);

void UpdateRaceHud(void)
{
    struct Car *car;
    u16 *dest;
    s32 v;

    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId[0]];
    else
        car = &gCars[0];
    UpdateRaceTimers();
    dest = (u16 *)(gUnk_08364B08[0] + 0x4C6);
    DrawTime(dest, gUnk_02025218[0], gUnk_020251FC[0], gUnk_020253CC[0]);
    if (gUnk_0200215C[0] == 0x0E || gUnk_0200215C[0] == 0x02) {
        dest = (u16 *)(gUnk_08364B08[0] + 0x486);
        if (gUnk_0202F030 != 0)
            DrawTime(dest,
                         gUnk_02025380[gTrackId],
                         gUnk_02025200[gTrackId],
                         gUnk_020253A0[gTrackId]);
    }
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    sub_08005A2C(v);
    if (gUnk_0200215C[0] != 2 && gUnk_0200215C[0] != 0x0E) {
        DrawRacePosition(car->racePosition + 1);
        if (car->unk18E != 0 || (u8)(gUnk_0200215C[0] - 3) <= 1)
            DrawLapCounter((*(s8 *)&car->lap) + 1, gNumLaps);
        else
            DrawLapCounter(999, gNumLaps);
        sub_08005AF0((*(u32 *)&car->fuel) << 8);
        DrawTireWear(car);
        sub_08005AA0(car);
        sub_08005AEC(car);
    }
    sub_08004980(car);
}
