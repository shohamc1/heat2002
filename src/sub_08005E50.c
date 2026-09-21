#include "global.h"

struct Car {
    u8 pad00[0x8C];
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
};

extern u8 gUnk_0202EEB0;
extern u32 gUnk_08364B08[];
extern u8 gUnk_020251F4;
extern u16 gUnk_08335A8C[];
extern u8 gUnk_08334DCC[];

void sub_08005E50(struct Car *p)
{
    u16 *dest;
    u32 off;

    if (gUnk_0202EEB0 == 0)
        return;
    dest = (u16 *)(gUnk_08364B08[0] + 0x4A4);
    if (p->unk8C <= 0x7CFFF || (gUnk_020251F4 & 8) != 0) {
        off = 0x6C2;
        *dest = (0xE0 << 8) | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    } else {
        off = 0x6BE;
        *dest = (0xE0 << 8) | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    }
    if (p->unk90 <= 0x7CFFF || (gUnk_020251F4 & 8) != 0) {
        off = 0x6C4;
        dest[1] = (0xE0 << 8) | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    } else {
        off = 0x6C0;
        dest[1] = (0xE0 << 8) | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    }
    if (p->unk94 <= 0x7CFFF || (gUnk_020251F4 & 8) != 0) {
        off = 0x74A;
        dest[0x20] = (0xE0 << 8) | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    } else {
        off = 0x746;
        dest[0x20] = (0xE0 << 8) | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    }
    if (p->unk98 <= 0x7CFFF || (gUnk_020251F4 & 8) != 0) {
        off = 0x74C;
        dest[0x21] = (0xE0 << 8) | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    } else {
        off = 0x748;
        dest[0x21] = (0xE0 << 8) | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    }
    gUnk_020251F4++;
}
