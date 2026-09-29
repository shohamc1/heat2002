#include "global.h"
#include "car.h"
#include "variables.h"

void ModuleSetCameraPos(u32 x, u32 y)
{
    gModule_Camera[0] = x;
    gModule_Camera[1] = y;
    gModule_Camera[2] = x;
    gModule_Camera[3] = y;
    gModule_Camera[4] = 0;
    gModule_Camera[5] = 0;
}

void ModuleUpdateCameraScroll(void)
{
    s32 x = gModule_Camera[0];
    s32 y = gModule_Camera[1];
    s32 scrollX;
    s32 scrollY;

    x = x + 0x02580000;
    y = y + 0xFA8A0000;
    scrollX = (x - y) * 2;
    scrollY = x + y;
    scrollX = scrollX + 0xFF110000;
    scrollY = scrollY + 0xFF610000;
    scrollX = scrollX >> 17;
    scrollY = scrollY >> 17;
    gModule_Camera[6] = scrollX + 0x78;
    gModule_Camera[7] = scrollY + 0x50;
}

void ModuleSmoothCamera(void)
{
    s32 diffX = gModule_Camera[2] - gModule_Camera[0];
    s32 diffY = gModule_Camera[3] - gModule_Camera[1];

    if (gModule_IsDemo[0] != 0) {
        gModule_Camera[0] = gModule_Camera[0] + diffX;
        gModule_Camera[1] = gModule_Camera[1] + diffY;
    } else {
        gModule_Camera[0] = gModule_Camera[0] + (diffX >> 4);
        gModule_Camera[1] = gModule_Camera[1] + (diffY >> 4);
    }
}

void ModuleSetCameraTarget(struct Car *car)
{
    if (gModule_IsDemo[0] != 0) {
        gModule_Camera[2] = car->posX;
        gModule_Camera[3] = car->posZ;
    } else {
        gModule_Camera[2] = car->posX + car->velX * 20;
        gModule_Camera[3] = car->posZ + car->velZ * 20;
    }
}
