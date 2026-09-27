#include "global.h"
#include "variables.h"


u8 sub_0833C828(u16 r0, u8 r1)
{
    u16 v0 = r0;

    if (r1 == 0) {
        if (v0 != gModule_LinkTxSeqNum)
            return 0;
    } else {
        if (v0 != ((gModule_LinkTxSeqNum + 1) & 7))
            return 0;
    }
    return 1;
}
