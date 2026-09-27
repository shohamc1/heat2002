#ifndef GUARD_DATA_H
#define GUARD_DATA_H

#include "structs.h"


// ROM data that src/data/ defines and several files read, in ROM order.

extern const u32 gPitStallPositions[];
extern const u8 gText_BlankRowRaceMsg[];
extern const u8 gUnk_0829F258[];
extern const u16 gTextGlyphTileIndices[];
extern const u16 gFontGlyphGrid[];
extern const u16 gFontTileEntries[];
extern const u8 gText_BlankRowMenu[];
extern const u32 gDriverPalettes[];
extern const u8 gUnk_08338788[];
extern const u8 gUnk_0829F24C[];
extern const u8 gUnk_0829F264[];
extern const u8 gUnk_0829ECE4[];
extern struct Unk0801DACC gUnk_0801DACC[];
extern const u32 gDriverCarPalettes[];
extern const u32 gDriverCarGfxRightTiles[];
extern const u32 gSplashSpriteFrames[];
extern const u8 gMenuPalette[];
extern const u8 RomHeaderMagic;
extern const u32 RomHeaderGameCode;
extern const u8 gUnk_0829ED0C[];
extern u8 *gUnk_08365340;
extern const u8 gUnk_0829F2A0[];
extern const u8 gUnk_0829ECD4[];
extern const u8 gUnk_08367C06[];
extern const u8 gUnk_08367C10[];
extern const u8 gUnk_0829ECB8[];
extern const u8 gFontPalette[];
extern const u32 gTrackLapLengths[];
extern const u8 gUnk_0829F270[];
extern const u8 gUnk_0829F27C[];
extern const u8 gText_PagePrevArrow[];
extern const u8 gUnk_0829F44C[];
extern u32 gTextLayerMapPtr[];
extern const u8 gUnk_08337C20[];
extern const u8 gUnk_0829F294[];
extern const u32 gUnk_083FDE18[];
extern const u8 gUnk_0829F288[];
extern struct Unk0801DA90 gUnk_0801DA90[];
extern const u8 gUnk_0829EC9C[];
extern const u32 gLinkMarkerFrameLists[];
extern const u32 gLaneLengthPtrs[];
extern const u8 gText_BlankRowPauseMenu[];
extern const u16 gFontCharToGlyphTable[];
extern const u8 gUnk_0806C878[];
extern const u32 gDriverRoster[][2];
extern const u32 gDriverCarGfxLeftTiles[];
extern const u8 gUnk_08367BFA[];
extern const u32 gTextLayerTiles[];
extern const u8 gResultsScreenPalette[];
extern const u32 gLanePointTables[];
extern const u8 gText_PageNextArrow[];
extern const u8 gSplashSpritePalette[];
extern const u16 gTextCharMap[];
extern const s16 gSinTable[];
extern const u8 gUnk_0829EC88[];
extern const u8 gText_PageNoArrowBlank[];
extern const u32 gUnk_083671C0[];
extern const u32 gLaneSegmentTables[];
extern const u8 gUnk_0829ED78[];

#endif
