#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

void SetCameraPos(u32 x, u32 y)
{
    gCamera[0] = x;
    gCamera[1] = y;
    gCamera[2] = x;
    gCamera[3] = y;
    gCamera[4] = 0;
    gCamera[5] = 0;
}

void UpdateCameraScroll(void)
{
    u32 a;
    u32 b;
    u32 t;
    u32 w;
    s32 x;
    s32 y;

    a = gCamera[0];
    b = gCamera[1];
    switch (gTrackId) {
        case 0:
            t = a + 0x2580000;
            w = b + 0xFA8C0000;
            break;
        case 1:
            t = a + 0x02DD0000;
            w = b + 0xFB220000;
            break;
        case 2:
            t = a + 0xF84D0000;
            w = b + 0x520000;
            break;
        case 3:
            t = a + 0x03970000;
            w = b + 0xFAB60000;
            break;
        case 4:
            t = a + 0xF8450000;
            w = b + 0x460000;
            break;
        case 5:
            t = a + 0x170000;
            w = b + 0xF6650000;
            break;
        case 6:
            t = a + 0x02550000;
            w = b + 0xFA850000;
            break;
        case 7:
            t = a + 0x2580000;
            w = b + 0xFA8A0000;
            break;
        case 8:
            t = a + 0x02520000;
            w = b + 0xFA840000;
            break;
        case 9:
            t = a + 0x049E0000;
            w = b + 0xF70C0000;
            break;
        case 10:
            t = a + 0x04490000;
            w = b + 0xFC750000;
            break;
        case 11:
            t = a + 0xFB080000;
            w = b + 0x02D60000;
            break;
    }
    x = (t - w) * 2;
    y = t + w;
    x += 0xFF110000;
    y += 0xFF610000;
    x >>= 17;
    y >>= 17;
    gCamera[6] = x + 0x78;
    gCamera[7] = y + 0x50;
}

void SmoothCamera(void)
{
    s32 x = gCamera[2] - gCamera[0];
    s32 y = gCamera[3] - gCamera[1];

    if (gIsDemo != 0) {
        gCamera[0] += x;
        gCamera[1] += y;
    } else {
        gCamera[0] += x >> 4;
        gCamera[1] += y >> 4;
    }
}

void SetCameraTarget(struct Car *arg0)
{
    if (gIsDemo != 0) {
        gCamera[2] = arg0->posX;
        gCamera[3] = arg0->posZ;
    } else {
        gCamera[2] = arg0->posX + arg0->velX * 20;
        gCamera[3] = arg0->posZ + arg0->velZ * 20;
    }
}
