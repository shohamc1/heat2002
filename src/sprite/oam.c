#include "global.h"
#include "functions.h"
#include "gba/defines.h"
#include "variables.h"

void ResetSpriteQueues(void);

/* The file's RAM variables, one section per run it owns, each defined in
   address order. .bss_oam places ewram_data at 0x02024820: the depth-sorted
   sprite queue's cursor and count (gDepthSortedSpriteCursor,
   gDepthSortedSpriteCount; the queue is gDepthSortedSprites), the OAM entry
   queue's fill cursor gOamEntryQueueCursor and the anonymous 0x0202482C
   slot, the 0x400-byte OAM entry queue gOamEntryQueue itself
   (ClearOamBuffer fills its 0x80 8-byte entries, AddOamEntry appends
   through the cursor, and MainVBlankCallback copies all 0x100 words to
   OAM), and gSecondOamSortCursor, reset to gSecondOamSortBuffer
   (src/hud/globals.c). Only the 12 bytes 0x02024C34-0x02024C40 behind
   gSecondOamSortCursor stay unnamed, which no section pads over. .bss_oam_3
   places ewram_data3 at 0x0202E960 (gOamBuffer: the 0x400-byte OAM image
   plus 8 bytes of slack, which ClearOamBuffer and MainVBlankCallback DMA
   out and multiboot.c copies). */
EWRAM_DATA struct DepthSortedSprite *gDepthSortedSpriteCursor = 0;
EWRAM_DATA u8 gDepthSortedSpriteCount = 0;
static EWRAM_DATA u8 oam_gap4825[0x3] = {0};
EWRAM_DATA u32 *gOamEntryQueueCursor = 0;
static EWRAM_DATA u8 oam_gap482C[0x4] = {0};
EWRAM_DATA u32 gOamEntryQueue[0x100] = { 0 };
EWRAM_DATA u8 *gSecondOamSortCursor = 0;

EWRAM_DATA3 s16 gOamBuffer[0x204] = {0};

extern u8 gSecondOamSortBuffer[]; /* 0x02024F50, src/hud/globals.c */

void ResetSpriteQueues(void)
{
    gOamEntryQueueCursor = gOamEntryQueue;
    gSecondOamSortCursor = gSecondOamSortBuffer;
    gDepthSortedSpriteCursor = gDepthSortedSprites;
    gOamEntryCount = 0;
    gOamAffineCount = 0;
    gDepthSortedSpriteCount = 0;
}

void ClearOamBuffer(void)
{
    u32 i;
    u32 fill;
    u32 *entry;

    i = 0;
    fill = 0xAA;
    entry = gOamEntryQueue;
    while (i != 0x80) {
        *entry = fill;
        entry += 2;
        i++;
    }
    ResetSpriteQueues();
}

u32 AddOamEntry(u32 a, u32 b)
{
    u32 *p;

    if ((s8)gOamEntryCount < 0)
        return 0;
    p = gOamEntryQueueCursor;
    p[0] = a;
    p[1] = b;
    gOamEntryQueueCursor = p + 2;
    gOamEntryCount = gOamEntryCount + 1;
    return 1;
}

u32 AddDepthSortedSprite(u32 attr01, u32 attr2, u16 depth)
{
    struct DepthSortedSprite *entry = gDepthSortedSpriteCursor;
    u32 count;

    entry->attr01 = attr01;
    entry->attr2 = attr2;
    entry->depth = depth;
    gDepthSortedSpriteCursor = entry + 1;
    count = gDepthSortedSpriteCount + 1;
    gDepthSortedSpriteCount = count;
    return count;
}
