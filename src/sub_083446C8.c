#include "global.h"
#include "variables.h"


void sub_083446C8(u8 param)
{
    u8 v;
    register u8 w asm("r3");

    v = param;
    w = v;
    if (v == 0) {
        gUnk_0203E140[0] = 1;
        gUnk_0203E140[1] = 1;
        gUnk_0203E140[2] = 1;
        gUnk_0203E140[3] = 1;
        gUnk_0203E140[4] = 1;
        gUnk_0203E140[5] = 1;
        gUnk_0203E140[6] = 1;
    }
    if (v == 1) {
        gUnk_0203E140[7] = v;
        gUnk_0203E140[8] = v;
        gUnk_0203E140[9] = v;
        gUnk_0203E140[10] = v;
        gUnk_0203E140[11] = v;
    }
    if (w == 2) {
        gUnk_0203E140[12] = 1;
        gUnk_0203E140[13] = 1;
        gUnk_0203E140[14] = 1;
        gUnk_0203E140[15] = 1;
        gUnk_0203E140[16] = 1;
    }
}
