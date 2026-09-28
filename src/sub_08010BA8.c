#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"
#include "gba/syscall.h"



u32 sub_08010BA8(u8 param)
{
    u8 unused[0xC];
    u8 buf[2];
    s32 ret;

    /* sub_08010B38: this file's old prototype returns s32; the matched definition returns u16 */
    ret = ((s32 (*)(u8))sub_08010B38)(param);
    buf[0] = ret;
    buf[1] = (ret & 0xFF00) >> 8;
    GetString(0x70);
    ((void (*)(void))DrawBigText)();
    sub_08010AA4(param);
    CpuCopy16((u32)gDriverCarPalettes[0], OBJ_PLTT, OBJ_PLTT_SIZE);
    if (buf[1] == 0xFF) {
        RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[buf[0]], OBJ_VRAM0);
        RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[buf[0]], OBJ_VRAM0 + 0x1000);
        Draw64x64Sprite(0x38, 0x30, 0);
        Draw64x64Sprite(0x78, 0x30, 0x80);
    } else {
        RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[buf[0]], OBJ_VRAM0);
        RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[buf[0]], OBJ_VRAM0 + 0x1000);
        RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[buf[1]], OBJ_VRAM0 + 0x2000);
        RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[buf[1]], OBJ_VRAM0 + 0x3000);
        Draw64x64Sprite(0x60, 0x30, 0x80 << 1);
        Draw64x64Sprite(0xA0, 0x30, 0xC0 << 1);
        Draw64x64Sprite(0x10, 0x30, 0);
        Draw64x64Sprite(0x50, 0x30, 0x80);
    }
}
