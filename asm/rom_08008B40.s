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
	.byte 0x02, 0x1C, 0x06, 0x48, 0x00, 0x68, 0x90, 0x42, 0x0E, 0xDC, 0x05, 0x48, 0x00, 0x6D, 0x05, 0x49
	.byte 0x08, 0x40, 0x90, 0x42, 0x08, 0xD3, 0x01, 0x20, 0x07, 0xE0, 0x00, 0x00, 0x14, 0xCB, 0x02, 0x02
	.byte 0x50, 0xA5, 0x02, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x20, 0x70, 0x47, 0x06, 0x49, 0x0A, 0x68
	.byte 0x51, 0x01, 0x89, 0x1A, 0x89, 0x00, 0x89, 0x18, 0xC9, 0x00, 0x04, 0x4A, 0x12, 0x68, 0x89, 0x18
	.byte 0x81, 0x42, 0x05, 0xDD, 0x00, 0x20, 0x04, 0xE0, 0xDC, 0xCA, 0x02, 0x02, 0x34, 0xA5, 0x02, 0x02
	.byte 0x01, 0x20, 0x70, 0x47
	thumb_func_start sub_08008B94
sub_08008B94:
	push {r4, r5, r6, lr}
	ldr r0, _08008C2C @ =0x08364B08
	ldr r6, [r0, #0x00]
	movs r0, #0x94
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r0, _08008C30 @ =0x0806C8E4
	movs r1, #0x08
	movs r2, #0x08
	bl sub_0800649C
	adds r0, r5, #0x0
	movs r1, #0x00
	bl sub_08005870
	movs r0, #0x95
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r0, _08008C34 @ =0x0202CAE4
	ldr r1, [r0, #0x00]
	adds r0, r5, #0x0
	bl sub_08005870
	ldr r0, _08008C38 @ =0x0000025A
	adds r5, r6, r0
	ldr r4, _08008C3C @ =0x0202CADC
	ldr r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_08017230
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	ldr r0, _08008C40 @ =0x0000025E
	adds r5, r6, r0
	ldr r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	movs r0, #0x99
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r4, _08008C44 @ =0x0202A534
	ldr r0, [r4, #0x00]
	movs r1, #0x64
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	movs r0, #0x9A
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _08008C2C
_08008C2C: .4byte 0x08364B08
	.global _08008C30
_08008C30: .4byte 0x0806C8E4
	.global _08008C34
_08008C34: .4byte 0x0202CAE4
	.global _08008C38
_08008C38: .4byte 0x0000025A
	.global _08008C3C
_08008C3C: .4byte 0x0202CADC
	.global _08008C40
_08008C40: .4byte 0x0000025E
	.global _08008C44
_08008C44: .4byte 0x0202A534
	thumb_func_start sub_08008C48
sub_08008C48:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, _08008CB0 @ =0x08364B08
	ldr r6, [r0, #0x00]
	movs r0, #0xE5
	lsls r0, r0, #0x02
	adds r5, r6, r0
	adds r0, r4, #0x0
	movs r1, #0x64
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	movs r0, #0xE6
	lsls r0, r0, #0x02
	adds r5, r6, r0
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	movs r0, #0xE7
	lsls r0, r0, #0x02
	adds r5, r6, r0
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	ldr r0, _08008CB4 @ =0x0806C8EC
	movs r1, #0x10
	movs r2, #0x0F
	bl sub_0800649C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08008CB0
_08008CB0: .4byte 0x08364B08
	.global _08008CB4
_08008CB4: .4byte 0x0806C8EC
