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
	thumb_func_start sub_080057E8
sub_080057E8:
	ldr r0, _080057FC @ =0x0202521C
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08005804
	ldr r0, _08005800 @ =0x020253C0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08005804
	movs r0, #0x00
	b _08005806
_080057FC: .4byte 0x0202521C
_08005800: .4byte 0x020253C0
_08005804:
	movs r0, #0x01
_08005806:
	bx lr
	thumb_func_start sub_08005808
sub_08005808:
	push {r4, r5, lr}
	ldr r0, _08005858 @ =0x020020C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08005852
	ldr r0, _0800585C @ =0x020021E0
	ldrb r4, [r0, #0x00]
	cmp r4, #0x00
	bne _08005852
	ldr r5, _08005860 @ =0x020253C0
	ldr r1, [r5, #0x00]
	adds r0, r1, #0x0
	subs r0, #0x18
	str r0, [r5, #0x00]
	cmp r0, #0x00
	bge _08005852
	movs r2, #0xF4
	lsls r2, r2, #0x02
	adds r0, r1, r2
	str r0, [r5, #0x00]
	ldr r3, _08005864 @ =0x0202521C
	ldr r1, [r3, #0x00]
	subs r1, #0x01
	str r1, [r3, #0x00]
	ldr r2, _08005868 @ =0x02025238
	movs r0, #0x01
	strb r0, [r2, #0x00]
	cmp r1, #0x00
	bge _08005852
	str r4, [r3, #0x00]
	str r4, [r5, #0x00]
	ldr r0, _0800586C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08005852
	bl sub_0800B09C
_08005852:
	pop {r4, r5}
	pop {r0}
	bx r0
_08005858: .4byte 0x020020C4
_0800585C: .4byte 0x020021E0
_08005860: .4byte 0x020253C0
_08005864: .4byte 0x0202521C
_08005868: .4byte 0x02025238
_0800586C: .4byte 0x0200215C
