#include "global.h"

extern void (*gUnk_02001E18)(u32);
extern void (*gUnk_02001E1C)(u32);

void ClearChain(u32 x)
{ gUnk_02001E18(x); }

void Clear64byte(u32 x)
{ gUnk_02001E1C(x); }
