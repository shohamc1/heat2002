#include "global.h"
#include "variables.h"

extern u32 gUnk_0203C390[];

struct SlotFF44
{
    u32 a[15];
    u32 b;
    u32 c;
};

void *sub_0833FF44(void)
{
    u32 i = 0;
    u32 flagsAddr = (u32)gUnk_0203C340;
    u32 one = 1;
    struct SlotFF44 *p = (struct SlotFF44 *)gUnk_0203C390;
    u32 off = 0;
    u32 q = (u32)&p[0].b;

    while (i != 0x40)
    {
        if (*(u8 *)(i + flagsAddr) == 0)
        {
            *(u8 *)(i + flagsAddr) = one;
            *(u32 *)(off + q) = i;
            return p;
        }
        p++;
        off += 0x44;
        i++;
    }
    return 0;
}
