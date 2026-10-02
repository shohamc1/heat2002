#ifndef GUARD_PLATFORM_CONFIG_H
#define GUARD_PLATFORM_CONFIG_H

// Platform-layer switches, after sa2's include/config.h. The game build
// never includes this header; only src/platform/ does, so it can key on
// the host freely.

// The one renderer the port links: the gpSP-derived software renderer
// (src/platform/shared/video/gpsp_renderer.cc).
#define RENDERER_SOFTWARE 0
#define RENDERER_OPENGL   1
#define RENDERER          RENDERER_SOFTWARE

// SA2's VRAM debug view window is not ported.
#define ENABLE_VRAM_VIEW 0

// 240x160, plain OAM: our include/gba/defines.h sizes VRAM/OAM for the
// real hardware, so the renderer's EXTENDED_OAM paths stay off.
#define EXTENDED_OAM 0

#endif // GUARD_PLATFORM_CONFIG_H
