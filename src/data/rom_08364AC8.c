#include "global.h"
#include "data.h"

extern const u8 gUnk_0806C664[];
extern const u8 gUnk_0806C668[];
extern const u8 gUnk_0806C66C[];
extern const u8 gUnk_0806C670[];
extern const u8 gUnk_0806C674[];
extern const u8 gUnk_0807CE30[];
extern const u8 gUnk_0807EDEC[];
extern const u8 gUnk_08086D6C[];
extern const u8 gUnk_0808A98C[];
extern const u8 gUnk_0808AB8C[];
extern const u8 gUnk_0808C638[];
extern const u8 gUnk_080954F8[];
extern const u8 gUnk_0809C718[];
extern const u8 gUnk_0809C918[];
extern const u8 gUnk_0809D954[];
extern const u8 gUnk_080A6C74[];
extern const u8 gUnk_080AAD54[];
extern const u8 gUnk_080ABC14[];
extern const u8 gUnk_080B1434[];
extern const u8 gUnk_080B9234[];
extern const u8 gUnk_080B9434[];
extern const u8 gUnk_080BAEF0[];
extern const u8 gUnk_080CA7F0[];
extern const u8 gUnk_080CE6D0[];
extern const u8 gUnk_080D1EF0[];
extern const u8 gUnk_080EC8B0[];
extern const u8 gUnk_080F3FD0[];
extern const u8 gUnk_080F41D0[];
extern const u8 gUnk_080F613C[];
extern const u8 gUnk_0810721C[];
extern const u8 gUnk_0810B27C[];
extern const u8 gUnk_0810E2B0[];
extern const u8 gUnk_08125DD0[];
extern const u8 gUnk_0812DF70[];
extern const u8 gUnk_0812FE5C[];
extern const u8 gUnk_0813EDFC[];
extern const u8 gUnk_081428DC[];
extern const u8 gUnk_08142ADC[];
extern const u8 gUnk_08145D84[];
extern const u8 gUnk_0815E024[];
extern const u8 gUnk_08166024[];
extern const u8 gUnk_08166224[];
extern const u8 gUnk_081698F0[];
extern const u8 gUnk_08178110[];
extern const u8 gUnk_0817C190[];
extern const u8 gUnk_0817E918[];
extern const u8 gUnk_0818F958[];
extern const u8 gUnk_08197518[];
extern const u8 gUnk_08197718[];
extern const u8 gUnk_08198DC8[];
extern const u8 gUnk_081A34C8[];
extern const u8 gUnk_081A4B88[];
extern const u8 gUnk_081A7164[];
extern const u8 gUnk_081B4F24[];
extern const u8 gUnk_081BCEE4[];
extern const u8 gUnk_081C317C[];
extern const u8 gUnk_081C515C[];
extern const u8 gUnk_081C6ADC[];
extern const u8 gUnk_081C6CDC[];
extern const u8 gUnk_081C7EA8[];
extern const u8 gUnk_081C9BC8[];
extern const u8 gUnk_081CB608[];
extern const u8 gUnk_081CB808[];
extern const u8 gUnk_081CDE68[];
extern const u8 gUnk_081DECC8[];
extern const u8 gUnk_081E2188[];
extern const u8 gUnk_081E4A64[];
extern const u8 gUnk_081F8744[];
extern const u8 gUnk_08200444[];
extern const u8 gUnk_08200644[];
extern const u8 gUnk_08203A14[];
extern const u8 gUnk_0820E234[];
extern const u8 gUnk_082121D4[];
extern const u8 gUnk_08215980[];
extern const u8 gUnk_08228880[];
extern const u8 gUnk_082307A0[];
extern const u8 gUnk_08231DC8[];
extern const u8 gUnk_0823F128[];
extern const u8 gUnk_08242CA8[];
extern const u8 gUnk_08242EA8[];
extern const u8 gUnk_08244C24[];
extern const u8 gUnk_08253884[];
extern const u8 gUnk_0825B764[];
extern const u8 gUnk_0825B964[];
extern const u8 gUnk_0825D510[];
extern const u8 gUnk_082683F0[];
extern const u8 gUnk_0826BC70[];
extern const u8 gUnk_0826DE48[];
extern const u8 gUnk_0827AAA8[];
extern const u8 gUnk_08282468[];
extern const u8 gUnk_08283E0C[];
extern const u8 gUnk_0828519C[];
extern const u8 gUnk_082855D8[];
extern const u8 gUnk_08285968[];
extern const u8 gUnk_082876D4[];
extern const u8 gUnk_08288BD4[];
extern const u8 gUnk_0828AA90[];
extern const u8 gUnk_0828BA60[];
extern const u8 gUnk_0828DD4C[];
extern const u8 gUnk_0828F52C[];
extern const u8 gUnk_082914A0[];
extern const u8 gUnk_08292650[];
extern const u8 gUnk_08293548[];
extern const u8 gUnk_082939A8[];
extern const u8 gUnk_08295820[];
extern const u8 gUnk_08296A30[];
extern const u8 gUnk_08298BE4[];
extern const u8 gUnk_08299AF4[];
extern const u8 gUnk_0829B024[];
extern const u8 gUnk_0829C7B4[];
extern const u8 gUnk_0829DBB0[];

