// After sa2's src/platform/shared/input.c with the win32 half dropped:
// that file held only GetXInputKeys() under #ifdef _WIN32. Keyboard
// state lives in src/platform/pret_sdl/sdl2.c (Platform_GetKeyInput);
// this translation unit keeps the shared/input.h mapping in place for
// a future platform that wants gamepad input.
#include "platform/shared/input.h"
