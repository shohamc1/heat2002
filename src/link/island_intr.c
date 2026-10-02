#include "global.h"
#include "functions.h"
#include "variables.h"

struct OamAttr1 /* OAM entry's attr1: 9-bit X */
{
    u16 x : 9;
    u16 : 7;
};
struct OamAttr1Hi /* attr1's high byte: bits 14-15 are the OBJ size */
{
    u8 unk00 : 6;
    u8 size : 2;
};
struct OamAttr2 /* OAM entry's attr2: 10-bit tile index */
{
    u16 tile : 10;
    u16 : 6;
};

void IslandDummyIntr(void)
{}

void IslandVBlankIntr(void)
{ gIntrCheck = 1; }

void IslandDrawMultibootProgressMarker(s16 x, u8 y)
{
    struct OamAttr1Hi *attr1Hi;
    u8 *oam;
    u8 *attr2;

    oam = (u8 *)gIsland_OamBuffer;
    ((struct OamAttr1 *)(oam + 0x12))->x = x;
    attr1Hi = (struct OamAttr1Hi *)(oam + 0x13);
    oam[0x10] = y;
    attr2 = oam + 0x14;
    attr1Hi->size = 2;
    ((struct OamAttr2 *)attr2)->tile = 0;
}
