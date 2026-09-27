#include "global.h"
#include "functions.h"

u32 sub_08341644(s32 x, s32 y, s32 *out);

void sub_08342F4C(u32 a)
{
    s32 out[2];
    s32 t;
    s32 t2;

    if ((u8)sub_08341644(*(s32 *)(a + 0x00), *(s32 *)(a + 0x08), out) != 0)
    {
        out[0] -= 4;
        t2 = out[1] - 4;
        out[1] = t2 + (*(s32 *)(a + 0x04) >> 2);
    }
    t = *(s32 *)(a + 0x18) + 2;
    *(s32 *)(a + 0x18) = t;
    *(s32 *)(a + 0x04) -= 1;
    *(s32 *)(a + 0x00) += *(s32 *)(a + 0x28) >> 1;
    *(s32 *)(a + 0x08) += *(s32 *)(a + 0x30) >> 1;
    if (t == 0x10)
    {
        sub_0833FFA8(a);
        sub_0833FF84(a);
    }
}
