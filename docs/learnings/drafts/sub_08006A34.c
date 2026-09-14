/*
 * QUARANTINED (wave 5): 2240/2240 bytes, 10 bytes differ (3 sites), from a
 * FRESH rebuild (rm .o; make .o; match.py). All size/structure/pool issues
 * from the wave-4 draft are fixed. Remaining diff (all register-allocation
 * / one instruction choice, verified from fresh build):
 *
 *   0x8006b84/b86/b8e/b90/baa/bb0: determinant pseudos swapped.
 *     target: subs r6(r0,r1); adds r0,r6; ... subs r5(r3,r1); adds r1,r5;
 *             ... adds r0,r6; muls r0,r3; ... muls r1,r5
 *     ours:   same instructions with r5<->r6 swapped (P1=second-product
 *             difference in r5, P2 in r6; target homes P1 in r6, P2 in r5).
 *     Cause: global-alloc ordering of these two CSE'd subtractions.
 *     Swept: hoisting both into locals (breaks early spills), pinning one
 *     to r6 via `register asm("r6")` (rebuilds whole allocation badly),
 *     swapping l0/l4 and x0../y0.. declaration orders (no effect / breaks),
 *     negating det+both conds together (flips det block codegen).
 *
 *   0x8006c98/c9e: final time-sum add in the 0x0C block.
 *     target: adds r1, r0, r2 ; cmp r1, r0   (new pseudo r1)
 *     ours:   adds r2, r0, r2 ; cmp r2, r0   (coalesced into dying r2)
 *     Swept: commuting the expression to `253CC + (25218*60000+251FC*1000)`
 *     (breaks computation order), regrouping parens (no effect).
 *
 *   0x8006ce0: p->unk4D = -1 materialization.
 *     target: subs r0, r1, #1   (r1 = hoisted zero also stored to unk4E)
 *     ours:   movs r0, #255
 *     Cause: target reuses the unk4E-store's hoisted zero pseudo as the
 *     minuend; every source shape that shares that pseudo either folds the
 *     -1 back to a constant (CSE knows the zero) or stores unk4E too early.
 *     Swept: z locals (s32/u8/u16) before/after unk4C++, (z = 0) - 1,
 *     (p->unk4E = (z = 0)) - 1 (keeps subs but wrong store order),
 *     p->unk4E - 1 (real ldrb), ~10 toy-verified shapes.
 *
 * Fixes landed since wave 4 (all verified byte-exact):
 *   - u16 locals for e->unk10 reads inlined as s32 t / s32 t2 (kills the
 *     decl-init convert_move copies; s32 avoids store_expr's promoted-var
 *     copy branch); values survive QI stores because they live in pseudos,
 *     not CSE (char-alias-set-0 stores kill all memory CSE - proven).
 *   - -1 store to gUnk_0202524C written as `s32 v = 1; u16 w;
 *     gUnk_0202524C = (w = -v);` (address-first + movs#1+negs + copy).
 *   - gUnk_0200215C != 0x10/0xF/2/0xE chain as NESTED ifs (fold_range_test
 *     folds adjacent != pairs into (u8)(x-15)<=1 otherwise).
 *   - ==5 and ==0xC blocks: unk4C==2184 check nested INSIDE p==A550.
 *   - (u16)(e->unk10-1)<=1 block also guards the trailing ==1/t2 block.
 *   - gUnk_0200215C != 2 block CONTAINS the (x-3)/16D28/253D4 statements.
 *   - sub_08005598 arg: `s32 inner = v58/2+6; (u8)(e->unk14 + inner)`.
 *   - the second 0/6/1 || chain re-reads via
 *     `s32 v2 = *(volatile u8 *)&gUnk_0200215C;` (forces the ldrb r0,[r4]
 *     reload + keeps r4 as the address; plain reads get CSE'd into a
 *     callee-saved value + lsls/lsrs #24 narrowing).
 * NOTE: the wave-4 header's "inlined sub_080072F4 tail" theory was stale -
 * this draft never contained that inline; the object was 2256B due to the
 * reload/copy issues above. sub_08006A34 ends at 0x80072F4 exactly where
 * sub_080072F4 begins (fallthrough-free, no call needed).
 */
#include "global.h"

