#include "global.h"
#include "data.h"

/* "Licensed By Nintendo" boot screen (0x082B731C-0x082B8710), built from
 * the editable assets/graphics/screens/licensed_by_nintendo.png:
 * 256-color palette, 15x10 metatile map, metatile tile-index table, and
 * the raw BG data (the blob keeps the 32 bytes past the 64 tiles that the
 * ROM holds before the driver-select font). The dead pair
 * sub_0801037C/sub_08010714 draws it: gfx and palette into VRAM, then the
 * map, then 180 frames and a fade. */
const u32 gLicensedByNintendoPalette[] = INCBIN_U32("build/assets/graphics/screens/licensed_by_nintendo.pal.bin");
const u16 gLicensedByNintendoMetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/licensed_by_nintendo.map.bin");
// Its users declare it as u16 x[][4] (21 rows of 4).
const u16 gLicensedByNintendoMetatileTable[] = INCBIN_U16("build/assets/graphics/screens/licensed_by_nintendo.table.bin");
const u32 gLicensedByNintendoBgGfx[] = INCBIN_U32("build/assets/graphics/screens/licensed_by_nintendo.tiles.bin", "build/assets/graphics/screens/licensed_by_nintendo.tail.bin");
