/*
 * UpdateAiDriver -- SOLVED: MATCH, 1104 bytes @ 0x0800C534 (campaign 2026-09-15,
 * scratch /tmp/perm/w1/UpdateAiDriver, variant v015). Three levers closed the
 * final 11 register-name diff bytes (all other structure already matched):
 *
 *  C3 (0x0800C826/C836, 4 bytes): the (s16) narrowing must be written as TWO
 *     statements per site, same variable in and out:
 *       diffxy = diffxy << 16;  diffxy = diffxy >> 16;
 *       d2 = angle - ent->heading;  d2 = d2 << 16;  d2 = d2 >> 16;
 *     A one-expression pair or a (s16) cast creates a fresh intermediate
 *     pseudo that local-alloc homes in r0 (lsls r0,rX / asrs rX,r0 scratch).
 *     The two-statement form keeps one pseudo so both shifts run in place.
 *
 *  C1 (0x0800C660, 3 bytes): the tail state test (unk175 == 2 -> *pA0 = value)
 *     must use a SEPARATE block-local variable (st2), not reuse stv. Reusing
 *     stv gives it 2 sets and a whole-function allocno; the inflated conflict
 *     set excludes r0 in global find_reg pass 0, landing stv in r1.
 *
 *  C2 (0x0800C744, 2 bytes): the angle def must be written negation-first:
 *       angle = -(Atan2(...) << 8) + 0x8400;
 *     gcc canonicalizes to the identical `subs rd, r1, r0` RTL, but the
 *     different expand-time tree shifts pseudo creation order so the def-site
 *     output reload of the spilled angle pseudo inherits r0 (the dying shift
 *     result) instead of r1.
 *
 * Everything else (frame, pins, t1/t2/t3 interleave, ps/bufp locals, dead
 * pad[10]) is as documented in the previous draft header below.
 */
#include "global.h"
/* functions.h prototypes UpdateAiDriver with the legacy local tag
   Unk0800C534 (its gCars view). Bind that tag to the canonical record
   for this TU only, so the prototype and the definition agree without
   duplicating the struct. */
#define Unk0800C534 Car
#include "functions.h"
#include "variables.h"
#include "car.h"
#include "data.h"


void sub_08008394(u32 a);
void sub_0800C430(u32 a);
s32 sub_0800C358(u32 a, u32 b);
s32 sub_0800BBFC(u32 a, u32 b, u32 c, u32 d, u32 e);
void sub_0800C28C(struct Car *a);
s32 sub_0800C4E0(u32 a);
s32 Atan2(s32 a, s32 b);

