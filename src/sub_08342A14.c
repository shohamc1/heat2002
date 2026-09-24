#include "global.h"

extern u8 gUnk_020392C4;
extern u8 gUnk_0203916C;
extern u8 gUnk_020390D4;

void sub_0833FFA8(u32 a);
void sub_0833FF84(u32 a);
void sub_08339B18(void);

void sub_08342A14(u32 a)
{
    s32 t;

    if (gUnk_020392C4 == 0)
    {
        t = *(s32 *)(a + 0x18);
        if (t > 0x2D)
        {
            if (gUnk_0203916C == 9)
                gUnk_0203916C = 6;
            if (gUnk_0203916C == 0xD)
                gUnk_0203916C = 0xC;
            if (gUnk_0203916C == 0xE)
                gUnk_0203916C = 2;
            if (gUnk_0203916C == 0xF)
                gUnk_0203916C = 0x10;
            if (gUnk_0203916C == 0x11)
                gUnk_0203916C = 5;
            gUnk_020390D4 = 1;
        }
        *(s32 *)(a + 0x18) = t + 1;
        if (t + 1 == 0x7A)
        {
            sub_0833FFA8(a);
            sub_0833FF84(a);
        }
        if (gUnk_020390D4 == 0)
            sub_08339B18();
    }
}
