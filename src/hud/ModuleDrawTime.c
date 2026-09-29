#include "global.h"
#include "functions.h"

void ModuleDrawTime(u16 *dest, s32 min, u32 sec, u32 ms)
{
    u32 digits[8];
    u32 *digitPtr;
    u32 i;

    if (min > 0x63) {
        min = 0x63;
        sec = 0x3B;
        ms = 0;
    }
    digits[2] = 0xA;
    digits[5] = 0xA;
    digits[0] = sub_08344BB8(min, 0xA);
    digits[1] = sub_08344C50(min, 0xA);
    digits[3] = sub_08344BB8(sec, 0xA);
    digits[4] = sub_08344C50(sec, 0xA);
    digits[7] = sub_08344BB8(sub_08344C50(ms, 0x64), 0xA);
    digits[6] = sub_08344BB8(ms, 0x64);
    i = 0;
    digitPtr = digits;
    do {
        ModuleDrawSmallDigit(dest + 2, (u8)*digitPtr++);
        dest++;
        i++;
    } while (i != 8);
}
