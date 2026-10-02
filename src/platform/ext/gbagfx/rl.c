// Copyright (c) 2016 YamaArashi

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef _MSC_VER

#define FATAL_ERROR(format, ...)                                                                                                           \
    do {                                                                                                                                   \
        fprintf(stderr, format, __VA_ARGS__);                                                                                              \
        exit(1);                                                                                                                           \
    } while (0)

#define UNUSED

#else

#define FATAL_ERROR(format, ...)                                                                                                           \
    do {                                                                                                                                   \
        fprintf(stderr, format, ##__VA_ARGS__);                                                                                            \
        exit(1);                                                                                                                           \
    } while (0)

#define UNUSED __attribute__((__unused__))

#endif // _MSC_VER

/* Stops once the header's size is written, as the GBA BIOS RLUnComp
   does: a run that overshoots it is cut short, not an error. The ROM
   relies on this; one skid-smoke frame (0x08330C90) declares 32 bytes
   and encodes 160. */
void RLDecompressUnsafe(unsigned char *src, unsigned char *dest, int *uncompressedSize)
{
    int destSize = (src[3] << 16) | (src[2] << 8) | src[1];

    if (dest == NULL)
        goto fail;

    int srcPos = 4;
    int destPos = 0;

    while (destPos < destSize) {
        unsigned char flags = src[srcPos++];
        bool compressed = ((flags & 0x80) != 0);

        if (compressed) {
            int length = (flags & 0x7F) + 3;
            unsigned char data = src[srcPos++];

            for (int i = 0; i < length && destPos < destSize; i++)
                dest[destPos++] = data;
        } else {
            int length = (flags & 0x7F) + 1;

            for (int i = 0; i < length && destPos < destSize; i++)
                dest[destPos++] = src[srcPos++];
        }
    }
    *uncompressedSize = destSize;
    return;

fail:
    FATAL_ERROR("Fatal error while decompressing RL file.\n");
}
