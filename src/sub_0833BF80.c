/*
 * sub_0833BF80: the main race loop. Levers that made it match:
 * - dead `t++; t--;` pairs before each `(u8)t` site give gcse a kill on t,
 *   so PRE does not merge the two lsls/lsrs pairs; DCE removes the pair.
 * - `rrret` is placed out of line by jumping INTO the D5F4 then-arm, and
 *   it reaches the labelled `return 1` (ret1) so jump.c's range swap
 *   ("if (foo) bar; else break;") does not reorder the final return.
 * - `rr` is s32: ARM promotes s8 locals zero-extended, which gives lsrs;
 *   an s32 home keeps the ROM's asrs and cmp on the extended value.
 * - the busy-wait after sub_0833C874 is a goto loop: an empty-body
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

void sub_0833CD2C(u8);
void sub_0833D9E8(u8);
void sub_0833EE20(void);
void sub_0833BF20(void);
void sub_0833D3E4(s32);
void sub_08343504(u32);
void sub_0833F448(u32);
void sub_0833F9A8(void);
void sub_0833FF1C(void);
void sub_0833D7D4(void);
void sub_0833D680(void);
void sub_0833D9D8(void);
void sub_0833BF6C(void);
void sub_0833EDF8(void);
void sub_0833EDB8(void);
void ModuleM4aSongNumStart(u16);
void sub_083426C8(void);
void sub_08342868(void);
void sub_08342B04(void);
void sub_0833D5F4(void *);
void sub_08344878(void);
void sub_0833B81C(void *, u16, s16);
void sub_0833D448(void);
void sub_0833D5B8(void);
void sub_0833D57C(void);
void sub_0833FFC4(void);
void sub_083419D8(void);
void sub_0833DF58(void);
void sub_0833CF10(u32, u32);
void sub_08340EFC(void);
void ModuleM4aMPlayFadeOut(u32, u16);
u32 sub_0833DBC8(void);
u32 sub_0833DCB0(void);
u32 sub_0833DBF4(void);
s8 sub_0833C874(void);
void sub_0833FA3C(void);

s32 sub_0833BF80(u8 arg0, u8 arg1)
{
    u8 pad[4];
    register u8 *pf asm("r4");
    u32 t;
    u32 r;
    s32 rt;
    s32 i;
    u32 flag;
    struct Car *ent;
    s32 t2;
    s32 rr;
    u8 first;

    t = arg1;
    gUnk_02039100 = 0;
    gUnk_020391CC = 0;
    gUnk_02039154 = 0;
    gModule_GameMode[0] = t;
    pf = &gModule_IsDemo[0];
    *pf = arg0;
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
    if (*pf != 0)
        gModule_NumCars[0] = 2;
    if (gModule_TrackId > 6 && gModule_TrackId != 8 && gModule_TrackId != 9
        && gModule_TrackId != 0xA && gModule_TrackId != 0xB)
        gModule_NumCars[0] = 1;
    if ((u8)(gModule_GameMode[0] - 3) <= 1)
        gModule_NumCars[0] = gModule_NumLinkPlayers[0];
    gUnk_020391E0[0] = 0;
    gUnk_020391E0[1] = 0;
    gUnk_020391E0[2] = 0;
    gUnk_020391E0[3] = 0;
    sub_0833CD2C(gModule_TrackId);
    sub_0833F448(gModule_TrackId);
    sub_0833D9E8(gModule_TrackId);
    sub_0833EE20();
    sub_0833BF20();
    gUnk_02039158 = 0x100;
    sub_0833D3E4(0x32);
    sub_08343504(gModule_TrackId);
    sub_0833F9A8();
    sub_0833FF1C();
    sub_0833D7D4();
    sub_0833D680();
    sub_0833D9D8();
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
    sub_0833BF6C();
    if (gModule_GameMode[0] == 0xE) {
        sub_0833EDF8();
    } else {
        sub_0833EDB8();
    }
    if (gModule_IsDemo[0] != 0) {
        if (gModule_Options[2] != 0)
            ModuleM4aSongNumStart(1);
        gModule_RaceStarted = 1;
        gUnk_020250EC = 2;
        if (gModule_IsDemo[0] != 0) {
            for (i = 0; i != 100; i++)
                sub_083426C8();
            sub_08342868();
            goto skip42B04;
        }
    }
    if ((u8)(gModule_GameMode[0] - 3) <= 1)
        sub_08342B04();
skip42B04:
    if (gModule_GameMode[0] == 9 || gModule_GameMode[0] == 0xD || gModule_GameMode[0] == 0xE
        || gModule_GameMode[0] == 0xF || gModule_GameMode[0] == 0x11) {
        gUnk_020390B8 = 1;
        for (i = 0; i != 20; i++)
            sub_083426C8();
        gUnk_020390B8 = 0;
    }
    gUnk_020390B8 = 0;
    if (gModule_IsLinkRace != 0) {
        sub_0833D5F4(&gModule_Cars[(*(volatile u32 *)0x04000128 << 0x1A) >> 0x1E]);
        goto after_d5f4;
rrret:
        gUnk_02039154 = 1;
        goto ret1;
after_d5f4: ;
    } else {
        sub_0833D5F4(gModule_Cars);
    }
    gModule_Camera[0] = gModule_Camera[2];
    gModule_Camera[1] = gModule_Camera[3];
    gModule_FrameCounter = 0;
    gModule_RaceEndState = 0;
    gUnk_020390C4 = 1;
    t++;
    t--;
    if ((u8)t <= 1)
        sub_08344878();
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
        sub_0833FA3C();
        sub_0833D680();
        sub_08343148(gUnk_02039160, 0x4B, 0x3C);
        if (gUnk_0203921C != 0)
            sub_08343148(gUnk_02039170, 0x4B, 0x5A);
        gModule_VBlanksThisFrame = 0;
        if ((u8)t > 1)
            ent = gModule_Cars;
        else
            ent = &gModule_Cars[gModule_LinkPlayerId];
        sub_0833B81C(gUnk_02038FB0, 1,
                    ((s16)(gUnk_02025190[ent->gear]
                         + ((ent->rpm * gUnk_020251A4[ent->gear]) >> 6))) >> 3);
        if (gModule_IsDemo[0] != 0) {
            sub_0833D5F4(gUnk_0203D6B0);
            gUnk_020250EC = t2 = gModule_FrameCounter / 256;
            if (t2 % 8 == 0)
                gUnk_020250EC = 4;
        } else {
            if (gModule_IsLinkRace != 0)
                sub_0833D5F4(&gModule_Cars[(*(volatile u32 *)0x04000128 << 0x1A) >> 0x1E]);
            else
                sub_0833D5F4(gModule_Cars);
            if (gModule_GameMode[0] == 9 || gModule_GameMode[0] == 0xD || gModule_GameMode[0] == 0xE
                || gModule_GameMode[0] == 0xF || gModule_GameMode[0] == 0x11) {
                gModule_Camera[0] = *(u32 *)&gModule_Cars[0];
                gModule_Camera[1] = *(u32 *)((u8 *)&gModule_Cars[0] + 8);
            }
        }
        sub_0833D448();
        sub_0833D5B8();
        sub_0833D57C();
        sub_0833FFC4();
        sub_083419D8();
        sub_0833DF58();
        if (gModule_RaceStarted != 0 || gModule_GameMode[0] == 9 || gModule_GameMode[0] == 0xD
            || gModule_GameMode[0] == 0xE || gModule_GameMode[0] == 0xF || gModule_GameMode[0] == 0x11)
            sub_083426C8();
        sub_0833CF10(gModule_Camera[0], gModule_Camera[1]);
        sub_0833D9D8();
        sub_08340EFC();
        gUnk_020391D4 = 1;
        if (gModule_IsDemo[0] != 0) {
            if (gUnk_0203761C != 0) {
                gUnk_020391CC = 1;
                gModule_RaceEndState = 2;
                ModuleWaitForVBlank();
                *(volatile u16 *)0x04000000 &= 0xEFFF;
                if (gModule_Options[2] != 0)
                    ModuleM4aMPlayFadeOut(gUnk_02038F70, 2);
                sub_0833D288(0x19, 0);
            }
        } else {
            if ((u8)(gModule_GameMode[0] - 3) > 1 && gModule_RaceEndState == 0) {
                if (gModule_PaletteFadeActive != 0)
                    goto r_zero;
                r = sub_0833DBC8();
                goto r_ext;
            }
            if (gModule_PaletteFadeActive != 0 || gModule_RaceEndState != 0)
                goto r_zero;
            if (gModule_GameMode[0] == 4)
                r = sub_0833DCB0();
            else
                r = sub_0833DBF4();
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
            if (gModule_GameMode[0] == 2 || gModule_GameMode[0] == 0xE || gModule_GameMode[0] == 0
                || gModule_GameMode[0] == 7 || gModule_GameMode[0] == 6 || gModule_GameMode[0] == 9
                || gModule_GameMode[0] == 5 || gModule_GameMode[0] == 0x11 || gModule_GameMode[0] == 1
                || gModule_GameMode[0] == 3 || gModule_GameMode[0] == 0xC || gModule_GameMode[0] == 0xD
                || gModule_GameMode[0] == 0x10 || gModule_GameMode[0] == 0xF
                || gModule_GameMode[0] == 0x11) {
                gUnk_020391CC = 1;
                gModule_RaceEndState = 2;
                ModuleWaitForVBlank();
                *(volatile u16 *)0x04000000 &= 0xEFFF;
                sub_0833D288(0x19, 0);
            }
            goto r_end;
r_case27:
            flag = 1;
r_end: ;
        }
        if (gModule_IsLinkRace != 0) {
            rr = sub_0833C874();
            if (rr != 0)
                goto rrret;
            (*(volatile s8 *)&gModule_VBlankWorkDone) = rr;
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
    sub_0833B074((struct MusicPlayerInfo *)gUnk_02038FB0);
    return 0;
}
