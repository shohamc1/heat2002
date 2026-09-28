#include "global.h"
#include "data.h"

extern const u8 sample_0801DBC0[];
extern const u8 sample_0801E4C8[];
extern const u8 sample_0801F84C[];
extern const u8 sample_08020018[];
extern const u8 sample_08021F6C[];
void ply_xxx(void);
void ply_xwave(void);
void ply_xtype(void);
void ply_xatta(void);
void ply_xdeca(void);
void ply_xsust(void);
void ply_xrele(void);
void ply_xiecv(void);
void ply_xiecl(void);
void ply_xleng(void);
void ply_xswee(void);

// Its users declare it as MPlayFunc x[].
// Stays flat: the m4a sound driver owns this table (function
// pointers, samples, timer words); it is driver data, not game data.
const u32 gUnk_0801D230[] = {
    (u32)ply_xxx, (u32)ply_xwave, (u32)ply_xtype, (u32)ply_xxx,
    (u32)ply_xatta, (u32)ply_xdeca, (u32)ply_xsust, (u32)ply_xrele,
    (u32)ply_xiecv, (u32)ply_xiecl, (u32)ply_xleng, (u32)ply_xswee,
    0x3C00, (u32)sample_0801DBC0, 0xFF00FF, 0x3C00, (u32)sample_0801E4C8,
    0xFF00FF, 0x3C00, (u32)sample_0801F84C, 0xFF00FF, 0x3C00,
    (u32)sample_08020018, 0xFF00FF, 0x3C00, (u32)sample_08021F6C, 0xFF00FF
};
