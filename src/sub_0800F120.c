#include "global.h"
#include "data.h"


u8 sub_0800F120(u8 id)
{
    u8 i;

    for (i = 0; i != 0x1E; i++) {
        if (gDriverRoster[i].teamId == id)
            return i;
    }
    return 0;
}
