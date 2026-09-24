#include "global.h"

extern u32 gUnk_02000580;

void AckVBlank(void);

void VBlankIntr(void)
{
    if (gUnk_02000580 != 0)
        ((void (*)(void))gUnk_02000580)();
    AckVBlank();
}
