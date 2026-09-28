#include "global.h"

extern const u8 gText_ChampPenalised[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_08014C48(void)
{
    return sub_08012384((u32)gText_ChampPenalised, 0x38, 0x4C);
}
