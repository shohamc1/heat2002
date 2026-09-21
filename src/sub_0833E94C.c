#include "global.h"

struct Car {
    u8 pad00[0x8C];
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
};

extern u8 gUnk_0203E0E0;
extern u32 gUnk_020251B8[];
extern u8 gUnk_0203B6A4;
extern u16 gUnk_02022254[];
extern u8 gUnk_02021594[];

void sub_0833E94C(struct Car *p)
{
    u16 *dest;
    u32 off;

    if (gUnk_0203E0E0 == 0)
        return;
    dest = (u16 *)(gUnk_020251B8[0] + 0x4A4);
    if (p->unk8C <= 0x7CFFF || (gUnk_0203B6A4 & 8) != 0) {
        off = 0x6C2;
        *dest = (0xE0 << 8) | gUnk_02022254[*(u16 *)&gUnk_02021594[off]];
    } else {
        off = 0x6BE;
        *dest = (0xE0 << 8) | gUnk_02022254[*(u16 *)&gUnk_02021594[off]];
    }
    if (p->unk90 <= 0x7CFFF || (gUnk_0203B6A4 & 8) != 0) {
        off = 0x6C4;
        dest[1] = (0xE0 << 8) | gUnk_02022254[*(u16 *)&gUnk_02021594[off]];
    } else {
        off = 0x6C0;
        dest[1] = (0xE0 << 8) | gUnk_02022254[*(u16 *)&gUnk_02021594[off]];
    }
    if (p->unk94 <= 0x7CFFF || (gUnk_0203B6A4 & 8) != 0) {
        off = 0x74A;
        dest[0x20] = (0xE0 << 8) | gUnk_02022254[*(u16 *)&gUnk_02021594[off]];
    } else {
        off = 0x746;
        dest[0x20] = (0xE0 << 8) | gUnk_02022254[*(u16 *)&gUnk_02021594[off]];
    }
    if (p->unk98 <= 0x7CFFF || (gUnk_0203B6A4 & 8) != 0) {
        off = 0x74C;
        dest[0x21] = (0xE0 << 8) | gUnk_02022254[*(u16 *)&gUnk_02021594[off]];
    } else {
        off = 0x748;
        dest[0x21] = (0xE0 << 8) | gUnk_02022254[*(u16 *)&gUnk_02021594[off]];
    }
    gUnk_0203B6A4++;
}
