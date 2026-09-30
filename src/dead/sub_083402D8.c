#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_BlankRow12[];
extern u8 gModule_BlankRow24[];


void sub_083402D8(void)
{
    u32 p;

    ModuleDrawText(gModule_BlankRow12, 0x0B, 0x07);
    p = (u32)gModule_BlankRow24;
    ModuleDrawText(p, 0x06, 0x09);
    ModuleDrawText(p, 0x06, 0x0A);
    p = (u32)gModule_BlankRow28;
    ModuleDrawText(p, 0x06, 0x0B);
    ModuleDrawText(p, 0x0A, 0x0C);
}

extern u8 gModule_PitMenu[];
extern u8 gModule_BlankRow20_2[];
extern const u8 *const gModule_PitMenuRowLabelTexts[];
extern const u8 *const gModule_PitMenuTireOptionTexts[];
extern const u8 *const gModule_PitMenuFuelOptionTexts[];
extern u32 gModule_PitMenuRepairOptionTexts[];
extern u8 gUnk_0203D4F0;
extern u8 gUnk_0203DDE0[];


void sub_08340324(u8 a)
{
    ModuleDrawText(gModule_PitMenu, 0x0B, 0x07);
    if (a != 0 || (gUnk_0203D4F0 & 4) == 0)
    {
        ModuleDrawText(gModule_PitMenuRowLabelTexts[0], 0x06, 0x09);
        ModuleDrawText(gModule_PitMenuTireOptionTexts[gUnk_0203DDE0[0]], 0x0D, 0x09);
    }
    else
        ModuleDrawText(gModule_BlankRow20_2, 0x06, 0x09);
    if (a != 1 || (gUnk_0203D4F0 & 4) == 0)
    {
        ModuleDrawText(gModule_PitMenuRowLabelTexts[1], 0x06, 0x0A);
        ModuleDrawText(gModule_PitMenuFuelOptionTexts[gUnk_0203DDE0[1]], 0x0D, 0x0A);
    }
    else
        ModuleDrawText(gModule_BlankRow28, 0x06, 0x0A);
    if (a != 2 || (gUnk_0203D4F0 & 4) == 0)
    {
        ModuleDrawText(gModule_PitMenuRowLabelTexts[2], 0x06, 0x0B);
        ModuleDrawText(gModule_PitMenuRepairOptionTexts[gUnk_0203DDE0[2]], 0x0D, 0x0B);
    }
    else
        ModuleDrawText(gModule_BlankRow28, 0x06, 0x0B);
    if (a != 3 || (gUnk_0203D4F0 & 4) == 0)
        ModuleDrawText(gModule_PitMenuRowLabelTexts[3], 0x0D, 0x0C);
    else
        ModuleDrawText(gModule_BlankRow20_2, 0x0A, 0x0C);
    gUnk_0203D4F0++;
}

void sub_08340470(void)
{
}

void sub_08340474(void)
{
}

void sub_08340478(void)
{
}

void sub_0834047C(u16 *a, u16 *b)
{
    u32 i;
    for (i = 0; (u8)i != 5; i = (u8)(i + 1))
    {
        u16 *d = (u16 *)((u32)i * 2 + (u32)b);
        *d = sub_08344BB8(0x80 << 9, a[i]);
    }
}

extern u16 gUnk_0203D510[];
extern u16 gUnk_0203DD40[];
extern u16 gUnk_0203DD20[];
extern u16 gUnk_020270C6[];
extern u16 gUnk_020270D0[];
void sub_083404A8(void)
{
    u16 *dst;
    u16 *src;
    u8 i = 0;
    do {
        gUnk_0203D510[i] = gUnk_020270C6[i];
        gUnk_0203DD40[i] = gUnk_020270D0[i];
        i++;
    } while (i != 5);
    dst = gUnk_0203DD40;
    src = gUnk_0203DD20;
    sub_0834047C(dst, src);
}

void sub_08340504(u32 a)
{
    *(vu8 *)&gModule_GameMode[0]; /* deliberate volatile read: keeps the load in the output */
    *(u32 *)(a + 0xE4) = (u32)gUnk_0202713E;
    *(u32 *)(a + 0xE8) = (u32)gUnk_0202714A;
    *(u32 *)(a + 0xEC) = (u32)gUnk_02027154;
}
