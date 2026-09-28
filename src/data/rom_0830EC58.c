#include "global.h"
#include "data.h"

/* 0x0830EC58-0x0830EE78: the silver trophy OBJ palette sub_08012C4C
 * requests for championship place 1, and the palette of the second boot
 * splash drawn by sub_08010334 (its gfx is the RLUnComp blob that follows). */
const u8 gSilverTrophyPalette[] = INCBIN_U8("build/assets/unknown/data_0830EC58.bin");
const u32 gBootSplash2Palette[] = INCBIN_U32("build/assets/unknown/data_0830EC78.bin");
