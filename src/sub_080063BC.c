#include "global.h"
#include "data.h"

void DrawText(u8 *p, u32 a1, u32 a2, u8 a3)
{
    u16 *out = (u16 *)*(u32 *)&gUnk_08364B08;
    u16 color;
    u32 c;

    out += a2 * 0x20 + a1;
    color = 0xE0 << 8;
    if (a3 != 0)
        color = 0xF0 << 8;
    while ((c = *p++) != 0)
    {
        u16 idx = gUnk_08332DC8[(u8)(c - 0x20)];
        *out++ = color | gUnk_08333208[idx];
    }
}
