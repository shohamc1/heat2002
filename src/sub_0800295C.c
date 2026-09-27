#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

extern s32 gUnk_0200209C;          /* 0x0200209C */
extern u32 gCamera[];        /* 0x02002100 */
extern u8 gUnk_02002144;           /* 0x02002144 */
extern u32 gUnk_02002148;          /* 0x02002148 */
extern u8 gUnk_02002150[];         /* 0x02002150 */
extern u8 gUnk_02002160[];         /* 0x02002160 */
extern u32 gUnk_020021D0[];        /* 0x020021D0 */
extern u8 gUnk_020021EC[];         /* 0x020021EC */
extern u8 gUnk_020021F0;           /* 0x020021F0 */
extern u8 gUnk_02001F60[];         /* 0x02001F60 */
extern u8 gUnk_0202A6E0[];         /* 0x0202A6E0 */
extern u8 gUnk_08364ADC;           /* 0x08364ADC */
extern u32 gUnk_08364AE0[];        /* 0x08364AE0 */
extern u8 gUnk_08364AF4[];         /* 0x08364AF4 */
extern u8 gUnk_0806C678[];         /* 0x0806C678 */


/* The cancelling offset gives the destination address an earlier quantity,
   selecting the ROM's r3/r4 allocation without emitting extra code. */
u8 RunRace(u32 a, u8 b)
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

    gUnk_020020F0 = 0;
    gUnk_020021BC = 0;
    gUnk_02002144 = 0;
    gUnk_0200215C[0] = b;
    off = a;
    dest = (u8 *)((u32)&gIsDemo + off - a);
    *dest = a;
    if (b != 0x0F)
        gNumCars[0] = 0x18;
    if (gUnk_0200215C[0] == 0x02)
        gNumCars[0] = 1;
    if (gUnk_0200215C[0] == 0x11)
        gNumCars[0] = 1;
    if (gUnk_0200215C[0] == 0x0D)
        gNumCars[0] = 1;
    if (gUnk_0200215C[0] == 0x0E)
        gNumCars[0] = 1;
    if (gIsDemo != 0)
        gNumCars[0] = 2;
    if (gTrackId > 6 && gTrackId != 8 && gTrackId != 9
        && gTrackId != 0x0A && gTrackId != 0x0B)
        gNumCars[0] = 1;
    if (gUnk_0200215C[0] == 3 || gUnk_0200215C[0] == 4)
        gNumCars[0] = gNumLinkPlayers[0];
    gUnk_020021D0[0] = 0;
    gUnk_020021D0[1] = 0;
    gUnk_020021D0[2] = 0;
    gUnk_020021D0[3] = 0;
    LoadTrack(gTrackId);
    sub_08006A14(gTrackId);
    sub_08004944(gTrackId);
    sub_080063B0();
    sub_08002718();
    gUnk_02002148 = 0x100;
    sub_080040E0(0x32);
    LoadTrackWalls(gTrackId);
    InitGfxCaches();
    InitTasks();
    sub_080045D8();
    ClearOamBuffer();
    sub_080047DC();
    gUnk_020021C4 = 1;
    (*(vu8 *)&gUnk_020020C0) = 0;
    while ((*(vu8 *)&gUnk_020020C0) == 0)
        ;
    WaitForVBlank();
    gUnk_020020EC = 0;
    EnableRaceDisplay();
    if (gUnk_0200215C[0] == 0x0E)
        sub_08006388();
    else
        InitRaceHud();
    if (gIsDemo != 0) {
        if (gOptions[2] != 0)
            m4aSongNumStart(1);
        gUnk_020020C4 = 1;
        gUnk_08364ADC = 2;
    }
    if (gIsDemo != 0) {
        for (i = 0; i != 100; i++)
            UpdateAllCars();
        sub_0800AF20();
    } else if (gUnk_0200215C[0] == 3 || gUnk_0200215C[0] == 4) {
        sub_0800B334();
    }
    if (gUnk_0200215C[0] != 9 && gUnk_0200215C[0] != 2 && gUnk_0200215C[0] != 7
        && gIsDemo == 0 && gOptions[3] != 0)
        m4aSongNumStart(0x1E);
    if (gIsDemo == 0)
        sub_08002950();
    if (gUnk_0200215C[0] == 9 || gUnk_0200215C[0] == 0x0D || gUnk_0200215C[0] == 0x0E
        || gUnk_0200215C[0] == 0x0F || gUnk_0200215C[0] == 0x11) {
        gUnk_020020A8 = 1;
        for (i = 0; i != 20; i++)
            UpdateAllCars();
        gUnk_020020A8 = 0;
    }
    gUnk_020020A8 = 0;
    if (gIsLinkRace != 0) {
        SetCameraTarget((struct UnkStruct080043F8 *)(&gCars[(*(volatile u32 *)REG_ADDR_SIOCNT << 26) >> 30]));
        goto camera_ready;
connection_error:
        gUnk_02002144 = 1;
        goto success;
    } else
        SetCameraTarget((struct UnkStruct080043F8 *)(&gCars[0]));
