#include "global.h"
#include "functions.h"

extern u8 gUnk_0202F030;
extern u8 gUnk_0806C78C[];


void sub_08006388(void)
{
    InitRaceHud();
    if (gUnk_0202F030 != 0)
    {
        sub_0800649C(gUnk_0806C78C, 0, 0x12);
    }
}
