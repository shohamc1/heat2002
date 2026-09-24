#include "global.h"

extern u8 gOptions[];

void m4aSongNumStart(u32 a);
void sub_0800184C(void);

void sub_080100B0(void)
{
    if (gOptions[2] != 0)
        m4aSongNumStart(2);
    sub_0800184C();
}