camera_ready:
    gCamera[0] = gCamera[2];
    gCamera[1] = gCamera[3];
    gUnk_0200209C = 0;
    gUnk_020021E0 = 0;
    gUnk_020020B4 = 1;
    if (b == 3 || b == 4)
        InitMultiplayerSio();
    if (gOptions[3] != 0 && gIsDemo == 0)
        m4aSongNumStart(0x0A);
    gUnk_020021F0 = 0;
    gUnk_02002124 = 0;
    flag = 0;
    gUnk_020021EC[3] = 0;
    gUnk_020021EC[2] = 0;
    gUnk_020021EC[1] = 0;
    gUnk_020021EC[0] = 0;
    while (gUnk_02002144 == 0) {
        AgeGfxCaches();
        ClearOamBuffer();
        DrawSpriteText(gUnk_02002150, 0x4B, 0x3C);
        if (gUnk_020021F0 != 0)
            DrawSpriteText(gUnk_02002160, 0x4B, 0x5A);
        gUnk_02002124 = 0;
        if (b != 3 && b != 4)
            p = &gCars[0];
        else
            p = &gCars[gLinkPlayerId[0]];
        /* sub_0800215C: this file's old prototype took (void *, u32, s32);
           the matched definition narrows to u16; call through the old one. */
        ((void (*)(void *, u32, s32))sub_0800215C)(gUnk_02001F60, 1,
                     (s16)(gUnk_08364AE0[p->gear]
                           + ((p->rpm * gUnk_08364AF4[p->gear]) >> 6)) >> 3);
        if (gIsDemo != 0) {
            SetCameraTarget((struct UnkStruct080043F8 *)gUnk_0202A6E0);
            gUnk_08364ADC = t = gUnk_0200209C / 256;
            if ((t & 7) == 0)
                gUnk_08364ADC = 4;
        } else {
            if (gIsLinkRace != 0)
                SetCameraTarget((struct UnkStruct080043F8 *)(&gCars[(*(volatile u32 *)REG_ADDR_SIOCNT << 26) >> 30]));
            else
                SetCameraTarget((struct UnkStruct080043F8 *)(&gCars[0]));
            if (gUnk_0200215C[0] == 9 || gUnk_0200215C[0] == 0x0D || gUnk_0200215C[0] == 0x0E
                || gUnk_0200215C[0] == 0x0F || gUnk_0200215C[0] == 0x11) {
                gCamera[0] = (*(u32 *)&gCars[0].posX);
                gCamera[1] = (*(u32 *)&gCars[0].posZ);
            }
        }
        UpdatePaletteFade();
        SmoothCamera();
        UpdateCameraScroll();
        RunTasks();
        DrawAllCars();
        if (gUnk_0200215C[0] == 4)
            sub_0800545C();
        if (gUnk_020020C4 != 0 || gUnk_0200215C[0] == 9 || gUnk_0200215C[0] == 0x0D
            || gUnk_0200215C[0] == 0x0E || gUnk_0200215C[0] == 0x0F
            || gUnk_0200215C[0] == 0x11)
            UpdateAllCars();
        ((void (*)(u32, u32))UpdateTrackScroll)(gCamera[0], gCamera[1]);
        if (gUnk_0200215C[0] == 9 || gUnk_0200215C[0] == 0x0D || gUnk_0200215C[0] == 0x0E
            || gUnk_0200215C[0] == 0x0F || gUnk_0200215C[0] == 0x11) {
            if ((gUnk_0200209C & 8) == 0)
                /* DrawTextCentered: the ROM callers pass a third argument the matched definition drops; call
                   through a function pointer with the old prototype. */
                ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x5D), 8, 1);
            else
                ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C678, 8, 1);
        }
        sub_080047DC();
        sub_08008D8C();
        gUnk_020021C4 = 1;
        if (gIsDemo != 0) {
            if (gKeysPressed != 0) {
                gUnk_020021BC = 1;
                gUnk_020021E0 = 2;
                WaitForVBlank();
                REG_DISPCNT &= ~DISPCNT_OBJ_ON;
                if (gOptions[2] != 0)
                    m4aMPlayFadeOut(gUnk_02001F20, 2);
                BeginFadeToColor(0x19, 0);
            }
        } else {
            if (gUnk_0200215C[0] != 3 && gUnk_0200215C[0] != 4 && gUnk_020021E0 == 0) {
                if (gUnk_02022E14 == 0)
                    res = PauseMenu();
                else
                    res = 0;
            } else {
                if (gUnk_02022E14 == 0 && gUnk_020021E0 == 0) {
                    if (gUnk_0200215C[0] == 4)
                        res = sub_08005280();
                    else
                        res = sub_080050F0();
                } else {
                    res = 0;
                }
            }
            switch (res) {
            case 0:
                break;
            case 1:
                if (gOptions[3] != 0 && gIsDemo == 0)
                    m4aSongNumStart(0x0A);
                break;
            case 2:
                if (gUnk_0200215C[0] == 0x02 || gUnk_0200215C[0] == 0x0E
                    || gUnk_0200215C[0] == 0x00 || gUnk_0200215C[0] == 0x07
                    || gUnk_0200215C[0] == 0x06 || gUnk_0200215C[0] == 0x09
                    || gUnk_0200215C[0] == 0x05 || gUnk_0200215C[0] == 0x11
                    || gUnk_0200215C[0] == 0x01 || gUnk_0200215C[0] == 0x03
                    || gUnk_0200215C[0] == 0x0C || gUnk_0200215C[0] == 0x0D
                    || gUnk_0200215C[0] == 0x10 || gUnk_0200215C[0] == 0x0F
                    || gUnk_0200215C[0] == 0x11) {
                    gUnk_020021BC = 1;
                    gUnk_020021E0 = 2;
                    WaitForVBlank();
                    REG_DISPCNT &= ~DISPCNT_OBJ_ON;
                    sub_080019B4((struct MusicPlayerInfo *)gUnk_02001FA0);
                    sub_080019B4((struct MusicPlayerInfo *)gUnk_02002030);
                    sub_080019B4((struct MusicPlayerInfo *)gUnk_02001FE0);
                    BeginFadeToColor(0x19, 0);
                }
                break;
            case 0x27:
                flag = 1;
                break;
            }
        }
        if (gIsLinkRace != 0) {
            v = (s8)ExchangeLinkInput();
            if (v != 0) {
                goto connection_error;
            }
            (*(vu8 *)&gUnk_020020C0) = v;
wait_link:
            if ((*(vu8 *)&gUnk_020020C0) == 0)
                goto wait_link;
        } else {
            (*(vu8 *)&gUnk_020020C0) = 0;
            while ((*(vu8 *)&gUnk_020020C0) == 0)
                ;
        }
        gUnk_0200209C++;
        if (gUnk_020021E0 == 2 && gUnk_02022E14 == 0)
            gUnk_02002144 = 1;
    }
    if (flag != 0) {
success:
        return 1;
    }
    sub_080019B4((struct MusicPlayerInfo *)gUnk_02001F60);
    return 0;
}
