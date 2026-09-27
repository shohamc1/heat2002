/*
 * UpdateLapProgress -- SOLVED: MATCH, 2240 bytes @ 0x08006A34 (campaign 2026-09-15).
 * Three levers closed the last three sites of the wave-6 draft:
 *
 *  0x08006B84 (X/Y r5<->r6): pin dx/dy with register asm, assigned INSIDE
 *     the det-check expression. A separate initialiser statement moves the
 *     subtraction ahead of the first multiply.
 *
 *  0x08006C98 (time sum in r2, ROM r1): block_alloc ties the sum to the
 *     dying partial, and combine_regs refuses a tie for a pseudo that is not
 *     block-local. One function-scope `time`, assigned at both unsigned
 *     compare sites (the only two of seven time sums the ROM puts in r1),
 *     makes the sum multi-block, so it takes the first free register.
 *
 *  0x08006CE0 (-1 as movs #255, ROM subs r0, r1, #1): compute the -1 in an
 *     int temp (`s32 m = z - 1;`). Written straight into the u8 field it is
 *     narrowed to QImode, CSE rewrites the zero to the 4C store's QI zero,
 *     and combine folds it because that zero has no other use. In SImode, CSE
 *     picks the SImode zero that the 4E store also uses, combine cannot drop
 *     it, and CSE keeps (plus zero -1) because const -1 costs more on Thumb.
 */

#include "global.h"

struct Car {
    s32 posX;                          /* 0x00 */
    u8 pad04[4];
    s32 posZ;                          /* 0x08 */
    s32 velX;                          /* 0x0C */
    u8 pad10[4];
    s32 velZ;                          /* 0x14 */
    u8 pad18[0x2C - 0x18];
    s32 speed;                          /* 0x2C */
    u8 pad30[4];
    u16 heading;                          /* 0x34 */
    u16 unk36;                          /* 0x36 */
    u16 unk38;                          /* 0x38 */
    u8 pad3A[0x4C - 0x3A];
    u8 lap;                           /* 0x4C */
    u8 waypoint;                           /* 0x4D */
    u8 subStep;                           /* 0x4E */
    s32 progress;                          /* 0x50 */
    u8 pad54[0x150 - 0x54];
    u8 racePosition;                         /* 0x150 */
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

extern volatile u8 gIsLinkRace;
extern u8 gUnk_020020BC;
extern u8 gOptions[];
extern u8 gLinkPlayerId;
extern u8 gNumLinkPlayers[];
extern u8 gNumCars[];
extern u8 gUnk_0202CAF0;
extern u8 gUnk_0200215C;
extern u32 gUnk_0202ED84;
extern u8 gUnk_0202EEE4;
extern u8 gUnk_0202ED70;
extern struct Car gCars[];
extern u8 gUnk_0202524C;
extern u16 gUnk_02025218;
extern u16 gUnk_020251FC;
extern u16 gUnk_020253CC;
extern u8 gIsDemo;
extern u8 gUnk_020021E0;
extern u32 gUnk_0202CB40[];
extern u32 gUnk_020253B8;
extern u8 gUnk_0202F030;
extern struct Track *gUnk_020253D0;
extern u8 gNumLaps;
extern u8 gUnk_0202CBD0;
extern u32 gUnk_0202CC20;
extern u16 gUnk_02025260;
extern u16 gUnk_02025220;
extern u16 gUnk_02025224;
extern u8 gUnk_020253D4;
extern u8 gUnk_020253E0[];

extern void EndRace(void);
extern void RecordFinishTime(struct Car *p);
extern void CheckTrackRecord(u16 a, u16 b, u16 c);
extern void sub_0800B3D4(u16 a, u16 b, u16 c);
extern void sub_0800B540(void);
extern void sub_0800B2C4(void);
extern void ResetLapTimer(void);
extern void sub_08005598(u8 x);
extern void m4aSongNumStart(u16 idx);
extern void sub_08016D28(u8 a);

u8 UpdateLapProgress(struct Car *p, u8 a1)
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
    u32 time;

    v58 = 3 - gOptions[0];
    gUnk_020020BC = 0;
    v6C = gIsLinkRace != 0 ? gLinkPlayerId : 0;
    if (gIsLinkRace != 0)
        v68 = gNumLinkPlayers[0];
    else
        v68 = gNumCars[0];

    e = &gUnk_020253D0[p->waypoint];
    b = e + 1;
    if (e->unk10 == 1)
        b = gUnk_020253D0;

    corners[0] = p->posX >> 16;
    corners[1] = p->posZ >> 16;
    corners[2] = (p->posX + p->velX) >> 16;
    corners[3] = (p->posZ + p->velZ) >> 16;

