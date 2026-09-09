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
	thumb_func_start sub_0801A3AC
sub_0801A3AC:
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0x0
	adds r1, r0, #0x0
	movs r0, #0xFF
	ands r5, r0
	cmp r2, #0x03
	bls _0801A420
	movs r0, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801A420
	adds r4, r1, #0x0
	movs r6, #0x00
	movs r1, #0x00
	.global _0801A3C8
_0801A3C8:
	lsls r0, r6, #0x08
	adds r6, r0, r5
	adds r1, #0x01
	cmp r1, #0x03
	bls _0801A3C8
	cmp r2, #0x03
	bls _0801A406
	ldr r0, _0801A40C @ =0xFEFEFEFF
	mov r12, r0
	ldr r7, _0801A410 @ =0x80808080
	.global _0801A3DC
_0801A3DC:
	ldr r1, [r4, #0x00]
	eors r1, r6
	mov r3, r12
	adds r0, r1, r3
	bics r0, r1
	ands r0, r7
	cmp r0, #0x00
	beq _0801A3FE
	adds r1, r4, #0x0
	movs r3, #0x00
	.global _0801A3F0
_0801A3F0:
	ldrb r0, [r1, #0x00]
	cmp r0, r5
	beq _0801A41A
	adds r1, #0x01
	adds r3, #0x01
	cmp r3, #0x03
	bls _0801A3F0
	.global _0801A3FE
_0801A3FE:
	subs r2, #0x04
	adds r4, #0x04
	cmp r2, #0x03
	bhi _0801A3DC
	.global _0801A406
_0801A406:
	adds r1, r4, #0x0
	b _0801A420
	.byte 0x00, 0x00
	.global _0801A40C
_0801A40C: .4byte 0xFEFEFEFF
	.global _0801A410
_0801A410: .4byte 0x80808080
	.global _0801A414
_0801A414:
	ldrb r0, [r1, #0x00]
	cmp r0, r5
	bne _0801A41E
	.global _0801A41A
_0801A41A:
	adds r0, r1, #0x0
	b _0801A42A
	.global _0801A41E
_0801A41E:
	adds r1, #0x01
	.global _0801A420
_0801A420:
	adds r0, r2, #0x0
	subs r2, #0x01
	cmp r0, #0x00
	bne _0801A414
	movs r0, #0x00
	.global _0801A42A
_0801A42A:
	pop {r4, r5, r6, r7, pc}
	thumb_func_start sub_0801A42C
sub_0801A42C:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r3, r1, #0x0
	cmp r2, #0x0F
	bls _0801A46C
	adds r0, r3, #0x0
	orrs r0, r5
	movs r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801A46C
	adds r1, r5, #0x0
	.global _0801A446
_0801A446:
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, #0x10
	cmp r2, #0x0F
	bhi _0801A446
	cmp r2, #0x03
	bls _0801A46A
	.global _0801A460
_0801A460:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, #0x04
	cmp r2, #0x03
	bhi _0801A460
	.global _0801A46A
_0801A46A:
	adds r4, r1, #0x0
	.global _0801A46C
_0801A46C:
	subs r2, #0x01
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	beq _0801A486
	adds r1, r0, #0x0
	.global _0801A478
_0801A478:
	ldrb r0, [r3, #0x00]
	strb r0, [r4, #0x00]
	adds r3, #0x01
	adds r4, #0x01
	subs r2, #0x01
	cmp r2, r1
	bne _0801A478
	.global _0801A486
_0801A486:
	adds r0, r5, #0x0
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801A48C
sub_0801A48C:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r3, r1, #0x0
	cmp r3, r5
	bcs _0801A4BE
	adds r0, r3, r2
	cmp r5, r0
	bcs _0801A4BE
	adds r3, r0, #0x0
	adds r4, r5, r2
	subs r2, #0x01
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	beq _0801A510
	adds r1, r0, #0x0
	.global _0801A4AE
_0801A4AE:
	subs r4, #0x01
	subs r3, #0x01
	ldrb r0, [r3, #0x00]
	strb r0, [r4, #0x00]
	subs r2, #0x01
	cmp r2, r1
	bne _0801A4AE
	b _0801A510
	.global _0801A4BE
_0801A4BE:
	cmp r2, #0x0F
	bls _0801A4F6
	adds r0, r3, #0x0
	orrs r0, r4
	movs r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801A4F6
	adds r1, r3, #0x0
	.global _0801A4D0
_0801A4D0:
	ldm r1!, {r0}
	stm r4!, {r0}
	ldm r1!, {r0}
	stm r4!, {r0}
	ldm r1!, {r0}
	stm r4!, {r0}
	ldm r1!, {r0}
	stm r4!, {r0}
	subs r2, #0x10
	cmp r2, #0x0F
	bhi _0801A4D0
	cmp r2, #0x03
	bls _0801A4F4
	.global _0801A4EA
_0801A4EA:
	ldm r1!, {r0}
	stm r4!, {r0}
	subs r2, #0x04
	cmp r2, #0x03
	bhi _0801A4EA
	.global _0801A4F4
_0801A4F4:
	adds r3, r1, #0x0
	.global _0801A4F6
_0801A4F6:
	subs r2, #0x01
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	beq _0801A510
	adds r1, r0, #0x0
	.global _0801A502
_0801A502:
	ldrb r0, [r3, #0x00]
	strb r0, [r4, #0x00]
	adds r3, #0x01
	adds r4, #0x01
	subs r2, #0x01
	cmp r2, r1
	bne _0801A502
	.global _0801A510
_0801A510:
	adds r0, r5, #0x0
	pop {r4, r5, pc}
	thumb_func_start sub_0801A514
sub_0801A514:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	adds r3, r5, #0x0
	cmp r2, #0x03
	bls _0801A55A
	movs r0, #0x03
	ands r0, r5
	cmp r0, #0x00
	bne _0801A55A
	adds r1, r5, #0x0
	movs r0, #0xFF
	ands r4, r0
	lsls r3, r4, #0x08
	orrs r3, r4
	lsls r0, r3, #0x10
	orrs r3, r0
	cmp r2, #0x0F
	bls _0801A54E
	.global _0801A53A
_0801A53A:
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	subs r2, #0x10
	cmp r2, #0x0F
	bhi _0801A53A
	b _0801A54E
	.global _0801A54A
_0801A54A:
	stm r1!, {r3}
	subs r2, #0x04
	.global _0801A54E
_0801A54E:
	cmp r2, #0x03
	bhi _0801A54A
	adds r3, r1, #0x0
	b _0801A55A
	.global _0801A556
_0801A556:
	strb r4, [r3, #0x00]
	adds r3, #0x01
	.global _0801A55A
_0801A55A:
	adds r0, r2, #0x0
	subs r2, #0x01
	cmp r0, #0x00
	bne _0801A556
	adds r0, r5, #0x0
	pop {r4, r5, pc}
	.byte 0x00, 0x00
