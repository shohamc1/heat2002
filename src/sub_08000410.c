#include "global.h"
#include "variables.h"


void AckVBlank(void);

void VBlankIntr(void)
{
    if (gVBlankCallback[0] != 0)
        /* gVBlankCallback[0]: this file's old local prototype differs from
           functions.h; call through the old signature (solved-walls 31). */
        ((void (*)(void))gVBlankCallback[0])();
    AckVBlank();
}
