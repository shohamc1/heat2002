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
	.align 2, 0
	.global gUnk_083CA0C4
gUnk_083CA0C4:
	cSym gUnk_083CA0C4
	.incbin "build/assets/tracks/hooley_downs/wall_verts.bin"
	.align 2, 0
	.global gUnk_083CA9DC
gUnk_083CA9DC:
	cSym gUnk_083CA9DC
	.incbin "build/assets/tracks/hooley_downs/wall_recs.bin"
	.align 1, 0
	.global gUnk_083CCDDC
gUnk_083CCDDC:
	cSym gUnk_083CCDDC
	.incbin "build/assets/tracks/hooley_downs/wall_lists.bin"
	.align 1, 0
	.global gUnk_083CDA98
gUnk_083CDA98:
	cSym gUnk_083CDA98
	.incbin "build/assets/tracks/hooley_downs/wall_grid.bin"
	.align 2, 0
	.global gUnk_083CEC98
gUnk_083CEC98:
	cSym gUnk_083CEC98
	.incbin "build/assets/tracks/green_valley/wall_verts.bin"
	.align 2, 0
	.global gUnk_083CF7D0
gUnk_083CF7D0:
	cSym gUnk_083CF7D0
	.incbin "build/assets/tracks/green_valley/wall_recs.bin"
	.align 1, 0
	.global gUnk_083D2430
gUnk_083D2430:
	cSym gUnk_083D2430
	.incbin "build/assets/tracks/green_valley/wall_lists.bin"
	.align 1, 0
	.global gUnk_083D32A8
gUnk_083D32A8:
	cSym gUnk_083D32A8
	.incbin "build/assets/tracks/green_valley/wall_grid.bin"
	.align 2, 0
	.global gUnk_083D44A8
gUnk_083D44A8:
	cSym gUnk_083D44A8
	.incbin "build/assets/tracks/darlington_raceway/wall_verts.bin"
	.align 2, 0
	.global gUnk_083D4A28
gUnk_083D4A28:
	cSym gUnk_083D4A28
	.incbin "build/assets/tracks/darlington_raceway/wall_recs.bin"
	.align 1, 0
	.global gUnk_083D5FA8
gUnk_083D5FA8:
	cSym gUnk_083D5FA8
	.incbin "build/assets/tracks/darlington_raceway/wall_lists.bin"
	.align 1, 0
	.global gUnk_083D669E
gUnk_083D669E:
	cSym gUnk_083D669E
	.incbin "build/assets/tracks/darlington_raceway/wall_grid.bin"
	.align 2, 0
	.global gUnk_083D78A0
gUnk_083D78A0:
	cSym gUnk_083D78A0
	.incbin "build/assets/tracks/michigan_international_speedway/wall_verts.bin"
	.align 2, 0
	.global gUnk_083D7FE0
gUnk_083D7FE0:
	cSym gUnk_083D7FE0
	.incbin "build/assets/tracks/michigan_international_speedway/wall_recs.bin"
	.align 1, 0
	.global gUnk_083D9C80
gUnk_083D9C80:
	cSym gUnk_083D9C80
	.incbin "build/assets/tracks/michigan_international_speedway/wall_lists.bin"
	.align 1, 0
	.global gUnk_083DA5D0
gUnk_083DA5D0:
	cSym gUnk_083DA5D0
	.incbin "build/assets/tracks/michigan_international_speedway/wall_grid.bin"
	.align 2, 0
	.global gUnk_083DB7D0
gUnk_083DB7D0:
	cSym gUnk_083DB7D0
	.incbin "build/assets/tracks/great_canyon/wall_verts.bin"
	.align 2, 0
	.global gUnk_083DC1C0
gUnk_083DC1C0:
	cSym gUnk_083DC1C0
	.incbin "build/assets/tracks/great_canyon/wall_recs.bin"
	.align 1, 0
	.global gUnk_083DE920
gUnk_083DE920:
	cSym gUnk_083DE920
	.incbin "build/assets/tracks/great_canyon/wall_lists.bin"
	.align 1, 0
	.global gUnk_083DF630
gUnk_083DF630:
	cSym gUnk_083DF630
	.incbin "build/assets/tracks/great_canyon/wall_grid.bin"
	.align 2, 0
	.global gUnk_083E0830
gUnk_083E0830:
	cSym gUnk_083E0830
	.incbin "build/assets/tracks/fuji_port/wall_verts.bin"
	.align 2, 0
	.global gUnk_083E1290
gUnk_083E1290:
	cSym gUnk_083E1290
	.incbin "build/assets/tracks/fuji_port/wall_recs.bin"
	.align 1, 0
	.global gUnk_083E3BB0
gUnk_083E3BB0:
	cSym gUnk_083E3BB0
	.incbin "build/assets/tracks/fuji_port/wall_lists.bin"
	.align 1, 0
	.global gUnk_083E4A40
gUnk_083E4A40:
	cSym gUnk_083E4A40
	.incbin "build/assets/tracks/fuji_port/wall_grid.bin"
	.align 2, 0
	.global gUnk_083E5C40
