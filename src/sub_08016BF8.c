#include "global.h"
extern u16 gUnk_0202F040[];
extern void InitEeprom(void);
extern void ReadSaveBlocks(u32 a, u32 b);
u32 IsSaveValid(void)
{
    InitEeprom();
    ReadSaveBlocks(0, 8);
    if (gUnk_0202F040[0] == 0xA482 && gUnk_0202F040[1] == 0x7674)
        return 1;
    return 0;
}
