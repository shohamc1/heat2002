#include "global.h"
#include "variables.h"
#include "car.h"


void sub_08342258(u8 *a, u16 b, u8 c);
void sub_08342074(u8 *a);
void sub_08342FAC(u8 *a);
void ModuleUpdateRacePosition(u8 idx);

void sub_083425C4(u8 *a, u8 b)
{
    u8 *p;
    u8 *q;
    u32 off;

    if (gModule_IsLinkRace != 0) {
        if (gModule_RaceEndState == 0 && a[0x7D] == 0)
            sub_08342258(a, gUnk_020390B0[b], b);
        else
            sub_08342258(a, 2, b);
        sub_08342074(a);
    }
    if (*(s32 *)(a + 0x88) > 0x11940 && a[0x7C] != 1 && (gModule_FrameCounter & 0x3F) == 0)
        sub_08342FAC(a);
    if (gModule_IsLinkRace != 0) {
        if (b == gModule_LinkPlayerId) {
            ModuleUpdateRacePosition(b);
            q = (u8 *)gModule_Cars;
            off = b * 400;
            p = off + q;
            if (p[0x150] != 0 && p[0x150] != 0x63)
                p[0x166] = 0;
        }
    } else if (b == 0) {
        ModuleUpdateRacePosition(0);
        p = (u8 *)gModule_Cars;
        off = 0x150;
        if (p[off] != 0 && p[off] != 0x63)
            p[off + 0x16] = b;
    }
    *(s32 *)(a + 0x15C) += 1;
}
