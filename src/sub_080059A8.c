#include "global.h"
#include "functions.h"
#include "variables.h"
#include "data.h"

extern u8 gUnk_0202525C[];


void sub_080059A8(void)
{
    u8 *d;
    s32 v;
    s32 w;

    d = gUnk_0202525C;
    v = gCountdownSeconds;
    d[1] = sub_080172C8(v, 10);
    d[0] = sub_08017230(v, 10);
    DrawBigDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0x82)), d[0]);
    DrawBigDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0x86)), d[1]);
    w = (*(s32 *)&gCountdownMs);
    d[1] = sub_080172C8(sub_08017230(w, 10), 10);
    d[0] = sub_08017230(w, 100);
    DrawSmallDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0xCA)), 10);
    DrawSmallDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0xCC)), d[0]);
    DrawSmallDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0xCE)), d[1]);
}
