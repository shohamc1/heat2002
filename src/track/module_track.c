/* Before the includes, so gba/compat.h takes the high module's copy. */
#define GBA_CPUSET sub_08344B64

#include "global.h"
#include "functions.h"
#include "variables.h"
#include "tilemap.h"
#include "gba/compat.h"

/* struct Track comes from include/structs.h via variables.h; it is the
   record type of gModule_TrackData, also from variables.h. */
extern u16 gUnk_02022428[];
extern u16 gModule_RaceHudBgPalette[];
extern u32 gModule_BgMapWidth2;
extern const u16 *gModule_TrackUnk28;
extern u32 gUnk_020392A0;
extern u32 gUnk_02039280;
void ModuleLoadTrackTiles(u8 idx);

void ModuleLoadTrackTiles(u8 idx)
{
    u32 off;
    u8 *base;
    u8 *p;

    base = (u8 *)gModule_TrackData;
    off = idx * 100;
    p = base + 4;
    CpuSet(*(u32 *)(p + off), VRAM, 0x4000);
    CpuSet(*(u32 *)(base + off), BG_CHAR_ADDR(2), 0x2000);
    gUnk_02039294 = 0;
    gUnk_02039248 = 0;
    gUnk_020392A4 = 0;
}

void ModuleLoadTrack(u32 idx)
{
    u16 fadePalette[0xE0];
    u16 paletteCopy[0x20];
    u16 *t;

    ModuleLoadTrackTiles(idx);
    t = gUnk_02022428;
    CpuCopy16(t, BG_SCREEN_ADDR(24), 0x2000);
    CpuCopy16(gModule_TrackData[idx].palette, fadePalette, 0x200);
    CpuCopy16(t = gModule_RaceHudBgPalette, paletteCopy, 0x20);
    ModuleBeginFadeToBrightenedPalette(0x1E, fadePalette);
    gModule_BgMapWidth = gModule_TrackData[idx].mapWidth;
    gModule_BgMapWidth2 = gModule_TrackData[idx].mapWidth2;
    gModule_Bg3MapPtr = gModule_TrackData[idx].bg3Map;
    gModule_Bg2MapPtr = gModule_TrackData[idx].bg2Map;
    gModule_TrackUnk28 = gModule_TrackData[idx].unk28;
    gModule_Bg3Metatiles = gModule_TrackData[idx].bg3Metatiles;
    gModule_Bg2Metatiles = gModule_TrackData[idx].bg2Metatiles;
    gUnk_020392A0 = gModule_TrackData[idx].unk3C;
    gUnk_02039280 = gModule_TrackData[idx].unk40;
    gModule_SurfaceTablePtr = gModule_TrackData[idx].surfaceTable;
    if (idx == 0)
        gModule_TrackMapWidth = 125;
    if (idx == 1)
        gModule_TrackMapWidth = 112;
    if (idx == 2)
        gModule_TrackMapWidth = 168;
    if (idx == 3)
        gModule_TrackMapWidth = 107;
    if (idx == 4)
        gModule_TrackMapWidth = 163;
    if (idx == 5)
        gModule_TrackMapWidth = 166;
    if (idx == 6)
        gModule_TrackMapWidth = 125;
    if (idx == 8)
        gModule_TrackMapWidth = 125;
    if (idx == 9)
        gModule_TrackMapWidth = 125;
    if (idx == 10)
        gModule_TrackMapWidth = 94;
    if (idx == 11)
        gModule_TrackMapWidth = 125;
    ModuleDrawTrackMapWindow(0, 0, (u8 *)gModule_Bg3MapPtr, (u32 *)TILEMAP_BUFFER(1), (u32 *)gModule_Bg3Metatiles,
                             gUnk_02039294);
    ModuleDrawTrackMapWindow(0, 0, (u8 *)gModule_Bg2MapPtr, (u32 *)TILEMAP_BUFFER(2), (u32 *)gModule_Bg2Metatiles,
                             gUnk_02039248);
    ModuleFlushTrackBgBuffers();
    ModuleSetCameraPos(0, 0);
    ModuleInitRaceCars(idx);
    ModuleResetLapTimer();
    ModuleResetRaceTimer();
    gModule_NumFinishedCars = 0;
}

void ModuleUpdateTrackScroll(u32 unused0, u32 unused1)
{
    s32 x;
    s32 y;

    x = gModule_Camera[6] - 0x78;
    y = gModule_Camera[7] - 0x50;
    gModule_Bg1ScrollX = x & 0xF;
    gModule_Bg1ScrollY = y & 0x1F;
    gModule_Bg2ScrollX = x & 0xF;
    gModule_Bg2ScrollY = y & 0x1F;
    gModule_Bg3ScrollX = x & 0xF;
    gModule_Bg3ScrollY = y & 0x1F;
    gModule_MapScrollHalfMetatile = x & 0x10;
    x = x >> 5;
    y = y >> 5;
    ModuleDrawTrackMapWindow(x, y, (u8 *)gModule_Bg3MapPtr, (u32 *)TILEMAP_BUFFER(0), (u32 *)gModule_Bg3Metatiles,
                             gUnk_02039248);
    ModuleDrawTrackMapWindow(x, y, (u8 *)gModule_Bg2MapPtr, (u32 *)TILEMAP_BUFFER(1), (u32 *)gModule_Bg2Metatiles,
                             gUnk_020392A4);
}

void ModuleDrawTrackMapWindow(u32 tileX, u32 tileY, u8 *map, u32 *dest, u32 *charBase, u16 unused)
{
    u8 *mapPtr;
    u32 *destPtr;
    u32 *destRow2;
    u32 *tileSrc;
    u32 row;
    u32 col;
    u32 tileIdx;

    mapPtr = map + tileY * gModule_BgMapWidth + tileX;
    destPtr = dest;
    for (row = 0; row != 24; row += 4) {
        destRow2 = destPtr + 36;
        for (col = 0; col != 9; col++) {
            tileIdx = *mapPtr++;
            tileSrc = &charBase[tileIdx * 8];
            destPtr[0] = *tileSrc++;
            destPtr[1] = *tileSrc++;
            destPtr[18] = *tileSrc++;
            destPtr[19] = *tileSrc++;
            destRow2[0] = *tileSrc++;
            destRow2[1] = *tileSrc++;
            destRow2[18] = *tileSrc++;
            destRow2[19] = *tileSrc;
            destRow2 += 2;
            destPtr += 2;
        }
        destPtr += 54;
        mapPtr += gModule_BgMapWidth - 9;
    }
}

void ModuleFlushTilemapBuffer(u8 *src, u8 *dest)
{
    u32 row;

    if (gModule_MapScrollHalfMetatile != 0)
        src += 4;
    for (row = 0; row != TILEMAP_ROWS; row++) {
        sub_08344B60(src, dest, TILEMAP_DST_STRIDE / 4);
        src += TILEMAP_SRC_STRIDE;
        dest += TILEMAP_DST_STRIDE;
    }
}
