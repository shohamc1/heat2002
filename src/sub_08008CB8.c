#include "global.h"
#include "functions.h"

extern u8 gText_BlankRow8[];
extern u8 gText_BlankRow12_2[];


void sub_08008CB8(void)
{
    DrawTextAt(gText_BlankRow8, 0x0A, 0x0E);
    DrawTextAt(gText_BlankRow12_2, 0x0A, 0x0F);
}
