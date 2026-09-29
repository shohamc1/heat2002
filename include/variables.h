#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// Shared RAM globals that several files declare and no module owns yet,
// sorted by address. Stage 1 catch-all of docs/extern-headers-plan.md;
// the addresses stay in symbols.ld.

#include "structs.h" // struct Track, complete (gModule_TrackData below)

// Forward-declared struct tags; the defining files complete them.
struct Car;
struct LaneSeg;
struct CommRegs;
struct MusicPlayerInfo;
struct SoundInfo;
struct Pt;
struct Unk0833D848;
struct WallRec;

// Main program

extern u16 gUnk_02021D04[];
extern s32 gUnk_02000478;
extern u8 gLinkPlayerSlots[];
extern struct Unk0801DA90 gModule_MPlayTable[];
extern struct Track gModule_TrackData[];
extern u16 gLinkMenuKeysPrev;
extern u8 gUnk_02024F50[];
extern u16 *gUnk_0202CC68;
extern u8 gLapProgressAdvanced;
extern u8 gUnk_02025370;
extern u32 gUnk_0200BC50[];
extern u16 gUnk_0202CB20[];
extern u32 gCamera[];
extern u32 gChallengeTimerSec;
extern s32 gUnk_02000470;
extern u32 gUnk_0200BC48;
extern u8 gChallengeCategoryUnlocked[];
extern struct Pt *gWallVertices;
extern u8 gPitMenuActive;
extern u8 gIsTimeTrial;
extern u8 gNumFinishedCars;
extern u8 gNumLaps;
extern u8 gCheatCodeDials[];
extern u8 gMenuBlinkCounter;
extern u8 *gUnk_0200221C;
extern u8 gUnk_02002218;
extern u16 gLapMs[];
extern u16 gModule_FontTileEntries[];
extern u32 gClosestLaneSegmentIndex[];
extern u16 gUnk_02022E18;
extern u16 gTrackRecordSec[];
extern u8 gModule_PleaseTurnOffYour_2[];
extern u32 gObjTileCache64[];
extern s16 gModule_SinTable[];
extern u32 gIntrVector;
extern u32 gChallengeBestValue;
extern u32 gUnk_02002148;
extern s16 gOamBuffer[];
extern s32 gTireForceAngle;
extern u8 gUnk_0202EED0;
extern u8 gUnk_02025238;
extern u8 gPitMenuCursorRow;
extern u8 gUnk_020253C8;
extern u8 gOamEntryCount;
extern u16 gLapMin[];
extern u32 gTrackCueList;
extern u8 gPracticeDone;
extern u32 gUnk_02022DE8;
extern s32 gUnk_02000474;
extern struct CommRegs gIsland_SioTransfer;
extern u32 gObjTileCache4[];
extern const u16 gUnk_0202713E[];
extern u8 gProgressFlags[];
extern u32 *gUnk_0202772C[];
extern u8 gUnk_0202EDC8[];
extern u8 gLinkSyncByte;
extern u16 gUnk_02022DE4;
extern u16 gUnk_0202F040[];
extern u32 gClosestLanePointZ[];
extern u8 *gUnk_0200BC54;
extern struct Unk0801DACC gModule_SongTable[];
extern u8 gChallengePhase;
extern s32 gUnk_02023A20[];
extern u16 gUnk_0202A540[];
extern u8 gUnk_0202523C;
extern u32 gUnk_0202CC1C[];
extern u32 gBgMapWidth;
extern u8 gSeasonNumLaps;
extern u32 gObjTileCache2[];
extern struct Car *gCarOrder[];
extern u32 gUnk_0202CC00[];
extern s32 gUnk_02000484;
extern u8 gDefaultCountdownSeconds;
extern s32 gUnk_02000488;
extern s32 gUnk_0202CD24;
extern u8 gAiCarAheadSide;
extern u32 gUnk_02022DE0;
extern u16 gUnk_020251F0;
extern u32 gSeasonRaceIndex[];
extern u8 gChampionshipAvailable[];
extern u32 gUnk_02025FD0;
extern u16 gUnk_0201F590[];
extern u8 gUnk_0202A6E0[];
extern u8 gMenuValueChanged;
extern u32 gUnk_0202ED84;
extern u8 gUnk_02024824;
extern s32 gFrameCounter;
extern s32 gUnk_02000460;
extern const struct TrackSeg *gTrackSegs;
extern s16 gUnk_0202E948;
extern u8 gChallengeResult;
extern s32 gUnk_02000480;
extern u32 gUnk_0202A3F0[];
extern u8 gPitStallOccupied[];
extern u8 gTrackSelectFrameCount;
extern u8 gUnk_02024C40[];
extern u32 gClosestLanePointX[];
extern u8 gFrontTireGripFast;
extern u8 gTireGripSlow;
extern u8 gLinkMenuPlayerIndex;
extern u8 *gUnk_02002210;
extern u8 gFuelOutStutterCounter;
extern u8 gTireGripFast;
extern s32 gCountdownSeconds;
extern u8 gTrackSelectCursor;
extern u32 gUnk_0202CB14;
extern u32 gIsland_OamBuffer[];
extern u16 *gUnk_0202CC6C;
extern u32 gUnk_0200BC2C;
extern const struct LaneSeg *gClosestLaneSegment[];
extern u32 gUnk_02024828;
extern u16 gLinkSendWords[];
extern u32 gUnk_02022DF8;
extern u16 gLinkRecvWords[];
extern u32 gObjPaletteCache[];
extern u32 gWaypointSpeedSamples[];
extern u32 gCountdownMs;
extern u8 gUnk_02025ED0[];
extern u8 gUnk_0202CC2C;
extern u8 gCheatMsgBlinkTimer;
extern u8 gOamAffineCount;
extern u16 gIntrCheck;
extern s32 gTireContactVelZ;
extern u32 gUnk_02022E20[];
extern struct SoundInfo *gSoundInfoPtr[];
extern u32 gUnk_02024C30;
extern u8 gUnk_0202CDA8[];
extern s32 gUnk_02000464;
extern u16 gUnk_02025398;
extern u8 gSeasonRaceIncomplete;
extern u8 gIsland_IntrMainBuffer[];
extern u8 gChampionshipIndex;
extern u8 gModule_GameBoyAdvance_2[];
extern u16 gLapSec[];
extern u16 gKeysHeld;
extern u8 gPitServiceEnabled;
extern u16 gPlayerKeys[];
extern u16 gVBlankCounter;
extern u32 gUnk_02022DEC[];
extern u16 gLinkMenuKeysPressed;
extern u32 gUnk_0202CC08[];
extern u8 gCheatFlags[];
extern u8 *gUnk_02002208;
extern u32 gUnk_02024820;
extern u32 gObjTileCache8[];
extern u8 gProgressSaveBuffer[];
extern u8 gFinishedCarOrder[];
extern s32 gTireSlipLimit;
extern u8 gCurrentCarIndex;
extern u32 gModule_TextLayerMapPtr[];
extern u32 gObjTileCache16[];
extern s32 gTireContactVelX;
extern u8 gStartedCarCount;
extern u16 gUnk_0202CB00[];
extern u32 *gUnk_02026E1C[];
extern u32 gTrackMapWidth[];
extern s32 gUnk_02000468;
extern u8 gPitServiceSelections[];
extern u32 gUnk_0200BC4C;
extern u32 gUnk_0202AF44[][2];
extern u32 gVBlankCallback[];
extern u32 gChallengeTimerMs;
extern u8 gTrackCueId;
extern struct CommRegs gSioTransfer;
extern u8 gPlayerPittedFlag;
extern u8 gUnk_0200D118[];
extern u8 gModule_BlankRow28[];
extern u8 gUnk_0202ED80[];
extern u8 gUnk_020020B4;
extern u8 gUnk_0202F1B8[];
extern u8 gDamagePitsEnabled;
extern u16 gUnk_0202522C;
extern u16 gUnk_0200BC34;
extern u8 gUnk_02024830[];
extern u16 gSpriteOrderTable[];
extern u32 gUnk_0202CAE4;
extern s32 gUnk_0200046C;
extern s32 gUnk_0200047C;
extern u8 gUnk_02025244;
extern u8 gChallengeIndex;
extern struct WallRec *gUnk_0202CC40;
extern u16 gTrackRecordMin[];
extern const u16 gUnk_02027154[];
extern u8 gFrontTireGripSlow;
extern s32 gAxleTireGrip;
extern u8 gUnk_02021594[];
extern s16 gUnk_0202E930;
extern u16 gTrackRecordMs[];
extern u8 gCheatCodeWasValid;
extern u32 gObjTileCache1[];
extern const u16 gUnk_0202714A[];
extern u32 gTireSlipLimitBase;
extern u16 gLinkVBlankTimeout;
extern u8 gLinkPlayerCount;
extern u16 gModule_TextGlyphTileIndices[];
extern u8 gQualifyingDone;
extern u8 gChallengeStatus[];
extern u16 gUnk_0202F170[];
extern u8 gUnk_020243E8[];
extern s32 gAxleCarAngle;
extern u8 *gUnk_02025230;
extern u32 gIntrTable[];
extern u16 gKeysPressed;                     /* 0x020005CC */
extern u16 gUnk_02000DD0;                    /* 0x02000DD0 */
extern u8 gBgMusicPlayer[];                  /* 0x02001F20 */
extern struct MusicPlayerInfo gUnk_02001FA0; /* 0x02001FA0 */
extern struct MusicPlayerInfo gUnk_02001FE0; /* 0x02001FE0 */
extern struct MusicPlayerInfo gUnk_02002030; /* 0x02002030 */
extern u8 gNumCars[];                        /* 0x02002090 */
extern u8 gChallengeScore;                   /* 0x02002098 */
extern u8 gPreRaceSimActive;                 /* 0x020020A8 */
extern u8 gNumLinkPlayers[];                 /* 0x020020AC */
extern u8 gVBlankWorkDone;                   /* 0x020020C0 */
extern u8 gRaceStarted;                      /* 0x020020C4 */
extern u8 gTrackId;                          /* 0x020020CC */
extern u32 gRngState;                        /* 0x020020D4 */
extern u8 gIsLinkRace;                       /* 0x020020DC */
extern u8 gIsDemo;                           /* 0x020020E0 */
extern u8 gUnk_020020EC;                     /* 0x020020EC */
extern u8 gNewTrackRecord;                   /* 0x020020F0 */
extern u8 gGameMode[];                       /* 0x0200215C */
extern u16 gLinkTxSeqNum;                    /* 0x02002170 */
extern u8 gRaceAborted;                      /* 0x020021BC */
extern u8 gBgScrollUpdateEnabled;            /* 0x020021C4 */
extern u8 gRaceEndState;                     /* 0x020021E0 */
extern u8 gFadeActive;                       /* 0x02022E14 */
extern u16 gRaceSec;                         /* 0x02025220 */
extern u16 gRaceMs;                          /* 0x02025224 */
extern u8 gPauseMenuCursor;                  /* 0x02025248 */
extern u16 gRaceMin;                         /* 0x02025260 */
extern u32 gRaceStartTaskPtr;                /* 0x0202CC04 */
extern u8 gLapTimeTextBuf[];                 /* 0x0202CC10 */
extern u8 gOptions[];                        /* 0x0202EF00 */
extern u8 gLinkPlayerId[];                   /* 0x0202EF90 */

