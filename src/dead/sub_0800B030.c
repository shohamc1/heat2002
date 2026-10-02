#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_0202EDCC;


void sub_0800B030(struct Task *task)
{
    gUnk_0202EDCC = 1;
    if (gFadeActive == 0)
    {
        DrawSpriteText((u8 *)(GetString(0x9B)), 0x4C, 0x18);
        if (--task->timer == 0)
        {
            RemoveTask(task);
            FreeTask(task);
            BeginFadeToColor(0xA, 0);
            WaitForVBlank();
            REG_DISPCNT &= ~DISPCNT_OBJ_ON;
            gRaceEndState = 2;
        }
    }
}

void sub_0800B09C(void)
{
}
