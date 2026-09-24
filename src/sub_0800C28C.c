#include "global.h"

struct Unk0800C28C {
    u32 posX;
    u32 unk04;
    u32 posZ;
    u32 velX;
    u32 unk10;
    u32 velZ;
    u32 unk18;
    u32 unk1C;
    s32 unk20;
    u32 unk24;
    u32 unk28;
    s32 speed;
};

void sub_0800C28C(struct Unk0800C28C *r)
{
    if (r->speed > (s32)0xFFFF0000)
    {
        r->unk18 = r->posX;
        r->unk1C = r->posZ;
    }
    else
    {
        r->unk18 = r->posX + r->velX * 8 + r->velX * 4 + r->velX * 2;
        r->unk1C = r->posZ + r->velZ * 8 + r->velZ * 4 + r->velX * 2;
    }
}
