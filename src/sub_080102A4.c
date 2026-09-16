#include "global.h"

extern void sub_08000458(void);

void sub_080102A4(s32 n)
{
    s32 i;

    if (n > 0) {
        for (i = n; i != 0; i--)
            sub_08000458();
    }
}
