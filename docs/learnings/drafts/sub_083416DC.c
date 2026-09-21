#include "global.h"

struct Ent083416DC {
    /* +0x00 */ s32 f00;
    /* +0x04 */ u8 pad04[4];
    /* +0x08 */ s32 f08;
    /* +0x0C */ u8 pad0C[0x34 - 0x0C];
    /* +0x34 */ u16 f34;
    /* +0x36 */ u8 pad36[0x7D - 0x36];
    /* +0x7D */ u8 f7D;
    /* +0x7E */ u8 pad7E[0x162 - 0x7E];
    /* +0x162 */ u8 f162;
    /* +0x163 */ u8 pad163[0x172 - 0x163];
    /* +0x172 */ u8 f172;
};

struct Slot083416DC {
    /* +0x00 */ u32 f00;
    /* +0x04 */ u32 f04;
    /* +0x08 */ u32 f08;
    /* +0x0C */ u32 f0C;
    /* +0x10 */ u32 f10;
};

extern u32 *gUnk_02026E14[];
extern u32 *gUnk_02026E18[];
extern u32 *gUnk_02026E1C[];
extern u8 gUnk_020390EC;
extern s32 gUnk_020390AC;
extern u32 gUnk_020243E8[];
extern u32 gUnk_0201B590[];
extern u32 *gUnk_0202772C[];
extern u32 *gUnk_0202773C[];

u32 sub_08341644(s32 x, s32 y, s32 *out);
struct Slot083416DC *sub_0833FC48(void *a);
struct Slot083416DC *sub_0833FBB0(void *a);
struct Slot083416DC *sub_0833FC94(void *a);
struct Slot083416DC *sub_0833FBFC(void *a);
u32 sub_0833FD78(u32 a);
u32 sub_0833D6D8(u32 a, u32 b, u16 c);
s32 sub_08344C50(s32 a, s32 b);

void sub_083416DC(struct Ent083416DC *a, u8 b)
{
    s32 out[2];
    u16 y0;
    s32 idx;
    u8 flip;
    u32 bits;
    struct Slot083416DC *slot;
    u32 a2;
    u32 b2;
    u32 *ptr;

    if ((u8)sub_08341644(a->f00, a->f08, out) == 0)
        return;
    y0 = out[1];
    out[0] -= 0x18;
    out[1] -= 0x10;
    if (a->f7D != 0 && gUnk_020390EC != 0 && (gUnk_020390AC & 8) != 0)
        return;
    idx = (a->f34 + 0x200) >> 10;
    idx += 0x28;
    idx &= 0x3F;
    flip = idx & 0x20;
    idx &= 0x1F;
    if (flip != 0)
        idx = 0x20 - idx;
    bits = (sub_0833FD78(gUnk_02026E1C[a->f162]) << 24) >> 12;
    if (a->f172 != 0)
        bits |= 0x800;
    else
        bits |= 0x400;
    if (flip == 0) {
        slot = sub_0833FC48(gUnk_02026E14[a->f162][idx]);
        if (slot != 0) {
            a2 = out[1] & 0xFF;
            a2 |= (out[0] & 0x1FF) << 16;
            a2 |= 0x80008000;
            b2 = slot->f10 | bits;
            sub_0833D6D8(a2, b2, y0 + 0x40);
        }
        slot = sub_0833FBB0(gUnk_02026E18[a->f162][idx]);
        if (slot != 0) {
            a2 = out[1] & 0xFF;
            a2 |= ((out[0] + 0x10) & 0x1FF) << 16;
            a2 |= 0x80000000;
            b2 = slot->f10 | bits;
            sub_0833D6D8(a2, b2, y0 + 0x40);
        }
    } else {
        slot = sub_0833FBB0(gUnk_02026E18[a->f162][idx]);
        if (slot != 0) {
            a2 = out[1] & 0xFF;
            a2 |= (out[0] & 0x1FF) << 16;
            a2 |= 0x80000000;
            b2 = slot->f10 | bits;
            a2 |= 0x4000000;
            sub_0833D6D8(a2, b2, y0 + 0x40);
        }
        slot = sub_0833FC48(gUnk_02026E14[a->f162][idx]);
        if (slot != 0) {
            a2 = out[1] & 0xFF;
            a2 |= ((out[0] + 0x20) & 0x1FF) << 16;
            a2 |= 0x80008000;
            b2 = slot->f10 | bits;
            a2 |= 0x4000000;
            sub_0833D6D8(a2, b2, y0 + 0x40);
        }
    }
    if (gUnk_020390EC != 0) {
        ptr = gUnk_0202772C[b];
        ptr += sub_08344C50(gUnk_020390AC >> 1, 7);
        out[1] -= 0xC;
        out[0] += 0x10;
        a2 = out[1] & 0xFF;
        a2 |= (out[0] & 0x1FF) << 16;
        a2 |= 0x10000000;
        slot = sub_0833FC94(*ptr);
        if (slot == 0)
            return;
        b2 = slot->f10;
        b2 |= 0x400;
        b2 |= (sub_0833FD78(gUnk_020243E8) << 24) >> 12;
        sub_0833D6D8(a2, b2, y0 + 0x40);
    } else {
        ptr = gUnk_0202773C[a->f162];
        out[1] -= 8;
        out[0] += 0x10;
        a2 = out[1] & 0xFF;
        a2 |= (out[0] & 0x1FF) << 16;
        a2 |= 0x8000;
        slot = sub_0833FBFC(*ptr);
        if (slot == 0)
            return;
        b2 = slot->f10;
        b2 |= 0x400;
        b2 |= (sub_0833FD78(gUnk_0201B590) << 24) >> 12;
        sub_0833D6D8(a2, b2, y0 + 0x40);
    }
}
