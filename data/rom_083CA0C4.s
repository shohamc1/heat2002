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
	.global gUnk_083CA0C4
gUnk_083CA0C4:
	.incbin "build/assets/tracks/hooley_downs/wall_verts.bin", 0, 2328
	.global gUnk_083CA9DC
gUnk_083CA9DC:
	.incbin "build/assets/tracks/hooley_downs/wall_recs.bin", 0, 9216
	.global gUnk_083CCDDC
gUnk_083CCDDC:
	.incbin "build/assets/tracks/hooley_downs/wall_lists.bin", 0, 3260
	.global gUnk_083CDA98
gUnk_083CDA98:
	.incbin "build/assets/tracks/hooley_downs/wall_grid.bin", 0, 4608
	.global gUnk_083CEC98
gUnk_083CEC98:
	.incbin "build/assets/tracks/green_valley/wall_verts.bin", 0, 2872
	.global gUnk_083CF7D0
gUnk_083CF7D0:
	.incbin "build/assets/tracks/green_valley/wall_recs.bin", 0, 11360
	.global gUnk_083D2430
gUnk_083D2430:
	.incbin "build/assets/tracks/green_valley/wall_lists.bin", 0, 3704
	.global gUnk_083D32A8
gUnk_083D32A8:
	.incbin "build/assets/tracks/green_valley/wall_grid.bin", 0, 4608
	.global gUnk_083D44A8
gUnk_083D44A8:
	.incbin "build/assets/tracks/darlington_raceway/wall_verts.bin", 0, 1408
	.global gUnk_083D4A28
gUnk_083D4A28:
	.incbin "build/assets/tracks/darlington_raceway/wall_recs.bin", 0, 5504
	.global gUnk_083D5FA8
gUnk_083D5FA8:
	.incbin "build/assets/tracks/darlington_raceway/wall_lists.bin", 0, 1782
	.global gUnk_083D669E
gUnk_083D669E:
	.incbin "build/assets/tracks/darlington_raceway/wall_grid.bin", 0, 4610
	.global gUnk_083D78A0
gUnk_083D78A0:
	.incbin "build/assets/tracks/michigan_international_speedway/wall_verts.bin", 0, 1856
	.global gUnk_083D7FE0
gUnk_083D7FE0:
	.incbin "build/assets/tracks/michigan_international_speedway/wall_recs.bin", 0, 7328
	.global gUnk_083D9C80
gUnk_083D9C80:
	.incbin "build/assets/tracks/michigan_international_speedway/wall_lists.bin", 0, 2384
	.global gUnk_083DA5D0
gUnk_083DA5D0:
	.incbin "build/assets/tracks/michigan_international_speedway/wall_grid.bin", 0, 4608
	.global gUnk_083DB7D0
gUnk_083DB7D0:
	.incbin "build/assets/tracks/great_canyon/wall_verts.bin", 0, 2544
	.global gUnk_083DC1C0
gUnk_083DC1C0:
	.incbin "build/assets/tracks/great_canyon/wall_recs.bin", 0, 10080
	.global gUnk_083DE920
gUnk_083DE920:
	.incbin "build/assets/tracks/great_canyon/wall_lists.bin", 0, 3344
	.global gUnk_083DF630
gUnk_083DF630:
	.incbin "build/assets/tracks/great_canyon/wall_grid.bin", 0, 4608
	.global gUnk_083E0830
gUnk_083E0830:
	.incbin "build/assets/tracks/fuji_port/wall_verts.bin", 0, 2656
	.global gUnk_083E1290
gUnk_083E1290:
	.incbin "build/assets/tracks/fuji_port/wall_recs.bin", 0, 10528
	.global gUnk_083E3BB0
gUnk_083E3BB0:
	.incbin "build/assets/tracks/fuji_port/wall_lists.bin", 0, 3728
	.global gUnk_083E4A40
gUnk_083E4A40:
	.incbin "build/assets/tracks/fuji_port/wall_grid.bin", 0, 4608
	.global gUnk_083E5C40
