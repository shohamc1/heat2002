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
        s32 bend = *(s8 *)(r2 + 0xE) * *(u8 *)(r2 + 0xF);
        s32 x = (*(s8 *)(r2 + 0xC) + bend) * 4
              + (*(s8 *)(r2 + 0xA) << 8)
              + (*(s8 *)(r2 + 0xB) << 8)
              + *(u8 *)(r2 + 0xD);
        if (*(u8 *)(r2 + 0x18) == 0)
        {
            x += *(s8 *)(r2 + 0x16) << 4;
        }
        *(u8 *)(r2 + 0x8) = (u8)(x >> 8);
        *(u8 *)(r2 + 0x9) = (u8)x;
    }

    *(u8 *)(r2 + 0x00) = r3 & 0xFA;
}
