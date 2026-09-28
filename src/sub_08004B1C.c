#include "global.h"
#include "functions.h"
#include "variables.h"

extern s32 gTuneMenuSteps[];
extern s32 gTuneMenuMinValues[];
extern s32 gTuneMenuMaxValues[];


void sub_08004B1C(u8 arg)
{
    s32 val;
    u32 sel = arg;
    u32 *p;
    u32 idx;
    u32 j;

    if (sel <= 4) {
        val = gUnk_0202A540[idx];
        p = gUnk_0202CB20;
    } else {
        val = gUnk_0202CB20[idx - 5];
        p = gUnk_0202CB20;
    }
    if (gKeysPressed & 0x20) {
        val = val - gTuneMenuSteps[sel];
        if (val < gTuneMenuMinValues[sel])
            val = gTuneMenuMinValues[sel];
    }
    if (gKeysPressed & 0x10) {
        val = val + gTuneMenuSteps[sel];
        if (val > gTuneMenuMaxValues[sel])
            val = gTuneMenuMaxValues[sel];
    }
    if (sel <= 4)
        gUnk_0202A540[idx] = val;
    else
        *(p + (j = idx - 5)) = val;
    sub_0800830C((u16 *)p,(u16 *)gUnk_0202CB00);
}
