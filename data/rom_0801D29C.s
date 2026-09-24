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
	.thumb
	@ 0x0801D29C-0x0806C664: MP2K sound data; assets/sound.json lists
	@ each file. The songs are mid2agb's assembly of assets/sound/songs/*.mid
	@ and the samples aif2pcm's output from assets/sound/samples/*.aif
	@ (see the Makefile); scripts/assets.py extracts the rest.
voicegroup_0801D29C:
	.incbin "build/assets/sound/voicegroup_0801D29C.bin"
voicegroup_0801D89C:
	.incbin "build/assets/sound/voicegroup_0801D89C.bin"
	.incbin "build/assets/sound/cgb_waves.bin"
	.incbin "build/assets/sound/music_players.bin"
	.incbin "build/assets/sound/song_table.bin"
	.incbin "build/assets/sound/song_dummy.bin"
	.incbin "build/assets/sound/samples/sample_0801DBC0.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0801E4C8.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0801F84C.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08020018.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08021F6C.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_080242E0.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08025900.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_080263D8.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_080299FC.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0802B6B8.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08031B04.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_080354F8.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08039D34.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0803B058.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0803CDAC.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0803E700.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0803F198.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08040540.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08049278.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0804BC44.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0804D870.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0804F2B4.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08050C70.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08051F88.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08053E3C.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08059848.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0805B51C.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0805D390.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_0805F85C.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08061320.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08061844.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08062A24.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08064318.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_080661AC.bin"
	.align 2, 0
	.incbin "build/assets/sound/samples/sample_08066D20.bin"
	.align 2, 0
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
	.incbin "build/assets/unknown/data_0806C664.bin"
	.incbin "build/assets/unknown/data_0806C668.bin"
	.incbin "build/assets/unknown/data_0806C66C.bin"
	.incbin "build/assets/unknown/data_0806C670.bin"
	.incbin "build/assets/unknown/data_0806C674.bin"
