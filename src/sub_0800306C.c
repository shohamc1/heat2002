#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/compat.h"

extern volatile u16 gUnk_02002124;
extern u16 gUnk_0200216C;
extern u8 gIsLinkRace;
extern u8 gUnk_020020EC;
extern u8 gUnk_020021B8;
extern volatile u8 gUnk_020020C0;
extern u8 gUnk_02024830[];
extern u8 gUnk_020021C4;
extern u32 gUnk_02022DE0;
extern u32 gUnk_02022DE8;
extern u32 gUnk_02022DF8;
extern u32 gUnk_0200BC2C;
extern u32 gUnk_0200BC48;
extern u32 gUnk_0200BC4C;
extern vu16 gUnk_03007FF8;

void m4aSoundVSync(void);
void FlushTrackBgBuffers(void);
void UploadPendingGfx(void);
void FlushPaletteBuffer(void);
void m4aSoundMain(void);

void MainVBlankCallback(void)
{
    u8 v;

    m4aSoundVSync();
    gUnk_02002124++;
    gUnk_0200216C++;
    if (gIsLinkRace != 0) {
        if (gUnk_02002124 > 1)
            gUnk_020020EC = 1;
        else
            gUnk_020020EC = 0;
    } else {
        gUnk_020020EC ^= 1;
    }
    if (gIsLinkRace == 0)
        gUnk_020020EC = 1;
    gUnk_020021B8++;
    if (gUnk_020021B8 > 2) {
        v = gUnk_020020C0;
        if (v == 0) {
            gUnk_020021B8 = v;
            CpuFastSet(gUnk_02024830, (void *)OAM, 0x100);
            if (gUnk_020021C4 != 0) {
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
            gUnk_020020C0 = 1;
        }
    }
    FlushPaletteBuffer();
    m4aSoundMain();
    REG_IME = 0;
    gUnk_03007FF8 |= 1;
    REG_IME = 1;
}
