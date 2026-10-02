// SDL2 platform layer, after sa2's src/platform/pret_sdl/sdl2.c.
//
// Adapted for this project (issue 5 step 5):
//   - 240x160: DISPLAY_WIDTH/DISPLAY_HEIGHT come from include/gba/defines.h,
//     which fixes the GBA's real resolution (sa2 widens to 426x240).
//   - The win32, PSP and VRAM-view halves are dropped; the save file is
//     sa2's pattern on this ROM's EEPROM instead of flash: main() loads
//     nascar-heat.sav through ReadSaveFile (step 7,
//     src/platform/shared/save.c), which also backs the EEPROM calls.
//   - cgb_audio_init runs before the queue opens (step 6): the software
//     PSG's duty/noise tables are baked for the 48 kHz rate.
//   - The interrupt slot numbers come from this ROM's crt0 dispatch order
//     (include/platform/shared/video/gpsp_renderer.h), not sa2's.
//   - main() calls this game's AgbMain (src/system/AgbMain.c), which
//     never returns.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL.h>

#include "config.h"
#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"
#include "platform/platform.h"
#include "platform/shared/audio/cgb_audio.h"
#include "platform/shared/dma.h"
#include "platform/shared/input.h"
#include "platform/shared/soak.h"
#include "platform/shared/video/gpsp_renderer.h"

ALIGNED(256) u16 gameImage[DISPLAY_WIDTH * DISPLAY_HEIGHT];

SDL_Window *sdlWindow;
SDL_Renderer *sdlRenderer;
SDL_Texture *sdlTexture;
// The window opens at 3x (720x480), stepping down on a desktop too small
// for it; it stays resizable.
#define INITIAL_VIDEO_SCALE 3
unsigned int videoScale = INITIAL_VIDEO_SCALE;
unsigned int preFullscreenVideoScale = INITIAL_VIDEO_SCALE;

bool8 speedUp = FALSE;
bool8 videoScaleChanged = FALSE;
bool8 isRunning = TRUE;
bool8 paused = FALSE;
bool8 stepOneFrame = FALSE;
bool8 headless = FALSE;

// The GBA's actual refresh rate (platform.h): the frame pacing and the
// audio device's rate both derive from it, so the port runs at the
// hardware's speed rather than 0.45% fast.
#define GBA_FPS PLATFORM_FRAME_RATE

double lastGameTime = 0;
double curGameTime = 0;
double fixedTimestep = 1.0 / GBA_FPS;
double timeScale = 1.0;
double accumulator = 0.0;

void DoSoftReset(void) {};

void ProcessSDLEvents(void);
void VDraw(SDL_Texture *texture);

u16 Platform_GetKeyInput(void);
static void OpenController(int which);
static void HandleControllerEvent(const SDL_Event *event);

