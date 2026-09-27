#include "global.h"

struct Unk08340964 {
    u8 pad0[0x8C];
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    u8 pad9C[0x140 - 0x9C];
    s32 unk140;
    s32 unk144;
    s32 unk148;
    u8 pad14C[0x180 - 0x14C];
    u8 unk180;
};

extern s16 gUnk_0200C3E8[]; /* 0x0200C3E8 */
extern s32 gUnk_0203DE10; /* 0x0203DE10 */
extern s32 gUnk_0203D51C; /* 0x0203D51C */
extern s32 gUnk_0203D4F4; /* 0x0203D4F4 */
extern u8 gUnk_0203E0E0; /* 0x0203E0E0 */
extern s32 gUnk_0203D4E4; /* 0x0203D4E4 */
extern u8 gUnk_0203DD38; /* 0x0203DD38 */
extern u8 gUnk_020390EC; /* 0x020390EC */
extern u8 gUnk_0203E1B0; /* 0x0203E1B0 */
extern u8 gUnk_0203E120[]; /* 0x0203E120 */
extern u8 gUnk_020390F0[]; /* 0x020390F0 */
extern u8 gUnk_020391F0; /* 0x020391F0 */
extern s32 gUnk_0203DDF4; /* 0x0203DDF4 */
extern s32 gUnk_0203DD2C; /* 0x0203DD2C */

void sub_08342ED0(u8 a, u8 b);
void sub_0833A8C8(u16 idx);

void sub_08340964(u8 which, struct Unk08340964 *obj)
{
    s32 cos;
    s32 sin;
    s32 prod;
    s32 dist;
    s32 idx;
    register s32 m asm("r2");
    register s32 mm asm("r0");
    s32 ti;
    s32 t;
    s32 *pa;

    cos = gUnk_0200C3E8[((gUnk_0203DE10 + 0x40) & 0xFF) + 0x40];
    sin = gUnk_0200C3E8[(gUnk_0203DE10 + 0x40) & 0xFF];
    prod = cos * gUnk_0203D51C + sin * gUnk_0203D4F4;
    dist = prod >> 8;
    if (which != 0) {
        if (gUnk_0203E0E0 != 0) {
            obj->unk8C += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
            obj->unk90 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
        }
        if (dist < -gUnk_0203D4E4) {
            dist = -gUnk_0203D4E4 / 2;
            sub_08342ED0(gUnk_0203DD38, 2);
            if (gUnk_020390EC == 0) {
                if (gUnk_0203DD38 == 0)
                    goto e2check;
                goto tail;
            }
            if (gUnk_0203DD38 != gUnk_0203E1B0)
                goto tail;
        } else if (dist > gUnk_0203D4E4) {
            dist = gUnk_0203D4E4 / 2;
            sub_08342ED0(gUnk_0203DD38, 3);
            if (gUnk_020390EC == 0) {
                if (gUnk_0203DD38 == 0)
                    goto e2check;
                goto tail;
            }
            if (gUnk_0203DD38 != gUnk_0203E1B0)
                goto tail;
        } else {
            goto tail;
        }
e2check:
        if (gUnk_0203E120[3] != 0 && gUnk_020390F0[0] == 0 && gUnk_020391F0 == 0)
            sub_0833A8C8(0xB);
    } else {
        if (gUnk_0203E0E0 != 0) {
            obj->unk94 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
            obj->unk98 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
        }
    }
tail:
    m = dist * gUnk_0203DDF4;
    m >>= 8;
    m = -m;
    pa = &obj->unk140;
    *pa += (m * cos) >> 8;
    pa = &obj->unk144;
    *pa += (sin * m) >> 8;
    ti = gUnk_0203DE10;
    ti += 0x40;
    ti -= gUnk_0203DD2C;
    ti &= 0xFF;
    mm = gUnk_0200C3E8[ti] * m;
    m = mm >> 8;
    m <<= 7;
    t = m;
    if (m < 0)
        t = m + 0x7FFF;
    m = t >> 15;
    if (obj->unk180 != 0) {
        obj->unk180--;
        obj->unk148 += t >> 16;
    } else {
        obj->unk148 += m;
    }
}
