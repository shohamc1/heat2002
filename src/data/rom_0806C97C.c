#include "global.h"

// Atan2's lookup table (src/system/Atan2.c): 256x256 u8 angles, indexed
// [(y + 128) * 256 + 128 + x] with x and y scaled into -127..127, 256
// units per turn. Nothing but Atan2 reads it, and only by index, so the
// ROM gave no label to its tail half. scripts/gen_atan2.py regenerates
// every byte from atan2(x, y) * 128 / pi truncated toward zero, as a C
// cast does (assets/generated.json, type "gen").
const u8 gAtan2Table[256 * 256] =
    INCBIN_U8("build/assets/generated/atan2_table.bin");
