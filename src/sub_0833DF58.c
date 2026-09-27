#include "global.h"
#include "functions.h"

struct Drv
{
    u8 filler0[0x7D];
    u8 unk7D;
    u8 filler7E[0x104 - 0x7E];
    u16 unk104;
    u16 unk106;
    u16 unk108;
    u8 filler10A[400 - 0x10A];
};

extern struct Drv gUnk_0203D520[];
extern u8 gUnk_0203B864;
extern u8 gUnk_0203B868[];
extern u8 gUnk_020390EC;
extern u8 gUnk_0203E1B0;
extern u32 gUnk_020251B8[];

void sub_0833DDB8(u32 a, u16 b, u16 c, u16 d);
void sub_08341A30(u8 a, u32 b, u8 c);

void sub_0833DF58(void)
{
    struct Drv *p;
    struct Drv *e;
    u32 base;
    u8 r7v;
    u8 r8v;
    u8 i;
    u8 n;

    if (gUnk_0203B864 == 0)
        return;
    p = gUnk_0203D520;
    if (gUnk_020390EC != 0)
        p = &gUnk_0203D520[gUnk_0203E1B0];
    if (p->unk7D == 0)
        return;
    r7v = 5;
    if (gUnk_020390EC != 0)
        r7v = 2;
    r8v = 1;
    for (i = 0; i != gUnk_0203B864; i++)
    {
        u32 *tbl = gUnk_020251B8;

        n = gUnk_0203B868[i];
        e = &gUnk_0203D520[n];
        if (gUnk_020390EC != 0)
            base = (0x14 + tbl[0]) + r7v * 128;
        else
            base = (0x14 + tbl[0]) + r7v * 64;
        sub_0833E3C8((u16 *)base, r8v);
        sub_0833DDB8(base, e->unk104, e->unk106, e->unk108);
        if (gUnk_020390EC != 0)
            sub_08341A30(0x40, r7v * 16, gUnk_0203B868[i]);
        r7v++;
        r8v++;
    }
}
