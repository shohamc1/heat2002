#include "global.h"
#include "variables.h"

void DummyIntr(void);

void SetVBlankCallback(void (*callback)(void))
{
    gVBlankCallback[0] = (u32)callback;
    if (callback == NULL)
        gVBlankCallback[0] = (u32)DummyIntr;
}
