#include "global.h"

struct Unk080079A0
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    void (*unkC)(struct Unk080079A0 *);
};

void sub_080079A0(struct Unk080079A0 *arg)
{
    arg->unkC(arg);
}
