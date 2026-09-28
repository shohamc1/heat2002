#include "global.h"

struct Unk0800C984 {
    u32 a;
    u32 b;
};

void InitCarSteering(struct Unk0800C984 *steer, u32 heading)
{
    steer->b = heading;
    steer->a = heading;
}
