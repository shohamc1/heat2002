#include "global.h"
#include "functions.h"

extern u16 gUnk_0829FC80[][4];
extern u16 gUnk_0600F800[];

void sub_08010680(u16 *data)
{
    u16 *vram;
    u32 i;
    u32 j;
    u16 idx;
    u16 *entry;

    vram = gUnk_0600F800;
    i = 0;
    for (; i != 0xA; i++) {
        j = 0;
        for (; j != 0xF; j++) {
            idx = *data;
            data++;
            entry = gUnk_0829FC80[idx];
            vram[0] = *entry++;
            vram[1] = *entry++;
            vram[0x20] = entry[0];
            vram[0x21] = entry[1];
            vram += 2;
        }
        vram += 0x22;
    }
}
