#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/compat.h"
#include "variables.h"
#include "functions.h"
#include "m4a.h"

/* gVBlankWorkPhase (0x020021B8) — the first RAM variable ever moved into C,
   per the phase-6 mechanism proof in docs/extern-headers-plan.md — now
   lives in src/system/globals.c, which owns the whole 0x02000DE0-0x02022E20
   EWRAM run; the EWRAM_DATA definition pattern moved with it. Only this
   file reads it, so it keeps a local extern. */
extern u8 gVBlankWorkPhase;                       /* 0x020021B8 */

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
            CpuFastSet(gOamEntryQueue, (void *)OAM, 0x100);
            if (gBgScrollUpdateEnabled != 0) {
                REG_BG3HOFS = gBg3ScrollX;
                REG_BG3VOFS = gBg3ScrollY;
                REG_BG2HOFS = gBg2ScrollX;
                REG_BG2VOFS = gBg2ScrollY;
                REG_BG1HOFS = gBg1ScrollX;
                REG_BG1VOFS = gBg1ScrollY;
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
