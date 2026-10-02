#include "global.h"
#include "data.h"
#include "functions.h"

extern const u8 sample_0801DBC0[];
extern const u8 sample_0801E4C8[];
extern const u8 sample_0801F84C[];
extern const u8 sample_08020018[];
extern const u8 sample_08021F6C[];

// Its users declare it as MPlayFunc x[].
// Stays flat: the m4a sound driver owns this table (function
// pointers, samples, timer words); it is driver data, not game data.
#if PLATFORM_GBA
const u32 gUnk_0801D230[] = {
    (u32)ply_xxx,   (u32)ply_xwave,       (u32)ply_xtype, (u32)ply_xxx,   (u32)ply_xatta,       (u32)ply_xdeca,
    (u32)ply_xsust, (u32)ply_xrele,       (u32)ply_xiecv, (u32)ply_xiecl, (u32)ply_xleng,       (u32)ply_xswee,
    0x3C00,         (u32)sample_0801DBC0, 0xFF00FF,       0x3C00,         (u32)sample_0801E4C8, 0xFF00FF,
    0x3C00,         (u32)sample_0801F84C, 0xFF00FF,       0x3C00,         (u32)sample_08020018, 0xFF00FF,
    0x3C00,         (u32)sample_08021F6C, 0xFF00FF
};
#else
// Pointer width on the host: a truncated pointer is not a constant
// expression a modern compiler will fold. ply_xcmd.c views the first
// twelve words as MPlayFunc.
#include "gba/m4a_internal.h"
const MPlayFunc gUnk_0801D230[] = {
    ply_xxx,        ply_xwave,            ply_xtype,      ply_xxx,        ply_xatta,           ply_xdeca,
    ply_xsust,      ply_xrele,            ply_xiecv,      ply_xiecl,      ply_xleng,           ply_xswee,
    (MPlayFunc)0x3C00,         (MPlayFunc)sample_0801DBC0, (MPlayFunc)0xFF00FF, (MPlayFunc)0x3C00, (MPlayFunc)sample_0801E4C8, (MPlayFunc)0xFF00FF,
    (MPlayFunc)0x3C00,         (MPlayFunc)sample_0801F84C, (MPlayFunc)0xFF00FF, (MPlayFunc)0x3C00, (MPlayFunc)sample_08020018, (MPlayFunc)0xFF00FF,
    (MPlayFunc)0x3C00,         (MPlayFunc)sample_08021F6C, (MPlayFunc)0xFF00FF
};
#endif
