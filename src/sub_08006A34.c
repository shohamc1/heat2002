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
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

/* The 0x18-byte track segment record gTrackSegs points at (waypoint
   quads). It shares its old tag name with include/structs.h's 0x64-byte
   struct Track but not its layout or stride, so it keeps a local tag.
   The gTrackSegs extern (variables.h) is typed struct Track *; the
   casts below are pointer casts only and emit nothing. */
struct TrackSeg {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u16 unk10;
    u8 pad12[2];
    u8 unk14;
    u8 pad15[3];
};

extern u32 gUnk_0202CC20;


u8 UpdateLapProgress(struct Car *p, u8 a1)
{
    u8 unused1[40];
    s32 corners[4];
    u8 unused2[28];
    u8 v58;
    s32 l0, l4, l8, lC;
    struct TrackSeg *e, *b;
    u8 v68, v6C;
    s32 x0, x1, x2, x3, y0, y1, y2, y3;
    s32 det;
    u32 time;

    v58 = 3 - gOptions[0];
    gLapProgressAdvanced = 0;
    v6C = gIsLinkRace != 0 ? gLinkPlayerId[0] : 0;
    if (gIsLinkRace != 0)
        v68 = gNumLinkPlayers[0];
    else
        v68 = gNumCars[0];

    e = &((struct TrackSeg *)gTrackSegs)[p->waypoint];
    b = e + 1;
    if (e->unk10 == 1)
        b = (struct TrackSeg *)gTrackSegs;

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

    if (p->firstStepCrossed == 0) {
        p->firstStepCrossed = 1;
        gStartedCarCount = gStartedCarCount + 1;
    }
    p->subStep = p->subStep + 1;
    gLapProgressAdvanced = 1;
    p->progress = ((s8)p->lap << 16) + p->waypoint * 16 + p->subStep;
    if (p->subStep != 0x10)
        return 1;
    p->subStep = 0;
    if (p == gCars && gGameMode[0] == 0x10 && gChallengeIndex == 9) {
        gWaypointSpeedSamples[p->waypoint] = -p->speed / 7000;
    }
    p->respawnHeading = p->heading;
    p->respawnWaypoint = p->waypoint;
    {
    s32 t = e->unk10;
    if (t == 1) {
            (*(u32 *)&p->trackCueCursor) = gTrackCueList;

        if (p == gCars) {
            s32 v = 1;
            u16 w;
            gTrackCueId = (w = -v);
        }
        if (gGameMode[0] == 0x0C) {
            if ((time = gLapMin[0] * 60000 + gLapSec[0] * 1000 + gLapMs[0]) < gUnk_0202ED84)
                gChallengeResult = t;
        }
        if (a1 == v6C && gGameMode[0] != 0x0C && p->ledLapFlag != 0) {
            p->lapLedTimer = 0x1E;
            p->lapsLed = p->lapsLed + 1;
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
            if (gIsTimeTrial != 0 && p->lapStartedFlag != 0)
                CheckTrackRecord(gLapMin[0], gLapSec[0], gLapMs[0]);
        }
        if (gGameMode[0] == 0x10) {
            if (gChallengeIndex == 1) {
                if (gLapMin[0] * 60000 + gLapSec[0] * 1000 + gLapMs[0] <= 0x7D00)
                    gChallengeResult = gChallengeIndex;
                EndRace();
            }
            if (gChallengeIndex == 2) {
                if (a1 == 0 && *(s8 *)&p->lap == gNumLaps) {
                    EndRace();
                    if (gCars[0].racePosition <= 2)
                        gChallengeResult = 1;
                }
            }
            if (gChallengeIndex == 3) {
                if (a1 == 0 && *(s8 *)&p->lap == gNumLaps) {
                    if (gCars[0].racePosition == 0 && gPlayerPittedFlag != 0)
                        gChallengeResult = 1;
                    EndRace();
                }
            }
            if (gChallengeIndex == 5) {
                if (p == gCars) {
                    if (p->ledLapFlag != 0) {
                        gChallengeResult = 1;
                        EndRace();
                    }
                    if (*(s8 *)&p->lap == gNumLaps)
                        EndRace();
                }
            }
            if (gChallengeIndex == 6) {
                if (a1 == 0 && *(s8 *)&p->lap == gNumLaps) {
                    EndRace();
                    if (gCars[0].racePosition == 0)
                        gChallengeResult = 1;
                }
            }
            if (gChallengeIndex == 7) {
                if (gLapMin[0] * 60000 + gLapSec[0] * 1000 + gLapMs[0] <= 0x68CE) {
                    gChallengeResult = 1;
                    EndRace();
                }
            }
            if (gChallengeIndex == 8) {
                if (gLapMin[0] * 60000 + gLapSec[0] * 1000 + gLapMs[0] <= 0x6E87) {
                    gChallengeResult = 1;
                    EndRace();
                }
            }
            if (gChallengeIndex == 0xA) {
                if (p == gCars && *(s8 *)&p->lap == gNumLaps) {
                    if (p->racePosition == 0)
                        gChallengeResult = 1;
                    EndRace();
                }
            }
            if (gChallengeIndex == 0xB) {
                if (p == gCars && *(s8 *)&p->lap == gNumLaps) {
                    if (p->racePosition == 0)
                        gChallengeResult = 1;
                    EndRace();
                }
            }
            if (gChallengeIndex == 0xC) {
                if (p == gCars) {
                    if (p->ledLapFlag != 0) {
                        gChallengeResult = 1;
                        EndRace();
                    }
                    if (*(s8 *)&p->lap == gNumLaps)
                        EndRace();
                }
            }
            if (gChallengeIndex == 0xD) {
                if (p == gCars && *(s8 *)&p->lap == gNumLaps) {
                    if (p->racePosition == 0)
                        gChallengeResult = 1;
                    EndRace();
                }
            }
            if (gChallengeIndex == 0xE) {
                if (p == gCars) {
                    if (p->racePosition == 0 && *(s8 *)&p->lap == gNumLaps) {
                        gChallengeResult = 1;
                        EndRace();
                    }
                    if (p == gCars && *(s8 *)&p->lap == gNumLaps)
                        EndRace();
                }
            }
            if (gChallengeIndex == 0xF) {
                if (p == gCars) {
                    if (p->racePosition == 0 && *(s8 *)&p->lap == gNumLaps) {
                        gChallengeResult = 1;
                        EndRace();
                    }
                    if (p == gCars && *(s8 *)&p->lap == gNumLaps)
                        EndRace();
                }
            }
        }
        p->ledLapFlag = 1;
        if (p == gCars && gGameMode[0] == 5 && p->lapStartedFlag != 0) {
            if ((time = gLapMin[0] * 60000 + gLapSec[0] * 1000 + gLapMs[0]) < p->finishTime)
                p->finishTime = gLapMin[0] * 60000 + gLapSec[0] * 1000 + gLapMs[0];
        }
        if (*(s8 *)&p->lap == gNumLaps) {
            if (gGameMode[0] == 0 || gGameMode[0] == 6 || gGameMode[0] == 1)
                p->finishTime = gRaceMin * 60000 + gRaceSec * 1000 + gRaceMs;
            if (a1 == v6C && p->lapStartedFlag != 0)
                sub_0800B3D4(gLapMin[0], gLapSec[0], gLapMs[0]);
            if (gGameMode[0] != 2) {
                RecordFinishTime((struct Unk0800A438 *)p);
                gFinishedCarOrder[gNumFinishedCars] = a1;
                gNumFinishedCars = gNumFinishedCars + 1;
                if ((u8)(gGameMode[0] - 3) <= 1)
                    p->finishTime = gRaceMin * 60000 + gRaceSec * 1000 + gRaceMs;
                if (a1 == v6C) {
                    s32 v2 = *(volatile u8 *)&gGameMode[0];
                    if (v2 == 0 || v2 == 6 || v2 == 1) {
                        /* sub_08016D28: the ROM call passes no argument; the matched definition takes one; call
                           through a function pointer with the old prototype. */
                        ((void (*)(void))sub_08016D28)();
                        EndRace();
                    }
                }
                if (gNumFinishedCars == v68) {
                    if (gGameMode[0] != 0x10) {
                        if (gGameMode[0] != 0xF) {
                            if (gGameMode[0] != 2) {
                                if (gGameMode[0] != 0xE)
                                    EndRace();
                            }
                        }
                    }
                }
            }
        } else {
            if (a1 == v6C && p->lapStartedFlag != 0)
                sub_0800B3D4(gLapMin[0], gLapSec[0], gLapMs[0]);
        }
        if (a1 == v6C)
            ResetLapTimer();
    }
    }

    if ((u16)(e->unk10 - 1) <= 1) {
        if (a1 == v6C) {
            gUnk_0202CC20 = (*(u32 *)&p->tickCount);
            if (e->unk10 != 1)
                sub_0800B540();
            if (gOptions[3] != 0 && gIsDemo == 0 && gRaceEndState == 0)
                m4aSongNumStart(0x33);
            if (a1 == v6C && gGameMode[0] != 0xA) {
                s32 inner = v58 / 2 + 6;
                sub_08005598((u8)(e->unk14 + inner));
            }
        }
        {
        s32 t2 = e->unk10;
        if (t2 == 1 && p->lapStartedFlag == 0) {
            if (p == gCars)
                sub_0800B2C4();
            p->lapStartedFlag = t2;
        }
        }
    }
    p->waypoint = p->waypoint + 1;
    return 1;
}
