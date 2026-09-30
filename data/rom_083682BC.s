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
	.global gUnk_083682BC
gUnk_083682BC:
	.incbin "build/assets/tracks/hooley_downs/lane_points_0.bin", 0, 400
	.global gLaneSegs_Track0_Lane00
gLaneSegs_Track0_Lane00:
	.incbin "build/assets/tracks/hooley_downs/lane_segs_0.bin", 0, 2000
	.global gUnk_08368C1C
gUnk_08368C1C:
	.incbin "build/assets/tracks/hooley_downs/lane_cells_0.bin", 0, 914
	.global gUnk_08368FAE
gUnk_08368FAE:
	.incbin "build/assets/tracks/hooley_downs/lane_cells_0.bin", 914, 4608
	.incbin "build/assets/tracks/hooley_downs/lane_orphan_0.bin"
	.global gUnk_0836A1B0
gUnk_0836A1B0:
	.incbin "build/assets/tracks/hooley_downs/lane_points_4.bin", 0, 360
	.global gLaneSegs_Track0_Lane04
gLaneSegs_Track0_Lane04:
	.incbin "build/assets/tracks/hooley_downs/lane_segs_4.bin", 0, 1800
	.global gUnk_0836AA20
gUnk_0836AA20:
	.incbin "build/assets/tracks/hooley_downs/lane_cells_4.bin", 0, 930
	.global gUnk_0836ADC2
gUnk_0836ADC2:
	.incbin "build/assets/tracks/hooley_downs/lane_cells_4.bin", 930, 4608
	.incbin "build/assets/tracks/hooley_downs/lane_orphan_1.bin"
	.global gUnk_0836BFC4
gUnk_0836BFC4:
	.incbin "build/assets/tracks/hooley_downs/lane_points_7.bin", 0, 356
	.global gLaneSegs_Track0_Lane07
gLaneSegs_Track0_Lane07:
	.incbin "build/assets/tracks/hooley_downs/lane_segs_7.bin", 0, 1780
	.global gUnk_0836C81C
gUnk_0836C81C:
	.incbin "build/assets/tracks/hooley_downs/lane_cells_7.bin", 0, 804
	.global gUnk_0836CB40
gUnk_0836CB40:
	.incbin "build/assets/tracks/hooley_downs/lane_cells_7.bin", 804, 4608
	.incbin "build/assets/tracks/hooley_downs/lane_orphan_2.bin"
	.global gUnk_0836DD42
gUnk_0836DD42:
	.incbin "build/assets/tracks/hooley_downs/lane_lengths.bin", 0, 8
	.global gUnk_0836DD4A
gUnk_0836DD4A:
	.incbin "build/assets/tracks/hooley_downs/lane_lengths.bin", 8, 4
	.global gUnk_0836DD4E
gUnk_0836DD4E:
	.incbin "build/assets/tracks/hooley_downs/lane_lengths.bin", 12, 2
	.global gUnk_0836DD50
gUnk_0836DD50:
	.incbin "build/assets/tracks/darlington_raceway/lane_points_0.bin", 0, 236
	.global gLaneSegs_Track1_Lane00
gLaneSegs_Track1_Lane00:
	.incbin "build/assets/tracks/darlington_raceway/lane_segs_0.bin", 0, 1180
	.global gUnk_0836E2D8
gUnk_0836E2D8:
	.incbin "build/assets/tracks/darlington_raceway/lane_cells_0.bin", 0, 514
	.global gUnk_0836E4DA
gUnk_0836E4DA:
	.incbin "build/assets/tracks/darlington_raceway/lane_cells_0.bin", 514, 4608
	.incbin "build/assets/tracks/darlington_raceway/lane_orphan_3.bin"
	.global gUnk_0836F6DC
gUnk_0836F6DC:
	.incbin "build/assets/tracks/darlington_raceway/lane_points_1.bin", 0, 192
	.global gLaneSegs_Track1_Lane01
gLaneSegs_Track1_Lane01:
	.incbin "build/assets/tracks/darlington_raceway/lane_segs_1.bin", 0, 960
	.global gUnk_0836FB5C
gUnk_0836FB5C:
	.incbin "build/assets/tracks/darlington_raceway/lane_cells_1.bin", 0, 430
	.global gUnk_0836FD0A
