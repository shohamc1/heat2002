#include "global.h"
#include "data.h"
#include "functions.h"

extern u8 gText_BlankRow12[];
extern u8 gText_BlankRow24[];


void sub_08007EF8(void)
{
    u32 p;

    DrawTextAt(gText_BlankRow12, 0x0B, 0x07);
    p = (u32)gText_BlankRow24;
    DrawTextAt(p, 0x06, 0x09);
    DrawTextAt(p, 0x06, 0x0A);
    p = (u32)gText_BlankRow28;
    DrawTextAt(p, 0x06, 0x0B);
    DrawTextAt(p, 0x0A, 0x0C);
}