struct Car {
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
    u16 unk36;                          /* 0x36 */
    u16 unk38;                          /* 0x38 */
    u8 pad3A[0x4C - 0x3A];
    u8 unk4C;                           /* 0x4C */
    u8 unk4D;                           /* 0x4D */
    u8 unk4E;                           /* 0x4E */
    s32 unk50;                          /* 0x50 */
    u8 pad54[0x150 - 0x54];
    u8 unk150;                         /* 0x150 */
    u8 pad151[0x15C - 0x151];
    u32 unk15C;                         /* 0x15C */
    u8 pad160[0x166 - 0x160];
    u8 unk166;                          /* 0x166 */
    u8 unk167;                          /* 0x167 */
    u8 unk168;                          /* 0x168 */
    u8 pad169[0x16C - 0x169];
    u32 unk16C;                         /* 0x16C */
    u8 pad170[0x174 - 0x170];
    u8 unk174;                          /* 0x174 */
    u8 pad175[0x17C - 0x175];
    u32 unk17C;                         /* 0x17C */
    u8 pad180[0x18E - 0x180];
    u8 unk18E;                          /* 0x18E */
};

struct Track {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u16 unk10;
    u8 pad12[2];
    u8 unk14;
    u8 pad15[3];
};

extern volatile u8 gUnk_020020DC;
extern u8 gUnk_020020BC;
extern u8 gUnk_0202EF00[];
extern u8 gUnk_0202EF90;
extern u8 gUnk_020020AC[];
extern u8 gUnk_02002090[];
extern u8 gUnk_0202CAF0;
extern u8 gUnk_0200215C;
extern u32 gUnk_0202ED84;
extern u8 gUnk_0202EEE4;
extern u8 gUnk_0202ED70;
extern struct Car gUnk_0202A550[];
extern u8 gUnk_0202524C;
extern u16 gUnk_02025218;
extern u16 gUnk_020251FC;
extern u16 gUnk_020253CC;
extern u8 gUnk_020020E0;
extern u8 gUnk_020021E0;
extern u32 gUnk_0202CB40[];
extern u32 gUnk_020253B8;
extern u8 gUnk_0202F030;
extern struct Track *gUnk_020253D0;
extern u8 gUnk_02002184;
extern u8 gUnk_0202CBD0;
extern u32 gUnk_0202CC20;
extern u16 gUnk_02025260;
extern u16 gUnk_02025220;
extern u16 gUnk_02025224;
extern u8 gUnk_020253D4;
extern u8 gUnk_020253E0[];

extern void sub_0800AFF0(void);
extern void sub_0800A438(struct Car *p);
extern void sub_08005664(u16 a, u16 b, u16 c);
extern void sub_0800B3D4(u16 a, u16 b, u16 c);
extern void sub_0800B540(void);
extern void sub_0800B2C4(void);
extern void sub_08005560(void);
extern void sub_08005598(u8 x);
extern void sub_08001208(u16 idx);
extern void sub_08016D28(void);

