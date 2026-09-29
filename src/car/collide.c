#include "global.h"
#include "data.h"
#include "variables.h"
#include "car.h"
#include "functions.h"

struct unk_D64C
{
    u32 a;
    u32 c;
    u8 b;
    u8 d;
    u32 g;
};

void BuildCarCollFrame(struct Car *car, s32 *frame)
{
    s32 x, z;
    s32 v;

    v = -(car->heading >> 8) & 0xFF;
    frame[0] = gSinTable[v];
    frame[1] = gSinTable[v + 0x40];
    x = car->posX;
    frame[4] = x >> 8;
    z = car->posZ;
    frame[5] = z >> 8;
    v = car->heading + (s16)car->yawRate;
    v = -(v >> 8) & 0xFF;
    frame[2] = gSinTable[v];
    frame[3] = gSinTable[v + 0x40];
    frame[6] = (x + car->velX) >> 8;
    frame[7] = (z + car->velZ) >> 8;
}

void KeepNearestCarContact(s32 a, u8 b, s32 c, u8 d, struct unk_D64C *e, u8 *f, s32 g, s32 h)
{
    if (h < gUnk_0202CD24) {
        e->a = a;
        e->c = c;
        e->b = b;
        e->d = d;
        e->g = g;
        *f = 1;
        gUnk_0202CD24 = h;
    }
}
