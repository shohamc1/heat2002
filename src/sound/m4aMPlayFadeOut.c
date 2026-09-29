#include "global.h"

void MPlayFadeOut(u32 mplayInfo, u16 fadeOutDelay);

void m4aMPlayFadeOut(u32 arg0, u32 arg1)
{ MPlayFadeOut(arg0, arg1); }
