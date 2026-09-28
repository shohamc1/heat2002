#include "global.h"
#include "functions.h"
#include "variables.h"


void ModuleDrawTextCenteredHighlight(u8 *str, u32 y, u32 z);

void sub_083429B8(u32 a)
{
    if (++*(u32 *)(a + 0x18) == 0x30)
    {
        ModuleRemoveTask(a);
        ModuleFreeTask(a);
    }
    ModuleDrawTextCenteredHighlight(gUnk_0200D118, 8, 1);
}
