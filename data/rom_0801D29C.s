@ Generated with Luvdis v0.9.0
.syntax unified
.text
@ Begin embedded Luvdis macros
	.macro arm_func_start name
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro arm_func_end name
	.size \name, .-\name
	.endm

	.macro thumb_func_start name
	.align 2, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro thumb_func_end name
	.size \name, .-\name
	.endm
@ End embedded Luvdis macros
	.include "tools/tmc/asm/macros/music_voice.inc"
	.include "tools/tmc/asm/macros/m4a.inc"
	.thumb
	@ 0x0801D29C-0x0806C664: MP2K sound data; assets/sound.json lists
	@ each file. The songs are mid2agb's assembly of assets/sound/songs/*.mid
	@ and the samples aif2pcm's output from assets/sound/samples/*.aif
	@ (see the Makefile); scripts/assets.py extracts the rest.
voicegroup_0801D29C:
	voice_directsound 60, 0, sample_080242E0, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08025900, 255, 0, 218, 0
	voice_directsound 60, 0, sample_080263D8, 255, 0, 255, 0
	voice_directsound 60, 0, sample_080299FC, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0802B6B8, 255, 0, 218, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 4, 0
	voice_directsound 60, 0, sample_08031B04, 255, 0, 244, 0
	voice_directsound 60, 0, sample_080354F8, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08039D34, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0803B058, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0803CDAC, 255, 0, 255, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 6, 0
	voice_directsound 60, 0, sample_0803E700, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0803F198, 255, 0, 229, 0
	voice_directsound 60, 0, sample_08040540, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08049278, 255, 0, 255, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit_all gMPlayJumpTableTemplate + 8
voicegroup_0801D89C:
	voice_directsound 60, 0, sample_0804BC44, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0804D870, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0804F2B4, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08050C70, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08051F88, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sample_08053E3C, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08053E3C, 15, 0, 255, 0
	voice_directsound 60, 0, sample_08059848, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0805B51C, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0805D390, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0805F85C, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08061320, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08061844, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08062A24, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08064318, 255, 0, 255, 0
	voice_directsound 60, 0, sample_080661AC, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08066D20, 255, 0, 255, 0
	voice_directsound 60, 0, sample_080694E0, 255, 0, 255, 0
	@ The last 12 entries hold runs of 0 and 1, not voices.
	.fill 36, 1, 0
	.fill 36, 1, 1
	.fill 36, 1, 0
	.fill 36, 1, 1
	.incbin "build/assets/sound/cgb_waves.bin"
	.global gUnk_0801DA90
gUnk_0801DA90:
	music_player gBgMusicPlayer, gUnk_02000000, 10, 0
	music_player gEngineSoundPlayer, gUnk_02000320, 1, 0
	music_player gUnk_02001FA0, gUnk_02000370, 1, 0
	music_player gUnk_02002030, gUnk_020003C0, 1, 0
	music_player gUnk_02001FE0, gUnk_02000410, 1, 0
	.global gUnk_0801DACC
gUnk_0801DACC:
	song song_dummy, 0, 0
	song song_01, 0, 0
	song song_02, 0, 0
	song song_03, 0, 0
	song song_dummy, 0, 0
	song song_dummy, 0, 0
	song song_dummy, 0, 0
	song song_dummy, 0, 0
	song song_08, 1, 1
	song song_09, 1, 1
	song song_10, 1, 1
	song song_11, 2, 2
	song song_12, 2, 2
	song song_13, 2, 2
	song song_14, 3, 3
	song song_15, 3, 3
	song song_16, 4, 4
	song song_17, 4, 4
	song song_18, 2, 2
	song song_19, 2, 2
	song song_20, 2, 2
	song song_21, 3, 3
	song song_22, 3, 3
	song song_23, 3, 3
	song song_24, 2, 2
	song song_25, 2, 2
	song song_26, 2, 2
	song song_27, 2, 2
	song song_28, 3, 3
	song song_29, 2, 2
song_dummy:
	.incbin "build/assets/sound/song_dummy.bin"
	.global sample_0801DBC0
sample_0801DBC0:
	.incbin "build/assets/sound/samples/sample_0801DBC0.bin"
	.align 2, 0
	.global sample_0801E4C8
sample_0801E4C8:
	.incbin "build/assets/sound/samples/sample_0801E4C8.bin"
	.align 2, 0
	.global sample_0801F84C
sample_0801F84C:
	.incbin "build/assets/sound/samples/sample_0801F84C.bin"
	.align 2, 0
	.global sample_08020018
sample_08020018:
	.incbin "build/assets/sound/samples/sample_08020018.bin"
	.align 2, 0
	.global sample_08021F6C
sample_08021F6C:
	.incbin "build/assets/sound/samples/sample_08021F6C.bin"
	.align 2, 0
	.global sample_080242E0
sample_080242E0:
	.incbin "build/assets/sound/samples/sample_080242E0.bin"
	.align 2, 0
	.global sample_08025900
sample_08025900:
	.incbin "build/assets/sound/samples/sample_08025900.bin"
	.align 2, 0
	.global sample_080263D8
sample_080263D8:
	.incbin "build/assets/sound/samples/sample_080263D8.bin"
	.align 2, 0
	.global sample_080299FC
sample_080299FC:
	.incbin "build/assets/sound/samples/sample_080299FC.bin"
	.align 2, 0
	.global sample_0802B6B8
sample_0802B6B8:
	.incbin "build/assets/sound/samples/sample_0802B6B8.bin"
	.align 2, 0
	.global sample_08031B04
sample_08031B04:
	.incbin "build/assets/sound/samples/sample_08031B04.bin"
	.align 2, 0
	.global sample_080354F8
