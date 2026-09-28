#include "global.h"
#include "functions.h"
#include "variables.h"



void SetFadeDeltasColors240To255(u32 frames)
{
    register u32 *colorBase asm("r1");
    register u32 *deltaBase asm("r2");
    register u32 *colorPtr asm("r6");
    register u32 colorIdx asm("r8");
    u32 *deltaPtr;
    u32 target;

    colorIdx = 0xF0;
    deltaBase = (u32 *)gUnk_02023A20;
    colorBase = gUnk_02022E20;
    colorPtr = colorBase + 0x2D0;
    deltaPtr = deltaBase + 0x2D0;
loop:
    target = 0xF8 << 0xD;
    deltaPtr[0] = sub_08017230(target - colorPtr[0], frames);
    deltaPtr[1] = sub_08017230(target - colorPtr[1], frames);
    deltaPtr[2] = sub_08017230(target - colorPtr[2], frames);
    colorPtr += 3;
    deltaPtr += 3;
    colorIdx++;
    if (colorIdx != 0x100)
        goto loop;
}
