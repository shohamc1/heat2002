#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"



void sub_080100B0(void)
{
    if (gOptions[2] != 0)
        m4aSongNumStart(2);
    m4aSoundVSyncOn();
}
