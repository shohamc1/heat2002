#include "global.h"

struct UnkStruct080043F8 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
};

extern u8 gUnk_020020E0;    /* 0x020020E0 */
extern u32 gUnk_02002100[]; /* 0x02002100 */

void sub_080043F8(struct UnkStruct080043F8 *arg0)
{
    if (gUnk_020020E0 != 0) {
        gUnk_02002100[2] = arg0->unk00;
        gUnk_02002100[3] = arg0->unk08;
    } else {
        gUnk_02002100[2] = arg0->unk00 + arg0->unk0C * 20;
        gUnk_02002100[3] = arg0->unk08 + arg0->unk14 * 20;
    }
}
