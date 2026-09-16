#include "global.h"
#include "gba/defines.h"

void sub_0833995C(void)
{
    vu16 *dst = (vu16 *)OAM;
    register u16 t asm("r1") = 0x200;
    register u16 hide asm("r2") = t;
    register u16 zero asm("r1") = 0;
    register u16 u asm("r3") = 0x100;
    register u16 affine asm("r4") = u;
    register s32 i asm("r3") = 31;

    do {
        *dst++ = hide;
        *dst++ = zero;
        *dst++ = zero;
        *dst++ = affine;
        *dst++ = hide;
        *dst++ = zero;
        *dst++ = zero;
        *dst++ = zero;
        *dst++ = hide;
        *dst++ = zero;
        *dst++ = zero;
        *dst++ = zero;
        *dst++ = hide;
        *dst++ = zero;
        *dst++ = zero;
        *dst++ = affine;
    } while (--i >= 0);
}
