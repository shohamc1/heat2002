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
	.thumb
	.incbin "build/assets/unknown/data_08344E68.bin"
	.incbin "build/assets/unknown/data_08349780.bin"
	.incbin "build/assets/unknown/data_0835041C.bin"
	.incbin "build/assets/unknown/data_08350528.bin"
	.incbin "build/assets/unknown/data_0835081C.bin"
	.incbin "build/assets/unknown/data_08350830.bin"
	.incbin "build/assets/unknown/data_08350834.bin"
	.incbin "build/assets/unknown/data_0835085C.bin"
	.incbin "build/assets/unknown/data_08350C20.bin"
	.incbin "build/assets/unknown/data_08351780.bin"
	.incbin "build/assets/unknown/data_08358070.bin"
	.incbin "build/assets/unknown/data_08359780.bin"
	.incbin "build/assets/unknown/data_08360000.bin"
	.incbin "build/assets/unknown/data_0836019C.bin"
	.incbin "build/assets/unknown/data_08360860.bin"
	.incbin "build/assets/unknown/data_08360888.bin"
	.incbin "build/assets/unknown/data_083608F8.bin"
	.incbin "build/assets/unknown/data_08360C2C.bin"
	.incbin "build/assets/unknown/data_08361780.bin"
	.incbin "build/assets/unknown/data_08363EE8.bin"
	arm_func_start sub_08363FC8
