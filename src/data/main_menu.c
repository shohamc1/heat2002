#include "global.h"
#include "data.h"

/* Main-menu screen data (0x082A9730-0x082B350C), built from the editable
 * assets/graphics/screens/main_menu.png: palette, then a 150-entry identity
 * metatile map followed by a 600-entry identity metatile tile-index table
 * (the same layout the title screen stores as two blobs), then the tiles.
 * sub_0800F434 passes the map half to DrawBackdropMetatileMap. */
const u8 gMainMenuPalette[] = INCBIN_U8("build/assets/graphics/screens/main_menu.pal.bin");
// Its users declare it as u8 x[].
const u16 gMainMenuMetatileMapAndTable[750] = INCBIN_U16("build/assets/graphics/screens/main_menu.map.bin", "build/assets/graphics/screens/main_menu.table.bin");
/* LoadResultsBackdrop copies 0xA280 bytes of tiles into VRAM -- the
 * picture's full capacity -- which on the GBA ran past the blob into the
 * following ROM data; hosted, the tail past the blob zero-fills so the
 * same copy stays defined. */
#if PORTABLE
const u8 gUnk_082A9F0C[0xA280] = INCBIN_U8("build/assets/graphics/screens/main_menu.tiles.bin");
#else
const u8 gUnk_082A9F0C[] = INCBIN_U8("build/assets/graphics/screens/main_menu.tiles.bin");
#endif
