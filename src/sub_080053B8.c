#include "global.h"
#include "gba/io_reg.h"

void sub_080073D8(void);
void sub_08004484(void);
u32 sub_08003330(void);
u32 sub_08016558(u16 idx);
void sub_08006418(u32 a, u32 b, u32 c);
void sub_080019B4(u32 a);
void sub_080017D0(void);
void sub_08016E30(u32 a);
u32 sub_08004DB4(void);
void sub_0800420C(u32 a, u32 b);

void sub_080053B8(void)
{
    sub_080073D8();
    sub_08004484();
    while (1)
    {
        u16 r;
        *(u16 *)0x02002124 = 0;
        if (sub_08003330() != 0)
        {
            sub_08006418(sub_08016558(0x75), 0x0A, 1);
            sub_080019B4(0x02001F20);
            sub_080019B4(0x02001F60);
            sub_080017D0();
            while (1)
            {
                u32 r0 = *(u8 *)0x0202EF90;
                if (r0 == 0)
                    r0 = REG_KEYINPUT;
                sub_08016E30(r0);
            }
        }
        if (*(u8 *)0x0202EF90 != 0)
            sub_08006418(sub_08016558(0x58), 0x0E, 1);
        else
            sub_08006418(sub_08016558(0x0F), 0x0E, 1);
        r = sub_08004DB4();
        if (r & 8)
        {
            sub_0800420C(0, 0x32);
            return;
        }
    }
}
