#include "global.h"

struct Unk0202A550Drv
{
    u8 filler0[0x8C];
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
};

extern struct Unk0202A550Drv gUnk_0202A550[];

u8 sub_080079D0(struct Unk0202A550Drv *a1)
{
    u8 ret;

    if (a1 != gUnk_0202A550)
    {
        ret = 0;
        if (a1->unk9C <= 0x2800)
            ret = 1;
        if (a1->unk8C > 0x3E7FF
         || a1->unk90 > 0x3E7FF
         || a1->unk94 > 0x3E7FF
         || a1->unk98 > 0x3E7FF)
            ret = 1;
    }
    else
    {
        ret = 0;
        if (a1->unk9C <= 0x2800)
            ret = 1;
        if (a1->unk8C > 0x5DBFF
         || a1->unk90 > 0x5DBFF
         || a1->unk94 > 0x5DBFF
         || a1->unk98 > 0x5DBFF)
            ret = 1;
    }
    return ret;
}
