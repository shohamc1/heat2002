#include "global.h"

struct Ent1F08 {
    u8 pad00[0x7C];
    u8 unk7C;
    u8 pad7D[3];
    u32 unk80;
    u8 pad84[0x88 - 0x84];
    u32 unk88;
    u8 pad8C[0xA2 - 0x8C];
    u16 unkA2;
    u8 padA4[0x160 - 0xA4];
    u16 unk160;
};

extern struct Ent1F08 gUnk_0203D520[];
extern u8 gUnk_0203916C;
extern s32 gUnk_0203B6CC;

void sub_08341F04(struct Ent1F08 *p);

void sub_08341F08(struct Ent1F08 *p)
{
    p->unk88 = 0;
    p->unk7C = 2;
    p->unk80 = 1;
    p->unk160 = 0;
    p->unkA2 = 0;
    sub_08341F04(p);
    if (p == gUnk_0203D520 && gUnk_0203916C == 0)
    {
        gUnk_0203B6CC += 5;
        if (gUnk_0203B6CC > 0x63)
            gUnk_0203B6CC = 0x63;
    }
}
