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
extern s32 gUnk_02025190[];
extern u8 gUnk_020251A4[];
extern u8 gUnk_0203D6B0[];

void ModuleLoadTrack(u8);
void ModuleLoadTrackCues(u8);
void ModuleClearRaceTextLayer(void);
void ModuleSetTrackBgCnt(void);
void ModuleSetFadeDeltasColors240To255(s32);
void ModuleLoadTrackWalls(u32);
void ModuleLoadTrackSegs(u32);
void ModuleInitGfxCaches(void);
void ModuleInitTasks(void);
void ModuleResetSpriteOrderTable(void);
void ModuleClearOamBuffer(void);
void ModuleUpdateSprites(void);
void ModuleEnableRaceDisplay(void);
void ModuleInitTimeTrialHud(void);
void ModuleInitRaceHud(void);
void ModuleM4aSongNumStart(u16);
void ModuleUpdateAllCars(void);
void ModuleAddDemoEndTask(void);
void ModuleInitLinkRaceStart(void);
void ModuleSetCameraTarget(struct Car *car);
void ModuleInitMultiplayerSio(void);
void ModuleM4aMPlayPitchControl(struct MusicPlayerInfo *, u16, s16);
void ModuleUpdatePaletteFade(void);
void ModuleSmoothCamera(void);
void ModuleUpdateCameraScroll(void);
void ModuleRunTasks(void);
void ModuleDrawAllCars(void);
void ModuleDrawLinkFinishTimes(void);
void ModuleUpdateTrackScroll(u32, u32);
void ModuleUpdateChallenge(void);
void ModuleM4aMPlayFadeOut(u32, u16);
u32 ModulePauseMenu(void);
u32 ModuleSinglePakPauseMenu(void);
u32 ModuleLinkPauseMenu(void);
s8 ModuleExchangeLinkInput(void);
void ModuleAgeGfxCaches(void);

