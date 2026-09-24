#include "global.h"

extern u16 *gUnk_08364B08;
extern u16 gUnk_08332DC8[];
extern u16 gUnk_08333208[];

void DrawTextCenteredHighlight(u8 *p, u32 a1, u8 a2)
{
    u8 *s = p;
    u8 len = 0;
    u32 c = *p;
    u16 **v = &gUnk_08364B08;
    u8 pad;
    u16 *out;
    u16 color;

    while (c != 0)
    {
        s++;
        len++;
        c = *s;
    }
    pad = (u8)((0x1E - len) / 2);
    out = *v;
    out += a1 * 0x20 + pad;
    color = 0xE0 << 8;
    if (a2 != 0)
        color = 0xF0 << 8;
    while ((c = *p++) != 0)
    {
        u16 idx = gUnk_08332DC8[(u8)(c - 0x20)];
        *out++ = color | gUnk_08333208[idx];
    }
}
