#include "global.h"
#include "gba/defines.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u16 gSaveFormatFillPattern[];

/* This file owns the merged menu/link/save EWRAM run 0x0202ED70-0x0202F1C0
   (issue 5 step 3, run rule: runs 19 and 20 interleave, so one owner).
   Every identified variable in the span is defined here in address order;
   the static gap arrays pad only the addresses no identified symbol
   covers. That includes the dead-only symbols src/dead/sub_08014B14.c
   and sub_0800B030.c reach (gUnk_0202EDC0, gUnk_0202EDCC, gUnk_0202EDE0,
   gUnk_0202EEE0, gUnk_0202EEF0 and gUnk_0202F02C: defined here with the
   types their dead users declare, no symbols.ld lines left).
   ldscript.ld's .bss_save places the section at 0x0202ED70.

   Variables moved here from their old owners (definitions unchanged):
   src/menu/MainMenuLoop.c (the menu state from gChallengeIndex through
   gSeasonRaceIncomplete), src/link/ExchangeLinkInput.c (gLinkSendWords),
   src/link/link_state.c (the link state), src/race/challenge.c
   (gUnk_0202EED0, gCarOrder) and src/race/UpdateLapProgress.c
   (gChallengeResult), plus the symbols.ld lines the run covered, now
   deleted. gUnk_0202EDF0 is the colour-cycle palette buffer
   (sub_08010768 CpuSets from it to PLTT), bounded by gDamagePitsEnabled
   at 0x0202EEB0; gCarOrder holds one pointer per car (24, gNumCars'
   maximum) and ends at gSeasonRaceIndex. From gUnk_0202F040 on, the
   variables are views into the one EEPROM staging buffer that
   ReadSaveBlocks/WriteSaveBlocks fill (they index it from its base), so
   the run 0x0202F040..0x0202F1C0 is contiguous: gSeasonSaveFlag is the
   buffer's offset-8 flag block (gUnk_0202F040[5]), gSeasonSaveData its
   0xF0-byte season block, and writes through one view land in the next.
   gCheatCodeDials is the cheat screen's five dials (src/dead's password
   check reads [0..4]); gChampionshipAvailable holds one flag per
   championship cup; gChallengeStatus one s8 score per challenge;
   gProgressFlags the ten career progress bytes InitNewSaveData fills. gCheatFlags is the
   save file's eight cheat bytes (LoadProgress/SaveProgress loop i != 8;
   it was sized 0x10 before, which overlapped gPracticeDone at 0x0202EEC8
   -- a pre-consolidation overlap this file now resolves). */
