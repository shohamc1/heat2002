#include "global.h"
#include "variables.h"


void sub_0833D9F0(void)
{
    u8 i, j;
    u16 *p;

    p = (*(u16 **)&gModule_TextLayerMapPtr) + 0xA6;
    for (j = 0; j != 8; j++)
    {
        for (i = 0; i != 0x13; i++)
            *p++ = 0xE047;
        p += 13;
    }
}
