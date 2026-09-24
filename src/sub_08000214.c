#include "global.h"

void ClearWorkRam(void);
void ClearVideoMemory(void);

void sub_08000214(void)
{
    ClearWorkRam();
    ClearVideoMemory();
}
