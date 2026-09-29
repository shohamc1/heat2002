#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "variables.h"
#include "data.h"

struct Task
{
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 callback;
};

extern const u8 gRaceHudObjTiles[];
void UpdateRaceHud(void);
extern u8 gText_TimeLabel[];
void DrawHudLabels(void);
void InitCountdown(void);
extern u8 gText_HudBestLabel[];

void DrawHudLabels(void)
{
    u16 *dst;
    u8 row;
    u8 col;
    u32 glyphOff;

    dst = (*(u16 **)&gTextLayerMapPtr) + 0x1D4;
    row = 0;
    do {
        col = 0;
        do {
            glyphOff = 2 * ((row + 8) * 68 + col + 0x33);
            *dst++ = gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + glyphOff)] | 0xE000;
            col++;
        } while (col != 10);
        dst += 0x16;
        row++;
    } while (row != 6);
    dst = (*(u16 **)&gTextLayerMapPtr) + 0x1D4;
    if (gDamagePitsEnabled == 0) {
        row = 0;
        do {
            col = 0;
            do {
                *dst++ = 0x47;
                col++;
            } while (col != 4);
            dst += 0x1C;
            row++;
        } while (row != 6);
    }
}

void InitRaceHud(void)
{
    struct Task *task;
    u32 src;
    u32 dst;

    if (gIsDemo != 0)
        return;
    task = AllocTask();
    if (task != 0) {
        task->callback = (u32)UpdateRaceHud;
        AddTask((u32)task);
    }
    DrawHudLabels();
    DrawTextAt(gText_TimeLabel, 0, 0x13);
    src = (u32)gRaceHudObjTiles;
    dst = (u32)OBJ_VRAM1 + 0x2280;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    InitCountdown();
}

void InitTimeTrialHud(void)
{
    InitRaceHud();
    if (gIsTimeTrial != 0) {
        DrawTextAt(gText_HudBestLabel, 0, 0x12);
    }
}
