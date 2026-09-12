#include "global.h"

extern u8 gUnk_02025ED0[];
extern u32 gUnk_02025FE0[];

struct Slot78E4
{
    u32 a[15];
    u32 b;
    u32 c;
};

void *sub_080078E4(void)
{
    u32 i = 0;
    u32 flagsAddr = (u32)gUnk_02025ED0;
    u32 one = 1;
    struct Slot78E4 *p = (struct Slot78E4 *)gUnk_02025FE0;
    u32 off = 0;
    u32 q = (u32)&p[0].b;

    while (i != 0x100)
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
