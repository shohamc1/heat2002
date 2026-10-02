#include "global.h"
#include "functions.h"
#include "car.h"

void ModuleStopCar(struct Car *car)
{
    u32 zero = 0;

    car->velX = zero;
    car->velZ = zero;
    car->yawRate = zero;
    car->torque = zero;
    car->rpm = zero;
    car->gear = 0;
}
