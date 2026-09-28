#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "functions.h"

void sub_083398E4(void);
void sub_08339920(void);

void sub_083398D4(void)
{
    sub_083398E4();
    sub_08339920();
}

void sub_083398E4(void)
{
    DmaFill32(3, 0, EWRAM_START, 0x40000);
    DmaFill32(3, 0, IWRAM_START, 0x7E00);
}

void sub_08339934(void);
void sub_0833995C(void);
void sub_083399C0(void);

void sub_08339920(void)
{
    sub_08339934();
    sub_0833995C();
    sub_083399C0();
}

void sub_08339934(void)
{
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
}

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

void sub_083399C0(void)
{
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
}

s16 sub_083399E8(s16 arg0, s16 arg1)
{
    s32 prod = arg0 * arg1;

    prod /= 256;
    return prod;
}

s16 sub_08339A00(s16 arg0, s16 arg1)
{
    return (arg0 << 8) / arg1;
}

void CarNeedsPit(u32 arg);

s16 sub_08339A18(u16 r0)
{
    /* sub_08344BB8: this file's old prototype is s16 (u32, s16); the
   matched definition uses s32; call through the old one. */
return ((s16 (*)(u32, s16))sub_08344BB8)(0x10000, r0);
}
