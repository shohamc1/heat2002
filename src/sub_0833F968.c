#include "global.h"

struct OamInit
{
    u32 f0;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u32 f8;
    u32 fC;
    u32 f10;
};

void sub_0833F968(u32 count, u16 *src, struct OamInit *dst)
{
    u32 i;

    for (i = 0; i != count; i++, dst++, src++)
    {
        dst->f8 = 0xFFFF;
        dst->f0 = 0;
        dst->f4 = 0;
        dst->f10 = *src;
        dst->fC = (*src << 5) + 0x06010000;
        dst->f6 = 0;
    }
}
