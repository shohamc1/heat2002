#include "global.h"

struct Unk1C20
{
    u8 filler0[0x2];
    u8 unk2;
    u8 unk3;
    u8 filler4[0x6 - 0x4];
    u8 unk6;
    u8 filler7[0xA - 0x7];
    u8 unkA;
    u8 filler0B[0x19 - 0x0B];
    s8 unk19;
    u8 filler1A[0x1B - 0x1A];
    u8 unk1B;
    u8 unk1C;
};

void sub_08001C20(struct Unk1C20 *s)
{
    u32 v;

    if (s->unk2 >= s->unk3)
    {
        if ((s->unk2 >> 1) >= s->unk3)
        {
            s->unk1B = 0x0F;
            goto clip;
        }
    }
    else
    {
        if ((s->unk3 >> 1) >= s->unk2)
        {
            s->unk1B = 0xF0;
            goto clip;
        }
    }
    s->unk1B = 0xFF;
    v = s->unk2 + s->unk3;
    v >>= 4;
    s->unkA = v;
    goto tail;

clip:
    v = s->unk2 + s->unk3;
    v >>= 4;
    s->unkA = v;
    if (v > 0xF)
        s->unkA = 0xF;

tail:
    s->unk19 = (s8)(((s->unkA * s->unk6) + 0xF) >> 4);
    s->unk1B = s->unk1B & s->unk1C;
}
