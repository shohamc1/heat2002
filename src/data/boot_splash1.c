#include "global.h"
#include "data.h"

/* First boot splash (0x08319EE4-0x0831C850) drawn by ShowBootSplash1: the
 * copyright and trademark notice screen, built from the editable
 * assets/graphics/screens/boot_splash1.png: 256-color palette, 15x10
 * metatile map, 72-row metatile tile-index table, then 8bpp gfx. */
const u8 gBootSplash1Palette[] = INCBIN_U8("build/assets/graphics/screens/boot_splash1.pal.bin");
const u16 gBootSplash1MetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/boot_splash1.map.bin");
const u16 gBootSplash1MetatileTable[288] = INCBIN_U16("build/assets/graphics/screens/boot_splash1.table.bin");
const u8 gBootSplash1Gfx[] = INCBIN_U8("build/assets/graphics/screens/boot_splash1.tiles.bin");
