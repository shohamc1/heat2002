#include "global.h"
#include "data.h"

/* Shared menu palette (0x082E4328-0x082E4528), the palette of the menu
 * backdrop screen (assets/graphics/screens/menu_backdrop.png); e.g.
 * TrackSelectMenu.c and LinkDriverSelect.c load it through sub_0800F328. */
const u8 gMenuPalette[] = INCBIN_U8("build/assets/graphics/screens/menu_backdrop.pal.bin");
