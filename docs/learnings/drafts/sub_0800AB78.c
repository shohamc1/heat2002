/*
 * sub_0800AB78 quarantine note (2026-09-14, ~12 match.py iterations, 520/520 bytes):
 * Everything matches except the cross-jump sharing pattern of the four
 * sub_0800A80C call sites in the DC!=0 / idx==0 regions.
 *
 * ROM:  [table arm: args; bl INLINE; b AC4A] [pool] [else(=2,idx): args; b AC46]
 *       ... [keys arm: args; bl INLINE; b AC4A] [=2,0 arm: args; AC46: bl(shared with else)] [AC4A: adds r0; bl A628]
 * OURS: [table arm: args; b ac3e(shared bl)] [pool] [else: args; bl INLINE; b]
 *       ... [keys arm: args; b shared] [=2,0: args; shared bl; A628]
 * I.e. ROM keeps the THEN-arm bl's inline (table, keys) and cross-jumps the two
 * `movs r1,#2` arms together at AC46; ours merges the THEN arms into region-2's
 * shared bl and keeps the else's bl inline. MIRRORED pairing.
 *
 * Solved so far: u32 dc local gets ldrb r1,[r0] value-in-r1 (needed for the
 * later `p->unkA0 = dc` store via surviving register); `else if (21E0 == 0)
 * {gKeysHeld arm} else {=2,0 arm}` gives the right region-2 polarity;
 * region-1 needs `if (21E0 == 0 && unk7D == 0) table else =2` (bne-to-else).
 *
 * Swept: A628 call inside both arms (516b, over-merges); inverted region-1
 * polarity `21E0 != 0 || unk7D != 0` (table gets own bl but as the ELSE with
 * beq-polarity - mirrored); combined with all region-2 polarities. The
 * then-arm-inline-bl pattern was unreachable from every source arrangement
 * tried; GCC 2.95 jump.c cross_jump always merges the inline then-arm's
 * [adds r0; adds r2; bl] suffix into the adjacent else tail (find_cross_jump
 * minimum=1). Suspect initial RTL block order in the retail compile differed
 * (join1/join2 A628 merge order), possibly from a different if/else nesting.
 */
#include "global.h"

struct Car {
    u8 pad00[0x7C];
    u8 unk7C;
    u8 unk7D;
    u8 pad7E[0x88 - 0x7E];
    u32 unk88;
    u8 pad8C[0xA0 - 0x8C];
    u16 unkA0;
    u8 padA2[0x150 - 0xA2];
    u8 unk150;
    u8 pad151[0x15C - 0x151];
    u32 unk15C;
    u8 pad160[0x166 - 0x160];
    u8 unk166;
    u8 pad167[0x175 - 0x167];
    u8 unk175;
    u8 pad176[0x190 - 0x176];
};

extern struct Car gUnk_0202A550[];
extern u8 gUnk_020020DC;
extern u8 gUnk_020021E0;
extern u16 gUnk_020020A0[];
extern u16 gKeysHeld;
extern u8 gUnk_0200215C;
extern u32 gUnk_0200209C;
extern u8 gUnk_0202EF90;

void sub_0800A80C(struct Car *p, u32 a, u8 b);
void sub_0800A628(struct Car *p);
void sub_080093BC(struct Car *p, u8 idx);
void sub_0800C534(struct Car *p, u8 idx);
void sub_0800B8A8(struct Car *p);
void sub_08009B20(u8 idx);

void sub_0800AB78(struct Car *p, u8 idx)
{
    u16 *q;
    u32 dc;

    dc = gUnk_020020DC;
    if (dc != 0) {
        if (gUnk_020021E0 == 0 && p->unk7D == 0)
            sub_0800A80C(p, gUnk_020020A0[idx], idx);
        else
            sub_0800A80C(p, 2, idx);
        sub_0800A628(p);
    } else if (idx == 0) {
        if (p->unk175 != 0) {
            sub_080093BC(p, 0);
            sub_0800A80C(p, p->unkA0, 0);
        } else if (gUnk_0200215C == 9 || gUnk_0200215C == 0xD || gUnk_0200215C == 0xE
                   || gUnk_0200215C == 0xF || gUnk_0200215C == 0x11) {
            sub_0800C534(p, idx);
            sub_0800A80C(p, p->unkA0, idx);
        } else if (gUnk_020021E0 == 0) {
            sub_0800A80C(p, gKeysHeld, 0);
            sub_0800A628(p);
        } else {
            sub_0800A80C(p, 2, 0);
            sub_0800A628(p);
        }
    } else {
        if (gUnk_0200215C == 9 || gUnk_0200215C == 0xD || gUnk_0200215C == 0xE
            || gUnk_0200215C == 0xF || gUnk_0200215C == 0x11)
            sub_0800C534(p, idx);
        else if (gUnk_0200215C == 4)
            p->unkA0 = dc;
        else if (gUnk_020021E0 != 0)
            p->unkA0 = 2;
        else if (p->unk175 == 0)
            sub_0800C534(p, idx);
        else
            sub_080093BC(p, idx);
        q = &p->unkA0;
        sub_0800A628(p);
        sub_0800A80C(p, *q, idx);
    }
    if (p->unk88 > 0x11940 && p->unk7C != 1 && (gUnk_0200209C & 0x3F) == 0)
        sub_0800B8A8(p);
    if (gUnk_020020DC != 0) {
        if (idx == gUnk_0202EF90) {
            sub_08009B20(idx);
            if (gUnk_0202A550[idx].unk150 != 0 && gUnk_0202A550[idx].unk150 != 0x63)
                gUnk_0202A550[idx].unk166 = 0;
        }
    } else if (idx == 0) {
        sub_08009B20(0);
        if (gUnk_0202A550[0].unk150 != 0 && gUnk_0202A550[0].unk150 != 0x63)
            gUnk_0202A550[0].unk166 = idx;
    }
    p->unk15C++;
}
