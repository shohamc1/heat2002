#include "global.h"
#include "data.h"
#include "variables.h"

extern u32 gUnk_083C9574[];
extern u32 gUnk_083C97B4[];
extern u32 gUnk_083C99F4[];
extern u32 gUnk_083C9C34[];

void sub_0800BE00(void *base, s32 arg)
{
    s32 row = arg >> 8;

    *(u32 *)((u8 *)base + 0xF0) = arg;
    *(u32 *)((u8 *)base + 0xF4) = gUnk_083C9574[row + gTrackId * 12];
    *(u32 *)((u8 *)base + 0xF8) = gUnk_083C97B4[row + gTrackId * 12];
    *(u32 *)((u8 *)base + 0xFC) = gUnk_083C99F4[row + gTrackId * 12];
    *(u32 *)&((u16 *)base)[0x80] = gUnk_083C9C34[row + gTrackId * 12];
    *(u32 *)&((u16 *)base)[0xAA] = *(u16 *)gUnk_083C9E74[row + gTrackId * 12];
}