gUnk_083E5C40:
	.incbin "build/assets/tracks/crawfish_raceway/wall_verts.bin", 0, 1496
	.global gUnk_083E6218
gUnk_083E6218:
	.incbin "build/assets/tracks/crawfish_raceway/wall_recs.bin", 0, 5888
	.global gUnk_083E7918
gUnk_083E7918:
	.incbin "build/assets/tracks/crawfish_raceway/wall_lists.bin", 0, 2226
	.global gUnk_083E81CA
gUnk_083E81CA:
	.incbin "build/assets/tracks/crawfish_raceway/wall_grid.bin", 0, 4610
	.global gUnk_083E93CC
gUnk_083E93CC:
	.incbin "build/assets/tracks/purley_park/wall_verts.bin", 0, 1440
	.global gUnk_083E996C
gUnk_083E996C:
	.incbin "build/assets/tracks/purley_park/wall_recs.bin", 0, 5696
	.global gUnk_083EAFAC
gUnk_083EAFAC:
	.incbin "build/assets/tracks/purley_park/wall_lists.bin", 0, 2276
	.global gUnk_083EB890
gUnk_083EB890:
	.incbin "build/assets/tracks/purley_park/wall_grid.bin", 0, 4608
	.global gUnk_083ECA90
gUnk_083ECA90:
	.incbin "build/assets/tracks/kansas_speedway/wall_verts.bin", 0, 1456
	.global gUnk_083ED040
gUnk_083ED040:
	.incbin "build/assets/tracks/kansas_speedway/wall_recs.bin", 0, 5728
	.global gUnk_083EE6A0
gUnk_083EE6A0:
	.incbin "build/assets/tracks/kansas_speedway/wall_lists.bin", 0, 2020
	.global gUnk_083EEE84
gUnk_083EEE84:
	.incbin "build/assets/tracks/kansas_speedway/wall_grid.bin", 0, 4608
	.global gUnk_083F0084
gUnk_083F0084:
	.incbin "build/assets/tracks/asphalt_city/wall_verts.bin", 0, 3136
	.global gUnk_083F0CC4
gUnk_083F0CC4:
	.incbin "build/assets/tracks/asphalt_city/wall_recs.bin", 0, 12448
	.global gUnk_083F3D64
gUnk_083F3D64:
	.incbin "build/assets/tracks/asphalt_city/wall_lists.bin", 0, 4062
	.global gUnk_083F4D42
gUnk_083F4D42:
	.incbin "build/assets/tracks/asphalt_city/wall_grid.bin", 0, 4610
	.global gUnk_083F5F44
gUnk_083F5F44:
	.incbin "build/assets/tracks/phoenix_international_raceway/wall_verts.bin", 0, 1376
	.global gUnk_083F64A4
gUnk_083F64A4:
	.incbin "build/assets/tracks/phoenix_international_raceway/wall_recs.bin", 0, 5408
	.global gUnk_083F79C4
gUnk_083F79C4:
	.incbin "build/assets/tracks/phoenix_international_raceway/wall_lists.bin", 0, 1792
	.global gUnk_083F80C4
gUnk_083F80C4:
	.incbin "build/assets/tracks/phoenix_international_raceway/wall_grid.bin", 0, 4608
	.global gUnk_083F92C4
gUnk_083F92C4:
	.incbin "build/assets/tracks/infogrames_super_speedway/wall_verts.bin", 0, 2128
	.global gUnk_083F9B14
gUnk_083F9B14:
	.incbin "build/assets/tracks/infogrames_super_speedway/wall_recs.bin", 0, 8416
	.global gUnk_083FBBF4
gUnk_083FBBF4:
	.incbin "build/assets/tracks/infogrames_super_speedway/wall_lists.bin", 0, 2856
	.global gUnk_083FC71C
gUnk_083FC71C:
	.incbin "build/assets/tracks/infogrames_super_speedway/wall_grid.bin", 0, 4608
