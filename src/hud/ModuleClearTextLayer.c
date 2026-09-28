#include "global.h"
#include "variables.h"


void ModuleClearTextLayer(void)
{
    u16 *p = (u16 *)(*(u32 *)&gModule_TextLayerMapPtr);
    u32 i = 0;

    do {
        *p++ = 0xE047;
        i++;
    } while (i != 0x380);
}