gUnk_0836FD0A:
	.incbin "build/assets/tracks/darlington_raceway/lane_cells_1.bin", 430, 4608
	.incbin "build/assets/tracks/darlington_raceway/lane_orphan_4.bin"
	.global gUnk_08370F0C
gUnk_08370F0C:
	.incbin "build/assets/tracks/darlington_raceway/lane_points_4.bin", 0, 200
	.global gLaneSegs_Track1_Lane04
gLaneSegs_Track1_Lane04:
	.incbin "build/assets/tracks/darlington_raceway/lane_segs_4.bin", 0, 1000
	.global gUnk_083713BC
gUnk_083713BC:
	.incbin "build/assets/tracks/darlington_raceway/lane_cells_4.bin", 0, 446
	.global gUnk_0837157A
gUnk_0837157A:
	.incbin "build/assets/tracks/darlington_raceway/lane_cells_4.bin", 446, 4608
	.incbin "build/assets/tracks/darlington_raceway/lane_orphan_5.bin"
	.global gUnk_0837401C
gUnk_0837401C:
	.incbin "build/assets/tracks/darlington_raceway/lane_lengths.bin", 0, 2
	.global gUnk_0837401E
gUnk_0837401E:
	.incbin "build/assets/tracks/darlington_raceway/lane_lengths.bin", 2, 8
	.global gUnk_08374026
gUnk_08374026:
	.incbin "build/assets/tracks/darlington_raceway/lane_lengths.bin", 10, 6
	.global gUnk_0837402C
gUnk_0837402C:
	.incbin "build/assets/tracks/green_valley/lane_points_0.bin", 0, 520
	.global gLaneSegs_Track2_Lane00
gLaneSegs_Track2_Lane00:
	.incbin "build/assets/tracks/green_valley/lane_segs_0.bin", 0, 2600
	.global gUnk_08374C5C
gUnk_08374C5C:
	.incbin "build/assets/tracks/green_valley/lane_cells_0.bin", 0, 1324
	.global gUnk_08375188
gUnk_08375188:
	.incbin "build/assets/tracks/green_valley/lane_cells_0.bin", 1324, 4608
	.global gUnk_08376388
gUnk_08376388:
	.incbin "build/assets/tracks/green_valley/lane_points_1.bin", 0, 492
	.global gLaneSegs_Track2_Lane01
gLaneSegs_Track2_Lane01:
	.incbin "build/assets/tracks/green_valley/lane_segs_1.bin", 0, 2460
	.global gUnk_08376F10
gUnk_08376F10:
	.incbin "build/assets/tracks/green_valley/lane_cells_1.bin", 0, 1272
	.global gUnk_08377408
gUnk_08377408:
	.incbin "build/assets/tracks/green_valley/lane_cells_1.bin", 1272, 4608
	.incbin "build/assets/tracks/green_valley/lane_orphan_6.bin"
	.global gUnk_0837EE98
gUnk_0837EE98:
	.incbin "build/assets/tracks/green_valley/lane_points_4.bin", 0, 504
	.global gLaneSegs_Track2_Lane04
gLaneSegs_Track2_Lane04:
	.incbin "build/assets/tracks/green_valley/lane_segs_4.bin", 0, 2520
	.global gUnk_0837FA68
gUnk_0837FA68:
	.incbin "build/assets/tracks/green_valley/lane_cells_4.bin", 0, 1284
	.global gUnk_0837FF6C
gUnk_0837FF6C:
	.incbin "build/assets/tracks/green_valley/lane_cells_4.bin", 1284, 4608
	.incbin "build/assets/tracks/green_valley/lane_orphan_7.bin"
	.global gUnk_08383430
gUnk_08383430:
	.incbin "build/assets/tracks/green_valley/lane_points_7.bin", 0, 492
	.global gLaneSegs_Track2_Lane07
gLaneSegs_Track2_Lane07:
	.incbin "build/assets/tracks/green_valley/lane_segs_7.bin", 0, 2460
	.global gUnk_08383FB8
gUnk_08383FB8:
	.incbin "build/assets/tracks/green_valley/lane_cells_7.bin", 0, 1254
	.global gUnk_0838449E
