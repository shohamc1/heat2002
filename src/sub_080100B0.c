#include "global.h"
#include "functions.h"
#include "m4a.h"

extern u8 gOptions[];


void sub_080100B0(void)
{
    if (gOptions[2] != 0)
        m4aSongNumStart(2);
    sub_0800184C();
}