const u32 gUnk_08364AC8[] = {
    (u32)gUnk_0806C674, (u32)gUnk_0806C670, (u32)gUnk_0806C66C,
    (u32)gUnk_0806C668, (u32)gUnk_0806C664
};
// Its users declare it as u8 x.
const u8 gUnk_08364ADC[] = INCBIN_U8("build/assets/unknown/data_08364ADC.bin");
const u32 gUnk_08364AE0[] = INCBIN_U32("build/assets/unknown/data_08364AE0.bin");
const u8 gUnk_08364AF4[] = INCBIN_U8("build/assets/unknown/data_08364AF4.bin");
// Its users declare it as u16 *x, u32 *x, u32 x, u32 x[], vu32 x[].
const u32 gUnk_08364B08[] = INCBIN_U32("build/assets/unknown/data_08364B08.bin");
// Its users declare it as struct Track x[].
const u32 gUnk_08364B0C[] = {
    (u32)gUnk_08086D6C, (u32)gUnk_080954F8, 0, (u32)gUnk_0807EDEC,
    (u32)gUnk_0808C638, 0, (u32)gUnk_0808A98C, 0, (u32)gUnk_0807CE30,
    (u32)gUnk_0808AB8C, 0, 0x7D, 0x64, 0x7D, 0x64, 0, 0, (u32)gUnk_08282468,
    (u32)gUnk_08283E0C, 0, 0, 0, 0, 0xD560FDE, 0xCD2, (u32)gUnk_080A6C74,
    (u32)gUnk_080B1434, 0, (u32)gUnk_0809D954, (u32)gUnk_080ABC14, 0,
    (u32)gUnk_0809C718, 0, (u32)gUnk_0809C918, (u32)gUnk_080AAD54, 0, 0x7D,
    0x64, 0x7D, 0x64, 0, 0, (u32)gUnk_0828519C, (u32)gUnk_082855D8, 0, 0, 0, 0,
    0x75C081D, 0x21E, (u32)gUnk_080CA7F0, (u32)gUnk_080EC8B0, 0,
    (u32)gUnk_080BAEF0, (u32)gUnk_080D1EF0, 0, (u32)gUnk_080B9234, 0,
    (u32)gUnk_080B9434, (u32)gUnk_080CE6D0, 0, 0x7D, 0x64, 0x7D, 0x64, 0, 0,
    (u32)gUnk_08285968, (u32)gUnk_082876D4, 0, 0, 0, 0, 0x1C100D5D, 0xEB5,
    (u32)gUnk_0810721C, (u32)gUnk_08125DD0, 0, (u32)gUnk_080F613C,
    (u32)gUnk_0810E2B0, 0, (u32)gUnk_080F3FD0, 0, (u32)gUnk_080F41D0,
    (u32)gUnk_0810B27C, (u32)gUnk_0810B27C, 0x7D, 0x64, 0x7D, 0x64, 0, 0,
    (u32)gUnk_08288BD4, (u32)gUnk_0828AA90, 0, 0, 0, 0, 0x18190FB5, 0xF5D,
    (u32)gUnk_0813EDFC, (u32)gUnk_0815E024, 0, (u32)gUnk_0812FE5C,
    (u32)gUnk_08145D84, 0, (u32)gUnk_081428DC, 0, (u32)gUnk_0812DF70,
    (u32)gUnk_08142ADC, (u32)gUnk_08142ADC, 0x7D, 0x64, 0x7D, 0x64, 0, 0,
    (u32)gUnk_0828BA60, (u32)gUnk_0828DD4C, 0, 0, 0, 0, 0x194D0F75, 0x1176,
    (u32)gUnk_08178110, (u32)gUnk_0818F958, 0, (u32)gUnk_081698F0,
    (u32)gUnk_0817E918, 0, (u32)gUnk_08166024, 0, (u32)gUnk_08166224,
    (u32)gUnk_0817C190, (u32)gUnk_0817C190, 0x9B, 0x5A, 0x9B, 0x5A, 0, 0,
    (u32)gUnk_0828F52C, (u32)gUnk_082914A0, 0, 0, 0, 0, 0x13C31B66, 0xFBA,
    (u32)gUnk_081A34C8, (u32)gUnk_081B4F24, 0, (u32)gUnk_08198DC8,
    (u32)gUnk_081A7164, 0, (u32)gUnk_08197518, 0, (u32)gUnk_08197718,
    (u32)gUnk_081A4B88, (u32)gUnk_081A4B88, 0x7D, 0x64, 0x7D, 0x64, 0, 0,
    (u32)gUnk_08292650, (u32)gUnk_08293548, 0, 0, 0, 0, 0x12EC0B58, 0x77C,
    (u32)gUnk_081C515C, (u32)gUnk_081C9BC8, 0, (u32)gUnk_081C317C,
    (u32)gUnk_081C7EA8, 0, (u32)gUnk_081C6ADC, 0, (u32)gUnk_081BCEE4,
    (u32)gUnk_081C6CDC, (u32)gUnk_081C6CDC, 0x7D, 0x64, 0x7D, 0x64, 0, 0, 0, 0,
    0, 0, 0, 0, 0x8E6314C, 0, (u32)gUnk_081DECC8, (u32)gUnk_081F8744, 0,
    (u32)gUnk_081CDE68, (u32)gUnk_081E4A64, 0, (u32)gUnk_081CB608, 0,
    (u32)gUnk_081CB808, (u32)gUnk_081E2188, (u32)gUnk_081E2188, 0x7D, 0x64,
    0x7D, 0x64, 0, 0, (u32)gUnk_082939A8, (u32)gUnk_08295820, 0, 0, 0, 0,
    0x146D132F, 0xF3B, (u32)gUnk_0820E234, (u32)gUnk_08228880, 0,
    (u32)gUnk_08203A14, (u32)gUnk_08215980, 0, (u32)gUnk_08200444, 0,
    (u32)gUnk_08200644, (u32)gUnk_082121D4, (u32)gUnk_082121D4, 0xBA, 0x6A,
    0xBA, 0x6A, 0, 0, (u32)gUnk_08296A30, (u32)gUnk_08298BE4, 0, 0, 0, 0,
    0x1BD619E8, 0x10DA, (u32)gUnk_0823F128, (u32)gUnk_08253884, 0,
    (u32)gUnk_08231DC8, (u32)gUnk_08244C24, 0, (u32)gUnk_08242CA8, 0,
    (u32)gUnk_082307A0, (u32)gUnk_08242EA8, (u32)gUnk_08242EA8, 0x7D, 0x64,
    0x7D, 0x64, 0, 0, (u32)gUnk_08299AF4, (u32)gUnk_0829B024, 0, 0, 0, 0,
    0xEBD0B14, 0xA97, (u32)gUnk_082683F0, (u32)gUnk_0827AAA8, 0,
    (u32)gUnk_0825D510, (u32)gUnk_0826DE48, 0, (u32)gUnk_0825B764, 0,
    (u32)gUnk_0825B964, (u32)gUnk_0826BC70, (u32)gUnk_0826BC70, 0x7D, 0x6A,
    0x7D, 0x6A, 0, 0, (u32)gUnk_0829C7B4, (u32)gUnk_0829DBB0, 0, 0, 0, 0,
    0x10EB0DD5, 0x9FD
};
