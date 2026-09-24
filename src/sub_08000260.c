#include "global.h"

void ClearVram(void);
void ResetOam(void);
void ClearPalette(void);

void ClearVideoMemory(void)
{
    ClearVram();
    ResetOam();
    ClearPalette();
}
