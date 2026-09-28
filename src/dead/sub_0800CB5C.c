#include "global.h"
#include "variables.h"

u32 sub_0800CAB4(u32 n);
u32 sub_0800CB5C(s32 a, s32 b)
{
  /* The r0 pin keeps the sum in the outgoing argument register so the
     products allocate r2/r0 and the final add reads `adds r0, r2, r0`. */
  register u32 s asm("r0") = a * a + b * b;
  return sub_0800CAB4(s);
}

u8 GetTrackTileType(s32 x, s32 y);

u8 sub_0800CB70(u8 *a1, s32 a2, s32 a3)
{
    if ((*(u32 *)&gFrameCounter) == *(u32 *)(a1 + 0x138))
        return *(u8 *)(a1 + 0x134);
    *(u32 *)(a1 + 0x134) = GetTrackTileType(a2, a3);
    *(u32 *)(a1 + 0x138) = (*(u32 *)&gFrameCounter);
    return *(u8 *)(a1 + 0x134);
}
