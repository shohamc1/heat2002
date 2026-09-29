#include "global.h"
#include "data.h"

/* Main-menu screen data (0x082A9730-0x082BA310): palette, then a
 * 150-entry identity metatile map followed by a 600-entry identity
 * metatile tile-index table (the same layout the title screen stores as
 * two blobs); sub_0800F434 passes the map half to DrawBackdropMetatileMap. */
const u8 gMainMenuPalette[] = INCBIN_U8("build/assets/unknown/data_082A9730.bin");
// Its users declare it as u8 x[].
const u16 gMainMenuMetatileMapAndTable[750] = INCBIN_U16("build/assets/graphics/metatiles_082A9930.bin");
const u8 gUnk_082A9F0C[] = INCBIN_U8("build/assets/unknown/data_082A9F0C.bin");
