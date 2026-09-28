#include "global.h"
#include "functions.h"
#include "variables.h"


void sub_0833FA3C(void);
void sub_0833D680(void);
u32 sub_0833C874(void);
void ModuleDrawTextCenteredHighlight(u8 *str, u32 y, u32 shade);
void sub_0833AE90(void);
void sub_08344B74(u32 a);
u32 sub_0833DA34(void);
void sub_0833D510(u32 a, u32 b);

void sub_0833DE98(void)
{
    u32 key;
    u32 t2;

    sub_0833FA3C();
    sub_0833D680();
    for (;;)
    {
        gModule_VBlanksThisFrame = 0;
        if (sub_0833C874() != 0)
        {
            ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_LINK_FAIL), 0xA, 1);
            ModuleDrawTextCenteredHighlight(gModule_PleaseTurnOffYour_2, 0xC, 1);
            ModuleDrawTextCenteredHighlight(gModule_GameBoyAdvance_2, 0xD, 1);
            sub_0833B074((struct MusicPlayerInfo *)((u32)gUnk_02038F70));
            sub_0833B074((struct MusicPlayerInfo *)((u32)gUnk_02038FB0));
            sub_0833AE90();
            do
            {
                key = gModule_LinkPlayerId;
                if (key == 0)
                    key = *(volatile u16 *)0x04000130;
                sub_08344B74(key);
            } while (1);
        }
        else
        {
            if (gModule_LinkPlayerId != 0)
            {
                ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_WAITING), 0xE, 1);
            }
            else
            {
                ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_PRESS_START), 0xE, 1);
            }
        }
        t2 = (u16)sub_0833DA34();
        if ((t2 & 8) == 0)
            continue;
        sub_0833D510(0, 0x32);
        return;
    }
}
