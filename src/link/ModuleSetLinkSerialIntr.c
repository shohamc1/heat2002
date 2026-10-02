#include "global.h"
#include "variables.h"
#include "functions.h"

void ModuleSetLinkSerialIntr(void)
{ gModule_IntrTable[0] = ModuleSerialIntr; }
