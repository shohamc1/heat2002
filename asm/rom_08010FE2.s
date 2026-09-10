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
	thumb_func_start sub_08010FE4
sub_08010FE4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x034
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	cmp r1, #0x00
	beq _08011004
	movs r0, #0xA1
	bl sub_08016558
	bl sub_080065A8
	.global _08011004
_08011004:
	ldr r4, _0801103C @ =0x0829F2AC
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x04
	movs r3, #0x00
	bl sub_080063BC
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x05
	movs r3, #0x00
	bl sub_080063BC
	cmp r7, #0x03
	beq _08011044
	ldr r1, _08011040 @ =0x083FDA78
	lsls r4, r7, #0x01
	adds r0, r4, r7
	lsls r0, r0, #0x03
	adds r1, #0x0C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x04
	movs r2, #0x01
	bl sub_08006950
	b _0801105A
	.byte 0x00, 0x00
	.global _0801103C
_0801103C: .4byte 0x0829F2AC
	.global _08011040
_08011040: .4byte 0x083FDA78
	.global _08011044
_08011044:
	ldr r0, _0801112C @ =0x0829F2CC
	movs r1, #0x04
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _08011130 @ =0x0829F2D8
	movs r1, #0x05
	movs r2, #0x01
	bl sub_08006950
	movs r4, #0x06
	.global _0801105A
_0801105A:
	ldr r5, _08011134 @ =0x083FDA78
	adds r4, r4, r7
	lsls r4, r4, #0x03
	adds r0, r5, #0x0
	adds r0, #0x14
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	ldr r1, _08011138 @ =0x05000200
	movs r6, #0x80
	lsls r6, r6, #0x01
	adds r2, r6, #0x0
	bl sub_08016E10
	ldr r0, _0801113C @ =0x0830E670
	ldr r1, _08011140 @ =0x050003E0
	movs r2, #0x10
	bl sub_08016E10
	adds r5, #0x10
	adds r4, r4, r5
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08011144 @ =0x06010000
	bl sub_08016E28
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x04]
	ldr r1, _08011148 @ =0x06011000
	bl sub_08016E28
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x08]
	ldr r1, _0801114C @ =0x06012000
	bl sub_08016E28
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x0C]
	ldr r1, _08011150 @ =0x06013000
	bl sub_08016E28
	movs r0, #0x38
	movs r1, #0x20
	movs r2, #0x00
	bl sub_08010194
	movs r0, #0x78
	movs r1, #0x20
	movs r2, #0x80
	bl sub_08010194
	movs r0, #0x38
	movs r1, #0x60
	adds r2, r6, #0x0
	bl sub_08010194
	movs r2, #0xC0
	lsls r2, r2, #0x01
	movs r0, #0x78
	movs r1, #0x60
	bl sub_08010194
	mov r0, r8
	cmp r0, #0x00
	beq _08011116
	ldr r1, _08011154 @ =0x0202EED8
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08011116
	ldr r0, _08011158 @ =0x0830E618
	ldr r1, _0801115C @ =0x06014000
	bl sub_08016E28
	ldr r0, _08011160 @ =0x0830E690
	ldr r1, _08011164 @ =0x06015000
	bl sub_08016E28
	cmp r7, #0x00
	beq _08011106
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x10
	movs r1, #0x48
	bl sub_0801027C
	.global _08011106
_08011106:
	cmp r7, #0x0B
	beq _08011116
	movs r2, #0xA0
	lsls r2, r2, #0x02
	movs r0, #0xD0
	movs r1, #0x48
	bl sub_0801027C
	.global _08011116
_08011116:
	ldr r1, _08011154 @ =0x0202EED8
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	add sp, #0x034
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _0801112C
_0801112C: .4byte 0x0829F2CC
	.global _08011130
_08011130: .4byte 0x0829F2D8
	.global _08011134
_08011134: .4byte 0x083FDA78
	.global _08011138
_08011138: .4byte 0x05000200
	.global _0801113C
_0801113C: .4byte 0x0830E670
	.global _08011140
_08011140: .4byte 0x050003E0
	.global _08011144
_08011144: .4byte 0x06010000
	.global _08011148
_08011148: .4byte 0x06011000
	.global _0801114C
_0801114C: .4byte 0x06012000
	.global _08011150
_08011150: .4byte 0x06013000
	.global _08011154
_08011154: .4byte 0x0202EED8
	.global _08011158
_08011158: .4byte 0x0830E618
	.global _0801115C
_0801115C: .4byte 0x06014000
	.global _08011160
_08011160: .4byte 0x0830E690
	.global _08011164
_08011164: .4byte 0x06015000