int main(int argc, char **argv)
{
    const char *headlessEnv = getenv("HEADLESS");

    if (headlessEnv && strcmp(headlessEnv, "true") == 0) {
        headless = TRUE;
    }

    REG_KEYINPUT = 0x3FF;

    // The save file (step 7): load the EEPROM image before the game can
    // reach it, and create the file on the first run so it exists in its
    // erased state, as a blank cartridge would read.
    if (!ReadSaveFile())
        StoreSaveFile();

    if (headless) {
        AgbMain();
        return 1;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Pads attached before launch arrive without an ADDED event.
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
        if (SDL_IsGameController(i))
            OpenController(i);
    }

    const char *title = "NASCAR Heat 2002";

    {
        SDL_Rect usable;

        if (SDL_GetDisplayUsableBounds(0, &usable) == 0) {
            while (videoScale > 1
                   && (DISPLAY_WIDTH * videoScale > (unsigned)usable.w
                       || DISPLAY_HEIGHT * videoScale > (unsigned)usable.h))
                videoScale--;
        }
        preFullscreenVideoScale = videoScale;
    }

    sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DISPLAY_WIDTH * videoScale,
                                 DISPLAY_HEIGHT * videoScale, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (sdlWindow == NULL) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    if (sdlRenderer == NULL) {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
    SDL_RenderClear(sdlRenderer);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    SDL_RenderSetLogicalSize(sdlRenderer, DISPLAY_WIDTH, DISPLAY_HEIGHT);

    sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ABGR1555, SDL_TEXTUREACCESS_STREAMING, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    if (sdlTexture == NULL) {
        fprintf(stderr, "Texture could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    {
        SDL_AudioSpec want;

        SDL_memset(&want, 0, sizeof(want)); /* or SDL_zero(want) */
        want.freq = PLATFORM_AUDIO_RATE;
        want.format = AUDIO_S16;
        want.channels = 2;
        want.samples = PLATFORM_AUDIO_SAMPLES_PER_FRAME;

        // The software PSG's tables are baked for 48 kHz (step 6, as sa2);
        // this rate is 0.04% above it, a pitch change far below hearing.
        cgb_audio_init(want.freq);

        if (SDL_OpenAudio(&want, 0) < 0) {
            SDL_Log("Failed to open audio: %s", SDL_GetError());
        } else {
            if (want.format != AUDIO_S16) /* we let this one thing change. */
                SDL_Log("We didn't get S16 audio format.");
            SDL_PauseAudio(0);
        }
    }

    VDraw(sdlTexture);
    AgbMain();

    return 0;
}

bool8 newFrameRequested = FALSE;

// called every gba frame. we process sdl events and render as many times
// as vsync needs, then return when a new game frame is needed.
void VBlankIntrWait(void)
{
#define HANDLE_VBLANK_INTRS()                                                    \
    ({                                                                           \
        REG_DISPSTAT |= INTR_FLAG_VBLANK;                                        \
        RunDMAs(DMA_VBLANK);                                                     \
        if (REG_DISPSTAT & DISPSTAT_VBLANK_INTR)                                 \
            gIntrTable[INTR_INDEX_VBLANK]();                                     \
        REG_DISPSTAT &= ~INTR_FLAG_VBLANK;                                       \
    })

    if (headless) {
        static u32 hframe; /* TEMP SHOT: headless frame counter */
        REG_KEYINPUT = KEYS_MASK ^ Soak_Advance();
        REG_VCOUNT = DISPLAY_HEIGHT + 1;
        /* TEMP SHOT: render + dump PPM at the SHOT=csv frame counts */
        {
            static u32 *shots;
            static u32 nshots;
            if (shots == NULL) {
                const char *e = getenv("SHOT");
                if (e != NULL) {
                    char *dup = strdup(e), *tok;
                    nshots = 1;
                    for (tok = dup; *tok != '\0'; tok++)
                        if (*tok == ',')
                            nshots++;
                    shots = malloc(nshots * sizeof(u32));
                    nshots = 0;
                    for (tok = strtok(dup, ","); tok != NULL; tok = strtok(NULL, ","))
                        shots[nshots++] = strtoul(tok, NULL, 0);
                    free(dup);
                } else {
                    nshots = 0;
                    shots = (u32 *)-1;
                }
            }
            if (shots != (u32 *)-1) {
                u32 i;
                gpsp_draw_frame(gameImage);
                for (i = 0; i < nshots; i++) {
                    if (shots[i] == hframe) {
                        char name[64];
                        FILE *f;
                        u32 p;
                        snprintf(name, sizeof(name), "/tmp/shot_%06u.ppm", hframe);
                        f = fopen(name, "wb");
                        if (f != NULL) {
                            fprintf(f, "P6\n%u %u\n255\n", DISPLAY_WIDTH, DISPLAY_HEIGHT);
                            for (p = 0; p < DISPLAY_WIDTH * DISPLAY_HEIGHT; p++) {
                                u16 c = gameImage[p];
                                u8 rgb[3];
                                rgb[0] = (u8)(((c & 31) * 255 + 15) / 31);
                                rgb[1] = (u8)((((c >> 5) & 31) * 255 + 15) / 31);
                                rgb[2] = (u8)((((c >> 10) & 31) * 255 + 15) / 31);
                                fwrite(rgb, 1, 3, f);
                            }
                            fclose(f);
                        }
                        /* TEMP MEM: dump IO, PLTT, VRAM, OAM, EWRAM, IWRAM */
                        snprintf(name, sizeof(name), "/tmp/port_mem_%06u.bin", hframe);
                        f = fopen(name, "wb");
                        if (f != NULL) {
                            fwrite(REG_BASE, 1, 0x400, f);
                            fwrite(PLTT, 1, 0x400, f);
                            fwrite(VRAM, 1, 0x18000, f);
                            fwrite(OAM, 1, 0x400, f);
                            fwrite(EWRAM_START, 1, 0x40000, f);
                            fwrite(IWRAM_START, 1, 0x8000, f);
                            fclose(f);
                        }
                        break;
                    }
                }
            }
        }
        hframe++;
        HANDLE_VBLANK_INTRS();
        return;
    }

    bool8 frameAvailable = TRUE;
    bool8 frameDrawn = FALSE;

    while (isRunning) {
        ProcessSDLEvents();

        if (!paused || stepOneFrame) {
            double dt = fixedTimestep / timeScale; // TODO: Fix speedup

            // don't accumulate time if we already requested a new frame
            // this frame cycle (emulates threaded sdl behavior)
            if (!newFrameRequested) {
                double deltaTime = 0;

                curGameTime = SDL_GetPerformanceCounter();
                if (stepOneFrame) {
                    deltaTime = dt;
                } else {
                    deltaTime = (double)((curGameTime - lastGameTime) / (double)SDL_GetPerformanceFrequency());
                    if (deltaTime > (dt * 5))
                        deltaTime = dt * 5;
                }
                lastGameTime = curGameTime;

                accumulator += deltaTime;
            } else {
                newFrameRequested = FALSE;
            }

            while (accumulator >= dt) {
                if (frameAvailable) {
                    // Once per VBlank, as the headless path does: the pass
                    // that only hands control back to the game must not
                    // consume a scripted input step.
                    REG_KEYINPUT = KEYS_MASK ^ (Platform_GetKeyInput() | Soak_Advance());
                    VDraw(sdlTexture);
                    frameAvailable = FALSE;
                    frameDrawn = TRUE;

                    HANDLE_VBLANK_INTRS();

                    accumulator -= dt;
                } else {
                    // Back to the game for one update. A single-frame step
                    // (F10) ends here, once the game has its frame, not
                    // when the VBlank is drawn.
                    newFrameRequested = TRUE;
                    stepOneFrame = FALSE;
                    return;
                }
            }
        }

        // present
        SDL_RenderClear(sdlRenderer);
        SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);

        if (videoScaleChanged) {
            SDL_SetWindowSize(sdlWindow, DISPLAY_WIDTH * videoScale, DISPLAY_HEIGHT * videoScale);
            videoScaleChanged = FALSE;
        }

        SDL_RenderPresent(sdlRenderer);
    }

    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
    exit(0);
#undef HANDLE_VBLANK_INTRS
}

// Modern racing layout: WASD drives (W throttle, S brake/reverse, A/D
// steer), the arrow keys stay the D-pad for the menus, Q/E are the
// shoulders, Enter or Esc pauses and Tab is Select. sa2's legacy
// spellings survive as alternates where they do not collide (C/X for
// A/B; S and D now drive, so the old L/R keys are gone).
#define KEY_A_BUTTON       SDLK_c
#define KEY_A_BUTTON_ALT   SDLK_w
#define KEY_B_BUTTON       SDLK_x
#define KEY_B_BUTTON_ALT   SDLK_s
#define KEY_START_BUTTON   SDLK_RETURN
#define KEY_START_BUTTON_ALT SDLK_ESCAPE
#define KEY_SELECT_BUTTON  SDLK_BACKSLASH
#define KEY_SELECT_BUTTON_ALT SDLK_TAB
#define KEY_L_BUTTON       SDLK_q
#define KEY_R_BUTTON       SDLK_e
#define KEY_DPAD_UP        SDLK_UP
#define KEY_DPAD_DOWN      SDLK_DOWN
#define KEY_DPAD_LEFT      SDLK_LEFT
#define KEY_DPAD_LEFT_ALT  SDLK_a
#define KEY_DPAD_RIGHT     SDLK_RIGHT
#define KEY_DPAD_RIGHT_ALT SDLK_d

// Every key that drives a GBA button, aliases included. The buttons are
// read from the keyboard's held state each frame rather than toggled by
// key events, so releasing one alias leaves the button held while
// another key for it still is.
static const struct {
    SDL_Keycode key;
    u16 button;
} sKeyMap[] = {
    { KEY_A_BUTTON, A_BUTTON },          { KEY_A_BUTTON_ALT, A_BUTTON },
    { KEY_B_BUTTON, B_BUTTON },          { KEY_B_BUTTON_ALT, B_BUTTON },
    { KEY_START_BUTTON, START_BUTTON },  { KEY_START_BUTTON_ALT, START_BUTTON },
    { KEY_SELECT_BUTTON, SELECT_BUTTON }, { KEY_SELECT_BUTTON_ALT, SELECT_BUTTON },
    { KEY_L_BUTTON, L_BUTTON },          { KEY_R_BUTTON, R_BUTTON },
    { KEY_DPAD_UP, DPAD_UP },            { KEY_DPAD_DOWN, DPAD_DOWN },
    { KEY_DPAD_LEFT, DPAD_LEFT },        { KEY_DPAD_LEFT_ALT, DPAD_LEFT },
    { KEY_DPAD_RIGHT, DPAD_RIGHT },      { KEY_DPAD_RIGHT_ALT, DPAD_RIGHT },
};

static u16 KeyboardBits(void)
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    bool8 alt = (SDL_GetModState() & KMOD_ALT) != 0;
    u16 bits = 0;
    unsigned i;

    for (i = 0; i < sizeof(sKeyMap) / sizeof(sKeyMap[0]); i++) {
        // Alt+Enter toggles fullscreen; it is not Start.
        if (alt && sKeyMap[i].key == SDLK_RETURN)
            continue;
        if (state[SDL_GetScancodeFromKey(sKeyMap[i].key)])
            bits |= sKeyMap[i].button;
    }
    return bits;
}

