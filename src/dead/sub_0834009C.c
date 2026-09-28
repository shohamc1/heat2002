#include "global.h"
#include "car.h"
#include "variables.h"

u32 sub_0834009C(u32 a0, u32 a1, u32 count)
{
    u32 p;
    u8 i;

    i = 0;
    p = (u32)gModule_Cars;
    while (i != 0x05) {
        if (*(u8 *)(p + 0x175) != 0)
            count = (u8)(count + 1);
        p += 0x190;
        i++;
        p += 0x190;
    }
    return count;
}

u32 *ModuleRequestObjTiles4(u32 p);
s32 ModuleRequestObjPalette(u32 a);
u32 ModuleAddOamEntry(u32 a, u32 b);

void sub_083400D4(s32 a1, s32 a2, u32 a3, u32 a4, u8 a5)
{
    u32 dx;
    s32 dy;
    u32 *q;
    u32 attr;
    u32 t;
    u32 v;

    dx = (a1 >> 16) - gModule_Camera[6];
    dy = (a2 >> 16) - gModule_Camera[7];
    dy += 0x40;
    dx += 0x70;
    if (dx + 0x10 <= 0x100 && dy <= 0xA0 && dy >= -0x10) {
        q = ModuleRequestObjTiles4(a3);
        if (q != 0) {
            v = ModuleRequestObjPalette(a4) << 24;
            attr = (dy & 0xFF) | ((dx & 0x1FF) << 16) | 0x40000000;
            v = v >> 12;
            v = v | 0x800;
            t = *(u32 *)((u32)q + 0x10) | v;
            if (a5 != 0)
                attr |= 0x10000000;
            ModuleAddOamEntry(attr, t);
        }
    }
}

u32 sub_08340168(u32 ptr)
{
    u32 *p = gUnk_02039200;
    u8 i;

    for (i = 0; i != 0x5; i++, p++) {
        if (*p == ptr)
            return i;
    }
    return 0x5;
}

extern u8 gUnk_02026DF4[];

void sub_083415B0(u8 idx);
u32 sub_08340168(u32 ptr);

void sub_0834018C(struct Car *a1, u32 a2)
{
    u8 i;
    u8 flag;
    s32 t;

    sub_083415B0((u8)a2);
    t = sub_08340168((u32)a1);
    a1->points = a1->points + gUnk_02026DF4[(u8)t];
    if (a1->lapsLed != 0)
        a1->points += 5;
    flag = 1;
    for (i = 0; i != 5; i++) {
        if (a1 == &gModule_Cars[i])
            continue;
        if (gModule_Cars[i].lapsLed <= a1->lapsLed)
            continue;
        flag = 0;
    }
    if (flag != 0)
        a1->points += 10;
}
