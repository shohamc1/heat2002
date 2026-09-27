#include "global.h"
#include "functions.h"
#include "car.h"
#include "variables.h"

extern u32 gUnk_083FF68C[];
extern u8 gUnk_08331360[];
extern u8 gUnk_0806C8B4[];
extern u8 gUnk_0806C8BC[];
extern u8 gUnk_0806C8C4[];
extern u8 gUnk_0806C8CC[];
extern u8 gUnk_0806C8D4[];
extern u8 gUnk_0806C8DC[];

u8 GetTrackTileType(s32 x, s32 y);
u32 WorldToScreen(s32 x, s32 y, s32 *out);
void sub_08007A7C(s32 a1, s32 a2, u32 a3, u32 a4, u32 a5);
void sub_08017594(u8 *a, u8 *b, s32 c, s32 d);

void sub_08008160(void)
{
    s32 out[2];
    u8 buf[0x28];
    s32 x;
    s32 y;
    s32 cx;
    u8 v;
    u8 w;
    u32 pal;
    s32 t;
    s32 u;
    u32 flag2;
    u32 flag1;
    u32 flag3;
    s32 i;
    s32 cy;
    s32 j;

    x = ((s32 *)gCars)[0];
    y = ((s32 *)gCars)[2];
    cx = x >> 19;
    cy = y >> 19;
    cy += 2;
    cx += 1;
    flag1 = 0;
    flag2 = 0;
    flag3 = 0;
    for (j = cy - 3; j != cy + 4; j = j + 1) {
        for (i = cx - 3; i != cx + 4; i++) {
            v = GetTrackTileType(i, j);
            w = v;
            if ((WorldToScreen(i << 19, j << 19, out) << 0x18) != 0)
            {
                t = out[0] - 0x78;
                out[0] = t + gCamera[6];
                u = out[1] - 0x50;
                out[1] = u + gCamera[7];
                out[0] += 0xA;
                out[1] += 8;
                pal = (u32)gUnk_08331360;
                sub_08007A7C(out[0] << 16, out[1] << 16, gUnk_083FF68C[v], pal, 0);
                if (i > cx - 2 && i < cx + 2 && j > cy - 2 && j < cy + 2)
                {
                    if (v & 1)
                        flag3 = 1;
                    if ((u8)(v - 2) < 2)
                        flag2 = 1;
                    if ((u8)(w - 4) < 2)
                        flag1 = 1;
                }
            }
        }
    }
    if (flag1 != 0)
        DrawSpriteText(gUnk_0806C8B4, 0x64, 0x64);
    if (flag2 != 0)
        DrawSpriteText(gUnk_0806C8BC, 0x64, 0x64);
    if (flag1 == 0 && flag2 == 0)
        DrawSpriteText(gUnk_0806C8C4, 0x64, 0x64);
    if (flag3 != 0)
        DrawSpriteText(gUnk_0806C8CC, 0x64, 0x6E);
    else
        DrawSpriteText(gUnk_0806C8D4, 0x64, 0x6E);
    sub_08017594(buf, gUnk_0806C8DC, ((s32 *)gCars)[0] >> 19, ((s32 *)gCars)[2] >> 19);
    DrawSpriteText(buf, 0x64, 0x78);
}
