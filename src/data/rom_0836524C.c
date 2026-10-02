#include "global.h"
#include "race_setup_tables.h"

extern const u8 gText_01234[];
extern const u8 gText_BlankRow4[];
extern const u8 gText_BlankRow32[];
extern const u8 gTrack0Cues[];
extern const u8 gTrack2Cues[];
extern const u8 gTrack4Cues[];
extern const u8 gTrack5Cues[];
extern const u8 gTrack11Cues[];
extern const u8 gTrack9Cues[];

// Each track's cue list (LoadTrackCues reads entry [trackId]; 0 when the
// track has none), followed by config words no decompiled code reads.
#if PLATFORM_GBA
const u32 gTrackCueLists[] = { (u32)gTrack0Cues,
                              0,
                              (u32)gTrack2Cues,
                              0,
                              (u32)gTrack4Cues,
                              (u32)gTrack5Cues,
                              0,
                              0,
                              0,
                              (u32)gTrack9Cues,
                              0,
                              (u32)gTrack11Cues,
                              0,
                              0,
                              0,
                              0,
                              0x2000,
                              0xFF,
                              0xFF,
                              0xFF,
                              0xFF,
                              0x18000,
                              0x4,
                              0x4,
                              0x4,
                              0x4,
                              0x400 };
#else
// Hosted twin: pointer entries need a pointer-typed array here, since a
// pointer cast to an integer is not a constant initializer everywhere
// (MinGW-w64 rejects it). The trailing config words, which nothing
// reads, ride along as pointer-sized values.
const u8 *const gTrackCueLists[] = { gTrack0Cues,
                                     NULL,
                                     gTrack2Cues,
                                     NULL,
                                     gTrack4Cues,
                                     gTrack5Cues,
                                     NULL,
                                     NULL,
                                     NULL,
                                     gTrack9Cues,
                                     NULL,
                                     gTrack11Cues,
                                     NULL,
                                     NULL,
                                     NULL,
                                     NULL,
                                     (const u8 *)0x2000,
                                     (const u8 *)0xFF,
                                     (const u8 *)0xFF,
                                     (const u8 *)0xFF,
                                     (const u8 *)0xFF,
                                     (const u8 *)0x18000,
                                     (const u8 *)0x4,
                                     (const u8 *)0x4,
                                     (const u8 *)0x4,
                                     (const u8 *)0x4,
                                     (const u8 *)0x400 };
#endif
// The tune menu's lower bounds, one per setting: sub_08004B1C clamps the
// ten values (gUnk_0202A540[5] shown as "A%d %d", gUnk_0202CB20[5] as
// "G%d %d") against these.
const s32 gTuneMenuMinValues[10] = { 200, 200, 200, 200, 200, 6000, 6000, 6000, 6000, 6000 };
// The tune menu's upper bounds, one per setting.
const s32 gTuneMenuMaxValues[10] = { 1000, 1000, 1000, 1000, 600, 25000, 25000, 25000, 25000, 25000 };
// The tune menu's adjustment steps, one per setting.
const s32 gTuneMenuSteps[10] = { 20, 20, 20, 20, 20, 400, 400, 400, 400, 400 };
// One byte per track: extra seconds added to the pre-race countdown
// (InitCountdown reads it as u8 at gTrackId).
const u8 gTrackCountdownExtraSeconds[12] = TRACK_COUNTDOWN_EXTRA_SECONDS;
// Its users declare it as u8 *x.
#if PLATFORM_GBA
const u32 gUnk_0836533C = (u32)gText_01234;
#else
const u8 *const gUnk_0836533C = gText_01234;
#endif
// Its users declare it as u8 *x. This file skips data.h, whose GBA
// extern drops the outer const (see there).
const u8 *const gTextPadCharPtr = gText_BlankRow4;
// Its users declare it as u8 *x.
#if PLATFORM_GBA
const u32 gUnk_08365344 = (u32)gText_BlankRow32;
#else
const u8 *const gUnk_08365344 = gText_BlankRow32;
#endif
