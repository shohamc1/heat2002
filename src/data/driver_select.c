#include "global.h"
#include "data.h"

/* Driver-select car sprites (0x082B8710-0x082BA310): 112 8bpp OBJ
 * tiles with the driver_car palette, which LinkDriverSelect copies
 * into VRAM (0x2000 bytes, running 1024 past the blob into the
 * following ROM data, as the original build did). Editable:
 * assets/graphics/tiles/driver_select_cars.png. */
const u8 gDriverSelectTiles[] = INCBIN_U8("build/assets/graphics/tiles/driver_select_cars.tiles.bin");
