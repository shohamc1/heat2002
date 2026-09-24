#include "global.h"

struct Car08005FA8 {
    u8 pad00[0x2C];
    s32 speed;
    u8 pad30[0x9C - 0x30];
    s32 fuel;
    u8 padA0[0x190 - 0xA0];
};

extern u32 gUnk_08364B08[];
extern u16 gUnk_02025218;
extern u16 gUnk_020251FC;
extern u16 gUnk_020253CC;
extern u8 gUnk_0202F030;
extern u16 gUnk_02025380[];
extern u8 gTrackId;
extern u16 gUnk_02025200[];
extern u16 gUnk_020253A0[];
extern u8 gIsLinkRace;
extern u8 gLinkPlayerId;
extern struct Car08005FA8 gCars[];

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
    struct Car08005FA8 *car;
    s32 v;

    UpdateRaceTimers();
    base = gUnk_08364B08[0];
    obj = base + 0x448;
    DrawTime(obj, gUnk_02025218, gUnk_020251FC, gUnk_020253CC);
    obj = base + 0x488;
    if (gUnk_0202F030 != 0)
        DrawTime(obj, gUnk_02025380[gTrackId], gUnk_02025200[gTrackId], gUnk_020253A0[gTrackId]);
    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId];
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
