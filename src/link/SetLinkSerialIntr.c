#include "global.h"
#include "variables.h"
#include "functions.h"

void SetLinkSerialIntr(void)
{ gIntrTable[0] = SerialIntr; }
