#include "global.h"
#include "variables.h"

extern u16 gUnk_0201F550[];
extern u8 gUnk_0201FB54[];
extern u8 gUnk_0201F390[];

struct SoundSlot0833F *ModuleRequestObjTiles1(void *a);
u32 ModuleRequestObjPalette(u32 a);
void ModuleAddOamEntry(u32 a, u32 b);

void sub_08343148(const u8 *a, u32 b, u32 c)
{
    u16 t1;
    u16 t2;
    u8 idx;
    const u8 *p;
    u32 q;
    u32 m;
    u32 v;
    u32 x;
    struct SoundSlot0833F *r5;

    q = b;
    p = a;
    idx = *p;
    p++;
    if (idx != 0)
    {
        m = 0xFF;
        m = m & c;
        do
        {
            if (idx != 0x20)
            {
                t1 = *(u16 *)((idx << 1) + (u32)gUnk_0201F550);
                t2 = gModule_TextGlyphTileIndices[t1];
                r5 = ModuleRequestObjTiles1(&gUnk_0201FB54[t2 << 5]);
                if (r5 != 0)
                {
                    v = (q & 0x1FF) << 16;
                    v = v | m;
                    x = (ModuleRequestObjPalette((u32)gUnk_0201F390) << 24) >> 12;
                    ModuleAddOamEntry(v, *(u32 *)((u32)r5 + 0x10) | x);
                }
            }
            q += 8;
            idx = *p;
            p++;
        } while (idx != 0);
    }
}
