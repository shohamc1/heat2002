#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/compat.h"
#include "variables.h"
#include "functions.h"

#define GBA_CPUFASTSET sub_08344B60

extern u8 gModule_VBlankWorkPhase;

void sub_0833A1DC(void);

void ModuleMainVBlankCallback(void)
{
    u8 v;

    sub_0833A1DC();
    (*(vu16 *)&gModule_VBlanksThisFrame)++;
    gUnk_0203917C++;
    if (gModule_IsLinkRace != 0) {
        if ((*(vu16 *)&gModule_VBlanksThisFrame) > 1)
            gUnk_020390FC = 1;
        else
            gUnk_020390FC = 0;
    } else {
        gUnk_020390FC ^= 1;
    }
    if (gModule_IsLinkRace == 0)
        gUnk_020390FC = 1;
    gModule_VBlankWorkPhase++;
    if (gModule_VBlankWorkPhase > 2) {
        v = (*(vu8 *)&gModule_VBlankWorkDone);
        if (v == 0) {
            gModule_VBlankWorkPhase = v;
            CpuFastSet(gModule_OamEntryQueue, (void *)OAM, 0x100);
            if (gModule_BgScrollUpdateEnabled != 0) {
                REG_BG3HOFS = gModule_Bg3ScrollX;
                REG_BG3VOFS = gModule_Bg3ScrollY;
                REG_BG2HOFS = gModule_Bg2ScrollX;
                REG_BG2VOFS = gModule_Bg2ScrollY;
                REG_BG1HOFS = gModule_Bg1ScrollX;
                REG_BG1VOFS = gModule_Bg1ScrollY;
                REG_BG0HOFS = v;
                REG_BG0VOFS = v;
                ModuleFlushTrackBgBuffers();
                ModuleUploadPendingGfx();
            } else {
                ModuleUploadPendingGfx();
            }
            (*(vu8 *)&gModule_VBlankWorkDone) = 1;
        }
    }
    ModuleFlushPaletteBuffer();
    ModuleM4aSoundMain();
    REG_IME = 0;
    (*(vu16 *)&gIntrCheck) |= 1;
    REG_IME = 1;
}
