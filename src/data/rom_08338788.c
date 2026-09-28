#include "global.h"
#include "data.h"

/* 0x08338788: 16-color OBJ palette for the HUD warning icons: the
 * speed needle (sub_08005A2C) and the low-fuel warning
 * (sub_08005AF0). */
const u8 gHudWarningIconPalette[] = INCBIN_U8("build/assets/unknown/data_08338788.bin");