gUnk_0838449E:
	.incbin "build/assets/tracks/green_valley/lane_cells_7.bin", 1254, 4608
	.global gUnk_0838569E
gUnk_0838569E:
	.incbin "build/assets/tracks/green_valley/lane_lengths.bin", 0, 2
	.global gUnk_083856A0
gUnk_083856A0:
	.incbin "build/assets/tracks/green_valley/lane_lengths.bin", 2, 8
	.global gUnk_083856A8
gUnk_083856A8:
	.incbin "build/assets/tracks/green_valley/lane_lengths.bin", 10, 4
	.global gUnk_083856AC
gUnk_083856AC:
	.incbin "build/assets/tracks/green_valley/lane_lengths.bin", 14, 4
	.global gUnk_083856B0
gUnk_083856B0:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_points_0.bin", 0, 352
	.global gLaneSegs_Track3_Lane00
gLaneSegs_Track3_Lane00:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_segs_0.bin", 0, 1760
	.global gUnk_08385EF0
gUnk_08385EF0:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_cells_0.bin", 0, 840
	.global gUnk_08386238
gUnk_08386238:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_cells_0.bin", 840, 4608
	.global gUnk_08387438
gUnk_08387438:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_points_1.bin", 0, 328
	.global gLaneSegs_Track3_Lane01
gLaneSegs_Track3_Lane01:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_segs_1.bin", 0, 1640
	.global gUnk_08387BE8
gUnk_08387BE8:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_cells_1.bin", 0, 758
	.global gUnk_08387EDE
gUnk_08387EDE:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_cells_1.bin", 758, 4608
	.incbin "build/assets/tracks/michigan_international_speedway/lane_orphan_8.bin"
	.global gUnk_083890E0
gUnk_083890E0:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_points_4.bin", 0, 344
	.global gLaneSegs_Track3_Lane04
gLaneSegs_Track3_Lane04:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_segs_4.bin", 0, 1720
	.global gUnk_083898F0
gUnk_083898F0:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_cells_4.bin", 0, 738
	.global gUnk_08389BD2
gUnk_08389BD2:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_cells_4.bin", 738, 4608
	.incbin "build/assets/tracks/michigan_international_speedway/lane_orphan_9.bin"
	.global gUnk_0838ADD4
gUnk_0838ADD4:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_points_7.bin", 0, 380
	.global gLaneSegs_Track3_Lane07
gLaneSegs_Track3_Lane07:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_segs_7.bin", 0, 1900
	.global gUnk_0838B6BC
gUnk_0838B6BC:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_cells_7.bin", 0, 882
	.global gUnk_0838BA2E
gUnk_0838BA2E:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_cells_7.bin", 882, 4608
	.global gUnk_0838CC2E
gUnk_0838CC2E:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_lengths.bin", 0, 2
	.global gUnk_0838CC30
gUnk_0838CC30:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_lengths.bin", 2, 8
	.global gUnk_0838CC38
gUnk_0838CC38:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_lengths.bin", 10, 4
	.global gUnk_0838CC3C
gUnk_0838CC3C:
	.incbin "build/assets/tracks/michigan_international_speedway/lane_lengths.bin", 14, 4
	.global gUnk_0838CC40
gUnk_0838CC40:
	.incbin "build/assets/tracks/great_canyon/lane_points_0.bin", 0, 608
	.global gLaneSegs_Track4_Lane00
gLaneSegs_Track4_Lane00:
	.incbin "build/assets/tracks/great_canyon/lane_segs_0.bin", 0, 3020
	.global gUnk_0838DA6C
gUnk_0838DA6C:
	.incbin "build/assets/tracks/great_canyon/lane_cells_0.bin", 0, 1468
	.global gUnk_0838E028
gUnk_0838E028:
	.incbin "build/assets/tracks/great_canyon/lane_cells_0.bin", 1468, 4608
	.global gUnk_0838F228
gUnk_0838F228:
	.incbin "build/assets/tracks/great_canyon/lane_points_1.bin", 0, 596
	.global gLaneSegs_Track4_Lane01
gLaneSegs_Track4_Lane01:
	.incbin "build/assets/tracks/great_canyon/lane_segs_1.bin", 0, 2980
	.global gUnk_08390020
