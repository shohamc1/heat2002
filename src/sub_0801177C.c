#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u8 gDriverSelectTiles[], gMenuPalette[], gText_BlankRowDriverSelect[];
extern u8 gDriverSelectGfxDest[];

/* MATCH. The ROM keeps &b[0] in r6 and recomputes &b[i] every iteration; the
   hard-register hint on p and the temps in the input loop select that
   allocation. The final gNumLinkPlayers[0] test is a volatile read so its value
   lands in r0 rather than being reused from r1. */
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
    sub_080045D8();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    sub_080047DC();
    gVBlankWorkDone = 0;
    WaitForVBlank();
    ZeroTextLayer();
    sub_0800F4FC();
    sub_0800F328((u32)gMenuPalette, (u16 *)buf);
    sub_08010E04(a[(*(volatile u32 *)REG_ADDR_SIOCNT << 26) >> 30]);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    for (i = 0; i < gNumLinkPlayers[0]; i++)
        b[i] |= 0xFF;
    while (sel == 0x40) {
        ClearOamBuffer();
        sub_08010E04(a[gLinkPlayerId[0]]);
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
                /* sub_080116D4: this file's old prototype is
                   u8 (u16, u8, u32, u32, u8 *, u8); the matched definition
                   narrows differently; call through the old one. */
                a[i] = ((u8 (*)(u16, u8, u32, u32, u8 *, u8))sub_080116D4)(c[i], a[i], 0, 0x1D, (u32)a, i);
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
            DrawTextCenteredHighlight((u8 *)(GetString(0x58)), 0x11, 1);
            if (count == *(volatile u8 *)&gNumLinkPlayers[0]) {
                for (i = 0; i < gNumLinkPlayers[0]; i++) {
                    gCars[i].driverId = b[i];
                    sel = b[i];
                }
            }
        } else {
            DrawTextCenteredHighlight((u8 *)((u32)gText_BlankRowDriverSelect), 0x11, 1);
        }
        sub_080047DC();
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
