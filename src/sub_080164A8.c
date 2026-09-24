#include "global.h"
extern u16 gKeysPressed;
extern u8 gIsLinkRace;
extern u32 gUnk_083FDE18;
extern void sub_080019B4(u32 a);
extern void sub_080045D8(void);
extern void InitGfxCaches(void);
extern void AgeGfxCaches(void);
extern void ClearOamBuffer(void);
extern void sub_080047DC(void);
extern void ResetBgScroll(void);
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08006734(u32 a);
extern u32 GetString(u16 idx);
extern void sub_080065A8(void);
extern void DrawTextCenteredHighlight(u32 a, u32 b, u32 c);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void VBlankIntrWait(void);
extern void ReadKeys(void);
extern void FadeToColor(u32 a, u32 b);
void sub_080164A8(void)
{
    u8 buf[0x200];
    u16 keys;
    sub_080019B4(0x02001F60);
    sub_080019B4(0x02001F20);
    sub_080045D8();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    sub_080047DC();
    ResetBgScroll();
    gIsLinkRace = 0;
    sub_08011C9C(1, buf);
    sub_08006734(gUnk_083FDE18);
    GetString(0x75);
    sub_080065A8();
    DrawTextCenteredHighlight(GetString(0x75), 0x0A, 1);
    FadeToBrightenedPalette(buf, 0x0F);
    do {
        VBlankIntrWait();
        ReadKeys();
        DrawTextCenteredHighlight(GetString(0x0F), 0x0F, 1);
    } while (!(*(u16 *)0x020005CC & 8));
    FadeToColor(0, 0x0F);
}
