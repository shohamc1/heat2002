#include "global.h"
#include "variables.h"

extern u32 gUnk_083FECAC[];

u32 sub_08016568(u16 a0, u8 a1) {
    return gUnk_083FECAC[a0 * 70 + gLinkSyncByte * 14 + a1];
}
