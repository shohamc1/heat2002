/* sub_08009C4C — QUARANTINED 2026-09-14 (756/764 bytes, 8 bytes out)
 *
 * Everything matches byte-for-byte except ONE allocation web in the
 * `flip == 0` ("then") path; all cascades (branch/pool offsets) follow from
 * the 8-byte size delta. The else path and both tail blocks match exactly.
 *
 * Remaining diff (then-path entry):
 *   ROM:  adds r7, r6, r2      ; &p->unk162 pseudo got r7
 *         ldrb r3, [r7]
 *         lsls r0, r3, #2 / adds / ldr
 *         lsls r4, r4, #2      ; v*4 reuses v's r4 IN PLACE
 *         adds r0, r4, r0 / ldr / bl 75E4
 *         adds r3, r0, #0      ; t in r3
 *   ours: adds r2, r2, r6      ; reload temp (addr pseudo got r8)
 *         mov  r8, r2
 *         ldrb r3, [r2]
 *         lsls r0, r3, #2 / adds / ldr
 *         lsls r7, r4, #2      ; v*4 copy in r7, v stays live in r4
 *         adds r0, r7, r0 / ldr / bl 75E4
 *         adds r4, r0, #0      ; t in r4
 *   (second access: ROM `ldrb r7,[r7]` vs ours `mov r2,r8; ldrb r2,[r2]`)
 *
 * Root cause: global.c gives the &p->unk162 pseudo r7 in the ROM (pass 0),
 * letting v*4 take r4 (v dies exactly at its birth). In ours v*4 wins pass 0
 * (r7), the address cannot take r4 (v still live at its earlier birth) and
 * falls to r8 with the reload mov dance.
 *
 * Swept (all still 756/764 or worse):
 *   - u8 *pu = &a1->unk162 local; u8 ub = a1->unk162 reloaded between calls
 *   - u32 *tb = gUnk_08367640[a1->unk162]; t = f(tb[v]) table-base temp
 *   - u8** tables + [v * 4] explicit multiply (byte-pointer indexing)
 *   - *(gUnk_...[a1->unk162] + v) pointer-plus form
 *   - ((u8 *)a1)[0x162] byte-cast on first/second/both accesses
 *   - a-local for arg0 in the then-path (matches else style) — no change
 *   - goto flipped / goto tail structure — no change
 *   - register u32 v asm("r4") pin — worse (117 diff lines)
 *   - s32 v/attr; attr | t[4] commuted call arg (wrong: changes orrs order);
 *     separate w = v index temp; separate t2 local in then-path — worse
 *   - two a-local variants, tail 0x40000000 constant verified (0x80<<23)
 *
 * The constants that DID converge after misreads: 0x80<<15 = 0x10000000,
 * 0x80<<17(0x17)=0x40000000; else-path arg0 = local a | 0x10000000 (kept
 * un-folded because a is a variable); then-path arg0 inline.
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
