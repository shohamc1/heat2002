#include "global.h"

/* 0x08345390-0x083453C0 (EWRAM 0x0200C910): the high module's m4a
 * ply_xcmd dispatch table, the twin of the low copy's xcmd table in
 * src/data/rom_0801D230.c (which says what it is for): one handler per
 * xwave/effect command byte. module_ply_xcmd.c reads it as
 * gUnk_0200C910 (symbols.ld alias) and calls through the high module's
 * _08344B84 (_call_via_r2) stub. The handlers are its own
 * ModulePlyXxx family. */

void ModulePlyXxx(void);
void ModulePlyXwave(void);
void ModulePlyXtype(void);
void ModulePlyXatta(void);
void ModulePlyXdeca(void);
void ModulePlyXsust(void);
void ModulePlyXrele(void);
void ModulePlyXiecv(void);
void ModulePlyXiecl(void);
void ModulePlyXleng(void);
void ModulePlyXswee(void);

const u32 gUnk_08345390[12] = {
    (u32)ModulePlyXxx, (u32)ModulePlyXwave, (u32)ModulePlyXtype, (u32)ModulePlyXxx,
    (u32)ModulePlyXatta, (u32)ModulePlyXdeca, (u32)ModulePlyXsust, (u32)ModulePlyXrele,
    (u32)ModulePlyXiecv, (u32)ModulePlyXiecl, (u32)ModulePlyXleng, (u32)ModulePlyXswee
};
