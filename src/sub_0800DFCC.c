#include "global.h"
#include "functions.h"
#include "data.h"

extern u16 *gUnk_08364B08;


void sub_0800DFCC(void)
{
    u32 i;
    u32 *p;

    i = 0;
    p = gUnk_083FDE18;
    do {
        gUnk_08364B08[i] = 0;
        i++;
    } while (i != 0x380);
    /* sub_08006734: this file's old prototype takes an argument the matched definition drops; call
       through a function pointer with the old signature. */
    ((void (*)(u32))sub_08006734)(p[0]);
    GetString(0x52);
    ((void (*)(void))sub_080065A8)();
}
