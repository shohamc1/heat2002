#include "global.h"
#include "data.h"

/* 0x08331FC8: race HUD OBJ tiles: eight 384-byte 4bpp blocks
 * InitRaceHud copies into OBJ VRAM. Graphics, kept as INCBIN. */
const u8 gRaceHudObjTiles[] = INCBIN_U8("build/assets/unknown/data_08331FC8.bin");
