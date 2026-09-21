#include "global.h"

struct Trk {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    u16 unk10;
    u8 pad12[2];
    u8 unk14;
    u8 pad15[3];
};

struct Ent {
    s32 unk00;
    u8 pad04[4];
    s32 unk08;
    s32 unk0C;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[0x34 - 0x18];
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u8 pad3A[0x4C - 0x3A];
    s8 unk4C;
    u8 unk4D;
    u8 unk4E;
    u8 pad4F;
    s32 unk50;
    u8 pad54[0x15C - 0x54];
    s32 unk15C;
    u8 pad160[0x166 - 0x160];
    u8 unk166;
    u8 unk167;
    u8 unk168;
    u8 pad169[0x16C - 0x169];
    u32 unk16C;
    u8 pad170[0x174 - 0x170];
    u8 unk174;
    u8 pad175[0x18E - 0x175];
    u8 unk18E;
};

extern u8 gUnk_0203E120;
extern u8 gUnk_020390CC;
extern u8 gUnk_020390EC;
extern u8 gUnk_0203E1B0;
extern u8 gUnk_020390BC;
extern u8 gUnk_020390A0;
extern struct Trk *gUnk_0203B860;
extern u8 gUnk_0203DD10;
extern u8 gUnk_0203916C;
extern u16 gUnk_0203B6C8;
extern u16 gUnk_0203B6A8;
extern u16 gUnk_0203B858;
extern u32 gUnk_0203DFC4;
extern u8 gUnk_0203E104;
extern u8 gUnk_0203E1E0;
extern u8 gUnk_02039194;
extern u16 gUnk_0203B704;
extern u16 gUnk_0203B6D0;
extern u16 gUnk_0203B6D4;
extern u8 gUnk_0203B868[];
extern u8 gUnk_0203B864;
extern u32 gUnk_0203DE40;

void sub_0833E05C(void);
void sub_0833E094(u8);
void sub_0833E160(u16, u16, u16);
void sub_08341EC8(u16 *);
void sub_08342908(void);
void sub_08342A94(void);
void sub_08342BA4(u32, u32, u32);
void sub_08342D10(void);
u32 sub_08344BB8(u32, u32);

