#include "global.h"
#include "data.h"


void ZeroTextLayer(void)
{
    u32 *dest = (u32 *)*(u32 *)&gTextLayerMapPtr[0];
    u32 r1 = 0;
    u32 val = 0;
    u32 r2 = 0xA0 << 1;

    do
    {
        *dest = val;
        dest++;
        r1++;
    } while (r1 != r2);
}
