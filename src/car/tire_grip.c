#include "global.h"
#include "functions.h"
#include "gba/defines.h"
#include "variables.h"
#include "car.h"

extern const struct TireGripSetup gTireGripDefaults[];

void SetTireGrip(struct Car *car, u8 carIndex)
{
    if (gIsLinkRace != 0) {
        gTireGripSlow = gTireGripDefaults[0].rearGripSlow;
        gTireGripFast = gTireGripDefaults[0].rearGripFast;
        gFrontTireGripSlow = gTireGripDefaults[0].frontGripSlow;
        gFrontTireGripFast = gTireGripDefaults[0].frontGripFast;
        gTireSlipLimitBase = gTireGripDefaults[0].slipLimitBase;
    } else if (carIndex == 0) {
        gTireGripSlow = gTireGripDefaults[0].rearGripSlow;
        gTireGripFast = gTireGripDefaults[0].rearGripFast;
        gFrontTireGripSlow = gTireGripDefaults[0].frontGripSlow;
        gFrontTireGripFast = gTireGripDefaults[0].frontGripFast;
        gTireSlipLimitBase = gTireGripDefaults[0].slipLimitBase;
    } else {
        gTireGripSlow = 160;
        gTireGripFast = 255;
        gFrontTireGripSlow = 128;
        gFrontTireGripFast = 128;
        gTireSlipLimitBase = 45152;
    }
}
