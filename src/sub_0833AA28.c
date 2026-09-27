#include "global.h"

extern void sub_0833A7F4(struct MusicPlayerInfo *mplayInfo);

void sub_0833AA28(void)
{
    /* sub_0833A7F4: the ROM call passes no argument; the matched definition takes one; call
       through a function pointer with the old prototype. */
    ((void (*)(void))sub_0833A7F4)();
}
