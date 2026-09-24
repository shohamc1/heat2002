#include "global.h"

/* MidiKeyToCgbFreq. Tables: gUnk_0801D114 = gCgbScaleTable (u8),
 * gUnk_0801D198 = gCgbFreqTable (s16), gUnk_0801D1B0 = gNoiseTable (u8). */

extern const u8 gUnk_0801D114[];
extern const s16 gUnk_0801D198[];
extern const u8 gUnk_0801D1B0[];

u32 sub_08001B28(u8 chanNum, u8 key, u8 fineAdjust)
{
    if (chanNum == 4)
    {
        if (key <= 20)
        {
            key = 0;
        }
        else
        {
            key -= 21;
            if (key > 59)
                key = 59;
        }

        return gUnk_0801D1B0[key];
    }
    else
    {
        s32 val1;
        s32 val2;

        if (key <= 35)
        {
            fineAdjust = 0;
            key = 0;
        }
        else
        {
            key -= 36;
            if (key > 130)
            {
                key = 130;
                fineAdjust = 255;
            }
        }

        val1 = gUnk_0801D114[key];
        val1 = gUnk_0801D198[val1 & 0xF] >> (val1 >> 4);

        val2 = gUnk_0801D114[key + 1];
        val2 = gUnk_0801D198[val2 & 0xF] >> (val2 >> 4);

        return val1 + ((fineAdjust * (val2 - val1)) >> 8) + 2048;
    }
}
