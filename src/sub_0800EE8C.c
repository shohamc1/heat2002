#include "global.h"
#include "gba/io_reg.h"

void sub_0800EA64(void *a1);

s32 sub_0800EE8C(void *a1, u16 a2)
{
    s32 local;

    local = REG_SIOCNT & 0x8C;
    if (local != 8)
    {
        sub_0800EA64(a1);
        return local ^ 8;
    }
    else
    {
        REG_SIODATA8 = a2;
        REG_SIOCNT = 0x2083;
        *(u8 *)((u32)a1 + 0x48) = 1;
        return 0;
    }
}
