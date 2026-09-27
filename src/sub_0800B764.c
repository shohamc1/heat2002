#include "global.h"
#include "car.h"

void sub_0800B7E0(void);

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B764(u8 a, u8 b)
{
    u32 r;
    u32 v1, v2;
    struct Car *car;

    r = AllocTask();
    if (r != 0) {
        car = &gCars[a];
        *(u32 *)(r + 0x18) = 0;
        *(u8 *)(r + 0x34) = a;
        *(u32 *)(r + 0x1C) = b;
        *(u32 *)(r + 0x20) = 2;
        v1 = car->nextCornerX[b];
        *(u32 *)(r + 0x00) = v1;
        *(u32 *)(r + 0x04) = 0;
        v2 = car->nextCornerZ[b];
        *(u32 *)(r + 0x08) = v2;
        *(u32 *)(r + 0x28) = v1 - car->cornerX[b];
        *(u32 *)(r + 0x30) = v2 - car->cornerZ[b];
        *(u32 *)(r + 0x0C) = (u32)sub_0800B7E0;
        AddTask(r);
    }
}
