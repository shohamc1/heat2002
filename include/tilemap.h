#ifndef GUARD_TILEMAP_H
#define GUARD_TILEMAP_H

#include "gba/defines.h"

// Two tilemap staging buffers at the base of IWRAM, one BG screen block
// apart, flushed row by row to BG screen blocks 29 and 30.
#define TILEMAP_BUFFER(n) (IWRAM_START + BG_SCREEN_SIZE * (n))

// A buffer row is wider than the screen so the flush can start at a
// horizontal scroll offset.
#define TILEMAP_SRC_STRIDE 0x48 // 36 entries
#define TILEMAP_DST_STRIDE 0x40 // 32 entries, one screen-block row
#define TILEMAP_ROWS       0x18

#endif // GUARD_TILEMAP_H
