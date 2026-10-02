#include "global.h"
#include "functions.h"
#include "variables.h"

void sub_0800BA38(void *e);

void sub_0800BAFC(s32 a, s32 b)
{
    u32 *r;

    if (gGameMode == 2 || gGameMode == 0xA)
        return;
    r = (u32 *)AllocTask();
    if (r != 0) {
        r[6] = 0xF0;
        r[0] = a;
        r[1] = 0;
        r[2] = b;
        r[3] = (u32)sub_0800BA38;
        AddTask(r);
    }
}

void sub_0800BB3C(void)
{
}

void sub_0800BB40(void)
{
}

void sub_0800BB44(void)
{
}

void sub_0800BB48(void)
{
}

void sub_0800BB4C(void)
{
}

void sub_0800BB50(void)
{
}

void sub_0800BB54(void)
{
}
