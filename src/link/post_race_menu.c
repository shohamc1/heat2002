#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"
#include "gba/compat.h"
#include "car.h"
#include "gba/io_reg.h"
#include "m4a.h"

extern u8 gDriverSelectTiles[], gText_BlankRowDriverSelect[];
extern u8 gDriverSelectGfxDest[];

void DrawLinkPostRaceMenu(u8 selected)
{
    u8 cur = selected;
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x5A);
    ((void (*)(void))DrawBigText)();
    text = GetString(0x05);
    DrawTextCenteredHighlight(text, 7, selected == 0);
    text = GetString(0x06);
    DrawTextCenteredHighlight(text, 9, selected == 1);
    text = GetString(0x07);
    DrawTextCenteredHighlight(text, 0xB, selected == 2);
    text = GetString(0x08);
    DrawTextCenteredHighlight(text, 0xD, cur == 3);
}

u8 LinkPostRaceMenu(void)
{
    u8 palette[0x200];
    s8 choice;
    s8 cursor;
    u16 old;
    u16 keys;

    ResetLinkState();
    cursor = 0;
    LoadMenuScreen(1, (u16 *)palette);
    DrawLinkPostRaceMenu(0);
    FadeToBrightenedPalette(palette, 0x0F);
    choice = 0x40;
    do {
        old = gPlayerKeys[0];
        if (ExchangeLinkInput() != 0) {
            choice = 5;
        } else {
            keys = (gPlayerKeys[0] ^ old) & gPlayerKeys[0];
            if (keys & 9)
                choice = cursor;
            cursor = MenuMoveVertical(keys, cursor, 0, 3);
            DrawLinkPostRaceMenu(cursor);
            WaitForVBlank();
        }
    } while (choice == 0x40);
    FadeToColor(0, 0x0F);
    return choice;
}

/* MATCH. The ROM keeps &b[0] in r6 and recomputes &b[i] every iteration; the
   hard-register hint on p and the temps in the input loop select that
   allocation. The final gNumLinkPlayers[0] test is a volatile read so its value
   lands in r0 rather than being reused from r1. */
s16 LinkMenuMoveHorizontal(u16 keys, s16 v, s16 lo, s16 hi, u8 unused, u8 playerId)
{
    if (keys & DPAD_LEFT) {
        gMenuValueChanged = 1;
        if (gLinkPlayerId[0] == playerId && gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_RIGHT) {
        gMenuValueChanged = 1;
        if (gLinkPlayerId[0] == playerId && gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}

s8 LinkDriverSelect(void)
{
    u8 buf[0x200];
    u8 a[4];
    u8 b[4];
    u16 c[4];
    u16 d[4];
    s8 sel;
    s8 e;
    s32 i;
    s32 n;
    u8 count;
    register u8 value asm("r1");
    u8 assign;
    u8 *out;
    u8 *outElse;
    register u8 *p asm("r6");
    u8 *init;
    u8 *q;
    u32 src;
    u32 dst;

    ResetLinkState();
    i = 3;
    init = &a[3];
    do {
        *init-- = i;
        i--;
    } while (i >= 0);
    e = a[(*(volatile u32 *)REG_ADDR_SIOCNT << 26) >> 30];
    src = (u32)gDriverSelectTiles;
    dst = (u32)gDriverSelectGfxDest;
    CpuCopy16(src, dst, 0x2000);
    ResetSpriteOrderTable();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    UpdateSprites();
    gVBlankWorkDone = 0;
    WaitForVBlank();
    ZeroTextLayer();
    LoadMenuBackdrop();
    BuildScreenPalette(gMenuPalette, (u16 *)buf);
    DrawDriverSelect(a[(*(volatile u32 *)REG_ADDR_SIOCNT << 26) >> 30]);
    FadeToBrightenedPalette(buf, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    for (i = 0; i < gNumLinkPlayers[0]; i++)
        b[i] |= 0xFF;
    while (sel == 0x40) {
        ClearOamBuffer();
        DrawDriverSelect(a[gLinkPlayerId[0]]);
        n = gNumLinkPlayers[0];
        for (i = 0; i < n; i++)
            d[i] = gPlayerKeys[i];
        if (ExchangeLinkInput() != 0) {
            sel = -1;
            break;
        }
        for (i = 0; i < gNumLinkPlayers[0]; i++) {
            c[i] = (gPlayerKeys[i] ^ d[i]) & gPlayerKeys[i];
            p = b;
            q = p + i;
            if ((s8)*q == -1)
                /* LinkMenuMoveHorizontal: this file's old prototype is
                   u8 (u16, u8, u32, u32, u8 *, u8); the matched definition
                   narrows differently; call through the old one. */
                a[i] = ((u8 (*)(u16, u8, u32, u32, u8 *, u8))LinkMenuMoveHorizontal)(c[i], a[i], 0, 0x1D, (u32)a, i);
            if (c[i] & 1) {
                assign = a[i];
                out = q;
                *out = assign;
            }
            if (c[i] & 2) {
                if (i == 0) {
                    value = *(volatile u8 *)p;
                    if ((s8)*p != -1) {
                        *p = value | 0xFF;
                    } else {
                        sel = -2;
                        break;
                    }
                } else {
                    assign = 0xFF;
                    outElse = q;
                    *outElse = assign;
                }
            }
        }
        count = 0;
        for (i = 0; i < gNumLinkPlayers[0]; i++) {
            if ((s8)b[i] != -1)
                count++;
        }
        if ((s8)b[gLinkPlayerId[0]] != -1) {
            DrawTextCenteredHighlight(GetString(0x58), 0x11, 1);
            if (count == *(volatile u8 *)&gNumLinkPlayers[0]) {
                for (i = 0; i < gNumLinkPlayers[0]; i++) {
                    gCars[i].driverId = b[i];
                    sel = b[i];
                }
            }
        } else {
            DrawTextCenteredHighlight(gText_BlankRowDriverSelect, 0x11, 1);
        }
        UpdateSprites();
        gVBlankWorkDone = 0;
    spin:
        if (gVBlankWorkDone == 0)
            goto spin;
    }
    if (sel == -2)
        return sel;
    if (sel == -1)
        return sel;
    if (sel == 0)
        return 0;
    return e;
}
