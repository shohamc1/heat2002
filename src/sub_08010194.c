#include "global.h"

extern u32 AddOamEntry(u32 a, u32 b);

void sub_08010194(u32 a, u32 b, u32 c)
{
    AddOamEntry((b & 0xFF) | ((a & 0x1FF) << 16) | 0xC0002000, 0x800 | c);
}
