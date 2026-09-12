#include "global.h"

struct UnkCar {
    u8 filler000[0x7D];
    u8 unk7D;
    u8 filler07E[0x162 - 0x7E];
    u8 unk162;
    u8 filler163[0x164 - 0x163];
    u16 unk164;
    u8 filler166[0x16C - 0x166];
    u32 unk16C;
    u8 filler170[0x190 - 0x170];
};

extern u8 gUnk_02002184;
extern u8 gUnk_020020AC;
extern u8 gUnk_020020C0;
extern u8 gUnk_020020CC;
extern u32 gUnk_020020D4;
extern u8 gUnk_020020DC;
extern u8 gUnk_020020F0;
extern u8 gUnk_02002098;
extern u8 gUnk_020021C4;
extern u8 gUnk_020021BC;
extern u16 gKeysHeld;
extern u16 gKeysPressed;
extern u8 gUnk_0202A510[];
extern u8 gUnk_0202A514;
extern struct UnkCar gUnk_0202A550[];
extern u8 gUnk_0202A6B2;
extern u8 gUnk_0202CAD4;
extern u8 gUnk_0202CBC4;
extern u8 gUnk_0202CBDC;
extern u8 gUnk_0202CDA8[];
extern u8 gUnk_0202CD9C[];
extern u8 gUnk_0202CDC0[];
extern u16 gUnk_0202ED78;
extern u8 gUnk_0202ED70;
extern u8 gUnk_0202EDD0;
extern s32 gUnk_0202EDD4;
extern u8 gUnk_0202EDD8;
extern u8 gUnk_0202EEC8;
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202EED4;
extern u8 gUnk_0202EEE4;
extern u8 gUnk_0202EEF4;
extern u8 gUnk_0202EEF8;
extern u8 gUnk_0202EF00[];
extern u8 gUnk_0202EF08[];
extern u8 gUnk_0202EF10;
extern u8 gUnk_0202EF20[];
extern u8 gUnk_0202EF8C;
extern u8 gUnk_0202EFB0;
extern s8 gUnk_0202EF60[];
extern u8 *gUnk_0202EFC0;
extern u8 gUnk_0202F020;
extern u8 gUnk_0202F024;
extern u8 gUnk_0202F030;
extern u8 gUnk_0202F034;
extern u8 gUnk_083FDA6E[];
extern u8 gUnk_083FDE1C[];
extern u8 gUnk_083FDE2D[];

void sub_08000458(void);
void sub_0800048C(void);
void sub_08001170(void);
void sub_08001208(u16 index);
u8 sub_0800295C(u32 mode, u8 screen, void *data);
u8 sub_08003738(void);
void sub_08003F4C(u16 color);
void sub_0800420C(u32 value, u32 count);
void sub_08004238(u32 src, u32 count);
void sub_08004484(void);
void sub_080047DC(void);
void sub_08008338(void);
void sub_08008A20(void);
void sub_0800F818(u16 value);
u8 sub_0800F120(u8 value);
u8 sub_0800F190(void);
u8 sub_0800F22C(void);
u8 sub_0800F2BC(u8 a, u8 b);
void sub_0800F3A4(void);
void sub_0800F3C0(void);
void sub_0800F560(void);
void sub_0800F8D0(u8 value, u8 *unused);
void sub_08011168(u8 value, u8 selection);
void sub_080102F0(void);
void sub_08010334(void);
u8 sub_0801042C(void);
void sub_08010664(u8 value);
s8 sub_080107E0(void);
u8 sub_08010EA0(void);
u8 sub_08010CD0(void);
void sub_08010074(void);
void sub_080100B0(void);
void sub_08011A50(void);
void sub_08011C9C(u8 value, u16 *dst);
u8 sub_08011FC4(void);
u8 sub_08011528(void);
s8 sub_0801164C(void);
s16 sub_0801177C(void);
/* This caller narrows the result to s8. */
s8 sub_080122B4(void);
void sub_0801238C(void);
u8 sub_08012530(void);
u8 sub_080129E8(u8 value);
u8 sub_080128E0(u8 value);
u8 sub_08012A80(u32 a, u32 b, u32 c);
u8 sub_08012B50(u8 a, u8 b);
u8 sub_08012BBC(u8 value);
u32 sub_08012C20(void);
u8 sub_08012D34(u8 value);
u8 sub_080136F8(u8 a, u8 b);
u8 sub_08013570(u8 a, u8 b);
u8 sub_08013D5C(void);
void sub_08013964(void);
u8 sub_08014004(void);
u32 sub_080140D8(void);
u8 sub_08014278(void);
u8 sub_080144F4(void);
u8 sub_0801465C(void);
u8 sub_08014874(u8 a, u8 b);
u8 sub_08014A84(void);
u8 sub_08014E28(void);
u8 sub_08014F5C(void);
void sub_08015304(void);
void sub_08016834(void);
void sub_080167E0(void);
void sub_08016888(void);
void sub_0801692C(void);
void sub_080169CC(void);
void sub_08016A04(void);
void sub_08016A38(void);
void sub_08016CB0(void);
u8 sub_08016BF8(void);
void sub_080164A8(void);
u8 sub_08016634(void);
void sub_08016724(void);
void sub_08016D28(u8 value);