s32 ModuleRunRace(u8 isDemo, u8 gameMode)
{
    u8 pad[4];
    register u8 *isDemoPtr asm("r4");
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
    gModule_GameMode[0] = t;
    isDemoPtr = &gModule_IsDemo[0];
    *isDemoPtr = isDemo;
    if (t != 0xF)
        gModule_NumCars[0] = 5;
    if (gModule_GameMode[0] == 2)
        gModule_NumCars[0] = 1;
    if (gModule_GameMode[0] == 0x11)
        gModule_NumCars[0] = 1;
    if (gModule_GameMode[0] == 0xD)
        gModule_NumCars[0] = 1;
    if (gModule_GameMode[0] == 0xE)
        gModule_NumCars[0] = 1;
    if (*isDemoPtr != 0)
        gModule_NumCars[0] = 2;
    if (gModule_TrackId > 6 && gModule_TrackId != 8 && gModule_TrackId != 9 && gModule_TrackId != 0xA &&
        gModule_TrackId != 0xB)
        gModule_NumCars[0] = 1;
    if ((u8)(gModule_GameMode[0] - 3) <= 1)
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
    gUnk_020391D4 = 1;
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
    if (gModule_GameMode[0] == 0xE) {
        ModuleInitTimeTrialHud();
    } else {
        ModuleInitRaceHud();
    }
    if (gModule_IsDemo[0] != 0) {
        if (gModule_Options[2] != 0)
            ModuleM4aSongNumStart(1);
        gModule_RaceStarted = 1;
        gUnk_020250EC = 2;
        if (gModule_IsDemo[0] != 0) {
            for (i = 0; i != 100; i++)
                ModuleUpdateAllCars();
            ModuleAddDemoEndTask();
            goto skip42B04;
        }
    }
    if ((u8)(gModule_GameMode[0] - 3) <= 1)
        ModuleInitLinkRaceStart();
skip42B04:
    if (gModule_GameMode[0] == 9 || gModule_GameMode[0] == 0xD || gModule_GameMode[0] == 0xE ||
        gModule_GameMode[0] == 0xF || gModule_GameMode[0] == 0x11) {
        gUnk_020390B8 = 1;
        for (i = 0; i != 20; i++)
            ModuleUpdateAllCars();
        gUnk_020390B8 = 0;
    }
    gUnk_020390B8 = 0;
    if (gModule_IsLinkRace != 0) {
        ModuleSetCameraTarget(&gModule_Cars[(*(volatile u32 *)0x04000128 << 0x1A) >> 0x1E]);
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
    ModuleM4aSongNumStart(0x38);
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
        ModuleDrawSpriteText(gUnk_02039160, 0x4B, 0x3C);
        if (gUnk_0203921C != 0)
            ModuleDrawSpriteText(gUnk_02039170, 0x4B, 0x5A);
        gModule_VBlanksThisFrame = 0;
        if ((u8)t > 1)
            car = gModule_Cars;
        else
            car = &gModule_Cars[gModule_LinkPlayerId];
        ModuleM4aMPlayPitchControl(
            &gUnk_02038FB0, 1, ((s16)(gUnk_02025190[car->gear] + ((car->rpm * gUnk_020251A4[car->gear]) >> 6))) >> 3);
        if (gModule_IsDemo[0] != 0) {
            ModuleSetCameraTarget((struct Car *)gUnk_0203D6B0);
            gUnk_020250EC = t2 = gModule_FrameCounter / 256;
            if (t2 % 8 == 0)
                gUnk_020250EC = 4;
        } else {
            if (gModule_IsLinkRace != 0)
                ModuleSetCameraTarget(&gModule_Cars[(*(volatile u32 *)0x04000128 << 0x1A) >> 0x1E]);
            else
                ModuleSetCameraTarget(gModule_Cars);
            if (gModule_GameMode[0] == 9 || gModule_GameMode[0] == 0xD || gModule_GameMode[0] == 0xE ||
                gModule_GameMode[0] == 0xF || gModule_GameMode[0] == 0x11) {
                gModule_Camera[0] = *(u32 *)&gModule_Cars[0];
                gModule_Camera[1] = *(u32 *)((u8 *)&gModule_Cars[0] + 8);
            }
        }
        ModuleUpdatePaletteFade();
        ModuleSmoothCamera();
        ModuleUpdateCameraScroll();
        ModuleRunTasks();
        ModuleDrawAllCars();
        ModuleDrawLinkFinishTimes();
        if (gModule_RaceStarted != 0 || gModule_GameMode[0] == 9 || gModule_GameMode[0] == 0xD ||
            gModule_GameMode[0] == 0xE || gModule_GameMode[0] == 0xF || gModule_GameMode[0] == 0x11)
            ModuleUpdateAllCars();
        ModuleUpdateTrackScroll(gModule_Camera[0], gModule_Camera[1]);
        ModuleUpdateSprites();
        ModuleUpdateChallenge();
        gUnk_020391D4 = 1;
        if (gModule_IsDemo[0] != 0) {
            if (gUnk_0203761C != 0) {
                gUnk_020391CC = 1;
                gModule_RaceEndState = 2;
                ModuleWaitForVBlank();
                *(volatile u16 *)0x04000000 &= 0xEFFF;
                if (gModule_Options[2] != 0)
                    ModuleM4aMPlayFadeOut((u32)&gUnk_02038F70, 2);
                ModuleBeginFadeToColor(0x19, 0);
            }
        } else {
            if ((u8)(gModule_GameMode[0] - 3) > 1 && gModule_RaceEndState == 0) {
                if (gModule_PaletteFadeActive != 0)
                    goto r_zero;
                r = ModulePauseMenu();
                goto r_ext;
            }
            if (gModule_PaletteFadeActive != 0 || gModule_RaceEndState != 0)
                goto r_zero;
            if (gModule_GameMode[0] == 4)
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
            if (rt == 0x27)
                goto r_case27;
            goto r_end;
        r_case1:
            ModuleM4aSongNumStart(0x38);
            goto r_end;
        r_case2:
            if (gModule_GameMode[0] == 2 || gModule_GameMode[0] == 0xE || gModule_GameMode[0] == 0 ||
                gModule_GameMode[0] == 7 || gModule_GameMode[0] == 6 || gModule_GameMode[0] == 9 ||
                gModule_GameMode[0] == 5 || gModule_GameMode[0] == 0x11 || gModule_GameMode[0] == 1 ||
                gModule_GameMode[0] == 3 || gModule_GameMode[0] == 0xC || gModule_GameMode[0] == 0xD ||
                gModule_GameMode[0] == 0x10 || gModule_GameMode[0] == 0xF || gModule_GameMode[0] == 0x11) {
                gUnk_020391CC = 1;
                gModule_RaceEndState = 2;
                ModuleWaitForVBlank();
                *(volatile u16 *)0x04000000 &= 0xEFFF;
                ModuleBeginFadeToColor(0x19, 0);
            }
            goto r_end;
        r_case27:
            flag = 1;
        r_end:;
        }
        if (gModule_IsLinkRace != 0) {
            linkResult = ModuleExchangeLinkInput();
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
    ModuleM4aMPlayStop(&gUnk_02038FB0);
    return 0;
}
