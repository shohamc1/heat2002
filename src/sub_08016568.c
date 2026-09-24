#include "global.h"

extern u32 gUnk_083FECAC[];
extern u8 gUnk_0202EDD0;

u32 sub_08016568(u16 a0, u8 a1) {
    return gUnk_083FECAC[a0 * 70 + gUnk_0202EDD0 * 14 + a1];
}
