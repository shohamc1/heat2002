#include "global.h"
#include "data.h"
#include "font_text_tables.h"

/* Font and text system, 0x08332BC8-0x083378A0: the text palette,
 * the character-code tables the renderers look glyphs up through,
 * the 4bpp glyph tiles, and the two graphics blobs LoadTrack copies
 * (a 256-color BG palette and a BG tilemap). Every table up to
 * gFontTileEntries has a byte-identical copy in the high module
 * (src/data/rom_08357FD0.c and rom_08358450.c): the numeric ones share
 * their initialisers through font_text_tables.h, and the tiles and
 * palette are the same build files, so one edit changes both GBAs. */

const u8 gFontPalette[] = INCBIN_U8("build/assets/graphics/palettes/font.pal.bin");
/* Control-character pad in front of gTextCharMap: DrawSpriteText
 * indexes this table by the raw character byte, so printable
 * characters run on into gTextCharMap below; 0x3E0 (992) is a
 * deliberately out-of-range glyph code. */
const u16 gSpriteTextControlCharCodes[] = SPRITE_TEXT_CONTROL_CHAR_CODES;
/* Maps an ASCII character (less 0x20, 544 entries) to one of the
 * 194 glyph codes; 0 is the space glyph. */
const u16 gTextCharMap[] = TEXT_CHAR_MAP;
/* Maps a glyph code to the 4bpp tile index inside gTextLayerTiles. */
const u16 gTextGlyphTileIndices[] = TEXT_GLYPH_TILE_INDICES;
/* The screen loaders copy 0x2000 bytes of this into BG screen block 24,
 * past the blob into the following ROM data as the original build did;
 * hosted, the tail past the blob zero-fills so the copy stays defined. */
#if PORTABLE
const u32 gTextLayerTiles[0x800] = INCBIN_U32("build/assets/graphics/tiles/text_layer.tiles.bin");
#else
// Its users declare it as u32 x[], u8 x[].
const u32 gTextLayerTiles[] = INCBIN_U32("build/assets/graphics/tiles/text_layer.tiles.bin");
#endif
/* Full 256-color BG palette of the race HUD's char sheet (below);
 * LoadTrack copies only its first 16 colors into a scratch buffer.
 * Editable: assets/graphics/palettes/race_hud_bg.pal. */
const u16 gRaceHudBgPalette[] = INCBIN_U16("build/assets/graphics/palettes/race_hud_bg.pal.bin");
// Its users declare it as u16 x[], u8 x[].
/* HUD label layout grid: byte offsets into this table give the
 * gFontTileEntries index of each fixed label cell. */
const u16 gFontGlyphGrid[] = FONT_GLYPH_GRID;
/* Maps a printable ASCII character (less '!', 680 entries) to its
 * gFontTileEntries index. */
const u16 gFontCharToGlyphTable[] = FONT_CHAR_TO_GLYPH_TABLE;
/* Text-layer tile-map entries (tile index plus flip bits) for the digit
 * and HUD glyph cells; the renderers OR these into the text layer map. */
const u16 gFontTileEntries[] = FONT_TILE_ENTRIES;
/* The race HUD's BG0 character sheet: 226 4bpp tiles (the glyph and
 * icon tiles gFontTileEntries indexes), copied to 0x0600C000 by
 * LoadTrack; the 0x2000-byte copy deliberately runs past this blob
 * into the graphics that follow. Editable:
 * assets/graphics/tiles/race_hud_bg.png. Hosted, the tail past the
 * blob zero-fills so the copy stays defined. */
#if PORTABLE
const u16 gRaceHudBgTiles[0x1000] = INCBIN_U16("build/assets/graphics/tiles/race_hud_bg.tiles.bin");
#else
const u16 gRaceHudBgTiles[] = INCBIN_U16("build/assets/graphics/tiles/race_hud_bg.tiles.bin");
#endif
