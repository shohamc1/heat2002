#include "global.h"
#include "variables.h"


void ModuleSerialIntr(void);

void ModuleSetLinkSerialIntr(void)
{
    gModule_IntrTable[0] = (u32)ModuleSerialIntr;
}
