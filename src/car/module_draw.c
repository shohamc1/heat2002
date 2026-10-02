#include "global.h"
#include "variables.h"
#include "car.h"
#include "functions.h"

extern u32 *gModule_DriverCarSpriteHalfATables[];
extern u32 *gModule_DriverCarSpriteHalfBTables[];
extern u32 *gModule_DriverNumberFrameLists[];
extern u8 gModule_DriverNumberPalette[];

void ModuleDrawCar(struct Car *car, u8 idx)
{
    s32 pos[2];
    struct ObjTileCacheEntry *t;
    u32 t5;
    u16 y;
    u8 flip;
    s32 k;
    u32 *row;

    if (ModuleWorldToScreen(car->posX, car->posZ, pos) == 0)
        return;
    y = pos[1];
    pos[0] -= 24;
    pos[1] -= 16;
    if (car->finished != 0 && gModule_IsLinkRace != 0 && (gModule_FrameCounter & 8) != 0)
        return;
    k = (car->heading + 0x200) >> 10;
    k += 40;
    k &= 0x3F;
    flip = k & 0x20;
    k &= 0x1F;
    if (flip != 0)
        k = 0x20 - k;
    t5 = (u32)(ModuleRequestObjPalette(gModule_DriverPalettes[car->driverId]) << 24) >> 12;
    if (car->behindBgFlag != 0)
        t5 |= 0x800;
    else
        t5 |= 0x400;
    if (flip == 0) {
        t = ModuleRequestObjTiles8(gModule_DriverCarSpriteHalfATables[car->driverId][k]);
        if (t != NULL) {
            ModuleAddDepthSortedSprite((pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80008000, t->tileIndex | t5,
                                       y + 0x40);
        }
        t = ModuleRequestObjTiles16(gModule_DriverCarSpriteHalfBTables[car->driverId][k]);
        if (t != NULL) {
            ModuleAddDepthSortedSprite((pos[1] & 0xFF) | (((pos[0] + 0x10) & 0x1FF) << 16) | 0x80000000,
                                       t->tileIndex | t5, y + 0x40);
        }
    } else {
        u8 *p162;
        register u32 a PIN(r4);
        u32 b;
        u32 **tbl;

        tbl = gModule_DriverCarSpriteHalfBTables;
        p162 = &car->driverId;
        t = ModuleRequestObjTiles16(tbl[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80000000;
            b = t->tileIndex | t5;
            a |= 0x10000000;
            ModuleAddDepthSortedSprite(a, b, y + 64);
        }
        t = ModuleRequestObjTiles8(gModule_DriverCarSpriteHalfATables[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | (((pos[0] + 0x20) & 0x1FF) << 16) | 0x80008000;
            b = t->tileIndex | t5;
            a |= 0x10000000;
            ModuleAddDepthSortedSprite(a, b, y + 64);
        }
    }
    if (gModule_IsLinkRace != 0) {
        row = gModule_LinkMarkerFrameLists[idx];
        row += (gModule_FrameCounter >> 1) % 7;
        pos[1] -= 12;
        pos[0] += 16;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x40000000;
        t = ModuleRequestObjTiles4(*row);
        if (t == NULL)
            return;
        t5 = t->tileIndex | 0x400;
        t5 |= (u32)(ModuleRequestObjPalette(gModule_LinkMarkerPalette) << 24) >> 12;
        ModuleAddDepthSortedSprite(k, t5, y + 64);
    } else {
        row = gModule_DriverNumberFrameLists[car->driverId];
        pos[1] -= 8;
        pos[0] += 16;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x4000;
        t = ModuleRequestObjTiles2(*row);
        if (t == NULL)
            return;
        t5 = t->tileIndex | 0x400;
        t5 |= (u32)(ModuleRequestObjPalette(gModule_DriverNumberPalette) << 24) >> 12;
        ModuleAddDepthSortedSprite(k, t5, y + 64);
    }
}

void ModuleDrawAllCars(void)
{
    u32 i;
    u32 limit;
    struct Car *p;

    limit = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0)
        limit = gModule_NumLinkPlayers[0];
    p = gModule_Cars;
    for (i = 0; i != limit; i++, p++) {
        if (gModule_GameMode != 2 || i == 0)
            ModuleDrawCar(p, i);
    }
}
