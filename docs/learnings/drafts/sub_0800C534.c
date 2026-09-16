/*
 * sub_0800C534 — SOLVED 2026-09-15 (permutation campaign wave 1):
 * MATCH (1104 bytes). Canonical source in src/sub_0800C534.c; this file
 * kept for the learning record.
 *
 * THE FIX, cluster by cluster (all three ties were source-idiom issues,
 * not allocation magic):
 *  C3 (narrowing scratch): the (s16) narrowing must be TWO STATEMENTS on
 *    the SAME variable (`diffxy = diffxy << 16; diffxy = diffxy >> 16;`)
 *    — one-expression shift pairs and (s16) casts create a fresh
 *    intermediate pseudo that local-alloc homes in r0.
 *  C1 (ldrb r0 vs r1): the tail's `stv` reuse for `ent->unk175` inflated
 *    its global allocno across the whole function; a separate block-local
 *    `u8 st2` for the tail load shrinks stv's range so it takes r0.
 *  C2 (subs operand): write the angle def NEGATION-FIRST:
 *    `angle = -(sub_0800CB18(...) << 8) + 0x8400;` — same minus RTL after
 *    canonicalization, but the expand-time tree order shifts pseudo
 *    creation so the spilled angle's def-site reload picks r0.
 *
 * sub_0800C534 -- QUARANTINED (1104/1104 bytes, 536/536 instructions, 11 register-name diffs)
 *
 * Status: MISMATCH. Structure, size, branch targets, pool contents all match.
 * Three independent one-register allocation ties remain (all others swept):
 *
 *  1) 0x0800C660  T: ldrb r0,[r6]      O: ldrb r1,[r6]   (+ cmp r0/r1 x2 at C664/C668)
 *     The state byte read through ps (r6). Target reuses r0 (the reg that just
 *     held the 0x175 pool const); ours allocates a fresh r1. Direct `*ps` reads
 *     (no stv local) DO land in r0 (cse folds the two tests to one load), but
 *     then the reload move `mov r10,r4` (bufp=buf) slides BEFORE the ldrb
 *     instead of after it. With `u8 stv = *ps` the mov position is right but
 *     the read takes r1. Tried: stv as u8/u32/register, pinned/unpinned ps,
 *     decl-order permutations. (Pinned ps defeats the load cse entirely --
 *     two ldrb's -- see /tmp notes below.)
 *
 *  2) 0x0800C744  T: subs r0,r1,r0 ; str r0,[sp,#0x34]   O: subs r1,... ; str r1,...
 *     angle = 0x8400 - (sub_0800CB18(...) << 8). Reload picks the sub's
 *     destination: target reuses r0 (call-result reg), ours r1 (0x8400 reg).
 *
 *  3) 0x0800C826  T: lsls r3,r3,#16 ; asrs r3,r3,#16     O: lsls r0,r3,#16 ; asrs r3,r0,#16
 *    0x0800C836  T: ldrh r0 ; subs r1,r2,r0 ; lsls r1,r1 ; asrs r1,r1
 *                 O: ldrh r1 ; subs r0,r2,r1 ; lsls r0,r0 ; asrs r1,r0
 *     The (s16) narrowing after the if/else writes through an r0 scratch;
 *     target narrows in place. d2 = (s16)(angle - ent->unk34) likewise.
 *
 * Swept (all matched or reverted): ternary vs if/else for the unkA0 mask
 * (direct stores per arm + gcc cross-jump merges the strh -- REQUIRED),
 * table reads inside the state==2 block, operand order `gUnk_020020CC * 8 +
 * ent->unk181`, angle as a separate stack local (buf[2] must NOT be an array
 * element -- the compiler then picks pointer-form vs sp-form addressing for
 * bufp[1]/angle exactly as the ROM), t1/t2/t3 locals for the second table
 * block (REQUIRED for the T1,T2,T3,dx,T4,dy interleave), 0x8400-(x<<8) not
 * 0x84000-x, ps=&ent->unk175 local (r6; pinned breaks cse, unpinned works but
 * see (1)), stv single-read for the state tests, second sub_0800C4E0 call in
 * the state==1 arm (<= 0xC7 after gUnk_020020CC==3), dead pad[10] before buf
 * (frame 0x38), result pinned r8 / zero pinned r9 (register-asm; zero must be
 * pinned or the `if (zero != 0)` tail folds away -- plain locals get cse'd to
 * nothing), bufp unpinned (r10 falls out naturally once ps takes r6).
 *
 * Next levers not yet tried: -dl dump of local_alloc qty order around the
 * three sites (the C660 block has exactly the 3-quantity broken-sort shape
 * described in parked.md); making the C660 read part of a 2-qty block;
 * reload-suggested-register games via copy shapes for (2)/(3).
 */