    x0 = e->f0;
    x1 = e->f4;
    x2 = e->f8;
    x3 = e->fC;
    y0 = b->f0;
    y1 = b->f4;
    y2 = b->f8;
    y3 = b->fC;

    l0 = (x0 * (16 - p->subStep) + y0 * p->subStep) >> 4;
    l8 = (x2 * (16 - p->subStep) + y2 * p->subStep) >> 4;
    l4 = (x1 * (16 - p->subStep) + y1 * p->subStep) >> 4;
    lC = (x3 * (16 - p->subStep) + y3 * p->subStep) >> 4;

    p->progress = ((s8)p->lap << 16) + p->waypoint * 16 + p->subStep;

    det = (corners[2] - corners[0]) * (lC - l4)
        - (corners[3] - corners[1]) * (l8 - l0);
    if (det == 0)
        return 0;
    {
    register s32 dx asm("r6");
    register s32 dy asm("r5");
    if ((u32)((((dx = corners[1] - l4) * (l8 - l0) - (dy = corners[0] - l0) * (lC - l4)) << 8) / det) > 0x100)
        return 0;
    if ((u32)((((dx) * (corners[2] - corners[0]) - (corners[3] - corners[1]) * (dy)) << 8) / det) > 0x100)
        return 0;
    }

    if (p->unk174 == 0) {
        p->unk174 = 1;
        gUnk_0202CAF0 = gUnk_0202CAF0 + 1;
    }
    p->subStep = p->subStep + 1;
    gUnk_020020BC = 1;
    p->progress = ((s8)p->lap << 16) + p->waypoint * 16 + p->subStep;
    if (p->subStep != 0x10)
        return 1;
    p->subStep = 0;
    if (p == gCars && gUnk_0200215C == 0x10 && gUnk_0202ED70 == 9) {
        gUnk_0202CB40[p->waypoint] = -p->speed / 7000;
    }
    p->unk36 = p->heading;
    p->unk38 = p->waypoint;
    {
    s32 t = e->unk10;
    if (t == 1) {
        p->unk17C = gUnk_020253B8;
        if (p == gCars) {
            s32 v = 1;
            u16 w;
            gUnk_0202524C = (w = -v);
        }
        if (gUnk_0200215C == 0x0C) {
            if ((time = gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC) < gUnk_0202ED84)
                gUnk_0202EEE4 = t;
        }
        if (a1 == v6C && gUnk_0200215C != 0x0C && p->unk166 != 0) {
            p->unk167 = 0x1E;
            p->unk168 = p->unk168 + 1;
        }
        p->lap = p->lap + 1;
        {
        s32 z = 0;
        s32 m = z - 1;
        p->waypoint = m;
        }
        p->subStep = 0;
        p->progress = ((s8)p->lap << 16) + p->waypoint * 16;
        if (a1 == v6C) {
            if (gUnk_0202F030 != 0 && p->unk18E != 0)
                CheckTrackRecord(gUnk_02025218, gUnk_020251FC, gUnk_020253CC);
        }
        if (gUnk_0200215C == 0x10) {
            if (gUnk_0202ED70 == 1) {
                if (gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC <= 0x7D00)
                    gUnk_0202EEE4 = gUnk_0202ED70;
                EndRace();
            }
            if (gUnk_0202ED70 == 2) {
                if (a1 == 0 && *(s8 *)&p->lap == gNumLaps) {
                    EndRace();
                    if (gCars[0].racePosition <= 2)
                        gUnk_0202EEE4 = 1;
                }
            }
            if (gUnk_0202ED70 == 3) {
                if (a1 == 0 && *(s8 *)&p->lap == gNumLaps) {
                    if (gCars[0].racePosition == 0 && gUnk_0202CBD0 != 0)
                        gUnk_0202EEE4 = 1;
                    EndRace();
                }
            }
            if (gUnk_0202ED70 == 5) {
                if (p == gCars) {
                    if (p->unk166 != 0) {
                        gUnk_0202EEE4 = 1;
                        EndRace();
                    }
                    if (*(s8 *)&p->lap == gNumLaps)
                        EndRace();
                }
            }
            if (gUnk_0202ED70 == 6) {
                if (a1 == 0 && *(s8 *)&p->lap == gNumLaps) {
                    EndRace();
                    if (gCars[0].racePosition == 0)
                        gUnk_0202EEE4 = 1;
                }
            }
            if (gUnk_0202ED70 == 7) {
                if (gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC <= 0x68CE) {
                    gUnk_0202EEE4 = 1;
                    EndRace();
                }
            }
            if (gUnk_0202ED70 == 8) {
                if (gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC <= 0x6E87) {
                    gUnk_0202EEE4 = 1;
                    EndRace();
                }
            }
            if (gUnk_0202ED70 == 0xA) {
                if (p == gCars && *(s8 *)&p->lap == gNumLaps) {
                    if (p->racePosition == 0)
                        gUnk_0202EEE4 = 1;
                    EndRace();
                }
            }
            if (gUnk_0202ED70 == 0xB) {
                if (p == gCars && *(s8 *)&p->lap == gNumLaps) {
                    if (p->racePosition == 0)
                        gUnk_0202EEE4 = 1;
                    EndRace();
                }
            }
            if (gUnk_0202ED70 == 0xC) {
                if (p == gCars) {
                    if (p->unk166 != 0) {
                        gUnk_0202EEE4 = 1;
                        EndRace();
                    }
                    if (*(s8 *)&p->lap == gNumLaps)
                        EndRace();
                }
            }
            if (gUnk_0202ED70 == 0xD) {
                if (p == gCars && *(s8 *)&p->lap == gNumLaps) {
                    if (p->racePosition == 0)
                        gUnk_0202EEE4 = 1;
                    EndRace();
                }
            }
            if (gUnk_0202ED70 == 0xE) {
                if (p == gCars) {
                    if (p->racePosition == 0 && *(s8 *)&p->lap == gNumLaps) {
                        gUnk_0202EEE4 = 1;
                        EndRace();
                    }
                    if (p == gCars && *(s8 *)&p->lap == gNumLaps)
                        EndRace();
                }
            }
            if (gUnk_0202ED70 == 0xF) {
                if (p == gCars) {
                    if (p->racePosition == 0 && *(s8 *)&p->lap == gNumLaps) {
                        gUnk_0202EEE4 = 1;
                        EndRace();
                    }
                    if (p == gCars && *(s8 *)&p->lap == gNumLaps)
                        EndRace();
                }
            }
        }
        p->unk166 = 1;
        if (p == gCars && gUnk_0200215C == 5 && p->unk18E != 0) {
            if ((time = gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC) < p->unk16C)
                p->unk16C = gUnk_02025218 * 60000 + gUnk_020251FC * 1000 + gUnk_020253CC;
        }
        if (*(s8 *)&p->lap == gNumLaps) {
            if (gUnk_0200215C == 0 || gUnk_0200215C == 6 || gUnk_0200215C == 1)
                p->unk16C = gUnk_02025260 * 60000 + gUnk_02025220 * 1000 + gUnk_02025224;
            if (a1 == v6C && p->unk18E != 0)
                sub_0800B3D4(gUnk_02025218, gUnk_020251FC, gUnk_020253CC);
            if (gUnk_0200215C != 2) {
                RecordFinishTime(p);
                gUnk_020253E0[gUnk_020253D4] = a1;
                gUnk_020253D4 = gUnk_020253D4 + 1;
                if ((u8)(gUnk_0200215C - 3) <= 1)
                    p->unk16C = gUnk_02025260 * 60000 + gUnk_02025220 * 1000 + gUnk_02025224;
                if (a1 == v6C) {
                    s32 v2 = *(volatile u8 *)&gUnk_0200215C;
                    if (v2 == 0 || v2 == 6 || v2 == 1) {
                        /* sub_08016D28: the ROM call passes no argument; the matched definition takes one; call
                           through a function pointer with the old prototype. */
                        ((void (*)(void))sub_08016D28)();
                        EndRace();
                    }
                }
                if (gUnk_020253D4 == v68) {
                    if (gUnk_0200215C != 0x10) {
                        if (gUnk_0200215C != 0xF) {
                            if (gUnk_0200215C != 2) {
                                if (gUnk_0200215C != 0xE)
                                    EndRace();
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
            ResetLapTimer();
    }
    }

    if ((u16)(e->unk10 - 1) <= 1) {
        if (a1 == v6C) {
            gUnk_0202CC20 = p->unk15C;
            if (e->unk10 != 1)
                sub_0800B540();
            if (gOptions[3] != 0 && gIsDemo == 0 && gUnk_020021E0 == 0)
                m4aSongNumStart(0x33);
            if (a1 == v6C && gUnk_0200215C != 0xA) {
                s32 inner = v58 / 2 + 6;
                sub_08005598((u8)(e->unk14 + inner));
            }
        }
        {
        s32 t2 = e->unk10;
        if (t2 == 1 && p->unk18E == 0) {
            if (p == gCars)
                sub_0800B2C4();
            p->unk18E = t2;
        }
        }
    }
    p->waypoint = p->waypoint + 1;
    return 1;
}
