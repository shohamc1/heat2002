#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_BlankRow12[];
extern u8 gModule_BlankRow24[];


void sub_083402D8(void)
{
    u32 p;

    ModuleDrawText(gModule_BlankRow12, 0x0B, 0x07);
    p = (u32)gModule_BlankRow24;
    ModuleDrawText(p, 0x06, 0x09);
    ModuleDrawText(p, 0x06, 0x0A);
    p = (u32)gModule_BlankRow28;
    ModuleDrawText(p, 0x06, 0x0B);
    ModuleDrawText(p, 0x0A, 0x0C);
}