sample_080354F8:
	.incbin "build/assets/sound/samples/sample_080354F8.bin"
	.align 2, 0
	.global sample_08039D34
sample_08039D34:
	.incbin "build/assets/sound/samples/sample_08039D34.bin"
	.align 2, 0
	.global sample_0803B058
sample_0803B058:
	.incbin "build/assets/sound/samples/sample_0803B058.bin"
	.align 2, 0
	.global sample_0803CDAC
sample_0803CDAC:
	.incbin "build/assets/sound/samples/sample_0803CDAC.bin"
	.align 2, 0
	.global sample_0803E700
sample_0803E700:
	.incbin "build/assets/sound/samples/sample_0803E700.bin"
	.align 2, 0
	.global sample_0803F198
sample_0803F198:
	.incbin "build/assets/sound/samples/sample_0803F198.bin"
	.align 2, 0
	.global sample_08040540
sample_08040540:
	.incbin "build/assets/sound/samples/sample_08040540.bin"
	.align 2, 0
	.global sample_08049278
sample_08049278:
	.incbin "build/assets/sound/samples/sample_08049278.bin"
	.align 2, 0
	.global sample_0804BC44
sample_0804BC44:
	.incbin "build/assets/sound/samples/sample_0804BC44.bin"
	.align 2, 0
	.global sample_0804D870
sample_0804D870:
	.incbin "build/assets/sound/samples/sample_0804D870.bin"
	.align 2, 0
	.global sample_0804F2B4
sample_0804F2B4:
	.incbin "build/assets/sound/samples/sample_0804F2B4.bin"
	.align 2, 0
	.global sample_08050C70
sample_08050C70:
	.incbin "build/assets/sound/samples/sample_08050C70.bin"
	.align 2, 0
	.global sample_08051F88
sample_08051F88:
	.incbin "build/assets/sound/samples/sample_08051F88.bin"
	.align 2, 0
	.global sample_08053E3C
sample_08053E3C:
	.incbin "build/assets/sound/samples/sample_08053E3C.bin"
	.align 2, 0
	.global sample_08059848
sample_08059848:
	.incbin "build/assets/sound/samples/sample_08059848.bin"
	.align 2, 0
	.global sample_0805B51C
sample_0805B51C:
	.incbin "build/assets/sound/samples/sample_0805B51C.bin"
	.align 2, 0
	.global sample_0805D390
sample_0805D390:
	.incbin "build/assets/sound/samples/sample_0805D390.bin"
	.align 2, 0
	.global sample_0805F85C
sample_0805F85C:
	.incbin "build/assets/sound/samples/sample_0805F85C.bin"
	.align 2, 0
	.global sample_08061320
sample_08061320:
	.incbin "build/assets/sound/samples/sample_08061320.bin"
	.align 2, 0
	.global sample_08061844
sample_08061844:
	.incbin "build/assets/sound/samples/sample_08061844.bin"
	.align 2, 0
	.global sample_08062A24
sample_08062A24:
	.incbin "build/assets/sound/samples/sample_08062A24.bin"
	.align 2, 0
	.global sample_08064318
sample_08064318:
	.incbin "build/assets/sound/samples/sample_08064318.bin"
	.align 2, 0
	.global sample_080661AC
sample_080661AC:
	.incbin "build/assets/sound/samples/sample_080661AC.bin"
	.align 2, 0
	.global sample_08066D20
sample_08066D20:
	.incbin "build/assets/sound/samples/sample_08066D20.bin"
	.align 2, 0
	.global sample_080694E0
sample_080694E0:
	.incbin "build/assets/sound/samples/sample_080694E0.bin"
	.align 2, 0
	.include "build/assets/sound/songs/song_01.s"
	.include "build/assets/sound/songs/song_02.s"
	.include "build/assets/sound/songs/song_03.s"
	.include "build/assets/sound/songs/song_08.s"
	.include "build/assets/sound/songs/song_09.s"
	.include "build/assets/sound/songs/song_10.s"
	.include "build/assets/sound/songs/song_11.s"
	.include "build/assets/sound/songs/song_12.s"
	.include "build/assets/sound/songs/song_13.s"
	.include "build/assets/sound/songs/song_14.s"
	.include "build/assets/sound/songs/song_15.s"
	.include "build/assets/sound/songs/song_16.s"
	.include "build/assets/sound/songs/song_17.s"
	.include "build/assets/sound/songs/song_18.s"
	.include "build/assets/sound/songs/song_19.s"
	.include "build/assets/sound/songs/song_20.s"
	.include "build/assets/sound/songs/song_21.s"
	.include "build/assets/sound/songs/song_22.s"
	.include "build/assets/sound/songs/song_23.s"
	.include "build/assets/sound/songs/song_24.s"
	.include "build/assets/sound/songs/song_25.s"
	.include "build/assets/sound/songs/song_26.s"
	.include "build/assets/sound/songs/song_27.s"
	.include "build/assets/sound/songs/song_28.s"
	.include "build/assets/sound/songs/song_29.s"
	.global gUnk_0806C664
gUnk_0806C664:
	.incbin "build/assets/unknown/data_0806C664.bin"
	.global gUnk_0806C668
gUnk_0806C668:
	.incbin "build/assets/unknown/data_0806C668.bin"
	.global gUnk_0806C66C
gUnk_0806C66C:
	.incbin "build/assets/unknown/data_0806C66C.bin"
	.global gUnk_0806C670
gUnk_0806C670:
	.incbin "build/assets/unknown/data_0806C670.bin"
	.global gUnk_0806C674
gUnk_0806C674:
	.incbin "build/assets/unknown/data_0806C674.bin"
