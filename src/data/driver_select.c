#include "global.h"
#include "data.h"

/* Driver-select OBJ font (0x082B8710-0x082BA310): 224 4bpp tiles of
 * punctuation, digits, and plain and accented letters, which
 * LinkDriverSelect copies into OBJ VRAM at 0x06016000 (0x2000 bytes,
 * running 1024 past the blob into the following ROM data, as the
 * original build did). No OBJ on that screen uses tiles 0x300 and up,
 * so the game never shows it. Editable:
 * assets/graphics/tiles/driver_select_font.png. */
const u8 gDriverSelectTiles[] = INCBIN_U8("build/assets/graphics/tiles/driver_select_font.tiles.bin");
