#include "global.h"
#include "variables.h"

struct Unk0833E528Ent
{
    u32 field_00;
    u8 field_04;
    u8 field_05[3];
    void *field_08;
    u8 field_0C[4];
    u32 field_10;
};

extern u32 gUnk_02024EE8[];

struct Unk0833E528Ent *sub_0833FBB0(void *a, u16 *b);
u32 sub_0833FD78(u32 a);
void ModuleAddOamEntry(u32 a, u32 b);

void sub_0833E528(u32 a0)
{
    u16 local[2];
    struct Unk0833E528Ent *ret;
    u32 bits;
    u32 v;

    local[0] = 0xC8;
    local[1] = 0x78;
    ret = sub_0833FBB0(gUnk_02024EE8, local);
    if (ret != 0)
    {
        bits = local[1] & 0xFF;
        bits |= (local[0] & 0x1FF) << 16;
        bits |= 0x80000000;
        v = ret->field_10 | ((sub_0833FD78((u32 *)gUnk_02024F50) << 24) >> 12);
        bits |= 0x100;
        ModuleAddOamEntry(bits, v);
    }
    gUnk_0203B6DC = (a0 + 0xA0) & 0xFF;
}
