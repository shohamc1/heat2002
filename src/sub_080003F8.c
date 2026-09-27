#include "global.h"
#include "variables.h"

void DummyIntr(void);


void SetVBlankCallback(u32 r0)
{
    gUnk_02000580[0] = r0;
    if (r0 == 0)
        gUnk_02000580[0] = (u32)DummyIntr;
}
