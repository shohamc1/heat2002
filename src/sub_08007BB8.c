#include "global.h"
#include "variables.h"

struct Track {
    /* +0x00 */ u32 unk00;
    /* +0x04 */ u32 unk04;
    /* +0x08 */ u32 unk08;
    /* +0x0C */ u32 unk0C;
    /* +0x10 */ u32 unk10;
    /* +0x14 */ u32 unk14;
    /* +0x18 */ u32 unk18;
};

extern struct Track gUnk_08367A14[];

void BuildStartingGrid(u8 a1)
{
    u32 x = gUnk_08367A14[a1].unk00;
    u32 y = gUnk_08367A14[a1].unk04;
    u32 *p = gUnk_0202A3F0;
    u8 j;

    for (j = 0; j != 12; j++) {
        p[0] = x;
        p[1] = y;
        p[2] = gUnk_08367A14[a1].unk18;
        p += 3;
        p[0] = x + gUnk_08367A14[a1].unk10;
        p[1] = y + gUnk_08367A14[a1].unk14;
        p[2] = gUnk_08367A14[a1].unk18;
        p += 3;
        x += gUnk_08367A14[a1].unk08;
        y += gUnk_08367A14[a1].unk0C;
    }
}
