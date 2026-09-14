/*
 * sub_0800A80C quarantine notes (896/876 bytes, 2026-09-14):
 * Structure, branch layout, calls, and pools all match. Remaining diffs:
 * 1. GCSE PRE hoists (plus a 0x7C) to the join after the sub_0800D248 if-block
 *    (bb6/bb7), spilling it across the do-while loop: str/ldr [sp,#0x14] and
 *    sub sp,#24 vs ROM's recompute-per-use and sub sp,#20. Defeated nested-if,
 *    &&-form, and goto-loop variants (goto loop DID fix the same hoist for
 *    a+0x55/0x3E/0xE8/0x40 - those needed the && forms, not nested ifs).
 * 2. Third zero store: fresh `movs #0xA4; lsls #1` instead of ROM's
 *    `adds r2, #4` reuse of the 0x144 constant. Tried: array field
 *    unk144[1], (&a->unk144)[1], *(&a->unk144+1) - expander flattens all.
 * 3. Register-web: flag's zero/-1 constants computed in r4 vs ROM r0, plus
 *    scattered r1<->r2 r4<->r0 homes (pure register names, same count).
 * Fixed along the way: 20-byte dead frame via u8 unused[20]; goto loop for
 * the sub_08006A34 retry loop; x-temp before the unk40 store (moves the
 * address computation after the division); s32 sub_0800C164 prototype
 * (direct cmp r0,#0 instead of lsls#24/lsrs#24 narrowing).
 */
#include "global.h"

struct Car0800A80C {
    s32 unk00;                          /* 0x00 */
    u8 pad04[4];
    s32 unk08;                          /* 0x08 */
    s32 unk0C;                          /* 0x0C */
    u8 pad10[4];
    s32 unk14;                          /* 0x14 */
    u8 pad18[0x2C - 0x18];
    s32 unk2C;                          /* 0x2C */
    u8 pad30[4];
    u16 unk34;                          /* 0x34 */
    u8 pad36[0x3C - 0x36];
    s16 unk3C;                          /* 0x3C */
    u8 unk3E;                           /* 0x3E */
    u8 pad3F[1];
    u16 unk40;                          /* 0x40 */
    u8 pad42[6];
    s32 unk48;                          /* 0x48 */
    u8 pad4C[4];
    s32 unk50;                          /* 0x50 */
    u8 pad54[1];
    u8 unk55;                           /* 0x55 */
    u8 pad56[0x7C - 0x56];
    u8 unk7C;                           /* 0x7C */
    u8 pad7D[0x88 - 0x7D];
    s32 unk88;                          /* 0x88 */
    u8 pad8C[0xE8 - 0x8C];
    u16 *unkE8;                         /* 0xE8 */
    u8 padEC[0x140 - 0xEC];
    s32 unk140;                         /* 0x140 */
    s32 unk144[2];                      /* 0x144, 0x148 */
    s32 unk14C;                         /* 0x14C */
    u8 pad150[0x170 - 0x150];
    u8 unk170;                          /* 0x170 */
    u8 unk171;                          /* 0x171 */
    u8 pad172[4];
    u8 unk176;                          /* 0x176 */
    u8 pad177[0x18C - 0x177];
    u16 unk18C;                         /* 0x18C */
};

extern u8 gUnk_0200215C;           /* 0x0200215C */
extern u8 gUnk_020020CC;           /* 0x020020CC */
extern u8 gUnk_020020DC;           /* 0x020020DC */
extern u8 gUnk_020020A8;           /* 0x020020A8 */
extern u8 gUnk_020020BC;           /* 0x020020BC */
extern u8 gUnk_020020E0;           /* 0x020020E0 */
extern u8 gUnk_020021E0;           /* 0x020021E0 */
extern u8 gUnk_0202EF00[];         /* 0x0202EF00 */
extern u8 gUnk_0202EF90;           /* 0x0202EF90 */
extern u8 gUnk_0202EEB0;           /* 0x0202EEB0 */
extern struct Car0800A80C gUnk_0202A550[];
extern u16 gUnk_08368290[];        /* 0x08368290 */

