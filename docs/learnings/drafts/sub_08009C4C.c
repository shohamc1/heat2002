/*
 * sub_08009C4C — QUARANTINED wave 6 (2026-09-14, budget reached; best state
 * = THIS draft: 756/764, 8 bytes / one alloc web in the then-path).
 * WAVE-6 FINDINGS (all fresh-verified):
 *   - ROM's two paths compile the SAME table access DIFFERENTLY:
 *     then: adds r7,r6,r2 (a1-FIRST plus), address global r7 direct,
 *           lsls r4,r4,#2 (v-scale IN PLACE on v's reg), t -> r3;
 *     else: adds r0,r0,r6 (offset-first), mov r8,r0 (global r8 + reload
 *           dance), lsls r7,r4,#2 (fresh v4), t -> r3.
 *     The draft already produces the ELSE pattern in both paths.
 *   - v <<= 2 as a statement (v's own pseudo, in-place lsls rX,rX,#2)
 *     WORKS for the scale shape; combined with a table-base temp
 *     (tb = gUnk[*pk]; t = f(*(u32*)(v + tb))) and u8 *pk = &a1->unk162
 *     the then-path ORDER comes out right (pk, tb chain, v<<=2, v+tb,
 *     ldr, bl) — but the plus orders come out offset-first
 *     (adds r2,r2,r6 / adds r0,r0,r6) and pk still lands r8.
 *   - register u32 attr asm("r5") pin: WORKS (no shape damage, orrs
 *     chains unchanged). register struct Car *a1 asm("r6") = a0 copy-pin:
 *     gives ROM's exact prologue byte (adds r6,r0,#0) but pk STILL r8
 *     (the v pseudo then takes r7; flip takes r4 — the web just rotates).
 *   - pinning pk itself r7: adds r7,r6,r2 a1-first ✓ but ldrb gets a
 *     preceding `adds r0,r7,#0` copy (pinned-address-copy disease) and
 *     the pool ldr moves after the address computation (ROM: pool first).
 *   - the residual web (v/flip/pk homes) is RELOAD-driven, not
 *     global-alloc-driven (greg conflict rows predict r3/r4 picks that
 *     never appear in the final asm). Same reload-rotation phenomenon as
 *     sub_0800C2CC: every web member lands one register late.
 * Remaining diff (then-path only, else + tails exact):
 *   0x8009d10 adds r7,r6,r2 vs ours adds r2,r2,r6 (+ mov r8,r2 copy)
 *   0x8009d1a lsls r4,r4,#2   vs ours lsls r7,r4,#2
 *   0x8009d24 adds r3,r0,#0   vs ours adds r4,r0,#0   (t home)
 */

#include "global.h"

struct Car {
    u32 unk00;
    u8 pad04[0x08 - 0x04];
    u32 unk08;
    u8 pad0C[0x34 - 0x0C];
    u16 unk34;
    u8 pad36[0x7D - 0x36];
    u8 unk7D;
    u8 pad7E[0x162 - 0x7E];
    u8 unk162;
    u8 pad163[0x172 - 0x163];
    u8 unk172;
};

extern u8 gUnk_020020DC;
extern u32 gUnk_0200209C;
extern u32 *gUnk_08367730[];
extern u32 *gUnk_08367640[];
extern u32 *gUnk_083676B8[];
extern u32 *gUnk_083681E8[];
extern u32 *gUnk_083681F8[];
extern u8 gUnk_08337C20[];
extern u8 gUnk_0831D0EC[];

extern u8 sub_08009BB4(s32 x, s32 y, s32 *out);
extern u8 sub_08007714(u8 *a);
extern u32 *sub_080075E4(u32 a);
extern u32 *sub_0800754C(u32 a);
extern u32 *sub_08007630(u32 p);
extern u32 *sub_08007598(u32 a);
extern u32 sub_080044DC(u32 arg0, u32 arg1, u32 arg2);

void sub_08009C4C(struct Car *a1, u8 a2)
{
    s32 out[2];
    u16 base;
    u32 v;
    u32 attr;
    u8 flip;
    u32 *t;
    u32 a;
    u32 *tp;

    if (sub_08009BB4(a1->unk00, a1->unk08, out) == 0)
        return;
    base = out[1];
    out[0] -= 0x18;
    out[1] -= 0x10;
    if (a1->unk7D != 0 && gUnk_020020DC != 0 && gUnk_0200209C & 8)
        return;
    v = (a1->unk34 + 0x200) >> 10;
    v = (v + 0x28) & 0x3F;
    flip = v & 0x20;
    v &= 0x1F;
    if (flip != 0)
        v = 0x20 - v;
    attr = sub_08007714((u8 *)gUnk_08367730[a1->unk162]) << 12;
    if (a1->unk172 != 0)
        attr |= 0x800;
    else
        attr |= 0x400;
    if (flip == 0) {
        t = sub_080075E4(gUnk_08367640[a1->unk162][v]);
        if (t != 0)
            sub_080044DC((out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x80008000,
                         t[4] | attr, (u16)(base + 0x40));
        t = sub_0800754C(gUnk_083676B8[a1->unk162][v]);
        if (t != 0)
            sub_080044DC((out[1] & 0xFF) | (((out[0] + 0x10) & 0x1FF) << 16) | 0x80000000,
                         t[4] | attr, (u16)(base + 0x40));
    } else {
        t = sub_0800754C(gUnk_083676B8[a1->unk162][v]);
        if (t != 0) {
            a = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x80000000;
            sub_080044DC(a | 0x10000000, t[4] | attr, (u16)(base + 0x40));
        }
        t = sub_080075E4(gUnk_08367640[a1->unk162][v]);
        if (t != 0) {
            a = (out[1] & 0xFF) | (((out[0] + 0x20) & 0x1FF) << 16) | 0x80008000;
            sub_080044DC(a | 0x10000000, t[4] | attr, (u16)(base + 0x40));
        }
    }
    if (gUnk_020020DC != 0) {
        tp = gUnk_083681E8[a2] + ((s32)gUnk_0200209C >> 1) % 7;
        out[1] -= 0x0C;
        out[0] += 0x10;
        a = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
        t = sub_08007630(*tp);
        if (t != 0)
            sub_080044DC(a, t[4] | 0x400 | (sub_08007714(gUnk_08337C20) << 12),
                         (u16)(base + 0x40));
    } else {
        tp = gUnk_083681F8[a1->unk162];
        out[1] -= 8;
        out[0] += 0x10;
        a = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x4000;
        t = sub_08007598(*tp);
        if (t != 0)
            sub_080044DC(a, t[4] | 0x400 | (sub_08007714(gUnk_0831D0EC) << 12),
                         (u16)(base + 0x40));
    }
}
