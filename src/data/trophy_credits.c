#include "global.h"
#include "data.h"

/* Championship podium screen and credits page 1 (0x08310140-0x0831377C).
 * DrawTrophyScreen loads the trophy OBJ palettes by championship place
 * (0 gold, 1 silver at gSilverTrophyPalette, 2 bronze); ShowCreditsPage1
 * draws credits page 1, built from the editable
 * assets/graphics/screens/credits_page1.png: 256-color palette, 15x10
 * metatile map, 106-row metatile tile-index table (the map's max index is
 * 0x69), then 8bpp gfx through the end of the range. */
const u8 gBronzeTrophyPalette[32] = INCBIN_U8("build/assets/unknown/data_08310140.bin");
const u8 gGoldTrophyPalette[32] = INCBIN_U8("build/assets/unknown/data_08310160.bin");
const u8 gCreditsPage1Palette[512] = INCBIN_U8("build/assets/graphics/screens/credits_page1.pal.bin");

// Its users declare it as u8 x[].
const u16 gCreditsPage1MetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/credits_page1.map.bin");

// Its users declare it as u8 x[].
const u16 gCreditsPage1MetatileTable[424] = INCBIN_U16("build/assets/graphics/screens/credits_page1.table.bin");

const u8 gCreditsPage1Gfx[12160] = INCBIN_U8("build/assets/graphics/screens/credits_page1.tiles.bin");
