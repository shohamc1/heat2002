#include "global.h"

extern u32 gUnk_02000580;

void AckVBlank(void);

void VBlankIntr(void)
{
    if (gUnk_02000580 != 0)
        /* gUnk_02000580: this file's old local prototype differs from
           functions.h; call through the old signature (solved-walls 31). */
        ((void (*)(void))gUnk_02000580)();
    AckVBlank();
}
