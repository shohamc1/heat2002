#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// Shared RAM globals that several files declare and no module owns yet,
// sorted by address. Stage 1 catch-all of docs/extern-headers-plan.md;
// the addresses stay in symbols.ld.

#include "config.h"
#include "structs.h" // struct Track, complete (gModule_TrackData below)

#if !PLATFORM_GBA
#include "gba/m4a_internal.h" // completes struct MusicPlayerTrack for the
                              // extern track arrays below; agbcc accepted
                              // them on a forward declaration alone
#endif

// Forward-declared struct tags; the defining files complete them.
struct Car;
struct LaneSeg;
struct CommRegs;
struct MusicPlayerInfo;
struct SoundInfo;
struct Pt;
struct WallRec;

// Main program

extern u16 gModule_FontCharToGlyphTable[];
extern s32 gUnk_02000478;
extern u8 gLinkPlayerSlots[];
extern const struct MusicPlayer gModule_MPlayTable[];
extern struct Track gModule_TrackData[];
extern u16 gLinkMenuKeysPrev;
extern u32 gModule_SpeedNeedleGfx[];
extern u8 gModule_LowFuelWarningGfx[];
extern u16 *gUnk_0202CC68;
extern u8 gLapProgressAdvanced;
extern u8 gUnk_02025370;
/* The track's cell map, RLE-decoded into gCellMapBuffer (see
   GetTrackTileType). */
extern u8 *gCellMapPtr;
extern u16 gUnk_0202CB20[];
extern u32 gCamera[];
extern s32 gChallengeTimerSec;
extern s32 gUnk_02000470;
extern u32 gBg1ScrollX;
extern u8 gChallengeCategoryUnlocked[];
extern struct Pt *gWallVertices;
extern u8 gPitMenuActive;
extern u8 gIsTimeTrial;
extern u8 gNumFinishedCars;
extern u8 gNumLaps;
extern u8 gCheatCodeDials[];
extern u8 gMenuBlinkCounter;
extern u8 *gBg3Metatiles;
extern u8 gMapScrollHalfMetatile;
extern u16 gLapMs;
extern u16 gModule_FontTileEntries[];
extern s32 gClosestLaneSegmentIndex;
extern u16 gPaletteFadeSteps;
extern u16 gTrackRecordSec[];
extern u8 gModule_PleaseTurnOffYour_2[];
extern struct ObjTileCacheEntry gObjTileCache64[];
extern s16 gModule_SinTable[];
extern u32 gIntrVector;
extern s32 gChallengeBestValue;
extern u32 gUnk_02002148;
extern s16 gOamBuffer[];
extern s32 gTireForceAngle;
extern u8 gUnk_0202EED0;
extern u8 gUnk_02025238;
extern u8 gPitMenuCursorRow;
extern u8 gUnk_020253C8;
extern u8 gOamEntryCount;
extern u16 gLapMin;
/* The active track's cue-record list; pointer-wide when hosted, the
   u32 word the GBA code computes with otherwise. */
#if PORTABLE
extern const u8 *gTrackCueList;
#else
extern u32 gTrackCueList;
#endif
extern u8 gPracticeDone;
extern u32 gBg3ScrollY;
extern s32 gUnk_02000474;
extern struct CommRegs gIsland_SioTransfer;
extern struct ObjTileCacheEntry gObjTileCache4[];
extern const u16 gModule_AiDriverGearPowerTable[];
extern u8 gProgressFlags[];
extern const GfxSrc *gModule_LinkMarkerFrameLists[];
extern u8 gUnk_0202EDC8[];
extern u8 gLinkSyncByte;
extern u16 gUnk_02022DE4;
#if PORTABLE
/* The EEPROM staging run 0x0202F040-0x0202F1C0 as one buffer (defined in
   src/save/save.c): the game indexes across its views (WriteSaveBlocks
   walks &gUnk_0202F040[a/2] to a = 0x178, IsSeasonSaved reads
   gUnk_0202F040[5], SaveSeason walks out of gSeasonSaveFlag), which the
   GBA build's contiguous run makes defined and a hosted build's separate
   globals would not. Each view aliases into the buffer at its GBA offset;
   the GBA build keeps the run's separate arrays (src/save/save.c). */
