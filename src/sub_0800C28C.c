#include "global.h"

struct Unk0800C28C {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    s32 unk20;
    u32 unk24;
    u32 unk28;
    s32 unk2C;
};

void sub_0800C28C(struct Unk0800C28C *r)
{
    if (r->unk2C > (s32)0xFFFF0000)
    {
        r->unk18 = r->unk00;
        r->unk1C = r->unk08;
    }
    else
    {
        r->unk18 = r->unk00 + r->unk0C * 8 + r->unk0C * 4 + r->unk0C * 2;
        r->unk1C = r->unk08 + r->unk14 * 8 + r->unk14 * 4 + r->unk0C * 2;
    }
}
