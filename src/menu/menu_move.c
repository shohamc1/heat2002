#include "global.h"
#include "gba/io_reg.h"
#include "m4a.h"
#include "variables.h"

s16 MenuMoveVertical(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_UP) {
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_DOWN) {
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}

s16 MenuMoveVerticalSilent(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_UP) {
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_DOWN) {
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}

s16 MenuMoveHorizontal(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_LEFT) {
        gMenuValueChanged = 1;
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_RIGHT) {
        gMenuValueChanged = 1;
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}

s16 MenuMoveHorizontalSilent(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_LEFT) {
        gMenuValueChanged = 1;
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_RIGHT) {
        gMenuValueChanged = 1;
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}

s16 MenuMoveHorizontalClamped(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_LEFT) {
        gMenuValueChanged = 1;
        v = v - 1;
        if (v < lo)
            v = lo;
        else if (gOptions[3] != 0)
            m4aSongNumStart(8);
    }
    if (keys & DPAD_RIGHT) {
        gMenuValueChanged = 1;
        v = v + 1;
        if (v > hi)
            v = hi;
        else if (gOptions[3] != 0)
            m4aSongNumStart(8);
    }
    return v;
}
