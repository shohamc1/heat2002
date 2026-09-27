#include "global.h"
#include "data.h"
#include "functions.h"

extern u8 gUnk_0806C894[];
extern u8 gUnk_0806C8A0[];
extern u32 gUnk_0836813C[];
extern u32 gUnk_0836814C[];
extern u32 gUnk_0836815C[];
extern u32 gUnk_08368168[];
extern u8 gUnk_0202A524;
extern u8 gUnk_0202CBC0[];


void sub_08007F44(u8 a)
{
    sub_0800649C((u8 *)((u32)gUnk_0806C894), 0x0B, 0x07);
    if (a != 0 || (gUnk_0202A524 & 4) == 0)
    {
        sub_0800649C((u8 *)gUnk_0836813C[0], 0x06, 0x09);
        sub_0800649C((u8 *)(gUnk_0836814C[gUnk_0202CBC0[0]]), 0x0D, 0x09);
    }
    else
        sub_0800649C((u8 *)((u32)gUnk_0806C8A0), 0x06, 0x09);
    if (a != 1 || (gUnk_0202A524 & 4) == 0)
    {
        sub_0800649C((u8 *)gUnk_0836813C[1], 0x06, 0x0A);
        sub_0800649C((u8 *)(gUnk_0836815C[gUnk_0202CBC0[1]]), 0x0D, 0x0A);
    }
    else
        sub_0800649C((u8 *)((u32)gUnk_0806C878), 0x06, 0x0A);
    if (a != 2 || (gUnk_0202A524 & 4) == 0)
    {
        sub_0800649C((u8 *)gUnk_0836813C[2], 0x06, 0x0B);
        sub_0800649C((u8 *)(gUnk_08368168[gUnk_0202CBC0[2]]), 0x0D, 0x0B);
    }
    else
        sub_0800649C((u8 *)((u32)gUnk_0806C878), 0x06, 0x0B);
    if (a != 3 || (gUnk_0202A524 & 4) == 0)
        sub_0800649C((u8 *)gUnk_0836813C[3], 0x0D, 0x0C);
    else
        sub_0800649C((u8 *)((u32)gUnk_0806C8A0), 0x0A, 0x0C);
    gUnk_0202A524++;
}
