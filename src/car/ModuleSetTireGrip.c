#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

// Row 0 of gTireGripDefaults (src/data/race_setup.c) as five u32s, carried
// in the module image: the second GBA has no cartridge to read it from.
extern u32 gModule_TireGripDefaults[];

void ModuleSetTireGrip(struct Car *car, u8 carIndex)
{
    if (gModule_IsLinkRace != 0) {
        gModule_TireGripSlow = gModule_TireGripDefaults[0];
        gModule_TireGripFast = gModule_TireGripDefaults[1];
        gModule_FrontTireGripSlow = gModule_TireGripDefaults[2];
        gModule_FrontTireGripFast = gModule_TireGripDefaults[3];
        gModule_TireSlipLimitBase = gModule_TireGripDefaults[4];
        return;
    }
    if (carIndex == 0) {
        gModule_TireGripSlow = gModule_TireGripDefaults[0];
        gModule_TireGripFast = gModule_TireGripDefaults[1];
        gModule_FrontTireGripSlow = gModule_TireGripDefaults[2];
        gModule_FrontTireGripFast = gModule_TireGripDefaults[3];
        gModule_TireSlipLimitBase = gModule_TireGripDefaults[4];
        return;
    }
    gModule_TireGripSlow = 0xA0;
    gModule_TireGripFast = 0xFF;
    gModule_FrontTireGripSlow = 0x80;
    gModule_FrontTireGripFast = 0x80;
    gModule_TireSlipLimitBase = 0xB060;
}
