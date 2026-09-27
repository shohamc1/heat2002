#include "global.h"
#include "functions.h"
extern u16 gUnk_0202F040[];
u32 IsSaveValid(void)
{
    InitEeprom();
    ReadSaveBlocks(0, 8);
    if (gUnk_0202F040[0] == 0xA482 && gUnk_0202F040[1] == 0x7674)
        return 1;
    return 0;
}
