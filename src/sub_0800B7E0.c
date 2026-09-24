#include "global.h"

struct EntityB7E0 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x18 - 0x0C];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x28 - 0x1C];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ s32 unk30;
};

extern u32 gUnk_083FF60C[];        /* 0x083FF60C */
extern u8 gUnk_08330D18[];         /* 0x08330D18 */

u32 sub_08009BB4(s32 x, s32 y, s32 *out);
u32 *sub_080076C8(u32 a);
u8 sub_08007714(u32 a);
u32 sub_080044A4(u32 a, u32 b);
void sub_08007950(struct EntityB7E0 *e);
void sub_0800792C(struct EntityB7E0 *e);

void sub_0800B7E0(struct EntityB7E0 *e)
{
    s32 pos[2];
    u32 *spr;
    u32 attr;
    u32 t;
    u32 arg1;
    s32 old;
    s32 t1;

    if ((sub_08009BB4(e->unk00, e->unk08, pos) << 0x18) != 0)
    {
        old = pos[0];
        pos[0] = old - 4;
        t1 = pos[1] - 4;
        pos[1] = t1 + (e->unk04 >> 2);
        if ((u32)(old + 0x1B) <= 0x10E && pos[1] <= 0x9F && pos[1] > -0x20)
        {
            spr = sub_080076C8(gUnk_083FF60C[((e->unk18 + 8) & 7) + 8]);
            if (spr != 0)
            {
                attr = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 0x10);
                t = (sub_08007714((u32)gUnk_08330D18) << 12) | 0x800;
                arg1 = spr[4] | t;
                sub_080044A4(attr, arg1);
            }
        }
    }
    e->unk18 = e->unk18 + 2;
    e->unk04 = e->unk04 - 1;
    e->unk00 = e->unk00 + (e->unk28 >> 1);
    e->unk08 = e->unk08 + (e->unk30 >> 1);
    if (e->unk18 == 0x10)
    {
        sub_08007950(e);
        sub_0800792C(e);
    }
}
