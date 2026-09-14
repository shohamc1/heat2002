#include "global.h"

struct Unk080087F4 {
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

extern s16 gUnk_0801CD08[]; /* 0x0801CD08 */
extern s32 gUnk_0202CBF0; /* 0x0202CBF0 */
extern s32 gUnk_0202A54C; /* 0x0202A54C */
extern s32 gUnk_0202A528; /* 0x0202A528 */
extern u8 gUnk_0202EEB0; /* 0x0202EEB0 */
extern s32 gUnk_0202A518; /* 0x0202A518 */
extern u8 gUnk_0202CB18; /* 0x0202CB18 */
extern u8 gUnk_020020DC; /* 0x020020DC */
extern u8 gUnk_0202EF90; /* 0x0202EF90 */
extern u8 gUnk_0202EF00[]; /* 0x0202EF00 */
extern u8 gUnk_020020E0; /* 0x020020E0 */
extern u8 gUnk_020021E0; /* 0x020021E0 */
extern s32 gUnk_0202CBD4; /* 0x0202CBD4 */
extern volatile s32 gUnk_0202CB0C; /* 0x0202CB0C */

void sub_0800B764(u8 a, u8 b);
void sub_08001208(u16 idx);

void sub_080087F4(u8 which, struct Unk080087F4 *obj)
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

    cos = gUnk_0801CD08[((gUnk_0202CBF0 + 0x40) & 0xFF) + 0x40];
    sin = gUnk_0801CD08[(gUnk_0202CBF0 + 0x40) & 0xFF];
    prod = cos * gUnk_0202A54C + sin * gUnk_0202A528;
    dist = prod >> 8;
    if (which != 0) {
        if (gUnk_0202EEB0 != 0) {
            obj->unk8C += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
            obj->unk90 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
        }
        if (dist < -gUnk_0202A518) {
            dist = -gUnk_0202A518 / 2;
            sub_0800B764(gUnk_0202CB18, 2);
            if (gUnk_020020DC == 0) {
                if (gUnk_0202CB18 == 0)
                    goto e2check;
                goto tail;
            }
            if (gUnk_0202CB18 != gUnk_0202EF90)
                goto tail;
        } else if (dist > gUnk_0202A518) {
            dist = gUnk_0202A518 / 2;
            sub_0800B764(gUnk_0202CB18, 3);
            if (gUnk_020020DC == 0) {
                if (gUnk_0202CB18 == 0)
                    goto e2check;
                goto tail;
            }
            if (gUnk_0202CB18 != gUnk_0202EF90)
                goto tail;
        } else {
            goto tail;
        }
e2check:
        if (gUnk_0202EF00[3] != 0 && gUnk_020020E0 == 0 && gUnk_020021E0 == 0)
            sub_08001208(0xB);
    } else {
        if (gUnk_0202EEB0 != 0) {
            obj->unk94 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
            obj->unk98 += ((prod >> 17) < 0 ? -(prod >> 17) : (prod >> 17));
        }
    }
tail:
    m = dist * gUnk_0202CBD4;
    m >>= 8;
    m = -m;
    pa = &obj->unk140;
    *pa += (m * cos) >> 8;
    pa = &obj->unk144;
    *pa += (sin * m) >> 8;
    ti = gUnk_0202CBF0;
    ti += 0x40;
    ti -= gUnk_0202CB0C;
    ti &= 0xFF;
    mm = gUnk_0801CD08[ti] * m;
    m = mm >> 8;
    m <<= 7;
    t = m;
    if (m < 0)
        t = m + 0x7FFF;
    idx = t >> 15;
    if (obj->unk180 != 0) {
        obj->unk180--;
        obj->unk148 += idx >> 1;
    } else {
        obj->unk148 += idx;
    }
}
