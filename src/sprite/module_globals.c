#include "global.h"
#include "gba/defines.h"
#include "variables.h"

/* This file owns the high module's two sprite EWRAM runs (issue 5 step
   3, run rule): the OAM queue pointers at 0x0203ACD0 (src/sprite/
   module_oam.c's variables, the module twin of src/sprite/oam.c's own
   run, ending with the 0x400-byte OAM entry queue) and the sprite sort
   state at 0x0203B0E0-0x0203B6A8 (the OAM shadow cursor, the
   depth-sorted sprite queue, the second sort buffer, the queue-reset
   state and the 0x48-u16 order table that
   src/sprite/module_sprite_update.c sorts through).
   One struct DepthSortedSprite entry is 0xC bytes, 64 used of the
   0x41 defined. ldscript.ld's .module_ewram_data_sprite and
   .module_ewram_data_sprite_2 place the two sections. */

MODULE_EWRAM_DATA struct DepthSortedSprite *gModule_DepthSortedSpriteCursor = 0;
MODULE_EWRAM_DATA u8 gModule_DepthSortedSpriteCount = 0;
static MODULE_EWRAM_DATA u8 spr_gapACD5[0x3] = { 0 };
MODULE_EWRAM_DATA u32 *gModule_OamEntryQueueCursor = 0;
static MODULE_EWRAM_DATA u8 spr_gapACDC[0x4] = { 0 };
MODULE_EWRAM_DATA u32 gModule_OamEntryQueue[0x100] = { 0 };

MODULE_EWRAM_DATA2 u8 *gModule_SecondOamSortCursor = 0;
static MODULE_EWRAM_DATA2 u8 spr_gapB0E4[0xC] = { 0 };
MODULE_EWRAM_DATA2 struct DepthSortedSprite gModule_DepthSortedSprites[0x41] = { 0 };
static MODULE_EWRAM_DATA2 u8 spr_gapB3FC[0x4] = { 0 };
/* the module's second OAM sort buffer (0x200 bytes, at the address
   ModuleResetSpriteQueues stores in gModule_SecondOamSortCursor); unreferenced */
MODULE_EWRAM_DATA2 u8 gModule_SecondOamSortBuffer[0x200] = { 0 };
MODULE_EWRAM_DATA2 u8 gUnk_0203B600 = 0;
static MODULE_EWRAM_DATA2 u8 spr_gapB601[0x3] = { 0 };
MODULE_EWRAM_DATA2 u8 gUnk_0203B604 = 0;
static MODULE_EWRAM_DATA2 u8 spr_gapB605[0xB] = { 0 };
MODULE_EWRAM_DATA2 u16 gModule_SpriteOrderTable[0x48] = { 0 };
MODULE_EWRAM_DATA2 u16 gUnk_0203B6A0 = 0;
static MODULE_EWRAM_DATA2 u8 spr_gapB6A2[0x2] = { 0 };
MODULE_EWRAM_DATA2 u8 gUnk_0203B6A4 = 0;
static MODULE_EWRAM_DATA2 u8 spr_gapB6A5[0x3] = { 0 };
