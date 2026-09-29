#include "global.h"
#include "data.h"

/* 16-color OBJ palette of the track-select cursor; DrawTrackSelect.c
 * copies it to OBJ_PLTT + 0x1E0 (0x0830E670-0x0830E690). */
const u8 gTrackSelectArrowPalette[] = INCBIN_U8("build/assets/graphics/palettes/track_select_arrow.pal.bin");
