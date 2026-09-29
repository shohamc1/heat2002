#include "global.h"

struct Unk0833F958
{
    u8 field_00;
    u8 field_01;
    u32 field_04;
};
struct OamInit
{
    u32 f0;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u32 f8;
    u32 fC;
    u32 f10;
};
#include "variables.h"
struct Unk0833C270
{
    u8 field_00;
    u8 field_01;
    u32 field_04;
    u32 field_08;
};
extern u8 gUnk_020269C4[];
extern u8 gUnk_020269CC[];
extern u8 gUnk_020269FC[];
extern u8 gUnk_02026A3C[];
extern u8 gUnk_02026A64[];
extern u8 gUnk_02026A84[];

void ModuleInitObjPaletteCacheEntry(struct Unk0833F958 *entry)
{
    entry->field_04 = 0xFFFF;
    entry->field_00 = 0;
    entry->field_01 = 0;
}

void ModuleInitObjTileCache(u32 count, u16 *tiles, struct OamInit *entries)
{
    u32 i;

    for (i = 0; i != count; i++, entries++, tiles++) {
        entries->f8 = 0xFFFF;
        entries->f0 = 0;
        entries->f4 = 0;
        entries->f10 = *tiles;
        entries->fC = (*tiles << 5) + 0x06010000;
        entries->f6 = 0;
    }
}

void ModuleInitGfxCaches(void)
{
    u32 i;
    u32 color;
    struct Unk0833C270 *entry;
    u16 *src;
    void *dest;

    src = gUnk_020269C4;
    dest = gModule_ObjTileCache64;
    ModuleInitObjTileCache(4, src, dest);
    src = gUnk_020269CC;
    dest = gModule_ObjTileCache16;
    ModuleInitObjTileCache(0x18, src, dest);
    src = gUnk_020269FC;
    dest = gModule_ObjTileCache2;
    ModuleInitObjTileCache(0x20, src, dest);
    src = gUnk_02026A3C;
    dest = gModule_ObjTileCache8;
    ModuleInitObjTileCache(0x14, src, dest);
    src = gUnk_02026A64;
    dest = gModule_ObjTileCache4;
    ModuleInitObjTileCache(0x10, src, dest);
    src = gUnk_02026A84;
    dest = gModule_ObjTileCache1;
    ModuleInitObjTileCache(0x20, src, dest);

    i = 0;
    color = 0x05000200;
    entry = (struct Unk0833C270 *)gUnk_0203C270;
    do {
        ModuleInitObjPaletteCacheEntry((struct Unk0833F958 *)entry);
        entry->field_08 = color;
        color += 0x20;
        entry++;
        i++;
    } while (i != 16);
}

void ModuleAgeGfxCaches(void)
{
    u32 *p;
    u32 *a2;
    u32 *a3;
    u32 *a4;
    u32 *a5;
    u32 *a6;
    u32 *q;
    u32 i;

    p = (u32 *)gModule_ObjTileCache64;
    i = 0;
    a2 = (u32 *)gModule_ObjTileCache16;
    a3 = (u32 *)gModule_ObjTileCache2;
    a4 = (u32 *)gModule_ObjTileCache8;
    a5 = (u32 *)gModule_ObjTileCache4;
    a6 = (u32 *)gModule_ObjTileCache1;
    q = gUnk_0203C270;
    for (; i != 4; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a2;
    for (i = 0; i != 0x18; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a3;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a4;
    for (i = 0; i != 0x14; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a5;
    for (i = 0; i != 0x10; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a6;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = q;
    for (i = 0; i != 0x10; i++, p += 3) {
        if (*(u8 *)p == 0)
            *(u32 *)(p + 1) = 0xFFFF;
        else
            (*(u8 *)p)--;
    }
}