gUnk_08390020:
	.incbin "build/assets/tracks/great_canyon/lane_cells_1.bin", 0, 1484
	.global gUnk_083905EC
gUnk_083905EC:
	.incbin "build/assets/tracks/great_canyon/lane_cells_1.bin", 1484, 4608
	.global gUnk_083917EC
gUnk_083917EC:
	.incbin "build/assets/tracks/great_canyon/lane_points_4.bin", 0, 640
	.global gLaneSegs_Track4_Lane04
gLaneSegs_Track4_Lane04:
	.incbin "build/assets/tracks/great_canyon/lane_segs_4.bin", 0, 3200
	.global gUnk_083926EC
gUnk_083926EC:
	.incbin "build/assets/tracks/great_canyon/lane_cells_4.bin", 0, 1534
	.global gUnk_08392CEA
gUnk_08392CEA:
	.incbin "build/assets/tracks/great_canyon/lane_cells_4.bin", 1534, 4608
	.incbin "build/assets/tracks/great_canyon/lane_orphan_10.bin"
	.global gUnk_08393EEC
gUnk_08393EEC:
	.incbin "build/assets/tracks/great_canyon/lane_points_7.bin", 0, 596
	.global gLaneSegs_Track4_Lane07
gLaneSegs_Track4_Lane07:
	.incbin "build/assets/tracks/great_canyon/lane_segs_7.bin", 0, 2980
	.global gUnk_08394CE4
gUnk_08394CE4:
	.incbin "build/assets/tracks/great_canyon/lane_cells_7.bin", 0, 1366
	.global gUnk_0839523A
gUnk_0839523A:
	.incbin "build/assets/tracks/great_canyon/lane_cells_7.bin", 1366, 4608
	.global gUnk_0839643A
gUnk_0839643A:
	.incbin "build/assets/tracks/great_canyon/lane_lengths.bin", 0, 2
	.global gUnk_0839643C
gUnk_0839643C:
	.incbin "build/assets/tracks/great_canyon/lane_lengths.bin", 2, 8
	.global gUnk_08396444
gUnk_08396444:
	.incbin "build/assets/tracks/great_canyon/lane_lengths.bin", 10, 4
	.global gUnk_08396448
gUnk_08396448:
	.incbin "build/assets/tracks/great_canyon/lane_lengths.bin", 14, 4
	.global gUnk_0839644C
gUnk_0839644C:
	.incbin "build/assets/tracks/fuji_port/lane_points_0.bin", 0, 484
	.global gLaneSegs_Track5_Lane00
gLaneSegs_Track5_Lane00:
	.incbin "build/assets/tracks/fuji_port/lane_segs_0.bin", 0, 2420
	.global gUnk_08396FA4
gUnk_08396FA4:
	.incbin "build/assets/tracks/fuji_port/lane_cells_0.bin", 0, 1170
	.global gUnk_08397436
gUnk_08397436:
	.incbin "build/assets/tracks/fuji_port/lane_cells_0.bin", 1170, 4608
	.incbin "build/assets/tracks/fuji_port/lane_orphan_11.bin"
	.global gUnk_08398638
gUnk_08398638:
	.incbin "build/assets/tracks/fuji_port/lane_points_1.bin", 0, 492
	.global gLaneSegs_Track5_Lane01
gLaneSegs_Track5_Lane01:
	.incbin "build/assets/tracks/fuji_port/lane_segs_1.bin", 0, 2460
	.global gUnk_083991C0
gUnk_083991C0:
	.incbin "build/assets/tracks/fuji_port/lane_cells_1.bin", 0, 1222
	.global gUnk_08399686
gUnk_08399686:
	.incbin "build/assets/tracks/fuji_port/lane_cells_1.bin", 1222, 4608
	.incbin "build/assets/tracks/fuji_port/lane_orphan_12.bin"
	.global gUnk_0839A888
gUnk_0839A888:
	.incbin "build/assets/tracks/fuji_port/lane_points_4.bin", 0, 452
	.global gLaneSegs_Track5_Lane04
gLaneSegs_Track5_Lane04:
	.incbin "build/assets/tracks/fuji_port/lane_segs_4.bin", 0, 2260
	.global gUnk_0839B320
