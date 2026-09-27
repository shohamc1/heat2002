#include "global.h"
#include "variables.h"

void SerialIntr(void);


void SetLinkSerialIntr(void)
{
    gIntrTable[0] = (u32)SerialIntr;
}
