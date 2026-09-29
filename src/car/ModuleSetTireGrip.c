#include "global.h"
#include "variables.h"
#include "car.h"

extern u32 gUnk_02026E20[];

void ModuleSetTireGrip(struct Car *car, u8 carIndex)
{
    if (gModule_IsLinkRace != 0) {
        gUnk_0203DCF4 = gUnk_02026E20[0];
        gUnk_0203D4E0 = gUnk_02026E20[1];
        gUnk_0203DDE4 = gUnk_02026E20[2];
        gUnk_0203DDFC = gUnk_02026E20[3];
        gUnk_0203D4DC = gUnk_02026E20[4];
        return;
    }
    if (carIndex == 0) {
        gUnk_0203DCF4 = gUnk_02026E20[0];
        gUnk_0203D4E0 = gUnk_02026E20[1];
        gUnk_0203DDE4 = gUnk_02026E20[2];
        gUnk_0203DDFC = gUnk_02026E20[3];
        gUnk_0203D4DC = gUnk_02026E20[4];
        return;
    }
    gUnk_0203DCF4 = 0xA0;
    gUnk_0203D4E0 = 0xFF;
    gUnk_0203DDE4 = 0x80;
    gUnk_0203DDFC = 0x80;
    gUnk_0203D4DC = 0xB060;
}
