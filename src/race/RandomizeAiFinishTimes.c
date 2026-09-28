#include "global.h"
#include "functions.h"
#include "variables.h"
struct Unk0202A550 { u8 filler[0x16C]; u32 finishTime; u8 filler170[400 - 0x170]; };
extern const struct AiFinishTimeRange gTrackAiFinishTimeRanges[];
void RandomizeAiFinishTimes(void)
{
    u32 minTime = gTrackAiFinishTimeRanges[gTrackId].min;
    u32 maxTime = gTrackAiFinishTimeRanges[gTrackId].max;
    struct Unk0202A550 *car = (struct Unk0202A550 *)gUnk_0202A6E0;
    s32 i = 0;
    do {
        car->finishTime = RandomInRange(minTime, maxTime);
        i++;
        car++;
    } while (i != 0x17);
}
