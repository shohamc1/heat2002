#include "global.h"
struct Unk083FECB8 { u32 unk0; u32 unk4; };
struct Unk0202A550 { u8 filler[0x16C]; u32 unk16C; u8 filler170[400 - 0x170]; };
extern struct Unk083FECB8 gUnk_083FECB8[];
extern u8 gUnk_020020CC;
extern struct Unk0202A550 gUnk_0202A6E0[];
extern u32 sub_08016C30(u32 a, u32 b);
void sub_08016CB0(void)
{
    u32 a = gUnk_083FECB8[gUnk_020020CC].unk0;
    u32 b = gUnk_083FECB8[gUnk_020020CC].unk4;
    struct Unk0202A550 *p = gUnk_0202A6E0;
    s32 i = 0;
    do {
        p->unk16C = sub_08016C30(a, b);
        i++;
        p++;
    } while (i != 0x17);
}
