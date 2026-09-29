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
	@ 0x0801DBBC-0x0806AA64: song_dummy, the 4-byte empty song every
	@ unused gSongTable row plays, then the 36 direct sound samples
	@ (aif2pcm's output from assets/sound/samples/*.aif). The voice
	@ groups reference the samples from another object.
	.global song_dummy
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
