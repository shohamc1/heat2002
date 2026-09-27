#include "global.h"
#include "functions.h"
#include "variables.h"

extern u32 gChampionshipRetainTexts[];


void sub_080127E4(s8 a)
{
    GetString(0x14);
    /* sub_080065A8: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(void))sub_080065A8)();
    if (a != 0) {
        DrawText((u8 *)(GetString(0x17)), 0, 9, 1);
        DrawText((u8 *)(GetString(0x18)), 0, 0xA, 1);
        DrawText((u8 *)(GetString(0x19)), 0, 0xB, 1);
        DrawText((u8 *)gChampionshipRetainTexts[gChampionshipIndex], 0, 0xD, 1);
    } else {
        DrawText((u8 *)(GetString(0x15)), 0, 0xD, 1);
        DrawText((u8 *)(GetString(0x16)), 0, 0xE, 1);
    }
}