gUnk_0839B320:
	.incbin "build/assets/tracks/fuji_port/lane_cells_4.bin", 0, 1128
	.global gUnk_0839B788
gUnk_0839B788:
	.incbin "build/assets/tracks/fuji_port/lane_cells_4.bin", 1128, 4608
	.global gUnk_0839C988
gUnk_0839C988:
	.incbin "build/assets/tracks/fuji_port/lane_points_7.bin", 0, 500
	.global gLaneSegs_Track5_Lane07
gLaneSegs_Track5_Lane07:
	.incbin "build/assets/tracks/fuji_port/lane_segs_7.bin", 0, 2500
	.global gUnk_0839D540
gUnk_0839D540:
	.incbin "build/assets/tracks/fuji_port/lane_cells_7.bin", 0, 1316
	.global gUnk_0839DA64
gUnk_0839DA64:
	.incbin "build/assets/tracks/fuji_port/lane_cells_7.bin", 1316, 4608
	.global gUnk_0839EC64
gUnk_0839EC64:
	.incbin "build/assets/tracks/fuji_port/lane_lengths.bin", 0, 2
	.global gUnk_0839EC66
gUnk_0839EC66:
	.incbin "build/assets/tracks/fuji_port/lane_lengths.bin", 2, 8
	.global gUnk_0839EC6E
gUnk_0839EC6E:
	.incbin "build/assets/tracks/fuji_port/lane_lengths.bin", 10, 4
	.global gUnk_0839EC72
gUnk_0839EC72:
	.incbin "build/assets/tracks/fuji_port/lane_lengths.bin", 14, 2
	.global gUnk_0839EC74
gUnk_0839EC74:
	.incbin "build/assets/tracks/crawfish_raceway/lane_points_0.bin", 0, 240
	.global gLaneSegs_Track6_Lane00
gLaneSegs_Track6_Lane00:
	.incbin "build/assets/tracks/crawfish_raceway/lane_segs_0.bin", 0, 1200
	.global gUnk_0839F214
gUnk_0839F214:
	.incbin "build/assets/tracks/crawfish_raceway/lane_cells_0.bin", 0, 402
	.global gUnk_0839F3A6
gUnk_0839F3A6:
	.incbin "build/assets/tracks/crawfish_raceway/lane_cells_0.bin", 402, 4608
	.incbin "build/assets/tracks/crawfish_raceway/lane_orphan_13.bin"
	.global gUnk_083A05A8
gUnk_083A05A8:
	.incbin "build/assets/tracks/crawfish_raceway/lane_points_1.bin", 0, 252
	.global gLaneSegs_Track6_Lane01
gLaneSegs_Track6_Lane01:
	.incbin "build/assets/tracks/crawfish_raceway/lane_segs_1.bin", 0, 1260
	.global gUnk_083A0B90
gUnk_083A0B90:
	.incbin "build/assets/tracks/crawfish_raceway/lane_cells_1.bin", 0, 532
	.global gUnk_083A0DA4
gUnk_083A0DA4:
	.incbin "build/assets/tracks/crawfish_raceway/lane_cells_1.bin", 532, 4608
	.global gUnk_083A1FA4
gUnk_083A1FA4:
	.incbin "build/assets/tracks/crawfish_raceway/lane_points_4.bin", 0, 300
	.global gLaneSegs_Track6_Lane04
gLaneSegs_Track6_Lane04:
	.incbin "build/assets/tracks/crawfish_raceway/lane_segs_4.bin", 0, 1500
	.global gUnk_083A26AC
gUnk_083A26AC:
	.incbin "build/assets/tracks/crawfish_raceway/lane_cells_4.bin", 0, 696
	.global gUnk_083A2964
gUnk_083A2964:
	.incbin "build/assets/tracks/crawfish_raceway/lane_cells_4.bin", 696, 4608
	.global gUnk_083A3B64
gUnk_083A3B64:
	.incbin "build/assets/tracks/crawfish_raceway/lane_points_7.bin", 0, 280
	.global gLaneSegs_Track6_Lane07
gLaneSegs_Track6_Lane07:
	.incbin "build/assets/tracks/crawfish_raceway/lane_segs_7.bin", 0, 1400
	.global gUnk_083A41F4
