#include "global.h"

#include "variables.h"


void IslandDummyIntr(void)
{
}


void IslandVBlankIntr(void)
{
    gIntrCheck = 1;
}

