#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"

struct EntityAF44 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ u32 unk18;
};

extern u8 gUnk_02022E14;           /* 0x02022E14 */
extern u8 gIsLinkRace;  /* 0x020020DC */
extern u8 gUnk_0200215C;           /* 0x0200215C */
extern u8 gUnk_02002098;           /* 0x02002098 */
extern u8 gUnk_020021E0;           /* 0x020021E0 */


void RaceEndTask(struct EntityAF44 *e)
{
    if (gUnk_02022E14 == 0)
    {
        if (gIsLinkRace == 0)
        {
            if (gUnk_0200215C == 0x0A || gUnk_0200215C == 0x0B)
            {
                if (gUnk_02002098 != 0)
                    /* sub_0800649C: the ROM callers pass a fourth argument the matched definition drops; call
                       through a function pointer with the old prototype. */
                    ((void (*)(u8 *, u32, u32, u32))sub_0800649C)((u8 *)GetString(0x8E), 0x0A, 3, 1);
            }
            else
            {
                ((void (*)(u8 *, u32, u32, u32))sub_0800649C)((u8 *)GetString(0x97), 0x0A, 3, 1);
            }
        }
        e->unk18 = e->unk18 - 1;
        if (e->unk18 == 0)
        {
            RemoveTask((u32)e);
            FreeTask((u32)e);
            if (gUnk_0200215C != 4)
            {
                BeginFadeToColor(0x0A, 0);
                WaitForVBlank();
                REG_DISPCNT &= ~DISPCNT_OBJ_ON;
            }
            gUnk_020021E0 = 2;
        }
    }
}
