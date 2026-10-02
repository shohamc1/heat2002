#include "global.h"
#include "data.h"

/* Title screen (0x0829F954-0x082A9730), built from the editable
 * assets/graphics/screens/title_screen.png: 256-color palette, the 15x10
 * metatile map (150 u16 identity ramp), the shared 150x4 metatile
 * tile-index table, and 8bpp tiles. TitleScreen.c feeds the map and table
 * to DrawBackdropMetatileMap, and copies 0xA280 bytes of gfx into VRAM (the copy runs
 * past the gfx blob into the following ROM data, as the original build did). */
const u8 gTitleScreenPalette[] = INCBIN_U8("build/assets/graphics/screens/title_screen.pal.bin");
const u16 gTitleScreenMetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/title_screen.map.bin");

// Its users declare it as u16 x[][4] (150 rows of 4).
const u16 gSharedMetatileTileTable[600] = INCBIN_U16("build/assets/graphics/screens/title_screen.table.bin");

/* The 0xA280-byte VRAM copy runs past the gfx blob into the following
 * ROM data, as the original build did; hosted, the tail past the blob
 * zero-fills so the copy stays defined. */
#if PORTABLE
const u8 gTitleScreenGfx[0xA280] = INCBIN_U8("build/assets/graphics/screens/title_screen.tiles.bin");
#else
const u8 gTitleScreenGfx[] = INCBIN_U8("build/assets/graphics/screens/title_screen.tiles.bin");
#endif
