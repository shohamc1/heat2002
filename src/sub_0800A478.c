#include "global.h"

struct EntA478 {
    u8 pad00[0x7C];
    u8 unk7C;
    u8 pad7D[3];
    u32 unk80;
    u8 pad84[0x88 - 0x84];
    u32 damage;
    u8 pad8C[0xA2 - 0x8C];
    u16 unkA2;
    u8 padA4[0x160 - 0xA4];
    u16 unk160;
};

extern struct EntA478 gCars[];
extern u8 gUnk_0200215C;
extern s32 gUnk_0202521C;

void sub_0800A474(struct EntA478 *p);

void sub_0800A478(struct EntA478 *p)
{
    p->damage = 0;
    p->unk7C = 2;
    p->unk80 = 1;
    p->unk160 = 0;
    p->unkA2 = 0;
    sub_0800A474(p);
    if (p == gCars && gUnk_0200215C == 0)
    {
        gUnk_0202521C += 5;
        if (gUnk_0202521C > 0x63)
            gUnk_0202521C = 0x63;
    }
}