sub_08363FC8:
	.4byte 0xE1D010B8 @ ldrh r1, [r0, #8]
	.4byte 0xE3110080 @ tst r1, #128
	.4byte 0x0AFFFFFC @ beq 0x8363fc8
	.4byte 0xE1D010B8 @ ldrh r1, [r0, #8]
	.4byte 0xE3110080 @ tst r1, #128
	.4byte 0x1AFFFFFC @ bne 0x8363fd4
	.4byte 0xE1D010B8 @ ldrh r1, [r0, #8]
	.4byte 0xE3110040 @ tst r1, #64
	.4byte 0x112FFF1E @ bxne lr
	.4byte 0xE1D010B0 @ ldrh r1, [r0]
	.4byte 0xE12FFF1E @ bx lr
	arm_func_end sub_08363FC8
	arm_func_start sub_08363FF4
sub_08363FF4:
	.4byte 0xE59F017C @ ldr r0, [pc, #380]
	.4byte 0xEBFFFFF2 @ bl 0x8363fc8
	.4byte 0x1AFFFFFD @ bne 0x8363ff8
	.4byte 0xE3A02000 @ mov r2, #0
	.4byte 0xE1C020BA @ strh r2, [r0, #10]
	.4byte 0xE3510000 @ cmp r1, #0
	.4byte 0x1AFFFFF9 @ bne 0x8363ff8
	.4byte 0xE3A02902 @ mov r2, #32768
	.4byte 0xE3A01000 @ mov r1, #0
	.4byte 0xE1C010BA @ strh r1, [r0, #10]
	.4byte 0xEBFFFFE9 @ bl 0x8363fc8
	.4byte 0x1AFFFFF4 @ bne 0x8363ff8
	.4byte 0xE1510002 @ cmp r1, r2
	.4byte 0x1AFFFFF9 @ bne 0x8364014
	.4byte 0xE1A022A2 @ lsr r2, r2, #5
	.4byte 0xE3510000 @ cmp r1, #0
	.4byte 0x1AFFFFF7 @ bne 0x8364018
	.4byte 0xE59F313C @ ldr r3, [pc, #316]
	.4byte 0xE1D320B0 @ ldrh r2, [r3]
	.4byte 0xE1C020BA @ strh r2, [r0, #10]
	.4byte 0xEBFFFFDF @ bl 0x8363fc8
	.4byte 0x1AFFFFFE @ bne 0x8364048
	.4byte 0xE1510002 @ cmp r1, r2
	.4byte 0x1AFFFFFC @ bne 0x8364048
	.4byte 0xE1D320B2 @ ldrh r2, [r3, #2]
	.4byte 0xE1C020BA @ strh r2, [r0, #10]
	.4byte 0xEBFFFFD9 @ bl 0x8363fc8
	.4byte 0x1AFFFFF8 @ bne 0x8364048
	.4byte 0xE1510002 @ cmp r1, r2
	.4byte 0x1AFFFFF6 @ bne 0x8364048
	.4byte 0xE3A01000 @ mov r1, #0
	.4byte 0xE1C010BA @ strh r1, [r0, #10]
	.4byte 0xE3A00012 @ mov r0, #18
	.4byte 0xE129F000 @ msr CPSR_fc, r0
	.4byte 0xE59FD028 @ ldr sp, [pc, #40]
	.4byte 0xE3A0001F @ mov r0, #31
	.4byte 0xE129F000 @ msr CPSR_fc, r0
	.4byte 0xE59FD018 @ ldr sp, [pc, #24]
	.4byte 0xE59F10EC @ ldr r1, [pc, #236]
	.4byte 0xE28F0018 @ add r0, pc, #24
	.4byte 0xE5810000 @ str r0, [r1]
	.4byte 0xE59F10E4 @ ldr r1, [pc, #228]
	.4byte 0xE1A0E00F @ mov lr, pc
	.4byte 0xE12FFF11 @ bx r1
	.4byte 0xEAFFFFF2 @ b 0x8364074
	.4byte 0x03007F00 @ literal
	.4byte 0x03007FA0 @ literal
	arm_func_end sub_08363FF4
	arm_func_start sub_083640B0
sub_083640B0:
	.4byte 0xE3A03301 @ mov r3, #67108864
	.4byte 0xE2833C02 @ add r3, r3, #512
	.4byte 0xE5932000 @ ldr r2, [r3]
	.4byte 0xE0021822 @ and r1, r2, r2, lsr #16
	.4byte 0xE3A02000 @ mov r2, #0
	.4byte 0xE2110001 @ ands r0, r1, #1
	.4byte 0x1A000025 @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110002 @ ands r0, r1, #2
	.4byte 0x1A000022 @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110004 @ ands r0, r1, #4
	.4byte 0x1A00001F @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110008 @ ands r0, r1, #8
	.4byte 0x1A00001C @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110010 @ ands r0, r1, #16
	.4byte 0x1A000019 @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110020 @ ands r0, r1, #32
	.4byte 0x1A000016 @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110040 @ ands r0, r1, #64
	.4byte 0x1A000013 @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110080 @ ands r0, r1, #128
	.4byte 0x1A000010 @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110C01 @ ands r0, r1, #256
	.4byte 0x1A00000D @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110C02 @ ands r0, r1, #512
	.4byte 0x1A00000A @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110B01 @ ands r0, r1, #1024
	.4byte 0x1A000007 @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110B02 @ ands r0, r1, #2048
	.4byte 0x1A000004 @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110A01 @ ands r0, r1, #4096
	.4byte 0x1A000001 @ bne 0x8364164
	.4byte 0xE2822004 @ add r2, r2, #4
	.4byte 0xE2110A02 @ ands r0, r1, #8192
	.4byte 0xE1C300B2 @ strh r0, [r3, #2]
	.4byte 0xE59F1018 @ ldr r1, [pc, #24]
	.4byte 0xE0811002 @ add r1, r1, r2
	.4byte 0xE5910000 @ ldr r0, [r1]
	.4byte 0xE12FFF10 @ bx r0
	.4byte 0x04000120 @ literal
	.4byte 0x020000AC @ literal
	.4byte 0x03007FFC @ literal
	.4byte 0x02000415 @ literal
	.4byte 0x02000980 @ literal
	arm_func_end sub_083640B0
	thumb_func_start sub_0836418C
sub_0836418C:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08364190
sub_08364190:
	ldr r1, _08364198 @ =0x03007FF8
	movs r0, #0x01
	strh r0, [r1, #0x00]
	bx lr
	.global _08364198
_08364198: .4byte 0x03007FF8
