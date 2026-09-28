#include "global.h"
#include "gba/io_reg.h"
#include "variables.h"

void ResetBgScroll(void)
{
    gUnk_0200BC48 = gUnk_0200BC4C = gUnk_02022DF8 = gUnk_0200BC2C = gUnk_02022DE0 =
        gUnk_02022DE8 = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
}
