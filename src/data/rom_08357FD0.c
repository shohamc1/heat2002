#include "global.h"
#include "font_text_tables.h"

/* no variables.h: it declares gUnk_0201F590 without const, which its
   readers' bytes need; this file needs nothing else from it. */

/* High module (link slave) font and text character-code tables (ROM
 * 0x08357FD0-0x08358450, EWRAM 0x0201F550-0x0201F970), byte-identical to
 * the main program's gSpriteTextControlCharCodes and gTextCharMap
 * (src/data/rom_08332BC8.c, which says what each table is for): the ROM
 * holds them twice, one set per GBA. font_text_tables.h shares the
 * initialisers, so one edit changes both copies. ModuleDrawSpriteText
 * indexes gUnk_0201F550 by the raw character byte; sub_0833EE2C and
 * ModuleDrawTextHighlight index gUnk_0201F590 by the character less
 * 0x20, the same indexing as the low copy's gTextCharMap. */

const u16 gUnk_0201F550[] = SPRITE_TEXT_CONTROL_CHAR_CODES;
const u16 gUnk_0201F590[] = TEXT_CHAR_MAP;
