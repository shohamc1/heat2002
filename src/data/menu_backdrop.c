#include "global.h"
#include "data.h"

/* Screen data for the menu backdrop drawn by LoadMenuBackdrop
 * (0x082E4328-0x082EE104), built from the editable
 * assets/graphics/screens/menu_backdrop.png: the shared menu palette
 * (TrackSelectMenu.c and LinkDriverSelect.c load it through sub_0800F328),
 * then the identity metatile map + table, then the tiles. */
const u8 gMenuPalette[] = INCBIN_U8("build/assets/graphics/screens/menu_backdrop.pal.bin");
// Its users declare it as u8 x[].
const u16 gMenuBackdropMetatileMapAndTable[750] = INCBIN_U16("build/assets/graphics/screens/menu_backdrop.map.bin", "build/assets/graphics/screens/menu_backdrop.table.bin");
/* LoadMenuBackdrop copies 0xA280 bytes of tiles into VRAM -- the
 * picture's full capacity -- which on the GBA ran past the blob into the
 * following ROM data; hosted, the tail past the blob zero-fills so the
 * same copy stays defined. */
#if PORTABLE
const u8 gUnk_082E4B04[0xA280] = INCBIN_U8("build/assets/graphics/screens/menu_backdrop.tiles.bin");
#else
const u8 gUnk_082E4B04[] = INCBIN_U8("build/assets/graphics/screens/menu_backdrop.tiles.bin");
#endif
