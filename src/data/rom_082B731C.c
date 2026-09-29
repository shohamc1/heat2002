#include "global.h"
#include "data.h"

/* Driver-select screen data (0x082B731C-0x082BA310), built from the
 * editable assets/graphics/screens/driver_select.png: 256-color palette,
 * 15x10 metatile map, metatile tile-index table, and the raw BG data
 * sub_0801037C copies to VRAM (the blob keeps the 32 bytes past the 64
 * tiles that the ROM holds between it and the driver car sprites). */
const u32 gDriverSelectPalette[] = INCBIN_U32("build/assets/graphics/screens/driver_select.pal.bin");
const u16 gDriverSelectMetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/driver_select.map.bin");
// Its users declare it as u16 x[][4] (21 rows of 4).
const u16 gDriverSelectMetatileTable[84] = INCBIN_U16("build/assets/graphics/screens/driver_select.table.bin");
const u32 gDriverSelectBgGfx[] = INCBIN_U32("build/assets/graphics/screens/driver_select.tiles.bin", "build/assets/unknown/data_082B86F0.bin");
const u8 gDriverSelectTiles[] = INCBIN_U8("build/assets/unknown/data_082B8710.bin");
