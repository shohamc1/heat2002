#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "gba/syscall.h"
#include "functions.h"
#include "data.h"
#include "variables.h"
#include "gba/compat.h"

void MultibootVBlankIntr(void);
void SioTransferIntr(void);
extern u32 gGameCodeAgbj;
extern const u8 *const gUnk_083FDA50[];
extern const u8 *const gHighModuleChunks[];
extern u8 gText_BlankRow24_2[];
extern u8 gText_DoNotRemoveGameBoy[];
extern u8 gText_AdvanceGameLink[];
extern u8 gText_CableOrTurnPowerOff[];
extern u8 gMultibootSendObjPalette[];
void SioTransferInit(u32 a1, const u8 *a2);
void DrawLinkProgressBar(u16 x, u16 y);
void DrawMultibootProgressMarker(u32 id, u32 c);
u32 SioTransferUpdate(u32 *frame);
extern u8 gText_BlankRow28_2[];
extern u8 gUnk_08363EE8[];
extern u8 gUnk_08364AC8[];

void DrawMultibootProgressMarker(u32 x, u32 y)
{
    s16 *oam = gOamBuffer;
    u32 spriteX = (x << 23) >> 23;

    oam[9] = (oam[9] & ~0x1FF) | spriteX;
    ((u8 *)oam)[0x10] = y;
    ((u8 *)oam)[0x13] = (((u8 *)oam)[0x13] & 0x3F) | 0x80;
    oam[10] &= ~0x3FF;
}

void DrawLinkProgressBar(u16 progress, u16 y)
{
    s16 *oam = gOamBuffer;
    s16 *oamPtr;
    u16 *capAttr1;
    u16 *capAttr2;
    s32 m1, m2, attr1Mask, attr2Mask;
    u8 *obj;
    u16 seg;
    s32 segPos;
    s32 tile;
    u16 tileNum;

    capAttr1 = &oam[0x25];
    m1 = ~0x1FF;
    *capAttr1 &= m1;
    ((u8 *)oam)[0x48] = y;
    ((u8 *)oam)[0x4B] = (((u8 *)oam)[0x4B] & 0x3F) | 0x80;
    ((u8 *)oam)[0x4D] &= 0x0F;
    capAttr2 = &oam[0x26];
    m2 = ~0x3FF;
    *capAttr2 = (*capAttr2 & m2) | 0x10;

    for (seg = 0, oamPtr = oam, attr1Mask = m1, attr2Mask = m2; seg < 8; seg++) {
        obj = (u8 *)((seg + 10) * 8 + (u32)oamPtr);
        segPos = seg * 32 + 32;
        tileNum = segPos & 0x1FF;
        tile = tileNum;
        *(u16 *)&obj[2] = (*(u16 *)&obj[2] & attr1Mask) | tile;
        obj[0] = y;
        obj[3] = (obj[3] & 0x3F) | 0x80;
        obj[5] &= 0x0F;
        if (progress < segPos)
            *(u16 *)&obj[4] = (*(u16 *)&obj[4] & attr2Mask) | 0x20;
        else
            *(u16 *)&obj[4] = (*(u16 *)&obj[4] & attr2Mask) | 0x10;
    }

    oam[0x41] = (oam[0x41] & ~0x1FF) | 0xD0;
    ((u8 *)oam)[0x80] = y;
    ((u8 *)oam)[0x83] = (((u8 *)oam)[0x83] & 0x3F) | 0x80;
    ((u8 *)oam)[0x85] &= 0x0F;
    oam[0x42] = (oam[0x42] & ~0x3FF) | 0x20;
}

void MultibootVBlankIntr(void)
{ gIntrCheck = 1; }

void InitSinglePakLinkScreen(void)
{
    u32 entryIdx;
    u32 *fontTable;

    entryIdx = 0;
    fontTable = gUiFontTable;
    do {
        *(u16 *)(*(volatile u32 *)&gTextLayerMapPtr[0] + 2 * entryIdx) = 0; /* per-iteration reload, as the ROM loop */
        entryIdx++;
    } while (entryIdx != 0x380);
    DummyUiFontLoad(fontTable[0]);
    GetString(0x52);
    ((void (*)(void))DrawBigText)();
}

u32 SendMultibootPayload(void)
{
    u32 frame;
    u8 idx;
    u16 i;
    u8 t;

    frame = 0;
    idx = 0;
    REG_IE = INTR_FLAG_VBLANK;
    if (RomHeaderMagic == 0x96 && RomHeaderGameCode == gGameCodeAgbj)
        REG_IE |= INTR_FLAG_GAMEPAK;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    REG_IME = 1;
    gIntrTable[1] = (u32)MultibootVBlankIntr;
    gIntrTable[0] = (u32)SioTransferIntr;
    REG_DISPCNT &= ~DISPCNT_OBJ_ON;
    for (i = 0; i < 3; i++)
        LZ77UnCompVram(gUnk_083FDA50[i], (void *)(OBJ_VRAM0 + i * 0x200));
    DmaCopy32(3, gMultibootSendObjPalette, OBJ_PLTT, 0xA0);
    DmaFill32(3, 0xA0, (u8 *)gOamBuffer, 0x400);
    CpuFastSet((u8 *)gOamBuffer, (void *)OAM, 0x100);
    REG_DISPCNT |= DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP;
    SioTransferInit(1, gHighModuleChunks[idx]);
    for (i = 0; i < 4; i++)
        DrawTextCenteredHighlight(gText_BlankRow24_2, i + 8, 1);
    for (;;) {
        t = ((idx << 15) + frame * 4) >> 10;
        DrawLinkProgressBar(t, 100);
        DrawMultibootProgressMarker(t, 100);
        DrawTextCenteredHighlight(gText_DoNotRemoveGameBoy, 8, 1);
        DrawTextCenteredHighlight(gText_AdvanceGameLink, 9, 1);
        DrawTextCenteredHighlight(gText_CableOrTurnPowerOff, 10, 1);
        if (SioTransferUpdate(&frame)) {
            idx++;
            /* goto, not break: expand_end_loop rolls a loop that has a
               break into exit-test-at-bottom form, and the ROM's loop is
               not rolled. */
            if (idx == 7)
                goto done;
            SioTransferInit(1, gHighModuleChunks[idx]);
            frame = 0;
        }
        CpuFastSet((u8 *)gOamBuffer, (void *)OAM, 0x100);
        VBlankIntrWait();
    }
done:
    DmaFill32(3, 0xA0, (u8 *)gOamBuffer, 0x400);
    CpuFastSet((u8 *)gOamBuffer, (void *)OAM, 0x100);
    InitSinglePakLinkScreen();
    return 0;
}

