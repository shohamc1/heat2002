#include "global.h"
#include "functions.h"

extern u32 gUnk_02038E68;
void _08344B80(u32 arg0, u32 arg1);
extern u32 gUnk_02038E6C;

void ModuleClearChain(u32 x)
{ _08344B80(x, gUnk_02038E68); }

void ModuleClear64byte(void *x)
{ _08344B80((u32)x, gUnk_02038E6C); }
