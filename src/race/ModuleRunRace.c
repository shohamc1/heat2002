/*
 * ModuleRunRace: the main race loop. Levers that made it match:
 * - dead `t++; t--;` pairs before each `(u8)t` site give gcse a kill on t,
 *   so PRE does not merge the two lsls/lsrs pairs; DCE removes the pair.
 * - `rrret` is placed out of line by jumping INTO the D5F4 then-arm, and
 *   it reaches the labelled `return 1` (ret1) so jump.c's range swap
 *   ("if (foo) bar; else break;") does not reorder the final return.
 * - `rr` is s32: ARM promotes s8 locals zero-extended, which gives lsrs;
 *   an s32 home keeps the ROM's asrs and cmp on the extended value.
 * - the busy-wait after ModuleExchangeLinkInput is a goto loop: an empty-body
 *   do-while is rotated and duplicate_loop_exit_test adds a pre-test.
 * - the r dispatch is a goto net; see parked.md for the switch findings.
 */
#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u8 gUnk_020391CC;
extern u8 gUnk_02039154;
extern u32 gUnk_020391E0[4];
extern u32 gUnk_02039158;
extern u8 gUnk_020250EC;
extern u8 gUnk_0203921C;
extern u8 gUnk_02039218[4];
extern u8 gUnk_02039160[];
extern u8 gUnk_02039170[];
extern s32 gModule_EngineSoundFreqBases[];
extern u8 gModule_EngineSoundRpmMultipliers[];

