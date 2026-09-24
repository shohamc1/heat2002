#include "global.h"

void MPlayFadeOut(u32 arg0, u32 arg1);

void m4aMPlayFadeOut(u32 arg0, u32 arg1)
{
    MPlayFadeOut(arg0, (u16)arg1);
}
