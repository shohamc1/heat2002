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
	thumb_func_start sub_0800F434
sub_0800F434:
	push {lr}
	ldr r1, _0800F478 @ =0x04000008
	ldr r2, _0800F47C @ =0x00001C0E
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F480 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F484 @ =0x082A9F0C
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F488 @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F48C @ =0x0833338C
	ldr r1, _0800F490 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F494 @ =0x082A9930
	bl sub_08010680
	pop {r0}
	bx r0
	.global _0800F478
_0800F478: .4byte 0x04000008
	.global _0800F47C
_0800F47C: .4byte 0x00001C0E
	.global _0800F480
_0800F480: .4byte 0x00001F82
	.global _0800F484
_0800F484: .4byte 0x082A9F0C
	.global _0800F488
_0800F488: .4byte 0x00005140
	.global _0800F48C
_0800F48C: .4byte 0x0833338C
	.global _0800F490
_0800F490: .4byte 0x0600C000
	.global _0800F494
_0800F494: .4byte 0x082A9930
	thumb_func_start sub_0800F498
sub_0800F498:
	push {lr}
	ldr r1, _0800F4DC @ =0x04000008
	ldr r2, _0800F4E0 @ =0x00001C0E
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F4E4 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F4E8 @ =0x082EE8E0
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F4EC @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F4F0 @ =0x0833338C
	ldr r1, _0800F4F4 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F4F8 @ =0x082EE304
	bl sub_08010680
	pop {r0}
	bx r0
	.global _0800F4DC
_0800F4DC: .4byte 0x04000008
	.global _0800F4E0
_0800F4E0: .4byte 0x00001C0E
	.global _0800F4E4
_0800F4E4: .4byte 0x00001F82
	.global _0800F4E8
_0800F4E8: .4byte 0x082EE8E0
	.global _0800F4EC
_0800F4EC: .4byte 0x00005140
	.global _0800F4F0
_0800F4F0: .4byte 0x0833338C
	.global _0800F4F4
_0800F4F4: .4byte 0x0600C000
	.global _0800F4F8
_0800F4F8: .4byte 0x082EE304
	thumb_func_start sub_0800F4FC
sub_0800F4FC:
	push {lr}
	ldr r1, _0800F540 @ =0x04000008
	ldr r2, _0800F544 @ =0x00001C0D
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F548 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F54C @ =0x082E4B04
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F550 @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F554 @ =0x0833338C
	ldr r1, _0800F558 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F55C @ =0x082E4528
	bl sub_08010680
	pop {r0}
	bx r0
	.global _0800F540
_0800F540: .4byte 0x04000008
	.global _0800F544
_0800F544: .4byte 0x00001C0D
	.global _0800F548
_0800F548: .4byte 0x00001F82
	.global _0800F54C
_0800F54C: .4byte 0x082E4B04
	.global _0800F550
_0800F550: .4byte 0x00005140
	.global _0800F554
_0800F554: .4byte 0x0833338C
	.global _0800F558
_0800F558: .4byte 0x0600C000
	.global _0800F55C
_0800F55C: .4byte 0x082E4528
