#include "global.h"

extern u8 gUnk_020020CC;
extern u32 gUnk_083C9574[];
extern u32 gUnk_083C97B4[];
extern u32 gUnk_083C99F4[];
extern u32 gUnk_083C9C34[];
extern u32 *gUnk_083C9E74[];

void sub_0800BE00(void *base, s32 arg)
{
    s32 row = arg >> 8;

    *(u32 *)((u8 *)base + 0xF0) = arg;
    *(u32 *)((u8 *)base + 0xF4) = gUnk_083C9574[row + gUnk_020020CC * 12];
    *(u32 *)((u8 *)base + 0xF8) = gUnk_083C97B4[row + gUnk_020020CC * 12];
    *(u32 *)((u8 *)base + 0xFC) = gUnk_083C99F4[row + gUnk_020020CC * 12];
    *(u32 *)&((u16 *)base)[0x80] = gUnk_083C9C34[row + gUnk_020020CC * 12];
    *(u32 *)&((u16 *)base)[0xAA] = *(u16 *)gUnk_083C9E74[row + gUnk_020020CC * 12];
}
