#include "global.h"
#include "data.h"

/* Results-screen data (0x082EE104-0x082F7EE0), built from the editable
 * assets/graphics/screens/results_screen.png: palette, identity metatile
 * map + table (LoadResultsScreenBackdrop), then the BG gfx copied to VRAM. */
const u8 gResultsScreenPalette[] = INCBIN_U8("build/assets/graphics/screens/results_screen.pal.bin");
// Its users declare it as u32 x[].
const u16 gResultsScreenMetatileMapAndTable[750] = INCBIN_U16("build/assets/graphics/screens/results_screen.map.bin", "build/assets/graphics/screens/results_screen.table.bin");
const u32 gUnk_082EE8E0[] = INCBIN_U32("build/assets/graphics/screens/results_screen.tiles.bin");

#if PORTABLE
const u32 gResultsScreenGfxSize = sizeof(gUnk_082EE8E0);
#endif