u8 sub_08006A34(struct Car *p, u8 a1)
{
    u8 unused1[40];
    s32 corners[4];
    u8 unused2[28];
    u8 v58;
    s32 l0, l4, l8, lC;
    struct Track *e, *b;
    u8 v68, v6C;
    s32 x0, x1, x2, x3, y0, y1, y2, y3;
    s32 det;

    v58 = 3 - gUnk_0202EF00[0];
    gUnk_020020BC = 0;
    v6C = gUnk_020020DC != 0 ? gUnk_0202EF90 : 0;
    if (gUnk_020020DC != 0)
        v68 = gUnk_020020AC[0];
    else
        v68 = gUnk_02002090[0];

    e = &gUnk_020253D0[p->unk4D];
    b = e + 1;
    if (e->unk10 == 1)
        b = gUnk_020253D0;

    corners[0] = p->unk00 >> 16;
    corners[1] = p->unk08 >> 16;
    corners[2] = (p->unk00 + p->unk0C) >> 16;
    corners[3] = (p->unk08 + p->unk14) >> 16;

    x0 = e->f0;
    x1 = e->f4;
    x2 = e->f8;
    x3 = e->fC;
    y0 = b->f0;
    y1 = b->f4;
    y2 = b->f8;
    y3 = b->fC;

    l0 = (x0 * (16 - p->unk4E) + y0 * p->unk4E) >> 4;
    l8 = (x2 * (16 - p->unk4E) + y2 * p->unk4E) >> 4;
    l4 = (x1 * (16 - p->unk4E) + y1 * p->unk4E) >> 4;
    lC = (x3 * (16 - p->unk4E) + y3 * p->unk4E) >> 4;

    p->unk50 = ((s8)p->unk4C << 16) + p->unk4D * 16 + p->unk4E;

    det = (corners[2] - corners[0]) * (lC - l4)
        - (corners[3] - corners[1]) * (l8 - l0);
    if (det == 0)
        return 0;
    if ((u32)((((corners[1] - l4) * (l8 - l0) - (corners[0] - l0) * (lC - l4)) << 8) / det) > 0x100)
        return 0;
    if ((u32)((((corners[1] - l4) * (corners[2] - corners[0]) - (corners[3] - corners[1]) * (corners[0] - l0)) << 8) / det) > 0x100)
        return 0;

    if (p->unk174 == 0) {
        p->unk174 = 1;
        gUnk_0202CAF0 = gUnk_0202CAF0 + 1;
    }
    p->unk4E = p->unk4E + 1;
    gUnk_020020BC = 1;
    p->unk50 = ((s8)p->unk4C << 16) + p->unk4D * 16 + p->unk4E;
    if (p->unk4E != 0x10)
        return 1;
    p->unk4E = 0;
    if (p == gUnk_0202A550 && gUnk_0200215C == 0x10 && gUnk_0202ED70 == 9) {
        gUnk_0202CB40[p->unk4D] = -p->unk2C / 7000;
    }
    p->unk36 = p->unk34;
    p->unk38 = p->unk4D;
    {
    s32 t = e->unk10;
    if (t == 1) {
        p->unk17C = gUnk_020253B8;
        if (p == gUnk_0202A550) {
            s32 v = 1;
            u16 w;
            gUnk_0202524C = (w = -v);
        }
        if (gUnk_0200215C == 0x0C) {
            if ((u32)(gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC) < gUnk_0202ED84)
                gUnk_0202EEE4 = t;
        }
        if (a1 == v6C && gUnk_0200215C != 0x0C && p->unk166 != 0) {
            p->unk167 = 0x1E;
            p->unk168 = p->unk168 + 1;
        }
        p->unk4C = p->unk4C + 1;
        p->unk4D = -1;
        p->unk4E = 0;
        p->unk50 = ((s8)p->unk4C << 16) + p->unk4D * 16;
        if (a1 == v6C) {
            if (gUnk_0202F030 != 0 && p->unk18E != 0)
                sub_08005664(gUnk_02025218, gUnk_020251FC, gUnk_020253CC);
        }
        if (gUnk_0200215C == 0x10) {
            if (gUnk_0202ED70 == 1) {
                if (gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC <= 0x7D00)
                    gUnk_0202EEE4 = gUnk_0202ED70;
                sub_0800AFF0();
            }
            if (gUnk_0202ED70 == 2) {
                if (a1 == 0 && *(s8 *)&p->unk4C == gUnk_02002184) {
                    sub_0800AFF0();
                    if (gUnk_0202A550[0].unk150 <= 2)
                        gUnk_0202EEE4 = 1;
                }
            }
            if (gUnk_0202ED70 == 3) {
                if (a1 == 0 && *(s8 *)&p->unk4C == gUnk_02002184) {
                    if (gUnk_0202A550[0].unk150 == 0 && gUnk_0202CBD0 != 0)
                        gUnk_0202EEE4 = 1;
                    sub_0800AFF0();
                }
            }
            if (gUnk_0202ED70 == 5) {
                if (p == gUnk_0202A550) {
                    if (p->unk166 != 0) {
                        gUnk_0202EEE4 = 1;
                        sub_0800AFF0();
                    }
                    if (*(s8 *)&p->unk4C == gUnk_02002184)
                        sub_0800AFF0();
                }
            }
            if (gUnk_0202ED70 == 6) {
                if (a1 == 0 && *(s8 *)&p->unk4C == gUnk_02002184) {
                    sub_0800AFF0();
                    if (gUnk_0202A550[0].unk150 == 0)
                        gUnk_0202EEE4 = 1;
                }
            }
            if (gUnk_0202ED70 == 7) {
                if (gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC <= 0x68CE) {
                    gUnk_0202EEE4 = 1;
                    sub_0800AFF0();
                }
            }
            if (gUnk_0202ED70 == 8) {
                if (gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC <= 0x6E87) {
                    gUnk_0202EEE4 = 1;
                    sub_0800AFF0();
                }
            }
            if (gUnk_0202ED70 == 0xA) {
                if (p == gUnk_0202A550 && *(s8 *)&p->unk4C == gUnk_02002184) {
                    if (p->unk150 == 0)
                        gUnk_0202EEE4 = 1;
                    sub_0800AFF0();
                }
            }
            if (gUnk_0202ED70 == 0xB) {
                if (p == gUnk_0202A550 && *(s8 *)&p->unk4C == gUnk_02002184) {
                    if (p->unk150 == 0)
                        gUnk_0202EEE4 = 1;
                    sub_0800AFF0();
                }
            }
            if (gUnk_0202ED70 == 0xC) {
                if (p == gUnk_0202A550) {
                    if (p->unk166 != 0) {
                        gUnk_0202EEE4 = 1;
                        sub_0800AFF0();
                    }
                    if (*(s8 *)&p->unk4C == gUnk_02002184)
                        sub_0800AFF0();
                }
            }
            if (gUnk_0202ED70 == 0xD) {
                if (p == gUnk_0202A550 && *(s8 *)&p->unk4C == gUnk_02002184) {
                    if (p->unk150 == 0)
                        gUnk_0202EEE4 = 1;
                    sub_0800AFF0();
                }
            }
            if (gUnk_0202ED70 == 0xE) {
                if (p == gUnk_0202A550) {
                    if (p->unk150 == 0 && *(s8 *)&p->unk4C == gUnk_02002184) {
                        gUnk_0202EEE4 = 1;
                        sub_0800AFF0();
                    }
                    if (p == gUnk_0202A550 && *(s8 *)&p->unk4C == gUnk_02002184)
                        sub_0800AFF0();
                }
            }
            if (gUnk_0202ED70 == 0xF) {
                if (p == gUnk_0202A550) {
                    if (p->unk150 == 0 && *(s8 *)&p->unk4C == gUnk_02002184) {
                        gUnk_0202EEE4 = 1;
                        sub_0800AFF0();
                    }
                    if (p == gUnk_0202A550 && *(s8 *)&p->unk4C == gUnk_02002184)
                        sub_0800AFF0();
                }
            }
        }
        p->unk166 = 1;
        if (p == gUnk_0202A550 && gUnk_0200215C == 5 && p->unk18E != 0) {
            if ((u32)(gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC) < p->unk16C)
                p->unk16C = gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC;
        }
        if (*(s8 *)&p->unk4C == gUnk_02002184) {
            if (gUnk_0200215C == 0 || gUnk_0200215C == 6 || gUnk_0200215C == 1)
                p->unk16C = gUnk_02025260 * 60000 + gUnk_02025220 * 1000 + gUnk_02025224;
            if (a1 == v6C && p->unk18E != 0)
                sub_0800B3D4(gUnk_02025218, gUnk_020251FC, gUnk_020253CC);
            if (gUnk_0200215C != 2) {
                sub_0800A438(p);
                gUnk_020253E0[gUnk_020253D4] = a1;
                gUnk_020253D4 = gUnk_020253D4 + 1;
                if ((u8)(gUnk_0200215C - 3) <= 1)
                    p->unk16C = gUnk_02025260 * 60000 + gUnk_02025220 * 1000 + gUnk_02025224;
                if (a1 == v6C) {
                    s32 v2 = *(volatile u8 *)&gUnk_0200215C;
                    if (v2 == 0 || v2 == 6 || v2 == 1) {
                        sub_08016D28();
                        sub_0800AFF0();
                    }
                }
                if (gUnk_020253D4 == v68) {
                    if (gUnk_0200215C != 0x10) {
                        if (gUnk_0200215C != 0xF) {
                            if (gUnk_0200215C != 2) {
                                if (gUnk_0200215C != 0xE)
                                    sub_0800AFF0();
                            }
                        }
                    }
                }
            }
        } else {
            if (a1 == v6C && p->unk18E != 0)
                sub_0800B3D4(gUnk_02025218, gUnk_020251FC, gUnk_020253CC);
        }
        if (a1 == v6C)
            sub_08005560();
    }
    }

    if ((u16)(e->unk10 - 1) <= 1) {
        if (a1 == v6C) {
            gUnk_0202CC20 = p->unk15C;
            if (e->unk10 != 1)
                sub_0800B540();
            if (gUnk_0202EF00[3] != 0 && gUnk_020020E0 == 0 && gUnk_020021E0 == 0)
                sub_08001208(0x33);
            if (a1 == v6C && gUnk_0200215C != 0xA) {
                s32 inner = v58 / 2 + 6;
                sub_08005598((u8)(e->unk14 + inner));
            }
        }
        {
        s32 t2 = e->unk10;
        if (t2 == 1 && p->unk18E == 0) {
            if (p == gUnk_0202A550)
                sub_0800B2C4();
            p->unk18E = t2;
        }
        }
    }
    p->unk4D = p->unk4D + 1;
    return 1;
}
