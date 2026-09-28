#include "global.h"
#include "data.h"


u16 sub_08010B38(u8 id)
{
    u8 buf[2];
    u8 i;
    u8 *p;

    buf[0] |= 0xFF;
    buf[1] |= 0xFF;
    i = 0;
    do {
        if (gDriverRoster[i].teamId == id)
            buf[0] = i;
        i++;
    } while (i != 0x1E);
    i = 0;
    do {
        if (i != buf[0] && gDriverRoster[i].teamId == id)
            buf[1] = i;
        i++;
    } while (i != 0x1E);
    p = &buf[0];
    return (buf[1] << 8) | *p;
}
