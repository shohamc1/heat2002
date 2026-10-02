#include "global.h"
#include "gba/compat.h"
#include "variables.h"
#include "tilemap.h"
#include "functions.h"
#include "gba/defines.h"

/* struct Track and gTrackData come from include/structs.h via
   variables.h. */
/* Each case carries its own copy of the body so expand_case counts 12
   distinct labels and emits a jump table; cross-jumping then merges the
   twelve identical bodies, leaving every table entry at one address. */
extern u16 gRaceHudBgTiles[];
extern u16 gRaceHudBgPalette[];
void LoadTrackTiles(u8 idx);
void RleDecode16(u16 *src, u16 *dst, u16 count);

extern u16 gBg3MapBuffer[0x4D06];                 /* 0x02002220 */
extern u16 gBg2MapBuffer[0x4D06];                 /* 0x0200BC70 */
extern u32 gUnk_0201567C;                         /* 0x0201567C */
extern u16 gCellMapBuffer[0x6BA4];                /* 0x02015690 */
extern u32 gBgMapWidth2;                          /* 0x02022DD8 */
extern u32 gUnk_02022DF0;                         /* 0x02022DF0 */
extern u16 gUnk_02022DF4;                         /* 0x02022DF4 */

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
#if PORTABLE
    /* The CpuCopy16 below writes 0x200 bytes (the 256-colour palette)
       into a, 64 bytes past the GBA's 0xE0 halfwords; on the GBA the
       spill lands on b, which the next line overwrites with the HUD
       palette, and the fade then reads all 256 colours from a, so the
       HUD colours become BG bank 14. Rebuild that layout: one
       0x100-halfword array, with b its last 0x20. */
    u16 a[0x100];
    u16 *b = &a[0xE0];
#else
    u16 a[0xE0];
    u16 b[0x20];
#endif
    u16 *t;

    LoadTrackTiles(idx);
    t = gRaceHudBgTiles;
    CpuCopy16(t, BG_SCREEN_ADDR(24), 0x2000);
    CpuCopy16(gTrackData[idx].palette, a, 0x200);
    CpuCopy16(t = gRaceHudBgPalette, b, 0x20);
    BeginFadeToBrightenedPalette(0x1E, a);
    gBgMapWidth = gTrackData[idx].mapWidth;
    gBgMapWidth2 = gTrackData[idx].mapWidth2;
    gBg3MapPtr = (u8 *)gBg3MapBuffer;
    gBg2MapPtr = (u8 *)gBg2MapBuffer;
    RleDecode16(gTrackData[idx].bg3Map, gBg3MapBuffer, gTrackData[idx].bg3MapLen);
    RleDecode16(gTrackData[idx].bg2Map, gBg2MapBuffer, gTrackData[idx].bg2MapLen);
    gBg3Metatiles = (u8 *)gTrackData[idx].bg3Metatiles;
    gBg2Metatiles = (u8 *)gTrackData[idx].bg2Metatiles;
    gUnk_02022DF0 = gTrackData[idx].unk3C;
    gUnk_0201567C = gTrackData[idx].unk40;
    gCellMapPtr = (u8 *)gCellMapBuffer;
    RleDecode16(gTrackData[idx].cellMap, gCellMapBuffer, gTrackData[idx].cellMapLen);
    gSurfaceTablePtr = gTrackData[idx].surfaceTable;
    if (idx == 0)
        gTrackMapWidth = 125;
    if (idx == 1)
        gTrackMapWidth = 112;
    if (idx == 2)
        gTrackMapWidth = 168;
    if (idx == 3)
        gTrackMapWidth = 107;
    if (idx == 4)
        gTrackMapWidth = 163;
    if (idx == 5)
        gTrackMapWidth = 166;
    if (idx == 6)
        gTrackMapWidth = 125;
    if (idx == 8)
        gTrackMapWidth = 125;
    if (idx == 9)
        gTrackMapWidth = 125;
    if (idx == 10)
        gTrackMapWidth = 94;
    if (idx == 11)
        gTrackMapWidth = 125;
    DrawTrackMapWindow(0, 0, gBg3MapPtr, (u32 *)TILEMAP_BUFFER(0), gBg3Metatiles, gUnk_02022DE4);
    DrawTrackMapWindow(0, 0, gBg2MapPtr, (u32 *)TILEMAP_BUFFER(1), gBg2Metatiles, gUnk_0200BC34);
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
    gBg1ScrollX = x & 0x0F;
    gBg1ScrollY = y & 0x1F;
    gBg2ScrollX = x & 0x0F;
    gBg2ScrollY = y & 0x1F;
    gBg3ScrollX = x & 0x0F;
    gBg3ScrollY = y & 0x1F;
    gMapScrollHalfMetatile = x & 0x10;
    x >>= 5;
    y >>= 5;
    DrawTrackMapWindow(x, y, gBg3MapPtr, (u32 *)TILEMAP_BUFFER(0), gBg3Metatiles, gUnk_02022DE4);
    DrawTrackMapWindow(x, y, gBg2MapPtr, (u32 *)TILEMAP_BUFFER(1), gBg2Metatiles, gUnk_0200BC34);
}

void DrawTrackMapWindow(u32 tileX, u32 tileY, u8 *map, u32 *dest, u8 *charBase, u16 unused)
{
    u8 *mapPtr;
    u32 *destRow2;
    u32 *tileSrc;
    u32 tileIdx;
    u32 row;
    u32 col;

#if PORTABLE
    /* Negative projected columns are valid on the diagonal tracks.
       Combine the offsets before pointer addition, with GBA 32-bit wrap. */
    mapPtr = map + (s32)(tileY * gBgMapWidth * 2 + tileX * 2);
#else
    mapPtr = map + tileY * gBgMapWidth * 2 + tileX * 2;
#endif
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
