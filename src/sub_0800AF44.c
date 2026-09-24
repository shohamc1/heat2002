#include "global.h"
#include "gba/io_reg.h"

struct EntityAF44 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ u32 unk18;
};

extern u8 gUnk_02022E14;           /* 0x02022E14 */
extern volatile u8 gUnk_020020DC;  /* 0x020020DC */
extern u8 gUnk_0200215C;           /* 0x0200215C */
extern u8 gUnk_02002098;           /* 0x02002098 */
extern u8 gUnk_020021E0;           /* 0x020021E0 */

extern u32 sub_08016558(u32 a);
extern void sub_0800649C(u8 *str, u32 x, u32 y, u32 z);
extern void sub_08003F84(s32 a, u32 b);
extern void sub_08000458(void);
extern void sub_08007950(struct EntityAF44 *e);
extern void sub_0800792C(struct EntityAF44 *e);

void sub_0800AF44(struct EntityAF44 *e)
{
    if (gUnk_02022E14 == 0)
    {
        if (gUnk_020020DC == 0)
        {
            if (gUnk_0200215C == 0x0A || gUnk_0200215C == 0x0B)
            {
                if (gUnk_02002098 != 0)
                    sub_0800649C((u8 *)sub_08016558(0x8E), 0x0A, 3, 1);
            }
            else
            {
                sub_0800649C((u8 *)sub_08016558(0x97), 0x0A, 3, 1);
            }
        }
        e->unk18 = e->unk18 - 1;
        if (e->unk18 == 0)
        {
            sub_08007950(e);
            sub_0800792C(e);
            if (gUnk_0200215C != 4)
            {
                sub_08003F84(0x0A, 0);
                sub_08000458();
                REG_DISPCNT &= ~DISPCNT_OBJ_ON;
            }
            gUnk_020021E0 = 2;
        }
    }
}
