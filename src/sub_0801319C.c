#include "global.h"
#include "variables.h"

extern u8 *gCheatCodeTable[];

s8 sub_0801319C(void)
{
    u8 i;
    u8 *e;

    i = 0;
    do {
        e = gCheatCodeTable[i];
        if (e[0] == gCheatCodeDials[0]
            && e[1] == gCheatCodeDials[1]
            && e[2] == gCheatCodeDials[2]
            && e[3] == gCheatCodeDials[3]
            && e[4] == gCheatCodeDials[4])
            return i;
        i++;
    } while (i != 5);
    return -1;
}
