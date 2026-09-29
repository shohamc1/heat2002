#include "global.h"
#include "data.h"

/* Driver-select car sprites (0x082B8710-0x082BA310): the OBJ tiles
 * LinkDriverSelect copies into VRAM (0x2000 bytes, running 1024 past the
 * 7168-byte blob into the following ROM data, as the original build did). */
const u8 gDriverSelectTiles[] = INCBIN_U8("build/assets/unknown/data_082B8710.bin");
