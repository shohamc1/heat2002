#include "global.h"
#include "functions.h"

extern u16 gSharedMetatileTileTable[][4];
extern u16 gUnk_0600F800[];
#include "gba/defines.h"

void DrawBackdropMetatileMap(u16 *map)
{
    u16 *dest;
    u32 i;
    u32 j;
    u16 idx;
    u16 *entry;

    dest = gUnk_0600F800;
    i = 0;
    for (; i != 0xA; i++) {
        j = 0;
        for (; j != 0xF; j++) {
            idx = *map;
            map++;
            entry = gSharedMetatileTileTable[idx];
            dest[0] = *entry++;
            dest[1] = *entry++;
            dest[0x20] = entry[0];
            dest[0x21] = entry[1];
            dest += 2;
        }
        dest += 0x22;
    }
}

void DrawMetatileMap(u16 *map, u16 *table)
{
    u16 *dest;
    u16 *entry;
    u16 idx;
    u32 i;
    u32 j;

    dest = (u16 *)BG_SCREEN_ADDR(31);
    for (i = 0; i != 10; i++) {
        for (j = 0; j != 15; j++) {
            idx = *map++;
            entry = table + idx * 4;
            dest[0] = entry[0];
            entry++;
            dest[1] = entry[0];
            entry++;
            dest[32] = entry[0];
            dest[33] = entry[1];
            dest += 2;
        }
        dest += 0x22;
    }
}
