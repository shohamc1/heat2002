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
@ The link track's walls: a copy of track 7's (purley_park) wall parts,
@ built from the same editable folder, so one edit changes both GBAs.
	.align 2, 0
	.global gUnk_02027810
gUnk_02027810:
	.incbin "build/assets/tracks/purley_park/wall_verts.bin"
	.align 2, 0
	.global gUnk_02027DB0
gUnk_02027DB0:
	.incbin "build/assets/tracks/purley_park/wall_recs.bin"
	.align 1, 0
	.global gUnk_020293F0
gUnk_020293F0:
	.incbin "build/assets/tracks/purley_park/wall_lists.bin"
	.align 1, 0
	.global gUnk_02029CD4
gUnk_02029CD4:
	.incbin "build/assets/tracks/purley_park/wall_grid.bin"
