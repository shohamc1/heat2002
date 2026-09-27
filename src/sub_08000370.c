#include "global.h"
#include "variables.h"

void SerialIntr(void);


void SetLinkSerialIntr(void)
{
    gUnk_02000590[0] = (u32)SerialIntr;
}
