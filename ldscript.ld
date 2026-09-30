ENTRY(rom_entry)

/* Linker-level data newlib needs. */
errno = 0x0202F244;
end = 0x0202F248;

/* Game code and the remaining asm call libgcc's main copy by its luvdis
   names; the high module's copy is renamed in the Makefile. */
sub_08017230 = __divsi3;
sub_080172C8 = __modsi3;

/* Game code and the remaining asm call newlib by its luvdis names. */
sub_08017594 = sprintf;
sub_0801AF74 = strcmp;
sub_0801AFD0 = strlen;
sub_0801B52C = __errno;
sub_0801B564 = abort;

/* Game code calls the MultiBoot library by its luvdis names. */
sub_0800EA64 = MultiBootInit;
sub_0800EAA0 = MultiBootMain;
sub_0800EEFC = MultiBootStartMaster;
sub_0800EFC0 = MultiBootCheckComplete;

/* Game code calls the EEPROM library by its luvdis names. Its RAM is
   declared extern in lib/eeprom.c and fixed here. */
sub_08016E38 = IdentifyEeprom;
sub_08016EA0 = SetEepromTimerIntr;
sub_08017000 = ReadEepromDword;
sub_080170B8 = ProgramEepromDword;
sub_0801719C = VerifyEepromDword;
timer_No = 0x02000494;
timer_Count = 0x02000496;
timeoutFlag = 0x02000498;
timerReg = 0x0200049C;
shelt_ime = 0x020004A0;
gEEPROMConfig = 0x0202F240;

/* include/gba/compat.h maps pokeemerald-style CpuSet/CpuFastSet/RLUnCompVram
   calls onto these names with u32 prototypes; they are libagbsyscall's. */
sub_08016E0C = CpuFastSet;
sub_08016E10 = CpuSet;
sub_08016E28 = RLUnCompVram;

/* lib/m4a_1.s calls into m4a.c and reads the driver's tables. The high
   module's copy is bound to its own twins in the Makefile (M4A_HIGH_EXTERNS). */
SoundMainRAM_Buffer = 0x03007000;

