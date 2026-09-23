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
	thumb_func_start sub_083642FC
sub_083642FC:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r5, #0x00
	movs r0, #0x02
	bl sub_08364804
	ldr r1, _083643E4 @ =0x040000D4
	ldr r0, _083643E8 @ =0x020001C8
	str r0, [r1, #0x00]
	ldr r2, _083643EC @ =0x03000000
	str r2, [r1, #0x04]
	ldr r0, _083643F0 @ =0x84000200
	str r0, [r1, #0x08]
	ldr r0, [r1, #0x08]
	ldr r0, _083643F4 @ =0x03007FFC
	str r2, [r0, #0x00]
	ldr r3, _083643F8 @ =0x04000200
	movs r0, #0x01
	strh r0, [r3, #0x00]
	ldr r0, _083643FC @ =0x080000B2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x96
	bne _0836434C
	ldr r0, _08364400 @ =0x080000AC
	ldr r1, _08364404 @ =0x020009B8
	ldr r2, [r0, #0x00]
	ldr r0, [r1, #0x00]
	cmp r2, r0
	bne _0836434C
	ldrh r0, [r3, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x06
	adds r1, r2, #0x0
	orrs r0, r1
	strh r0, [r3, #0x00]
_0836434C:
	ldr r1, _08364408 @ =0x04000004
	movs r0, #0x08
	strh r0, [r1, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	adds r1, #0xD0
	mov r3, sp
	str r3, [r1, #0x00]
	movs r0, #0xC0
	lsls r0, r0, #0x13
	str r0, [r1, #0x04]
	ldr r0, _0836440C @ =0x85006000
	str r0, [r1, #0x08]
	ldr r0, [r1, #0x08]
	movs r4, #0x00
	lsls r0, r5, #0x02
	mov r8, r0
	lsls r6, r5, #0x0F
	add r2, sp, #0x004
	mov r9, r2
	adds r5, #0x01
	ldr r7, _08364410 @ =0x02000BD4
_08364378:
	lsls r0, r4, #0x02
	adds r0, r0, r7
	ldr r0, [r0, #0x00]
	lsls r1, r4, #0x09
	ldr r3, _08364414 @ =0x06010000
	adds r1, r1, r3
	bl sub_08364800
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x02
	bls _08364378
	ldr r2, _083643E4 @ =0x040000D4
	ldr r0, _08364418 @ =0x02000A9C
	str r0, [r2, #0x00]
	ldr r0, _0836441C @ =0x05000200
	str r0, [r2, #0x04]
	ldr r0, _08364420 @ =0x84000008
	str r0, [r2, #0x08]
	ldr r0, [r2, #0x08]
	ldr r1, _08364424 @ =0x04000008
	movs r0, #0x89
	strh r0, [r1, #0x00]
	subs r1, #0x08
	movs r3, #0x8A
	lsls r3, r3, #0x05
	adds r0, r3, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _083643F8 @ =0x04000200
	movs r3, #0x01
	strh r3, [r0, #0x00]
	adds r1, #0x04
	movs r0, #0x08
	strh r0, [r1, #0x00]
	ldr r0, _08364428 @ =0x04000208
	strh r3, [r0, #0x00]
	movs r0, #0xA0
	str r0, [sp, #0x000]
	mov r0, sp
	str r0, [r2, #0x00]
	ldr r0, _0836442C @ =0x03000800
	str r0, [r2, #0x04]
	ldr r0, _08364430 @ =0x85000100
	str r0, [r2, #0x08]
	ldr r0, [r2, #0x08]
	ldr r0, _08364434 @ =0x02000964
	add r0, r8
	ldr r1, [r0, #0x00]
	movs r0, #0x00
	bl sub_083644B4
	b _08364460
	.byte 0x00, 0x00
_083643E4: .4byte 0x040000D4
_083643E8: .4byte 0x020001C8
_083643EC: .4byte 0x03000000
_083643F0: .4byte 0x84000200
_083643F4: .4byte 0x03007FFC
_083643F8: .4byte 0x04000200
_083643FC: .4byte 0x080000B2
_08364400: .4byte 0x080000AC
_08364404: .4byte 0x020009B8
_08364408: .4byte 0x04000004
_0836440C: .4byte 0x85006000
_08364410: .4byte 0x02000BD4
_08364414: .4byte 0x06010000
_08364418: .4byte 0x02000A9C
_0836441C: .4byte 0x05000200
_08364420: .4byte 0x84000008
_08364424: .4byte 0x04000008
_08364428: .4byte 0x04000208
_0836442C: .4byte 0x03000800
_08364430: .4byte 0x85000100
_08364434: .4byte 0x02000964
_08364438:
	ldr r1, _083644A8 @ =0x02000964
	lsls r0, r5, #0x02
	adds r0, r0, r1
	ldr r1, [r0, #0x00]
	movs r0, #0x00
	bl sub_083644B4
	movs r0, #0x00
	str r0, [sp, #0x004]
	lsls r6, r5, #0x0F
	adds r5, #0x01
_0836444E:
	ldr r0, _083644AC @ =0x03000800
	movs r1, #0xE0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl sub_083647F8
	bl sub_08364808
_08364460:
	ldr r4, [sp, #0x004]
	lsls r4, r4, #0x02
	adds r4, r6, r4
	lsrs r4, r4, #0x0A
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0x0
	movs r1, #0x64
	bl sub_083641D8
	adds r0, r4, #0x0
	movs r1, #0x64
	bl sub_0836419C
	mov r0, r9
	bl sub_08364550
	cmp r0, #0x00
	beq _0836444E
	lsls r0, r5, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x07
	bne _08364438
	movs r0, #0xE2
	bl sub_08364804
	ldr r0, _083644B0 @ =0x02000D00
	bl _08364810
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_083644A8: .4byte 0x02000964
_083644AC: .4byte 0x03000800
_083644B0: .4byte 0x02000D00
