#include "global.h"
#include "functions.h"

void sub_0833D31C(u32 a, u32 b);
void sub_0833D448(void);

void sub_0833D53C(u32 a, u32 b)
{
    u32 i;

    sub_0833D31C(b, a);
    for (i = 0; i != b; i++)
    {
        sub_08339B18();
        sub_0833D448();
    }
}
