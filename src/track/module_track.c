#include "global.h"
#include "functions.h"
#include "variables.h"

#define GBA_CPUSET sub_08344B64
#include "tilemap.h"
#include "gba/compat.h"
/* struct Track comes from include/structs.h via variables.h; it is the
   record type of gModule_TrackData, also from variables.h. */
extern u16 gUnk_02022428[];
extern u16 gUnk_02021394[];
extern u32 gUnk_02039288;
extern u32 gUnk_02039224;
extern u32 gUnk_020392A0;
extern u32 gUnk_02039280;
void ModuleLoadTrackTiles(u8 idx);
void ModuleBeginFadeToBrightenedPalette(s32 arg0, u16 *src);
void ModuleFlushTrackBgBuffers(void);
void ModuleSetCameraPos(u32 x, u32 y);
void sub_0834108C(u32 idx);
void sub_0833E078(void);
void sub_08344B60(u32 a, u32 b, u32 c);


void ModuleLoadTrackTiles(u8 idx)
{
    u32 off;
    u8 *base;
    u8 *p;

    base = (u8 *)gModule_TrackData;
    off = idx * 100;
    p = base + 4;
    sub_08344B64(*(u32 *)(p + off), 0x06000000, 0x4000);
    sub_08344B64(*(u32 *)(base + off), 0x06008000, 0x2000);
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
    CpuCopy16(gModule_TrackData[idx].unk18, (u32)fadePalette, 0x200);
    CpuCopy16(t = gUnk_02021394, (u32)paletteCopy, 0x20);
    ModuleBeginFadeToBrightenedPalette(0x1E, fadePalette);
    gUnk_02039244 = gModule_TrackData[idx].unk2C;
    gUnk_02039288 = gModule_TrackData[idx].unk34;
    gUnk_02039228 = gModule_TrackData[idx].unk20;
    gUnk_02039268 = gModule_TrackData[idx].unk24;
    gUnk_02039224 = gModule_TrackData[idx].unk28;
    gUnk_02039238 = gModule_TrackData[idx].unk0C;
    gUnk_0203922C = gModule_TrackData[idx].unk10;
    gUnk_020392A0 = gModule_TrackData[idx].unk3C;
    gUnk_02039280 = gModule_TrackData[idx].unk40;
    gUnk_0203929C = (u8 *)gModule_TrackData[idx].unk48;
    if (idx == 0)
        gModule_TrackMapWidth[0] = 0x7D;
    if (idx == 1)
        gModule_TrackMapWidth[0] = 0x70;
    if (idx == 2)
        gModule_TrackMapWidth[0] = 0xA8;
    if (idx == 3)
        gModule_TrackMapWidth[0] = 0x6B;
    if (idx == 4)
        gModule_TrackMapWidth[0] = 0xA3;
    if (idx == 5)
        gModule_TrackMapWidth[0] = 0xA6;
    if (idx == 6)
        gModule_TrackMapWidth[0] = 0x7D;
    if (idx == 8)
        gModule_TrackMapWidth[0] = 0x7D;
    if (idx == 9)
        gModule_TrackMapWidth[0] = 0x7D;
    if (idx == 10)
        gModule_TrackMapWidth[0] = 0x5E;
    if (idx == 11)
        gModule_TrackMapWidth[0] = 0x7D;
    ModuleDrawTrackMapWindow(0, 0, (u8 *)gUnk_02039228, (u32 *)TILEMAP_BUFFER(1), (u32 *)gUnk_02039238, gUnk_02039294);
    ModuleDrawTrackMapWindow(0, 0, (u8 *)gUnk_02039268, (u32 *)TILEMAP_BUFFER(2), (u32 *)gUnk_0203922C, gUnk_02039248);
    ModuleFlushTrackBgBuffers();
    ModuleSetCameraPos(0, 0);
    sub_0834108C(idx);
    sub_0833E05C();
    sub_0833E078();
    gModule_NumFinishedCars = 0;
}


void ModuleUpdateTrackScroll(void)
{
    s32 x;
    s32 y;

    x = gModule_Camera[6] - 0x78;
    y = gModule_Camera[7] - 0x50;
    gUnk_0203925C = x & 0xF;
    gUnk_02039260 = y & 0x1F;
    gUnk_020392A8 = x & 0xF;
    gUnk_02039240 = y & 0x1F;
    gUnk_02039290 = x & 0xF;
    gUnk_02039298 = y & 0x1F;
    gUnk_02039234[0] = x & 0x10;
    x = x >> 5;
    y = y >> 5;
    ModuleDrawTrackMapWindow(x, y, (*(u32 *)&gUnk_02039228), 0x03000000, (*(u32 *)&gUnk_02039238), gUnk_02039248);
    ModuleDrawTrackMapWindow(x, y, (*(u32 *)&gUnk_02039268), 0x03000800, (*(u32 *)&gUnk_0203922C), gUnk_020392A4);
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

    mapPtr = map + tileY * gUnk_02039244 + tileX;
    destPtr = dest;
    for (row = 0; row != 0x18; row += 4)
    {
        destRow2 = destPtr + 36;
        for (col = 0; col != 9; col++)
        {
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
        mapPtr += gUnk_02039244 - 9;
    }
}


void ModuleFlushTilemapBuffer(u32 src, u32 dest)
{
    u32 row;
    u32 srcPtr = src;
    u32 destPtr = dest;

    if (gUnk_02039234[0] != 0)
        srcPtr += 4;
    for (row = 0; row != TILEMAP_ROWS; row++) {
        sub_08344B60(srcPtr, destPtr, TILEMAP_DST_STRIDE / 4);
        srcPtr += TILEMAP_SRC_STRIDE;
        destPtr += TILEMAP_DST_STRIDE;
    }
}

