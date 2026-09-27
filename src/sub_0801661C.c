#include "global.h"
#include "variables.h"


u32 sub_08016E38(u32 a);
u32 sub_08016EA0(u32 a, u32 b);

u32 InitEeprom(void)
{
    sub_08016E38(4);
    {
        u32 p = (u32)gIntrTable;

        return sub_08016EA0(3, p);
    }
}
