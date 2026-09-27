#include "global.h"
#include "variables.h"


struct unk_D64C
{
    u32 a;
    u32 c;
    u8 b;
    u8 d;
    u32 g;
};

void sub_0800D64C(s32 a, u8 b, s32 c, u8 d, struct unk_D64C *e, u8 *f, s32 g, s32 h)
{
    if (h < gUnk_0202CD24)
    {
        e->a = a;
        e->c = c;
        e->b = b;
        e->d = d;
        e->g = g;
        *f = 1;
        gUnk_0202CD24 = h;
    }
}
