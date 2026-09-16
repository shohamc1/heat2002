#include "global.h"
#include "gba/defines.h"

struct unk_07304
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

void sub_08007304(u32 count, u16 *src, struct unk_07304 *e)
{
    u32 i;
    u32 t;

    i = 0;
    if (i != count)
    {
        register u32 f asm("r12") = 0xFFFF;
        do {
            e->f8 = f;
            e->f0 = 0;
            e->f4 = 0;
            e->f10 = *src;
            t = *src;
            e->fC = OBJ_VRAM0 + (t << 5);
            e->f6 = 0;
            i++;
            e++;
            src++;
        } while (i != count);
    }
}
