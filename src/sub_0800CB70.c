#include "global.h"
#include "variables.h"


u8 GetTrackTileType(s32 x, s32 y);

u8 sub_0800CB70(u8 *a1, s32 a2, s32 a3)
{
    if ((*(u32 *)&gFrameCounter) == *(u32 *)(a1 + 0x138))
        return *(u8 *)(a1 + 0x134);
    *(u32 *)(a1 + 0x134) = GetTrackTileType(a2, a3);
    *(u32 *)(a1 + 0x138) = (*(u32 *)&gFrameCounter);
    return *(u8 *)(a1 + 0x134);
}
