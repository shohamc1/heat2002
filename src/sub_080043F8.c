#include "global.h"

struct UnkStruct080043F8 {
    u32 posX;
    u32 unk04;
    u32 posZ;
    u32 velX;
    u32 unk10;
    u32 velZ;
};

extern u8 gIsDemo;    /* 0x020020E0 */
extern u32 gCamera[]; /* 0x02002100 */

void SetCameraTarget(struct UnkStruct080043F8 *arg0)
{
    if (gIsDemo != 0) {
        gCamera[2] = arg0->posX;
        gCamera[3] = arg0->posZ;
    } else {
        gCamera[2] = arg0->posX + arg0->velX * 20;
        gCamera[3] = arg0->posZ + arg0->velZ * 20;
    }
}
