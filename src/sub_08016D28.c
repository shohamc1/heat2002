#include "global.h"
struct Unk0202A550 {
    u8 filler0[0x4C];
    s8 unk4C;
    u8 filler4D[0x50 - 0x4D];
    u32 unk50;
    u8 filler54[0x7D - 0x54];
    u8 unk7D;
    u8 filler7E[0x104 - 0x7E];
    u16 unk104;
    u16 unk106;
    u16 unk108;
    u8 filler10A[0x16C - 0x10A];
    u32 unk16C;
    u8 filler170[400 - 0x170];
};
extern struct Unk0202A550 gUnk_0202A550[];
extern u32 gUnk_083FED18[];
extern u8 gUnk_020020CC;
extern u32 sub_08017230(u32 a, s32 b);
extern u32 sub_08016D08(u32 a, u8 b);
void sub_08016D28(u8 a)
{
    struct Unk0202A550 *p;
    s32 i;
    s32 v;
    u32 w;
    u32 u;
    u32 x;
    if (a != 0) {
        p = gUnk_0202A550;
        i = 0;
        do {
            if (p->unk7D != 0)
                p->unk16C = p->unk104 * 60000 + p->unk106 * 1000 + p->unk108;
            i++;
            p++;
        } while (i != 0x18);
    }
    v = gUnk_0202A550[0].unk4C * gUnk_083FED18[gUnk_020020CC];
    w = gUnk_0202A550[0].unk16C;
    u = sub_08017230(w, v);
    p = gUnk_0202A550;
    i = 0;
    do {
        if (p->unk7D == 0) {
            x = u * (v - sub_08016D08(p->unk50, gUnk_020020CC)) + w;
            p->unk16C = x;
            p->unk7D = 1;
        }
        i++;
        p++;
    } while (i != 0x18);
}
