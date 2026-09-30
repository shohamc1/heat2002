#include "global.h"
#include "font_text_tables.h"

/* no variables.h: it declares gModule_TextGlyphTileIndices,
   gModule_FontGlyphGrid, gModule_FontCharToGlyphTable and
   gModule_FontTileEntries without const, which their readers' bytes
   need; this file needs nothing else from it. */

/* High module (link slave) font block (ROM 0x08358450-0x0835AEA8, EWRAM
 * 0x0201F9D0-0x02022428), the twin of the main program's
 * gTextGlyphTileIndices to gFontTileEntries (src/data/rom_08332BC8.c,
 * which says what each is for): the ROM holds it twice, once per GBA.
 * The numeric tables build from font_text_tables.h and the tiles and
 * palette from the same files as the main program's, so one edit changes
 * both copies. The glyph grid's slices are aliased in symbols.ld, as the
 * main program's are. */

const u16 gModule_TextGlyphTileIndices[] = TEXT_GLYPH_TILE_INDICES;
const u32 gModule_TextLayerTiles[] = INCBIN_U32("build/assets/graphics/tiles/text_layer.tiles.bin");
const u16 gModule_RaceHudBgPalette[] = INCBIN_U16("build/assets/graphics/palettes/race_hud_bg.pal.bin");
const u16 gModule_FontGlyphGrid[] = FONT_GLYPH_GRID;
/* ModuleText indexes it by the character less '!', then reads the
 * glyph's tile entry from gModule_FontTileEntries. */
const u16 gModule_FontCharToGlyphTable[] = FONT_CHAR_TO_GLYPH_TABLE;
const u16 gModule_FontTileEntries[] = FONT_TILE_ENTRIES;
