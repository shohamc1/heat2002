#include "global.h"
#include "functions.h"
#include "data.h"

extern u8 *gUnk_083FE9EC[];
extern u8 gUnk_0202EF60[];
extern u8 gUnk_0829F4EC[];
extern u8 gUnk_0829F4F4[];
extern u8 gUnk_0829F4FC[];
extern u8 *gUnk_083FEA2C[];

void sub_08014708(u8 a, u8 b)
{
    u8 y;
    u8 i;
    u8 base;
    s8 sv;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(a + 0xAE);
    ((void (*)(void))sub_080065A8)();
    base = (u8)(a * 4);
    y = 3;
    i = 0;
    do {
        DrawText(gUnk_083FE9EC[base + i], 0, y, i == (b & 3));
        if (gUnk_0202EF60[base + i] == 1) {
            u8 *s = gUnk_0829F4EC;
            DrawText(s, 0x16, y, i == (b & 3));
        }
        if (gUnk_0202EF60[base + i] == 2) {
            u8 *s = gUnk_0829F4EC;
            DrawText(s, 0x16, y, i == (b & 3));
        }
        sv = ((s8 *)gUnk_0202EF60)[base + i];
        if (sv == 3) {
            u8 *s = gUnk_0829F4EC;
            DrawText(s, 0x16, y, i == (sv & b));
        }
        if (((s8 *)gUnk_0202EF60)[base + i] == -1) {
            u8 *s = gUnk_0829F4F4;
            DrawText(s, 0x16, y, i == (b & 3));
        }
        if ((s8)gUnk_0202EF60[base + i] == 0) {
            u8 *s = gUnk_0829F4FC;
            DrawText(s, 0x16, y, i == (b & 3));
        }
        y++;
        i++;
    } while (i != 4);
    y = 8;
    base = (u8)(b * 5) * 2;
    i = base;
    while (i != base + 10) {
        DrawText(gUnk_083FEA2C[i], 0, y, 1);
        y++;
        i++;
    }
}
