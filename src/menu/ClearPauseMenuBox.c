#include "global.h"
#include "functions.h"
#include "data.h"

void ClearPauseMenuBox(void)
{
    u8 col, row;
    u16 *dest;

    dest = (*(u16 **)&gTextLayerMapPtr) + 0xA6;
    for (row = 0; row != 8; row++) {
        for (col = 0; col != 19; col++)
            *dest++ = 0xE047;
        dest += 13;
    }
}
