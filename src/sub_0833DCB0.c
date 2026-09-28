#include "global.h"
#include "functions.h"
#include "variables.h"

extern u32 gUnk_02038FF0[];
extern u32 gUnk_02039040[];

void ModuleReadLinkMenuKeys(void);
u32 ModuleExchangeLinkInput(void);
void ModuleDrawTextCenteredHighlight(u32 *a, u32 b, u32 c);
void ModuleM4aSoundVSyncOff(void);
void sub_08344B74(void);
void sub_0833DC7C(void);
void sub_0833DC14(void);

u8 sub_0833DCB0(void)
{
    volatile u8 buf[512];
    u32 done;
    u16 v;

    gUnk_0203B850[0] = 0xFF;
    ModuleReadLinkMenuKeys();
    if (gUnk_0203B6FC & 8) {
        ModuleM4aMPlayStop((struct MusicPlayerInfo *)gUnk_02038F70);
        ModuleM4aMPlayStop((struct MusicPlayerInfo *)gUnk_02038FB0);
        ModuleM4aMPlayStop((struct MusicPlayerInfo *)gUnk_02038FF0);
        ModuleM4aMPlayStop((struct MusicPlayerInfo *)gUnk_02039040);
        for (;;) {
            gModule_VBlanksThisFrame = 0;
            if (ModuleExchangeLinkInput() != 0) {
                ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_LINK_FAIL), 0xA, 1);
                ModuleDrawTextCenteredHighlight((u32 *)gModule_PleaseTurnOffYour_2, 0xC, 1);
                ModuleDrawTextCenteredHighlight((u32 *)gModule_GameBoyAdvance_2, 0xD, 1);
                ModuleM4aSoundVSyncOff();
                done = 0;
                do {
                    if (gModule_LinkPlayerId == 0)
                        return 0x27;
                    sub_08344B74();
                } while (done == 0);
            }
            ModuleReadLinkMenuKeys();
            v = gUnk_0203B6FC & 8;
            if (v != 0) {
                sub_0833DC7C();
                return 1;
            }
            sub_0833DC14();
            (*(u32 *)&gModule_FrameCounter) = (*(u32 *)&gModule_FrameCounter) + 1;
            gModule_VBlankWorkDone = v;
          spin:
            if (gModule_VBlankWorkDone == 0)
                goto spin;
        }
    }
    return 0;
}
