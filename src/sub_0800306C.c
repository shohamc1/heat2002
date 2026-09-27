#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/compat.h"
#include "variables.h"

/* Defined here (not symbols.ld): the first RAM variable moved into C,
   per the phase-6 mechanism proof in docs/extern-headers-plan.md. */
EWRAM_DATA u8 gVBlankWorkPhase = 0;

void m4aSoundVSync(void);
void FlushTrackBgBuffers(void);
void UploadPendingGfx(void);
void FlushPaletteBuffer(void);
void m4aSoundMain(void);

void MainVBlankCallback(void)
{
    u8 v;

    m4aSoundVSync();
    (*(vu16 *)&gVBlankCounter)++;
    gLinkVBlankTimeout++;
    if (gIsLinkRace != 0) {
        if ((*(vu16 *)&gVBlankCounter) > 1)
            gUnk_020020EC = 1;
        else
            gUnk_020020EC = 0;
    } else {
        gUnk_020020EC ^= 1;
    }
    if (gIsLinkRace == 0)
        gUnk_020020EC = 1;
    gVBlankWorkPhase++;
    if (gVBlankWorkPhase > 2) {
        v = (*(vu8 *)&gVBlankWorkDone);
        if (v == 0) {
            gVBlankWorkPhase = v;
            CpuFastSet(gUnk_02024830, (void *)OAM, 0x100);
            if (gBgScrollUpdateEnabled != 0) {
                REG_BG3HOFS = gUnk_02022DE0;
                REG_BG3VOFS = gUnk_02022DE8;
                REG_BG2HOFS = gUnk_02022DF8;
                REG_BG2VOFS = gUnk_0200BC2C;
                REG_BG1HOFS = gUnk_0200BC48;
                REG_BG1VOFS = gUnk_0200BC4C;
                REG_BG0HOFS = v;
                REG_BG0VOFS = v;
                FlushTrackBgBuffers();
                UploadPendingGfx();
            } else {
                UploadPendingGfx();
            }
            (*(vu8 *)&gVBlankWorkDone) = 1;
        }
    }
    FlushPaletteBuffer();
    m4aSoundMain();
    REG_IME = 0;
    (*(vu16 *)&gIntrCheck) |= 1;
    REG_IME = 1;
}
