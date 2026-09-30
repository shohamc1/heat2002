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
	.align 2, 0
	.global gTrackSegs_Track0
gTrackSegs_Track0:
	.incbin "build/assets/tracks/hooley_downs/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track1
gTrackSegs_Track1:
	.incbin "build/assets/tracks/darlington_raceway/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track2
gTrackSegs_Track2:
	.incbin "build/assets/tracks/green_valley/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track3
gTrackSegs_Track3:
	.incbin "build/assets/tracks/michigan_international_speedway/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track4
gTrackSegs_Track4:
	.incbin "build/assets/tracks/great_canyon/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track5
gTrackSegs_Track5:
	.incbin "build/assets/tracks/fuji_port/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track6
gTrackSegs_Track6:
	.incbin "build/assets/tracks/crawfish_raceway/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track7
gTrackSegs_Track7:
	.incbin "build/assets/tracks/purley_park/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track8
gTrackSegs_Track8:
	.incbin "build/assets/tracks/kansas_speedway/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track9
gTrackSegs_Track9:
	.incbin "build/assets/tracks/asphalt_city/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track10
gTrackSegs_Track10:
	.incbin "build/assets/tracks/phoenix_international_raceway/segs.bin"
	.align 2, 0
	.global gTrackSegs_Track11
gTrackSegs_Track11:
	.incbin "build/assets/tracks/infogrames_super_speedway/segs.bin"
