#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

void EnterPit(u8 *a, u8 b);
u8 GetTrackTileType(s32 x, s32 y);

void sub_08007C44(struct Car *car)
{
    u8 pad[0x28];
    s32 p;
    s32 cx, cy;
    s32 a, b;
    s32 x, y;
    u8 v;
    u8 cnt;
    u8 f2;

    car->unk170 = 0;
    car->unk173 = car->unk171;
    car->unk171 = 0;
    car->unk172 = 0;
    if (gUnk_0200215C[0] == 4)
        return;
    if (gTrackId == 7)
        return;
    p = 0;
    if (gIsLinkRace != 0)
        p = gLinkPlayerId[0];
    a = car->posX;
    b = car->posZ;
    cx = a >> 19;
    cy = b >> 19;
    cy += 2;
    cx += 1;
    car->unk170 = 0;
    car->unk171 = 0;
    car->unk172 = 0;
    cnt = 0;
    for (y = cy - 1; y != cy + 2; y++) {
        for (x = cx - 1; x != cx + 2; x++) {
            v = GetTrackTileType(x, y);
            if (v & 1)
                car->unk172 = 1;
            if ((v == 2 || v == 3) && x == cx && y == cy)
                car->unk170 = 1;
            if ((v == 4 || v == 5) && x == cx && y == cy)
                car->unk171 = 1;
            if (v == 6)
                cnt++;
            if ((v == 8 || v == 9) && car->pitState == 6)
                car->unk182 = 0;
        }
    }
    if (cnt > 4 || (cnt != 0 && (gTrackId == 3 || gTrackId == 5
            || gTrackId == 8 || gTrackId == 0xB || gTrackId == 2))) {
        if (gIsLinkRace == 0 && car == gCars)
            EnterPit((u8 *)car, 0);
    }
    f2 = 0;
    if ((u8)(gUnk_0200215C[0] - 0xF) <= 1 && gUnk_0202ED70 == 0xC)
        f2 = 1;
    if (car == &gCars[p]) {
        if (car->unk171 != 0 && car->unk173 == 0 && f2 == 0 && gOptions[3] != 0
            && gIsDemo == 0 && gUnk_020021E0 == 0)
            m4aSongNumStart(0x1C);
    }
    if (car == &gCars[p]) {
        if (car->unk171 != 0 && (Random8() & 0x1F) == 0 && gOptions[3] != 0
            && gIsDemo == 0 && gUnk_020021E0 == 0 && f2 == 0)
            m4aSongNumStart(0x1D);
    }
    if (car == &gCars[p]) {
        if ((*(u32 *)&car->unk170 & 0xFF00FF00) == 0x01000000) {
            sub_080019B4((struct MusicPlayerInfo *)((s32)gUnk_02001FA0));
            sub_080019B4((struct MusicPlayerInfo *)((s32)gUnk_02002030));
            sub_080019B4((struct MusicPlayerInfo *)((s32)gUnk_02001FE0));
        }
    }
    if (gUnk_0200215C[0] == 0x10 && gUnk_0202ED70 == 0xC)
        car->unk171 = 0;
}
