#include "global.h"

void ModuleResetCarSurface(u8 *car)
{
    u32 carAddr = (u32)car;
    u8 wasGrass;
    u32 sp[0x0A];

    (void)sp;
    *(u8 *)(carAddr + (0xB8 << 1)) = 0;
    wasGrass = *(u8 *)(carAddr + 0x171);
    *(u8 *)(carAddr + 0x173) = wasGrass;
    *(u8 *)(carAddr + 0x171) = 0;
    *(u8 *)(carAddr + 0x172) = 0;
}
