#include "global.h"
#include "data.h"

/* Multiboot-send OBJ palette. SendMultibootPayload (src/link/multiboot.c)
 * DMAs 0xA0 bytes from here to OBJ_PLTT: these 16 colours, then the
 * version string below as colours 0x10-0x4F. */
const u16 gMultibootSendObjPalette[] = INCBIN_U16("build/assets/graphics/palettes/multiboot_obj.pal.bin");

/* The SDK Sio32MultiLoad library's version string, zero-padded. The
 * island holds the same palette and string (gUnk_02000A9C). */
const char gSio32MultiLoadVersion[0xB8] = "Sio32MultiLoad010214";

/* A copy of Hooley Downs' track palette that no code reads. */
const u16 gUnusedHooleyDownsPalette[] = INCBIN_U16("build/assets/tracks/hooley_downs/palette.bin");