EWRAM_DATA u8 gChallengeIndex = 0;
static EWRAM_DATA u8 save_gapED71[0x7] = {0};
EWRAM_DATA u16 gLinkSendWords[4] = {0};
EWRAM_DATA u8 gUnk_0202ED80[0x4] = {0};
EWRAM_DATA u32 gUnk_0202ED84 = 0;
static EWRAM_DATA u8 save_gapED88[0x28] = {0};
EWRAM_DATA u8 gCheatCodeWasValid = 0;
static EWRAM_DATA u8 save_gapEDB1[0x3] = {0};
EWRAM_DATA u8 gUnk_0202EDB4 = 0;
static EWRAM_DATA u8 save_gapEDB5[0x7] = {0};
EWRAM_DATA u32 gUnk_0202EDBC = 0;
EWRAM_DATA u32 gUnk_0202EDC0 = 0;
static EWRAM_DATA u8 save_gapEDC4[0x4] = {0};
EWRAM_DATA u8 gUnk_0202EDC8[0x4] = {0};
EWRAM_DATA u8 gUnk_0202EDCC = 0;
static EWRAM_DATA u8 save_gapEDCD[0x3] = {0};
EWRAM_DATA u8 gLinkSyncByte = 0;
static EWRAM_DATA u8 save_gapEDD1[0x3] = {0};
EWRAM_DATA s32 gMainMenuCursor = 0;
EWRAM_DATA u8 gChampionshipIndex = 0;
static EWRAM_DATA u8 save_gapEDD9[0x7] = {0};
EWRAM_DATA u8 gUnk_0202EDE0 = 0;
static EWRAM_DATA u8 save_gapEDE1[0x3] = {0};
EWRAM_DATA u32 gUnk_0202EDE4 = 0;
static EWRAM_DATA u8 save_gapEDE8[0x8] = {0};
EWRAM_DATA u16 gUnk_0202EDF0[0x60] = {0};
EWRAM_DATA u8 gDamagePitsEnabled = 0;
static EWRAM_DATA u8 save_gapEEB1[0x3] = {0};
EWRAM_DATA u8 gCheatMsgBlinkTimer = 0;
static EWRAM_DATA u8 save_gapEEB5[0xB] = {0};
EWRAM_DATA u8 gCheatFlags[0x8] = {0};
EWRAM_DATA u8 gPracticeDone = 0;
static EWRAM_DATA u8 save_gapEEC9[0x7] = {0};
EWRAM_DATA u8 gUnk_0202EED0 = 0;
static EWRAM_DATA u8 save_gapEED1[0x3] = {0};
EWRAM_DATA u8 gUnk_0202EED4 = 0;
static EWRAM_DATA u8 save_gapEED5[0x3] = {0};
EWRAM_DATA u8 gTrackSelectFrameCount = 0;
static EWRAM_DATA u8 save_gapEED9[0x7] = {0};
EWRAM_DATA u8 gUnk_0202EEE0 = 0;
static EWRAM_DATA u8 save_gapEEE1[0x3] = {0};
EWRAM_DATA u8 gChallengeResult = 0;
static EWRAM_DATA u8 save_gapEEE5[0xB] = {0};
EWRAM_DATA u8 gUnk_0202EEF0 = 0;
static EWRAM_DATA u8 save_gapEEF1[0x3] = {0};
EWRAM_DATA u8 gLinkPlayerCount = 0;
static EWRAM_DATA u8 save_gapEEF5[0x3] = {0};
EWRAM_DATA u8 gSeasonSession = 0;
static EWRAM_DATA u8 save_gapEEF9[0x3] = {0};
EWRAM_DATA u8 gUnk_0202EEFC = 0;
static EWRAM_DATA u8 save_gapEEFD[0x3] = {0};
EWRAM_DATA u8 gOptions[0x8] = {0};
EWRAM_DATA u8 gChallengeCategoryUnlocked[0x8] = {0};
EWRAM_DATA u8 gSeasonNumLaps = 0;
static EWRAM_DATA u8 save_gapEF11[0x3] = {0};
EWRAM_DATA u8 gChallengeCategorySelected = 0;
static EWRAM_DATA u8 save_gapEF15[0xB] = {0};
#if PORTABLE
/* Hosted: 0x11 entries. MainMenuLoop zeroes and sets indices up to 0x10
   and SaveSeason/LoadSeason walk [0..0x10]; the GBA run pads the 17th
   championship byte into the gap that follows the 0x10-entry array. */
EWRAM_DATA u8 gChampionshipAvailable[0x11] = {0};
#else
EWRAM_DATA u8 gChampionshipAvailable[0x10] = {0};
#endif
static EWRAM_DATA u8 save_gapEF30[0x10] = {0};
EWRAM_DATA u16 gLinkRecvWords[16] = {0};
EWRAM_DATA u8 gChallengeStatus[0x10] = {0};
static EWRAM_DATA u8 save_gapEF70[0x8] = {0};
EWRAM_DATA u8 gCheatCodeDials[0x5] = {0};
static EWRAM_DATA u8 save_gapEF7D[0x3] = {0};
EWRAM_DATA u8 gProgressFlags[0xA] = {0};
static EWRAM_DATA u8 save_gapEF8A[0x2] = {0};
EWRAM_DATA s8 gTrackSelectCursor = 0;
static EWRAM_DATA u8 save_gapEF8D[0x3] = {0};
EWRAM_DATA u8 gLinkPlayerId = 0;
static EWRAM_DATA u8 save_gapEF91[0x3] = { 0 };
static EWRAM_DATA u8 save_gapEF94[0xC] = {0};
EWRAM_DATA u8 gLinkPlayerSlots[16] = {0};
EWRAM_DATA u8 gMenuValueChanged = 0;
static EWRAM_DATA u8 save_gapEFB1[0xF] = {0};
EWRAM_DATA struct Car *gCarOrder[0x18] = {0};
EWRAM_DATA u8 gSeasonRaceIndex[0x4] = {0};
EWRAM_DATA u8 gQualifyingDone = 0;
static EWRAM_DATA u8 save_gapF025[0x7] = {0};
EWRAM_DATA u8 gUnk_0202F02C = 0;
static EWRAM_DATA u8 save_gapF02D[0x3] = {0};
EWRAM_DATA u8 gIsTimeTrial = 0;
static EWRAM_DATA u8 save_gapF031[0x3] = {0};
EWRAM_DATA u8 gSeasonRaceIncomplete = 0;
static EWRAM_DATA u8 save_gapF035[0xB] = {0};
#if PORTABLE
/* Hosted: the EEPROM staging run 0x0202F040-0x0202F1C0 is one buffer,
   because the game indexes across its views (WriteSaveBlocks walks
   &gUnk_0202F040[a/2] up to a = 0x178, IsSeasonSaved reads
   gUnk_0202F040[5], SaveSeason walks a pointer from gSeasonSaveFlag
   into the season block). The GBA build keeps the run's separate
   address-placed arrays; include/variables.h aliases each view into
   this buffer at its GBA offset, so every access stays in bounds
   without changing any GBA-visible structure. 0xC0 u16s = the run's
   0x180 bytes. */
