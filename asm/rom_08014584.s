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
	thumb_func_start sub_08014584
sub_08014584:
	push {lr}
	ldr r0, _08014598 @ =0x0829F484
	movs r1, #0x54
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_08014598: .4byte 0x0829F484
	thumb_func_start sub_0801459C
sub_0801459C:
	push {lr}
	ldr r0, _080145B0 @ =0x0829F490
	movs r1, #0x40
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_080145B0: .4byte 0x0829F490
	thumb_func_start sub_080145B4
sub_080145B4:
	push {lr}
	ldr r0, _080145C8 @ =0x0829F4A0
	movs r1, #0x38
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_080145C8: .4byte 0x0829F4A0
	thumb_func_start sub_080145CC
sub_080145CC:
	push {lr}
	ldr r0, _080145E0 @ =0x0829F4B4
	movs r1, #0x3C
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_080145E0: .4byte 0x0829F4B4
	thumb_func_start sub_080145E4
sub_080145E4:
	push {lr}
	ldr r0, _080145F8 @ =0x0829F4C4
	movs r1, #0x20
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_080145F8: .4byte 0x0829F4C4
	thumb_func_start sub_080145FC
sub_080145FC:
	push {lr}
	ldr r0, _08014610 @ =0x0829F4DC
	movs r1, #0x48
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_08014610: .4byte 0x0829F4DC
