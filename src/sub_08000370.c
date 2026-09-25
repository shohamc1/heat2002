#include "global.h"

void SerialIntr(void);

extern u32 gUnk_02000590[];

void SetLinkSerialIntr(void)
{
    gUnk_02000590[0] = (u32)SerialIntr;
}
