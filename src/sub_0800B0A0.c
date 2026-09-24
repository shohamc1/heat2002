#include "global.h"

struct EntityB0A0 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ u32 unk18;
};

extern u32 gUnk_083FF5B0[];        /* 0x083FF5B0 */
extern u8 gUnk_08330AD4[];         /* 0x08330AD4 */
extern volatile u8 gUnk_020020DC;  /* 0x020020DC */
extern u8 gUnk_0806C96C[];         /* 0x0806C96C */

u32 *sub_0800754C(u32 a);
u8 sub_08007714(u32 a);
u32 sub_080044A4(u32 a, u32 b);
void sub_08006418(u8 *str, u32 y, u32 z);
void sub_08007950(struct EntityB0A0 *e);
void sub_0800792C(struct EntityB0A0 *e);

void sub_0800B0A0(struct EntityB0A0 *e)
{
    u32 *spr;
    u32 counter;
    u32 attr;
    u32 arg1;
    u8 idx;

    counter = e->unk18;
    idx = (u8)e->unk18 % 0x17;
    e->unk18 = counter + 1;
    spr = sub_0800754C(gUnk_083FF5B0[idx]);
    if (spr != 0)
    {
        register u32 attr asm("r6") = 0x80680040;
        u32 t;

        t = (sub_08007714((u32)gUnk_08330AD4) << 12) | 0x400;
        arg1 = spr[4] | t;
        if (gUnk_020020DC == 0)
            sub_080044A4(attr, arg1);
    }
    if (e->unk18 == 0x30)
    {
        sub_08007950(e);
        sub_0800792C(e);
    }
    sub_08006418(gUnk_0806C96C, 8, 1);
}
