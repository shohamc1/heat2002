#include "global.h"

// A stub in the retail build: callers still set up the argument
// (a string pointer from gUiFontTable), so it keeps an unused parameter.
void DummyUiFontLoad(const u8 *fontRow)
{}
