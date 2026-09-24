#include "global.h"
#include "gba/compat.h"
#include "data.h"


struct Tbl8 {
    u32 p;
    u32 unk;
};

extern struct Tbl8 gUnk_083FDB98[];
extern u32 gUnk_083FDEF4[];
extern u32 *gUnk_083FDF74[];
extern u32 *gUnk_083FDFEC[];
void sub_08010194(u32 a, u32 b, u32 c);
void DrawText(u8 *p, u32 a1, u32 a2, u8 a3);
void sub_080065A8(void);
u32 GetString(u16 idx);
void DrawTextCenteredHighlight(u32 a, u32 b, u32 c);

u8 sub_08010E04(u8 a)
{
    u8 unused[0xC];

    GetString(0x9C);
    sub_080065A8();
    DrawText(gUnk_0829F2AC, 0, 6, 0);
    DrawTextCenteredHighlight(gUnk_083FDB98[a].p, 6, 1);
    CpuCopy16(gUnk_083FDEF4[a], OBJ_PLTT, OBJ_PLTT_SIZE);
    RLUnCompVram(*gUnk_083FDF74[a], OBJ_VRAM0);
    RLUnCompVram(*gUnk_083FDFEC[a], OBJ_VRAM0 + 0x1000);
    sub_08010194(0x38, 0x40, 0);
    sub_08010194(0x78, 0x40, 0x80);
}
