#include "global.h"
#include "variables.h"

struct Car {
    s32 unk00;                          /* 0x00 */
    u8 pad04[0x08 - 0x04];
    s32 unk08;                          /* 0x08 */
    s32 unk0C;                          /* 0x0C */
    u8 pad10[0x14 - 0x10];
    s32 unk14;                          /* 0x14 */
    u8 pad18[0x34 - 0x18];
    u16 unk34;                          /* 0x34 */
    u16 respawnHeading;                          /* 0x36 */
    u16 respawnWaypoint;                          /* 0x38 */
    u8 pad3A[0x3C - 0x3A];
    u16 unk3C;                          /* 0x3C */
    u8 pad3E[0x4D - 0x3E];
    u8 unk4D;                           /* 0x4D */
    u8 unk4E;                           /* 0x4E */
    u8 pad4F[0x128 - 0x4F];
    s32 unk128;                         /* 0x128 */
    s32 steerHeading;                         /* 0x12C */
    s32 unk130;                         /* 0x130 */
    u8 pad134[0x13C - 0x134];
    s32 engineForce;                         /* 0x13C */
    u8 pad140[0x148 - 0x140];
    s32 unk148;                         /* 0x148 */
};

/* The 0x18-byte track segment record gModule_TrackSegs points at; local
   twin of sub_0800A4D4.c's struct TrackSeg. It shares its old tag name
   with include/structs.h's 0x64-byte struct Track but not its layout or
   stride, so it keeps a local tag. The gModule_TrackSegs extern
   (variables.h) is typed struct Track *; the casts below are pointer
   casts only and emit nothing. */

void sub_08341F64(struct Car *p)
{
    struct TrackSeg *e;

    e = &((struct TrackSeg *)gModule_TrackSegs)[p->respawnWaypoint];
    p->unk00 = (e->corner1X + e->corner2X) << 15;
    p->unk08 = (e->corner1Z + e->corner2Z) << 15;
    /* Dead since this revision dropped sub_0800A4D4's delta block, but the
       branch still splits the blocks that local-alloc and reload see. */
    if (e->kind == 1)
        e = (struct TrackSeg *)gModule_TrackSegs;
    else
        e = e + 1;
    p->unk34 = p->respawnHeading;
    p->unk3C = 0;
    p->engineForce = 0;
    p->unk148 = 0;
    p->unk0C = 0;
    p->unk14 = 0;
    p->steerHeading = p->unk34;
    p->unk128 = p->unk34;
    p->unk130 = 0;
    p->unk4E = 1;
    e = &((struct TrackSeg *)gModule_TrackSegs)[p->respawnWaypoint];
    if (e->kind == 1)
        p->unk4D = 0;
    else
        p->unk4D = p->respawnWaypoint + 1;
}