EWRAM_DATA u16 gSaveStaging[0xC0] = {0};
#else
EWRAM_DATA u16 gUnk_0202F040[0x5] = {0};
EWRAM_DATA u16 gSeasonSaveFlag[0x3] = {0};
EWRAM_DATA u8 gProgressSaveBuffer[0x30] = {0};
EWRAM_DATA u16 gSeasonSaveData[0x78] = {0};
EWRAM_DATA u16 gUnk_0202F170[0x24] = {0};
EWRAM_DATA u8 gUnk_0202F1B8[0x8] = {0};
#endif

u32 IsSeasonSaved(void)
{
    u32 saveOffset = 8;
    u32 byteCount = 8;

    ReadSaveBlocks(saveOffset, byteCount);
    if (gUnk_0202F040[5] != 0)
        return 1;
    return 0;
}

void SaveSeason(void)
{
    u16 *p;
    s32 i;
    struct Car *q;
    u32 t;

    StopAllSongsAndVSyncOff();
    p = gSeasonSaveFlag;
    *p = 1;
    p += 27;
    *p++ = gSeasonRaceIndex[0];
    *p++ = (gQualifyingDone << 8) | gPracticeDone;
    *p++ = gSeasonRaceIncomplete;
    *p++ = gChampionshipIndex;
    q = gCars;
    i = 0;
    do {
        *p++ = q->driverId;
        *p++ = q->points;
        t = q->finishTime;
        *p++ = t >> 16;
        *p++ = t;
        i++;
        q++;
    } while (i != 24);
    i = 0;
    do {
        *p++ = gChampionshipAvailable[i];
        i++;
    } while (i != 17);
    *p = gSeasonNumLaps;
    WriteSaveBlocks(0x40, 0xF0);
    WriteSaveBlocks(8, 8);
    StartMenuMusic();
}

void LoadSeason(void)
{
    struct Car *q;
    u16 *p;
    u32 t;
    s32 i;
    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0x40, 0xF0);
    p = gSeasonSaveData;
    gSeasonRaceIndex[0] = *p++;
    gQualifyingDone = *p >> 8;
    gPracticeDone = *p++;
    gSeasonRaceIncomplete = *p++;
    gChampionshipIndex = *p++;
    q = gCars;
    i = 0;
    do {
        q->driverId = *p++;
        q->points = *p++;
        q->finishTime = (*p++ << 16);
        q->finishTime |= *p++;
        i++;
        q++;
    } while (i != 24);
    i = 0;
    do {
        gChampionshipAvailable[i] = *p++;
        i++;
    } while (i != 17);
    gSeasonNumLaps = *p;
    StartMenuMusic();
}

void LoadTrackRecords(void)
{
    u16 *src;
    s32 i;
    u16 *d4;
    u16 *d3;
    u16 *d2;
    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0x130, 0x48);
    src = gUnk_0202F170;
    i = 0;
    d4 = gTrackRecordMs;
    d3 = gTrackRecordSec;
    d2 = gTrackRecordMin;
    do {
        *d2 = *src++;
        *d3 = *src++;
        *d4 = *src++;
        d4++;
        d3++;
        d2++;
        i++;
    } while (i != 12);
    StartMenuMusic();
}

