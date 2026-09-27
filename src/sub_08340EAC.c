#include "global.h"
#include "functions.h"

extern u32 gUnk_0203DD60[];


u32 sub_08340EAC(void)
{
    u32 sum = 0;
    u8 i = 0;
    u32 v;
    u32 r;

    do {
        v = gUnk_0203DD60[i];
        sum += v;
        if (v == 0)
        {
            r = 0;
            goto end;
        }
        i++;
    } while (i != 0x0D);
    r = sub_08344BB8(sum, 0x0D) - 1;
end:
    return r;
}
