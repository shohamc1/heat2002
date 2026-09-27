#include "global.h"
#include "data.h"

extern u8 *gUnk_0836533C;
extern u8 *gUnk_08365344;

void sub_08006738(u8 *str)
{
    vu16 *vp;
    u16 pal;
    u8 i;
    u8 j;
    u8 c;
    u8 ch;
    u16 base;
    u16 *tile;

    vp = (vu16 *)0x06008040;
    pal = 0xF000;
    i = 0;
    while ((c = *str++) != 0) {
        ch = c - 0x20;
        base = (ch >> 5) * 64 + 0x60;
        tile = &gUnk_08332DC8[base + (ch & 0x1F)];
        vp[0] = pal | gUnk_08333208[tile[0]];
        vp[0x20] = pal | gUnk_08333208[tile[0x20]];
        vp++;
        i++;
    }
    str = gUnk_0836533C;
    while ((c = *str++) != 0) {
        ch = c - 0x20;
        base = (ch >> 5) * 64 + 0x60;
        tile = &gUnk_08332DC8[base + (ch & 0x1F)];
        vp[0] = pal | gUnk_08333208[tile[0]];
        vp[0x20] = pal | gUnk_08333208[tile[0x20]];
        vp++;
        i++;
    }
    while (i < 32) {
        c = *gUnk_08365340;
        ch = c - 0x20;
        base = (ch >> 5) * 64 + 0x60;
        tile = &gUnk_08332DC8[base + (ch & 0x1F)];
        vp[0] = pal | gUnk_08333208[tile[0]];
        vp[0x20] = pal | gUnk_08333208[tile[0x20]];
        i++;
        vp++;
    }
    str = gUnk_08365344;
    vp = (vu16 *)0x06008440;
    while ((c = *str++) != 0) {
        /* The space glyph, set inside the loop: the index stays a
           register sum off the table base, as in the ROM. */
        ch = ' ' - 0x20;
        base = (ch >> 5) * 64 + 0x60;
        tile = &gUnk_08332DC8[base + (ch & 0x1F)];
        vp[0] = pal | gUnk_08333208[tile[0]];
        vp[0x20] = pal | gUnk_08333208[tile[0x20]];
        vp[0x40] = pal | gUnk_08333208[tile[0x20]];
        vp[0x60] = pal | gUnk_08333208[tile[0x20]];
        vp++;
    }
    vp = (vu16 *)0x06008000;
    for (j = 0; j != 32; j++) {
        *vp = pal | gUnk_08333208[tile[0x20]];
        vp++;
    }
}
