#include "global.h"
#include "variables.h"


void ResetSpriteOrderTable(void)
{
    u32 i = 0;
    u16 *orderEntry = gSpriteOrderTable;

    while (i != 0x40)
    {
        *orderEntry = i;
        orderEntry += 1;
        i++;
    }
}
