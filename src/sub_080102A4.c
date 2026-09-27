#include "global.h"
#include "functions.h"


void WaitFrames(s32 n)
{
    s32 i;

    if (n > 0) {
        for (i = n; i != 0; i--)
            WaitForVBlank();
    }
}