u8 ModuleRunRace(u8 isDemo, u8 gameMode, void *unused)
{
    u8 pad[4];
    register u8 *isDemoPtr PIN(r4);
    u32 t;
    u32 r;
    s32 rt;
    s32 i;
    u32 flag;
    struct Car *car;
    s32 t2;
    s32 linkResult;
    u8 first;

    t = gameMode;
    gUnk_02039100 = 0;
    gUnk_020391CC = 0;
    gUnk_02039154 = 0;
    gModule_GameMode = t;
    isDemoPtr = &gModule_IsDemo;
    *isDemoPtr = isDemo;
    if (t != 0xF)
        gModule_NumCars[0] = 5;
    if (gModule_GameMode == 2)
        gModule_NumCars[0] = 1;
    if (gModule_GameMode == 17)
        gModule_NumCars[0] = 1;
    if (gModule_GameMode == 13)
        gModule_NumCars[0] = 1;
    if (gModule_GameMode == 14)
        gModule_NumCars[0] = 1;
    if (*isDemoPtr != 0)
        gModule_NumCars[0] = 2;
    if (gModule_TrackId > 6 && gModule_TrackId != 8 && gModule_TrackId != 9 && gModule_TrackId != 10 &&
        gModule_TrackId != 11)
        gModule_NumCars[0] = 1;
    if ((u8)(gModule_GameMode - 3) <= 1)
        gModule_NumCars[0] = gModule_NumLinkPlayers[0];
    gUnk_020391E0[0] = 0;
    gUnk_020391E0[1] = 0;
    gUnk_020391E0[2] = 0;
    gUnk_020391E0[3] = 0;
    ModuleLoadTrack(gModule_TrackId);
    ModuleLoadTrackSegs(gModule_TrackId);
    ModuleLoadTrackCues(gModule_TrackId);
    ModuleClearRaceTextLayer();
    ModuleSetTrackBgCnt();
    gUnk_02039158 = 0x100;
    ModuleSetFadeDeltasColors240To255(0x32);
    ModuleLoadTrackWalls(gModule_TrackId);
    ModuleInitGfxCaches();
    ModuleInitTasks();
    ModuleResetSpriteOrderTable();
    ModuleClearOamBuffer();
    ModuleUpdateSprites();
    gModule_BgScrollUpdateEnabled = 1;
    (*(volatile s8 *)&gModule_VBlankWorkDone) = 0;
    first = (*(volatile s8 *)&gModule_VBlankWorkDone);
    t -= 3;
    if (first == 0) {
        do
            ;
        while ((*(volatile s8 *)&gModule_VBlankWorkDone) == 0);
    }
    ModuleWaitForVBlank();
    gUnk_020390FC = 0;
    ModuleEnableRaceDisplay();
    if (gModule_GameMode == 14) {
        ModuleInitTimeTrialHud();
    } else {
        ModuleInitRaceHud();
    }
    if (gModule_IsDemo != 0) {
        if (gModule_Options[2] != 0)
            ModuleM4aSongNumStart(1);
        gModule_RaceStarted = 1;
        gUnk_020250EC = 2;
        if (gModule_IsDemo != 0) {
            for (i = 0; i != 100; i++)
                ModuleUpdateAllCars();
            ModuleAddDemoEndTask();
            goto skip42B04;
        }
    }
    if ((u8)(gModule_GameMode - 3) <= 1)
        ModuleInitLinkRaceStart();
skip42B04:
    if (gModule_GameMode == 9 || gModule_GameMode == 13 || gModule_GameMode == 14 || gModule_GameMode == 15 ||
        gModule_GameMode == 17) {
        gUnk_020390B8 = 1;
        for (i = 0; i != 20; i++)
            ModuleUpdateAllCars();
        gUnk_020390B8 = 0;
    }
    gUnk_020390B8 = 0;
    if (gModule_IsLinkRace != 0) {
        ModuleSetCameraTarget(&gModule_Cars[(*(volatile u32 *)REG_ADDR_SIOCNT << 0x1A) >> 0x1E]);
        goto after_d5f4;
    rrret:
        gUnk_02039154 = 1;
        goto ret1;
    after_d5f4:;
    } else {
        ModuleSetCameraTarget(gModule_Cars);
    }
    gModule_Camera[0] = gModule_Camera[2];
    gModule_Camera[1] = gModule_Camera[3];
    gModule_FrameCounter = 0;
    gModule_RaceEndState = 0;
    gUnk_020390C4 = 1;
    t++;
    t--;
    if ((u8)t <= 1)
        ModuleInitMultiplayerSio();
    ModuleM4aSongNumStart(56);
    t++;
    t--;
    gUnk_0203921C = 0;
    gModule_VBlanksThisFrame = 0;
    flag = 0;
    gUnk_02039218[3] = 0;
    gUnk_02039218[2] = 0;
    gUnk_02039218[1] = 0;
    gUnk_02039218[0] = 0;
    while (gUnk_02039154 == 0) {
        ModuleAgeGfxCaches();
        ModuleClearOamBuffer();
        ModuleDrawSpriteText(gUnk_02039160, 75, 60);
        if (gUnk_0203921C != 0)
            ModuleDrawSpriteText(gUnk_02039170, 75, 90);
        gModule_VBlanksThisFrame = 0;
        if ((u8)t > 1)
            car = gModule_Cars;
        else
            car = &gModule_Cars[gModule_LinkPlayerId];
        ModuleM4aMPlayPitchControl(
            &gModule_EngineSoundPlayer, 1, ((s16)(gModule_EngineSoundFreqBases[car->gear] + ((car->rpm * gModule_EngineSoundRpmMultipliers[car->gear]) >> 6))) >> 3);
        if (gModule_IsDemo != 0) {
            ModuleSetCameraTarget(gModule_AiCars);
            gUnk_020250EC = t2 = gModule_FrameCounter / 256;
            if (t2 % 8 == 0)
                gUnk_020250EC = 4;
        } else {
            if (gModule_IsLinkRace != 0)
                ModuleSetCameraTarget(&gModule_Cars[(*(volatile u32 *)REG_ADDR_SIOCNT << 0x1A) >> 0x1E]);
            else
                ModuleSetCameraTarget(gModule_Cars);
            if (gModule_GameMode == 9 || gModule_GameMode == 13 || gModule_GameMode == 14 || gModule_GameMode == 15 ||
                gModule_GameMode == 17) {
                gModule_Camera[0] = gModule_Cars[0].posX;
                gModule_Camera[1] = gModule_Cars[0].posZ;
            }
        }
        ModuleUpdatePaletteFade();
        ModuleSmoothCamera();
        ModuleUpdateCameraScroll();
        ModuleRunTasks();
        ModuleDrawAllCars();
        ModuleDrawLinkFinishTimes();
        if (gModule_RaceStarted != 0 || gModule_GameMode == 9 || gModule_GameMode == 13 || gModule_GameMode == 14 ||
            gModule_GameMode == 15 || gModule_GameMode == 17)
            ModuleUpdateAllCars();
        ModuleUpdateTrackScroll(gModule_Camera[0], gModule_Camera[1]);
        ModuleUpdateSprites();
        ModuleUpdateChallenge();
        gModule_BgScrollUpdateEnabled = 1;
        if (gModule_IsDemo != 0) {
            if (gUnk_0203761C != 0) {
                gUnk_020391CC = 1;
                gModule_RaceEndState = 2;
                ModuleWaitForVBlank();
                REG_DISPCNT &= 0xEFFF;
                if (gModule_Options[2] != 0)
                    ModuleM4aMPlayFadeOut((u32)&gModule_BgMusicPlayer, 2);
                ModuleBeginFadeToColor(25, 0);
            }
        } else {
            if ((u8)(gModule_GameMode - 3) > 1 && gModule_RaceEndState == 0) {
                if (gModule_PaletteFadeActive != 0)
                    goto r_zero;
                r = ModulePauseMenu();
                goto r_ext;
            }
            if (gModule_PaletteFadeActive != 0 || gModule_RaceEndState != 0)
                goto r_zero;
            if (gModule_GameMode == 4)
                r = ModuleSinglePakPauseMenu();
            else
                r = ModuleLinkPauseMenu();
        r_ext:
            rt = (u8)r;
            goto r_tests;
        r_zero:
            rt = 0;
        r_tests:
            if (rt == 1)
                goto r_case1;
            if (rt <= 1)
                goto r_end;
            if (rt == 2)
                goto r_case2;
            if (rt == 39)
                goto r_case27;
            goto r_end;
        r_case1:
            ModuleM4aSongNumStart(56);
            goto r_end;
        r_case2:
            if (gModule_GameMode == 2 || gModule_GameMode == 14 || gModule_GameMode == 0 || gModule_GameMode == 7 ||
                gModule_GameMode == 6 || gModule_GameMode == 9 || gModule_GameMode == 5 || gModule_GameMode == 17 ||
                gModule_GameMode == 1 || gModule_GameMode == 3 || gModule_GameMode == 12 || gModule_GameMode == 13 ||
                gModule_GameMode == 16 || gModule_GameMode == 15 || gModule_GameMode == 17) {
                gUnk_020391CC = 1;
                gModule_RaceEndState = 2;
                ModuleWaitForVBlank();
                REG_DISPCNT &= 0xEFFF;
                ModuleBeginFadeToColor(25, 0);
            }
            goto r_end;
        r_case27:
            flag = 1;
        r_end:;
        }
        if (gModule_IsLinkRace != 0) {
            linkResult = (s8)ModuleExchangeLinkInput();
            if (linkResult != 0)
                goto rrret;
            (*(volatile s8 *)&gModule_VBlankWorkDone) = linkResult;
        wait_ec:
            if ((*(volatile s8 *)&gModule_VBlankWorkDone) == 0)
                goto wait_ec;
        } else {
            (*(volatile s8 *)&gModule_VBlankWorkDone) = 0;
            while ((*(volatile s8 *)&gModule_VBlankWorkDone) == 0)
                ;
        }
        gModule_FrameCounter = gModule_FrameCounter + 1;
        if (gModule_RaceEndState == 2 && gModule_PaletteFadeActive == 0)
            gUnk_02039154 = 1;
    }
    if (flag != 0) {
    ret1:
        return 1;
    }
    ModuleM4aMPlayStop(&gModule_EngineSoundPlayer);
    return 0;
}