// A gamepad's buttons, held separately from the keyboard bits so both
// can be pressed at once; the analog stick and triggers are polled.
static SDL_GameController *sdlController;
static u16 padButtons;

#define STICK_DEADZONE 11000 // ~1/3 of the axis range

static void OpenController(int which)
{
    if (sdlController == NULL) {
        sdlController = SDL_GameControllerOpen(which);
        if (sdlController != NULL)
            printf("Gamepad: %s\n", SDL_GameControllerName(sdlController));
    }
}

static SDL_JoystickID ControllerInstance(void)
{
    return SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(sdlController));
}

// The open pad was unplugged: drop it and its held buttons, then take
// over any other pad still connected.
static void CloseController(SDL_JoystickID instance)
{
    if (sdlController == NULL || ControllerInstance() != instance)
        return;
    SDL_GameControllerClose(sdlController);
    sdlController = NULL;
    padButtons = 0;
    for (int i = 0; i < SDL_NumJoysticks() && sdlController == NULL; i++) {
        if (SDL_IsGameController(i))
            OpenController(i);
    }
}

static void HandleControllerEvent(const SDL_Event *event)
{
    static const struct { SDL_GameControllerButton button; u16 bit; } padMap[] = {
        { SDL_CONTROLLER_BUTTON_A, A_BUTTON },
        { SDL_CONTROLLER_BUTTON_B, B_BUTTON },
        { SDL_CONTROLLER_BUTTON_LEFTSHOULDER, L_BUTTON },
        { SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, R_BUTTON },
        { SDL_CONTROLLER_BUTTON_DPAD_UP, DPAD_UP },
        { SDL_CONTROLLER_BUTTON_DPAD_DOWN, DPAD_DOWN },
        { SDL_CONTROLLER_BUTTON_DPAD_LEFT, DPAD_LEFT },
        { SDL_CONTROLLER_BUTTON_DPAD_RIGHT, DPAD_RIGHT },
        { SDL_CONTROLLER_BUTTON_START, START_BUTTON },
        { SDL_CONTROLLER_BUTTON_BACK, SELECT_BUTTON },
    };
    unsigned i;

    switch (event->type) {
        case SDL_CONTROLLERDEVICEADDED:
            OpenController(event->cdevice.which);
            break;
        case SDL_CONTROLLERDEVICEREMOVED:
            CloseController(event->cdevice.which);
            break;
        case SDL_CONTROLLERBUTTONDOWN:
        case SDL_CONTROLLERBUTTONUP:
            // Only the open pad drives the game.
            if (sdlController == NULL || event->cbutton.which != ControllerInstance())
                break;
            for (i = 0; i < sizeof(padMap) / sizeof(padMap[0]); i++) {
                if (event->cbutton.button == padMap[i].button) {
                    if (event->type == SDL_CONTROLLERBUTTONDOWN)
                        padButtons |= padMap[i].bit;
                    else
                        padButtons &= ~padMap[i].bit;
                    break;
                }
            }
            break;
        default:
            break;
    }
}