#include "global.h"

struct Unk0800C534 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    s32 unk2C;
    u8 pad30[4];
    u16 unk34;
    u8 pad36[0xA0 - 0x36];
    u16 unkA0;
    u8 padA2[0xF0 - 0xA2];
    s32 unkF0;
    u32 unkF4;
    u32 unkF8;
    u8 padFC[0x12C - 0xFC];
    s32 unk12C;
    u8 pad130[0x154 - 0x130];
    s32 unk154;
    u8 pad158[0x175 - 0x158];
    u8 unk175;
    u8 pad176[0x181 - 0x176];
    u8 unk181;
};

extern u8 gUnk_0202CC28;
extern u8 gUnk_0202CC2C;
extern u32 gUnk_0202CC24;
extern u32 gUnk_0202CC34;
extern u32 gUnk_0202CC38;
extern u32 gUnk_0202CC3C;
extern u8 gUnk_020020CC;
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202CAD0;
extern u8 gUnk_0202A53C;
extern struct Unk0800C534 gUnk_0202A550[];
extern u32 gUnk_083672F0[];
extern u8 gUnk_0200215C;

void sub_08008394(u32 a);
void sub_0800C430(u32 a);
s32 sub_0800C358(u32 a, u32 b);
s32 sub_0800BBFC(u32 a, u32 b, u32 c, u32 d, u32 e);
void sub_0800BD98(s32 a, void *b, u32 c, u32 d);
void sub_0800BE00(void *a, s32 b);
void sub_0800C28C(struct Unk0800C534 *a);
s32 sub_0800C4E0(u32 a);
s32 sub_0800CB18(s32 a, s32 b);

