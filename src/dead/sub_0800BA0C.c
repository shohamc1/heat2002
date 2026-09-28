#include "global.h"

struct EntBA0C {
    s32 posX;
    s32 f04;
    s32 posZ;
    u8 pad0C[0x28 - 0x0C];
    s32 f28;
    s32 f2C;
    s32 f30;
};

s32 BounceOffWalls(struct EntBA0C *ent);

void sub_0800BA0C(struct EntBA0C *e)
{
    BounceOffWalls(e);
    e->posX = e->posX + e->f28;
    e->f04 = e->f04 + e->f2C;
    e->posZ = e->posZ + e->f30;
}
