#include "global.h"

struct Unk083FDB98 {
    u32 a;
    u8 b;
};

extern struct Unk083FDB98 gUnk_083FDB98[];

u8 sub_0800F120(u8 id)
{
    u8 i;

    for (i = 0; i != 0x1E; i++) {
        if (gUnk_083FDB98[i].b == id)
            return i;
    }
    return 0;
}
