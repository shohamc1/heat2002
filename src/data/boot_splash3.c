#include "global.h"
#include "data.h"

/* Palette (256 colors) of the third boot splash drawn by ShowBootSplash3
 * (0x082B350C-0x082B370C); the screen's gfx is the RLUnComp blob that
 * follows. */
const u32 gBootSplash3Palette[] = INCBIN_U32("build/assets/unknown/data_082B350C.bin");
