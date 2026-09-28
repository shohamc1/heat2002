#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
extern u16 gSeasonSaveFlag[];
extern u16 gSeasonSaveData[];
extern u16 gUnk_083FECB0[];

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
    *p++ = (*(u8 *)&gSeasonRaceIndex);
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
    } while (i != 0x18);
    i = 0;
    do {
        *p++ = gChampionshipAvailable[i];
        i++;
    } while (i != 0x11);
    *p = gSeasonNumLaps;
    WriteSaveBlocks(0x40, 0xF0);
    WriteSaveBlocks(8, 8);
    sub_080100B0();
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
    (*(u8 *)&gSeasonRaceIndex) = *p++;
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
    } while (i != 0x18);
    i = 0;
    do {
        gChampionshipAvailable[i] = *p++;
        i++;
    } while (i != 0x11);
    gSeasonNumLaps = *p;
    sub_080100B0();
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
    } while (i != 0x0C);
    sub_080100B0();
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
    } while (i != 0x0C);
    WriteSaveBlocks(0x130, 0x48);
    sub_080100B0();
}

void LoadProgress(void)
{
    u8 *p;
    s32 i;
    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0x10, 0x30);
    p = gProgressSaveBuffer;
    i = 0;
    do { gProgressFlags[i] = *p++; i++; } while (i != 0x0A);
    i = 0;
    do { gChallengeCategoryUnlocked[i] = *p++; i++; } while (i != 0x04);
    i = 0;
    do { gChallengeStatus[i] = *p++; i++; } while (i != 0x10);
    i = 0;
    do { gCheatFlags[i] = *p++; i++; } while (i != 0x08);
    i = 0;
    do { gUnk_0202EDC8[i] = *p++; i++; } while (i != 0x04);
    i = 0;
    do { gUnk_0202ED80[i] = *p++; i++; } while (i != 0x04);
    sub_080100B0();
}

void SaveProgress(void)
{
    u8 *p;
    s32 i;
    StopAllSongsAndVSyncOff();
    p = gProgressSaveBuffer;
    i = 0;
    do { *p++ = gProgressFlags[i]; i++; } while (i != 0x0A);
    i = 0;
    do { *p++ = gChallengeCategoryUnlocked[i]; i++; } while (i != 0x04);
    i = 0;
    do { *p++ = gChallengeStatus[i]; i++; } while (i != 0x10);
    i = 0;
    do { *p++ = gCheatFlags[i]; i++; } while (i != 0x08);
    i = 0;
    do { *p++ = gUnk_0202EDC8[i]; i++; } while (i != 0x04);
    i = 0;
    do { *p++ = gUnk_0202ED80[i]; i++; } while (i != 0x04);
    WriteSaveBlocks(0x10, 0x30);
    sub_080100B0();
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
    sub_080100B0();
}

void SaveOptions(void)
{
    u32 i;
    u8 *dst;
    StopAllSongsAndVSyncOff();
    dst = gUnk_0202F1B8;
    for (i = 0; i != 6; i++)
    {
        *dst = gOptions[i];
        dst++;
    }
    WriteSaveBlocks(0xBC << 1, 8);
    sub_080100B0();
}

void FormatSave(void)
{
    u16 *p;
    u8 *q;

    p = (u16 *)&gProgressSaveBuffer[0x120];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
    *p++ = gUnk_083FECB0[0];
    *p++ = gUnk_083FECB0[1];
    *p++ = gUnk_083FECB0[2];
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

u32 IsSaveValid(void)
{
    InitEeprom();
    ReadSaveBlocks(0, 8);
    if (gUnk_0202F040[0] == 0xA482 && gUnk_0202F040[1] == 0x7674)
        return 1;
    return 0;
}