// High module (links at its EWRAM run address)

extern u32 gUnk_0203DE3C[];
extern u32 gModule_CountdownSeconds;
extern u8 gUnk_0203ACE0[];
extern s32 gUnk_020375B4;
extern u8 gModule_GameMode[];
extern u8 gUnk_0203B604;
extern u8 gUnk_020390CC;
extern u32 gModule_CountdownMs;
extern u16 gUnk_0203B848;
extern u16 gModule_TrackRecordMin[];
extern u32 *gUnk_0203ACD8;
extern u8 gUnk_020391D4;
extern u8 gUnk_0203E104;
extern u8 gModule_RaceStarted;
extern u8 gModule_NumCars[];
extern s32 gModule_TireContactVelZ;
extern u8 gUnk_020390B8;
extern u8 gModule_TrackId;
extern s32 gUnk_020375A8;
extern u32 gModule_TireSlipLimitBase;
extern u32 gUnk_02039298;
extern struct Pt *gUnk_0203DE64;
extern u8 gModule_ObjTileCache8[];
extern u8 gModule_IsDemo[];
extern s32 gModule_AxleTireGrip;
extern u8 gUnk_0203B600;
extern u16 *gUnk_0203DE88;
extern s32 gModule_TireSlipLimit;
extern u32 gUnk_02039290;
extern u8 gUnk_020390C4;
extern u8 gModule_NumFinishedCars;
extern u8 gUnk_0203DFB0;
extern u16 gUnk_020392A4;
extern u8 gModule_ObjTileCache2[];
extern u8 gModule_ObjTileCache4[];
extern u8 gUnk_0203E140[];
extern u8 gModule_FrontTireGripSlow;
extern u32 gModule_PaletteFadeColors[];
extern s32 gModule_FrameCounter;
extern s32 gUnk_020375A0;
extern u32 gUnk_0203DCFC;
extern s32 gUnk_020375C4;
extern u32 gUnk_02039240;
extern u8 *gUnk_0203929C;
extern u32 gUnk_0203DD60[];
extern u16 *gUnk_02039238;
extern u32 gModule_TrackMapWidth[];
extern u16 gUnk_0203B6FC;
extern u16 gUnk_020390B0[];
extern u8 gUnk_020390FC;
extern s32 gUnk_020375AC;
extern u8 gUnk_02039100;
extern u16 gModule_TrackRecordMs[];
extern s32 gModule_AxleCarAngle;
extern s32 gUnk_020375BC;
extern u16 *gUnk_0203922C;
extern u8 gModule_DamagePitsEnabled;
extern u16 gModule_LinkTxSeqNum;
extern u32 gModule_PaletteFadeDeltas[];
extern u8 gModule_CurrentCarIndex;
extern u16 *gUnk_02039268;
extern u8 gModule_VBlankWorkDone;
extern u32 gUnk_0203B0E0;
extern u8 gModule_NumLinkPlayers[];
extern s32 gUnk_020375B0;
extern u16 gModule_VBlanksThisFrame;
extern u8 gModule_Options[];
extern s32 gUnk_020375B8;
extern u8 gModule_ObjTileCache16[];
extern u8 gModule_TireGripSlow;
extern s32 gModule_TireForceAngle;
extern u8 gModule_PaletteFadeActive;
extern u32 gUnk_020375D0;
extern s32 gUnk_020375C8;
extern u32 gUnk_020392A8;
extern u8 gModule_RaceEndState;
extern u32 gUnk_0203925C;
extern u8 gUnk_02039194;
extern u32 *gUnk_0203ACD0;
extern u32 gUnk_0203DE20[];
extern u8 gModule_TireGripFast;
extern u8 gModule_FinishedCarOrder[];
extern u32 gUnk_0203D500;
extern u32 gUnk_0203DE28[];
extern u32 gUnk_0203DD04;
extern u16 *gUnk_02039228;
extern s32 gUnk_020375C0;
extern u16 *gUnk_0203DE8C;
extern u8 gUnk_0203DDE8[];
extern u8 gModule_FrontTireGripFast;
extern u16 gUnk_0203B828;
extern u8 gUnk_0203DD10;
extern u32 gUnk_0203C380;
extern u32 gUnk_0203DE24;
extern s32 gModule_TireContactVelX;
extern struct Unk0833D848 gUnk_0203B0F0[];
extern u32 gUnk_0203C270[];
extern u32 gUnk_02039260;
extern s32 gUnk_020375A4;
extern u32 gModule_IntrTable[];
extern u8 gUnk_0203D4E8;
extern u8 gModule_LinkPlayerId;
extern u8 gUnk_0203C340[];
extern u16 gUnk_02039248;
extern s32 gUnk_0203DF44;
extern u16 gModule_TrackRecordSec[];
extern u16 gUnk_0203B610[];
extern struct MusicPlayerInfo gUnk_02038FB0;
extern u8 gModule_ObjTileCache1[];
extern u32 gUnk_02039200[];
extern u32 gUnk_0203DD34;
extern u8 gModule_ObjTileCache64[];
extern u8 gModule_Language;
extern u16 gUnk_0203B6DC;
extern u16 gUnk_02039294;
extern u16 gModule_PaletteFadeSteps;
extern const struct TrackSeg *gModule_TrackSegs;
extern u8 gUnk_0203B850[];
extern u16 gModule_LinkTxBuffer[];
extern u32 gUnk_0203D4A0[];
extern u8 gModule_IsLinkRace;
extern u16 gModule_LinkRecvWords[];
extern u8 gUnk_0203ACD4;
extern u8 gUnk_02039234[];
extern u8 gUnk_0203E1C0[];
extern u8 gUnk_0203E1E0[];
extern u32 gUnk_02039244;
extern struct WallRec *gUnk_0203DE60;
extern struct MusicPlayerInfo gUnk_02038F70;
extern u16 gUnk_0203917C;
extern u32 gModule_Camera[];
extern u16 gUnk_02037618;     /* 0x02037618 */
extern u16 gUnk_0203761C;     /* 0x0203761C */
extern u16 gUnk_02037E20;     /* 0x02037E20 */
extern u32 gUnk_020390E4;     /* 0x020390E4 */
extern u8 gUnk_020392C0;      /* 0x020392C0 */
extern u16 gModule_LapSec[];  /* 0x0203B6A8 */
extern u16 gModule_LapMin[];  /* 0x0203B6C8 */
extern u16 gModule_RaceSec[]; /* 0x0203B6D0 */
extern u16 gModule_RaceMs[];  /* 0x0203B6D4 */
extern u8 gUnk_0203B6E8;      /* 0x0203B6E8 */
extern u8 gUnk_0203B6F0;      /* 0x0203B6F0 */
extern u16 gModule_RaceMin[]; /* 0x0203B704 */
extern u16 gModule_LapMs[];   /* 0x0203B858 */
extern u8 gUnk_0203DE30[];    /* 0x0203DE30 */

#endif
