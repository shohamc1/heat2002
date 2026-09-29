#include "global.h"

extern void (*gUnk_02001E18)(u32);
extern void (*gUnk_02001E1C)(void *);

void ClearChain(u32 x)
{ gUnk_02001E18(x); }

void Clear64byte(void *x)
{ gUnk_02001E1C(x); }
