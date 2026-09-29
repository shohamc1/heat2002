#include "global.h"

void TrkVolPitSet(u32 mplayInfo, u32 track)
{
    u32 trackPtr = track;
    u32 isPitchSet;
    u32 flags;
    u32 envFactor;
    u32 type;
    s32 pan;
    u8 flagsAfter;

    flags = *(u8 *)(trackPtr + 0x00);
    if (flags & 1) {
        envFactor = (u32)(*(u8 *)(trackPtr + 0x12) * *(u8 *)(trackPtr + 0x13)) >> 5;
        type = *(u8 *)(trackPtr + 0x18);
        if (type == 1) {
            envFactor = (u32)((*(s8 *)(trackPtr + 0x16) + 0x80) * envFactor) >> 7;
        }
        pan = (*(s8 *)(trackPtr + 0x14) << 1) + *(s8 *)(trackPtr + 0x15);
        if (type == 2) {
            pan += *(s8 *)(trackPtr + 0x16);
        }
        if (pan < -0x80) {
            pan = -0x80;
        } else if (pan > 0x7F) {
            pan = 0x7F;
        }
        *(u8 *)(trackPtr + 0x10) = (u8)(((pan + 0x80) * envFactor) >> 8);
        *(u8 *)(trackPtr + 0x11) = (u8)(((0x7F - pan) * envFactor) >> 3 >> 5);
    }

    flags = *(u8 *)(trackPtr + 0x00);
    isPitchSet = flags & 4;
    flagsAfter = flags;
    if (isPitchSet) {
        s32 bend = *(s8 *)(trackPtr + 0xE) * *(u8 *)(trackPtr + 0xF);
        s32 x = (*(s8 *)(trackPtr + 0xC) + bend) * 4 + (*(s8 *)(trackPtr + 0xA) << 8) + (*(s8 *)(trackPtr + 0xB) << 8) +
                *(u8 *)(trackPtr + 0xD);
        if (*(u8 *)(trackPtr + 0x18) == 0) {
            x += *(s8 *)(trackPtr + 0x16) << 4;
        }
        *(u8 *)(trackPtr + 0x8) = (u8)(x >> 8);
        *(u8 *)(trackPtr + 0x9) = (u8)x;
    }

    *(u8 *)(trackPtr + 0x00) = flagsAfter & 0xFA;
}
