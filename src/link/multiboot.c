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
extern u32 gGameCodeAgbj;
extern const u8 *const gUnk_083FDA50[];
extern const u8 *const gHighModuleChunks[];
extern u8 gText_BlankRow24_2[];
extern u8 gText_DoNotRemoveGameBoy[];
extern u8 gText_AdvanceGameLink[];
extern u8 gText_CableOrTurnPowerOff[];
extern u8 gMultibootSendObjPalette[];
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
#if PORTABLE
        obj = (u8 *)((seg + 10) * 8 + (u8 *)oamPtr);
#else
        obj = (u8 *)((seg + 10) * 8 + (u32)oamPtr);
#endif
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
    const u8 *const *fontTable;

    entryIdx = 0;
    fontTable = gUiFontTable;
    do {
#if PORTABLE
        *(u16 *)(*(u8 *volatile *)&gTextLayerMapPtr[0] + 2 * entryIdx) = 0; /* per-iteration reload, as the ROM loop */
#else
        *(u16 *)(*(volatile u32 *)&gTextLayerMapPtr[0] + 2 * entryIdx) = 0; /* per-iteration reload, as the ROM loop */
#endif
        entryIdx++;
    } while (entryIdx != 896);
    DummyUiFontLoad(fontTable[0]);
    DrawBigText(GetString(82));
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
    gIntrTable[1] = MultibootVBlankIntr;
    gIntrTable[0] = SioTransferIntr;
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
    register u32 icon PIN(r9);
    register u8 *start PIN(r10);
    register u8 *stack PIN(sp);
    u8 *a;
    register u32 one PIN(r8);
    register u32 x PIN(r4);
    register u32 y PIN(r5);
    register s32 i PIN(r6);

#if PORTABLE
    /* No link cable and no second GBA on the host: fail as the declined
       dialog does (the caller's "player backed out" path), before any
       serial setup, the island-length arithmetic below (which would
       subtract two unrelated hosted arrays), and SendMultibootPayload's
       chunk walk over gHighModuleRom. */
    return 1;
#endif
    flag = 0;
    icon = 0;
    REG_BG3CNT = BGCNT_SCREENBASE(28) | BGCNT_CHARBASE(3);
    {
        u8 *src = (u8 *)gTextLayerTiles;
        CpuCopy16(src, BG_SCREEN_ADDR(24), 0x2000);
    }
    {
        u8 *buf = work + 0x4C;
        LoadMenuScreen(4, (u16 *)buf);
        InitSinglePakLinkScreen();
        FadeToBrightenedPalette(buf, 0x0F);
    }
    start = gUnk_08363EE8;
    len = (u32)(ADDR_WORD(gUnk_08364AC8) - ADDR_WORD(start));
    *(u32 *)(work + 0x28) = (u32)ADDR_WORD(start);
    {
        register u8 *dst PIN(r0) = work + 0x4B;
        *dst = stack[0x254];
    }
    sub_0800EA64(work);
loop:
    {
        VBlankIntrWait();
        DrawTextCenteredHighlight(GetString(83), 8, 1);
        i = 1;
        a = work;
        one = i;
        y = 9;
        x = 84;
        do {
            register u32 bit1 PIN(r2);
            register u32 bit2 PIN(r1);
            register u32 shifted PIN(r0);
            shifted = a[0x1D] >> i;
            __asm__ volatile("" : "=r"(bit1) : "0"(one));
            if ((shifted & bit1) == 0)
                goto show0;
            shifted = a[0x1E] >> i;
            __asm__ volatile("" : "=r"(bit2) : "0"(one));
            if ((shifted & bit2) != 0)
                goto show1;
        show0:
            /* Called as GetString(u32): the real u16 parameter would narrow
               x with an extra lsl/lsr pair. */
            DrawTextCenteredHighlight((u8 *)((u8 *(*)(u32))GetString)(x), y, 0);
            goto pnext;
        show1:
            DrawTextCenteredHighlight((u8 *)((u8 *(*)(u32))GetString)(x), y, 1);
        pnext:;
            y = y + 1;
            x = x + 1;
            i = i + 1;
        } while (i <= 3);
        if (work[0x1E] & 0x0E) {
            if (work[0x18] == 0) {
                register u32 value PIN(r2) = 0x0F;
                __asm__ volatile("" : : "r"(value));
                icon = value;
            } else if (work[0x18] != 0xD1) {
                register u32 value PIN(r0) = 0;
                __asm__ volatile("" : : "r"(value));
                icon = value;
            }
            if (work[0x18] > 0xDF) {
                register u32 value PIN(r1) = 0x58;
                __asm__ volatile("" : : "r"(value));
                icon = value;
                goto show_icon;
            }
        } else {
            register u32 value PIN(r2) = 0;
            __asm__ volatile("" : : "r"(value));
            icon = value;
        }
        if (icon == 0)
            goto show_empty;
    show_icon:
#if PLATFORM_GBA
        __asm__ volatile("" : : : "r0");
#endif
        DrawTextCenteredHighlight((u8 *)((u8 * (*)(u32)) GetString)(icon), 14, 1);
        goto shown;
    show_empty:
        DrawTextCenteredHighlight(gText_BlankRow28_2, 14, 1);
    shown:
        ReadKeys();
        if (gKeysPressed & 8) {
            if (work[0x18] == 0 && work[0x1E] != 0) {
                sub_0800EEFC(work, start + 0xC0, len - 0xC0, 4, 1);
                {
                    register u32 value PIN(r1);
                    __asm__ volatile("" : "=r"(value) : "0"(1));
                    flag = value;
                }
            }
        }
        if (sub_0800EAA0(work) != 0) {
            register u32 value PIN(r2) = flag;
            __asm__ volatile("" : : "r"(value));
            if (value == 1)
                return 1;
        }
        if (sub_0800EFC0(work) == 0) {
            if ((gKeysPressed & 2) != 0) {
                register u32 value PIN(r0) = flag;
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
