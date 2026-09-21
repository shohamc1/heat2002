#include "global.h"

struct Ent {
    u8 pad00[0x3E];
    u8 unk3E;
    u16 unk40;
    u8 pad42[0x190 - 0x42];
};

extern u8 gUnk_02039100;
extern u8 gUnk_020391CC;
extern u8 gUnk_02039154;
extern u8 gUnk_0203916C;
extern u8 gUnk_020390F0;
extern u8 gUnk_020390A0;
extern u8 gUnk_020390DC;
extern u8 gUnk_020390BC;
extern u32 gUnk_020391E0[4];
extern u32 gUnk_02039158;
extern u8 gUnk_020391D4;
extern volatile u8 gUnk_020390D0;
extern u8 gUnk_020390FC;
extern u8 gUnk_0203E120[];
extern u8 gUnk_020390D4;
extern u8 gUnk_020250EC;
extern u8 gUnk_020390B8;
extern u8 gUnk_020390EC;
extern struct Ent gUnk_0203D520[];
extern u32 gUnk_02039110[4];
extern u32 gUnk_020390AC;
extern u8 gUnk_020391F0;
extern u8 gUnk_020390C4;
extern u8 gUnk_0203921C;
extern u16 gUnk_02039134;
extern u8 gUnk_02039218[4];
extern u8 gUnk_02039160[];
extern u8 gUnk_02039170[];
extern s32 gUnk_02025190[];
extern u8 gUnk_020251A4[];
extern u8 gUnk_02038FB0[];
extern u8 gUnk_0203D6B0[];
extern u16 gUnk_0203761C;
extern u8 gUnk_020392C4;
extern u8 gUnk_02038F70[];
extern u8 gUnk_08338FB0[];
extern u8 gUnk_0203E1B0;

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
void sub_08339B18(void);
void sub_0833BF6C(void);
void sub_0833EDF8(void);
void sub_0833EDB8(void);
void sub_0833A8C8(u16);
void sub_083426C8(void);
void sub_08342868(void);
void sub_08342B04(void);
void sub_0833D5F4(void *);
void sub_08344878(void);
void sub_08343148(u8 *, u32, u32);
void sub_0833B81C(void *, u16, u16);
void sub_0833D448(void);
void sub_0833D5B8(void);
void sub_0833D57C(void);
void sub_0833FFC4(void);
void sub_083419D8(void);
void sub_0833DF58(void);
void sub_0833CF10(u32, u32);
void sub_08340EFC(void);
void sub_0833AA60(u32, u16);
u32 sub_0833DBC8(void);
u8 sub_0833DCB0(void);
u32 sub_0833DBF4(void);
s8 sub_0833C874(void);
void sub_0833D288(u32, u32);
void sub_0833B074(void *);
void sub_0833FA3C(void);

