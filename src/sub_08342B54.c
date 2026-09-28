#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_08342B54(u32 a)
{
    u8 unused[0x28];

    ModuleDrawText(ModuleGetString(MODULE_MSG_LAP_TIME), 9, 5);
    ModuleDrawText(gUnk_0203DE30, 0xD, 5);
    if (--*(u32 *)(a + 0x18) == 0)
    {
        ModuleDrawText(gUnk_0200D118, 9, 5);
        ModuleRemoveTask(a);
        ModuleFreeTask(a);
    }
}
