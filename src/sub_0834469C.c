#include "global.h"
#include "variables.h"

struct Unk083FDB98 {
    u32 a;
    u8 b;
};


u8 sub_0834469C(u8 id)
{
    u8 i;

    for (i = 0; i != 0x1E; i++) {
        if (((struct Unk083FDB98 *)gUnk_0202AF44)[i].b == id)
            return i;
    }
    return 0;
}
