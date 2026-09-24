#include "global.h"
#include "data.h"


struct Unk0800D5D4 {
    s32 posX;
    u8 pad04[4];
    s32 posZ;
    s32 velX;
    u8 pad10[4];
    s32 velZ;
    u8 pad18[0x34 - 0x18];
    u16 heading;
    u8 pad36[0x3C - 0x36];
    s16 yawRate;
};

void sub_0800D5D4(struct Unk0800D5D4 *a, s32 *d)
{
    s32 x, z;
    s32 v;

    v = -(a->heading >> 8) & 0xFF;
    d[0] = gUnk_0801CD08[v];
    d[1] = gUnk_0801CD08[v + 0x40];
    x = a->posX;
    d[4] = x >> 8;
    z = a->posZ;
    d[5] = z >> 8;
    v = a->heading + a->yawRate;
    v = -(v >> 8) & 0xFF;
    d[2] = gUnk_0801CD08[v];
    d[3] = gUnk_0801CD08[v + 0x40];
    d[6] = (x + a->velX) >> 8;
    d[7] = (z + a->velZ) >> 8;
}
