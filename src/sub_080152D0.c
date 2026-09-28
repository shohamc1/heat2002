#include "global.h"

extern const u8 gText_SplashScreen[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_080152D0(void)
{
    return sub_08012384((u32)gText_SplashScreen, 0x44, 0x4C);
}
