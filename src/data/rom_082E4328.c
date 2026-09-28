#include "global.h"
#include "data.h"

/* Shared menu palette (0x082E4328-0x082E4528); e.g. TrackSelectMenu.c
 * and LinkDriverSelect.c load it through sub_0800F328. */
const u8 gMenuPalette[] = INCBIN_U8("build/assets/unknown/data_082E4328.bin");