void sub_0800C534(struct Unk0800C534 *ent, u8 param)
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
    if (gUnk_0202CC28 == 0 || gUnk_0200215C == 9 || gUnk_0200215C == 0xD
        || gUnk_0200215C == 0xE || gUnk_0200215C == 0xF || gUnk_0200215C == 0x11)
    {
        ent->unkA0 = 1;
        gUnk_0202CC28 = 0;
        pA0 = &ent->unkA0;
    }
    else
    {
        if (ent->unk175 == 0 && (-ent->unk2C) >> 12 > 0x28)
            ent->unkA0 = ent->unkA0 & 0xFFFE;
        else
            ent->unkA0 = 1;
        pA0 = &ent->unkA0;
        if (ent->unk175 == 0)
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
    diff = sub_0800BBFC(gUnk_0202CC24, gUnk_0202CC38, ent->unkF4, gUnk_0202CC3C, gUnk_0202CC34);
    diff = diff + 0x40;
    if (diff >= ent->unk154)
        diff = diff - ent->unk154;
    sub_0800BD98(diff, buf, ent->unkF4, ent->unkF8);
    ps = &ent->unk175;
    stv = 0;
    stv = *ps;
    bufp = buf;
    if (stv != 0)
    {
        if (stv == 1)
        {
            if (sub_0800C4E0((u32)ent) <= 0x63
                || (gUnk_020020CC == 3 && sub_0800C4E0((u32)ent) <= 0xC7))
                *ps = 2;
        }
        if (ent->unk175 == 2)
        {
            if (sub_0800C4E0((u32)ent) <= 0x13 || gUnk_0202EEB0 == 0
                || (ent == gUnk_0202A550 && gUnk_0202CAD0 == 0 && gUnk_0202A53C == 0))
                ent->unk175 = 3;
            buf[0] = gUnk_083672F0[(gUnk_020020CC * 8 + ent->unk181) * 2];
            bufp[1] = gUnk_083672F0[(gUnk_020020CC * 8 + ent->unk181) * 2 + 1];
        }
        if (ent->unk175 == 3)
        {
            if (gUnk_0202EEB0 == 0)
                ent->unk175 = 4;
            t1 = gUnk_083672F0[(gUnk_020020CC * 8 + 6) * 2];
            t2 = gUnk_083672F0[(gUnk_020020CC * 8 + 6) * 2 + 1];
            t3 = gUnk_083672F0[(gUnk_020020CC * 8 + 7) * 2];
            angle = 0x8400 - (sub_0800CB18(t1 - t3,
                t2 - gUnk_083672F0[(gUnk_020020CC * 8 + 7) * 2 + 1]) << 8);
        }
    }
    limit = 4;
    if (gUnk_0200215C == 9 || gUnk_0200215C == 0xD || gUnk_0200215C == 0xE
        || gUnk_0200215C == 0xF || gUnk_0200215C == 0x11)
        limit = -99;
    if (result > limit || ent->unk175 != 0)
    {
        diffxy = (buf[0] << 16) - ent->unk00;
        dya = (bufp[1] << 16) - ent->unk08;
        angl = 0x8400 - (sub_0800CB18(diffxy >> 5, dya >> 5) << 8);
        if (ent->unk175 != 0)
        {
            d34 = angl - ent->unk34;
            if (d34 < 0)
                d34 = -d34;
            if (d34 > 0x4000)
            {
                ent->unk34 = angl;
                ent->unk12C = angl;
            }
        }
        if (ent->unk175 == 3)
            diffxy = angle - ent->unk12C;
        else
            diffxy = angl - ent->unk12C;
        diffxy = (diffxy << 16) >> 16;
        if (ent->unk175 == 3)
        {
            d2 = (s16)(angle - ent->unk34);
            if ((d2 < 0 ? -d2 : d2) <= 0x3FF
                || gUnk_020020CC == 3 || gUnk_020020CC == 1 || gUnk_020020CC == 9
                || ((d2 < 0 ? -d2 : d2) <= 0xFFF && (gUnk_020020CC == 4 || gUnk_020020CC == 2)))
                ent->unk175 = 4;
        }
        if (ent->unk175 == 0 && gUnk_0202CC28 == 0)
            diffxy = diffxy / 8;
        if (gUnk_0202CC28 != 0)
            diffxy = diffxy * 4;
        if (ent->unk2C > 0)
            ent->unk12C = -angl;
        else
            ent->unk12C = ent->unk12C + diffxy;
        if ((diffxy < 0 ? -diffxy : diffxy) > 0x1F4 && (-ent->unk2C) >> 12 > 0x28)
            *pA0 = *pA0 & 0xFFFE;
        if ((diffxy < 0 ? -diffxy : diffxy) > 0x28A && (-ent->unk2C) >> 12 > 0x28)
            *pA0 = 2;
    }
    if (ent->unk175 == 1 && (-ent->unk2C) >> 12 > 0x50)
        *pA0 = 2;
    stv = ent->unk175;
    if (stv == 2 && (-ent->unk2C) >> 12 > 0x28)
        *pA0 = stv;
    if (ent->unk175 == 3 && (-ent->unk2C) >> 12 > 0xA)
        *pA0 = 2;
    if (zero != 0)
    {
        zero = (s16)zero;
        ent->unk12C = ent->unk12C + zero;
    }
}
