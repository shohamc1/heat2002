#include "global.h"
#include "variables.h"

struct Unk0833D848
{
    u32 a;
    u32 b;
    u16 c;
    u16 d;
};

extern u32 *gUnk_0203ACD0;
extern u32 *gUnk_0203ACD8;
extern struct Unk0833D848 gUnk_0203B0F0[];

u32 sub_0833D7E8(void);

void sub_0833D848(void)
{
    u32 *ptr;
    u32 *wp;
    u16 *ip;
    struct Unk0833D848 *e;
    u32 i;

    i = gUnk_0203ACD4;
    while (i != 0x3F)
    {
        ptr = gUnk_0203ACD0;
        ((u16 *)ptr)[4] = 0;
        ptr[1] = 0xFFFFFFFF;
        ptr = ptr + 3;
        gUnk_0203ACD0 = ptr;
        i++;
    }
    sub_0833D7E8();
    ip = gUnk_0203B610;
    for (i = 0; i != gUnk_0203ACD4; i++)
    {
        e = &gUnk_0203B0F0[*ip];
        if (e->b != 0xFFFFFFFF)
        {
            wp = gUnk_0203ACD8;
            wp[0] = e->a;
            wp[1] = e->b;
            gUnk_0203ACD8 = wp + 2;
        }
        ip++;
    }
}
