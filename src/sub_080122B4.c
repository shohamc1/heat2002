#include "global.h"
#include "data.h"

extern u16 gKeysPressed;
extern u16 gUnk_020020B8;
extern u8 gOptions[];

extern void ResetLinkState(void);
extern void ZeroTextLayer(void);
extern void sub_0800F4FC(void);
extern void sub_0800F328(u32 src, u16 *dst);
extern void sub_08012228(u8 a);
extern void FadeToBrightenedPalette(u32 a, u32 b);
extern void ReadKeys(void);
extern s8 sub_08012074(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);

u8 sub_080122B4(void)
{
    u8 buf[0x200];
    u8 v;
    u8 sel;
    s8 r;

    v = 0;
    sel = 0x40;
    ResetLinkState();
    ZeroTextLayer();
    sub_0800F4FC();
    sub_0800F328((u32)gUnk_082E4328, (u16 *)buf);
    sub_08012228(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    gUnk_020020B8 = v;
    do
    {
        ReadKeys();
        sub_08012228(v);
        r = sub_08012074();
        switch (r)
        {
        case 1:
            sel = 1;
            break;
        case -1:
            sel = 0;
            break;
        }
        if (gKeysPressed & 2)
            sel = 0;
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
