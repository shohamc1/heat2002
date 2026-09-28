#include "global.h"
#include "functions.h"

extern const u8 gModule_BlankRow8[];
extern const u8 gModule_BlankRow12_2[];


void sub_08340E28(void)
{
    ModuleDrawText(gModule_BlankRow8, 10, 14);
    ModuleDrawText(gModule_BlankRow12_2, 10, 15);
}