extern u16 gSaveStaging[];
#define gUnk_0202F040 gSaveStaging
#define gSeasonSaveFlag (gSaveStaging + 5)
#define gProgressSaveBuffer ((u8 *)(gSaveStaging + 8))
#define gSeasonSaveData (gSaveStaging + 0x20)
#define gUnk_0202F170 (gSaveStaging + 0x98)
#define gUnk_0202F1B8 ((u8 *)(gSaveStaging + 0xBC))
#else
extern u16 gUnk_0202F040[];
#endif
extern s32 gClosestLanePointZ;
extern u8 *gBg2MapPtr;
extern const struct Song gModule_SongTable[];
extern u8 gChallengePhase;
extern s32 gPaletteFadeDeltas[];
extern u16 gUnk_0202A540[];
extern u8 gUnk_0202523C;
extern u32 gUnk_0202CC1C[];
extern u32 gBgMapWidth;
extern u8 gSeasonNumLaps;
extern struct ObjTileCacheEntry gObjTileCache2[];
extern struct Car *gCarOrder[];
extern u32 gUnk_0202CC00;
extern s32 gUnk_02000484;
extern u8 gDefaultCountdownSeconds;
extern s32 gUnk_02000488;
extern s32 gUnk_0202CD24;
extern u8 gAiCarAheadSide;
extern u32 gBg3ScrollX;
extern u16 gUnk_020251F0;
extern u8 gSeasonRaceIndex[];
extern u8 gChampionshipAvailable[];
extern struct Task *gTaskListHead;
extern u16 gUnk_0201F590[];
extern u8 gMenuValueChanged;
extern u32 gUnk_0202ED84;
extern u8 gDepthSortedSpriteCount;
extern s32 gFrameCounter;
extern s32 gUnk_02000460;
extern const struct TrackSeg *gTrackSegs;
extern s16 gUnk_0202E948;
extern u8 gChallengeResult;
extern s32 gUnk_02000480;
extern u32 gUnk_0202A3F0[];
extern u8 gPitStallOccupied[];
extern u8 gTrackSelectFrameCount;
extern struct DepthSortedSprite gDepthSortedSprites[];
extern s32 gClosestLanePointX;
extern u8 gFrontTireGripFast;
extern u8 gTireGripSlow;
extern u8 gLinkMenuPlayerIndex;
extern u8 *gBg2Metatiles;
extern u8 gFuelOutStutterCounter;
extern u8 gTireGripFast;
extern s32 gCountdownSeconds;
extern s8 gTrackSelectCursor;
extern s32 gUnk_0202CB14;
extern u32 gIsland_OamBuffer[];
extern u16 *gUnk_0202CC6C;
extern u32 gBg2ScrollY;
extern const struct LaneSeg *gClosestLaneSegment;
/* The OAM entry queue's fill cursor (see src/sprite/oam.c). */
extern u32 *gOamEntryQueueCursor;
extern u16 gLinkSendWords[];
extern u32 gBg2ScrollX;
extern u16 gLinkRecvWords[];
extern struct ObjPaletteCacheEntry gObjPaletteCache[];
extern u32 gWaypointSpeedSamples[];
extern u32 gCountdownMs;
extern u8 gTaskSlotUsed[];
extern struct Task gTasks[];
extern u8 gUnk_0202CC2C;
extern u8 gCheatMsgBlinkTimer;
extern u8 gOamAffineCount;
#if PLATFORM_GBA
extern u16 gIntrCheck;
#else
/* The port's interrupt-check flag is the platform's INTR_CHECK variable
   (gba/defines.h); the GBA build keeps the IWRAM extern, defined in
   src/link/ExchangeLinkInput.c. */
