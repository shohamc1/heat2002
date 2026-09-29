#include "global.h"
#include "data.h"

/* Screen data for the menu backdrop drawn by LoadMenuBackdrop
 * (0x082E4528-0x082EE104), built from the editable
 * assets/graphics/screens/menu_backdrop.png: identity metatile map +
 * table, then tiles. */
// Its users declare it as u8 x[].
const u16 gMenuBackdropMetatileMapAndTable[750] = INCBIN_U16("build/assets/graphics/screens/menu_backdrop.map.bin", "build/assets/graphics/screens/menu_backdrop.table.bin");
const u8 gUnk_082E4B04[] = INCBIN_U8("build/assets/graphics/screens/menu_backdrop.tiles.bin");
