#include "global.h"
#include "functions.h"

void Draw32x32Sprite(u32 posX, u32 posY, u32 tileNum)
{ AddOamEntry((posY & 0xFF) | ((posX & 0x1FF) << 16) | 0x40000000, 0xF800 | tileNum); }
