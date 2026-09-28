#include "global.h"
#include "variables.h"
#include "functions.h"

u16 sub_0833DAD8(void)
{
    u16 keys;
    u16 i;
    u8 count;
    u16 *newp;
    u16 *oldp;
    u16 *base;
    u32 j;

    keys = 0;
    i = 0;
    count = gModule_NumLinkPlayers[0];
    newp = &gUnk_0203B6FC;
    oldp = &gUnk_0203B848;
    if (keys != count) {
        base = gUnk_020390B0;
        j = count;
        do {
            keys |= base[i];
            i++;
        } while (i != j);
    }
    *newp = keys & ~*oldp;
    *oldp = keys;
    return *newp;
}

extern u8 gUnk_0203B6F4;           /* 0x02025248 */
extern u8 gUnk_0203B82C;           /* 0x0202539C */


u8 sub_0833DB24(void)
{
    u8 unused[0x200];
    u16 v;
    u32 w;
    gUnk_0203B6F4 = 0;
    ModuleReadKeys();
    while (1) {

    if (gUnk_0203761C & 0xC0)
        gUnk_0203B6F4 ^= 1;
    v = gUnk_0203761C & 8;
    if (v != 0) {
        gUnk_0203B82C = 0;
        /* sub_0833DA2C: this file's old local prototype differs from
           functions.h; call through the old signature (solved-walls 31). */
        ((void (*)(u8))sub_0833DA2C)(3);
        return 0;
    }
    w = gUnk_0203761C & 1;
    if (w != 0) {
        gUnk_0203B82C = v;
        ((void (*)(u8))sub_0833DA2C)(3);
        return gUnk_0203B6F4 + 1;
    }
    if (gUnk_0203761C & 2) {
        gUnk_0203B82C = w;
        ((void (*)(u8))sub_0833DA2C)(3);
        gUnk_0203B6F4 = w;
        return 1;
    }
    ((void (*)(u8))sub_0833DA2C)(gUnk_0203B6F4);
    ModuleWaitForVBlank();
        gUnk_0203B82C++;
        ModuleReadKeys();
    }
}
