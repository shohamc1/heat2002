#include "global.h"
#include "data.h"

/* Three full-screen data sets, each built from its editable
 * assets/graphics/screens/NAME.png: palette + 15x10 metatile map +
 * metatile tile-index table + 8bpp gfx, in the order their screens run:
 * credits page 2 (ShowCreditsPage2, 0x0831377C), credits page 3 (ShowCreditsPage3,
 * 0x08316B30), and the first boot splash (ShowBootSplash1, 0x08319EE4). */
const u8 gCreditsPage2Palette[] = INCBIN_U8("build/assets/graphics/screens/credits_page2.pal.bin");
const u16 gCreditsPage2MetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/credits_page2.map.bin");
const u16 gCreditsPage2MetatileTable[420] = INCBIN_U16("build/assets/graphics/screens/credits_page2.table.bin");
const u8 gCreditsPage2Gfx[] = INCBIN_U8("build/assets/graphics/screens/credits_page2.tiles.bin");
const u8 gCreditsPage3Palette[] = INCBIN_U8("build/assets/graphics/screens/credits_page3.pal.bin");
const u16 gCreditsPage3MetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/credits_page3.map.bin");
const u16 gCreditsPage3MetatileTable[420] = INCBIN_U16("build/assets/graphics/screens/credits_page3.table.bin");
const u8 gCreditsPage3Gfx[] = INCBIN_U8("build/assets/graphics/screens/credits_page3.tiles.bin");
const u8 gBootSplash1Palette[] = INCBIN_U8("build/assets/graphics/screens/boot_splash1.pal.bin");
const u16 gBootSplash1MetatileMap[150] = INCBIN_U16("build/assets/graphics/screens/boot_splash1.map.bin");
const u16 gBootSplash1MetatileTable[288] = INCBIN_U16("build/assets/graphics/screens/boot_splash1.table.bin");
const u8 gBootSplash1Gfx[] = INCBIN_U8("build/assets/graphics/screens/boot_splash1.tiles.bin");
