#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"
#include "gba/syscall.h"


struct Tbl8 {
    u32 p;
    u32 unk;
};

extern struct Tbl8 gUnk_083FDB98[];

u8 sub_08010E04(u8 a)
{
    u8 unused[0xC];

    GetString(0x9C);
    /* sub_080065A8: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(void))sub_080065A8)();
    DrawText(gUnk_0829F2AC, 0, 6, 0);
    DrawTextCenteredHighlight((u8 *)(gUnk_083FDB98[a].p), 6, 1);
    CpuCopy16(gUnk_083FDEF4[a], OBJ_PLTT, OBJ_PLTT_SIZE);
    RLUnCompVram(*(u32 *)gUnk_083FDF74[a], OBJ_VRAM0);
    RLUnCompVram(*(u32 *)gUnk_083FDFEC[a], OBJ_VRAM0 + 0x1000);
    sub_08010194(0x38, 0x40, 0);
    sub_08010194(0x78, 0x40, 0x80);
}