u8 SendMultibootIsland(void)
{
    u8 work[0x24C];
    u32 len;
    u32 flag;
    register u32 icon __asm__("r9");
    register u8 *start __asm__("r10");
    register u8 *stack __asm__("sp");
    u8 *a;
    register u32 one __asm__("r8");
    register u32 x __asm__("r4");
    register u32 y __asm__("r5");
    register s32 i __asm__("r6");

    flag = 0;
    icon = 0;
    REG_BG3CNT = BGCNT_SCREENBASE(28) | BGCNT_CHARBASE(3);
    {
        u8 *src = (u8 *)gTextLayerTiles;
        CpuCopy16((u32)src, BG_SCREEN_ADDR(24), 0x2000);
    }
    {
        u8 *buf = work + 0x4C;
        LoadMenuScreen(4, (u16 *)buf);
        InitSinglePakLinkScreen();
        FadeToBrightenedPalette(buf, 0x0F);
    }
    start = gUnk_08363EE8;
    len = (u32)gUnk_08364AC8 - (u32)start;
    *(u32 *)(work + 0x28) = (u32)start;
    {
        register u8 *dst __asm__("r0") = work + 0x4B;
        *dst = stack[0x254];
    }
    sub_0800EA64(work);
loop:
    {
        VBlankIntrWait();
        DrawTextCenteredHighlight(GetString(0x53), 8, 1);
        i = 1;
        a = work;
        one = i;
        y = 9;
        x = 0x54;
        do {
            register u32 bit1 __asm__("r2");
            register u32 bit2 __asm__("r1");
            register u32 shifted __asm__("r0");
            shifted = a[0x1D] >> i;
            __asm__ volatile("" : "=r"(bit1) : "0"(one));
            if ((shifted & bit1) == 0)
                goto show0;
            shifted = a[0x1E] >> i;
            __asm__ volatile("" : "=r"(bit2) : "0"(one));
            if ((shifted & bit2) != 0)
                goto show1;
        show0:
            /* old prototype u32 GetString(u32): the canonical u16 parameter would
                        narrow x with an extra lsls/lsrs pair */
            DrawTextCenteredHighlight((u8 *)((u32 (*)(u32))GetString)(x), y, 0);
            goto pnext;
        show1:
            DrawTextCenteredHighlight((u8 *)((u32 (*)(u32))GetString)(x), y, 1);
        pnext:;
            y = y + 1;
            x = x + 1;
            i = i + 1;
        } while (i <= 3);
        if (work[0x1E] & 0x0E) {
            if (work[0x18] == 0) {
                register u32 value __asm__("r2") = 0x0F;
                __asm__ volatile("" : : "r"(value));
                icon = value;
            } else if (work[0x18] != 0xD1) {
                register u32 value __asm__("r0") = 0;
                __asm__ volatile("" : : "r"(value));
                icon = value;
            }
            if (work[0x18] > 0xDF) {
                register u32 value __asm__("r1") = 0x58;
                __asm__ volatile("" : : "r"(value));
                icon = value;
                goto show_icon;
            }
        } else {
            register u32 value __asm__("r2") = 0;
            __asm__ volatile("" : : "r"(value));
            icon = value;
        }
        if (icon == 0)
            goto show_empty;
    show_icon:
        __asm__ volatile("" : : : "r0");
        DrawTextCenteredHighlight((u8 *)((u32 (*)(u32))GetString)(icon), 0x0E, 1);
        goto shown;
    show_empty:
        DrawTextCenteredHighlight(gText_BlankRow28_2, 0x0E, 1);
    shown:
        ReadKeys();
        if (gKeysPressed & 8) {
            if (work[0x18] == 0 && work[0x1E] != 0) {
                sub_0800EEFC(work, start + 0xC0, len - 0xC0, 4, 1);
                {
                    register u32 value __asm__("r1");
                    __asm__ volatile("" : "=r"(value) : "0"(1));
                    flag = value;
                }
            }
        }
        if (sub_0800EAA0(work) != 0) {
            register u32 value __asm__("r2") = flag;
            __asm__ volatile("" : : "r"(value));
            if (value == 1)
                return 1;
        }
        if (sub_0800EFC0(work) == 0) {
            if ((gKeysPressed & 2) != 0) {
                register u32 value __asm__("r0") = flag;
                __asm__ volatile("" : : "r"(value));
                if (value != 1)
                    return 1;
            }
        } else {
            InitSinglePakLinkScreen();
            SendMultibootPayload();
            return 0;
        }
        goto loop;
    }
    return 1;
}
