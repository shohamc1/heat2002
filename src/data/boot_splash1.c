#include "global.h"
#include "data.h"

/* First boot splash (0x08319EE4-0x0831C850) drawn by ShowBootSplash1: the
 * copyright and trademark notice screen, built from the editable
 * assets/graphics/screens/boot_splash1.png: 256-color palette, 15x10
 * metatile map, 72-row metatile tile-index table, then 8bpp gfx. */
const u8 gBootSplash1Palette[] = INCBIN_U8("build/assets/graphics/screens/boot_splash1.pal.bin");
const u16 gBootSplash1MetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/boot_splash1.map.bin");
const u16 gBootSplash1MetatileTable[] = INCBIN_U16("build/assets/graphics/screens/boot_splash1.table.bin");
/* ShowBootSplash1 copies 0xA280 bytes of tiles into VRAM, past the blob
 * into the following ROM data as the original build did; hosted, the
 * tail past the blob zero-fills so the copy stays defined. */
#if PORTABLE
const u8 gBootSplash1Gfx[0xA280] = INCBIN_U8("build/assets/graphics/screens/boot_splash1.tiles.bin");
#else
const u8 gBootSplash1Gfx[] = INCBIN_U8("build/assets/graphics/screens/boot_splash1.tiles.bin");
#endif
