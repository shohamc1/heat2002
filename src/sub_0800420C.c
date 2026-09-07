#include "global.h"

void sub_08003F84(u32 a, u32 b);
void sub_08000458(void);
void sub_08004144(void);

void sub_0800420C(u32 r0, u32 r1)
{
    u32 r4;
    u32 r2 = (u16)r0;

    sub_08003F84(r1, r2);
    for (r4 = 0; r4 != r1; r4++)
    {
        sub_08000458();
        sub_08004144();
    }
}
