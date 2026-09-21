#include "global.h"

void sub_08001A74(u32 r0, u32 r1)
{
    u32 r2 = r1;
    u32 cond;
    u32 flags;
    u32 envfactor;
    u32 type;
    s32 pan;
    u8 r3;
    s32 freq;

    flags = *(u8 *)(r2 + 0x00);
    if (flags & 1)
    {
        envfactor = (u32)(*(u8 *)(r2 + 0x12) * *(u8 *)(r2 + 0x13)) >> 5;
        type = *(u8 *)(r2 + 0x18);
        if (type == 1)
        {
            envfactor = (u32)((*(s8 *)(r2 + 0x16) + 0x80) * envfactor) >> 7;
        }
        pan = (*(s8 *)(r2 + 0x14) << 1) + *(s8 *)(r2 + 0x15);
        if (type == 2)
        {
            pan += *(s8 *)(r2 + 0x16);
        }
        if (pan < -0x80)
        {
            pan = -0x80;
        }
        else if (pan > 0x7F)
        {
            pan = 0x7F;
        }
        *(u8 *)(r2 + 0x10) = (u8)(((pan + 0x80) * envfactor) >> 8);
        *(u8 *)(r2 + 0x11) = (u8)(((0x7F - pan) * envfactor) >> 3 >> 5);
    }

    flags = *(u8 *)(r2 + 0x00);
    cond = flags & 4;
    r3 = flags;
    if (cond)
    {
        freq = *(s8 *)(r2 + 0xE);
        freq = *(u8 *)(r2 + 0xF) * freq;
        freq = *(s8 *)(r2 + 0xC) + freq;
        freq = freq << 2;
        freq += *(s8 *)(r2 + 0xA) << 8;
        freq += *(s8 *)(r2 + 0xB) << 8;
        freq += *(u8 *)(r2 + 0xD);
        if (*(u8 *)(r2 + 0x18) == 0)
        {
            freq += *(s8 *)(r2 + 0x16) << 4;
        }
        *(u8 *)(r2 + 0x8) = (u8)(freq >> 8);
        *(u8 *)(r2 + 0x9) = (u8)freq;
    }

    *(u8 *)(r2 + 0x00) = r3 & 0xFA;
}
