#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u32 gUnk_0202EDBC;
struct Unk_0202EFA0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};
void ResetLinkState(void)
{
    u8 i;
    u8 j;
    REG_RCNT = 0;
    REG_SIOCNT = 0;
    i = 0;
    do {
        ((struct Unk_0202EFA0 *)gUnk_0202EFA0)[i].unk0 |= 0xFF;
        ((struct Unk_0202EFA0 *)gUnk_0202EFA0)[i].unk1 |= 0xFF;
        ((struct Unk_0202EFA0 *)gUnk_0202EFA0)[i].unk2 |= 0xFF;
        i++;
    } while (i != 4);
    gUnk_0202EDBC = 0;
    gUnk_0200216C = 0;
    SetLinkSerialIntr();
    InitMultiplayerSio();
    REG_IE |= INTR_FLAG_SERIAL;
    if ((*(u8 *)REG_ADDR_SIOCNT & 0x30) == 0)
        REG_IE |= INTR_FLAG_TIMER3;
    i = 0;
    do {
        gUnk_0202ED78[i] = 0;
        j = 0;
        do {
            *(u16 *)((u8 *)gUnk_0202EF40 + j * 2 + i * 8) = 0;
            j++;
        } while (j < 4);
        i++;
    } while (i < 4);
}