#define gIntrCheck INTR_CHECK
#endif
extern s32 gTireContactVelZ;
extern u32 gPaletteFadeColors[];
#if PLATFORM_GBA
extern struct SoundInfo *gSoundInfoPtr[];
#else
/* The port's sound-info pointer slot is the platform's SOUND_INFO_PTR
   variable (gba/defines.h); the & keeps the [0] the code reads. */
#define gSoundInfoPtr (&SOUND_INFO_PTR)
#endif
/* The driver state itself (defined in src/system/globals.c; SoundInit
   writes its address into SOUND_INFO_PTR). The platform layer also
   reads it: the port's SOUND_INFO_PTR starts pointing here, since the
   game calls m4aSoundVSyncOff before any m4aSoundInit and the GBA
   survives that only because the pointer slot holds stack garbage. */
extern struct SoundInfo gSoundInfo;
/* The second OAM sort buffer's cursor (see src/sprite/oam.c). */
extern u8 *gSecondOamSortCursor;
extern u8 gUnk_0202CDA8[];
extern s32 gUnk_02000464;
extern u16 gUnk_02025398;
extern u8 gSeasonRaceIncomplete;
extern u8 gIsland_IntrMainBuffer[];
extern u8 gChampionshipIndex;
extern u8 gModule_GameBoyAdvance_2[];
extern u16 gLapSec;
extern u16 gKeysHeld;
extern u8 gPitServiceEnabled;
extern u16 gPlayerKeys[];
extern u16 gVBlankCounter;
extern const u8 *gSurfaceTablePtr;
extern u16 gLinkMenuKeysPressed;
extern u32 gUnk_0202CC08;
extern u8 gCheatFlags[];
extern u8 *gBg3MapPtr;
/* The depth-sorted sprite queue's append cursor (see src/sprite/oam.c). */
extern struct DepthSortedSprite *gDepthSortedSpriteCursor;
extern struct ObjTileCacheEntry gObjTileCache8[];
#if !PORTABLE /* aliases gSaveStaging hosted (see the gUnk_0202F040 block) */
extern u8 gProgressSaveBuffer[];
#endif
extern u8 gFinishedCarOrder[];
extern s32 gTireSlipLimit;
extern u8 gCurrentCarIndex;
extern u32 gModule_TextLayerMapPtr[];
extern struct ObjTileCacheEntry gObjTileCache16[];
extern s32 gTireContactVelX;
extern u8 gStartedCarCount;
extern u16 gUnk_0202CB00[];
extern u32 *gModule_DriverPalettes[];
extern u32 gTrackMapWidth;
extern s32 gUnk_02000468;
extern u8 gPitServiceSelections[];
extern u32 gBg1ScrollY;
extern IntrFunc gVBlankCallback;
extern s32 gChallengeTimerMs;
extern s8 gTrackCueId;
extern struct CommRegs gSioTransfer;
extern u8 gPlayerPittedFlag;
extern u8 gUnk_0200D118[];
extern u8 gModule_BlankRow28[];
extern u8 gUnk_0202ED80[];
extern u8 gUnk_020020B4;
#if !PORTABLE /* aliases gSaveStaging hosted (see the gUnk_0202F040 block) */
extern u8 gUnk_0202F1B8[];
#endif
extern u8 gDamagePitsEnabled;
extern u16 gUnk_0202522C;
extern u16 gUnk_0200BC34;
extern u32 gOamEntryQueue[];
extern u16 gSpriteOrderTable[];
extern s32 gUnk_0202CAE4;
extern s32 gUnk_0200046C;
extern s32 gUnk_0200047C;
extern u8 gUnk_02025244;
extern u8 gChallengeIndex;
extern struct WallRec *gWalls;
extern u16 gTrackRecordMin[];
extern const u16 gModule_AiDriverRpmPerSpeedTable[];
extern u8 gFrontTireGripSlow;
extern s32 gAxleTireGrip;
extern u8 gModule_FontGlyphGrid[];
extern s16 gUnk_0202E930;
extern u16 gTrackRecordMs[];
extern u8 gCheatCodeWasValid;
extern struct ObjTileCacheEntry gObjTileCache1[];
extern const u16 gModule_AiDriverGearRatioTable[];
extern u32 gTireSlipLimitBase;
extern u16 gLinkVBlankTimeout;
extern u8 gLinkPlayerCount;
extern u16 gModule_TextGlyphTileIndices[];
extern u8 gQualifyingDone;
extern u8 gChallengeStatus[];
#if !PORTABLE /* aliases gSaveStaging hosted (see the gUnk_0202F040 block) */
extern u16 gUnk_0202F170[];
#endif
extern s32 gAxleCarAngle;
extern u8 *gUnk_02025230;
extern IntrFunc gIntrTable[];
extern struct MusicPlayerTrack gUnk_02000000[];   /* 0x02000000: gMPlayTable's track arrays */
extern struct MusicPlayerTrack gUnk_02000320[];   /* 0x02000320 */
extern struct MusicPlayerTrack gUnk_02000370[];   /* 0x02000370 */
extern struct MusicPlayerTrack gUnk_020003C0[];   /* 0x020003C0 */
extern struct MusicPlayerTrack gUnk_02000410[];   /* 0x02000410 */
extern u16 gKeysPressed;                          /* 0x020005CC */
extern u8 gUnk_020005D0[];                        /* 0x020005D0: IntrMain's EWRAM copy, INTR_VECTOR's target */
extern u16 gUnk_02000DD0;                         /* 0x02000DD0 */
extern struct MusicPlayerInfo gBgMusicPlayer;     /* 0x02001F20 */
extern struct MusicPlayerInfo gEngineSoundPlayer; /* 0x02001F60 */
extern struct MusicPlayerInfo gMPlayInfo_SE2;     /* 0x02001FA0 */
extern struct MusicPlayerInfo gMPlayInfo_SE4;     /* 0x02001FE0 */
extern struct MusicPlayerInfo gMPlayInfo_SE3;     /* 0x02002030 */
extern u8 gNumCars[];                             /* 0x02002090 */
extern u8 gChallengeScore;                        /* 0x02002098 */
extern u8 gPreRaceSimActive;                      /* 0x020020A8 */
extern u8 gNumLinkPlayers[];                      /* 0x020020AC */
extern u8 gVBlankWorkDone;                        /* 0x020020C0 */
extern u8 gRaceStarted;                           /* 0x020020C4 */
extern u8 gTrackId;                               /* 0x020020CC */
extern u32 gRngState;                             /* 0x020020D4 */
extern u8 gIsLinkRace;                            /* 0x020020DC */
extern u8 gIsDemo;                                /* 0x020020E0 */
extern u8 gUnk_020020EC;                          /* 0x020020EC */
extern u8 gNewTrackRecord;                        /* 0x020020F0 */
extern u8 gGameMode;                              /* 0x0200215C */
extern u16 gLinkTxSeqNum;                         /* 0x02002170 */
extern u8 gRaceAborted;                           /* 0x020021BC */
extern u8 gBgScrollUpdateEnabled;                 /* 0x020021C4 */
extern u8 gRaceEndState;                          /* 0x020021E0 */
extern u8 gFadeActive;                            /* 0x02022E14 */
extern u16 gRaceSec;                              /* 0x02025220 */
extern u16 gRaceMs;                               /* 0x02025224 */
extern u8 gPauseMenuCursor;                       /* 0x02025248 */
extern u16 gRaceMin;                              /* 0x02025260 */
extern struct Task *gRaceStartTaskPtr;            /* 0x0202CC04 */
extern u8 gLapTimeTextBuf[];                      /* 0x0202CC10 */
extern u8 gOptions[];                             /* 0x0202EF00 */
extern u8 gLinkPlayerId;                          /* 0x0202EF90 */

