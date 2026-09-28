#include "global.h"

struct Unk080079A0
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    void (*unkC)(struct Unk080079A0 *);
};

void _08344B80(struct Unk080079A0 *arg0, void (*arg1)(struct Unk080079A0 *));

void sub_0833FFF8(struct Unk080079A0 *arg)
{
    _08344B80(arg, arg->unkC);
}
