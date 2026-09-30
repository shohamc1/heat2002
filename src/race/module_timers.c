#include "global.h"
#include "variables.h"

extern u8 gModule_TrackCountdownExtraSeconds[];

void ModuleResetLapTimer(void)
{
    gModule_LapMs[0] = 0;
    gModule_LapSec[0] = 0;
    gModule_LapMin[0] = 0;
}

void ModuleResetRaceTimer(void)
{
    gModule_RaceMs[0] = 0;
    gModule_RaceSec[0] = 0;
    gModule_RaceMin[0] = 0;
}

void ModuleSetCountdownSeconds(u8 seconds)
{
    s32 secondsVal = seconds;

    gModule_CountdownSeconds = secondsVal;
    if (secondsVal > 99)
        gModule_CountdownSeconds = 99;
}

void ModuleInitCountdown(void)
{
    int seconds;
    u8 *trackExtra;

    gModule_CountdownMs = 0;
    gModule_CountdownSeconds = gUnk_0203B6F0;
    gUnk_0203B6E8 = 1;
    if (gModule_GameMode[0] == 0xA)
        gModule_CountdownSeconds = 0x14;
    if (gModule_GameMode[0] == 0) {
        seconds = (u8)(3 - gModule_Options[0]);
        trackExtra = gModule_TrackCountdownExtraSeconds;
        trackExtra += gModule_TrackId;
        seconds += 3;
        gModule_CountdownSeconds = *trackExtra + seconds;
    }
}
