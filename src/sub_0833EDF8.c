#include "global.h"
#include "functions.h"
#include "variables.h"

void sub_0833EDB8(void);

extern u8 gModule_PitLabelBlock[];

void sub_0833EDF8(void)
{
    sub_0833EDB8();
    if (gUnk_0203E1E0[0] != 0)
        ModuleDrawText(gModule_PitLabelBlock, 0, 0x12);
}
