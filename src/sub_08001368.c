#include "global.h"

extern void sub_08001134(struct MusicPlayerInfo *mplayInfo);

void m4aMPlayContinue(void)
{
    /* sub_08001134: the ROM call passes no argument; the matched definition takes one; call
       through a function pointer with the old prototype. */
    ((void (*)(void))sub_08001134)();
}
