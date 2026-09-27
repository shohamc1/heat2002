#include "global.h"
#include "variables.h"
#include "car.h"

extern u8 gUnk_0203E0F8;

void sub_0833D9E8(void);
void sub_08340210(u8 a);
void sub_08340EE0(void);
void sub_08341288(u8 a, u32 b, u32 c, u32 d, u32 e, u32 f);

void sub_0834108C(u32 a1)
{
    u32 v;
    u32 *q;
    u32 *ep;
    u32 i;
    u32 off;

    sub_0833D9E8();
    sub_08340210((u8)a1);
    gUnk_0203DD10 = 0;
    v = gUnk_0203E0F8;
    sub_08340EE0();
    if (gModule_GameMode[0] == 0) {
        q = (u32 *)gUnk_02039200;
        ep = (u32 *)gUnk_0203D4A0;
        for (i = 0; i != 5; i++) {
            sub_08341288((u8)i, *q, ep[0] << 16, ep[1] << 16, ep[2] << 8,
                         ((((s32)(*q++ - (u32)gModule_Cars)) * (s32)0xC28F5C29) >> 4) + v);
            ep += 3;
        }
    } else {
        ep = (u32 *)gUnk_0203D4A0;
        i = 0;
        off = 0;
        for (; i != 5; i++) {
            sub_08341288((u8)i, off + (u32)gModule_Cars, ep[0] << 16, ep[1] << 16, ep[2] << 8, i + v);
            ep += 3;
            off += 0x190;
        }
    }
}
