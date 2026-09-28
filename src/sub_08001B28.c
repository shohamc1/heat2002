#include "global.h"

/* MidiKeyToCgbFreq. Tables: gCgbScaleTable = gCgbScaleTable (u8),
 * gCgbFreqTable = gCgbFreqTable (s16), gNoiseTable = gNoiseTable (u8). */

extern const u8 gCgbScaleTable[];
extern const s16 gCgbFreqTable[];
extern const u8 gNoiseTable[];

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

        return gNoiseTable[key];
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

        val1 = gCgbScaleTable[key];
        val1 = gCgbFreqTable[val1 & 0xF] >> (val1 >> 4);

        val2 = gCgbScaleTable[key + 1];
        val2 = gCgbFreqTable[val2 & 0xF] >> (val2 >> 4);

        return val1 + ((fineAdjust * (val2 - val1)) >> 8) + 2048;
    }
}
