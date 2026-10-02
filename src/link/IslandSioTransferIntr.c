#include "global.h"
#include "gba/io_reg.h"
#include "variables.h"

/* Serial IRQ handler for the comm state at 0x03000C00. */

void IslandSioTransferIntr(void)
{
    vu32 *sio = (vu32 *)REG_ADDR_SIODATA32;
    u32 v = *sio;
    register struct CommRegs *w PIN(r5) = &gIsland_SioTransfer;
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