gUnk_083E5C40:
	cSym gUnk_083E5C40
	.incbin "build/assets/tracks/crawfish_raceway/wall_verts.bin"
	.align 2, 0
	.global gUnk_083E6218
gUnk_083E6218:
	cSym gUnk_083E6218
	.incbin "build/assets/tracks/crawfish_raceway/wall_recs.bin"
	.align 1, 0
	.global gUnk_083E7918
gUnk_083E7918:
	cSym gUnk_083E7918
	.incbin "build/assets/tracks/crawfish_raceway/wall_lists.bin"
	.align 1, 0
	.global gUnk_083E81CA
gUnk_083E81CA:
	cSym gUnk_083E81CA
	.incbin "build/assets/tracks/crawfish_raceway/wall_grid.bin"
	.align 2, 0
	.global gUnk_083E93CC
gUnk_083E93CC:
	cSym gUnk_083E93CC
	.incbin "build/assets/tracks/purley_park/wall_verts.bin"
	.align 2, 0
	.global gUnk_083E996C
gUnk_083E996C:
	cSym gUnk_083E996C
	.incbin "build/assets/tracks/purley_park/wall_recs.bin"
	.align 1, 0
	.global gUnk_083EAFAC
gUnk_083EAFAC:
	cSym gUnk_083EAFAC
	.incbin "build/assets/tracks/purley_park/wall_lists.bin"
	.align 1, 0
	.global gUnk_083EB890
gUnk_083EB890:
	cSym gUnk_083EB890
	.incbin "build/assets/tracks/purley_park/wall_grid.bin"
	.align 2, 0
	.global gUnk_083ECA90
gUnk_083ECA90:
	cSym gUnk_083ECA90
	.incbin "build/assets/tracks/kansas_speedway/wall_verts.bin"
	.align 2, 0
	.global gUnk_083ED040
gUnk_083ED040:
	cSym gUnk_083ED040
	.incbin "build/assets/tracks/kansas_speedway/wall_recs.bin"
	.align 1, 0
	.global gUnk_083EE6A0
gUnk_083EE6A0:
	cSym gUnk_083EE6A0
	.incbin "build/assets/tracks/kansas_speedway/wall_lists.bin"
	.align 1, 0
	.global gUnk_083EEE84
gUnk_083EEE84:
	cSym gUnk_083EEE84
	.incbin "build/assets/tracks/kansas_speedway/wall_grid.bin"
	.align 2, 0
	.global gUnk_083F0084
gUnk_083F0084:
	cSym gUnk_083F0084
	.incbin "build/assets/tracks/asphalt_city/wall_verts.bin"
	.align 2, 0
	.global gUnk_083F0CC4
gUnk_083F0CC4:
	cSym gUnk_083F0CC4
	.incbin "build/assets/tracks/asphalt_city/wall_recs.bin"
	.align 1, 0
	.global gUnk_083F3D64
gUnk_083F3D64:
	cSym gUnk_083F3D64
	.incbin "build/assets/tracks/asphalt_city/wall_lists.bin"
	.align 1, 0
	.global gUnk_083F4D42
gUnk_083F4D42:
	cSym gUnk_083F4D42
	.incbin "build/assets/tracks/asphalt_city/wall_grid.bin"
	.align 2, 0
	.global gUnk_083F5F44
gUnk_083F5F44:
	cSym gUnk_083F5F44
	.incbin "build/assets/tracks/phoenix_international_raceway/wall_verts.bin"
	.align 2, 0
	.global gUnk_083F64A4
gUnk_083F64A4:
	cSym gUnk_083F64A4
	.incbin "build/assets/tracks/phoenix_international_raceway/wall_recs.bin"
	.align 1, 0
	.global gUnk_083F79C4
gUnk_083F79C4:
	cSym gUnk_083F79C4
	.incbin "build/assets/tracks/phoenix_international_raceway/wall_lists.bin"
	.align 1, 0
	.global gUnk_083F80C4
gUnk_083F80C4:
	cSym gUnk_083F80C4
	.incbin "build/assets/tracks/phoenix_international_raceway/wall_grid.bin"
	.align 2, 0
	.global gUnk_083F92C4
gUnk_083F92C4:
	cSym gUnk_083F92C4
	.incbin "build/assets/tracks/infogrames_super_speedway/wall_verts.bin"
	.align 2, 0
	.global gUnk_083F9B14
gUnk_083F9B14:
	cSym gUnk_083F9B14
	.incbin "build/assets/tracks/infogrames_super_speedway/wall_recs.bin"
	.align 1, 0
	.global gUnk_083FBBF4
gUnk_083FBBF4:
	cSym gUnk_083FBBF4
	.incbin "build/assets/tracks/infogrames_super_speedway/wall_lists.bin"
	.align 1, 0
	.global gUnk_083FC71C
gUnk_083FC71C:
	cSym gUnk_083FC71C
	.incbin "build/assets/tracks/infogrames_super_speedway/wall_grid.bin"