void sub_08007C44(struct Car0800A80C *a);
void sub_0800A708(struct Car0800A80C *a, u16 keys);
void sub_0800A2D4(s32 *a);
void sub_0800A084(struct Car0800A80C *a, s32 keys);
void sub_08008480(struct Car0800A80C *a, u8 b);
void sub_0800A310(struct Car0800A80C *a);
s32 sub_0800D248(struct Car0800A80C *a);
s32 sub_0800C164(u8 *a);
void sub_0800D684(struct Car0800A80C *a);
u8 sub_08006A34(struct Car0800A80C *p, u8 a1);
void sub_0800B618(u8 a, u8 b);
void sub_08001208(u16 idx);

void sub_0800A80C(struct Car0800A80C *a, s32 keys, u8 c)
{
    s32 flag;
    s32 v;
    s32 sq;
    s32 x;
    s8 r;
    u8 unused[20];

    a->unk140 = 0;
    a->unk144[0] = 0;
    a->unk144[1] = 0;
    sub_08007C44(a);
    if (a->unk55 != 0)
        a->unk55--;
    sub_0800A708(a, (u16)keys);
    sub_0800A2D4((s32 *)a);
    sub_0800A084(a, keys);
    sub_08008480(a, c);
    flag = 0;
    sub_0800A310(a);
    if (gUnk_0200215C == 4 || gUnk_020020CC <= 0xB) {
        if (((u8 *)a)[0x175] == 0)
            flag = sub_0800D248(a);
    }
    if (flag != 0 && (u8)(a->unk7C - 1) <= 2)
        flag = -1;
    v = a->unk2C >> 6;
    sq = v * v;
    a->unk14C = sq;
    if (v > 0)
        a->unk14C = -sq;
    if (gUnk_020020DC != 0 || gUnk_0200215C == 4 || gUnk_0200215C == 3) {
        a->unk14C /= 0xD7;
    } else {
        if (a == gUnk_0202A550 || gUnk_0200215C == 9 || gUnk_0200215C == 0xD
            || gUnk_0200215C == 0xE || gUnk_0200215C == 0xF || gUnk_0200215C == 0x11
            || gUnk_0200215C == 4) {
            if (a->unk170 != 0)
                a->unk14C /= 0xFA;
            else if (a->unk171 != 0)
                a->unk14C /= 0x64;
            else
                a->unk14C /= 0x1E0;
        } else {
            a->unk14C /= gUnk_08368290[gUnk_020020CC];
        }
    }
    if (gUnk_020020A8 != 0 && (u8)(gUnk_0200215C - 3) <= 1)
        a->unk14C = 0;
    if ((a == gUnk_0202A550 || gUnk_020020DC != 0)
        && gUnk_0200215C != 9 && gUnk_0200215C != 0xD && gUnk_0200215C != 0xE
        && gUnk_0200215C != 0xF && gUnk_0200215C != 0x11) {
        if (sub_0800C164((u8 *)a) != 0 || a->unk176 != 0) {
            if (a->unk176 != 0)
                a->unk176--;
            a->unk14C = (a->unk14C * 3) >> 2;
            sub_0800B618(c, 0);
            sub_0800B618(c, 1);
        }
    }
    if (gUnk_0200215C != 2)
        sub_0800D684(a);
    a->unk18C = a->unk50;
loop:
    r = sub_08006A34(a, c);
    gUnk_020020BC = r;
    if (r != 0)
        goto loop;
    a->unk00 += a->unk0C;
    a->unk08 += a->unk14;
    a->unk34 += a->unk3C;
    if (flag != 0) {
        if (gUnk_020020E0 == 0 && gUnk_020021E0 == 0 && gUnk_0202EF00[3] != 0) {
            if (gUnk_020020DC == 0) {
                if (a == gUnk_0202A550)
                    sub_08001208(0x12);
            } else if (a == &gUnk_0202A550[gUnk_0202EF90 * 0x190]) {
                sub_08001208(0x12);
            }
        }
    }
    if ((u8)(a->unk7C - 5) > 2 && gUnk_0202EEB0 != 0)
        a->unk88 -= flag >> 12;
    a->unk55 = 6;
    sub_0800A2D4((s32 *)a);
    a->unk48 = a->unk2C;
    if (a->unk2C > 0)
        a->unk48 = 0;
    x = (a->unk48 << 8) / -a->unkE8[a->unk3E];
    a->unk40 = x;
    a->unk0C += a->unk140;
    a->unk14 += a->unk144[0];
    a->unk3C += (s16)a->unk144[1];
    a->unk3C = (a->unk3C * 31) >> 5;
}
