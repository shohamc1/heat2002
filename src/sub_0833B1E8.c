#include "global.h"

/* MidiKeyToCgbFreq, high 0x0833 module copy: same code as sub_08001B28
 * with the tables read from the module's EWRAM image (delta 0x17FF6E0 from
 * the low copies): gUnk_0200C7F4 = gCgbScaleTable, gUnk_0200C878 =
 * gCgbFreqTable, gUnk_0200C890 = gNoiseTable. */

extern const u8 gUnk_0200C7F4[];
extern const s16 gUnk_0200C878[];
extern const u8 gUnk_0200C890[];

u32 sub_0833B1E8(u8 chanNum, u8 key, u8 fineAdjust)
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

        return gUnk_0200C890[key];
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

        val1 = gUnk_0200C7F4[key];
        val1 = gUnk_0200C878[val1 & 0xF] >> (val1 >> 4);

        val2 = gUnk_0200C7F4[key + 1];
        val2 = gUnk_0200C878[val2 & 0xF] >> (val2 >> 4);

        return val1 + ((fineAdjust * (val2 - val1)) >> 8) + 2048;
    }
}
