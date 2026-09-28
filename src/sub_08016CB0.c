#include "global.h"
#include "functions.h"
#include "variables.h"
struct Unk0202A550 { u8 filler[0x16C]; u32 finishTime; u8 filler170[400 - 0x170]; };
extern const struct AiFinishTimeRange gTrackAiFinishTimeRanges[];
void sub_08016CB0(void)
{
    u32 a = gTrackAiFinishTimeRanges[gTrackId].min;
    u32 b = gTrackAiFinishTimeRanges[gTrackId].max;
    struct Unk0202A550 *p = (struct Unk0202A550 *)gUnk_0202A6E0;
    s32 i = 0;
    do {
        p->finishTime = RandomInRange(a, b);
        i++;
        p++;
    } while (i != 0x17);
}