// High module (links at its EWRAM run address)

extern u8 gModule_FontPalette[];
extern u8 gModule_HudWarningIconPalette[];
extern u8 gModule_LinkMarkerPalette[];
extern u32 gUnk_0203DE3C;
extern u32 gModule_CountdownSeconds;
extern u32 gModule_OamEntryQueue[];
extern s32 gUnk_020375B4;
extern u8 gModule_GameMode;
extern u8 gUnk_0203B604;
extern u8 gUnk_020390CC;
extern u32 gModule_CountdownMs;
extern u16 gUnk_0203B848;
extern u16 gModule_TrackRecordMin[];
extern u32 *gModule_OamEntryQueueCursor;
extern u8 gModule_BgScrollUpdateEnabled;
extern u8 gUnk_0203E104;
extern u8 gModule_RaceStarted;
extern u8 gModule_NumCars[];
extern s32 gModule_TireContactVelZ;
extern u8 gUnk_020390B8;
extern u8 gModule_TrackId;
extern s32 gUnk_020375A8;
extern u32 gModule_TireSlipLimitBase;
extern u32 gModule_Bg3ScrollY;
extern struct Pt *gModule_WallVertices;
extern struct ObjTileCacheEntry gModule_ObjTileCache8[];
extern u8 gModule_IsDemo;
extern s32 gModule_AxleTireGrip;
extern u8 gUnk_0203B600;
extern u16 *gUnk_0203DE88;
extern s32 gModule_TireSlipLimit;
extern u32 gModule_Bg3ScrollX;
extern u8 gUnk_020390C4;
extern u8 gModule_NumFinishedCars;
extern u8 gUnk_0203DFB0;
extern u16 gUnk_020392A4;
extern struct ObjTileCacheEntry gModule_ObjTileCache2[];
extern struct ObjTileCacheEntry gModule_ObjTileCache4[];
extern u8 gUnk_0203E140[];
extern u8 gModule_FrontTireGripSlow;
extern u32 gModule_PaletteFadeColors[];
extern s32 gModule_FrameCounter;
extern s32 gUnk_020375A0;
extern s32 gUnk_0203DCFC;
extern s32 gUnk_020375C4;
extern u32 gModule_Bg2ScrollY;
extern const u8 *gModule_SurfaceTablePtr;
extern u32 gUnk_0203DD60[];
extern u16 *gModule_Bg3Metatiles;
extern u32 gModule_TrackMapWidth;
extern u16 gUnk_0203B6FC;
extern u16 gUnk_020390B0[];
extern u8 gUnk_020390FC;
extern s32 gUnk_020375AC;
extern u8 gUnk_02039100;
extern u16 gModule_TrackRecordMs[];
extern s32 gModule_AxleCarAngle;
extern s32 gUnk_020375BC;
extern u16 *gModule_Bg2Metatiles;
extern u8 gModule_DamagePitsEnabled;
extern u16 gModule_LinkTxSeqNum;
extern u32 gModule_PaletteFadeDeltas[];
extern u8 gModule_CurrentCarIndex;
extern u16 *gModule_Bg2MapPtr;
extern u8 gModule_VBlankWorkDone;
extern u8 *gModule_SecondOamSortCursor;
extern u8 gModule_SecondOamSortBuffer[];
extern u8 gModule_NumLinkPlayers[];
extern s32 gUnk_020375B0;
extern u16 gModule_VBlanksThisFrame;
extern u8 gModule_Options[];
extern s32 gUnk_020375B8;
extern struct ObjTileCacheEntry gModule_ObjTileCache16[];
extern u8 gModule_TireGripSlow;
extern s32 gModule_TireForceAngle;
extern u8 gModule_PaletteFadeActive;
extern IntrFunc gModule_VBlankCallback;
extern s32 gUnk_020375C8;
extern u32 gModule_Bg2ScrollX;
extern u8 gModule_RaceEndState;
extern u32 gModule_Bg1ScrollX;
extern u8 gUnk_02039194;
extern struct DepthSortedSprite *gModule_DepthSortedSpriteCursor;
extern u32 gUnk_0203DE20;
extern u8 gModule_TireGripFast;
extern u8 gModule_FinishedCarOrder[];
extern s32 gUnk_0203D500;
extern u32 gUnk_0203DE28;
extern u32 gUnk_0203DD04;
extern u16 *gModule_Bg3MapPtr;
extern s32 gUnk_020375C0;
extern u16 *gUnk_0203DE8C;
extern u8 gUnk_0203DDE8[];
extern u8 gModule_FrontTireGripFast;
extern u16 gUnk_0203B828;
extern u8 gUnk_0203DD10;
extern struct Task *gModule_TaskListHead;
extern struct Task *gModule_RaceStartTaskPtr;
extern s32 gModule_TireContactVelX;
extern struct DepthSortedSprite gModule_DepthSortedSprites[];
extern struct ObjPaletteCacheEntry gModule_ObjPaletteCache[];
extern u32 gModule_Bg1ScrollY;
extern s32 gUnk_020375A4;
extern IntrFunc gModule_IntrTable[];
extern u8 gUnk_0203D4E8;
extern u8 gModule_LinkPlayerId;
extern u8 gModule_TaskSlotUsed[];
extern struct Task gModule_Tasks[];
extern u16 gUnk_02039248;
extern s32 gUnk_0203DF44;
extern u16 gModule_TrackRecordSec[];
extern u16 gModule_SpriteOrderTable[];
extern struct MusicPlayerInfo gModule_EngineSoundPlayer;
extern struct ObjTileCacheEntry gModule_ObjTileCache1[];
extern struct Car *gModule_CarOrder[];
extern s32 gUnk_0203DD34;
extern struct ObjTileCacheEntry gModule_ObjTileCache64[];
extern u8 gModule_Language;
extern u16 gUnk_0203B6DC;
extern u16 gUnk_02039294;
extern s16 gModule_PaletteFadeSteps;
extern const struct TrackSeg *gModule_TrackSegs;
extern u8 gUnk_0203B850;
extern u16 gModule_LinkTxBuffer[];
extern u32 gUnk_0203D4A0[];
extern u8 gModule_IsLinkRace;
extern u16 gModule_LinkRecvWords[];
extern u8 gModule_DepthSortedSpriteCount;
extern u8 gModule_MapScrollHalfMetatile;
extern u8 gUnk_0203E1C0[];
extern u8 gUnk_0203E1E0[];
extern u32 gModule_BgMapWidth;
extern struct WallRec *gModule_Walls;
extern struct MusicPlayerInfo gModule_BgMusicPlayer;
extern struct MusicPlayerInfo gUnk_02038FF0; /* gModule_MPlayTable rows 2-3 */
extern struct MusicPlayerInfo gUnk_02039040;
extern u16 gUnk_0203917C;
extern u32 gModule_Camera[];
extern u16 gUnk_02037618;             /* 0x02037618 */
extern u16 gUnk_0203761C;             /* 0x0203761C */
extern u16 gUnk_02037E20;             /* 0x02037E20 */
extern u32 gUnk_020390E4;             /* 0x020390E4 */
extern u8 gModule_PaletteBufferDirty; /* 0x020392C0 */
extern u16 gModule_LapSec;            /* 0x0203B6A8 */
extern u16 gModule_LapMin[];          /* 0x0203B6C8 */
extern u16 gModule_RaceSec[];         /* 0x0203B6D0 */
extern u16 gModule_RaceMs[];          /* 0x0203B6D4 */
extern u8 gUnk_0203B6E8;              /* 0x0203B6E8 */
extern u8 gUnk_0203B6F0;              /* 0x0203B6F0 */
extern u16 gModule_RaceMin[];         /* 0x0203B704 */
extern u16 gModule_LapMs[];           /* 0x0203B858 */
extern u8 gUnk_0203DE30[];            /* 0x0203DE30 */

#endif
