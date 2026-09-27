#include "global.h"
#define GBA_CPUFASTSET sub_08344B60
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/compat.h"

extern u16 gUnk_02039134;
extern u16 gUnk_0203917C;
extern u8 gUnk_020390EC;
extern u8 gUnk_020390FC;
extern u8 gUnk_020391C8;
extern u8 gUnk_020390D0;
extern u8 gUnk_0203ACE0[];
extern u8 gUnk_020391D4;
extern u32 gUnk_02039290;
extern u32 gUnk_02039298;
extern u32 gUnk_020392A8;
extern u32 gUnk_02039240;
extern u32 gUnk_0203925C;
extern u32 gUnk_02039260;
extern u16 gUnk_03007FF8;

void sub_0833A1DC(void);
void sub_0833D094(void);
void sub_0833FDC4(void);
void sub_0833D4E4(void);
void sub_0833A8BC(void);

void sub_0833C5B0(void)
{
    u8 v;

    sub_0833A1DC();
    (*(vu16 *)&gUnk_02039134)++;
    gUnk_0203917C++;
    if (gUnk_020390EC != 0) {
        if ((*(vu16 *)&gUnk_02039134) > 1)
            gUnk_020390FC = 1;
        else
            gUnk_020390FC = 0;
    } else {
        gUnk_020390FC ^= 1;
    }
    if (gUnk_020390EC == 0)
        gUnk_020390FC = 1;
    gUnk_020391C8++;
    if (gUnk_020391C8 > 2) {
        v = (*(vu8 *)&gUnk_020390D0);
        if (v == 0) {
            gUnk_020391C8 = v;
            CpuFastSet(gUnk_0203ACE0, (void *)OAM, 0x100);
            if (gUnk_020391D4 != 0) {
                REG_BG3HOFS = gUnk_02039290;
                REG_BG3VOFS = gUnk_02039298;
                REG_BG2HOFS = gUnk_020392A8;
                REG_BG2VOFS = gUnk_02039240;
                REG_BG1HOFS = gUnk_0203925C;
                REG_BG1VOFS = gUnk_02039260;
                REG_BG0HOFS = v;
                REG_BG0VOFS = v;
                sub_0833D094();
                sub_0833FDC4();
            } else {
                sub_0833FDC4();
            }
            (*(vu8 *)&gUnk_020390D0) = 1;
        }
    }
    sub_0833D4E4();
    sub_0833A8BC();
    REG_IME = 0;
    (*(vu16 *)&gUnk_03007FF8) |= 1;
    REG_IME = 1;
}
