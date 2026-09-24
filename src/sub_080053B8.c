#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"

void AgeGfxCaches(void);
void ClearOamBuffer(void);
u32 ExchangeLinkInput(void);
u32 GetString(u16 idx);
void DrawTextCentered(u32 a, u32 b, u32 c);
void sub_080019B4(u32 a);
void sub_080017D0(void);
void VBlankIntrWait(u32 a);
u32 sub_08004DB4(void);
void FadeToColor(u32 a, u32 b);

void sub_080053B8(void)
{
    AgeGfxCaches();
    ClearOamBuffer();
    while (1)
    {
        u16 r;
        *(u16 *)0x02002124 = 0;
        if (ExchangeLinkInput() != 0)
        {
            DrawTextCentered(GetString(0x75), 0x0A, 1);
            sub_080019B4(0x02001F20);
            sub_080019B4(0x02001F60);
            sub_080017D0();
            while (1)
            {
                u32 r0 = *(u8 *)(EWRAM_START + 0x2EF90);
                if (r0 == 0)
                    r0 = REG_KEYINPUT;
                VBlankIntrWait(r0);
            }
        }
        if (*(u8 *)(EWRAM_START + 0x2EF90) != 0)
            DrawTextCentered(GetString(0x58), 0x0E, 1);
        else
            DrawTextCentered(GetString(0x0F), 0x0E, 1);
        r = sub_08004DB4();
        if (r & 8)
        {
            FadeToColor(0, 0x32);
            return;
        }
    }
}
