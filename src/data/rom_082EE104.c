#include "global.h"
#include "data.h"

/* Results-screen data (0x082EE104-0x082F0000): palette, identity
 * metatile map + table (LoadResultsScreenBackdrop), then the BG gfx copied to VRAM. */
const u8 gResultsScreenPalette[] = INCBIN_U8("build/assets/unknown/data_082EE104.bin");
// Its users declare it as u32 x[].
const u16 gResultsScreenMetatileMapAndTable[750] = INCBIN_U16("build/assets/graphics/metatiles_082EE304.bin");
const u32 gUnk_082EE8E0[] = INCBIN_U32("build/assets/unknown/data_082EE8E0.bin");
