#include "global.h"
#include "variables.h"

extern const u8 *gModule_LocalizedText[];

const u8 *ModuleGetString(u16 messageId)
{
    return gModule_LocalizedText[gModule_Language + messageId * 5];
}
