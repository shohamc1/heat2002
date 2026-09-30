#include "global.h"
#include "data.h"
#include "race_setup_tables.h"

extern const u8 gText_01234[];
extern const u8 gText_BlankRow4[];
extern const u8 gText_BlankRow32[];
extern const u8 gUnk_08364FBC[];
extern const u8 gUnk_0836500C[];
extern const u8 gUnk_0836509C[];
extern const u8 gUnk_08365114[];
extern const u8 gUnk_08365174[];
extern const u8 gUnk_083651C4[];

// Stays flat: mixed pointer/config words with no decompiled reader
// holding a struct view; a guessed layout would be wrong.
const u32 gUnk_0836524C[] = { (u32)gUnk_08364FBC,
                              0,
                              (u32)gUnk_0836500C,
                              0,
                              (u32)gUnk_0836509C,
                              (u32)gUnk_08365114,
                              0,
                              0,
                              0,
                              (u32)gUnk_083651C4,
                              0,
                              (u32)gUnk_08365174,
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
const u32 gUnk_0836533C = (u32)gText_01234;
// Its users declare it as u8 *x.
u8 *const gUnk_08365340 = (u8 *)gText_BlankRow4;
// Its users declare it as u8 *x.
const u32 gUnk_08365344 = (u32)gText_BlankRow32;
