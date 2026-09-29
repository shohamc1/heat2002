#include "global.h"
#include "car.h"

void StopCar(struct Car *p)
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