// The stick steers (deadzone aside) and, as on modern platforms, the
// analog triggers are throttle and brake.
static u16 PadBits(void)
{
    u16 bits = padButtons;
    Sint16 axis;

    if (sdlController == NULL)
        return bits;

    axis = SDL_GameControllerGetAxis(sdlController, SDL_CONTROLLER_AXIS_LEFTX);
    if (axis > STICK_DEADZONE)
        bits |= DPAD_RIGHT;
    else if (axis < -STICK_DEADZONE)
        bits |= DPAD_LEFT;

    axis = SDL_GameControllerGetAxis(sdlController, SDL_CONTROLLER_AXIS_LEFTY);
    if (axis > STICK_DEADZONE)
        bits |= DPAD_DOWN;
    else if (axis < -STICK_DEADZONE)
        bits |= DPAD_UP;

    if (SDL_GameControllerGetAxis(sdlController, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > STICK_DEADZONE)
        bits |= A_BUTTON;
    if (SDL_GameControllerGetAxis(sdlController, SDL_CONTROLLER_AXIS_TRIGGERLEFT) > STICK_DEADZONE)
        bits |= B_BUTTON;

    return bits;
}

u32 fullScreenFlags = 0;
static SDL_DisplayMode sdlDispMode = { 0 };

void Platform_QueueAudio(const s16 *data, u32 bytesCount)
{
    if (headless) {
        return;
    }
    // Reset the audio buffer if we are 10 frames out of sync
    // If this happens it suggests there was some OS level lag
    // in playing audio. The queue length should remain stable at < 10 otherwise
    if (SDL_GetQueuedAudioSize(1) > (bytesCount * 10)) {
        SDL_ClearQueuedAudio(1);
    }

    SDL_QueueAudio(1, data, bytesCount);
}

void ProcessSDLEvents(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        SDL_Keycode keyCode;
        Uint16 keyMod;

        HandleControllerEvent(&event);

        keyCode = event.key.keysym.sym;
        keyMod = event.key.keysym.mod;

        switch (event.type) {
            case SDL_QUIT:
                isRunning = FALSE;
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
                        if (speedUp) {
                            speedUp = FALSE;
                            timeScale = 1.0;
                            SDL_ClearQueuedAudio(1);
                            SDL_PauseAudio(0);
                        }
                        break;
                }
                break;
            case SDL_KEYDOWN:
                // Holding a toggle past the repeat delay must not flip it
                // again (fullscreen, pause, reset).
                if (event.key.repeat
                    && ((keyCode == SDLK_RETURN && (keyMod & KMOD_ALT))
                        || ((keyCode == SDLK_p || keyCode == SDLK_r) && (keyMod & (KMOD_LCTRL | KMOD_RCTRL)))))
                    break;
                if (keyCode == SDLK_RETURN && (keyMod & KMOD_ALT)) {
                    fullScreenFlags ^= SDL_WINDOW_FULLSCREEN_DESKTOP;
                    if (fullScreenFlags & SDL_WINDOW_FULLSCREEN_DESKTOP) {
                        SDL_GetWindowDisplayMode(sdlWindow, &sdlDispMode);
                        preFullscreenVideoScale = videoScale;
                    } else {
                        SDL_SetWindowDisplayMode(sdlWindow, &sdlDispMode);
                        videoScale = preFullscreenVideoScale;
                    }
                    SDL_SetWindowFullscreen(sdlWindow, fullScreenFlags);

                    SDL_SetWindowSize(sdlWindow, DISPLAY_WIDTH * videoScale, DISPLAY_HEIGHT * videoScale);
                    videoScaleChanged = FALSE;
                } else
                    switch (event.key.keysym.sym) {
                        case SDLK_r:
                            if (event.key.keysym.mod & (KMOD_LCTRL | KMOD_RCTRL)) {
                                DoSoftReset();
                            }
                            break;
                        case SDLK_p:
                            if (event.key.keysym.mod & (KMOD_LCTRL | KMOD_RCTRL)) {
                                paused = !paused;
                            }
                            break;
                        case SDLK_SPACE:
                            if (!speedUp) {
                                speedUp = TRUE;
                                timeScale = SPEEDUP_SCALE;
                                SDL_PauseAudio(1);
                            }
                            break;
                        case SDLK_F10:
                            paused = TRUE;
                            stepOneFrame = TRUE;
                            break;
                    }
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                    unsigned int w = event.window.data1;
                    unsigned int h = event.window.data2;

                    videoScale = 0;
                    if (w / DISPLAY_WIDTH > videoScale)
                        videoScale = w / DISPLAY_WIDTH;
                    if (h / DISPLAY_HEIGHT > videoScale)
                        videoScale = h / DISPLAY_HEIGHT;
                    if (videoScale < 1)
                        videoScale = 1;

                    videoScaleChanged = TRUE;
                }
                break;
        }
    }
}

void Platform_ReportSaveError(const char *message)
{
    fprintf(stderr, "error: %s\n", message);
    if (!headless)
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Save failed", message, sdlWindow);
}

u16 Platform_GetKeyInput(void)
{
    return KeyboardBits() | PadBits();
}

void VDraw(SDL_Texture *texture)
{
    gpsp_draw_frame(gameImage);
    SDL_UpdateTexture(texture, NULL, gameImage, DISPLAY_WIDTH * sizeof(Uint16));
    REG_VCOUNT = DISPLAY_HEIGHT + 1; // prep for being in VBlank period
}
