#include "global.h"

extern u8 gUnk_0202EEB0;
extern u8 gUnk_02025228;
extern u16 gUnk_02025398;
extern u8 gUnk_083387A8[];
extern u8 gUnk_08338788[];
extern u32 gUnk_08364B08[];
extern s32 gUnk_0200209C;
extern u16 gUnk_08335A8C[];
extern u8 gUnk_08334DCC[];
extern u8 gUnk_0202EF00[];
extern u8 gUnk_020020E0;

u32 sub_08007630(u32 r0);
u32 sub_08007714(u32 r0);
void sub_080044A4(u32 r0, u32 r1);
void sub_08001208(u32 r0);

void sub_08005AF0(s32 arg)
{
    u16 buf[2];
    u32 ptr;
    u32 v;
    u32 r1v;
    u16 *dest;
    u32 off;

    if (gUnk_0202EEB0 == 0)
        return;
    gUnk_02025228++;
    buf[0] = 0xAA;
    buf[1] = 0x89;
    ptr = sub_08007630((u32)gUnk_083387A8);
    if (ptr != 0) {
        v = buf[1] & 0xFF;
        v |= (buf[0] & 0x1FF) << 16;
        v |= 0x40000000;
        r1v = *(u32 *)(ptr + 0x10) | (((u32)sub_08007714((u32)gUnk_08338788) << 24) >> 12);
        sub_080044A4(v | 0x02000100, r1v);
    }
    gUnk_02025398 = ((arg >> 16) + 0xBE) & 0xFF;
    dest = (u16 *)(gUnk_08364B08[0] + 0x4EE);
    if (arg <= 0x31FF && (gUnk_0200209C & 0x10) != 0) {
        off = 0x5B2;
        *dest = 0xE000 | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
        if (gUnk_0202EF00[3] != 0) {
            if (gUnk_020020E0 == 0)
                sub_08001208(0x1B);
        }
    } else {
        off = 0x5B4;
        *dest = 0xE000 | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    }
}
