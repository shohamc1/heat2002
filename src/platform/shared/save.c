// The port's save store: the EEPROM the cartridge
// carries, as a file next to the binary, as sa2's sdl2.c backs its flash
// with a.sav (the ReadSaveFile/StoreSaveFile pattern).
//
// The game's save code (src/save/eeprom.c) calls Nintendo's EEPROM_V120
// library (lib/eeprom.c) through the luvdis names ldscript.ld aliases to
// it: sub_08016E38 = IdentifyEeprom, sub_08016EA0 = SetEepromTimerIntr,
// sub_08017000 = ReadEepromDword, sub_080170B8 = ProgramEepromDword,
// sub_0801719C = VerifyEepromDword. The GBA build compiles lib/eeprom.c
// and the alias resolves; the port defines the same names here, backed
// by the file instead of the bit-serial protocol on REG_EEPROM. Nothing
// in this file is compiled into the GBA build.
//
// Size: the game identifies a 4Kbit EEPROM (InitEeprom calls
// sub_08016E38(4), which picks the library's 512-byte configuration),
// and every block the save code addresses stays inside it --
// WriteSaveBlocks' highest one is the options block at byte 0x178
// (0xBC*2), block 0x2F of the 0x40 the 512-byte configuration holds.
//
// Lifetime: ReadSaveFile() runs once in main(), before AgbMain. The
// store is written back after every ProgramEepromDword (the game writes
// only at save screens, a few blocks each), which also covers every
// exit path -- AgbMain never returns, so there is no exit hook to miss.

#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

#include "config.h"
#include "global.h"
#include "platform/platform.h"

// InitEeprom's argument: the 4Kbit configuration (sub_08016E38(4)).
#define EEPROM_SIZE_KBIT 4
#define EEPROM_SIZE_BYTES (EEPROM_SIZE_KBIT * 1024 / 8)
// One EEPROM dword: four halfwords, what Read/Program/Verify move
// (ReadSaveBlocks and WriteSaveBlocks step eight bytes per block).
#define EEPROM_BLOCK_BYTES 8
#define EEPROM_BLOCK_COUNT (EEPROM_SIZE_BYTES / EEPROM_BLOCK_BYTES)
// An erased EEPROM reads all 1 bits.
#define EEPROM_ERASED_BYTE 0xFF

#define SAVEFILE_NAME "nascar-heat.sav"
#define SAVEFILE_TEMP_NAME SAVEFILE_NAME ".tmp"

static u8 eeprom[EEPROM_SIZE_BYTES];
// Set while writes are failing, so one save (several blocks) reports once.
static bool8 saveErrorReported;

bool8 ReadSaveFile(void)
{
    FILE *file = fopen(SAVEFILE_NAME, "rb");
    size_t read;

    // A missing or short file leaves the tail erased, as a blank
    // cartridge would read.
    memset(eeprom, EEPROM_ERASED_BYTE, sizeof(eeprom));
    if (file == NULL)
        return FALSE;
    read = fread(eeprom, 1, sizeof(eeprom), file);
    fclose(file);
    return read == sizeof(eeprom);
}

// Writes a temporary file and renames it over the save, so a failed
// write (full disk, file-size limit) leaves the previous save intact.
bool8 StoreSaveFile(void)
{
    FILE *file = fopen(SAVEFILE_TEMP_NAME, "wb");
    bool8 ok;

    if (file == NULL)
        return FALSE;
    ok = fwrite(eeprom, 1, sizeof(eeprom), file) == sizeof(eeprom);
    ok = (fflush(file) == 0) && ok;
    ok = (fclose(file) == 0) && ok;
    if (ok) {
#ifdef _WIN32
        // rename() refuses to replace an existing file on Windows.
        ok = MoveFileExA(SAVEFILE_TEMP_NAME, SAVEFILE_NAME, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != 0;
#else
        ok = rename(SAVEFILE_TEMP_NAME, SAVEFILE_NAME) == 0;
#endif
    }
    if (!ok)
        remove(SAVEFILE_TEMP_NAME);
    return ok;
}

/* IdentifyEeprom: the library's error code -- 0 when sizeInKbit names a
   configuration it carries. Only InitEeprom calls it, with 4 (the
   512-byte store above); the 64Kbit configuration the library also
   knows would need a bigger file, so it is not accepted here. */
u32 sub_08016E38(u32 sizeInKbit)
{
    if (sizeInKbit == EEPROM_SIZE_KBIT)
        return 0;
    return 1;
}

/* SetEepromTimerIntr: installs the write-timeout timer interrupt. The
   file store cannot time out, so this is a no-op that still reports
   success (the timer and its interrupt never run under PORTABLE). */
u32 sub_08016EA0(u32 timerNo, IntrFunc *timerReg)
{
    (void)timerNo;
    (void)timerReg;
    return 0;
}

/* ReadEepromDword: eight bytes from block blockNo. The library returns
   EEPROM_OUT_OF_RANGE without touching the buffer for a bad block; an
   out-of-range read leaves the destination alone here too (the game
   never passes one). */
void sub_08017000(u16 blockNo, u16 *dest)
{
    u32 i;

    if (blockNo >= EEPROM_BLOCK_COUNT)
        return;
    for (i = 0; i < EEPROM_BLOCK_BYTES / 2; i++)
        dest[i] = eeprom[blockNo * EEPROM_BLOCK_BYTES + 2 * i] |
                  (eeprom[blockNo * EEPROM_BLOCK_BYTES + 2 * i + 1] << 8);
}

/* ProgramEepromDword: eight bytes into block blockNo, then the file.
   The game writes rarely (save screens), so a flush per program is the
   whole write-back policy. */
void sub_080170B8(u16 blockNo, u16 *src)
{
    u32 i;

    if (blockNo >= EEPROM_BLOCK_COUNT)
        return;
    for (i = 0; i < EEPROM_BLOCK_BYTES / 2; i++) {
        eeprom[blockNo * EEPROM_BLOCK_BYTES + 2 * i] = src[i];
        eeprom[blockNo * EEPROM_BLOCK_BYTES + 2 * i + 1] = src[i] >> 8;
    }
    if (StoreSaveFile()) {
        saveErrorReported = FALSE;
    } else if (!saveErrorReported) {
        saveErrorReported = TRUE;
        Platform_ReportSaveError("Could not write " SAVEFILE_NAME ". The game may say the save worked, "
                                 "but this progress will be lost when you quit. The previous save is unchanged.");
    }
}

/* VerifyEepromDword: the library compares and returns
   EEPROM_VERIFY_FAIL on mismatch; the return value only feeds
   WriteSaveBlocks' ignored result, and the file always reads back what
   the last program wrote, so this checks and does nothing else. */
void sub_0801719C(u16 blockNo, u16 *src)
{
    u32 i;

    if (blockNo >= EEPROM_BLOCK_COUNT)
        return;
    for (i = 0; i < EEPROM_BLOCK_BYTES / 2; i++) {
        if (src[i] != (u16)(eeprom[blockNo * EEPROM_BLOCK_BYTES + 2 * i] |
                            (eeprom[blockNo * EEPROM_BLOCK_BYTES + 2 * i + 1] << 8)))
            break;
    }
}
