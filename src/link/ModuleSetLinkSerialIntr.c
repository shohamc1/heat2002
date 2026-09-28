#include "global.h"
#include "variables.h"


void sub_083448F4(void);

void ModuleSetLinkSerialIntr(void)
{
    gModule_IntrTable[0] = (u32)sub_083448F4;
}
