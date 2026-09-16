#include "global.h"

extern u8 gUnk_02002090;
extern u8 gUnk_020020DC;
extern u8 gUnk_020020AC;

struct Standing {
    u8 pad0[0x50];
    s32 score;
    u8 pad54[0xFC];
    u8 rank;
    u8 pad151[0x3F];
};

extern struct Standing gUnk_0202A550[];

void sub_08009B20(u8 idx)
{
    u8 n = gUnk_02002090;
    u8 count;
    s32 threshold;
    u32 j;

    if (gUnk_020020DC != 0)
        n = gUnk_020020AC;
    count = 0;
    threshold = gUnk_0202A550[idx].score;
    for (j = 0; j != n; j++) {
        if (j != idx && gUnk_0202A550[j].score > threshold)
            count++;
    }
    gUnk_0202A550[idx].rank = count;
}