gUnk_083A41F4:
	.incbin "build/assets/tracks/crawfish_raceway/lane_cells_7.bin", 0, 612
	.global gUnk_083A4458
gUnk_083A4458:
	.incbin "build/assets/tracks/crawfish_raceway/lane_cells_7.bin", 612, 4608
	.global gUnk_083A5658
gUnk_083A5658:
	.incbin "build/assets/tracks/crawfish_raceway/lane_lengths.bin", 0, 2
	.global gUnk_083A565A
gUnk_083A565A:
	.incbin "build/assets/tracks/crawfish_raceway/lane_lengths.bin", 2, 2
	.global gUnk_083A565C
gUnk_083A565C:
	.incbin "build/assets/tracks/crawfish_raceway/lane_lengths.bin", 4, 6
	.global gUnk_083A5662
gUnk_083A5662:
	.incbin "build/assets/tracks/crawfish_raceway/lane_lengths.bin", 10, 4
	.global gUnk_083A5666
gUnk_083A5666:
	.incbin "build/assets/tracks/crawfish_raceway/lane_lengths.bin", 14, 2
	.global gUnk_083A5668
gUnk_083A5668:
	.incbin "build/assets/tracks/kansas_speedway/lane_points_0.bin", 0, 284
	.global gLaneSegs_Track8_Lane00
gLaneSegs_Track8_Lane00:
	.incbin "build/assets/tracks/kansas_speedway/lane_segs_0.bin", 0, 1420
	.global gUnk_083A5D10
gUnk_083A5D10:
	.incbin "build/assets/tracks/kansas_speedway/lane_cells_0.bin", 0, 558
	.global gUnk_083A5F3E
gUnk_083A5F3E:
	.incbin "build/assets/tracks/kansas_speedway/lane_cells_0.bin", 558, 4608
	.incbin "build/assets/tracks/kansas_speedway/lane_orphan_14.bin"
	.global gUnk_083A7140
gUnk_083A7140:
	.incbin "build/assets/tracks/kansas_speedway/lane_points_1.bin", 0, 304
	.global gLaneSegs_Track8_Lane01
gLaneSegs_Track8_Lane01:
	.incbin "build/assets/tracks/kansas_speedway/lane_segs_1.bin", 0, 1520
	.global gUnk_083A7860
gUnk_083A7860:
	.incbin "build/assets/tracks/kansas_speedway/lane_cells_1.bin", 0, 712
	.global gUnk_083A7B28
gUnk_083A7B28:
	.incbin "build/assets/tracks/kansas_speedway/lane_cells_1.bin", 712, 4608
	.global gUnk_083A8D28
gUnk_083A8D28:
	.incbin "build/assets/tracks/kansas_speedway/lane_points_4.bin", 0, 312
	.global gLaneSegs_Track8_Lane04
gLaneSegs_Track8_Lane04:
	.incbin "build/assets/tracks/kansas_speedway/lane_segs_4.bin", 0, 1560
	.global gUnk_083A9478
gUnk_083A9478:
	.incbin "build/assets/tracks/kansas_speedway/lane_cells_4.bin", 0, 664
	.global gUnk_083A9710
gUnk_083A9710:
	.incbin "build/assets/tracks/kansas_speedway/lane_cells_4.bin", 664, 4608
	.global gUnk_083AA910
gUnk_083AA910:
	.incbin "build/assets/tracks/kansas_speedway/lane_points_7.bin", 0, 320
	.global gLaneSegs_Track8_Lane07
gLaneSegs_Track8_Lane07:
	.incbin "build/assets/tracks/kansas_speedway/lane_segs_7.bin", 0, 1600
	.global gUnk_083AB090
gUnk_083AB090:
	.incbin "build/assets/tracks/kansas_speedway/lane_cells_7.bin", 0, 732
	.global gUnk_083AB36C
gUnk_083AB36C:
	.incbin "build/assets/tracks/kansas_speedway/lane_cells_7.bin", 732, 4608
	.global gUnk_083AC56C
gUnk_083AC56C:
	.incbin "build/assets/tracks/kansas_speedway/lane_lengths.bin", 0, 2
	.global gUnk_083AC56E
gUnk_083AC56E:
	.incbin "build/assets/tracks/kansas_speedway/lane_lengths.bin", 2, 8
	.global gUnk_083AC576
