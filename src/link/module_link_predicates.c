#include "global.h"
#include "gba/defines.h"
#include "variables.h"

u8 ModuleIsLinkSeqNumExpected(u16 seq, u8 next)
{
    u16 recvSeq = seq;

    if (next == 0) {
        if (recvSeq != gModule_LinkTxSeqNum)
            return 0;
    } else {
        if (recvSeq != ((gModule_LinkTxSeqNum + 1) & 7))
            return 0;
    }
    return 1;
}

u32 ModuleIsValidLinkKeys(u32 keys)
{
    u32 tmp = keys << 16;
    if (((tmp >> 21) & 3) == 3)
        return 0;
    if (((tmp >> 19) & 3) == 3)
        return 0;
    return 1;
}
