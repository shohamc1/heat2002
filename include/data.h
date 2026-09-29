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
extern const u8 *const gDriverPalettes[];
extern const u8 gHudWarningIconPalette[];
extern const u8 gText_Abcdeeee[];
extern const u8 gText_Abcdee[];
extern const u8 gText_TimCoode[];
extern const struct Song gSongTable[];
extern const u8 *const gDriverCarPalettes[];
extern const u32 *const gDriverCarGfxRightTiles[];
extern const u8 *const gSplashSpriteFrames[];
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
extern const u8 gLinkMarkerPalette[];
extern const u8 gText_Ab[];
extern const u8 *const gUiFontTable[];
extern const u8 gText_Abc[];
extern const struct MusicPlayer gMPlayTable[];
/* Song headers; gSongTable's rows name them. The songs' labels come from
 * mid2agb in data/sound/sounds.s; song_dummy is the 4-byte empty song
 * data/sound/direct_sound_samples.s holds. */
extern struct SongHeader song_dummy;
extern struct SongHeader song_01;
extern struct SongHeader song_02;
extern struct SongHeader song_03;
extern struct SongHeader song_08;
extern struct SongHeader song_09;
extern struct SongHeader song_10;
extern struct SongHeader song_11;
extern struct SongHeader song_12;
extern struct SongHeader song_13;
extern struct SongHeader song_14;
extern struct SongHeader song_15;
extern struct SongHeader song_16;
extern struct SongHeader song_17;
extern struct SongHeader song_18;
extern struct SongHeader song_19;
extern struct SongHeader song_20;
extern struct SongHeader song_21;
extern struct SongHeader song_22;
extern struct SongHeader song_23;
extern struct SongHeader song_24;
extern struct SongHeader song_25;
extern struct SongHeader song_26;
extern struct SongHeader song_27;
extern struct SongHeader song_28;
extern struct SongHeader song_29;
extern const u8 gText_MikeMerren[];
extern const u32 *const gLinkMarkerFrameLists[];
extern const u8 *const gLaneLengthPtrs[];
extern const u8 gText_BlankRowPauseMenu[];
extern const u16 gFontCharToGlyphTable[];
extern const u8 gText_BlankRow28[];
extern const struct DriverRosterEntry gDriverRoster[];
extern const u32 *const gDriverCarGfxLeftTiles[];
extern const u16 gAiDriverGearPowerTable[];
extern const u32 gTextLayerTiles[];
extern const u8 gResultsScreenPalette[];
extern const u16 *const gLanePointTables[];
extern const u8 gText_PageNextArrow[];
extern const u8 gSplashSpritePalette[];
extern const u16 gTextCharMap[];
extern const s16 gSinTable[];
extern const u8 gText_CameronSheppard[];
extern const u8 gText_PageNoArrowBlank[];
extern const struct TrackSeg *const gTrackSegTables[];
extern const struct LaneSeg *const gLaneSegmentTables[];
extern const u8 gText_MitchellSlater[];
extern const struct CreditLine gCreditTexts[];

#endif