s32 sub_0833BF80(u8 arg0, u8 arg1)
{
    u8 pad[4];
    u32 t;
    u32 r;
    s32 i;
    u32 flag;
    struct Ent *ent;
    s32 t2;
    s8 rr;
    u8 first;

    t = arg1;
    gUnk_02039100 = 0;
    gUnk_020391CC = 0;
    gUnk_02039154 = 0;
    gUnk_0203916C = t;
    gUnk_020390F0 = arg0;
    if (t != 0xF)
        gUnk_020390A0 = 5;
    if (gUnk_0203916C == 2)
        gUnk_020390A0 = 1;
    if (gUnk_0203916C == 0x11)
        gUnk_020390A0 = 1;
    if (gUnk_0203916C == 0xD)
        gUnk_020390A0 = 1;
    if (gUnk_0203916C == 0xE)
        gUnk_020390A0 = 1;
    if (gUnk_020390F0 != 0)
        gUnk_020390A0 = 2;
    if (gUnk_020390DC > 6 && gUnk_020390DC != 8 && gUnk_020390DC != 9
        && gUnk_020390DC != 0xA && gUnk_020390DC != 0xB)
        gUnk_020390A0 = 1;
    if ((u8)(gUnk_0203916C - 3) <= 1)
        gUnk_020390A0 = gUnk_020390BC;
    gUnk_020391E0[0] = 0;
    gUnk_020391E0[1] = 0;
    gUnk_020391E0[2] = 0;
    gUnk_020391E0[3] = 0;
    sub_0833CD2C(gUnk_020390DC);
    sub_0833F448(gUnk_020390DC);
    sub_0833D9E8(gUnk_020390DC);
    sub_0833EE20();
    sub_0833BF20();
    gUnk_02039158 = 0x100;
    sub_0833D3E4(0x32);
    sub_08343504(gUnk_020390DC);
    sub_0833F9A8();
    sub_0833FF1C();
    sub_0833D7D4();
    sub_0833D680();
    sub_0833D9D8();
    gUnk_020391D4 = 1;
    gUnk_020390D0 = 0;
    first = gUnk_020390D0;
    t -= 3;
    if (first == 0) {
        do
            ;
        while (gUnk_020390D0 == 0);
    }
    sub_08339B18();
    gUnk_020390FC = 0;
    sub_0833BF6C();
    if (gUnk_0203916C == 0xE) {
        sub_0833EDF8();
    } else {
        sub_0833EDB8();
    }
    if (gUnk_020390F0 != 0) {
        if (gUnk_0203E120[2] != 0)
            sub_0833A8C8(1);
        gUnk_020390D4 = 1;
        gUnk_020250EC = 2;
        if (gUnk_020390F0 != 0) {
            for (i = 0; i != 100; i++)
                sub_083426C8();
            sub_08342868();
            goto skip42B04;
        }
    }
    if ((u8)(gUnk_0203916C - 3) <= 1)
        sub_08342B04();
skip42B04:
    if (gUnk_0203916C == 9 || gUnk_0203916C == 0xD || gUnk_0203916C == 0xE
        || gUnk_0203916C == 0xF || gUnk_0203916C == 0x11) {
        gUnk_020390B8 = 1;
        for (i = 0; i != 20; i++)
            sub_083426C8();
        gUnk_020390B8 = 0;
    }
    gUnk_020390B8 = 0;
    if (gUnk_020390EC != 0)
        sub_0833D5F4(&gUnk_0203D520[(*(volatile u32 *)0x04000128 << 0x1A) >> 0x1E]);
    else
        sub_0833D5F4(gUnk_0203D520);
    gUnk_02039110[0] = gUnk_02039110[2];
    gUnk_02039110[1] = gUnk_02039110[3];
    gUnk_020390AC = 0;
    gUnk_020391F0 = 0;
    gUnk_020390C4 = 1;
    if ((u8)t <= 1)
        sub_08344878();
    sub_0833A8C8(0x38);
    gUnk_0203921C = 0;
    gUnk_02039134 = 0;
    flag = 0;
    gUnk_02039218[3] = gUnk_02039218[2] = gUnk_02039218[1] = gUnk_02039218[0] = 0;
    while (gUnk_02039154 == 0) {
        sub_0833FA3C();
        sub_0833D680();
        sub_08343148(gUnk_02039160, 0x4B, 0x3C);
        if (gUnk_0203921C != 0)
            sub_08343148(gUnk_02039170, 0x4B, 0x5A);
        gUnk_02039134 = 0;
        if ((u8)t <= 1)
            ent = &gUnk_0203D520[gUnk_0203E1B0];
        else
            ent = gUnk_0203D520;
        sub_0833B81C(gUnk_02038FB0, 1,
                    ((s16)(gUnk_02025190[ent->unk3E]
                         + ((gUnk_020251A4[ent->unk3E] * ent->unk40) >> 6))) >> 3);
        if (gUnk_020390F0 != 0) {
            sub_0833D5F4(gUnk_0203D6B0);
            t2 = gUnk_020390AC / 256;
            gUnk_020250EC = t2;
            if (t2 % 8 == 0)
                gUnk_020250EC = 4;
        } else {
            if (gUnk_020390EC != 0)
                sub_0833D5F4(&gUnk_0203D520[(*(volatile u32 *)0x04000128 << 0x1A) >> 0x1E]);
            else
                sub_0833D5F4(gUnk_0203D520);
        }
        if (gUnk_0203916C == 9 || gUnk_0203916C == 0xD || gUnk_0203916C == 0xE
            || gUnk_0203916C == 0xF || gUnk_0203916C == 0x11) {
            gUnk_02039110[0] = *(u32 *)&gUnk_0203D520[0];
            gUnk_02039110[1] = *(u32 *)((u8 *)&gUnk_0203D520[0] + 8);
        }
        sub_0833D448();
        sub_0833D5B8();
        sub_0833D57C();
        sub_0833FFC4();
        sub_083419D8();
        sub_0833DF58();
        if (gUnk_020390D4 != 0 || gUnk_0203916C == 9 || gUnk_0203916C == 0xD
            || gUnk_0203916C == 0xE || gUnk_0203916C == 0xF || gUnk_0203916C == 0x11)
            sub_083426C8();
        sub_0833CF10(gUnk_02039110[0], gUnk_02039110[1]);
        sub_0833D9D8();
        sub_08340EFC();
        gUnk_020391D4 = 1;
        if (gUnk_020390F0 != 0) {
            if (gUnk_0203761C != 0) {
                gUnk_020391CC = 1;
                gUnk_020391F0 = 2;
                sub_08339B18();
                *(volatile u16 *)0x04000000 &= 0xEFFF;
                if (gUnk_0203E120[2] != 0)
                    sub_0833AA60(gUnk_02038F70, 2);
                sub_0833D288(0x19, 0);
            }
        } else {
            if ((u8)(gUnk_0203916C - 3) > 1 && gUnk_020391F0 == 0) {
                if (gUnk_020392C4 != 0) {
                    r = 0;
                } else {
                    r = sub_0833DBC8();
                }
            } else {
                if (gUnk_020392C4 != 0) {
                    r = 0;
                } else if (gUnk_020391F0 != 0) {
                    r = 0;
                } else if (gUnk_0203916C == 4) {
                    r = sub_0833DCB0();
                } else {
                    r = sub_0833DBF4();
                }
            }
            switch ((u8)r) {
            case 1:
                sub_0833A8C8(0x38);
                break;
            case 2:
                if (gUnk_0203916C == 2 || gUnk_0203916C == 0xE || gUnk_0203916C == 0
                    || gUnk_0203916C == 7 || gUnk_0203916C == 6 || gUnk_0203916C == 9
                    || gUnk_0203916C == 5 || gUnk_0203916C == 0x11 || gUnk_0203916C == 1
                    || gUnk_0203916C == 3 || gUnk_0203916C == 0xC || gUnk_0203916C == 0xD
                    || gUnk_0203916C == 0x10 || gUnk_0203916C == 0xF
                    || gUnk_0203916C == 0x11) {
                    gUnk_020391CC = 1;
                    gUnk_020391F0 = 2;
                    sub_08339B18();
                    *(volatile u16 *)0x04000000 &= 0xEFFF;
                }
                sub_0833D288(0x19, 0);
                break;
            case 0x27:
                flag = 1;
                break;
            }
        }
        if (gUnk_020390EC != 0) {
            rr = sub_0833C874();
            if (rr != 0) {
                gUnk_02039154 = 1;
                return 1;
            }
            gUnk_020390D0 = rr;
            do
                ;
            while (gUnk_020390D0 == 0);
        } else {
            gUnk_020390D0 = 0;
            first = gUnk_020390D0;
            if (first == 0) {
                do
                    ;
                while (gUnk_020390D0 == 0);
            }
        }
        gUnk_020390AC = gUnk_020390AC + 1;
        if (gUnk_020391F0 == 2 && gUnk_020392C4 == 0)
            gUnk_02039154 = 1;
    }
    if (flag != 0)
        return 1;
    sub_0833B074(gUnk_08338FB0);
    return 0;
}
