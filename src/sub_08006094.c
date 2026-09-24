#include "global.h"

struct UnkCar6094 {
    /* 0x000 */ u8 filler00[0x2C];
    /* 0x02C */ s32 speed;
    /* 0x030 */ u8 filler30[0x4C - 0x30];
    /* 0x04C */ s8 lap;
    /* 0x04D */ u8 filler4D[0x9C - 0x4D];
    /* 0x09C */ u32 fuel;
    /* 0x0A0 */ u8 fillerA0[0x150 - 0x0A0];
    /* 0x150 */ u8 racePosition;
    /* 0x151 */ u8 filler151[0x18E - 0x151];
    /* 0x18E */ u8 unk18E;
    /* 0x18F */ u8 filler18F[400 - 0x18F];
};

extern u8 gIsLinkRace;
extern u8 gLinkPlayerId;
extern struct UnkCar6094 gCars[];
extern u32 gUnk_08364B08[];
extern u16 gUnk_02025218;
extern u16 gUnk_020251FC;
extern u16 gUnk_020253CC;
extern u8 gUnk_0200215C;
extern u8 gUnk_0202F030;
extern u16 gUnk_02025380[];
extern u8 gTrackId;
extern u16 gUnk_02025200[];
extern u16 gUnk_020253A0[];
extern u8 gNumLaps;

void UpdateRaceTimers(void);
void DrawTime(u16 *dest, s32 a, s32 b, s32 c);
void sub_08005A2C(u32 a1);
void DrawRacePosition(s32 arg);
void DrawLapCounter(s32 a, s32 b);
void sub_08005AF0(s32 arg);
void DrawTireWear(struct UnkCar6094 *p);
void sub_08005AA0(struct UnkCar6094 *p);
void sub_08005AEC(struct UnkCar6094 *p);
void sub_08004980(struct UnkCar6094 *p);

void UpdateRaceHud(void)
{
    struct UnkCar6094 *car;
    u16 *dest;
    s32 v;

    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId];
    else
        car = &gCars[0];
    UpdateRaceTimers();
    dest = (u16 *)(gUnk_08364B08[0] + 0x4C6);
    DrawTime(dest, gUnk_02025218, gUnk_020251FC, gUnk_020253CC);
    if (gUnk_0200215C == 0x0E || gUnk_0200215C == 0x02) {
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
    if (gUnk_0200215C != 2 && gUnk_0200215C != 0x0E) {
        DrawRacePosition(car->racePosition + 1);
        if (car->unk18E != 0 || (u8)(gUnk_0200215C - 3) <= 1)
            DrawLapCounter(car->lap + 1, gNumLaps);
        else
            DrawLapCounter(999, gNumLaps);
        sub_08005AF0(car->fuel << 8);
        DrawTireWear(car);
        sub_08005AA0(car);
        sub_08005AEC(car);
    }
    sub_08004980(car);
}