u32 sub_08015364(void)
{
    u16 frame[0x100];
    u32 keys;
    u32 a6b2 = (u32)&gUnk_0202A6B2;
    u8 zero;
    u8 quit;
    s32 i;
    u8 redraw;
    u8 state;
    s8 result;
    s16 result16;
    u8 score;
    u8 choice;
    u8 track;
    u8 *p;
    u8 *dst;
    s8 one;

    one = 1;
    gUnk_0202F030 = 0;
    zero = 0;
    gUnk_020021C4 = zero;
    gUnk_020020DC = zero;
    sub_08015304();

    for (i = 0; i != 0x11; i++)
        gUnk_0202EF20[i] = 0;
    gUnk_0202EF20[0x0C] = 1;
    gUnk_0202EF20[0x0D] = 1;
    gUnk_0202EF20[0x0E] = 1;
    gUnk_0202EF20[0x0F] = 1;
    gUnk_0202EF20[0x10] = 1;

    sub_08011A50();
    if (sub_08016BF8() == 0) {
        sub_0801238C();
        sub_08016A38();
        sub_0801692C();
        sub_08016A04();
    }
    if (sub_08016BF8() != 0) {
        sub_080167E0();
        sub_08016888();
        sub_080169CC();
    }

    *(volatile u16 *)0x04000020 = 0x0100;
    *(volatile u16 *)0x04000024 = 0;
    *(volatile u16 *)0x04000026 = 0x0100;
    *(volatile u16 *)0x04000030 = 0x0100;
    *(volatile u16 *)0x04000032 = 0x0100;
    *(volatile s16 *)0x04000034 = -0x100;
    *(volatile u16 *)0x04000036 = 0x0100;
    *(volatile u16 *)0x04000028 = 0;
    *(volatile u16 *)0x0400002A = 0;
    *(volatile u16 *)0x0400002C = 0;
    *(volatile u16 *)0x0400002E = 0;
    *(volatile u16 *)0x04000038 = 0;
    *(volatile u16 *)0x0400003A = 0;
    *(volatile u16 *)0x0400003C = 0;
    *(volatile u16 *)0x0400003E = 0;

    sub_0800F560();
    sub_08010334();
    sub_080102F0();
    sub_08001170();
    sub_08003F4C(0x7FFF);

    gUnk_0202EDD0 = 0;
    gUnk_0202A514 = 0x60;
    gUnk_0202CBDC = 0xB6;
    gUnk_0202CAD4 = 0xA0;
    gUnk_0202CBC4 = 0xFF;
    *(u32 *)gUnk_0202A510 = 0x8950;
    sub_08008338();
    gUnk_020020D4 = 0x009F9AC4;

    while (sub_0801042C() == 1) {
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_08016D28(1);
        sub_08008A20();
        sub_0800F3C0();
        gUnk_02002184 = 3;
        gUnk_0202EEB0 = 0;
        sub_0800295C(1, 0, gUnk_0202CDA8);
        sub_08015304();
    }

    for (i = 0; i != 0x18; i++)
        gUnk_0202A550[i].unk162 = i % 0x0C;

    sub_0800F3A4();
    sub_08010664(0);
    *(volatile u16 *)0x04000000 = 0x0540;
    sub_08011C9C(1, frame);
    if (gUnk_0202EF00[2] != 0)
        sub_08001208(2);
    sub_08010664(gUnk_0202EDD4);
    sub_08004238((u32)frame, 0x0F);

    redraw = 0;
    quit = 0;

    do {
    if (redraw != 0) {
        redraw = 0;
        *(volatile u16 *)0x04000000 = 0x0540;
        sub_08011C9C(1, frame);
        sub_0800F3A4();
        sub_08010664(gUnk_0202EDD4);
        sub_08004238((u32)frame, 0x0F);
    }

    sub_0800048C();
    keys = gKeysHeld;
    keys &= gKeysPressed;
    if ((keys & 0x40) != 0) {
        if (--gUnk_0202EDD4 < 0)
            gUnk_0202EDD4 = 6;
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(8);
        sub_08010664(gUnk_0202EDD4);
    }
    if ((keys & 0x80) != 0) {
        if (++gUnk_0202EDD4 > 6)
            gUnk_0202EDD4 = 0;
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(8);
        sub_08010664(gUnk_0202EDD4);
    }

    if ((*(u8 *)0x04000128 & 0x30) == 0) {
        gUnk_0202ED78 = (((*(u32 *)0x04000128 << 26) >> 30) + 1) << 12 | 1;
        sub_0800F818(gUnk_0202ED78);
    }

    if (gUnk_0202EDD4 == 3 && (keys & 9) != 0) {
        gUnk_0202EEB0 = 0;
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(9);
        sub_0800420C(0, 0x0F);
        gUnk_0202EED4 = 0;
        state = sub_08011FC4();
        if (state == 1) {
            result = sub_080122B4();
            if (result == 0)
                goto state3_cleanup;

            gUnk_020020AC = gUnk_0202EEF4;
            gUnk_020020DC = 1;
            gUnk_020020CC = 0;

state3_prompt:
            result16 = sub_0801177C();
            sub_0800420C(0, 0x0F);
            if (result16 == -2)
                goto state3_done;
            if (result16 == -1)
                goto state3_accept;

            sub_0800420C(0, 0x0F);
state3_menu:
            result = sub_080107E0();
            switch (result) {
            case 1:
                gUnk_020020CC = gUnk_0202EF8C;
                break;
            case 0:
                sub_08000458();
                goto state3_prompt;
            case 2:
                goto state3_accept;
            }

state3_launch:
            sub_08000458();
            gUnk_02002184 = 3;
            gUnk_020020D4 = 0x009F9AC4;
            sub_0800420C(0, 0x0F);
            if (sub_0800295C(0, 3, gUnk_0202CDC0) != 0) {
                sub_0800420C(0, 0x0F);
state3_accept:
                sub_080164A8();
                goto state3_done;
            }

            sub_08001208(2);
            sub_08015304();
            if (gUnk_020021BC == 0 && sub_08011528() == 5)
                goto state3_accept;

            result = sub_0801164C();
            if (result == 0)
                goto state3_launch;
            if (result == 1)
                goto state3_menu;
            if (result == 2)
                goto state3_prompt;
            if (result == 4)
                return 0;
            if (result != 5)
                goto state3_menu_done;
            goto state3_accept;

state3_cleanup:
            if (gUnk_0202EF00[2] != 0)
                sub_08001208(2);
            sub_08015304();
            gUnk_020020DC = 0;
            sub_08004484();
            sub_080047DC();
            gUnk_020020C0 = 0;
            gUnk_020021C4 = 0;

state3_menu_done:
            if (gUnk_0202EF00[2] != 0)
                sub_08001208(2);
        } else if (state == 2) {
            sub_08010074();
            sub_08000458();
            if (sub_08003738() != 0) {
                sub_0800420C(0, 0x0F);
                sub_080100B0();
            }
        }

state3_done:
        if (gUnk_0202EF00[2] != 0)
            sub_08001208(2);
        gUnk_020020DC = 0;
        redraw = 1;
    }

    if (gUnk_0202EDD4 == 0 && (keys & 9) != 0) {
        gUnk_0202EEB0 = 0;
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(9);
        sub_0800420C(0, 0x0F);

        for (i = 0; i != 0x18; i++)
            gUnk_0202A550[i].unk164 = 0;

        *(u8 *)a6b2 = sub_08010EA0();
        sub_08008A20();
        sub_0800420C(0, 0x0F);
        if ((gKeysPressed & 2) != 0)
            goto state0_done;

        gUnk_0202F024 = 0;
        gUnk_0202EEC8 = 0;
        gUnk_0202F034 = 0;
        gUnk_0202F020 = 0;

state0_menu:
        choice = sub_080136F8(
            gUnk_0202F024 | gUnk_0202F034,
            gUnk_0202F034 | gUnk_0202EEC8);
        if ((gKeysPressed & 2) != 0 || choice == 3)
            goto state0_done;

        gUnk_0202EEF8 = choice;
        gUnk_020020CC = gUnk_083FDE1C[gUnk_0202F020];
        switch (gUnk_0202EEF8) {
        case 0:
            gUnk_02002184 = 10;
            gUnk_0202A550[0].unk16C = 0;
            gUnk_0202A550[0].unk7D = 1;
            sub_08016D28(1);
            sub_0800F3C0();
            gUnk_0202EFC0 = (u8 *)gUnk_0202A550;
            gUnk_0202EEB0 = 0;
            sub_08011168(0, gUnk_020020CC);
            sub_0800295C(0, 0x0E, gUnk_0202CD9C);
            if (gUnk_0202EF00[2] != 0)
                sub_08001208(2);
            sub_08015304();
            if (gUnk_020020F0 != 0)
                sub_08016834();
            gUnk_0202EEC8 = 1;
            break;
        case 1:
            gUnk_02002184 = 2;
            gUnk_0202EFC0 = (u8 *)gUnk_0202A550;
            gUnk_0202A550[0].unk16C = 0x0002BF20;
            sub_08011168(0, gUnk_020020CC);
            sub_0800295C(0, 0x11, gUnk_0202CDA8);
            if (gUnk_0202EF00[2] != 0)
                sub_08001208(3);
            sub_08015304();
            sub_08016CB0();
            if (gUnk_020020F0 != 0)
                sub_08016834();
            gUnk_0202F024 = 1;
            sub_08013D5C();
            break;
        case 2:
            if (gUnk_0202F024 == 0 || gUnk_0202F034 == 1) {
                gUnk_0202A550[0].unk16C = 0x0002BF20;
                sub_08016CB0();
            }
            sub_0800F3C0();
            gUnk_02002184 = 3;
            gUnk_02002184 = gUnk_083FDA6E[gUnk_0202EF00[1]];
            sub_08011168(0, gUnk_020020CC);
            sub_0800295C(0, 9, gUnk_0202CDA8);
            if (gUnk_0202EF00[2] != 0)
                sub_08001208(2);
            sub_08015304();
            if (gUnk_020021BC == 0) {
                gUnk_0202F024 = 0;
                gUnk_0202EEC8 = 0;
                gUnk_0202F034 = 0;
                if (gUnk_020020F0 != 0)
                    sub_08016834();
                sub_08014004();
                sub_080140D8();
                sub_08014278();
                gUnk_0202F020++;
            } else {
                gUnk_0202F034 = 1;
            }
            break;
        }

        if (gUnk_0202F020 != 0x0B)
            goto state0_menu;
        sub_08012D34(sub_08012C20());

state0_done:
        redraw = 1;
    }

    if (gUnk_0202EDD4 == 1 && (keys & 9) != 0) {
        gUnk_0202EEB0 = 0;
        if (gUnk_0202EF00[4] != 0)
            gUnk_0202EEB0 = 1;

        for (i = 0; i != 0x18; i++)
            gUnk_0202A550[i].unk162 = i % 0x0C;

        if (gUnk_0202EF00[3] != 0)
            sub_08001208(9);
        sub_0800420C(0, 0x0F);

state1_load:
        *(u8 *)a6b2 = sub_08010EA0();
        sub_08008A20();
        sub_0800420C(0, 0x0F);
        if ((gKeysPressed & 2) != 0)
            goto state1_done;

state1_config:
        sub_08011168(1, 0);
        sub_0800420C(0, 0x0F);
        if ((gKeysPressed & 2) != 0)
            goto state1_done;
        gUnk_020020CC = gUnk_0202EF8C;
        gUnk_02002184 = gUnk_083FDA6E[gUnk_0202EF00[1]];

state1_race:
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_08016D28(1);
        for (i = 0; i != 0x18; i++)
            gUnk_0202A550[i].unk16C = i;
        gUnk_0202A550[0].unk16C = 0x0002CAD8;
        sub_0800F3C0();
        sub_0800295C(0, 9, gUnk_0202CDA8);
        if (gUnk_020020F0 != 0)
            sub_08016834();
        if (gUnk_0202EF00[2] != 0)
            sub_08001208(2);
        sub_08015304();
        if (gUnk_020021BC == 0)
            sub_08014E28();

        result = sub_08014F5C();
        if (result == 0)
            goto state1_race;
        if (result == 1)
            goto state1_config;
        if (result == 2)
            goto state1_load;

state1_done:
        redraw = 1;
    }

    if (gUnk_0202EDD4 == 4 && (keys & 9) != 0) {
        gUnk_0202EEB0 = 0;
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(9);
        sub_0800420C(0, 0x0F);

state4_load:
        *(u8 *)a6b2 = sub_08010EA0();
        sub_08008A20();
        sub_0800420C(0, 0x0F);
        if ((gKeysPressed & 2) != 0)
            goto state4_done;

state4_config:
        sub_08011168(1, 0);
        gUnk_020020CC = gUnk_0202EF8C;
        sub_0800420C(0, 0x0F);
        if ((gKeysPressed & 2) != 0)
            goto state4_done;
        gUnk_020020CC = gUnk_0202EF8C;
        gUnk_02002184 = 3;

state4_race:
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_08016D28(1);
        sub_0800F3C0();
        gUnk_0202EFC0 = (u8 *)gUnk_0202A550;
        gUnk_0202F030 = 1;
        sub_0800295C(0, 0x0E, gUnk_0202CD9C);
        gUnk_0202F030 = 0;
        if (gUnk_0202EF00[2] != 0)
            sub_08001208(2);
        sub_08015304();
        if (gUnk_020020F0 != 0)
            sub_08016834();

        result = sub_080144F4();
        if (result == 0)
            goto state4_race;
        if (result == 1)
            goto state4_config;
        if (result == 2)
            goto state4_load;

state4_done:
        redraw = 1;
    }

    if (gUnk_0202EDD4 == 2 && (keys & 9) != 0) {
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(9);
        sub_0800420C(0, 0x0F);

state2_select:
        track = sub_0801465C();
        if ((gKeysPressed & 2) != 0)
            goto state2_done;
        gUnk_0202ED70 = track << 2;

state2_track:
        if (gUnk_0202EF60[gUnk_0202ED70] == -1) {
            gUnk_0202EF60[gUnk_0202ED70] = 0;
            sub_0801692C();
        }
        gUnk_0202ED70 = sub_08014874(track, gUnk_0202ED70);
        if ((gKeysPressed & 2) != 0)
            goto state2_select;

        gUnk_02002098 = 0;
        dst = &gUnk_020020CC;
        p = gUnk_083FDE2D;
        p += *(volatile u8 *)&gUnk_0202ED70;
        *dst = *p;
        sub_0800F8D0(gUnk_0202ED70, dst);
        gUnk_0202EEB0 = one;
        if (gUnk_0202ED70 == 1)
            gUnk_0202EEB0 = 0;
        if (gUnk_0202ED70 == 6)
            gUnk_0202EEB0 = 0;
        if (gUnk_0202ED70 == 10)
            gUnk_0202EEB0 = 0;
        if (gUnk_0202ED70 == 14)
            gUnk_0202EEB0 = 0;
        sub_0800295C(0, 0x0F, gUnk_0202CDA8);
        gUnk_02002098 = gUnk_0202EEE4;
        if (gUnk_0202EF00[2] != 0)
            sub_08001208(2);
        sub_08015304();

        if (gUnk_02002098 == 0)
            goto state2_no_score;

        sub_08012B50(
            gUnk_0202ED70,
            gUnk_0202EF60[gUnk_0202ED70] >= gUnk_02002098);
        if (gUnk_02002098 > gUnk_0202EF60[gUnk_0202ED70]) {
            gUnk_0202EF60[gUnk_0202ED70] = gUnk_02002098;
            sub_0801692C();
        }

        gUnk_0202ED70++;
        if (gUnk_0202ED70 == 4) {
            if (gUnk_0202EF08[1] != 0)
                goto state2_select;
            gUnk_0202EF08[1] = 1;
            sub_080129E8(1);
            sub_0801692C();
            goto state2_select;
        }
        if (gUnk_0202ED70 == 8) {
            if (gUnk_0202EF08[2] != 0)
                goto state2_select;
            gUnk_0202EF08[2] = 1;
            sub_080129E8(2);
            sub_0801692C();
            goto state2_select;
        }
        if (gUnk_0202ED70 == 12) {
            if (gUnk_0202EF08[3] != 0)
                goto state2_select;
            gUnk_0202EF08[3] = 1;
            sub_080129E8(3);
            sub_0801692C();
            goto state2_select;
        }
        if (gUnk_0202ED70 == 16) {
            if (gUnk_0202EF08[4] != 0)
                goto state2_select;
            gUnk_0202EF08[4] = 1;
            sub_080129E8(4);
            sub_0801692C();
            goto state2_select;
        }
        goto state2_after_unlock;

state2_no_score:
        sub_08012BBC(gUnk_0202ED70);
        goto state2_track;

state2_after_unlock:
        if (gUnk_02002098 == 0)
            goto state2_done;
        if (gUnk_0202ED70 == 4 || gUnk_0202ED70 == 8 ||
            gUnk_0202ED70 == 12 || gUnk_0202ED70 == 16) {
            gUnk_0202EF08[gUnk_0202ED70 >> 2] = 1;
            sub_08016A04();
            goto state2_done;
        }
        goto state2_track;

state2_done:
        redraw = 1;
    }

    if (gUnk_0202EDD4 == 5 && (keys & 9) != 0) {
        gUnk_0202EF10 = gUnk_083FDA6E[gUnk_0202EF00[1]];
        gUnk_0202EEB0 = 1;
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(9);
        sub_0800420C(0, 0x0F);

        for (i = 0; i != 0x18; i++)
            gUnk_0202A550[i].unk164 = 0;

        if (sub_08016634() != 0) {
            result = sub_08014A84();
            if ((gKeysPressed & 2) != 0)
                goto state5_done;
            if (result == 1) {
                sub_08016724();
                goto state5_menu;
            }
        }

state5_setup:
        for (i = 0; i != 0x18; i++)
            gUnk_0202A550[i].unk164 = 0;
        if (sub_0800F190() == 0) {
            sub_08012A80(0x0829F590, 0x0829F59C, 0x0829F5B4);
            goto state5_done;
        }

        gUnk_0202EDD8 = sub_08010CD0();
        if ((gKeysPressed & 2) != 0)
            goto state5_done;
        *(u8 *)a6b2 = sub_0800F120(gUnk_0202EDD8);
        if (sub_080128E0(*(u8 *)a6b2) == 0)
            goto state5_setup;

state5_load:
        *(u8 *)a6b2 = sub_0800F120(gUnk_0202EDD8);
        sub_08008A20();
        sub_0800420C(0, 0x0F);
        if ((gKeysPressed & 2) != 0)
            goto state5_done;

        gUnk_0202F024 = 0;
        gUnk_0202EEC8 = 0;
        gUnk_0202F034 = 0;
        gUnk_0202F020 = 0;

state5_menu:
        choice = sub_08013570(
            gUnk_0202F024 | gUnk_0202F034,
            gUnk_0202F034 | gUnk_0202EEC8);
        if ((gKeysPressed & 2) != 0 || choice == 4)
            goto state5_done;

        gUnk_0202EEF8 = choice;
        gUnk_020020CC = gUnk_083FDE1C[gUnk_0202F020];
        switch (gUnk_0202EEF8) {
        case 0:
            gUnk_0202A550[0].unk16C = 0;
            gUnk_0202A550[0].unk7D = 1;
            sub_08016D28(1);
            sub_0800F3C0();
            gUnk_0202EFC0 = (u8 *)gUnk_0202A550;
            gUnk_0202EEB0 = 0;
            sub_08011168(0, gUnk_020020CC);
            sub_0800295C(0, 0x0E, gUnk_0202CD9C);
            gUnk_0202EEB0 = 1;
            if (gUnk_0202EF00[2] != 0)
                sub_08001208(2);
            sub_08015304();
            if (gUnk_020020F0 != 0)
                sub_08016834();
            gUnk_0202EEC8 = 1;
            break;
        case 1:
            gUnk_02002184 = 2;
            gUnk_0202EFC0 = (u8 *)gUnk_0202A550;
            gUnk_0202A550[0].unk16C = 0x0002BF20;
            sub_08011168(0, gUnk_020020CC);
            sub_0800295C(0, 0x11, gUnk_0202CDA8);
            if (gUnk_0202EF00[2] != 0)
                sub_08001208(2);
            sub_08015304();
            sub_08016CB0();
            if (gUnk_020020F0 != 0)
                sub_08016834();
            gUnk_0202F024 = 1;
            sub_08013D5C();
            break;
        case 2:
            if (gUnk_0202F024 == 0 || gUnk_0202F034 == 1) {
                gUnk_0202A550[0].unk16C = 0x0002BF20;
                sub_08016CB0();
            }
            sub_0800F3C0();
            gUnk_02002184 = gUnk_0202EF10;
            sub_08011168(0, gUnk_020020CC);
            sub_0800295C(0, 9, gUnk_0202CDA8);
            if (gUnk_0202EF00[2] != 0)
                sub_08001208(2);
            sub_08015304();
            if (gUnk_020021BC == 0) {
                gUnk_0202F024 = 0;
                gUnk_0202EEC8 = 0;
                gUnk_0202F034 = 0;
                if (gUnk_020020F0 != 0)
                    sub_08016834();
                sub_08014004();
                sub_080140D8();
                sub_08014278();
                gUnk_0202F020++;
            } else {
                gUnk_0202F034 = 1;
            }
            break;
        case 3:
            sub_08013964();
            break;
        }

        if (gUnk_0202F020 != 0x0B)
            goto state5_menu;
        score = sub_08012C20();
        sub_08012D34(score);
        if (sub_0800F2BC(gUnk_0202EDD8, score) != 0)
            goto state5_setup;
        if (sub_0800F22C() != 0)
            goto state5_setup;
        goto state5_load;

state5_done:
        redraw = 1;
    }

    if (gUnk_0202EDD4 == 6 && (keys & 9) != 0) {
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(9);
        gUnk_0202EFB0 = 0;
        sub_0800420C(0, 0x0F);
        sub_08012530();
        redraw = 1;
        if (gUnk_0202EFB0 != 0)
            sub_08016A04();
    }

    sub_08000458();
    } while (quit == 0);
    return 0;
}
