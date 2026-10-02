@ Generated with Luvdis v0.9.0
@ Both builds preprocess this file (preproc inlines the .include files,
@ cpp resolves the switch below). The GBA keeps the exact luvdis layout;
@ the hosted build switches to a writable data section, because its mPtr
@ pointer fields carry relocations the host linker must be able to write.
	.include "asm/macros/portable.inc"
#if PLATFORM_GBA
.syntax unified
.text
#else
mSectionData
#endif
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
	.global gModule_0201AD3C
gModule_0201AD3C:
	.incbin "build/assets/graphics/rl_0831C898.bin"
	.space 2
	.global gModule_0201AD78
gModule_0201AD78:
	.incbin "build/assets/graphics/rl_0831C8D4.bin"
	.global gModule_0201ADBC
gModule_0201ADBC:
	.incbin "build/assets/graphics/rl_0831C918.bin"
	.space 2
	.global gModule_0201AE04
gModule_0201AE04:
	.incbin "build/assets/graphics/rl_0831C960.bin"
	.space 2
	.global gModule_0201AE4C
gModule_0201AE4C:
	.incbin "build/assets/graphics/rl_0831C9A8.bin"
	.space 2
	.global gModule_0201AE94
gModule_0201AE94:
	.incbin "build/assets/graphics/rl_0831C9F0.bin"
	.space 2
	.global gModule_0201AEDC
gModule_0201AEDC:
	.incbin "build/assets/graphics/rl_0831CA38.bin"
	.space 3
	.global gModule_0201AF24
gModule_0201AF24:
	.incbin "build/assets/graphics/rl_0831CA80.bin"
	.space 3
	.global gModule_0201AF6C
gModule_0201AF6C:
	.incbin "build/assets/graphics/rl_0831CAC8.bin"
	.global gModule_0201AFA8
gModule_0201AFA8:
	.incbin "build/assets/graphics/rl_0831CB04.bin"
	.space 2
	.global gModule_0201AFF0
gModule_0201AFF0:
	.incbin "build/assets/graphics/rl_0831CB4C.bin"
	.space 3
	.global gModule_0201B038
gModule_0201B038:
	.incbin "build/assets/graphics/rl_0831CB94.bin"
	.space 3
	.global gModule_0201B080
gModule_0201B080:
	.incbin "build/assets/graphics/rl_0831CBDC.bin"
	.space 3
	.global gModule_0201B0C8
gModule_0201B0C8:
	.incbin "build/assets/graphics/rl_0831CC24.bin"
	.space 3
	.global gModule_0201B110
gModule_0201B110:
	.incbin "build/assets/graphics/rl_0831CC6C.bin"
	.space 3
	.global gModule_0201B158
gModule_0201B158:
	.incbin "build/assets/graphics/rl_0831CCB4.bin"
	.space 3
	.global gModule_0201B1A0
gModule_0201B1A0:
	.incbin "build/assets/graphics/rl_0831CCFC.bin"
	.space 3
	.global gModule_0201B1E8
gModule_0201B1E8:
	.incbin "build/assets/graphics/rl_0831CD44.bin"
	.space 3
	.global gModule_0201B230
gModule_0201B230:
	.incbin "build/assets/graphics/rl_0831CD8C.bin"
	.space 3
	.global gModule_0201B278
gModule_0201B278:
	.incbin "build/assets/graphics/rl_0831CDD4.bin"
	.space 3
	.global gModule_0201B2C0
gModule_0201B2C0:
	.incbin "build/assets/graphics/rl_0831CE1C.bin"
	.space 3
	.global gModule_0201B308
gModule_0201B308:
	.incbin "build/assets/graphics/rl_0831CE64.bin"
	.space 3
	.global gModule_0201B350
gModule_0201B350:
	.incbin "build/assets/graphics/rl_0831CEAC.bin"
	.space 3
	.global gModule_0201B398
gModule_0201B398:
	.incbin "build/assets/graphics/rl_0831CEF4.bin"
	.space 3
	.global gModule_0201B3E0
gModule_0201B3E0:
	.incbin "build/assets/graphics/rl_0831CF3C.bin"
	.space 3
	.global gModule_0201B428
gModule_0201B428:
	.incbin "build/assets/graphics/rl_0831CF84.bin"
	.space 3
	.global gModule_0201B470
gModule_0201B470:
	.incbin "build/assets/graphics/rl_0831CFCC.bin"
	.space 3
	.global gModule_0201B4B8
gModule_0201B4B8:
	.incbin "build/assets/graphics/rl_0831D014.bin"
	.space 3
	.global gModule_0201B500
gModule_0201B500:
	.incbin "build/assets/graphics/rl_0831D05C.bin"
	.space 3
	.global gModule_0201B548
gModule_0201B548:
	.incbin "build/assets/graphics/rl_0831D0A4.bin"
	.space 3