void UpdateAiDriver(struct Car *ent, u8 param)
{
    register u8 stv;
    u32 pad[10];
    u32 buf[2];
    s32 angle;
    u16 *pA0;
    register s32 result asm("r8");
    register s32 zero asm("r9");
    u32 *bufp;
    u8 *ps;

    s32 diff;
    s32 angl;
    s32 diffxy;
    s32 limit;
    s32 d34;
    s32 d2;
    s32 dya;
    s32 t1;
    s32 t2;
    s32 t3;

    sub_08008394((u32)ent);
    sub_0800C430((u32)ent);
    zero = 0;
    if (gUnk_0202CC28 == 0 || gUnk_0200215C[0] == 9 || gUnk_0200215C[0] == 0xD
        || gUnk_0200215C[0] == 0xE || gUnk_0200215C[0] == 0xF || gUnk_0200215C[0] == 0x11)
    {
        ent->aiInput = 1;
        gUnk_0202CC28 = 0;
        pA0 = &ent->aiInput;
    }
    else
    {
        if (ent->pitState == 0 && (-ent->speed) >> 12 > 0x28)
            ent->aiInput = ent->aiInput & 0xFFFE;
        else
            ent->aiInput = 1;
        pA0 = &ent->aiInput;
        if (ent->pitState == 0)
        {
            if (gUnk_0202CC2C != 0)
                *pA0 = 2;
            if (gUnk_0202CC28 != 0)
            {
                ent->unkF0 = (ent->unkF0 - 0x20) & 0x7FF;
                if (ent->unkF0 <= 0x100)
                    ent->unkF0 = 0x6FF;
                sub_0800BE00(ent, ent->unkF0);
            }
        }
    }
    sub_0800C28C(ent);
    result = sub_0800C358((u32)ent, param);
    if (result == -1)
        return;
    diff = sub_0800BBFC((*(u32 *)&gUnk_0202CC24), (*(u32 *)&gUnk_0202CC38), (*(u32 *)&ent->unkF4), (*(u32 *)&gUnk_0202CC3C), (*(u32 *)&gUnk_0202CC34));
    diff = diff + 0x40;
    if (diff >= ent->unk154)
        diff = diff - ent->unk154;
    sub_0800BD98(diff,(struct OutBD98 *)buf,(u16 *)(*(u32 *)&ent->unkF4),(void *)(*(u32 *)&ent->unkF8));
    ps = &ent->pitState;
    stv = 0;
    stv = *ps;
    bufp = buf;
    if (stv != 0)
    {
        if (stv == 1)
        {
            if (sub_0800C4E0((u32)ent) <= 0x63
                || (gTrackId == 3 && sub_0800C4E0((u32)ent) <= 0xC7))
                *ps = 2;
        }
        if (ent->pitState == 2)
        {
            if (sub_0800C4E0((u32)ent) <= 0x13 || gUnk_0202EEB0 == 0
                || (ent == gCars && gUnk_0202CAD0 == 0 && gUnk_0202A53C == 0))
                ent->pitState = 3;
            buf[0] = gUnk_083672F0[(gTrackId * 8 + ent->pitStall) * 2];
            bufp[1] = gUnk_083672F0[(gTrackId * 8 + ent->pitStall) * 2 + 1];
        }
        if (ent->pitState == 3)
        {
            if (gUnk_0202EEB0 == 0)
                ent->pitState = 4;
            t1 = gUnk_083672F0[(gTrackId * 8 + 6) * 2];
            t2 = gUnk_083672F0[(gTrackId * 8 + 6) * 2 + 1];
            t3 = gUnk_083672F0[(gTrackId * 8 + 7) * 2];
            angle = -(Atan2(t1 - t3,
                t2 - gUnk_083672F0[(gTrackId * 8 + 7) * 2 + 1]) << 8) + 0x8400;
        }
    }
    limit = 4;
    if (gUnk_0200215C[0] == 9 || gUnk_0200215C[0] == 0xD || gUnk_0200215C[0] == 0xE
        || gUnk_0200215C[0] == 0xF || gUnk_0200215C[0] == 0x11)
        limit = -99;
    if (result > limit || ent->pitState != 0)
    {
        diffxy = (buf[0] << 16) - ent->posX;
        dya = (bufp[1] << 16) - ent->posZ;
        angl = 0x8400 - (Atan2(diffxy >> 5, dya >> 5) << 8);
        if (ent->pitState != 0)
        {
            d34 = angl - ent->heading;
            if (d34 < 0)
                d34 = -d34;
            if (d34 > 0x4000)
            {
                ent->heading = angl;
                ent->unk12C = angl;
            }
        }
        if (ent->pitState == 3)
            diffxy = angle - ent->unk12C;
        else
            diffxy = angl - ent->unk12C;
        diffxy = diffxy << 16;
        diffxy = diffxy >> 16;
        if (ent->pitState == 3)
        {
            d2 = angle - ent->heading;
            d2 = d2 << 16;
            d2 = d2 >> 16;
            if ((d2 < 0 ? -d2 : d2) <= 0x3FF
                || gTrackId == 3 || gTrackId == 1 || gTrackId == 9
                || ((d2 < 0 ? -d2 : d2) <= 0xFFF && (gTrackId == 4 || gTrackId == 2)))
                ent->pitState = 4;
        }
        if (ent->pitState == 0 && gUnk_0202CC28 == 0)
            diffxy = diffxy / 8;
        if (gUnk_0202CC28 != 0)
            diffxy = diffxy * 4;
        if (ent->speed > 0)
            ent->unk12C = -angl;
        else
            ent->unk12C = ent->unk12C + diffxy;
        if ((diffxy < 0 ? -diffxy : diffxy) > 0x1F4 && (-ent->speed) >> 12 > 0x28)
            *pA0 = *pA0 & 0xFFFE;
        if ((diffxy < 0 ? -diffxy : diffxy) > 0x28A && (-ent->speed) >> 12 > 0x28)
            *pA0 = 2;
    }
    if (ent->pitState == 1 && (-ent->speed) >> 12 > 0x50)
        *pA0 = 2;
    {
        u8 st2 = ent->pitState;
        if (st2 == 2 && (-ent->speed) >> 12 > 0x28)
            *pA0 = st2;
    }
    if (ent->pitState == 3 && (-ent->speed) >> 12 > 0xA)
        *pA0 = 2;
    if (zero != 0)
    {
        zero = (s16)zero;
        ent->unk12C = ent->unk12C + zero;
    }
}
