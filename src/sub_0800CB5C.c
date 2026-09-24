#include "global.h"
u32 sub_0800CAB4(u32 n);
u32 sub_0800CB5C(s32 a, s32 b)
{
  /* The r0 pin keeps the sum in the outgoing argument register so the
     products allocate r2/r0 and the final add reads `adds r0, r2, r0`. */
  register u32 s asm("r0") = a * a + b * b;
  return sub_0800CAB4(s);
}
