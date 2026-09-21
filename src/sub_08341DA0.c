#include "global.h"

struct Unk08341DA0 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
    s16 unk3C;
    u8 pad3E[0xA4 - 0x3E];
    s32 unkA4[4];
    s32 unkB4[4];
    s32 unkC4[4];
    s32 unkD4[4];
};

extern s16 gUnk_0200C3E8[]; /* 0x0200C3E8 */
extern s32 gUnk_020277B4[]; /* 0x020277B4 */
extern volatile s32 gUnk_020277C4[]; /* 0x020277C4 */

void sub_08341DA0(struct Unk08341DA0 *obj)
{
    s32 sin;
    s32 cos;
    s32 i;
    u32 idx;
    s32 a;
    s32 b;

    idx = obj->unk34 >> 8;
    sin = gUnk_0200C3E8[idx];
    cos = gUnk_0200C3E8[idx + 0x40];
    for (i = 0; i != 4; i++) {
        a = gUnk_020277B4[i];
        b = gUnk_020277C4[i];
        obj->unkA4[i] = (cos * a - sin * b) >> 8;
        obj->unkB4[i] = (sin * a + cos * b) >> 8;
        obj->unkA4[i] += obj->unk0;
        obj->unkB4[i] += obj->unk8;
    }

    idx = (obj->unk34 + obj->unk3C) >> 8 & 0xFF;
    sin = gUnk_0200C3E8[idx];
    cos = gUnk_0200C3E8[idx + 0x40];
    for (i = 0; i != 4; i++) {
        a = gUnk_020277B4[i];
        b = gUnk_020277C4[i];
        obj->unkC4[i] = (cos * a - sin * b) >> 8;
        obj->unkD4[i] = (sin * a + cos * b) >> 8;
        obj->unkC4[i] += obj->unk0 + obj->unkC;
        obj->unkD4[i] += obj->unk8 + obj->unk14;
    }
}
