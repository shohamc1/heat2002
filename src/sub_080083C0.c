#include "global.h"

extern u8 gUnk_020020DC;
extern u32 gUnk_083677A8[];
extern u8 gUnk_0202CAD4;
extern u8 gUnk_0202A514;
extern u8 gUnk_0202CBC4;
extern u8 gUnk_0202CBDC;
extern u32 gUnk_0202A510;

void sub_080083C0(u32 a, u8 b)
{
    if (gUnk_020020DC != 0)
    {
        gUnk_0202CAD4 = gUnk_083677A8[0];
        gUnk_0202A514 = gUnk_083677A8[1];
        gUnk_0202CBC4 = gUnk_083677A8[2];
        gUnk_0202CBDC = gUnk_083677A8[3];
        gUnk_0202A510 = gUnk_083677A8[4];
    }
    else if (b == 0)
    {
        gUnk_0202CAD4 = gUnk_083677A8[0];
        gUnk_0202A514 = gUnk_083677A8[1];
        gUnk_0202CBC4 = gUnk_083677A8[2];
        gUnk_0202CBDC = gUnk_083677A8[3];
        gUnk_0202A510 = gUnk_083677A8[4];
    }
    else
    {
        gUnk_0202CAD4 = 0xA0;
        gUnk_0202A514 = 0xFF;
        gUnk_0202CBC4 = 0x80;
        gUnk_0202CBDC = 0x80;
        gUnk_0202A510 = 0x0000B060;
    }
}
