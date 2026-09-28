#include "global.h"
#include "functions.h"
#include "data.h"



void sub_0800DFCC(void)
{
    u32 i;
    u32 *p;

    i = 0;
    p = gUiFontTable;
    do {
        *(u16 *)(*(volatile u32 *)&gTextLayerMapPtr[0] + 2 * i) = 0;  /* per-iteration reload, as the ROM loop */
        i++;
    } while (i != 0x380);
    DummyUiFontLoad(p[0]);
    GetString(0x52);
    ((void (*)(void))DrawBigText)();
}
