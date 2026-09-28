#include "global.h"

extern const u8 *const gGameTexts[];

const u8 *GetString(u16 idx) { return gGameTexts[idx]; }
