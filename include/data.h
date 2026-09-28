#ifndef GUARD_DATA_H
#define GUARD_DATA_H

#include "structs.h"


// ROM data that src/data/ defines and several files read, in ROM order.

extern const u32 gPitStallPositions[];
extern const u8 gText_BlankRowRaceMsg[];
extern const u8 gText_Abcdeee[];
extern const u16 gTextGlyphTileIndices[];
extern const u16 gFontGlyphGrid[];
extern const u16 gFontTileEntries[];
extern const u8 gText_BlankRowMenu[];
extern const u32 gDriverPalettes[];
extern const u8 gUnk_08338788[];
extern const u8 gText_Abcdeeee[];
extern const u8 gText_Abcdee[];
extern const u8 gText_TimCoode[];
extern struct Unk0801DACC gUnk_0801DACC[];
extern const u32 gDriverCarPalettes[];
extern const u32 gDriverCarGfxRightTiles[];
extern const u32 gSplashSpriteFrames[];
extern const u8 gMenuPalette[];
extern const u8 RomHeaderMagic;
extern const u32 RomHeaderGameCode;
extern const u8 gText_ChrisWalsh[];
extern u8 *gUnk_08365340;
extern const u8 gText_A[];
extern const u8 gText_WillGreenough[];
extern const u16 gAiDriverGearRatioTable[];
extern const u16 gAiDriverRpmPerSpeedTable[];
extern const u8 gText_DaveMurphy[];
extern const u8 gFontPalette[];
extern const u32 gTrackLapLengths[];
extern const u8 gText_Abcde[];
extern const u8 gText_Abcd[];
extern const u8 gText_PagePrevArrow[];
extern const u8 gText_BlankRow36[];
extern u32 gTextLayerMapPtr[];
extern const u8 gUnk_08337C20[];
extern const u8 gText_Ab[];
extern const u32 gUnk_083FDE18[];
extern const u8 gText_Abc[];
extern struct Unk0801DA90 gUnk_0801DA90[];
extern const u8 gText_MikeMerren[];
extern const u32 *const gLinkMarkerFrameLists[];
extern const u32 gLaneLengthPtrs[];
extern const u8 gText_BlankRowPauseMenu[];
extern const u16 gFontCharToGlyphTable[];
extern const u8 gText_BlankRow28[];
extern const u32 gDriverRoster[][2];
extern const u32 gDriverCarGfxLeftTiles[];
extern const u16 gAiDriverGearPowerTable[];
extern const u32 gTextLayerTiles[];
extern const u8 gResultsScreenPalette[];
extern const u32 gLanePointTables[];
extern const u8 gText_PageNextArrow[];
extern const u8 gSplashSpritePalette[];
extern const u16 gTextCharMap[];
extern const s16 gSinTable[];
extern const u8 gText_CameronSheppard[];
extern const u8 gText_PageNoArrowBlank[];
extern const u32 gUnk_083671C0[];
extern const u32 gLaneSegmentTables[];
extern const u8 gText_MitchellSlater[];

#endif
