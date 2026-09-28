#include "global.h"
#include "data.h"

/* Multiboot-send OBJ palette (0x0807CB58-0x0807CE30). The first 0xA0
 * bytes are the palette SendMultibootPayload (src/link/multiboot.c)
 * DMAs to OBJ_PLTT; its colors 0x10-0x19 hold the ASCII string
 * "Sio32MultiLoad010214" instead of colors, so the blob stays binary.
 * Only the four colors at the start are nonzero; the tail past 0xA0
 * (zeros, then more color-like words) is read by no decompiled code. */
const u8 gMultibootSendObjPalette[] = INCBIN_U8("build/assets/unknown/data_0807CB58.bin");
