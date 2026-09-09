#include "global.h"

void sub_0800EA64(void *a1);

void sub_0800EED8(void *a1)
{
    if (*(u8 *)((u32)a1 + 0x18) != 0)
    {
        sub_0800EA64(a1);
    }
    else
    {
        *(u8 *)((u32)a1 + 0x4A) = 0;
        *(u8 *)((u32)a1 + 0x1E) = 0;
        *(u8 *)((u32)a1 + 0x18) = 1;
    }
}
