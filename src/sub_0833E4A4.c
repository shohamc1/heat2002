#include "global.h"

extern u8 gUnk_0203B700[];
extern s32 gUnk_0203B6CC;
extern u32 gUnk_020251B8[];
extern s32 gUnk_0203B84C;

extern void sub_0833E36C(u16 *a, u32 b);
extern void sub_0833E3C8(u16 *a, s32 b);
extern s32 sub_08344BB8(s32 a, s32 b);
extern s32 sub_08344C50(s32 a, s32 b);

void sub_0833E4A4(void)
{
    u8 *d;
    s32 v;
    s32 w;

    d = gUnk_0203B700;
    v = gUnk_0203B6CC;
    d[1] = sub_08344C50(v, 10);
    d[0] = sub_08344BB8(v, 10);
    sub_0833E36C((u16 *)(gUnk_020251B8[0] + 0x82), d[0]);
    sub_0833E36C((u16 *)(gUnk_020251B8[0] + 0x86), d[1]);
    w = gUnk_0203B84C;
    d[1] = sub_08344C50(sub_08344BB8(w, 10), 10);
    d[0] = sub_08344BB8(w, 100);
    sub_0833E3C8((u16 *)(gUnk_020251B8[0] + 0xCA), 10);
    sub_0833E3C8((u16 *)(gUnk_020251B8[0] + 0xCC), d[0]);
    sub_0833E3C8((u16 *)(gUnk_020251B8[0] + 0xCE), d[1]);
}