gUnk_083AC576:
	.incbin "build/assets/tracks/kansas_speedway/lane_lengths.bin", 10, 4
	.global gUnk_083AC57A
gUnk_083AC57A:
	.incbin "build/assets/tracks/kansas_speedway/lane_lengths.bin", 14, 2
	.global gUnk_083AC57C
gUnk_083AC57C:
	.incbin "build/assets/tracks/asphalt_city/lane_points_0.bin", 0, 516
	.global gLaneSegs_Track9_Lane00
gLaneSegs_Track9_Lane00:
	.incbin "build/assets/tracks/asphalt_city/lane_segs_0.bin", 0, 2580
	.global gUnk_083AD194
gUnk_083AD194:
	.incbin "build/assets/tracks/asphalt_city/lane_cells_0.bin", 0, 1254
	.global gUnk_083AD67A
gUnk_083AD67A:
	.incbin "build/assets/tracks/asphalt_city/lane_cells_0.bin", 1254, 4608
	.incbin "build/assets/tracks/asphalt_city/lane_orphan_15.bin"
	.global gUnk_083AE87C
gUnk_083AE87C:
	.incbin "build/assets/tracks/asphalt_city/lane_points_1.bin", 0, 524
	.global gLaneSegs_Track9_Lane01
gLaneSegs_Track9_Lane01:
	.incbin "build/assets/tracks/asphalt_city/lane_segs_1.bin", 0, 2620
	.global gUnk_083AF4C4
gUnk_083AF4C4:
	.incbin "build/assets/tracks/asphalt_city/lane_cells_1.bin", 0, 1256
	.global gUnk_083AF9AC
gUnk_083AF9AC:
	.incbin "build/assets/tracks/asphalt_city/lane_cells_1.bin", 1256, 4608
	.incbin "build/assets/tracks/asphalt_city/lane_orphan_16.bin"
	.global gUnk_083B73C0
gUnk_083B73C0:
	.incbin "build/assets/tracks/asphalt_city/lane_points_4.bin", 0, 516
	.global gLaneSegs_Track9_Lane04
gLaneSegs_Track9_Lane04:
	.incbin "build/assets/tracks/asphalt_city/lane_segs_4.bin", 0, 2580
	.global gUnk_083B7FD8
gUnk_083B7FD8:
	.incbin "build/assets/tracks/asphalt_city/lane_cells_4.bin", 0, 1260
	.global gUnk_083B84C4
gUnk_083B84C4:
	.incbin "build/assets/tracks/asphalt_city/lane_cells_4.bin", 1260, 4608
	.global gUnk_083B96C4
gUnk_083B96C4:
	.incbin "build/assets/tracks/asphalt_city/lane_points_7.bin", 0, 508
	.global gLaneSegs_Track9_Lane07
gLaneSegs_Track9_Lane07:
	.incbin "build/assets/tracks/asphalt_city/lane_segs_7.bin", 0, 2540
	.global gUnk_083BA2AC
gUnk_083BA2AC:
	.incbin "build/assets/tracks/asphalt_city/lane_cells_7.bin", 0, 1250
	.global gUnk_083BA78E
gUnk_083BA78E:
	.incbin "build/assets/tracks/asphalt_city/lane_cells_7.bin", 1250, 4608
	.global gUnk_083BB98E
gUnk_083BB98E:
	.incbin "build/assets/tracks/asphalt_city/lane_lengths.bin", 0, 2
	.global gUnk_083BB990
gUnk_083BB990:
	.incbin "build/assets/tracks/asphalt_city/lane_lengths.bin", 2, 8
	.global gUnk_083BB998
gUnk_083BB998:
	.incbin "build/assets/tracks/asphalt_city/lane_lengths.bin", 10, 4
	.global gUnk_083BB99C
gUnk_083BB99C:
	.incbin "build/assets/tracks/asphalt_city/lane_lengths.bin", 14, 4
	.global gUnk_083BB9A0
gUnk_083BB9A0:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_points_0.bin", 0, 192
	.global gLaneSegs_Track10_Lane00
gLaneSegs_Track10_Lane00:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_segs_0.bin", 0, 960
	.global gUnk_083BBE20
