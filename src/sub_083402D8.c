#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_BlankRow12[];
extern u8 gModule_BlankRow24[];


void sub_083402D8(void)
{
    u32 p;

    sub_0833EF0C((u8 *)((u32)gModule_BlankRow12), 0x0B, 0x07);
    p = (u32)gModule_BlankRow24;
    sub_0833EF0C((u8 *)p, 0x06, 0x09);
    sub_0833EF0C((u8 *)p, 0x06, 0x0A);
    p = (u32)gModule_BlankRow28;
    sub_0833EF0C((u8 *)p, 0x06, 0x0B);
    sub_0833EF0C((u8 *)p, 0x0A, 0x0C);
}
