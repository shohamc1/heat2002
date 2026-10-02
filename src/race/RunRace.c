#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

extern u8 gUnk_08364ADC;                          /* 0x08364ADC */
extern u32 gEngineSoundFreqBases[];               /* 0x08364AE0 */
extern u8 gEngineSoundRpmMultipliers[];           /* 0x08364AF4 */
extern u8 gText_BlankRow16[];                     /* 0x0806C678 */

extern u8 gExitRaceLoop;                          /* 0x02002144 */
extern u8 gUnk_02002150[0xC];                     /* 0x02002150 */
extern u8 gUnk_02002160[0xC];                     /* 0x02002160 */
extern u32 gUnk_020021D0[0x4];                    /* 0x020021D0 */
extern u8 gUnk_020021EC[0x4];                     /* 0x020021EC */
extern u8 gUnk_020021F0;                          /* 0x020021F0 */

/* The cancelling offset gives the destination address an earlier quantity,
   selecting the ROM's r3/r4 allocation without emitting extra code. */
u8 RunRace(u32 a, u8 b, void *unused)
{
    /* The ROM reserves an otherwise unused stack word. */
    u8 buf[4];
    u32 i;
    struct Car *p;
    s32 res;
    u8 flag;
    s32 v;
    s32 t;
    u32 off;
    u8 *dest;

    gNewTrackRecord = 0;
    gRaceAborted = 0;
    gExitRaceLoop = 0;
    gGameMode = b;
    off = a;
    dest = (u8 *)((u8 *)&gIsDemo + off - a);
    *dest = a;
    if (b != 0x0F)
        gNumCars[0] = 0x18;
    if (gGameMode == 2)
        gNumCars[0] = 1;
    if (gGameMode == 17)
        gNumCars[0] = 1;
    if (gGameMode == 13)
        gNumCars[0] = 1;
    if (gGameMode == 14)
        gNumCars[0] = 1;
    if (gIsDemo != 0)
        gNumCars[0] = 2;
    if (gTrackId > 6 && gTrackId != 8 && gTrackId != 9 && gTrackId != 10 && gTrackId != 11)
        gNumCars[0] = 1;
    if (gGameMode == 3 || gGameMode == 4)
        gNumCars[0] = gNumLinkPlayers[0];
    gUnk_020021D0[0] = 0;
    gUnk_020021D0[1] = 0;
    gUnk_020021D0[2] = 0;
    gUnk_020021D0[3] = 0;
    LoadTrack(gTrackId);
    LoadTrackSegs(gTrackId);
    LoadTrackCues(gTrackId);
    ClearRaceTextLayer();
    SetTrackBgCnt();
    gUnk_02002148 = 0x100;
    SetFadeDeltasColors240To255(0x32);
    LoadTrackWalls(gTrackId);
    InitGfxCaches();
    InitTasks();
    ResetSpriteOrderTable();
    ClearOamBuffer();
    UpdateSprites();
    gBgScrollUpdateEnabled = 1;
#if PORTABLE
    /* The GBA's VBlank interrupt arrives from hardware mid-spin; the
       hosted build dispatches it only from the frame pump, so the spin
       pumps a VBlank per pass (HOST_WAIT_VBLANK, functions.h). */
    HOST_WAIT_VBLANK();
#else
    (*(vu8 *)&gVBlankWorkDone) = 0;
    while ((*(vu8 *)&gVBlankWorkDone) == 0)
        ;
#endif
    WaitForVBlank();
    gUnk_020020EC = 0;
    EnableRaceDisplay();
    if (gGameMode == 14)
        InitTimeTrialHud();
    else
        InitRaceHud();
    if (gIsDemo != 0) {
        if (gOptions[2] != 0)
            m4aSongNumStart(1);
        gRaceStarted = 1;
#if PORTABLE
        /* gUnk_08364ADC is cartridge ROM at 0x08364ADC: the GBA drops
           this store, and no code reads the byte back (the live, writable
           twin is the high module's EWRAM gUnk_020250EC,
           src/data/module_race_data.c). The hosted build holds it as
           const data, so the dead store is skipped there. */
#else
        gUnk_08364ADC = 2;
#endif
    }
    if (gIsDemo != 0) {
        for (i = 0; i != 100; i++)
            UpdateAllCars();
        AddDemoEndTask();
    } else if (gGameMode == 3 || gGameMode == 4) {
        InitLinkRaceStart();
    }
    if (gGameMode != 9 && gGameMode != 2 && gGameMode != 7 && gIsDemo == 0 && gOptions[3] != 0)
        m4aSongNumStart(30);
    if (gIsDemo == 0)
        StopAllSongsAtRaceStart();
    if (gGameMode == 9 || gGameMode == 13 || gGameMode == 14 || gGameMode == 15 || gGameMode == 17) {
        gPreRaceSimActive = 1;
        for (i = 0; i != 20; i++)
            UpdateAllCars();
        gPreRaceSimActive = 0;
    }
    gPreRaceSimActive = 0;
    if (gIsLinkRace != 0) {
        SetCameraTarget(&gCars[(*(volatile u32 *)REG_ADDR_SIOCNT << 26) >> 30]);
        goto camera_ready;
    connection_error:
        gExitRaceLoop = 1;
        goto success;
    } else
        SetCameraTarget(&gCars[0]);
camera_ready:
    gCamera[0] = gCamera[2];
    gCamera[1] = gCamera[3];
    gFrameCounter = 0;
    gRaceEndState = 0;
    gUnk_020020B4 = 1;
    if (b == 3 || b == 4)
        InitMultiplayerSio();
    if (gOptions[3] != 0 && gIsDemo == 0)
        m4aSongNumStart(10);
    gUnk_020021F0 = 0;
    gVBlankCounter = 0;
    flag = 0;
    gUnk_020021EC[3] = 0;
    gUnk_020021EC[2] = 0;
    gUnk_020021EC[1] = 0;
    gUnk_020021EC[0] = 0;
    while (gExitRaceLoop == 0) {
        AgeGfxCaches();
        ClearOamBuffer();
        DrawSpriteText(gUnk_02002150, 75, 60);
        if (gUnk_020021F0 != 0)
            DrawSpriteText(gUnk_02002160, 75, 90);
        gVBlankCounter = 0;
        if (b != 3 && b != 4)
            p = &gCars[0];
        else
            p = &gCars[gLinkPlayerId];
        m4aMPlayPitchControl(
            &gEngineSoundPlayer, 1,
            (s16)(gEngineSoundFreqBases[p->gear] + ((p->rpm * gEngineSoundRpmMultipliers[p->gear]) >> 6)) >> 3);
        if (gIsDemo != 0) {
            SetCameraTarget(gAiCars);
#if PORTABLE
            /* As the race-start store above: both writes land in cartridge
           ROM (0x08364ADC), which the GBA drops, and nothing reads the
           byte back, so the hosted build skips them. */
#else
            gUnk_08364ADC = t = gFrameCounter / 256;
            if ((t & 7) == 0)
                gUnk_08364ADC = 4;
#endif
        } else {
            if (gIsLinkRace != 0)
                SetCameraTarget(&gCars[(*(volatile u32 *)REG_ADDR_SIOCNT << 26) >> 30]);
            else
                SetCameraTarget(&gCars[0]);
            if (gGameMode == 9 || gGameMode == 13 || gGameMode == 14 || gGameMode == 15 || gGameMode == 17) {
                gCamera[0] = gCars[0].posX;
                gCamera[1] = gCars[0].posZ;
            }
        }
        UpdatePaletteFade();
        SmoothCamera();
        UpdateCameraScroll();
        RunTasks();
        DrawAllCars();
        if (gGameMode == 4)
            DrawLinkFinishTimes();
        if (gRaceStarted != 0 || gGameMode == 9 || gGameMode == 13 || gGameMode == 14 || gGameMode == 15 ||
            gGameMode == 17)
            UpdateAllCars();
        UpdateTrackScroll(gCamera[0], gCamera[1]);
        if (gGameMode == 9 || gGameMode == 13 || gGameMode == 14 || gGameMode == 15 || gGameMode == 17) {
            if ((gFrameCounter & 8) == 0)
                DrawTextCentered(GetString(93), 8, 1);
            else
                DrawTextCentered(gText_BlankRow16, 8, 1);
        }
        UpdateSprites();
        UpdateChallenge();
        gBgScrollUpdateEnabled = 1;
        if (gIsDemo != 0) {
            if (gKeysPressed != 0) {
                gRaceAborted = 1;
                gRaceEndState = 2;
                WaitForVBlank();
                REG_DISPCNT &= ~DISPCNT_OBJ_ON;
                if (gOptions[2] != 0)
                    m4aMPlayFadeOut(&gBgMusicPlayer, 2);
                BeginFadeToColor(25, 0);
            }
        } else {
            if (gGameMode != 3 && gGameMode != 4 && gRaceEndState == 0) {
                if (gFadeActive == 0)
                    res = PauseMenu();
                else
                    res = 0;
            } else {
                if (gFadeActive == 0 && gRaceEndState == 0) {
                    if (gGameMode == 4)
                        res = SinglePakPauseMenu();
                    else
                        res = LinkPauseMenu();
                } else {
                    res = 0;
                }
            }
            switch (res) {
                case 0:
                    break;
                case 1:
                    if (gOptions[3] != 0 && gIsDemo == 0)
                        m4aSongNumStart(10);
                    break;
                case 2:
                    if (gGameMode == 2 || gGameMode == 14 || gGameMode == 0 || gGameMode == 7 || gGameMode == 6 ||
                        gGameMode == 9 || gGameMode == 5 || gGameMode == 17 || gGameMode == 1 || gGameMode == 3 ||
                        gGameMode == 12 || gGameMode == 13 || gGameMode == 16 || gGameMode == 15 || gGameMode == 17) {
                        gRaceAborted = 1;
                        gRaceEndState = 2;
                        WaitForVBlank();
                        REG_DISPCNT &= ~DISPCNT_OBJ_ON;
                        m4aMPlayStop(&gMPlayInfo_SE2);
                        m4aMPlayStop(&gMPlayInfo_SE3);
                        m4aMPlayStop(&gMPlayInfo_SE4);
                        BeginFadeToColor(25, 0);
                    }
                    break;
                case 39:
                    flag = 1;
                    break;
            }
        }
        if (gIsLinkRace != 0) {
            v = (s8)ExchangeLinkInput();
            if (v != 0) {
                goto connection_error;
            }
            (*(vu8 *)&gVBlankWorkDone) = v;
#if PORTABLE
            /* The same spin as HOST_WAIT_VBLANK minus the re-zero:
               ExchangeLinkInput's return already staged the flag. */
            while ((*(vu8 *)&gVBlankWorkDone) == 0)
                VBlankIntrWait();
#else
        wait_link:
            if ((*(vu8 *)&gVBlankWorkDone) == 0)
                goto wait_link;
#endif
        } else {
#if PORTABLE
            /* As the race-start spin above: the hosted build must pump
               the frame for the VBlank callback that sets the flag. */
            HOST_WAIT_VBLANK();
#else
            (*(vu8 *)&gVBlankWorkDone) = 0;
            while ((*(vu8 *)&gVBlankWorkDone) == 0)
                ;
#endif
        }
        gFrameCounter++;
        if (gRaceEndState == 2 && gFadeActive == 0)
            gExitRaceLoop = 1;
    }
    if (flag != 0) {
    success:
        return 1;
    }
    m4aMPlayStop(&gEngineSoundPlayer);
    return 0;
}
