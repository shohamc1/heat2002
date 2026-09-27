#include "global.h"
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

void sub_0833F968(u32 count, u16 *src, void *dest);
void sub_0833F958(void *r0);

void sub_0833F9A8(void)
{
    u32 i;
    u32 pal;
    struct Unk0833C270 *p;
    u16 *src;
    void *dest;

    src = gUnk_020269C4;
    dest = gModule_ObjTileCache64;
    sub_0833F968(4, src, dest);
    src = gUnk_020269CC;
    dest = gModule_ObjTileCache16;
    sub_0833F968(0x18, src, dest);
    src = gUnk_020269FC;
    dest = gModule_ObjTileCache2;
    sub_0833F968(0x20, src, dest);
    src = gUnk_02026A3C;
    dest = gModule_ObjTileCache8;
    sub_0833F968(0x14, src, dest);
    src = gUnk_02026A64;
    dest = gModule_ObjTileCache4;
    sub_0833F968(0x10, src, dest);
    src = gUnk_02026A84;
    dest = gModule_ObjTileCache1;
    sub_0833F968(0x20, src, dest);

    i = 0;
    pal = 0x05000200;
    p = (struct Unk0833C270 *)gUnk_0203C270;
    do {
        sub_0833F958(p);
        p->field_08 = pal;
        pal += 0x20;
        p++;
        i++;
    } while (i != 16);
}
