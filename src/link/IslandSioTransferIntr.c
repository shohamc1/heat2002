#include "global.h"
#include "gba/io_reg.h"
#include "variables.h"

/* Serial IRQ handler for the comm state at 0x03000C00. */

struct CommRegs
{
    u8 mode;      /* +0 */
    u8 state;     /* +1 */
    u8 retry;     /* +2 */
    u8 flag;      /* +3 */
    u32 *data;    /* +4 */
    s32 count;    /* +8 */
    u32 checksum; /* +0xC */
    u32 crc;      /* +0x10 */
    s32 index;    /* +0x14 */
};

void IslandSioTransferIntr(void)
{
    vu32 *sio = (vu32 *)0x04000120;
    u32 v = *sio;
    register struct CommRegs *w asm("r5") = &gIsland_SioTransfer;
    register struct CommRegs *p asm("r4") = w;
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
            REG_TM3CNT_H = 0xC0;
        }
    }
}
