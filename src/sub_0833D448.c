#include "global.h"
#include "variables.h"

extern u32 gUnk_020392D0[]; /* 0x020392D0 */
extern u32 gUnk_02039ED0[]; /* 0x02039ED0 */

void sub_0833D4A4(void);

void sub_0833D448(void)
{
    int v;
    u32 i;
    u32 n;
    u32 *d;
    u32 *s;

    v = *(s16 *)&gUnk_020392C8;
    if (v == 0)
        gUnk_020392C4 = v;
    if (gUnk_020392C4 != 0)
    {
        sub_0833D4A4();
        i = 0;
        n = 0x300;
        d = gUnk_020392D0;
        s = gUnk_02039ED0;
        do {
            *d++ += *s++;
            i++;
        } while (i != n);
        gUnk_020392C8 -= 1;
    }
    gUnk_020392C0 = 1;
}
