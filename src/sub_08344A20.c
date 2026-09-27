#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "functions.h"

extern u16 gUnk_0203DFB8[];
extern u8 gUnk_0203E004;
extern u8 gUnk_0203E1C0[];
extern u8 gUnk_0203E110;
extern u16 gUnk_0203E160[];
extern u8 gUnk_0203E1B0;
extern u8 gUnk_020390BC;

void sub_08344968(void);
void sub_08344B74(void);
void sub_08344B68(u32 a, u32 b);
void sub_083448B0(u16 a);

void sub_08344A20(void)
{
    u8 *e004;
    u8 i;
    u16 v;
    vu16 *ed;

    sub_08344968();
    i = 0;
    /* Through a pointer: a store to a volatile array element by name
       compiles to a read-modify-write. */
    ed = gUnk_0203DFB8;
    do {
        if ((*(u8 *)REG_ADDR_SIOCNT & 0x30) == 0)
            sub_08344B74();
        else
            sub_08344B68(1, INTR_FLAG_SERIAL);
        sub_08339B4C();
        /* e004 is a variable so its pseudo predates the SIOCNT address
           temp: they tie on allocation priority, and the older one gets
           r6. */
        ed[0] = ((u16)((((*(vu32 *)REG_ADDR_SIOCNT << 26) >> 30) + 1) << 12)
                 | 0x100)
              | ((*(e004 = &gUnk_0203E004) + 1) & 0xFF);
        sub_083448B0(ed[0]);
        gUnk_0203E1C0[2] |= 0xFF;
        gUnk_0203E1C0[6] |= 0xFF;
        gUnk_0203E1C0[10] |= 0xFF;
        gUnk_0203E1C0[14] |= 0xFF;
        gUnk_0203E110 = 0;
        v = gUnk_0203E160[0];
        if ((v >> 12) == 1) {
            gUnk_0203E1C0[2] = 1;
            gUnk_0203E110 = 1;
            if (*(u8 *)REG_ADDR_SIOCNT & 0x30)
                *e004 = v - 1;
            if ((gUnk_0203E160[4] >> 12) == 2) {
                gUnk_0203E1C0[6] = 1;
                gUnk_0203E110 = 2;
                if ((gUnk_0203E160[8] >> 12) == 3) {
                    gUnk_0203E1C0[10] = 1;
                    gUnk_0203E110 = 3;
                    if ((gUnk_0203E160[12] >> 12) == 4) {
                        gUnk_0203E1C0[14] = 1;
                        gUnk_0203E110 = 4;
                    }
                }
            }
        }
        gUnk_0203E1B0 = (*(vu32 *)REG_ADDR_SIOCNT << 26) >> 30;
        gUnk_020390BC = gUnk_0203E110;
        if (gUnk_020390BC <= 1)
            i--;
        gUnk_0203E160[0] = 0;
        gUnk_0203E160[4] = 0;
        gUnk_0203E160[8] = 0;
        gUnk_0203E160[12] = 0;
        i++;
    } while (i != 5);
}
