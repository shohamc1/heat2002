#include "global.h"

extern u16 gUnk_02022DE4;
extern u16 gUnk_0200BC34;
extern u16 gUnk_02022DF4;

void sub_08016E10(u32 src, u32 dest, u32 control);

struct Track {
    /* +0x00 */ u32 unk00;
    /* +0x04 */ u32 unk04;
    /* +0x08 */ u8 filler08[100 - 8];
};

extern struct Track gUnk_08364B0C[];

/* Each case carries its own copy of the body so expand_case counts 12
   distinct labels and emits a jump table; cross-jumping then merges the
   twelve identical bodies, leaving every table entry at one address. */
void sub_08003890(u8 idx)
{
    switch (idx) {
    case 0:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 1:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 2:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 3:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 4:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 5:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 6:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 7:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 8:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 9:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 10:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 11:
        sub_08016E10(gUnk_08364B0C[idx].unk04, 0x06000000, 0x4000);
        sub_08016E10(gUnk_08364B0C[idx].unk00, 0x06008000, 0x2000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    }
}
