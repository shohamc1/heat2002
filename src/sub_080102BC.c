#include "global.h"

extern volatile u16 gKeysPressed; /* 0x020005CC */

void sub_08000458(void);
void sub_0800048C(void);

void sub_080102BC(s32 count)
{
    s32 i;

    for (i = 0; i < count; i++)
    {
        sub_08000458();
        sub_0800048C();
        if (gKeysPressed & 0x3FF)
            return;
    }
}
