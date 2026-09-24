#include "global.h"

extern u16 gUnk_020253CC;
extern u16 gUnk_020251FC;
extern u16 gUnk_02025218;

void ResetLapTimer(void)
{
    gUnk_020253CC = 0;
    gUnk_020251FC = 0;
    gUnk_02025218 = 0;
}
