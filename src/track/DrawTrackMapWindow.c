#include "global.h"
#include "gba/defines.h"
#include "variables.h"


void DrawTrackMapWindow(u32 tileX, u32 tileY, u8 *map, u32 *dest, u8 *charBase)
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
