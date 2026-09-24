#include "global.h"

struct Unk0A5BC {
    u8 pad0[0x0C];
    u32 velX;
    u32 f10;
    u32 velZ;
    u8 pad18[0x24];
    u16 yawRate;
    u8 gear;
    u16 rpm;
    u8 pad42[0x106];
    u32 torque;
};

void StopCar(struct Unk0A5BC *p)
{
    u32 a;
    u8 b;

    a = 0;
    p->velX = a;
    p->velZ = a;
    b = 0;
    p->yawRate = a;
    p->torque = a;
    p->rpm = a;
    p->gear = b;
}
