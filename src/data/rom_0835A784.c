#include "global.h"
#include "font_text_tables.h"

/* no variables.h: it declares gUnk_02021D04 without const, which its
   readers' bytes need; this file needs nothing else from it. */

/* High module (link slave) font character map (ROM 0x0835A784-0x0835ACD4,
 * EWRAM 0x02021D04-0x02021F54), byte-identical to the main program's
 * gFontCharToGlyphTable (src/data/rom_08332BC8.c, which says what it is
 * for): the ROM holds it twice, once per GBA. font_text_tables.h shares
 * the initialisers, so one edit changes both copies. ModuleText indexes
 * it by the character less '!', then reads the glyph's tile entry from
 * gModule_FontTileEntries. */

const u16 gUnk_02021D04[] = FONT_CHAR_TO_GLYPH_TABLE;
