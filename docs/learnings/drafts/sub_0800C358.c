/* sub_0800C358 -- quarantined draft (round 2, much closer than round 1).
 * 216/216 bytes, full instruction stream, loop, branch layout, pool and
 * prologue match. Remaining diff is ONE global-alloc ordering artifact
 * plus its renames:
 *   - target homes the struct pointer p in r3 (`adds r3, r0, #0`) and
 *     xi in r2 (`asrs r2, r0, #23`); ours p->r4, xi->r3. Everything
 *     downstream (clamps `cmp r1/r2`, index chain, epilogue sp8 read
 *     into r1) is byte-exact once these two swap back.
 * SOLVED THIS ROUND (keep):
 *   - yi/xi MUST be computed as raw-field shifts, not from the homed
 *     y/x: `yi = p->unk18 >> 23; xi = p->unk1C >> 23;` gives
 *     `asrs r1, r1, #23` / `asrs r2, r0, #23` reading the raw load
 *     pseudos (the >>16 y/x defs combine away). `yi = y >> 7` also
 *     combines to >>23 but reads the WRONG register in this build.
 * Allocation data (old_agbcc -dg, docs in /tmp/decomp/f1.c.greg):
 *   global order ... 30(xi, refs7 len16, pri 8750) ... 29(yi, 6315,
 *   pref r1) ... 22(p, refs7 len33, pri 4242). xi allocates before p
 *   and takes r3 (its conflicts exclude r0/r2, r1 taken by an earlier
 *   loop-temp allocno), forcing p to r4. p can ONLY take r3 among
 *   caller-saved (conflicts 0,1,2 hard). Flipping needs either p's pri
 *   > 8750 (impossible: 7 refs/33 insns) or xi's pri < 4242 (needs len
 *   > 33; it is 16) or xi to prefer/be-able-to-take r1.
 * Swept without flipping: xi/yi compute-order swap; xi/yi declaration
 * swap; mixed `xi = x >> 7`; u32 xi (flips branch polarity, wrong).
 */
#include "global.h"

extern u32 gUnk_0202CC24[];
extern u32 gUnk_0202CC34[];
extern u32 gUnk_0202CC38[];
extern u32 gUnk_0202CC3C[];

struct Unk0800C358 {
    u8 unk00[0x18];
    s32 unk18;
    s32 unk1C;
    u8 unk20[0xD4];
    u32 *unkF4;
    u32 *unkF8;
    u32 *unkFC;
    u16 *unk100;
};

u32 sub_0800C2CC(s32 a, s32 b, u32 *c, u8 *d);

u32 sub_0800C358(struct Unk0800C358 *p)
{
    u32 *table;
    u32 *tex;
    u32 best;
    u8 *cur;
    s32 y;
    s32 x;
    s32 yi;
    s32 xi;
    u8 *entry;
    u8 e;
    u32 res;
    u32 sp4;
    u32 sp8;

    table = p->unkF8;
    tex = p->unkF4;
    best = -1;
    gUnk_0202CC3C[0] = (u32)cur;
    y = p->unk18 >> 16;
    x = p->unk1C >> 16;
    yi = p->unk18 >> 23;
    xi = p->unk1C >> 23;
    if (yi < 0)
        yi = 0;
    if (xi < 0)
        xi = 0;
    if (yi > 47)
        yi = 47;
    if (xi > 47)
        xi = 47;
    entry = (u8 *)p->unkFC + p->unk100[xi * 48 + yi];
    while (*entry != 0xFF) {
        e = *entry;
        cur = (u8 *)table + e * 20;
        res = sub_0800C2CC(y, x, tex, cur);
        if (res <= best) {
            best = res;
            gUnk_0202CC3C[0] = (u32)cur;
            gUnk_0202CC34[0] = e;
            sp4 = gUnk_0202CC24[0];
            sp8 = gUnk_0202CC38[0];
        }
        entry++;
    }
    gUnk_0202CC24[0] = sp4;
    gUnk_0202CC38[0] = sp8;
    return best;
}
