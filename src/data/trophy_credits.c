#include "global.h"
#include "data.h"

/* Championship podium screen and the credits pages
 * (0x08310140-0x08319EE4). DrawTrophyScreen loads the trophy OBJ palettes
 * by championship place (0 gold, 1 silver at gSilverTrophyPalette, 2
 * bronze); ShowCreditsPage1/2/3 draw the three pages, each built from its
 * editable assets/graphics/screens/credits_pageN.png: 256-color palette,
 * 15x10 metatile map, the metatile tile-index table (106 rows for page 1,
 * whose map's max index is 0x69; 105 for pages 2 and 3), then 8bpp gfx. */
const u8 gBronzeTrophyPalette[32] = INCBIN_U8("build/assets/graphics/palettes/bronze_trophy.pal.bin");
const u8 gGoldTrophyPalette[32] = INCBIN_U8("build/assets/graphics/palettes/gold_trophy.pal.bin");
const u8 gCreditsPage1Palette[512] = INCBIN_U8("build/assets/graphics/screens/credits_page1.pal.bin");

// Its users declare it as u8 x[].
const u16 gCreditsPage1MetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/credits_page1.map.bin");

// Its users declare it as u8 x[].
const u16 gCreditsPage1MetatileTable[] = INCBIN_U16("build/assets/graphics/screens/credits_page1.table.bin");

const u8 gCreditsPage1Gfx[] = INCBIN_U8("build/assets/graphics/screens/credits_page1.tiles.bin");
const u8 gCreditsPage2Palette[] = INCBIN_U8("build/assets/graphics/screens/credits_page2.pal.bin");
const u16 gCreditsPage2MetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/credits_page2.map.bin");
const u16 gCreditsPage2MetatileTable[] = INCBIN_U16("build/assets/graphics/screens/credits_page2.table.bin");
const u8 gCreditsPage2Gfx[] = INCBIN_U8("build/assets/graphics/screens/credits_page2.tiles.bin");
const u8 gCreditsPage3Palette[] = INCBIN_U8("build/assets/graphics/screens/credits_page3.pal.bin");
const u16 gCreditsPage3MetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/credits_page3.map.bin");
const u16 gCreditsPage3MetatileTable[] = INCBIN_U16("build/assets/graphics/screens/credits_page3.table.bin");
const u8 gCreditsPage3Gfx[] = INCBIN_U8("build/assets/graphics/screens/credits_page3.tiles.bin");
