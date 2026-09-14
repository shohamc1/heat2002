/*
 * QUARANTINED (wave 6): 2240/2240 bytes, 10 bytes differ (3 sites), from a
 * FRESH rebuild (rm .o; make .o; match.py). Same 3 sites as wave 5, but the
 * ROOT CAUSES are now fully identified from agbcc source + -dr/-dg dumps
 * (tools/agbcc/gcc/global.c, arm.h). Nothing below is speculation.
 *
 * ALLOCATOR MECHANICS (verified from compiler source + .greg dump):
 *   - global.c allocno_compare: pri = floor_log2(n_refs)*n_refs/live_length
 *     (floor_log2(3)=1, so det: 2*4/24=.333 > Y: 1*3/13=.231 > X: 1*3/14=.214;
 *     dump order: det(45) pos336, Y(178) pos364, X(173) pos374).
 *   - find_reg scans hard regs ASCENDING r0..r15 (NOT REG_ALLOC_ORDER), two
 *     passes; pass 0 skips regs in regs_someone_prefers[] = full-preferences
 *     of CONFLICTING LOWER-priority allocnos (prune_preferences).
 *   - set_preference (global.c:1511) fires on mark_reg_store: a pseudo whose
 *     SET_SRC is an expr takes XEXP(src,0) and gives that operand pseudo a
 *     preference for operand0's HARD REG (local-alloc'd pseudos only).
 *
 * (a) 0x8006b84-bb0 r5<->r6 swap, X=(corners[1]-l4)=pseudo173, Y=(corners[0]-l0)=178:
 *   NATURAL order: det->r4, Y->r5, X->r6 = TARGET. OURS inverts because
 *   A=(corners[2]-corners[0]) (pseudo 160, spilled [sp,#116]) carries a
 *   full-preference for r5: A's def insn 278 is (set A (minus reg158 reg159))
 *   and operand0 reg158 = the corners[2] LOAD pseudo, which LOCAL-alloc put
 *   in r5 (visible at 0x8006b54: subs r0,r5,r0). A conflicts Y (ranges
 *   overlap insns 278..348 vs 311..360) and A is lower priority, so
 *   regs_someone_prefers[Y] gets r5 -> Y's pass 0 skips r5 -> Y=r6; X's pass
 *   0 also skips r5 (A conflicts X too) but pass 1 then takes it -> X=r5.
 *   FIX = make A's operand0 pseudo not be local-alloc'd into r5 (e.g. make
 *   the corners[2] load cross a basic block so it becomes a global pseudo
 *   with reg_renumber<0 at set_preference time -> no preference), or shift
 *   the det-block's local-alloc so 158 lands on any reg but r5. No source
 *   shape found that does this without moving bytes (tried this wave:
 *   yl0/xl4 hoists between checks [pure CSE no-op], new s32 local [frame+8,
 *   pool shift], x0-reuse [loses r7=p], dead expression statements [no-ops:
 *   flow.c RECOUNTS REG_N_REFS per live reference - the stale-refcount
 *   lever does not exist in this compiler], negations/decl-order [wave 5]).
 *
 * (b) 0x8006c98/c9e sum coalesced into dying partial r2:
 *   sum = pseudo 364 (refs=2,len=4), partial = 361 (local, r2). Gen RTL
 *   insn 704: (set 364 (plus 361 363)) -> set_preference gives 364 a COPY
 *   preference for r2 -> find_reg's preference override assigns r2 ->
 *   adds r2,r0,r2. TARGET = r1: needs operand0 != the r2-partial. Writing
 *   `gUnk_020253CC + (a*60000 + b*1000)` swaps operand0 but ALSO moves the
 *   253CC load before the 25218 load (expand is left-to-right) = byte diff.
 *   PARTIAL FIX verified: `det = a*60000+b*1000; if ((u32)(det + c) < ed84)`
 *   inside the ==0x0C block emits adds r1,r0,r4/cmp r1,r0 (sum reg correct!)
 *   but the partial rides det's r4 -> adds r4,r2,r0 defect at 0x8006c92.
 *   Full fix likely falls out of fixing (a) (same global allocation state).
 *
 * (c) 0x8006ce0 movs r0,#255 vs subs r0,r1,#1:
 *   EVERY u8 store to this struct expands as RMW (load; QIzero; and; ior;
 *   subreg; strb); the 4C-store's mask zero (QI pseudo, born between the
 *   adds and the 4C strb = 0x8006cdc movs r1,#0) is the block-canonical
 *   QI zero (CSE merges the 4D/4E stores' mask zeros into it) and reload
 *   gives it r1; the 4E strb r1,[r6] reads it in both builds.
 *   `subs r0,r1,#1` requires the -1 as plus(<that zero>, -1) surviving CSE,
 *   but CSE FOLDS subreg-of-known-const and plus(known-reg,-1) -> const -1
 *   (reload remat: movs r0,#1; negs r0). Only RMW-chain values (assignment
 *   values of u8 stores, which contain the unknown LOAD so CSE cannot fold
 *   and(x,0)) are opaque and keep the subs (verified: (p->unk4E=(t=0))-1
 *   emits subs r0,r3,#1 at exactly the right place), but any such form
 *   stores unk4E BEFORE unk4D (evaluation order is forced), while target
 *   stores 4C,4D,4E in order and unk50's ldrb r2,[r4] read-back needs the
 *   4E store after the 4D store to kill the CSE forwarding record. Also
 *   tried and folded: u8 z local (z-1 folds; z=0 statement before/after
 *   4C++: movs lands at wrong site or plus folds), (u8)t, (u8)(t=0),
 *   (z=0)-1, t=0 early (two movs), p->unk4E-1 (real ldrb), dead stores.
 *   Combine note: plus(x,-1) also folds when the zero-movsi and the plus
 *   are within combine's 3-insn window; the 4C strb between movs@0xcdc and
 *   subs@0xce0 is what protects the target shape.
 *
 * FIXES STILL VALID FROM WAVE 5 HEADER (all landed pre-quarantine).
 * Next lever if revisited: (a) is the master - a source shape that keeps
 * the corners[2] load pseudo out of r5 (or makes it global) should flip
 * X/Y AND likely re-land (b)'s sum into r1 (its r2 is a copy-preference
 * override, not reload inheritance) and possibly (c) via allocation
 * rotation. Dump recipe: cc -E -x c -I include -I tools/agbcc/include
 * -iquote include -nostdinc -undef src/f.c -o x.i;
 * tools/agbcc/old_agbcc -O2 -mthumb-interwork -fhex-asm -dr x.i (gen RTL);
 * -dg = global alloc sorted order + conflicts + post-alloc RTL (identify
 * pseudos by MEM offsets in minus/plus insns; hard regs already show).
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
