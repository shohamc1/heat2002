#include "global.h"

void CallFunc(void (*func)(void))
{
    asm("bx r0");
}