void SaveTrackRecords(void)
{
    u16 *dst;
    s32 i;
    u16 *s4;
    u16 *s3;
    u16 *s2;
    StopAllSongsAndVSyncOff();
    dst = gUnk_0202F170;
    i = 0;
    s4 = gTrackRecordMs;
    s3 = gTrackRecordSec;
    s2 = gTrackRecordMin;
    do {
        *dst++ = *s2;
        *dst++ = *s3;
        *dst++ = *s4;
        s4++;
        s3++;
        s2++;
        i++;
    } while (i != 12);
    WriteSaveBlocks(0x130, 0x48);
    StartMenuMusic();
}

void LoadProgress(void)
{
    u8 *p;
    s32 i;
    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0x10, 0x30);
    p = gProgressSaveBuffer;
    i = 0;
    do {
        gProgressFlags[i] = *p++;
        i++;
    } while (i != 10);
    i = 0;
    do {
        gChallengeCategoryUnlocked[i] = *p++;
        i++;
    } while (i != 4);
    i = 0;
    do {
        gChallengeStatus[i] = *p++;
        i++;
    } while (i != 0x10);
    i = 0;
    do {
        gCheatFlags[i] = *p++;
        i++;
    } while (i != 8);
    i = 0;
    do {
        gUnk_0202EDC8[i] = *p++;
        i++;
    } while (i != 4);
    i = 0;
    do {
        gUnk_0202ED80[i] = *p++;
        i++;
    } while (i != 4);
    StartMenuMusic();
}

void SaveProgress(void)
{
    u8 *p;
    s32 i;
    StopAllSongsAndVSyncOff();
    p = gProgressSaveBuffer;
    i = 0;
    do {
        *p++ = gProgressFlags[i];
        i++;
    } while (i != 10);
    i = 0;
    do {
        *p++ = gChallengeCategoryUnlocked[i];
        i++;
    } while (i != 4);
    i = 0;
    do {
        *p++ = gChallengeStatus[i];
        i++;
    } while (i != 0x10);
    i = 0;
    do {
        *p++ = gCheatFlags[i];
        i++;
    } while (i != 8);
    i = 0;
    do {
        *p++ = gUnk_0202EDC8[i];
        i++;
    } while (i != 4);
    i = 0;
    do {
        *p++ = gUnk_0202ED80[i];
        i++;
    } while (i != 4);
    WriteSaveBlocks(0x10, 0x30);
    StartMenuMusic();
}

void LoadOptions(void)
{
    u8 *src;
    u32 i;

    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0xBC * 2, 8);
    src = gUnk_0202F1B8;
    for (i = 0; i != 6; i++) {
        gOptions[i] = *src++;
    }
    StartMenuMusic();
}

void SaveOptions(void)
{
    u32 i;
    u8 *dst;
    StopAllSongsAndVSyncOff();
    dst = gUnk_0202F1B8;
    for (i = 0; i != 6; i++) {
        *dst = gOptions[i];
        dst++;
    }
    WriteSaveBlocks(0xBC << 1, 8);
    StartMenuMusic();
}

void FormatSave(void)
{
    u16 *p;
    u8 *q;

    p = (u16 *)&gProgressSaveBuffer[0x120];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    *p++ = gSaveFormatFillPattern[0];
    *p++ = gSaveFormatFillPattern[1];
    *p++ = gSaveFormatFillPattern[2];
    WriteSaveBlocks(0x130, 0x48);
    p = (u16 *)gProgressSaveBuffer;
    q = (u8 *)p;
    *q++ = 1;
    *q++ = 1;
    *q++ = 1;
    *q++ = 1;
    *q++ = 1;
    *q++ = 0;
    *q++ = 1;
    *q++ = 1;
    *q++ = 1;
    *q++ = 1;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    *q++ = 0;
    WriteSaveBlocks(0x10, 0x30);
    p -= 4;
    *p++ = 1;
    *p++ = 0;
    *p++ = 1;
    *p++ = 0;
    WriteSaveBlocks(8, 8);
    p = (u16 *)(q - 0x2E);
    *p++ = 0xA482;
    *p++ = 0x7674;
    WriteSaveBlocks(0, 8);
}

u8 IsSaveValid(void)
{
    InitEeprom();
    ReadSaveBlocks(0, 8);
    if (gUnk_0202F040[0] == 0xA482 && gUnk_0202F040[1] == 0x7674)
        return 1;
    return 0;
}
