#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "variables.h"
#include "data.h"

extern u8 gUnk_0807CA60[];
extern u8 gUnk_08363EE8[];
extern u8 gUnk_08364AC8[];

u32 SendMultibootIsland(void)
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
        u8 *src = (u8 *)gUnk_0833338C;
        CpuCopy16((u32)src, BG_SCREEN_ADDR(24), 0x2000);
    }
    {
        u8 *buf = work + 0x4C;
        sub_08011C9C(4, (u16 *)buf);
        sub_0800DFCC();
        FadeToBrightenedPalette((u32)buf, 0x0F);
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
        DrawTextCenteredHighlight((u8 *)GetString(0x53), 8, 1);
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
            __asm__ volatile ("" : "=r" (bit1) : "0" (one));
            if ((shifted & bit1) == 0)
                goto show0;
            shifted = a[0x1E] >> i;
            __asm__ volatile ("" : "=r" (bit2) : "0" (one));
            if ((shifted & bit2) != 0)
                goto show1;
show0:
/* old prototype u32 GetString(u32): the canonical u16 parameter would
            narrow x with an extra lsls/lsrs pair */
            DrawTextCenteredHighlight((u8 *)((u32 (*)(u32))GetString)(x), y, 0);
            goto pnext;
show1:
            DrawTextCenteredHighlight((u8 *)((u32 (*)(u32))GetString)(x), y, 1);
pnext:
            ;
            y = y + 1;
            x = x + 1;
            i = i + 1;
        } while (i <= 3);
        if (work[0x1E] & 0x0E)
        {
            if (work[0x18] == 0)
            {
                register u32 value __asm__("r2") = 0x0F;
                __asm__ volatile ("" : : "r" (value));
                icon = value;
            }
            else if (work[0x18] != 0xD1)
            {
                register u32 value __asm__("r0") = 0;
                __asm__ volatile ("" : : "r" (value));
                icon = value;
            }
            if (work[0x18] > 0xDF)
            {
                register u32 value __asm__("r1") = 0x58;
                __asm__ volatile ("" : : "r" (value));
                icon = value;
                goto show_icon;
            }
        }
        else
        {
            register u32 value __asm__("r2") = 0;
            __asm__ volatile ("" : : "r" (value));
            icon = value;
        }
        if (icon == 0)
            goto show_empty;
show_icon:
        __asm__ volatile ("" : : : "r0");
        DrawTextCenteredHighlight((u8 *)((u32 (*)(u32))GetString)(icon), 0x0E, 1);
        goto shown;
show_empty:
        DrawTextCenteredHighlight(gUnk_0807CA60, 0x0E, 1);
shown:
        ReadKeys();
        if (gKeysPressed & 8)
        {
            if (work[0x18] == 0 && work[0x1E] != 0)
            {
                sub_0800EEFC(work,(u32)(start + 0xC0),(void *)(len - 0xC0), 4, 1);
                {
                    register u32 value __asm__("r1");
                    __asm__ volatile ("" : "=r" (value) : "0" (1));
                    flag = value;
                }
            }
        }
        if (sub_0800EAA0(work) != 0)
        {
            register u32 value __asm__("r2") = flag;
            __asm__ volatile ("" : : "r" (value));
            if (value == 1)
                return 1;
        }
        if (sub_0800EFC0(work) == 0)
        {
            if ((gKeysPressed & 2) != 0)
            {
                register u32 value __asm__("r0") = flag;
                __asm__ volatile ("" : : "r" (value));
                if (value != 1)
                    return 1;
            }
        }
        else
        {
            sub_0800DFCC();
            SendMultibootPayload();
            return 0;
        }
        goto loop;
    }
    return 1;
}
