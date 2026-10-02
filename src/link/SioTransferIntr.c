#include "global.h"
#include "functions.h"
#include "gba/io_reg.h"
#include "variables.h"

/* Serial IRQ handler for the comm state at 0x0202CDD0.
 *
 * Built at -O1 (Makefile override, like eeprom.o): at -O2 the Cygnus
 * merge_blocks pass hoists the Lneg block next to its `b`, which the ROM
 * keeps after the mode-1 arm. The r5/r4 pins keep cse from folding the
 * copy p into w: cse never substitutes a hard register, so w keeps only
 * the mode test and the Lneg store.
 */

void SioTransferIntr(void)
{
    vu32 *sio = (vu32 *)REG_ADDR_SIODATA32;
    u32 v = *sio;
    register struct CommRegs *w PIN(r5) = &gSioTransfer;
    register struct CommRegs *p PIN(r4) = w;
    s32 cnt;
    s32 n;

    if (w->mode != 1) {
        REG_SIOCNT |= SIO_START;
        cnt = p->count;
        if (cnt >= 0)
            goto Lpos;
        goto Lneg;
    } else {
        REG_TM3CNT_H = 0;
        n = p->count;
        if (n < 0)
            *sio = 0xFEFEFEFE;
        else if (n <= 0x1FFF)
            *sio = p->data[n];
        else
            *sio = p->checksum;
        goto Ltail;
    }
Lneg:
    if (v != 0xFEFEFEFE)
        w->count = cnt - 1;
    goto Ltail;
Lpos:
    if (cnt <= 0x1FFF)
        p->data[cnt] = v;
    else
        p->checksum = v;
Ltail:
    n = p->count;
    if (n <= 0x2002) {
        p->count = n + 1;
        if (p->mode == 1) {
            REG_SIOCNT |= SIO_START;
            REG_TM3CNT_H = TIMER_INTR_ENABLE | TIMER_ENABLE;
        }
    }
}
