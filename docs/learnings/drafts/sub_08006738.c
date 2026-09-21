#include "global.h"

extern u16 gUnk_08332DC8[];
extern u16 gUnk_08333208[];
extern u8 *gUnk_0836533C;
extern u8 *gUnk_08365340;
extern u8 *gUnk_08365344;

void sub_08006738(u8 *str)
{
    vu16 *vp;
    u8 *s, *s2, *s4;
    u8 c, c4;
    u16 flags;
    u16 *tbl1, *t60, *t80, *tile;
    u8 i, j;

    s = str;
    vp = (vu16 *)0x06008040;
    flags = 0xF000;
    i = 0;
    c = *s++;
    if (c != 0) {
        tbl1 = gUnk_08332DC8;
        do {
            tile = &tbl1[((((((u32)(c - 0x20) << 24) >> 29) << 22) + 0x600000) >> 16) + ((((u32)(c - 0x20) << 24) & 0x1F000000) >> 24)];
            *vp = flags | gUnk_08333208[tile[0]];
            vp[0x20] = flags | gUnk_08333208[tile[0x20]];
            vp++;
            i++;
            c = *s++;
        } while (c != 0);
    }
    s2 = gUnk_0836533C;
    c = *s2++;
    if (c != 0) {
        tbl1 = gUnk_08332DC8;
        do {
            tile = &tbl1[((((((u32)(c - 0x20) << 24) >> 29) << 22) + 0x600000) >> 16) + ((((u32)(c - 0x20) << 24) & 0x1F000000) >> 24)];
            *vp = flags | gUnk_08333208[tile[0]];
            vp[0x20] = flags | gUnk_08333208[tile[0x20]];
            vp++;
            i++;
            c = *s2++;
        } while (c != 0);
    }
    tbl1 = gUnk_08332DC8;
    while (i <= 0x1F) {
        c = *gUnk_08365340;
        tile = &tbl1[((((((u32)(c - 0x20) << 24) >> 29) << 22) + 0x600000) >> 16) + ((((u32)(c - 0x20) << 24) & 0x1F000000) >> 24)];
        *vp = flags | gUnk_08333208[tile[0]];
        vp[0x20] = flags | gUnk_08333208[tile[0x20]];
        i++;
        vp++;
    }
    s4 = gUnk_08365344;
    vp = (vu16 *)0x06008440;
    c4 = *s4++;
    if (c4 != 0) {
        tbl1 = gUnk_08332DC8;
        t60 = &tbl1[0x60];
        t80 = &tbl1[0x80];
        do {
            *vp = flags | gUnk_08333208[t60[0]];
            vp[0x20] = flags | gUnk_08333208[t80[0]];
            vp[0x40] = flags | gUnk_08333208[t80[0]];
            vp[0x60] = flags | gUnk_08333208[t80[0]];
            vp++;
            c4 = *s4++;
        } while (c4 != 0);
    }
    vp = (vu16 *)0x06008000;
    j = 0;
    do {
        *vp++ = flags | gUnk_08333208[t60[0x20]];
        j++;
    } while (j != 0x20);
}
