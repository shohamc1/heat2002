#include "global.h"
#include "variables.h"

#include "functions.h"
extern u8 gModule_TimeLabel[];
void *ModuleAllocTask(void);
void ModuleAddTask(u32 r0);
void ModuleDrawHudLabels(void);
void ModuleInitCountdown(void);
void ModuleUpdateRaceHud(void);
void ModuleInitRaceHud(void);
extern u8 gModule_PitLabelBlock[];

void ModuleDrawHudLabels(void)
{
    u16 *dst;
    u8 row;
    u8 col;
    u32 rowStride;
    u32 glyphOff;
    dst = (u16 *)(*(u8 **)&gModule_TextLayerMapPtr + 0x3A8);
    for (row = 0; row != 6; row++) {
        rowStride = (row + 8) * 68;
        for (col = 0; col != 10; col++) {
            glyphOff = 2 * (((row + 8) * 68) + col + 0x33);
            *dst = gModule_FontTileEntries[*(u16 *)((u8 *)gUnk_02021594 + glyphOff)] | 0xE000;
            dst++;
        }

        dst += 22;
    }

    dst = (u16 *)(*(u8 **)&gModule_TextLayerMapPtr + 0x3A8);
    if (gModule_DamagePitsEnabled == 0) {
        for (row = 0; row != 6; row++) {
            for (col = 0; col != 4; col++) {
                *dst = 0x47;
                dst++;
            }

            dst += 28;
        }
    }
}

void ModuleInitRaceHud(void)
{
    void *task;

    if (gModule_IsDemo[0] != 0)
        return;
    task = ModuleAllocTask();
    if (task != 0) {
        *(u32 *)((u32)task + 0x0C) = (u32)ModuleUpdateRaceHud;
        ModuleAddTask((u32)task);
    }
    ModuleDrawHudLabels();
    ModuleDrawText(gModule_TimeLabel, 0, 0x13);
    ModuleInitCountdown();
}

void ModuleInitTimeTrialHud(void)
{
    ModuleInitRaceHud();
    if (gUnk_0203E1E0[0] != 0)
        ModuleDrawText(gModule_PitLabelBlock, 0, 0x12);
}
