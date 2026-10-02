// Scripted-input soak harness (issue 5 step 9): drives the hosted build
// from a text script so a sanitizer soak can walk menus and race without
// a person at the keyboard. Host-only; never compiled into the GBA build.
//
// Env variables:
//   INPUT_SCRIPT=<file>  the script; without it the mask stays 0.
//   FRAME_LIMIT=<n>      exit(0) once the frame count reaches n.
//   FRAME_LOG=<n>        print "frame <count>" every n frames (progress).
//
// Script lines, applied in order from frame 0:
//   wait <n>        hold the current mask for n frames
//   press <k>...    OR the named keys into the mask
//   release <k>...  clear the named keys from the mask
//   mask 0x<hex>    set the mask outright
// Key names: A B SELECT START RIGHT LEFT UP DOWN L R (GBA key bits).
// Past the last line the mask holds forever.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "global.h"
#include "platform/shared/soak.h"

typedef struct {
    enum { OP_WAIT, OP_PRESS, OP_RELEASE, OP_MASK } op;
    u32 arg;      /* wait frames / mask value */
    u32 keys;     /* press/release bit set */
} SoakOp;

static SoakOp *ops;
static u32 opCount;
static u32 opIndex;     /* the op being consumed */
static u32 opWaitLeft;  /* frames left on the current wait */
static u16 heldMask;
static u32 frame;
static u32 frameLimit = 0xFFFFFFFF;
static u32 frameLogInterval;

static u32 KeyBits(const char *name)
{
    struct { const char *name; u32 bit; } table[] = {
        { "A", 0x001 }, { "B", 0x002 }, { "SELECT", 0x004 },
        { "START", 0x008 }, { "RIGHT", 0x010 }, { "LEFT", 0x020 },
        { "UP", 0x040 }, { "DOWN", 0x080 }, { "R", 0x100 }, { "L", 0x200 },
    };
    u32 i;

    for (i = 0; i < sizeof(table) / sizeof(table[0]); i++)
        if (strcmp(name, table[i].name) == 0)
            return table[i].bit;
    fprintf(stderr, "soak: unknown key '%s'\n", name);
    exit(2);
    return 0;
}

// The numeric operand of wait/mask: present, and a number to the end.
static u32 NumberArg(const char *opName, u32 lineNo)
{
    const char *tok = strtok(NULL, " \t\r\n");
    char *end;
    unsigned long value;

    if (tok == NULL) {
        fprintf(stderr, "soak: line %u: '%s' needs a number\n", lineNo, opName);
        exit(2);
    }
    value = strtoul(tok, &end, 0);
    if (*end != '\0') {
        fprintf(stderr, "soak: line %u: '%s' is not a number\n", lineNo, tok);
        exit(2);
    }
    return (u32)value;
}

static void LoadScript(const char *path)
{
    FILE *f = fopen(path, "r");
    char line[512];
    u32 cap = 64;
    u32 lineNo = 0;

    if (f == NULL) {
        fprintf(stderr, "soak: cannot open %s\n", path);
        exit(2);
    }
    ops = malloc(cap * sizeof(SoakOp));
    while (fgets(line, sizeof(line), f) != NULL) {
        char *tok;
        SoakOp op = { 0, 0, 0 };

        lineNo++;
        // Blank lines (LF or CRLF) and comments carry no op.
        tok = strtok(line, " \t\r\n");
        if (tok == NULL || tok[0] == '#')
            continue;
        if (strcmp(tok, "wait") == 0) {
            op.op = OP_WAIT;
            op.arg = NumberArg(tok, lineNo);
        } else if (strcmp(tok, "press") == 0 || strcmp(tok, "release") == 0) {
            op.op = tok[0] == 'p' ? OP_PRESS : OP_RELEASE;
            while ((tok = strtok(NULL, " \t\r\n")) != NULL)
                op.keys |= KeyBits(tok);
        } else if (strcmp(tok, "mask") == 0) {
            op.op = OP_MASK;
            op.arg = NumberArg(tok, lineNo);
        } else {
            fprintf(stderr, "soak: unknown op '%s'\n", tok);
            exit(2);
        }
        if (opCount == cap) {
            cap *= 2;
            ops = realloc(ops, cap * sizeof(SoakOp));
        }
        ops[opCount++] = op;
    }
    fclose(f);
}

static void Soak_Init(void)
{
    const char *script = getenv("INPUT_SCRIPT");
    const char *limit = getenv("FRAME_LIMIT");
    const char *log = getenv("FRAME_LOG");

    if (script != NULL)
        LoadScript(script);
    if (limit != NULL)
        frameLimit = (u32)strtoul(limit, NULL, 0);
    if (log != NULL)
        frameLogInterval = (u32)strtoul(log, NULL, 0);
}

u16 Soak_Advance(void)
{
    static u8 inited;

    if (!inited) {
        inited = TRUE;
        Soak_Init();
    }

    // Called at the start of each frame: stop before frame number
    // frameLimit, so FRAME_LIMIT=n runs exactly n frames.
    if (frame >= frameLimit) {
        fflush(stdout);
        exit(0);
    }

    /* Consume waits and apply ops until the frame's mask is decided. */
    for (;;) {
        if (opIndex >= opCount)
            break;
        if (ops[opIndex].op == OP_WAIT) {
            if (opWaitLeft == 0)
                opWaitLeft = ops[opIndex].arg;
            if (opWaitLeft == 0) {
                opIndex++;
                continue;
            }
            opWaitLeft--;
            if (opWaitLeft == 0)
                opIndex++;
            break;
        }
        switch (ops[opIndex].op) {
        case OP_PRESS:
            heldMask |= ops[opIndex].keys;
            break;
        case OP_RELEASE:
            heldMask &= ~ops[opIndex].keys;
            break;
        case OP_MASK:
            heldMask = ops[opIndex].arg;
            break;
        default:
            break;
        }
        opIndex++;
    }

    if (frameLogInterval != 0 && frame % frameLogInterval == 0) {
        printf("frame %u\n", frame);
        fflush(stdout);
    }
    frame++;
    return heldMask;
}
