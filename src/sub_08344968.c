#include "global.h"
#include "variables.h"

extern u32 gUnk_0203DFF4;

void sub_08339A30(void);
void sub_08344878(void);

void sub_08344968(void)
{
    u32 *p1;
    u16 *p2;
    u8 *p3;
    register u8 mask asm("r3");
    u8 i;
    u8 j;

    *(volatile u16 *)0x04000134 = 0;
    *(volatile u16 *)0x04000128 = 0;
    i = 0;
    p1 = &gUnk_0203DFF4;
    p2 = &gUnk_0203917C;
    p3 = gUnk_0203E1C0;
    mask = 0xFF;
    do
    {
        p3[i * 4 + 0] |= mask;
        p3[i * 4 + 1] |= mask;
        p3[i * 4 + 2] |= mask;
        i++;
    } while (i != 4);
    *p1 = 0;
    *p2 = 0;
    sub_08339A30();
    sub_08344878();
    *(volatile u16 *)0x04000200 |= 0x80;
    if ((*(u8 *)0x04000128 & 0x30) == 0)
        *(volatile u16 *)0x04000200 |= 0x40;
    i = 0;
    do
    {
        gUnk_0203DFB8[i] = 0;
        j = 0;
        do
        {
            *(u16 *)((u8 *)gModule_LinkRecvWords + j * 2 + i * 8) = 0;
            j++;
        } while (j <= 3);
        i++;
    } while (i <= 3);
}
