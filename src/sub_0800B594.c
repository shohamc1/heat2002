#include "global.h"

extern u8 gUnk_083682B0[];
extern u32 gCallback_0800B5D5[];

u32 sub_080078E4(void);
void sub_0800793C(u32 a);

void sub_0800B594(void)
{
    u32 i = 0;
    do {
        u32 *r = (u32 *)sub_080078E4();
        if (r != 0)
        {
            r[6] = 0x60;
            r[7] = i << 5;
            r[0] = gUnk_083682B0[i];
            r[1] = 0x28;
            r[3] = (u32)gCallback_0800B5D5;
            sub_0800793C((u32)r);
        }
        i++;
    } while (i != 0xC);
}
