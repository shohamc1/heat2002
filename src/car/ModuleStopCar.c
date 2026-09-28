#include "global.h"

void ModuleStopCar(u32 car)
{
    u32 zero = 0;
    u32 torqueOffset = 0xA4 << 1;

    *(u32 *)(car + 0x0C) = zero;
    *(u32 *)(car + 0x14) = zero;
    *(u16 *)(car + 0x3C) = zero;
    *(u32 *)(car + torqueOffset) = zero;
    *(u16 *)(car + 0x40) = zero;
    *(u8 *)(car + 0x3E) = 0;
}
