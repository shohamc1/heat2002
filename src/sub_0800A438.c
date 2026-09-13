#include "global.h"

struct Unk0800A438 {
    u8 pad0[0x7D];
    u8 unk7D;
    u8 pad7E[0x104 - 0x7E];
    u16 unk104;
    u16 unk106;
    u16 unk108;
};

extern u16 gUnk_02025260; /* 0x02025260 */
extern u16 gUnk_02025220; /* 0x02025220 */
extern u16 gUnk_02025224; /* 0x02025224 */

void sub_0800A438(struct Unk0800A438 *obj)
{
    obj->unk104 = gUnk_02025260;
    obj->unk106 = gUnk_02025220;
    obj->unk108 = gUnk_02025224;
    obj->unk7D = 1;
}