s32 sub_0833F468(struct Ent *ent, u8 me)
{
    s32 pad0[10];
    s32 v[4];
    s32 pad1[7];
    u8 x58;
    s32 m0;
    s32 m4;
    struct Trk *tr;
    u8 x68;
    u8 x6C;
    u8 *pw;
    s32 dx;
    u8 *pd;
    s8 *pc;
    u8 *pw2;
    s32 a0, a4, a8, aC;
    s32 b0, b4, b8, bC;
    s32 m8;
    s32 z1;
    struct Trk *nx;
    u8 *psel;
    s32 w, iw, mC, z0, x1;
    s32 dz, dm, dn, t1, u1, cross;
    u32 t;

    x58 = 3 - gUnk_0203E120;
    gUnk_020390CC = 0;
    if (gUnk_020390EC != 0)
        x6C = gUnk_0203E1B0;
    else
        x6C = 0;
    if (gUnk_020390EC != 0)
        x68 = *(psel = &gUnk_020390BC);
    else
        x68 = *(psel = &gUnk_020390A0);
    tr = (struct Trk *)((u8 *)gUnk_0203B860 + *(pd = &ent->unk4D) * 24);
    nx = tr + 1;
    if (tr->unk10 == 1)
        nx = gUnk_0203B860;
    v[0] = ent->unk00 >> 16;
    v[1] = z0 = ent->unk08 >> 16;
    v[2] = x1 = (ent->unk00 + ent->unk0C) >> 16;
    v[3] = z1 = (ent->unk08 + ent->unk14) >> 16;
    a0 = tr->unk00;
    a4 = tr->unk04;
    a8 = tr->unk08;
    aC = tr->unk0C;
    b0 = nx->unk00;
    b4 = nx->unk04;
    b8 = nx->unk08;
    bC = nx->unk0C;
    pw = &ent->unk4E;
    w = *pw;
    iw = 16 - w;
    m0 = (a0 * iw + b0 * w) >> 4;
    m8 = (a8 * iw + b8 * w) >> 4;
    m4 = (a4 * iw + b4 * w) >> 4;
    mC = (aC * iw + bC * w) >> 4;
    pc = &ent->unk4C;
    ent->unk50 = ((s32)*pc << 16) + (*pd << 4) + w;
    dx = x1 - v[0];
    dm = mC - m4;
    dz = z1 - z0;
    dn = m8 - m0;
    cross = dx * dm - dz * dn;
    pw2 = pw;
    if (cross == 0)
        return 0;
    t1 = z0 - m4;
    u1 = v[0] - m0;
    if (sub_08344BB8((t1 * dn - u1 * dm) << 8, cross) > 0x100)
        return 0;
    if (sub_08344BB8((t1 * dx - dz * u1) << 8, cross) > 0x100)
        return 0;
    if (ent->unk174 == 0) {
        ent->unk174 = 1;
        gUnk_0203DD10 = gUnk_0203DD10 + 1;
    }
    *pw2 = *pw2 + 1;
    gUnk_020390CC = 1;
    ent->unk50 = ((s32)*pc << 16) + (*pd << 4) + *pw2;
    if (*pw2 == 0x10) {
        *pw2 = 0;
        ent->unk36 = ent->unk34;
        ent->unk38 = *pd;
        if (tr->unk10 == 1) {
            if (gUnk_0203916C == 0xC) {
                if (gUnk_0203B6C8 * 60000 + gUnk_0203B6A8 * 1000 + gUnk_0203B858 < gUnk_0203DFC4)
                    gUnk_0203E104 = tr->unk10;
            }
            if (me == x6C && gUnk_0203916C != 0xC && ent->unk166 != 0) {
                ent->unk167 = 0x1E;
                ent->unk168 = ent->unk168 + 1;
            }
            *pc = *pc + 1;
            *pd = -1;
            *pw2 = 0;
            ent->unk50 = ((s32)*pc << 16) + (*pd << 4);
            if (me == x6C && gUnk_0203E1E0 != 0 && ent->unk18E != 0)
                sub_0833E160(gUnk_0203B6C8, gUnk_0203B6A8, gUnk_0203B858);
            ent->unk166 = 1;
            if (ent == (struct Ent *)0x0203D520 && gUnk_0203916C == 5 && ent->unk18E != 0) {
                t = gUnk_0203B6C8 * 60000 + gUnk_0203B6A8 * 1000 + gUnk_0203B858;
                if (t < ent->unk16C)
                    ent->unk16C = t;
            }
            if ((s32)*pc == gUnk_02039194) {
                if (gUnk_0203916C == 0 || gUnk_0203916C == 6 || gUnk_0203916C == 1)
                    ent->unk16C = gUnk_0203B704 * 60000 + gUnk_0203B6D0 * 1000 + gUnk_0203B6D4;
                if (me == x6C && ent->unk18E != 0)
                    sub_08342BA4(gUnk_0203B6C8, gUnk_0203B6A8, gUnk_0203B858);
                if (gUnk_0203916C != 2) {
                    sub_08341EC8((u16 *)ent);
                    gUnk_0203B868[gUnk_0203B864] = me;
                    gUnk_0203B864 = gUnk_0203B864 + 1;
                    if ((u8)(gUnk_0203916C - 3) <= 1)
                        ent->unk16C = gUnk_0203B704 * 60000 + gUnk_0203B6D0 * 1000 + gUnk_0203B6D4;
                    if (gUnk_0203B864 == x68 && gUnk_0203916C != 0x10 && gUnk_0203916C != 0xF
                        && gUnk_0203916C != 2 && gUnk_0203916C != 0xE)
                        sub_08342908();
                }
            } else {
                if (me == x6C && ent->unk18E != 0)
                    sub_08342BA4(gUnk_0203B6C8, gUnk_0203B6A8, gUnk_0203B858);
            }
            if (me == x6C)
                sub_0833E05C();
        }
        if ((u16)(tr->unk10 - 1) <= 1) {
            if (me == x6C) {
                gUnk_0203DE40 = ent->unk15C;
                if (tr->unk10 != 1)
                    sub_08342D10();
                if (gUnk_0203916C != 0xA)
                    sub_0833E094(tr->unk14 + ((x58 >> 1) + 6));
            }
            if (tr->unk10 == 1 && ent->unk18E == 0) {
                if (ent == (struct Ent *)0x0203D520)
                    sub_08342A94();
                ent->unk18E = tr->unk10;
            }
        }
        *pd = *pd + 1;
    }
    return 1;
}