SECTIONS
{
    /* arm/syscalls.o's statics, in EWRAM; no bytes in the ROM */
    .bss_multiboot 0x0200048C (NOLOAD) :
    {
        build/lib/multiboot.o(.bss);
    }
    .bss 0x020004A8 (NOLOAD) :
    {
        build/lib/newlib/arm/syscalls.o(.bss);
    }
    .bss_libgcc 0x02000558 (NOLOAD) :
    {
        build/lib/libgcc/dp-bit.o(.bss);
        build/lib/libgcc/fp-bit.o(.bss);
    }
    /* gVBlankWorkPhase: defined in sub_0800306C.c, placed at its original
       address (phase-6 mechanism proof; NOLOAD, so no ROM bytes). */
    .bss_sub_0800306C 0x020021B8 (NOLOAD) :
    {
        build/src/system/MainVBlankCallback.o(ewram_data)
    }
    . = 0x08000000;
    rom_entry = .;
    .text : ALIGN(4)
    {
        build/lib/rom_header.o(.text);
        build/lib/crt0.o(.text);
        build/src/system/AgbMain.o(.text*);
        build/src/dead/sub_08000214.o(.text*);
        build/src/link/SetLinkSerialIntr.o(.text*);
        build/src/system/vblank.o(.text*);
        build/src/dead/sub_08000478.o(.text*);
        build/src/system/ReadKeys.o(.text*);
        build/lib/m4a/m4a_1.o(.text);
        build/src/sound/MidiKeyToFreq.o(.text*);
        build/src/dead/sub_08001130.o(.text*);
        build/src/sound/m4a_main.o(.text*);
        build/src/dead/sub_08001234.o(.text*);
        build/src/sound/m4a_song.o(.text*);
        build/src/dead/sub_0800133C.o(.text*);
        build/src/sound/m4aMPlayFadeOut.o(.text*);
        build/src/dead/sub_080013B0.o(.text*);
        build/src/sound/MPlayExtender.o(.text*);
        build/src/dead/sub_0800151C.o(.text*);
        build/src/sound/m4a_clear.o(.text*);
        build/src/sound/m4a_init.o(.text*);
        build/src/dead/sub_0800177C.o(.text*);
        build/src/sound/m4a_vsync.o(.text*);
        build/src/sound/m4a_mplay.o(.text*);
        build/src/sound/FadeOutBody.o(.text*);
        build/src/sound/TrkVolPitSet.o(.text*);
        build/src/sound/cgb_sound.o(.text*);
        build/src/dead/sub_080020CC.o(.text*);
        build/src/sound/m4aMPlayPitchControl.o(.text*);
        build/src/dead/sub_080021D0.o(.text*);
        build/src/sound/ply_xcmd.o(.text*);
        build/src/system/random.o(.text*);
        build/src/dead/sub_08002618.o(.text*);
        build/src/system/GameMain.o(.text*);
        build/src/track/SetTrackBgCnt.o(.text*);
        build/src/race/EnableRaceDisplay.o(.text*);
        build/src/sound/StopAllSongsAtRaceStart.o(.text*);
        build/src/race/RunRace.o(.text*);
        build/src/system/MainVBlankCallback.o(.text*);
        build/src/dead/sub_080031B0.o(.text*);
        build/src/link/link_keys.o(.text*);
        build/src/dead/sub_080032AC.o(.text*);
        build/src/link/ExchangeLinkInput.o(.text*);
        build/src/link/StartSinglePakLink.o(.text*);
        build/src/track/track.o(.text*);
        build/src/dead/sub_08003C78.o(.text*);
        build/src/track/FlushTilemapBuffer.o(.text*);
        build/src/dead/sub_08003D6C.o(.text*);
        build/src/track/FlushTrackBgBuffers.o(.text*);
        build/src/dead/LoadFadePalette.o(.text*);
        build/src/palette/fade_begin.o(.text*);
        build/src/palette/fade.o(.text*);
        build/src/camera/camera.o(.text*);
        build/src/sprite/oam.o(.text*);
        build/src/dead/sub_08004504.o(.text*);
        build/src/dead/sub_08004568.o(.text*);
        build/src/sprite/sprite_update.o(.text*);
        build/src/hud/track_cues.o(.text*);
        build/src/menu/ClearPauseMenuBox.o(.text*);
        build/src/dead/sub_08004A50.o(.text*);
        build/src/dead/sub_08004A7C.o(.text*);
        build/src/menu/pause_menu_draw.o(.text*);
        build/src/dead/sub_08004DB0.o(.text*);
        build/src/link/ReadLinkMenuKeys.o(.text*);
        build/src/dead/sub_08004E58.o(.text*);
        build/src/menu/PauseMenu.o(.text*);
        build/src/link/pause_menu.o(.text*);
        build/src/dead/sub_08005330.o(.text*);
        build/src/hud/DrawTime.o(.text*);
        build/src/link/WaitForLinkRestart.o(.text*);
        build/src/hud/DrawLinkFinishTimes.o(.text*);
        build/src/race/timers.o(.text*);
        build/src/race/records.o(.text*);
        build/src/dead/sub_080057E8.o(.text*);
        build/src/hud/digits.o(.text*);
        build/src/dead/sub_080058FC.o(.text*);
        build/src/hud/hud.o(.text*);
        build/src/dead/sub_08005FA8.o(.text*);
        build/src/hud/UpdateRaceHud.o(.text*);
        build/src/hud/ClearTextLayer.o(.text*);
        build/src/hud/InitRaceHud.o(.text*);
        build/src/dead/sub_080063AC.o(.text*);
        build/src/hud/text.o(.text*);
        build/src/dead/sub_080064F8.o(.text*);
        build/src/hud/DrawBigText.o(.text*);
        build/src/hud/DummyUiFontLoad.o(.text*);
        build/src/dead/sub_08006738.o(.text*);
        build/src/hud/DrawTextCenteredHighlight.o(.text*);
        build/src/dead/sub_080069D8.o(.text*);
        build/src/track/LoadTrackSegs.o(.text*);
        build/src/race/UpdateLapProgress.o(.text*);
        build/src/sprite/gfx_cache.o(.text*);
        build/src/task/task.o(.text*);
        build/src/dead/sub_080079A0.o(.text*);
        build/src/race/pit.o(.text*);
        build/src/dead/sub_08007A44.o(.text*);
        build/src/race/grid.o(.text*);
        build/src/car/UpdateCarSurface.o(.text*);
        build/src/race/pit_menu.o(.text*);
        build/src/dead/sub_08008160.o(.text*);
        build/src/car/setup.o(.text*);
        build/src/car/tire_grip.o(.text*);
        build/src/dead/sub_0800847C.o(.text*);
        build/src/car/tire_forces.o(.text*);
        build/src/dead/sub_080089EC.o(.text*);
        build/src/race/drivers.o(.text*);
        build/src/race/challenge.o(.text*);
        build/src/race/pitstop.o(.text*);
        build/src/car/InitCar.o(.text*);
        build/src/dead/sub_08009B1C.o(.text*);
        build/src/race/UpdateRacePosition.o(.text*);
        build/src/dead/sub_08009BA4.o(.text*);
        build/src/camera/WorldToScreen.o(.text*);
        build/src/dead/sub_08009C00.o(.text*);
        build/src/car/DrawCar.o(.text*);
        build/src/car/DrawAllCars.o(.text*);
        build/src/hud/DrawLinkMarker.o(.text*);
        build/src/dead/sub_0800A008.o(.text*);
        build/src/car/engine.o(.text*);
        build/src/race/RecordFinishTime.o(.text*);
        build/src/dead/sub_0800A470.o(.text*);
        build/src/dead/sub_0800A478.o(.text*);
        build/src/dead/sub_0800A4D4.o(.text*);
        build/src/car/StopCar.o(.text*);
        build/src/dead/sub_0800A5E4.o(.text*);
        build/src/car/update.o(.text*);
        build/src/race/end.o(.text*);
        build/src/dead/sub_0800B030.o(.text*);
        build/src/race/splash.o(.text*);
        build/src/dead/sub_0800B1A4.o(.text*);
        build/src/race/start.o(.text*);
        build/src/race/lap_time.o(.text*);
        build/src/race/record_tasks.o(.text*);
        build/src/dead/sub_0800B5F4.o(.text*);
        build/src/car/particles.o(.text*);
        build/src/dead/sub_0800BA0C.o(.text*);
        build/src/car/DummyCarHitHook.o(.text*);
        build/src/dead/sub_0800BA38.o(.text*);
        build/src/dead/sub_0800BAFC.o(.text*);
        build/src/hud/DrawSpriteText.o(.text*);
        build/src/dead/sub_0800BBDC.o(.text*);
        build/src/car/lane.o(.text*);
        build/src/dead/sub_0800C0F8.o(.text*);
        build/src/car/WorldToCarLocal.o(.text*);
        build/src/car/CheckDrafting.o(.text*);
        build/src/dead/sub_0800C21C.o(.text*);
        build/src/car/ai_driver.o(.text*);
        build/src/dead/sub_0800C98C.o(.text*);
        build/src/system/Atan2.o(.text*);
        build/src/dead/sub_0800CB5C.o(.text*);
        build/src/track/GetTrackTileType.o(.text*);
        build/src/dead/sub_0800CC00.o(.text*);
        build/src/track/walls.o(.text*);
        build/src/car/TestCornersVsWalls.o(.text*);
        build/src/dead/TestSegmentVsWalls.o(.text*);
        build/src/dead/BounceOffWalls.o(.text*);
        build/src/car/CollideCarWithWalls.o(.text*);
        build/src/car/collide.o(.text*);
        build/src/dead/CallFunc.o(.text*);
        build/src/link/multiboot.o(.text*);
        build/src/link/sio.o(.text*);
        build/src/link/SioTransferIntr.o(.text*);
        build/src/car/DummyCarDamageHook.o(.text*);
        build/src/dead/sub_0800E70C.o(.text*);
        build/src/menu/DummyMainMenuHook.o(.text*);
        build/src/dead/sub_0800E734.o(.text*);
        /* MultiBoot, from lib/multiboot.c */
        build/lib/multiboot.o(.text);
        build/src/car/GetDriverName.o(.text*);
        build/src/menu/championship.o(.text*);
        build/src/palette/BuildScreenPalette.o(.text*);
        build/src/hud/ZeroTextLayer.o(.text*);
        build/src/race/SortCarsByTime.o(.text*);
        build/src/menu/backdrop.o(.text*);
        build/src/menu/credits.o(.text*);
        build/src/link/serial.o(.text*);
        build/src/dead/sub_0800F8CC.o(.text*);
        build/src/race/SetupChallenge.o(.text*);
        build/src/sound/stop_songs.o(.text*);
        build/src/sprite/DrawCachedSprite.o(.text*);
        build/src/dead/sub_08010134.o(.text*);
        build/src/sprite/Draw64x64Sprite.o(.text*);
        build/src/dead/sub_080101BC.o(.text*);
        build/src/sprite/Draw32x32Sprite.o(.text*);
        build/src/system/wait.o(.text*);
        build/src/menu/boot_splash.o(.text*);
        build/src/dead/sub_0801037C.o(.text*);
        build/src/menu/main_menu.o(.text*);
        build/src/dead/sub_0801067C.o(.text*);
        build/src/menu/metatile.o(.text*);
        build/src/dead/sub_08010714.o(.text*);
        build/src/palette/color_cycle.o(.text*);
        build/src/dead/sub_080107DC.o(.text*);
        build/src/link/LinkTrackSelect.o(.text*);
        build/src/dead/sub_080109C0.o(.text*);
        build/src/menu/team_select.o(.text*);
        build/src/menu/driver_select.o(.text*);
        build/src/link/race_summary.o(.text*);
        build/src/link/post_race_menu.o(.text*);
        build/src/link/link_state.o(.text*);
        build/src/palette/RgbFromPercent.o(.text*);
        build/src/menu/LoadMenuScreen.o(.text*);
        build/src/dead/sub_08011D2C.o(.text*);
        build/src/menu/menu_move.o(.text*);
        build/src/link/multiplayer_menu.o(.text*);
        build/src/link/link_lobby.o(.text*);
        build/src/dead/sub_08012354.o(.text*);
        build/src/save/InitNewSaveData.o(.text*);
        build/src/menu/DrawOptionsMenu.o(.text*);
        build/src/menu/OptionsMenu.o(.text*);
        build/src/dead/sub_0801264C.o(.text*);
        build/src/menu/championship_qualify.o(.text*);
        build/src/menu/challenge_complete.o(.text*);
        build/src/menu/message_box.o(.text*);
        build/src/menu/challenge_result.o(.text*);
        build/src/race/GetPlayerStanding.o(.text*);
        build/src/menu/trophy.o(.text*);
        build/src/dead/sub_08012DE4.o(.text*);
        build/src/menu/season_menu.o(.text*);
        build/src/dead/sub_080139F0.o(.text*);
        build/src/race/SortCarsByPoints.o(.text*);
        build/src/menu/results.o(.text*);
        build/src/race/AwardAllRacePoints.o(.text*);
        build/src/menu/StandingsScreen.o(.text*);
        build/src/dead/sub_0801435C.o(.text*);
        build/src/menu/time_trial.o(.text*);
        build/src/dead/sub_08014584.o(.text*);
        build/src/menu/challenge_select.o(.text*);
        build/src/dead/sub_08014944.o(.text*);
        build/src/menu/new_game_load.o(.text*);
        build/src/dead/sub_08014B14.o(.text*);
        build/src/menu/single_race_results.o(.text*);
        build/src/dead/sub_08014ED0.o(.text*);
        build/src/menu/single_race_retry_menu.o(.text*);
        build/src/dead/sub_08014FD0.o(.text*);
        build/src/menu/ResetBgScroll.o(.text*);
        build/src/menu/MainMenuLoop.o(.text*);
        build/src/dead/sub_08016330.o(.text*);
        build/src/link/LinkFailScreen.o(.text*);
        build/src/hud/GetString.o(.text*);
        build/src/dead/sub_08016568.o(.text*);
        build/src/save/eeprom.o(.text*);
        build/src/save/save.o(.text*);
        build/src/system/RandomInRange.o(.text*);
        build/src/hud/SplitMilliseconds.o(.text*);
        build/src/race/RandomizeAiFinishTimes.o(.text*);
        build/src/dead/sub_08016CF8.o(.text*);
        build/src/race/finish_times.o(.text*);
        /* libagbsyscall, from lib/libagbsyscall.s */
        build/lib/agbsyscall/CpuFastSet.o(.text);
        build/lib/agbsyscall/CpuSet.o(.text);
        build/lib/agbsyscall/IntrWait.o(.text);
        build/lib/agbsyscall/LZ77UnCompVram.o(.text);
        build/lib/agbsyscall/MultiBoot.o(.text);
        build/lib/agbsyscall/RLUnCompVram.o(.text);
        build/lib/agbsyscall/RegisterRamReset.o(.text);
        build/lib/agbsyscall/VBlankIntrWait.o(.text);
        /* EEPROM_V120, from lib/eeprom.c */
        build/lib/eeprom.o(.text);
        /* libgcc, built from tools/agbcc/libgcc (see the Makefile) */
        build/lib/libgcc/_call_via_rX.o(.text);
        build/lib/libgcc/_divsi3.o(.text);
        build/lib/libgcc/_dvmd_tls.o(.text);
        build/lib/libgcc/_modsi3.o(.text);
        build/lib/libgcc/_muldi3.o(.text);
        build/lib/libgcc/_negdi2.o(.text);
        build/lib/libgcc/_udivsi3.o(.text);
        build/lib/libgcc/_umodsi3.o(.text);
        /* newlib, built from tools/agbcc/libc (see the Makefile) */
        build/lib/newlib/stdio/sprintf.o(.text);
        build/lib/newlib/stdio/vfprintf.o(.text);
        build/lib/newlib/stdio/wsetup.o(.text);
        build/lib/newlib/stdlib/dtoa.o(.text);
        build/lib/newlib/stdio/fflush.o(.text);
        build/lib/newlib/stdio/findfp.o(.text);
        build/lib/newlib/stdlib/freer.o(.text);
        build/lib/newlib/stdio/fvwrite.o(.text);
        build/lib/newlib/stdio/fwalk.o(.text);
        build/lib/newlib/locale/locale.o(.text);
        build/lib/newlib/stdio/makebuf.o(.text);
        build/lib/newlib/stdlib/mallocr.o(.text);
        build/lib/newlib/stdlib/mbtowc_r.o(.text);
        build/lib/newlib/string/memchr.o(.text);
        build/lib/newlib/string/memcpy.o(.text);
        build/lib/newlib/string/memmove.o(.text);
        build/lib/newlib/string/memset.o(.text);
        build/lib/newlib/stdlib/mlock.o(.text);
        build/lib/newlib/stdlib/mprec.o(.text);
        build/lib/newlib/math/s_isinf.o(.text);
        build/lib/newlib/math/s_isnan.o(.text);
        build/lib/newlib/reent/sbrkr.o(.text);
        build/lib/newlib/stdio/stdio.o(.text);
        build/lib/newlib/string/strcmp.o(.text);
        build/lib/newlib/string/strlen.o(.text);
        build/lib/newlib/arm/syscalls.o(.text);
        build/lib/newlib/reent/writer.o(.text);
        build/lib/newlib/stdlib/callocr.o(.text);
        build/lib/newlib/reent/closer.o(.text);
        build/lib/newlib/errno/errno.o(.text);
        build/lib/newlib/reent/fstatr.o(.text);
        build/lib/newlib/arm/libcfunc.o(.text);
        build/lib/newlib/reent/lseekr.o(.text);
        build/lib/newlib/reent/readr.o(.text);
        build/lib/libgcc/dp-bit.o(.text);
        build/lib/libgcc/fp-bit.o(.text);
        build/lib/libgcc/_lshrdi3.o(.text);
        build/src/data/rom_0801CD08.o(.rodata);
        build/data/rom_0801CF88.o(.text*);
        build/src/data/rom_0801D018.o(.rodata);
        build/src/data/rom_0801D230.o(.rodata);
        build/data/sound/voicegroups.o(.text*);
        build/data/sound/programmable_wave_samples.o(.text*);
        build/src/sound/tables.o(.rodata);
        build/data/sound/direct_sound_samples.o(.text*);
        build/data/sound/sounds.o(.text*);
        build/src/data/race_text.o(.rodata);
        build/src/data/rom_0806C97C.o(.rodata);
        build/src/data/link_text.o(.rodata);
        build/data/rom_0807CA7C.o(.text*);
        build/src/data/rom_0807CB58.o(.rodata);
        build/data/rom_0807CE30.o(.text*);
        build/src/data/game_text.o(.rodata);
        build/src/data/title_screen.o(.rodata);
        build/src/data/main_menu.o(.rodata);
        build/src/data/boot_splash3.o(.rodata);
        build/data/rom_082B370C.o(.text*);
        build/src/data/strings.o(.rodata);
        build/src/data/licensed_by_nintendo.o(.rodata);
        build/src/data/driver_select.o(.rodata);
        build/data/rom_082BA310.o(.text*);
        build/src/data/menu_backdrop.o(.rodata);
        build/src/data/results_screen.o(.rodata);
        build/data/rom_082F7EE0.o(.text*);
        build/src/data/rom_0830E670.o(.rodata);
        build/data/rom_0830E690.o(.text*);
        build/src/data/rom_0830EC58.o(.rodata);
        build/data/rom_0830EE78.o(.text*);
        build/src/data/trophy_credits.o(.rodata);
        build/src/data/boot_splash1.o(.rodata);
        build/data/rom_0831C850.o(.text*);
        build/src/data/rom_0831D0EC.o(.rodata);
        build/data/rom_0831D10C.o(.text*);
        build/src/data/rom_08330AD4.o(.rodata);
        build/data/rom_08330AF4.o(.text*);
        build/src/data/rom_08330D18.o(.rodata);
        build/data/rom_08330D38.o(.text*);
        build/src/data/rom_08331188.o(.rodata);
        build/data/rom_083311A8.o(.text*);
        build/src/data/rom_08331360.o(.rodata);
        build/data/rom_08331380.o(.text*);
        build/src/data/rom_08331F88.o(.rodata);
        build/src/data/rom_08331FC8.o(.rodata);
        build/src/data/rom_08332BC8.o(.rodata);
        build/data/rom_083378A0.o(.text*);
        build/src/data/rom_08337C20.o(.rodata);
        build/data/rom_08337C40.o(.text*);
        build/src/data/rom_08338788.o(.rodata);
        build/data/rom_083387A8.o(.text*);
        build/src/data/rom_083393C0.o(.rodata);
        build/lib/eeprom.o(.rodata);
        /* newlib .rodata, in link order */
        build/lib/newlib/stdio/vfprintf.o(.rodata);
        build/lib/newlib/stdlib/dtoa.o(.rodata);
        build/lib/newlib/reent/impure.o(.rodata);
        build/lib/newlib/locale/locale.o(.rodata);
        build/lib/newlib/stdlib/mprec.o(.rodata);
        build/lib/newlib/arm/syscalls.o(.rodata);
        /* 256 unused zero bytes before the high module. Nothing reads,
           writes or sends them: the chunk table at 0x0807C9CC starts at
           0x08339780. See "The gap before the high module" in parked.md. */
        . = ALIGN(4) + 0x100;
    }
    /* The high module: the image that the multiboot island receives in
       32 KB chunks and runs from EWRAM. Linked at its run address, stored
       in the ROM right after the main program's .text. */
    .high_module 0x02000D00 : AT(LOADADDR(.text) + SIZEOF(.text))
    {
        build/lib/crt0_high.o(.text);
        build/src/system/ModuleAgbMain.o(.text*);
        build/src/dead/sub_083398D4.o(.text*);
        build/src/link/ModuleSetLinkSerialIntr.o(.text*);
        build/src/system/module_intr.o(.text*);
        build/src/dead/sub_08339B38.o(.text*);
        build/src/system/ModuleReadKeys.o(.text*);
        build/lib/m4a/m4a_1_high.o(.text);
        build/src/sound/ModuleMidiKeyToFreq.o(.text*);
        build/src/dead/sub_0833A7F0.o(.text*);
        build/src/sound/module_m4a.o(.text*);
        build/src/dead/sub_0833A8F4.o(.text*);
        build/src/dead/sub_0833A9C8.o(.text*);
        build/src/sound/ModuleM4aMPlayFadeOut.o(.text*);
        build/src/dead/sub_0833AA70.o(.text*);
        build/src/sound/ModuleMPlayExtender.o(.text*);
        build/src/dead/sub_0833ABDC.o(.text*);
        build/src/sound/module_m4a_clear.o(.text*);
        build/src/sound/module_m4a_init.o(.text*);
        build/src/dead/sub_0833AE3C.o(.text*);
        build/src/sound/module_m4a_vsync.o(.text*);
        build/src/sound/module_m4a_mplay.o(.text*);
        build/src/sound/ModuleFadeOutBody.o(.text*);
        build/src/sound/ModuleTrkVolPitSet.o(.text*);
        build/src/sound/module_cgb_sound.o(.text*);
        build/src/dead/sub_0833B78C.o(.text*);
        build/src/sound/ModuleM4aMPlayPitchControl.o(.text*);
        build/src/dead/sub_0833B890.o(.text*);
        build/src/sound/module_ply_xcmd.o(.text*);
        build/src/dead/sub_0833BC7C.o(.text*);
        build/src/dead/sub_0833BCBC.o(.text*);
        build/src/link/ModuleSortLinkCarsByTime.o(.text*);
        build/src/hud/ModuleGetString.o(.text*);
        build/src/system/ModuleGameMain.o(.text*);
        build/src/track/ModuleSetTrackBgCnt.o(.text*);
        build/src/race/ModuleEnableRaceDisplay.o(.text*);
        build/src/dead/sub_0833BF7C.o(.text*);
        build/src/race/ModuleRunRace.o(.text*);
        build/src/system/ModuleMainVBlankCallback.o(.text*);
        build/src/dead/sub_0833C6F4.o(.text*);
        build/src/link/module_link_keys.o(.text*);
        build/src/dead/sub_0833C7F0.o(.text*);
        build/src/link/module_link_predicates.o(.text*);
        build/src/dead/sub_0833CC7C.o(.text*);
        build/src/track/module_track.o(.text*);
        build/src/dead/sub_0833D070.o(.text*);
        build/src/track/ModuleFlushTrackBgBuffers.o(.text*);
        build/src/dead/sub_0833D0B8.o(.text*);
        build/src/palette/module_fade.o(.text*);
        build/src/dead/sub_0833D53C.o(.text*);
        build/src/camera/module_camera.o(.text*);
        build/src/sprite/module_oam.o(.text*);
        build/src/dead/sub_0833D700.o(.text*);
        build/src/dead/sub_0833D764.o(.text*);
        build/src/sprite/module_sprite_update.o(.text*);
        build/src/dead/sub_0833D9E4.o(.text*);
        build/src/hud/module_track_cues.o(.text*);
        build/src/dead/sub_0833D9F0.o(.text*);
        build/src/link/ModuleReadLinkMenuKeys.o(.text*);
        build/src/dead/sub_0833DAD8.o(.text*);
        build/src/menu/ModulePauseMenu.o(.text*);
        build/src/dead/sub_0833DBE0.o(.text*);
        build/src/link/module_pause_menu.o(.text*);
        build/src/dead/sub_0833DDB0.o(.text*);
        build/src/hud/ModuleDrawTime.o(.text*);
        build/src/dead/sub_0833DE38.o(.text*);
        build/src/link/ModuleWaitForLinkRestart.o(.text*);
        build/src/hud/ModuleDrawLinkFinishTimes.o(.text*);
        build/src/race/module_timers.o(.text*);
        build/src/race/module_records.o(.text*);
        build/src/dead/sub_0833E2E4.o(.text*);
        build/src/hud/module_digits.o(.text*);
        build/src/dead/sub_0833E3F8.o(.text*);
        build/src/hud/module_hud.o(.text*);
        build/src/dead/sub_0833EAA4.o(.text*);
        build/src/hud/module_init_race_hud.o(.text*);
        build/src/dead/sub_0833EE1C.o(.text*);
        build/src/hud/ModuleClearRaceTextLayer.o(.text*);
        build/src/dead/sub_0833EE2C.o(.text*);
        build/src/hud/ModuleText.o(.text*);
        build/src/dead/ModuleDrawTextHighlight.o(.text*);
        build/src/track/ModuleLoadTrackSegs.o(.text*);
        build/src/race/ModuleUpdateLapProgress.o(.text*);
        build/src/sprite/module_gfx_cache.o(.text*);
        build/src/dead/sub_0833FB5C.o(.text*);
        build/src/sprite/module_gfx_request.o(.text*);
        build/src/dead/sub_0833FD2C.o(.text*);
        build/src/sprite/ModuleRequestObjPalette.o(.text*);
        build/src/sprite/ModuleUploadPendingGfx.o(.text*);
        build/src/task/module_task.o(.text*);
        build/src/dead/sub_0833FFF8.o(.text*);
        build/src/race/module_pit.o(.text*);
        build/src/dead/sub_0834009C.o(.text*);
        build/src/race/ModuleBuildStartingGrid.o(.text*);
        build/src/car/ModuleResetCarSurface.o(.text*);
        build/src/dead/sub_083402D8.o(.text*);
        build/src/car/ModuleSetTireGrip.o(.text*);
        build/src/dead/sub_083405EC.o(.text*);
        build/src/car/module_tire_forces.o(.text*);
        build/src/dead/sub_08340B5C.o(.text*);
        build/src/race/module_challenge.o(.text*);
        build/src/dead/sub_0834116C.o(.text*);
        build/src/race/ModuleEnterPit.o(.text*);
        build/src/dead/sub_08341284.o(.text*);
        build/src/car/ModuleInitCar.o(.text*);
        build/src/dead/sub_083415AC.o(.text*);
        build/src/race/ModuleUpdateRacePosition.o(.text*);
        build/src/dead/sub_08341634.o(.text*);
        build/src/camera/ModuleWorldToScreen.o(.text*);
        build/src/dead/sub_08341690.o(.text*);
        build/src/car/module_draw.o(.text*);
        build/src/hud/ModuleDrawLinkMarker.o(.text*);
        build/src/dead/sub_08341A98.o(.text*);
        build/src/car/module_engine.o(.text*);
        build/src/race/ModuleRecordFinishTime.o(.text*);
        build/src/dead/sub_08341F00.o(.text*);
        build/src/dead/sub_08341F08.o(.text*);
        build/src/dead/sub_08341F64.o(.text*);
        build/src/car/ModuleStopCar.o(.text*);
        build/src/dead/sub_08342030.o(.text*);
        build/src/car/module_update.o(.text*);
        build/src/race/module_end.o(.text*);
        build/src/dead/sub_08342948.o(.text*);
        build/src/race/module_splash.o(.text*);
        build/src/dead/sub_08342A14.o(.text*);
        build/src/race/module_start.o(.text*);
        build/src/race/module_lap_time.o(.text*);
        build/src/race/module_record_tasks.o(.text*);
        build/src/dead/sub_08342DC4.o(.text*);
        build/src/car/module_particles.o(.text*);
        build/src/dead/sub_08343110.o(.text*);
        build/src/car/ModuleDummyCarHitHook.o(.text*);
        build/src/dead/sub_0834313C.o(.text*);
        build/src/hud/ModuleDrawSpriteText.o(.text*);
        build/src/car/module_drafting.o(.text*);
        build/src/dead/sub_083432F4.o(.text*);
        build/src/track/ModuleGetTrackTileType.o(.text*);
        build/src/dead/sub_083434AC.o(.text*);
        build/src/track/module_walls.o(.text*);
        build/src/car/ModuleTestCornersVsWalls.o(.text*);
        build/src/dead/sub_083437A0.o(.text*);
        build/src/dead/sub_08343948.o(.text*);
        build/src/car/module_collide_walls.o(.text*);
        build/src/car/module_contact.o(.text*);
        build/src/car/module_collide.o(.text*);
        build/src/dead/sub_08344684.o(.text*);
        build/src/link/module_serial.o(.text*);
        build/src/dead/sub_08344964.o(.text*);
        build/src/link/ModuleLink.o(.text*);
        build/src/dead/sub_08344B5C.o(.text*);
        /* the high module's libagbsyscall copy */
        build/lib/agbsyscall/sub_08344B60.o(.text);
        build/lib/agbsyscall/sub_08344B64.o(.text);
        build/lib/agbsyscall/sub_08344B68.o(.text);
        build/lib/agbsyscall/sub_08344B70.o(.text);
        build/lib/agbsyscall/sub_08344B74.o(.text);
        /* the high module's libgcc copy, renamed (see the Makefile) */
        build/lib/libgcc/high/_call_via_rX.o(.text);
        build/lib/libgcc/high/_divsi3.o(.text);
        build/lib/libgcc/high/_dvmd_tls.o(.text);
        build/lib/libgcc/high/_modsi3.o(.text);
        build/lib/libgcc/high/_muldi3.o(.text);
        build/lib/libgcc/high/_negdi2.o(.text);
        build/lib/libgcc/high/_umodsi3.o(.text);
        build/src/data/rom_08344E68.o(.rodata);
        build/src/sound/module_engine_tables.o(.rodata);
        build/src/data/rom_08345390.o(.rodata);
        build/data/sound/module_sound.o(.text*);
        build/src/sound/module_tables.o(.rodata);
        build/data/sound/module_songs.o(.text*);
        build/src/data/rom_08345730.o(.rodata);
        build/src/data/high_module_text.o(.rodata);
        build/data/rom_08345BF8.o(.text*);
        build/src/data/rom_08353260.o(.rodata);
        build/src/data/career_text.o(.rodata);
        build/data/rom_083537BC.o(.text*);
        build/data/rom_08354010.o(.text*);
        build/src/data/rom_08357FD0.o(.rodata);
        build/data/rom_08358450.o(.text*);
        build/src/data/rom_0835A784.o(.rodata);
        build/data/rom_0835ACD4.o(.text*);
        build/src/data/rom_0835DB70.o(.rodata);
        build/data/rom_0835DC10.o(.text*);
        build/src/data/rom_0835DC38.o(.rodata);
        build/data/rom_0835DCA0.o(.text*);
        build/src/data/rom_0835F440.o(.rodata);
        build/data/rom_0835F444.o(.text*);
        build/src/data/rom_0835F8A0.o(.rodata);
        build/data/rom_0835FB0C.o(.text*);
        build/src/data/rom_0835FBFC.o(.rodata);
        build/data/rom_083600E8.o(.text*);
        build/src/data/rom_08360100.o(.rodata);
        build/data/rom_08360290.o(.text*);
        build/src/data/rom_08363954.o(.rodata);
        build/src/data/rom_08363988.o(.rodata);
        build/src/data/rom_083639A8.o(.rodata);
    }
    /* The multiboot island: the image the main program sends with the
       BIOS MultiBoot call. It runs from the start of EWRAM. */
    .island 0x02000000 : AT(LOADADDR(.high_module) + SIZEOF(.high_module))
    {
        build/data/rom_08363EE8.o(.text*);
        build/lib/crt0_island.o(.text);
        build/src/link/island_intr.o(.text*);
        build/src/link/island_multiboot.o(.text*);
        build/src/link/island_sio.o(.text*);
        build/src/link/IslandSioTransferIntr.o(.text*);
        /* the multiboot island's libagbsyscall copy */
        build/lib/agbsyscall/sub_083647F8.o(.text);
        build/lib/agbsyscall/sub_083647FC.o(.text);
        build/lib/agbsyscall/sub_08364800.o(.text);
        build/lib/agbsyscall/sub_08364804.o(.text);
        build/lib/agbsyscall/sub_08364808.o(.text);
        build/lib/libgcc/island/_call_via_rX.o(.text);
        build/data/rom_0836484C.o(.text*);
    }
    /* Where each EWRAM image sits in the ROM and where it runs. The main
       program sends the island from its ROM address and the high module in
       32 KB chunks from its own; the island receives those chunks at the
       high module's run address. */
    gHighModule = ADDR(.high_module);
    gHighModuleRom = LOADADDR(.high_module);
    gUnk_08363EE8 = LOADADDR(.island);
    /* Back to ROM-linked data. The explicit AT stops ld from carrying the
       island's VMA-to-LMA offset over to this section, and READONLY stops
       newlib's in-ROM .data from marking it writable. */
    .text_tail LOADADDR(.island) + SIZEOF(.island) (READONLY) :
        AT(LOADADDR(.island) + SIZEOF(.island))
    {
        build/src/data/rom_08364AC8.o(.rodata);
        build/data/rom_08364FBC.o(.text*);
        build/src/data/rom_0836524C.o(.rodata);
        build/data/rom_08365348.o(.text*);
        build/src/data/race_setup.o(.rodata);
        build/data/rom_083682BC.o(.text*);
        build/src/data/rom_083C9574.o(.rodata);
        build/data/rom_083CA0C4.o(.text*);
        build/src/data/rom_083FD91C.o(.rodata);
        build/src/data/rom_083FE064.o(.rodata);
        build/data/rom_083FED48.o(.text*);
        build/src/data/rom_083FEF00.o(.rodata);
        build/data/rom_083FEF08.o(.text*);
        build/src/data/rom_083FF5B0.o(.rodata);
        build/data/rom_083FF724.o(.text*);
        build/src/data/rom_083FF79C.o(.rodata);
        /* newlib .data, which the ROM uses in place */
        build/lib/newlib/reent/impure.o(.data);
        build/lib/newlib/locale/locale.o(.data);
        build/lib/newlib/stdlib/mallocr.o(.data);
        /* Catch-all, not the primary placement mechanism: every object above
           is listed explicitly and must stay in address order. This exists
           so a *forgotten* listing (a new src/*.c or data/*.s add without a
           matching line above) still links -- landing past the real ROM's
           end, where it grows the output and breaks the SHA1 loudly --
           instead of silently vanishing into /DISCARD/ with `make check`
           still printing MATCH. */
        *(.text*);
    }
    /DISCARD/ : { *(*); }
}
