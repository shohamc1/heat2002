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
	thumb_func_start sub_08000214
sub_08000214:
	push {lr}
	bl sub_08000224
	bl sub_08000260
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_08000224
sub_08000224:
	add sp, #-0x004
	movs r2, #0x00
	str r2, [sp, #0x000]
	ldr r0, _08000254 @ =0x040000D4
	mov r1, sp
	str r1, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x12
	str r1, [r0, #0x04]
	ldr r1, _08000258 @ =0x85010000
	str r1, [r0, #0x08]
	ldr r1, [r0, #0x08]
	str r2, [sp, #0x000]
	mov r1, sp
	str r1, [r0, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x12
	str r1, [r0, #0x04]
	ldr r1, _0800025C @ =0x85001F80
	str r1, [r0, #0x08]
	ldr r0, [r0, #0x08]
	add sp, #0x004
	bx lr
	.byte 0x00, 0x00
_08000254: .4byte 0x040000D4
_08000258: .4byte 0x85010000
_0800025C: .4byte 0x85001F80
