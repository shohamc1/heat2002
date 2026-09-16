#include "global.h"
#include "gba/io_reg.h"

struct Unk03007FF0
{
    u32 magic;
    volatile u8 x;
    u8 pad[3];
    u32 y;
};

extern struct Unk03007FF0 *gUnk_03007FF0;

void sub_0833AF0C(void)
{
    struct Unk03007FF0 *r2 = gUnk_03007FF0;
    u32 r3 = r2->magic;

    if (r3 != 0x68736D53)
    {
        REG_DMA1CNT_H = 0xB6 << 8;
        REG_DMA2CNT_H = 0xB6 << 8;
        r2->x = 0;
        r2->magic = r3 - 0xA;
    }
}
