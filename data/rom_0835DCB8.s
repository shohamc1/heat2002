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
@ The waypoint gates of tracks 3-11: a copy of their segs parts, in the
@ main program's order, built from the same editable folders.
	.align 2, 0
	.incbin "build/assets/tracks/michigan_international_speedway/segs.bin"
	.align 2, 0
	.incbin "build/assets/tracks/great_canyon/segs.bin"
	.align 2, 0
	.incbin "build/assets/tracks/fuji_port/segs.bin"
	.align 2, 0
	.incbin "build/assets/tracks/crawfish_raceway/segs.bin"
	.align 2, 0
	.global gUnk_02025E20
gUnk_02025E20:
	.incbin "build/assets/tracks/purley_park/segs.bin"
	.align 2, 0
	.incbin "build/assets/tracks/kansas_speedway/segs.bin"
	.align 2, 0
	.incbin "build/assets/tracks/asphalt_city/segs.bin"
	.align 2, 0
	.incbin "build/assets/tracks/phoenix_international_raceway/segs.bin"
	.align 2, 0
	.incbin "build/assets/tracks/infogrames_super_speedway/segs.bin"
