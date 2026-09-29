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
	.global gTrackSegs_Track0
gTrackSegs_Track0:
	.incbin "build/assets/unknown/data_08365348.bin"
	.global gTrackSegs_Track1
gTrackSegs_Track1:
	.incbin "build/assets/unknown/data_08365618.bin"
	.global gTrackSegs_Track2
gTrackSegs_Track2:
	.incbin "build/assets/unknown/data_08365798.bin"
	.global gTrackSegs_Track3
gTrackSegs_Track3:
	.incbin "build/assets/unknown/data_08365A38.bin"
	.global gTrackSegs_Track4
gTrackSegs_Track4:
	.incbin "build/assets/unknown/data_08365CC0.bin"
	.incbin "build/assets/unknown/data_08365D38.bin"
	.global gTrackSegs_Track5
gTrackSegs_Track5:
	.incbin "build/assets/unknown/data_08366140.bin"
	.global gTrackSegs_Track6
gTrackSegs_Track6:
	.incbin "build/assets/unknown/data_08366470.bin"
	.global gTrackSegs_Track7
gTrackSegs_Track7:
	.incbin "build/assets/unknown/data_08366620.bin"
	.global gTrackSegs_Track8
gTrackSegs_Track8:
	.incbin "build/assets/unknown/data_083668A8.bin"
	.global gTrackSegs_Track9
gTrackSegs_Track9:
	.incbin "build/assets/unknown/data_08366A58.bin"
	.global gTrackSegs_Track10
gTrackSegs_Track10:
	.incbin "build/assets/unknown/data_08366DE8.bin"
	.global gTrackSegs_Track11
gTrackSegs_Track11:
	.incbin "build/assets/unknown/data_08366F38.bin"
