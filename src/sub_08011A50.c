#include "global.h"
#include "gba/io_reg.h"
extern u32 gUnk_0202EDBC;
extern u16 gUnk_0200216C;
struct Unk_0202EFA0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};
extern struct Unk_0202EFA0 gUnk_0202EFA0[];
extern u16 gUnk_0202ED78[];
extern u16 gUnk_0202EF40[4][4];
extern void sub_08000370(void);
extern void sub_0800F7E0(void);
void sub_08011A50(void)
{
    u8 i;
    u8 j;
    REG_RCNT = 0;
    REG_SIOCNT = 0;
    i = 0;
    do {
        gUnk_0202EFA0[i].unk0 |= 0xFF;
        gUnk_0202EFA0[i].unk1 |= 0xFF;
        gUnk_0202EFA0[i].unk2 |= 0xFF;
        i++;
    } while (i != 4);
    gUnk_0202EDBC = 0;
    gUnk_0200216C = 0;
    sub_08000370();
    sub_0800F7E0();
    REG_IE |= 0x80;
    if ((*(u8 *)0x04000128 & 0x30) == 0)
        REG_IE |= 0x40;
    i = 0;
    do {
        gUnk_0202ED78[i] = 0;
        j = 0;
        do {
            gUnk_0202EF40[i][j] = 0;
            j++;
        } while (j < 4);
        i++;
    } while (i < 4);
}
