#include "global.h"
#include "data.h"

/* Three full-screen data sets, each palette + 15x10 metatile map +
 * metatile tile-index table + 4bpp gfx, in the order their screens run:
 * credits page 2 (ShowCreditsPage2, 0x0831377C), credits page 3 (ShowCreditsPage3,
 * 0x08316B30), and the first boot splash (ShowBootSplash1, 0x08319EE4). */
const u8 gCreditsPage2Palette[] = INCBIN_U8("build/assets/unknown/data_0831377C.bin");
const u16 gCreditsPage2MetatileMap[150] = INCBIN_U16("build/assets/graphics/metatiles_0831397C.bin");
const u16 gCreditsPage2MetatileTable[420] = INCBIN_U16("build/assets/graphics/metatiles_08313AA8.bin");
const u8 gCreditsPage2Gfx[] = INCBIN_U8("build/assets/unknown/data_08313DF0.bin");
const u8 gCreditsPage3Palette[] = INCBIN_U8("build/assets/unknown/data_08316B30.bin");
const u16 gCreditsPage3MetatileMap[150] = INCBIN_U16("build/assets/graphics/metatiles_08316D30.bin");
const u16 gCreditsPage3MetatileTable[420] = INCBIN_U16("build/assets/graphics/metatiles_08316E5C.bin");
const u8 gCreditsPage3Gfx[] = INCBIN_U8("build/assets/unknown/data_083171A4.bin");
const u8 gBootSplash1Palette[] = INCBIN_U8("build/assets/unknown/data_08319EE4.bin");
const u16 gBootSplash1MetatileMap[150] = INCBIN_U16("build/assets/graphics/metatiles_0831A0E4.bin");
const u16 gBootSplash1MetatileTable[288] = INCBIN_U16("build/assets/graphics/metatiles_0831A210.bin");
const u8 gBootSplash1Gfx[] = INCBIN_U8("build/assets/unknown/data_0831A450.bin");
