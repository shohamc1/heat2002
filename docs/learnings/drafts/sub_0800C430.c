/*
 * PARKED (wave 4): rebuild diverges from the ROM (first diff at ROM
 * 0x0800C430: ours pushes {r4,r5,r6,lr} vs ROM {r4-r7,lr}). Dead-agent
 * mid-edit state whose rebuild diverges while a stale .o once matched.
 * Needs re-derivation from the asm before extracting.
 */
#include "global.h"

extern u8 gUnk_02002090[];
extern u8 gUnk_0202CC28;
extern u8 gUnk_0202CC2C;

struct Car {
    s32 unk00;
    u8 pad04[4];
    s32 unk08;
    s32 unk0C;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[0x190 - 0x18];
};

extern struct Car gUnk_0202A550[];

void sub_0800C0FC(s32 *a, s32 b, s32 c, s32 *d);

void sub_0800C430(struct Car *a)
{
    s32 out[2];
    s32 i;
    s32 d;
    struct Car *e = gUnk_0202A550;

    gUnk_0202CC28 = 0;
    gUnk_0202CC2C = 0;
    for (i = 0; i != gUnk_02002090[0]; i++, e++) {
        if (a == e)
            continue;
        d = e->unk00 - a->unk00;
        if (d < 0)
            d = -d;
        if (d > 0xFA0000)
            continue;
        d = e->unk08 - a->unk08;
        if (d < 0)
            d = -d;
        if (d > 0xFA0000)
            continue;
        sub_0800C0FC(a, e->unk00, e->unk08, out);
        if (out[1] > -16)
            continue;
        if (out[0] < -16)
            continue;
        if (out[0] > 16)
            continue;
        if (out[1] > -128)
            gUnk_0202CC2C = 1;
        if (out[1] < -64)
            continue;
        gUnk_0202CC28 = (out[0] >= 0) ? 2 : 1;
    }
}
