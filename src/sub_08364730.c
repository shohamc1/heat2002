#include "global.h"
#include "gba/io_reg.h"
#include "variables.h"

/* Serial IRQ handler for the comm state at 0x03000C00.
 *
 * STATUS: near-miss, 3 real byte diffs remain (one register choice), and
 * only when compiled at -O1 (see drafts/sub_08364730.notes.md):
 * the ROM's shape (Lneg block after the mode-1 arm reached by a real
 * `b`, plus the surviving `ldr r5, =0x03000C00; adds r4, r5, #0` pointer
 * copy) is only producible when GCC's Cygnus merge_blocks pass does not
 * run, i.e. at optimize <= 1. At the project's -O2 this function cannot
 * match from any C (merge_blocks hoists the Lneg block; details in the
 * notes). The -O1 build of this file differs from the ROM only in which
 * of r4/r5 holds the pointer copy (3 bytes at 0x0800e646..0x0800e64a).
 */

struct CommRegs
{
    u8 mode;    /* +0 */
    u8 state;   /* +1 */
    u8 retry;   /* +2 */
    u8 flag;    /* +3 */
    u32 data;   /* +4 */
    s32 count;  /* +8 */
    u32 fC;     /* +0xC */
    u32 crc;    /* +0x10 */
    s32 index;  /* +0x14 */
};


void sub_08364730(void)
{
    vu32 *sio = (vu32 *)0x04000120;
    u32 v = *sio;
    register struct CommRegs *w asm("r5") = &gUnk_03000C00;
    register struct CommRegs *p asm("r4") = w;
    s32 cnt;
    s32 n;

    if (w->mode != 1)
    {
        REG_SIOCNT |= SIO_START;
        cnt = p->count;
        if (cnt >= 0)
            goto Lpos;
        goto Lneg;
    }
    else
    {
        REG_TM3CNT_H = 0;
        n = p->count;
        if (n < 0)
            *sio = 0xFEFEFEFE;
        else if (n <= 0x1FFF)
            *sio = ((u32 *)p->data)[n];
        else
            *sio = p->fC;
        goto Ltail;
    }
Lneg:
    if (v != 0xFEFEFEFE)
        w->count = cnt - 1;
    goto Ltail;
Lpos:
    if (cnt <= 0x1FFF)
        ((u32 *)p->data)[cnt] = v;
    else
        p->fC = v;
Ltail:
    n = p->count;
    if (n <= 0x2002)
    {
        p->count = n + 1;
        if (p->mode == 1)
        {
            REG_SIOCNT |= SIO_START;
            REG_TM3CNT_H = 0xC0;
        }
    }
}
