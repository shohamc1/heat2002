#include "global.h"

/* TODO: rename to CallFunc once the scripts can map names to addresses;
 * they only recognise sub_XXXXXXXX today. */
void sub_0800DE5C(void (*func)(void))
{
    asm("bx r0");
}
