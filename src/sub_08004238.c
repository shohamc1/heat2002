#include "global.h"

void sub_08004018(u32 a, u32 b);
void sub_08000458(void);
void sub_08004144(void);

void sub_08004238(u32 a, u32 b)
{
    u32 i;

    sub_08004018(b, a);
    for (i = 0; i != b; i++)
    {
        sub_08000458();
        sub_08004144();
    }
}
