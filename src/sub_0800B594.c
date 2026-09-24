#include "global.h"

extern u8 gUnk_083682B0[];
extern u8 gCallback_0800B5D5[];   /* Thumb entry: function address | 1 */

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B594(void)
{
    u32 i = 0;
    do {
        u32 *r = (u32 *)AllocTask();
        if (r != 0)
        {
            r[6] = 0x60;
            r[7] = i << 5;
            r[0] = gUnk_083682B0[i];
            r[1] = 0x28;
            r[3] = (u32)gCallback_0800B5D5;
            AddTask((u32)r);
        }
        i++;
    } while (i != 0xC);
}
