#include "global.h"
#include "gba/io_reg.h"

extern u32 gUnk_02000580;
extern u32 gUnk_03007FFC;
extern u32 gUnk_02000590[];
extern volatile u32 gUnk_040000D4[];

void sub_08000430(void);

void sub_08000380(void)
{
    sub_08000430();
    gUnk_02000580 = 0x0800042D;
    gUnk_040000D4[0] = 0x08000104;
    gUnk_040000D4[1] = 0x020005D0;
    gUnk_040000D4[2] = 0x80000400;
    (void)gUnk_040000D4[2];
    gUnk_03007FFC = 0x020005D0;
    REG_WAITCNT = 0x00004014;
    gUnk_02000590[1] = 0x08000411;
    gUnk_02000590[0] = 0x0800042D;
    gUnk_02000590[2] = 0x0800042D;
    gUnk_02000590[3] = 0x0800042D;
    gUnk_02000590[4] = 0x0800042D;
    gUnk_02000590[5] = 0x0800042D;
    gUnk_02000590[6] = 0x0800042D;
    gUnk_02000590[7] = 0x0800042D;
    gUnk_02000590[8] = 0x0800042D;
    gUnk_02000590[9] = 0x0800042D;
    gUnk_02000590[10] = 0x0800042D;
    gUnk_02000590[11] = 0x0800042D;
    gUnk_02000590[12] = 0x0800042D;
    gUnk_02000590[13] = 0x0800042D;
}
