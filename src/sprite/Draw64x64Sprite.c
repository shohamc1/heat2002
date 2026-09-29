#include "global.h"
#include "functions.h"

void Draw64x64Sprite(u32 posX, u32 posY, u32 tileNum)
{ AddOamEntry((posY & 0xFF) | ((posX & 0x1FF) << 16) | 0xC0002000, 0x800 | tileNum); }
