#include "global.h"

extern u16 *gUnk_02002208;
extern u16 *gUnk_0200BC54;
extern u16 gUnk_02002220[];
extern u16 gUnk_0200BC70[];
extern u16 gUnk_02015690[];
extern u16 *gUnk_0200BC50;
extern u16 *gUnk_0200221C;
extern u16 *gUnk_02002210;
extern u32 gUnk_0200BC30;
extern u32 gUnk_02022DD8;
extern u32 gUnk_02022DF0;
extern u32 gUnk_0201567C;
extern u32 gUnk_02022DEC;
extern u32 gUnk_02002200[];
extern u16 gUnk_02022DE4;
extern u16 gUnk_0200BC34;
extern u32 gUnk_03000800[];
extern u8 gUnk_020253D4;
extern u16 gUnk_08335C60[];
extern u16 gUnk_08334BCC[];

struct Track {
    /* +0x00 */ u32 unk00;
    /* +0x04 */ u32 unk04;
    /* +0x08 */ u32 unk08;
    /* +0x0C */ u16 *unk0C;
    /* +0x10 */ u16 *unk10;
    /* +0x14 */ u32 unk14;
    /* +0x18 */ u32 unk18;
    /* +0x1C */ u32 unk1C;
    /* +0x20 */ u16 *unk20;
    /* +0x24 */ u16 *unk24;
    /* +0x28 */ u32 unk28;
    /* +0x2C */ u32 unk2C;
    /* +0x30 */ u32 unk30;
    /* +0x34 */ u32 unk34;
    /* +0x38 */ u32 unk38;
    /* +0x3C */ u32 unk3C;
    /* +0x40 */ u32 unk40;
    /* +0x44 */ u16 *unk44;
    /* +0x48 */ u32 unk48;
    /* +0x4C */ u8 filler4C[0x5C - 0x4C];
    /* +0x5C */ u16 unk5C;
    /* +0x5E */ u16 unk5E;
    /* +0x60 */ u16 unk60;
    /* +0x62 */ u8 filler62[0x64 - 0x62];
};

extern struct Track gUnk_08364B0C[];

void sub_08003890(u8 idx);
void sub_08016E10(u32 src, u32 dest, u32 control);
void sub_08004018(s32 arg0, u16 *src);
void sub_0800383C(u16 *src, u16 *dst, u16 count);
void sub_08003BFC(u32 x, u32 y, u16 *map, u32 *dest, u16 *charBase, u16 a6);
void sub_08003D90(void);
void sub_08004260(u32 x, u32 y);
void sub_08008F1C(u32 idx);
void sub_08005560(void);
void sub_0800557C(void);

void sub_08003928(u32 idx)
{
    u16 a[0xE0];
    u16 b[0x20];
    u16 *t;

    sub_08003890(idx);
    t = gUnk_08335C60;
    sub_08016E10(t, 0x0600C000, 0x1000);
    sub_08016E10(gUnk_08364B0C[idx].unk18, (u32)a, 0x100);
    sub_08016E10(t = gUnk_08334BCC, (u32)b, 0x10);
    sub_08004018(0x1E, a);
    gUnk_0200BC30 = gUnk_08364B0C[idx].unk2C;
    gUnk_02022DD8 = gUnk_08364B0C[idx].unk34;
    gUnk_02002208 = gUnk_02002220;
    gUnk_0200BC54 = gUnk_0200BC70;
    sub_0800383C(gUnk_08364B0C[idx].unk20, gUnk_02002220, gUnk_08364B0C[idx].unk5C);
    sub_0800383C(gUnk_08364B0C[idx].unk24, gUnk_0200BC70, gUnk_08364B0C[idx].unk5E);
    gUnk_0200221C = gUnk_08364B0C[idx].unk0C;
    gUnk_02002210 = gUnk_08364B0C[idx].unk10;
    gUnk_02022DF0 = gUnk_08364B0C[idx].unk3C;
    gUnk_0201567C = gUnk_08364B0C[idx].unk40;
    gUnk_0200BC50 = gUnk_02015690;
    sub_0800383C(gUnk_08364B0C[idx].unk44, gUnk_02015690, gUnk_08364B0C[idx].unk60);
    gUnk_02022DEC = gUnk_08364B0C[idx].unk48;
    if (idx == 0)
        gUnk_02002200[0] = 0x7D;
    if (idx == 1)
        gUnk_02002200[0] = 0x70;
    if (idx == 2)
        gUnk_02002200[0] = 0xA8;
    if (idx == 3)
        gUnk_02002200[0] = 0x6B;
    if (idx == 4)
        gUnk_02002200[0] = 0xA3;
    if (idx == 5)
        gUnk_02002200[0] = 0xA6;
    if (idx == 6)
        gUnk_02002200[0] = 0x7D;
    if (idx == 8)
        gUnk_02002200[0] = 0x7D;
    if (idx == 9)
        gUnk_02002200[0] = 0x7D;
    if (idx == 10)
        gUnk_02002200[0] = 0x5E;
    if (idx == 11)
        gUnk_02002200[0] = 0x7D;
    sub_08003BFC(0, 0, gUnk_02002208, (u32 *)0x03000000, gUnk_0200221C, gUnk_02022DE4);
    sub_08003BFC(0, 0, gUnk_0200BC54, (u32 *)0x03000800, gUnk_02002210, gUnk_0200BC34);
    sub_08003D90();
    sub_08004260(0, 0);
    sub_08008F1C(idx);
    sub_08005560();
    sub_0800557C();
    gUnk_020253D4 = 0;
}
