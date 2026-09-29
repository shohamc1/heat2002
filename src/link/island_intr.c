#include "global.h"
#include "variables.h"

struct Unk83_A
{
    u16 f9 : 9;
    u16 : 7;
};
struct Unk83_B
{
    u8 f6 : 6;
    u8 g2 : 2;
};
struct Unk83_C
{
    u16 f10 : 10;
    u16 : 6;
};

void IslandDummyIntr(void)
{}

void IslandVBlankIntr(void)
{ gIntrCheck = 1; }

void IslandDrawMultibootProgressMarker(s16 x, u8 y)
{
    struct Unk83_B *attr1Hi;
    u8 *oam;
    u8 *attr2;

    oam = (u8 *)gIsland_OamBuffer;
    ((struct Unk83_A *)(oam + 0x12))->f9 = x;
    attr1Hi = (struct Unk83_B *)(oam + 0x13);
    oam[0x10] = y;
    attr2 = oam + 0x14;
    attr1Hi->g2 = 2;
    ((struct Unk83_C *)attr2)->f10 = 0;
}
