#include "global.h"
#include "gba/io_reg.h"

void sub_0800F0BC(u32 a);

void sub_0800F0D4(void)
{
    s32 i;

    i = 0;
    if ((REG_SIOCNT & 0x80) != 0)
    {
        do {
            i++;
        } while (i <= 0x795C && (REG_SIOCNT & 0x80) != 0);
    }
    sub_0800F0BC(0x258);
}