gUnk_083BBE20:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_cells_0.bin", 0, 376
	.global gUnk_083BBF98
gUnk_083BBF98:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_cells_0.bin", 376, 4608
	.global gUnk_083BD198
gUnk_083BD198:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_points_1.bin", 0, 188
	.global gLaneSegs_Track10_Lane01
gLaneSegs_Track10_Lane01:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_segs_1.bin", 0, 940
	.global gUnk_083BD600
gUnk_083BD600:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_cells_1.bin", 0, 378
	.global gUnk_083BD77A
gUnk_083BD77A:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_cells_1.bin", 378, 4608
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_orphan_17.bin"
	.global gUnk_083BE97C
gUnk_083BE97C:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_points_4.bin", 0, 172
	.global gLaneSegs_Track10_Lane04
gLaneSegs_Track10_Lane04:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_segs_4.bin", 0, 860
	.global gUnk_083BED84
gUnk_083BED84:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_cells_4.bin", 0, 340
	.global gUnk_083BEED8
gUnk_083BEED8:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_cells_4.bin", 340, 4608
	.global gUnk_083C00D8
gUnk_083C00D8:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_points_7.bin", 0, 220
	.global gLaneSegs_Track10_Lane07
gLaneSegs_Track10_Lane07:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_segs_7.bin", 0, 1100
	.global gUnk_083C0600
gUnk_083C0600:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_cells_7.bin", 0, 450
	.global gUnk_083C07C2
gUnk_083C07C2:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_cells_7.bin", 450, 4608
	.global gUnk_083C19C2
gUnk_083C19C2:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_lengths.bin", 0, 2
	.global gUnk_083C19C4
gUnk_083C19C4:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_lengths.bin", 2, 8
	.global gUnk_083C19CC
gUnk_083C19CC:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_lengths.bin", 10, 4
	.global gUnk_083C19D0
gUnk_083C19D0:
	.incbin "build/assets/tracks/phoenix_international_raceway/lane_lengths.bin", 14, 4
	.global gUnk_083C19D4
gUnk_083C19D4:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_points_0.bin", 0, 392
	.global gLaneSegs_Track11_Lane00
gLaneSegs_Track11_Lane00:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_segs_0.bin", 0, 1960
	.global gUnk_083C2304
gUnk_083C2304:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_cells_0.bin", 0, 890
	.global gUnk_083C267E
gUnk_083C267E:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_cells_0.bin", 890, 4608
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_orphan_18.bin"
	.global gUnk_083C3880
gUnk_083C3880:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_points_1.bin", 0, 392
	.global gLaneSegs_Track11_Lane01
gLaneSegs_Track11_Lane01:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_segs_1.bin", 0, 1960
	.global gUnk_083C41B0
gUnk_083C41B0:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_cells_1.bin", 0, 884
	.global gUnk_083C4524
gUnk_083C4524:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_cells_1.bin", 884, 4608
	.global gUnk_083C5724
gUnk_083C5724:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_points_4.bin", 0, 384
	.global gLaneSegs_Track11_Lane04
gLaneSegs_Track11_Lane04:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_segs_4.bin", 0, 1920
	.global gUnk_083C6024
gUnk_083C6024:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_cells_4.bin", 0, 888
	.global gUnk_083C639C
gUnk_083C639C:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_cells_4.bin", 888, 4608
	.global gUnk_083C759C
gUnk_083C759C:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_points_7.bin", 0, 420
	.global gLaneSegs_Track11_Lane07
gLaneSegs_Track11_Lane07:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_segs_7.bin", 0, 2100
	.global gUnk_083C7F74
gUnk_083C7F74:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_cells_7.bin", 0, 1006
	.global gUnk_083C8362
gUnk_083C8362:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_cells_7.bin", 1006, 4608
	.global gUnk_083C9562
gUnk_083C9562:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_lengths.bin", 0, 2
	.global gUnk_083C9564
gUnk_083C9564:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_lengths.bin", 2, 6
	.global gUnk_083C956A
gUnk_083C956A:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_lengths.bin", 8, 6
	.global gUnk_083C9570
gUnk_083C9570:
	.incbin "build/assets/tracks/infogrames_super_speedway/lane_lengths.bin", 14, 4
