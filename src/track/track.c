#include "global.h"
#include "gba/compat.h"
#include "variables.h"
#include "tilemap.h"
#include "functions.h"
#include "gba/defines.h"

extern u16 gUnk_02022DF4;
/* struct Track and gTrackData come from include/structs.h via
   variables.h. */
/* Each case carries its own copy of the body so expand_case counts 12
   distinct labels and emits a jump table; cross-jumping then merges the
   twelve identical bodies, leaving every table entry at one address. */
extern u16 gUnk_02002220[];
extern u16 gUnk_0200BC70[];
extern u16 gUnk_02015690[];
extern u32 gUnk_02022DD8;
extern u32 gUnk_02022DF0;
extern u32 gUnk_0201567C;
extern u16 gRaceHudBgTiles[];
extern u16 gRaceHudBgPalette[];
void LoadTrackTiles(u8 idx);
void RleDecode16(u16 *src, u16 *dst, u16 count);
void FlushTrackBgBuffers(void);
void SetCameraPos(u32 x, u32 y);
void InitRaceCars(u32 idx);
void ResetRaceTimer(void);

void RleDecode16(u16 *src, u16 *dst, u16 count)
{
    u16 t = 0xFFFF;
    u16 *s = src;
    u16 value = *s++;
    u16 i;
    u16 *out = dst;

    for (i = 1; i < count; i++) {
        *out++ = value;
        if (value == t) {
            u16 run = *s++;
            i++;
            while (run != 0) {
                *out++ = value;
                run--;
            }
        }
        t = value;
        value = *s++;
    }
}

void LoadTrackTiles(u8 idx)
{
    switch (idx) {
        case 0:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 1:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 2:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 3:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 4:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 5:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 6:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 7:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 8:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 9:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 10:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 11:
            CpuCopy16(gTrackData[idx].bg2Tiles, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].bg3Tiles, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
    }
}

void LoadTrack(u32 idx)
{
    u16 a[0xE0];
    u16 b[0x20];
    u16 *t;

    LoadTrackTiles(idx);
    t = gRaceHudBgTiles;
    CpuCopy16(t, BG_SCREEN_ADDR(24), 0x2000);
    CpuCopy16(gTrackData[idx].palette, (u32)a, 0x200);
    CpuCopy16(t = gRaceHudBgPalette, (u32)b, 0x20);
    BeginFadeToBrightenedPalette(0x1E, a);
    gBgMapWidth = gTrackData[idx].mapWidth;
    gUnk_02022DD8 = gTrackData[idx].mapWidth2;
    gUnk_02002208 = (u8 *)gUnk_02002220;
    gUnk_0200BC54 = (u8 *)gUnk_0200BC70;
    RleDecode16(gTrackData[idx].bg3Map, gUnk_02002220, gTrackData[idx].bg3MapLen);
    RleDecode16(gTrackData[idx].bg2Map, gUnk_0200BC70, gTrackData[idx].bg2MapLen);
    gUnk_0200221C = (u8 *)gTrackData[idx].bg3Metatiles;
    gUnk_02002210 = (u8 *)gTrackData[idx].bg2Metatiles;
    gUnk_02022DF0 = gTrackData[idx].unk3C;
    gUnk_0201567C = gTrackData[idx].unk40;
    gUnk_0200BC50[0] = (u32)gUnk_02015690;
    RleDecode16(gTrackData[idx].cellMap, gUnk_02015690, gTrackData[idx].cellMapLen);
    gUnk_02022DEC[0] = gTrackData[idx].surfaceTable;
    if (idx == 0)
        gTrackMapWidth[0] = 0x7D;
    if (idx == 1)
        gTrackMapWidth[0] = 0x70;
    if (idx == 2)
        gTrackMapWidth[0] = 0xA8;
    if (idx == 3)
        gTrackMapWidth[0] = 0x6B;
    if (idx == 4)
        gTrackMapWidth[0] = 0xA3;
    if (idx == 5)
        gTrackMapWidth[0] = 0xA6;
    if (idx == 6)
        gTrackMapWidth[0] = 0x7D;
    if (idx == 8)
        gTrackMapWidth[0] = 0x7D;
    if (idx == 9)
        gTrackMapWidth[0] = 0x7D;
    if (idx == 10)
        gTrackMapWidth[0] = 0x5E;
    if (idx == 11)
        gTrackMapWidth[0] = 0x7D;
    DrawTrackMapWindow(0, 0, gUnk_02002208, (u32 *)TILEMAP_BUFFER(0), gUnk_0200221C, gUnk_02022DE4);
    DrawTrackMapWindow(0, 0, gUnk_0200BC54, (u32 *)TILEMAP_BUFFER(1), gUnk_02002210, gUnk_0200BC34);
    FlushTrackBgBuffers();
    SetCameraPos(0, 0);
    InitRaceCars(idx);
    ResetLapTimer();
    ResetRaceTimer();
    gNumFinishedCars = 0;
}

void UpdateTrackScroll(u32 unused0, u32 unused1)
{
    s32 x;
    s32 y;

    x = gCamera[6] - 0x78;
    y = gCamera[7] - 0x50;
    gUnk_0200BC48 = x & 0x0F;
    gUnk_0200BC4C = y & 0x1F;
    gUnk_02022DF8 = x & 0x0F;
    gUnk_0200BC2C = y & 0x1F;
    gUnk_02022DE0 = x & 0x0F;
    gUnk_02022DE8 = y & 0x1F;
    gUnk_02002218 = x & 0x10;
    x >>= 5;
    y >>= 5;
    DrawTrackMapWindow(x, y, gUnk_02002208, (u32 *)TILEMAP_BUFFER(0), gUnk_0200221C, gUnk_02022DE4);
    DrawTrackMapWindow(x, y, gUnk_0200BC54, (u32 *)TILEMAP_BUFFER(1), gUnk_02002210, gUnk_0200BC34);
}

void DrawTrackMapWindow(u32 tileX, u32 tileY, u8 *map, u32 *dest, u8 *charBase, u16 unused)
{
    u8 *mapPtr;
    u32 *destRow2;
    u32 *tileSrc;
    u32 tileIdx;
    u32 row;
    u32 col;

    mapPtr = map + tileY * gBgMapWidth * 2 + tileX * 2;
    row = 0;
    do {
        destRow2 = dest + 0x24;
        col = 0;
        do {
            tileIdx = *(u16 *)mapPtr;
            mapPtr += 2;
            tileSrc = (u32 *)(charBase + tileIdx * TILE_SIZE_4BPP);
            dest[0] = *tileSrc++;
            dest[1] = *tileSrc++;
            dest[0x12] = *tileSrc++;
            dest[0x13] = *tileSrc++;
            destRow2[0] = *tileSrc++;
            destRow2[1] = *tileSrc++;
            destRow2[0x12] = *tileSrc++;
            destRow2[0x13] = *tileSrc;
            destRow2 += 2;
            dest += 2;
            col++;
        } while (col != 9);
        dest += 0x36;
        mapPtr += gBgMapWidth * 2 - 0x12;
        row += 4;
    } while (row != 24);
}
