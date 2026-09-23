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
	thumb_func_start sub_08340B5C
sub_08340B5C:
	push {r4, r5, lr}
	adds r2, r0, #0x0
	movs r4, #0x00
	movs r5, #0x00
	cmp r2, #0x00
	bge _08340B6E
	negs r2, r2
	movs r4, #0x01
	movs r5, #0x80
_08340B6E:
	cmp r1, #0x00
	bge _08340B78
	negs r1, r1
	movs r0, #0x01
	eors r4, r0
_08340B78:
	lsls r0, r1, #0x06
	adds r1, r2, r1
	bl sub_08344BB8
	cmp r4, #0x00
	beq _08340B86
	negs r0, r0
_08340B86:
	adds r0, r5, r0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_08340B90
sub_08340B90:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0x01
	ldr r0, _08340C18 @ =0x0203D520
	mov r8, r0
	movs r2, #0x63
	ldr r0, _08340C1C @ =0x000002F2
	add r0, r8
	movs r1, #0xC8
	lsls r1, r1, #0x01
_08340BA6:
	strb r2, [r0, #0x00]
	adds r0, r0, r1
	adds r4, #0x01
	cmp r4, #0x05
	bne _08340BA6
	movs r4, #0x01
_08340BB2:
	bl sub_0833BCBC
	movs r2, #0x1F
	ands r2, r0
	cmp r2, #0x1D
	bhi _08340BB2
	movs r5, #0x00
	movs r1, #0x00
	ldr r0, _08340C18 @ =0x0203D520
	mov r8, r0
	lsls r3, r4, #0x01
	adds r7, r4, #0x1
	mov r12, r8
	movs r6, #0xB1
	lsls r6, r6, #0x01
_08340BD0:
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	add r0, r12
	adds r0, r0, r6
	ldrb r0, [r0, #0x00]
	cmp r2, r0
	bne _08340BE6
	movs r5, #0x01
_08340BE6:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x05
	bne _08340BD0
	cmp r5, #0x00
	bne _08340BB2
	adds r0, r3, r4
	lsls r0, r0, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x04
	add r0, r8
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strb r2, [r0, #0x00]
	adds r4, r7, #0x0
	cmp r4, #0x05
	bne _08340BB2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08340C18: .4byte 0x0203D520
_08340C1C: .4byte 0x000002F2
	thumb_func_start sub_08340C20
sub_08340C20:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0x01
	ldr r0, _08340CAC @ =0x0203D520
	mov r12, r0
_08340C2C:
	lsls r1, r4, #0x01
	adds r0, r1, r4
	lsls r0, r0, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x04
	add r0, r12
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r0, r0, r2
	adds r7, r1, #0x0
	adds r1, r4, #0x1
	mov r8, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x63
	bne _08340C9A
_08340C4A:
	bl sub_0833BCBC
	movs r2, #0x1F
	ands r2, r0
	cmp r2, #0x1D
	bhi _08340C4A
	movs r3, #0x00
	movs r1, #0x00
	ldr r0, _08340CAC @ =0x0203D520
	mov r12, r0
	mov r6, r12
	movs r5, #0xB1
	lsls r5, r5, #0x01
_08340C64:
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r0, r0, r6
	adds r0, r0, r5
	ldrb r0, [r0, #0x00]
	cmp r2, r0
	bne _08340C7A
	movs r3, #0x01
_08340C7A:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x05
	bne _08340C64
	cmp r3, #0x00
	bne _08340C4A
	adds r0, r7, r4
	lsls r0, r0, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x04
	add r0, r12
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strb r2, [r0, #0x00]
_08340C9A:
	mov r4, r8
	cmp r4, #0x05
	bne _08340C2C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08340CAC: .4byte 0x0203D520
	thumb_func_start sub_08340CB0
sub_08340CB0:
	adds r2, r0, #0x0
	ldr r0, _08340CCC @ =0x0203DD34
	ldr r0, [r0, #0x00]
	cmp r0, r2
	bgt _08340CD8
	ldr r0, _08340CD0 @ =0x0203D520
	ldr r0, [r0, #0x50]
	ldr r1, _08340CD4 @ =0x0000FFFF
	ands r0, r1
	cmp r0, r2
	bcc _08340CD8
	movs r0, #0x01
	b _08340CDA
	.byte 0x00, 0x00
_08340CCC: .4byte 0x0203DD34
_08340CD0: .4byte 0x0203D520
_08340CD4: .4byte 0x0000FFFF
_08340CD8:
	movs r0, #0x00
_08340CDA:
	bx lr
	thumb_func_start sub_08340CDC
sub_08340CDC:
	ldr r1, _08340CF8 @ =0x0203DCFC
	ldr r2, [r1, #0x00]
	lsls r1, r2, #0x05
	subs r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x03
	ldr r2, _08340CFC @ =0x0203D500
	ldr r2, [r2, #0x00]
	adds r1, r1, r2
	cmp r1, r0
	ble _08340D00
	movs r0, #0x00
	b _08340D02
_08340CF8: .4byte 0x0203DCFC
_08340CFC: .4byte 0x0203D500
_08340D00:
	movs r0, #0x01
_08340D02:
	bx lr
