#include "global.h"
#include "data.h"

void ClearTextLayer(void)
{
    u16 *p = (*(u16 **)&gTextLayerMapPtr);
    u32 i = 0;

    do {
        *p++ = 0xE047;
        i++;
    } while (i != 0x380);
}
