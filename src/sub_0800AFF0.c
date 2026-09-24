#include "global.h"

extern u8 gUnk_020021E0;
extern u8 gUnk_02002098;
extern u8 gCallback_0800AF45[];   /* Thumb entry: function address | 1 */

u32 AllocTask(void);
void AddTask(u32 a);

void EndRace(void)
{
    u8 *p = &gUnk_020021E0;
    if (*p == 0)
    {
        u32 *r = (u32 *)AllocTask();
        if (r != 0)
        {
            r[7] = gUnk_02002098;
            r[6] = 0x64;
            r[3] = (u32)gCallback_0800AF45;
            AddTask((u32)r);
        }
        *p = 1;
    }
}
