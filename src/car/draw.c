#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern const GfxSrc *const gDriverCarSpriteHalfATables[];
extern const GfxSrc *const gDriverCarSpriteHalfBTables[];
extern const GfxSrc *const gDriverNumberFrameLists[];
extern u8 gDriverNumberPalette[];

void DrawCar(struct Car *car, u8 idx)
{
    s32 pos[2];
    struct ObjTileCacheEntry *t;
    u32 t5;
    u16 y;
    u8 flip;
    s32 k;
    const GfxSrc *row;

    if ((u8)WorldToScreen(car->posX, car->posZ, pos) == 0)
        return;
    y = pos[1];
    pos[0] -= 24;
    pos[1] -= 16;
    if (car->finished != 0 && gIsLinkRace != 0 && (gFrameCounter & 8) != 0)
        return;
    k = (car->heading + 0x200) >> 10;
    k += 40;
    k &= 0x3F;
    flip = k & 0x20;
    k &= 0x1F;
    if (flip != 0)
        k = 0x20 - k;
    t5 = (u32)(RequestObjPalette(gDriverPalettes[car->driverId]) << 24) >> 12;
    if (car->behindBgFlag != 0)
        t5 |= 0x800;
    else
        t5 |= 0x400;
    if (flip == 0) {
        t = RequestObjTiles8(gDriverCarSpriteHalfATables[car->driverId][k]);
        if (t != NULL) {
            AddDepthSortedSprite((pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80008000, t->tileIndex | t5, y + 64);
        }
        t = RequestObjTiles16(gDriverCarSpriteHalfBTables[car->driverId][k]);
        if (t != NULL) {
            AddDepthSortedSprite((pos[1] & 0xFF) | (((pos[0] + 0x10) & 0x1FF) << 16) | 0x80000000, t->tileIndex | t5,
                                 y + 0x40);
        }
    } else {
        u8 *p162;
        register u32 a PIN(r4);
        u32 b;
        const GfxSrc *const *tbl;

        tbl = gDriverCarSpriteHalfBTables;
        p162 = &car->driverId;
        t = RequestObjTiles16(tbl[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80000000;
            b = t->tileIndex | t5;
            a |= 0x10000000;
            AddDepthSortedSprite(a, b, y + 64);
        }
        t = RequestObjTiles8(gDriverCarSpriteHalfATables[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | (((pos[0] + 0x20) & 0x1FF) << 16) | 0x80008000;
            b = t->tileIndex | t5;
            a |= 0x10000000;
            AddDepthSortedSprite(a, b, y + 64);
        }
    }
    if (gIsLinkRace != 0) {
        row = gLinkMarkerFrameLists[idx];
        row += sub_080172C8(gFrameCounter >> 1, 7);
        pos[1] -= 12;
        pos[0] += 16;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x40000000;
        t = RequestObjTiles4(*row);
        if (t == NULL)
            return;
        t5 = t->tileIndex | 0x400;
        t5 |= (u32)(RequestObjPalette(gLinkMarkerPalette) << 24) >> 12;
        AddDepthSortedSprite(k, t5, y + 64);
    } else {
        row = gDriverNumberFrameLists[car->driverId];
        pos[1] -= 8;
        pos[0] += 16;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x4000;
        t = RequestObjTiles2(*row);
        if (t == NULL)
            return;
        t5 = t->tileIndex | 0x400;
        t5 |= (u32)(RequestObjPalette(gDriverNumberPalette) << 24) >> 12;
        AddDepthSortedSprite(k, t5, y + 64);
    }
}

void DrawAllCars(void)
{
    u8 n;
    u32 i;
    struct Car *p;

    n = gNumCars[0];
    if (gIsLinkRace != 0)
        n = gNumLinkPlayers[0];
    p = gCars;
    i = 0;
    while (i != n) {
        if (gGameMode != 2 || i == 0)
            DrawCar(p, i);
        i++;
        p++;
    }
}
