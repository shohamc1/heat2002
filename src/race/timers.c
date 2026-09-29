#include "global.h"
#include "variables.h"

extern u8 gTrackCountdownExtraSeconds[];

void ResetLapTimer(void)
{
    gLapMs[0] = 0;
    gLapSec[0] = 0;
    gLapMin[0] = 0;
}

void ResetRaceTimer(void)
{
    gRaceMs = 0;
    gRaceSec = 0;
    gRaceMin = 0;
}

void SetCountdownSeconds(u8 seconds)
{
    gCountdownSeconds = seconds;
    if (gCountdownSeconds > 0x63)
        gCountdownSeconds = 0x63;
}

void InitCountdown(void)
{
    u32 mode;
    u32 seconds;
    u8 *extraSeconds;
    u8 *trackExtra;

    gCountdownMs = 0;
    gCountdownSeconds = gDefaultCountdownSeconds;
    gUnk_02025238 = 1;
    mode = gGameMode[0];
    if (mode == 0xA)
        gCountdownSeconds = 0x14;
    if (mode == 0) {
        seconds = (u8)(3 - gOptions[0]);
        extraSeconds = gTrackCountdownExtraSeconds;
        trackExtra = extraSeconds + gTrackId;
        seconds += 3;
        gCountdownSeconds = *trackExtra + seconds;
    }
}
