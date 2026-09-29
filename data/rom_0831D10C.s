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
	.global gUnk_0831D10C
gUnk_0831D10C:
	.incbin "build/assets/graphics/rl_0831D10C.bin"
	.align 2, 0
	.global gUnk_0831D240
gUnk_0831D240:
	.incbin "build/assets/graphics/rl_0831D240.bin"
	.align 2, 0
	.global gUnk_0831D36C
gUnk_0831D36C:
	.incbin "build/assets/graphics/rl_0831D36C.bin"
	.global gUnk_0831D4A4
gUnk_0831D4A4:
	.incbin "build/assets/graphics/rl_0831D4A4.bin"
	.align 2, 0
	.global gUnk_0831D5D8
gUnk_0831D5D8:
	.incbin "build/assets/graphics/rl_0831D5D8.bin"
	.align 2, 0
	.global gUnk_0831D6FC
gUnk_0831D6FC:
	.incbin "build/assets/graphics/rl_0831D6FC.bin"
	.align 2, 0
	.global gUnk_0831D81C
gUnk_0831D81C:
	.incbin "build/assets/graphics/rl_0831D81C.bin"
	.align 2, 0
	.global gUnk_0831D928
gUnk_0831D928:
	.incbin "build/assets/graphics/rl_0831D928.bin"
	.align 2, 0
	.global gUnk_0831DA34
gUnk_0831DA34:
	.incbin "build/assets/graphics/rl_0831DA34.bin"
	.align 2, 0
	.global gUnk_0831DB48
gUnk_0831DB48:
	.incbin "build/assets/graphics/rl_0831DB48.bin"
	.align 2, 0
	.global gUnk_0831DC5C
gUnk_0831DC5C:
	.incbin "build/assets/graphics/rl_0831DC5C.bin"
	.global gUnk_0831DD68
gUnk_0831DD68:
	.incbin "build/assets/graphics/rl_0831DD68.bin"
	.align 2, 0
	.global gUnk_0831DE74
gUnk_0831DE74:
	.incbin "build/assets/graphics/rl_0831DE74.bin"
	.align 2, 0
	.global gUnk_0831DF80
gUnk_0831DF80:
	.incbin "build/assets/graphics/rl_0831DF80.bin"
	.align 2, 0
	.global gUnk_0831E08C
gUnk_0831E08C:
	.incbin "build/assets/graphics/rl_0831E08C.bin"
	.align 2, 0
	.global gUnk_0831E198
gUnk_0831E198:
	.incbin "build/assets/graphics/rl_0831E198.bin"
	.align 2, 0
	.global gUnk_0831E2A8
gUnk_0831E2A8:
	.incbin "build/assets/graphics/rl_0831E2A8.bin"
	.align 2, 0
	.global gUnk_0831E3B0
gUnk_0831E3B0:
	.incbin "build/assets/graphics/rl_0831E3B0.bin"
	.align 2, 0
	.global gUnk_0831E4C0
gUnk_0831E4C0:
	.incbin "build/assets/graphics/rl_0831E4C0.bin"
	.global gUnk_0831E5C8
gUnk_0831E5C8:
	.incbin "build/assets/graphics/rl_0831E5C8.bin"
	.global gUnk_0831E6D8
gUnk_0831E6D8:
	.incbin "build/assets/graphics/rl_0831E6D8.bin"
	.align 2, 0
	.global gUnk_0831E7F0
gUnk_0831E7F0:
	.incbin "build/assets/graphics/rl_0831E7F0.bin"
	.global gUnk_0831E900
gUnk_0831E900:
	.incbin "build/assets/graphics/rl_0831E900.bin"
	.align 2, 0
	.global gUnk_0831EA10
gUnk_0831EA10:
	.incbin "build/assets/graphics/rl_0831EA10.bin"
	.global gUnk_0831EB28
gUnk_0831EB28:
	.incbin "build/assets/graphics/rl_0831EB28.bin"
	.global gUnk_0831EC3C
gUnk_0831EC3C:
	.incbin "build/assets/graphics/rl_0831EC3C.bin"
	.global gUnk_0831ED50
gUnk_0831ED50:
	.incbin "build/assets/graphics/rl_0831ED50.bin"
	.align 2, 0
	.global gUnk_0831EE60
gUnk_0831EE60:
	.incbin "build/assets/graphics/rl_0831EE60.bin"
	.global gUnk_0831EF64
gUnk_0831EF64:
	.incbin "build/assets/graphics/rl_0831EF64.bin"
	.global gUnk_0831F064
gUnk_0831F064:
	.incbin "build/assets/graphics/rl_0831F064.bin"
	.align 2, 0
	.global gUnk_0831F164
gUnk_0831F164:
	.incbin "build/assets/graphics/rl_0831F164.bin"
	.align 2, 0
	.global gUnk_0831F260
gUnk_0831F260:
	.incbin "build/assets/graphics/rl_0831F260.bin"
	.global gUnk_0831F354
gUnk_0831F354:
	.incbin "build/assets/graphics/rl_0831F354.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_0831F448.pal.bin"
	.global gUnk_0831F468
gUnk_0831F468:
	.incbin "build/assets/graphics/rl_0831F468.bin"
	.align 2, 0
	.global gUnk_0831F4C4
gUnk_0831F4C4:
	.incbin "build/assets/graphics/rl_0831F4C4.bin"
	.align 2, 0
	.global gUnk_0831F510
gUnk_0831F510:
	.incbin "build/assets/graphics/rl_0831F510.bin"
	.align 2, 0
	.global gUnk_0831F560
gUnk_0831F560:
	.incbin "build/assets/graphics/rl_0831F560.bin"
	.align 2, 0
	.global gUnk_0831F5B4
gUnk_0831F5B4:
	.incbin "build/assets/graphics/rl_0831F5B4.bin"
	.align 2, 0
	.global gUnk_0831F618
gUnk_0831F618:
	.incbin "build/assets/graphics/rl_0831F618.bin"
	.align 2, 0
	.global gUnk_0831F6A0
gUnk_0831F6A0:
	.incbin "build/assets/graphics/rl_0831F6A0.bin"
	.align 2, 0
	.global gUnk_0831F734
gUnk_0831F734:
	.incbin "build/assets/graphics/rl_0831F734.bin"
	.align 2, 0
	.global gUnk_0831F7C8
gUnk_0831F7C8:
	.incbin "build/assets/graphics/rl_0831F7C8.bin"
	.align 2, 0
	.global gUnk_0831F85C
gUnk_0831F85C:
	.incbin "build/assets/graphics/rl_0831F85C.bin"
	.align 2, 0
	.global gUnk_0831F8F0
gUnk_0831F8F0:
	.incbin "build/assets/graphics/rl_0831F8F0.bin"
	.align 2, 0
	.global gUnk_0831F984
gUnk_0831F984:
	.incbin "build/assets/graphics/rl_0831F984.bin"
	.align 2, 0
	.global gUnk_0831FA14
gUnk_0831FA14:
	.incbin "build/assets/graphics/rl_0831FA14.bin"
	.global gUnk_0831FAA0
gUnk_0831FAA0:
	.incbin "build/assets/graphics/rl_0831FAA0.bin"
	.align 2, 0
	.global gUnk_0831FB28
gUnk_0831FB28:
	.incbin "build/assets/graphics/rl_0831FB28.bin"
	.align 2, 0
	.global gUnk_0831FBAC
gUnk_0831FBAC:
	.incbin "build/assets/graphics/rl_0831FBAC.bin"
	.align 2, 0
	.global gUnk_0831FC30
gUnk_0831FC30:
	.incbin "build/assets/graphics/rl_0831FC30.bin"
	.align 2, 0
	.global gUnk_0831FCB0
gUnk_0831FCB0:
	.incbin "build/assets/graphics/rl_0831FCB0.bin"
	.align 2, 0
	.global gUnk_0831FD30
gUnk_0831FD30:
	.incbin "build/assets/graphics/rl_0831FD30.bin"
	.align 2, 0
	.global gUnk_0831FDB0
gUnk_0831FDB0:
	.incbin "build/assets/graphics/rl_0831FDB0.bin"
	.global gUnk_0831FE28
gUnk_0831FE28:
	.incbin "build/assets/graphics/rl_0831FE28.bin"
	.global gUnk_0831FE9C
gUnk_0831FE9C:
	.incbin "build/assets/graphics/rl_0831FE9C.bin"
	.align 2, 0
	.global gUnk_0831FF10
gUnk_0831FF10:
	.incbin "build/assets/graphics/rl_0831FF10.bin"
	.align 2, 0
	.global gUnk_0831FF7C
gUnk_0831FF7C:
	.incbin "build/assets/graphics/rl_0831FF7C.bin"
	.align 2, 0
	.global gUnk_0831FFE8
gUnk_0831FFE8:
	.incbin "build/assets/graphics/rl_0831FFE8.bin"
	.global gUnk_08320050
gUnk_08320050:
	.incbin "build/assets/graphics/rl_08320050.bin"
	.align 2, 0
	.global gUnk_083200B0
gUnk_083200B0:
	.incbin "build/assets/graphics/rl_083200B0.bin"
	.align 2, 0
	.global gUnk_083200F4
gUnk_083200F4:
	.incbin "build/assets/graphics/rl_083200F4.bin"
	.align 2, 0
	.global gUnk_08320138
gUnk_08320138:
	.incbin "build/assets/graphics/rl_08320138.bin"
	.align 2, 0
	.global gUnk_0832017C
gUnk_0832017C:
	.incbin "build/assets/graphics/rl_0832017C.bin"
	.global gUnk_083201BC
gUnk_083201BC:
	.incbin "build/assets/graphics/rl_083201BC.bin"
	.align 2, 0
	.global gUnk_083201FC
gUnk_083201FC:
	.incbin "build/assets/graphics/rl_083201FC.bin"
	.align 2, 0
	.global gUnk_08320250
gUnk_08320250:
	.incbin "build/assets/graphics/rl_08320250.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_08320294.pal.bin"
	.global gUnk_083202B4
gUnk_083202B4:
	.incbin "build/assets/graphics/rl_083202B4.bin"
	.align 2, 0
	.global gUnk_083203E8
gUnk_083203E8:
	.incbin "build/assets/graphics/rl_083203E8.bin"
	.global gUnk_08320510
gUnk_08320510:
	.incbin "build/assets/graphics/rl_08320510.bin"
	.align 2, 0
	.global gUnk_08320648
gUnk_08320648:
	.incbin "build/assets/graphics/rl_08320648.bin"
	.align 2, 0
	.global gUnk_0832077C
gUnk_0832077C:
	.incbin "build/assets/graphics/rl_0832077C.bin"
	.align 2, 0
	.global gUnk_083208A0
gUnk_083208A0:
	.incbin "build/assets/graphics/rl_083208A0.bin"
	.align 2, 0
	.global gUnk_083209C0
gUnk_083209C0:
	.incbin "build/assets/graphics/rl_083209C0.bin"
	.align 2, 0
	.global gUnk_08320ACC
gUnk_08320ACC:
	.incbin "build/assets/graphics/rl_08320ACC.bin"
	.align 2, 0
	.global gUnk_08320BD8
gUnk_08320BD8:
	.incbin "build/assets/graphics/rl_08320BD8.bin"
	.align 2, 0
	.global gUnk_08320CEC
gUnk_08320CEC:
	.incbin "build/assets/graphics/rl_08320CEC.bin"
	.align 2, 0
	.global gUnk_08320E00
gUnk_08320E00:
	.incbin "build/assets/graphics/rl_08320E00.bin"
	.align 2, 0
	.global gUnk_08320F10
gUnk_08320F10:
	.incbin "build/assets/graphics/rl_08320F10.bin"
	.align 2, 0
	.global gUnk_0832101C
gUnk_0832101C:
	.incbin "build/assets/graphics/rl_0832101C.bin"
	.align 2, 0
	.global gUnk_08321128
gUnk_08321128:
	.incbin "build/assets/graphics/rl_08321128.bin"
	.global gUnk_0832122C
gUnk_0832122C:
	.incbin "build/assets/graphics/rl_0832122C.bin"
	.align 2, 0
	.global gUnk_08321338
gUnk_08321338:
	.incbin "build/assets/graphics/rl_08321338.bin"
	.align 2, 0
	.global gUnk_08321440
gUnk_08321440:
	.incbin "build/assets/graphics/rl_08321440.bin"
	.align 2, 0
	.global gUnk_08321544
gUnk_08321544:
	.incbin "build/assets/graphics/rl_08321544.bin"
	.global gUnk_08321648
gUnk_08321648:
	.incbin "build/assets/graphics/rl_08321648.bin"
	.align 2, 0
	.global gUnk_08321744
gUnk_08321744:
	.incbin "build/assets/graphics/rl_08321744.bin"
	.align 2, 0
	.global gUnk_0832184C
gUnk_0832184C:
	.incbin "build/assets/graphics/rl_0832184C.bin"
	.global gUnk_08321958
gUnk_08321958:
	.incbin "build/assets/graphics/rl_08321958.bin"
	.align 2, 0
	.global gUnk_08321A68
gUnk_08321A68:
	.incbin "build/assets/graphics/rl_08321A68.bin"
	.align 2, 0
	.global gUnk_08321B78
gUnk_08321B78:
	.incbin "build/assets/graphics/rl_08321B78.bin"
	.global gUnk_08321C90
gUnk_08321C90:
	.incbin "build/assets/graphics/rl_08321C90.bin"
	.global gUnk_08321DA4
gUnk_08321DA4:
	.incbin "build/assets/graphics/rl_08321DA4.bin"
	.global gUnk_08321EB8
gUnk_08321EB8:
	.incbin "build/assets/graphics/rl_08321EB8.bin"
	.align 2, 0
	.global gUnk_08321FC8
gUnk_08321FC8:
	.incbin "build/assets/graphics/rl_08321FC8.bin"
	.global gUnk_083220CC
gUnk_083220CC:
	.incbin "build/assets/graphics/rl_083220CC.bin"
	.align 2, 0
	.global gUnk_083221CC
gUnk_083221CC:
	.incbin "build/assets/graphics/rl_083221CC.bin"
	.align 2, 0
	.global gUnk_083222CC
gUnk_083222CC:
	.incbin "build/assets/graphics/rl_083222CC.bin"
	.align 2, 0
	.global gUnk_083223C4
gUnk_083223C4:
	.incbin "build/assets/graphics/rl_083223C4.bin"
	.align 2, 0
	.global gUnk_083224BC
gUnk_083224BC:
	.incbin "build/assets/graphics/rl_083224BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_083225AC.pal.bin"
	.global gUnk_083225CC
gUnk_083225CC:
	.incbin "build/assets/graphics/rl_083225CC.bin"
	.align 2, 0
	.global gUnk_08322628
gUnk_08322628:
	.incbin "build/assets/graphics/rl_08322628.bin"
	.align 2, 0
	.global gUnk_08322674
gUnk_08322674:
	.incbin "build/assets/graphics/rl_08322674.bin"
	.align 2, 0
	.global gUnk_083226C4
gUnk_083226C4:
	.incbin "build/assets/graphics/rl_083226C4.bin"
	.align 2, 0
	.global gUnk_08322718
gUnk_08322718:
	.incbin "build/assets/graphics/rl_08322718.bin"
	.align 2, 0
	.global gUnk_0832277C
gUnk_0832277C:
	.incbin "build/assets/graphics/rl_0832277C.bin"
	.align 2, 0
	.global gUnk_08322804
gUnk_08322804:
	.incbin "build/assets/graphics/rl_08322804.bin"
	.align 2, 0
	.global gUnk_08322898
gUnk_08322898:
	.incbin "build/assets/graphics/rl_08322898.bin"
	.align 2, 0
	.global gUnk_0832292C
gUnk_0832292C:
	.incbin "build/assets/graphics/rl_0832292C.bin"
	.align 2, 0
	.global gUnk_083229C0
gUnk_083229C0:
	.incbin "build/assets/graphics/rl_083229C0.bin"
	.align 2, 0
	.global gUnk_08322A54
gUnk_08322A54:
	.incbin "build/assets/graphics/rl_08322A54.bin"
	.align 2, 0
	.global gUnk_08322AE8
gUnk_08322AE8:
	.incbin "build/assets/graphics/rl_08322AE8.bin"
	.align 2, 0
	.global gUnk_08322B78
gUnk_08322B78:
	.incbin "build/assets/graphics/rl_08322B78.bin"
	.global gUnk_08322C04
gUnk_08322C04:
	.incbin "build/assets/graphics/rl_08322C04.bin"
	.align 2, 0
	.global gUnk_08322C8C
gUnk_08322C8C:
	.incbin "build/assets/graphics/rl_08322C8C.bin"
	.align 2, 0
	.global gUnk_08322D10
gUnk_08322D10:
	.incbin "build/assets/graphics/rl_08322D10.bin"
	.align 2, 0
	.global gUnk_08322D94
gUnk_08322D94:
	.incbin "build/assets/graphics/rl_08322D94.bin"
	.align 2, 0
	.global gUnk_08322E14
gUnk_08322E14:
	.incbin "build/assets/graphics/rl_08322E14.bin"
	.align 2, 0
	.global gUnk_08322E94
gUnk_08322E94:
	.incbin "build/assets/graphics/rl_08322E94.bin"
	.align 2, 0
	.global gUnk_08322F14
gUnk_08322F14:
	.incbin "build/assets/graphics/rl_08322F14.bin"
	.align 2, 0
	.global gUnk_08322F8C
gUnk_08322F8C:
	.incbin "build/assets/graphics/rl_08322F8C.bin"
	.align 2, 0
	.global gUnk_08323004
gUnk_08323004:
	.incbin "build/assets/graphics/rl_08323004.bin"
	.align 2, 0
	.global gUnk_08323078
gUnk_08323078:
	.incbin "build/assets/graphics/rl_08323078.bin"
	.align 2, 0
	.global gUnk_083230E4
gUnk_083230E4:
	.incbin "build/assets/graphics/rl_083230E4.bin"
	.align 2, 0
	.global gUnk_08323150
gUnk_08323150:
	.incbin "build/assets/graphics/rl_08323150.bin"
	.global gUnk_083231B8
gUnk_083231B8:
	.incbin "build/assets/graphics/rl_083231B8.bin"
	.align 2, 0
	.global gUnk_08323218
gUnk_08323218:
	.incbin "build/assets/graphics/rl_08323218.bin"
	.align 2, 0
	.global gUnk_0832325C
gUnk_0832325C:
	.incbin "build/assets/graphics/rl_0832325C.bin"
	.align 2, 0
	.global gUnk_083232A0
gUnk_083232A0:
	.incbin "build/assets/graphics/rl_083232A0.bin"
	.align 2, 0
	.global gUnk_083232E4
gUnk_083232E4:
	.incbin "build/assets/graphics/rl_083232E4.bin"
	.global gUnk_08323324
gUnk_08323324:
	.incbin "build/assets/graphics/rl_08323324.bin"
	.align 2, 0
	.global gUnk_08323364
gUnk_08323364:
	.incbin "build/assets/graphics/rl_08323364.bin"
	.align 2, 0
	.global gUnk_083233B8
gUnk_083233B8:
	.incbin "build/assets/graphics/rl_083233B8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_083233FC.pal.bin"
	.global gUnk_0832341C
gUnk_0832341C:
	.incbin "build/assets/graphics/rl_0832341C.bin"
	.global gUnk_0832354C
gUnk_0832354C:
	.incbin "build/assets/graphics/rl_0832354C.bin"
	.align 2, 0
	.global gUnk_08323674
gUnk_08323674:
	.incbin "build/assets/graphics/rl_08323674.bin"
	.align 2, 0
	.global gUnk_083237A8
gUnk_083237A8:
	.incbin "build/assets/graphics/rl_083237A8.bin"
	.align 2, 0
	.global gUnk_083238D8
gUnk_083238D8:
	.incbin "build/assets/graphics/rl_083238D8.bin"
	.align 2, 0
	.global gUnk_083239FC
gUnk_083239FC:
	.incbin "build/assets/graphics/rl_083239FC.bin"
	.align 2, 0
	.global gUnk_08323B1C
gUnk_08323B1C:
	.incbin "build/assets/graphics/rl_08323B1C.bin"
	.global gUnk_08323C24
gUnk_08323C24:
	.incbin "build/assets/graphics/rl_08323C24.bin"
	.align 2, 0
	.global gUnk_08323D30
gUnk_08323D30:
	.incbin "build/assets/graphics/rl_08323D30.bin"
	.align 2, 0
	.global gUnk_08323E3C
gUnk_08323E3C:
	.incbin "build/assets/graphics/rl_08323E3C.bin"
	.align 2, 0
	.global gUnk_08323F50
gUnk_08323F50:
	.incbin "build/assets/graphics/rl_08323F50.bin"
	.global gUnk_0832405C
gUnk_0832405C:
	.incbin "build/assets/graphics/rl_0832405C.bin"
	.align 2, 0
	.global gUnk_08324168
gUnk_08324168:
	.incbin "build/assets/graphics/rl_08324168.bin"
	.align 2, 0
	.global gUnk_08324274
gUnk_08324274:
	.incbin "build/assets/graphics/rl_08324274.bin"
	.align 2, 0
	.global gUnk_0832437C
gUnk_0832437C:
	.incbin "build/assets/graphics/rl_0832437C.bin"
	.global gUnk_08324484
gUnk_08324484:
	.incbin "build/assets/graphics/rl_08324484.bin"
	.align 2, 0
	.global gUnk_08324594
gUnk_08324594:
	.incbin "build/assets/graphics/rl_08324594.bin"
	.align 2, 0
	.global gUnk_0832469C
gUnk_0832469C:
	.incbin "build/assets/graphics/rl_0832469C.bin"
	.global gUnk_083247A8
gUnk_083247A8:
	.incbin "build/assets/graphics/rl_083247A8.bin"
	.global gUnk_083248AC
gUnk_083248AC:
	.incbin "build/assets/graphics/rl_083248AC.bin"
	.align 2, 0
	.global gUnk_083249BC
gUnk_083249BC:
	.incbin "build/assets/graphics/rl_083249BC.bin"
	.align 2, 0
	.global gUnk_08324AD4
gUnk_08324AD4:
	.incbin "build/assets/graphics/rl_08324AD4.bin"
	.global gUnk_08324BE4
gUnk_08324BE4:
	.incbin "build/assets/graphics/rl_08324BE4.bin"
	.global gUnk_08324CF0
gUnk_08324CF0:
	.incbin "build/assets/graphics/rl_08324CF0.bin"
	.global gUnk_08324E08
gUnk_08324E08:
	.incbin "build/assets/graphics/rl_08324E08.bin"
	.global gUnk_08324F1C
gUnk_08324F1C:
	.incbin "build/assets/graphics/rl_08324F1C.bin"
	.global gUnk_08325030
gUnk_08325030:
	.incbin "build/assets/graphics/rl_08325030.bin"
	.align 2, 0
	.global gUnk_08325140
gUnk_08325140:
	.incbin "build/assets/graphics/rl_08325140.bin"
	.global gUnk_08325244
gUnk_08325244:
	.incbin "build/assets/graphics/rl_08325244.bin"
	.align 2, 0
	.global gUnk_08325344
gUnk_08325344:
	.incbin "build/assets/graphics/rl_08325344.bin"
	.align 2, 0
	.global gUnk_08325444
gUnk_08325444:
	.incbin "build/assets/graphics/rl_08325444.bin"
	.global gUnk_08325538
gUnk_08325538:
	.incbin "build/assets/graphics/rl_08325538.bin"
	.align 2, 0
	.global gUnk_08325630
gUnk_08325630:
	.incbin "build/assets/graphics/rl_08325630.bin"
	.incbin "build/assets/graphics/palettes/pal_0832571C.pal.bin"
	.global gUnk_0832573C
gUnk_0832573C:
	.incbin "build/assets/graphics/rl_0832573C.bin"
	.align 2, 0
	.global gUnk_08325798
gUnk_08325798:
	.incbin "build/assets/graphics/rl_08325798.bin"
	.align 2, 0
	.global gUnk_083257E4
gUnk_083257E4:
	.incbin "build/assets/graphics/rl_083257E4.bin"
	.align 2, 0
	.global gUnk_08325834
gUnk_08325834:
	.incbin "build/assets/graphics/rl_08325834.bin"
	.align 2, 0
	.global gUnk_08325888
gUnk_08325888:
	.incbin "build/assets/graphics/rl_08325888.bin"
	.align 2, 0
	.global gUnk_083258EC
gUnk_083258EC:
	.incbin "build/assets/graphics/rl_083258EC.bin"
	.global gUnk_08325970
gUnk_08325970:
	.incbin "build/assets/graphics/rl_08325970.bin"
	.align 2, 0
	.global gUnk_08325A04
gUnk_08325A04:
	.incbin "build/assets/graphics/rl_08325A04.bin"
	.global gUnk_08325A94
gUnk_08325A94:
	.incbin "build/assets/graphics/rl_08325A94.bin"
	.align 2, 0
	.global gUnk_08325B28
gUnk_08325B28:
	.incbin "build/assets/graphics/rl_08325B28.bin"
	.align 2, 0
	.global gUnk_08325BBC
gUnk_08325BBC:
	.incbin "build/assets/graphics/rl_08325BBC.bin"
	.align 2, 0
	.global gUnk_08325C50
gUnk_08325C50:
	.incbin "build/assets/graphics/rl_08325C50.bin"
	.align 2, 0
	.global gUnk_08325CE0
gUnk_08325CE0:
	.incbin "build/assets/graphics/rl_08325CE0.bin"
	.align 2, 0
	.global gUnk_08325D6C
gUnk_08325D6C:
	.incbin "build/assets/graphics/rl_08325D6C.bin"
	.global gUnk_08325DF0
gUnk_08325DF0:
	.incbin "build/assets/graphics/rl_08325DF0.bin"
	.global gUnk_08325E6C
gUnk_08325E6C:
	.incbin "build/assets/graphics/rl_08325E6C.bin"
	.global gUnk_08325EEC
gUnk_08325EEC:
	.incbin "build/assets/graphics/rl_08325EEC.bin"
	.global gUnk_08325F64
gUnk_08325F64:
	.incbin "build/assets/graphics/rl_08325F64.bin"
	.global gUnk_08325FDC
gUnk_08325FDC:
	.incbin "build/assets/graphics/rl_08325FDC.bin"
	.align 2, 0
	.global gUnk_0832605C
gUnk_0832605C:
	.incbin "build/assets/graphics/rl_0832605C.bin"
	.global gUnk_083260D4
gUnk_083260D4:
	.incbin "build/assets/graphics/rl_083260D4.bin"
	.align 2, 0
	.global gUnk_0832614C
gUnk_0832614C:
	.incbin "build/assets/graphics/rl_0832614C.bin"
	.align 2, 0
	.global gUnk_083261C0
gUnk_083261C0:
	.incbin "build/assets/graphics/rl_083261C0.bin"
	.align 2, 0
	.global gUnk_0832622C
gUnk_0832622C:
	.incbin "build/assets/graphics/rl_0832622C.bin"
	.align 2, 0
	.global gUnk_08326298
gUnk_08326298:
	.incbin "build/assets/graphics/rl_08326298.bin"
	.global gUnk_08326300
gUnk_08326300:
	.incbin "build/assets/graphics/rl_08326300.bin"
	.align 2, 0
	.global gUnk_08326360
gUnk_08326360:
	.incbin "build/assets/graphics/rl_08326360.bin"
	.align 2, 0
	.global gUnk_083263A4
gUnk_083263A4:
	.incbin "build/assets/graphics/rl_083263A4.bin"
	.align 2, 0
	.global gUnk_083263E8
gUnk_083263E8:
	.incbin "build/assets/graphics/rl_083263E8.bin"
	.align 2, 0
	.global gUnk_0832642C
gUnk_0832642C:
	.incbin "build/assets/graphics/rl_0832642C.bin"
	.global gUnk_0832646C
gUnk_0832646C:
	.incbin "build/assets/graphics/rl_0832646C.bin"
	.align 2, 0
	.global gUnk_083264AC
gUnk_083264AC:
	.incbin "build/assets/graphics/rl_083264AC.bin"
	.align 2, 0
	.global gUnk_08326500
gUnk_08326500:
	.incbin "build/assets/graphics/rl_08326500.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_08326544.pal.bin"
	.global gUnk_08326564
gUnk_08326564:
	.incbin "build/assets/graphics/rl_08326564.bin"
	.align 2, 0
	.global gUnk_08326694
gUnk_08326694:
	.incbin "build/assets/graphics/rl_08326694.bin"
	.align 2, 0
	.global gUnk_083267B0
gUnk_083267B0:
	.incbin "build/assets/graphics/rl_083267B0.bin"
	.align 2, 0
	.global gUnk_083268E4
gUnk_083268E4:
	.incbin "build/assets/graphics/rl_083268E4.bin"
	.global gUnk_08326A18
gUnk_08326A18:
	.incbin "build/assets/graphics/rl_08326A18.bin"
	.align 2, 0
	.global gUnk_08326B44
gUnk_08326B44:
	.incbin "build/assets/graphics/rl_08326B44.bin"
	.align 2, 0
	.global gUnk_08326C60
gUnk_08326C60:
	.incbin "build/assets/graphics/rl_08326C60.bin"
	.align 2, 0
	.global gUnk_08326D70
gUnk_08326D70:
	.incbin "build/assets/graphics/rl_08326D70.bin"
	.global gUnk_08326E78
gUnk_08326E78:
	.incbin "build/assets/graphics/rl_08326E78.bin"
	.global gUnk_08326F84
gUnk_08326F84:
	.incbin "build/assets/graphics/rl_08326F84.bin"
	.align 2, 0
	.global gUnk_0832709C
gUnk_0832709C:
	.incbin "build/assets/graphics/rl_0832709C.bin"
	.align 2, 0
	.global gUnk_083271A8
gUnk_083271A8:
	.incbin "build/assets/graphics/rl_083271A8.bin"
	.align 2, 0
	.global gUnk_083272B8
gUnk_083272B8:
	.incbin "build/assets/graphics/rl_083272B8.bin"
	.global gUnk_083273C4
gUnk_083273C4:
	.incbin "build/assets/graphics/rl_083273C4.bin"
	.align 2, 0
	.global gUnk_083274D0
gUnk_083274D0:
	.incbin "build/assets/graphics/rl_083274D0.bin"
	.align 2, 0
	.global gUnk_083275E0
gUnk_083275E0:
	.incbin "build/assets/graphics/rl_083275E0.bin"
	.global gUnk_083276EC
gUnk_083276EC:
	.incbin "build/assets/graphics/rl_083276EC.bin"
	.align 2, 0
	.global gUnk_083277F8
gUnk_083277F8:
	.incbin "build/assets/graphics/rl_083277F8.bin"
	.align 2, 0
	.global gUnk_08327908
gUnk_08327908:
	.incbin "build/assets/graphics/rl_08327908.bin"
	.align 2, 0
	.global gUnk_08327A10
gUnk_08327A10:
	.incbin "build/assets/graphics/rl_08327A10.bin"
	.global gUnk_08327B20
gUnk_08327B20:
	.incbin "build/assets/graphics/rl_08327B20.bin"
	.align 2, 0
	.global gUnk_08327C2C
gUnk_08327C2C:
	.incbin "build/assets/graphics/rl_08327C2C.bin"
	.global gUnk_08327D3C
gUnk_08327D3C:
	.incbin "build/assets/graphics/rl_08327D3C.bin"
	.align 2, 0
	.global gUnk_08327E50
gUnk_08327E50:
	.incbin "build/assets/graphics/rl_08327E50.bin"
	.align 2, 0
	.global gUnk_08327F64
gUnk_08327F64:
	.incbin "build/assets/graphics/rl_08327F64.bin"
	.align 2, 0
	.global gUnk_0832807C
gUnk_0832807C:
	.incbin "build/assets/graphics/rl_0832807C.bin"
	.align 2, 0
	.global gUnk_08328190
gUnk_08328190:
	.incbin "build/assets/graphics/rl_08328190.bin"
	.align 2, 0
	.global gUnk_083282A0
gUnk_083282A0:
	.incbin "build/assets/graphics/rl_083282A0.bin"
	.align 2, 0
	.global gUnk_083283A4
gUnk_083283A4:
	.incbin "build/assets/graphics/rl_083283A4.bin"
	.align 2, 0
	.global gUnk_083284A0
gUnk_083284A0:
	.incbin "build/assets/graphics/rl_083284A0.bin"
	.align 2, 0
	.global gUnk_0832859C
gUnk_0832859C:
	.incbin "build/assets/graphics/rl_0832859C.bin"
	.global gUnk_08328698
gUnk_08328698:
	.incbin "build/assets/graphics/rl_08328698.bin"
	.align 2, 0
	.global gUnk_08328790
gUnk_08328790:
	.incbin "build/assets/graphics/rl_08328790.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_08328880.pal.bin"
	.global gUnk_083288A0
gUnk_083288A0:
	.incbin "build/assets/graphics/rl_083288A0.bin"
	.align 2, 0
	.global gUnk_08328900
gUnk_08328900:
	.incbin "build/assets/graphics/rl_08328900.bin"
	.align 2, 0
	.global gUnk_08328950
gUnk_08328950:
	.incbin "build/assets/graphics/rl_08328950.bin"
	.align 2, 0
	.global gUnk_083289A4
gUnk_083289A4:
	.incbin "build/assets/graphics/rl_083289A4.bin"
	.align 2, 0
	.global gUnk_083289F8
gUnk_083289F8:
	.incbin "build/assets/graphics/rl_083289F8.bin"
	.align 2, 0
	.global gUnk_08328A70
gUnk_08328A70:
	.incbin "build/assets/graphics/rl_08328A70.bin"
	.align 2, 0
	.global gUnk_08328AF8
gUnk_08328AF8:
	.incbin "build/assets/graphics/rl_08328AF8.bin"
	.align 2, 0
	.global gUnk_08328B88
gUnk_08328B88:
	.incbin "build/assets/graphics/rl_08328B88.bin"
	.align 2, 0
	.global gUnk_08328C1C
gUnk_08328C1C:
	.incbin "build/assets/graphics/rl_08328C1C.bin"
	.align 2, 0
	.global gUnk_08328CB4
gUnk_08328CB4:
	.incbin "build/assets/graphics/rl_08328CB4.bin"
	.align 2, 0
	.global gUnk_08328D4C
gUnk_08328D4C:
	.incbin "build/assets/graphics/rl_08328D4C.bin"
	.align 2, 0
	.global gUnk_08328DE0
gUnk_08328DE0:
	.incbin "build/assets/graphics/rl_08328DE0.bin"
	.global gUnk_08328E70
gUnk_08328E70:
	.incbin "build/assets/graphics/rl_08328E70.bin"
	.global gUnk_08328F00
gUnk_08328F00:
	.incbin "build/assets/graphics/rl_08328F00.bin"
	.global gUnk_08328F88
gUnk_08328F88:
	.incbin "build/assets/graphics/rl_08328F88.bin"
	.global gUnk_08329010
gUnk_08329010:
	.incbin "build/assets/graphics/rl_08329010.bin"
	.global gUnk_08329094
gUnk_08329094:
	.incbin "build/assets/graphics/rl_08329094.bin"
	.align 2, 0
	.global gUnk_08329118
gUnk_08329118:
	.incbin "build/assets/graphics/rl_08329118.bin"
	.align 2, 0
	.global gUnk_08329198
gUnk_08329198:
	.incbin "build/assets/graphics/rl_08329198.bin"
	.global gUnk_08329214
gUnk_08329214:
	.incbin "build/assets/graphics/rl_08329214.bin"
	.global gUnk_08329290
gUnk_08329290:
	.incbin "build/assets/graphics/rl_08329290.bin"
	.global gUnk_08329308
gUnk_08329308:
	.incbin "build/assets/graphics/rl_08329308.bin"
	.align 2, 0
	.global gUnk_08329380
gUnk_08329380:
	.incbin "build/assets/graphics/rl_08329380.bin"
	.align 2, 0
	.global gUnk_083293F4
gUnk_083293F4:
	.incbin "build/assets/graphics/rl_083293F4.bin"
	.align 2, 0
	.global gUnk_08329464
gUnk_08329464:
	.incbin "build/assets/graphics/rl_08329464.bin"
	.align 2, 0
	.global gUnk_083294CC
gUnk_083294CC:
	.incbin "build/assets/graphics/rl_083294CC.bin"
	.align 2, 0
	.global gUnk_08329530
gUnk_08329530:
	.incbin "build/assets/graphics/rl_08329530.bin"
	.align 2, 0
	.global gUnk_08329584
gUnk_08329584:
	.incbin "build/assets/graphics/rl_08329584.bin"
	.align 2, 0
	.global gUnk_083295CC
gUnk_083295CC:
	.incbin "build/assets/graphics/rl_083295CC.bin"
	.global gUnk_08329610
gUnk_08329610:
	.incbin "build/assets/graphics/rl_08329610.bin"
	.global gUnk_08329654
gUnk_08329654:
	.incbin "build/assets/graphics/rl_08329654.bin"
	.align 2, 0
	.global gUnk_08329698
gUnk_08329698:
	.incbin "build/assets/graphics/rl_08329698.bin"
	.align 2, 0
	.global gUnk_083296F0
gUnk_083296F0:
	.incbin "build/assets/graphics/rl_083296F0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_0832973C.pal.bin"
	.global gUnk_0832975C
gUnk_0832975C:
	.incbin "build/assets/graphics/rl_0832975C.bin"
	.align 2, 0
	.global gUnk_08329890
gUnk_08329890:
	.incbin "build/assets/graphics/rl_08329890.bin"
	.align 2, 0
	.global gUnk_083299BC
gUnk_083299BC:
	.incbin "build/assets/graphics/rl_083299BC.bin"
	.align 2, 0
	.global gUnk_08329AF4
gUnk_08329AF4:
	.incbin "build/assets/graphics/rl_08329AF4.bin"
	.align 2, 0
	.global gUnk_08329C28
gUnk_08329C28:
	.incbin "build/assets/graphics/rl_08329C28.bin"
	.align 2, 0
	.global gUnk_08329D4C
gUnk_08329D4C:
	.incbin "build/assets/graphics/rl_08329D4C.bin"
	.align 2, 0
	.global gUnk_08329E6C
gUnk_08329E6C:
	.incbin "build/assets/graphics/rl_08329E6C.bin"
	.align 2, 0
	.global gUnk_08329F78
gUnk_08329F78:
	.incbin "build/assets/graphics/rl_08329F78.bin"
	.align 2, 0
	.global gUnk_0832A084
gUnk_0832A084:
	.incbin "build/assets/graphics/rl_0832A084.bin"
	.align 2, 0
	.global gUnk_0832A198
gUnk_0832A198:
	.incbin "build/assets/graphics/rl_0832A198.bin"
	.align 2, 0
	.global gUnk_0832A2AC
gUnk_0832A2AC:
	.incbin "build/assets/graphics/rl_0832A2AC.bin"
	.align 2, 0
	.global gUnk_0832A3BC
gUnk_0832A3BC:
	.incbin "build/assets/graphics/rl_0832A3BC.bin"
	.align 2, 0
	.global gUnk_0832A4C8
gUnk_0832A4C8:
	.incbin "build/assets/graphics/rl_0832A4C8.bin"
	.align 2, 0
	.global gUnk_0832A5D4
gUnk_0832A5D4:
	.incbin "build/assets/graphics/rl_0832A5D4.bin"
	.align 2, 0
	.global gUnk_0832A6E0
gUnk_0832A6E0:
	.incbin "build/assets/graphics/rl_0832A6E0.bin"
	.global gUnk_0832A7E8
gUnk_0832A7E8:
	.incbin "build/assets/graphics/rl_0832A7E8.bin"
	.align 2, 0
	.global gUnk_0832A8F0
gUnk_0832A8F0:
	.incbin "build/assets/graphics/rl_0832A8F0.bin"
	.global gUnk_0832A9F8
gUnk_0832A9F8:
	.incbin "build/assets/graphics/rl_0832A9F8.bin"
	.align 2, 0
	.global gUnk_0832AAFC
gUnk_0832AAFC:
	.incbin "build/assets/graphics/rl_0832AAFC.bin"
	.align 2, 0
	.global gUnk_0832AC04
gUnk_0832AC04:
	.incbin "build/assets/graphics/rl_0832AC04.bin"
	.align 2, 0
	.global gUnk_0832AD18
gUnk_0832AD18:
	.incbin "build/assets/graphics/rl_0832AD18.bin"
	.align 2, 0
	.global gUnk_0832AE30
gUnk_0832AE30:
	.incbin "build/assets/graphics/rl_0832AE30.bin"
	.align 2, 0
	.global gUnk_0832AF40
gUnk_0832AF40:
	.incbin "build/assets/graphics/rl_0832AF40.bin"
	.align 2, 0
	.global gUnk_0832B050
gUnk_0832B050:
	.incbin "build/assets/graphics/rl_0832B050.bin"
	.global gUnk_0832B168
gUnk_0832B168:
	.incbin "build/assets/graphics/rl_0832B168.bin"
	.global gUnk_0832B27C
gUnk_0832B27C:
	.incbin "build/assets/graphics/rl_0832B27C.bin"
	.global gUnk_0832B390
gUnk_0832B390:
	.incbin "build/assets/graphics/rl_0832B390.bin"
	.align 2, 0
	.global gUnk_0832B4A0
gUnk_0832B4A0:
	.incbin "build/assets/graphics/rl_0832B4A0.bin"
	.global gUnk_0832B5A4
gUnk_0832B5A4:
	.incbin "build/assets/graphics/rl_0832B5A4.bin"
	.global gUnk_0832B6A4
gUnk_0832B6A4:
	.incbin "build/assets/graphics/rl_0832B6A4.bin"
	.align 2, 0
	.global gUnk_0832B7A4
gUnk_0832B7A4:
	.incbin "build/assets/graphics/rl_0832B7A4.bin"
	.global gUnk_0832B89C
gUnk_0832B89C:
	.incbin "build/assets/graphics/rl_0832B89C.bin"
	.align 2, 0
	.global gUnk_0832B994
gUnk_0832B994:
	.incbin "build/assets/graphics/rl_0832B994.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_0832BA88.pal.bin"
	.global gUnk_0832BAA8
gUnk_0832BAA8:
	.incbin "build/assets/graphics/rl_0832BAA8.bin"
	.align 2, 0
	.global gUnk_0832BB04
gUnk_0832BB04:
	.incbin "build/assets/graphics/rl_0832BB04.bin"
	.align 2, 0
	.global gUnk_0832BB50
gUnk_0832BB50:
	.incbin "build/assets/graphics/rl_0832BB50.bin"
	.align 2, 0
	.global gUnk_0832BBA0
gUnk_0832BBA0:
	.incbin "build/assets/graphics/rl_0832BBA0.bin"
	.align 2, 0
	.global gUnk_0832BBF4
gUnk_0832BBF4:
	.incbin "build/assets/graphics/rl_0832BBF4.bin"
	.align 2, 0
	.global gUnk_0832BC58
gUnk_0832BC58:
	.incbin "build/assets/graphics/rl_0832BC58.bin"
	.align 2, 0
	.global gUnk_0832BCE0
gUnk_0832BCE0:
	.incbin "build/assets/graphics/rl_0832BCE0.bin"
	.align 2, 0
	.global gUnk_0832BD74
gUnk_0832BD74:
	.incbin "build/assets/graphics/rl_0832BD74.bin"
	.align 2, 0
	.global gUnk_0832BE08
gUnk_0832BE08:
	.incbin "build/assets/graphics/rl_0832BE08.bin"
	.align 2, 0
	.global gUnk_0832BE9C
gUnk_0832BE9C:
	.incbin "build/assets/graphics/rl_0832BE9C.bin"
	.align 2, 0
	.global gUnk_0832BF30
gUnk_0832BF30:
	.incbin "build/assets/graphics/rl_0832BF30.bin"
	.align 2, 0
	.global gUnk_0832BFC4
gUnk_0832BFC4:
	.incbin "build/assets/graphics/rl_0832BFC4.bin"
	.align 2, 0
	.global gUnk_0832C054
gUnk_0832C054:
	.incbin "build/assets/graphics/rl_0832C054.bin"
	.global gUnk_0832C0E0
gUnk_0832C0E0:
	.incbin "build/assets/graphics/rl_0832C0E0.bin"
	.align 2, 0
	.global gUnk_0832C168
gUnk_0832C168:
	.incbin "build/assets/graphics/rl_0832C168.bin"
	.align 2, 0
	.global gUnk_0832C1EC
gUnk_0832C1EC:
	.incbin "build/assets/graphics/rl_0832C1EC.bin"
	.align 2, 0
	.global gUnk_0832C270
gUnk_0832C270:
	.incbin "build/assets/graphics/rl_0832C270.bin"
	.align 2, 0
	.global gUnk_0832C2F0
gUnk_0832C2F0:
	.incbin "build/assets/graphics/rl_0832C2F0.bin"
	.global gUnk_0832C36C
gUnk_0832C36C:
	.incbin "build/assets/graphics/rl_0832C36C.bin"
	.align 2, 0
	.global gUnk_0832C3EC
gUnk_0832C3EC:
	.incbin "build/assets/graphics/rl_0832C3EC.bin"
	.global gUnk_0832C464
gUnk_0832C464:
	.incbin "build/assets/graphics/rl_0832C464.bin"
	.align 2, 0
	.global gUnk_0832C4DC
gUnk_0832C4DC:
	.incbin "build/assets/graphics/rl_0832C4DC.bin"
	.align 2, 0
	.global gUnk_0832C550
gUnk_0832C550:
	.incbin "build/assets/graphics/rl_0832C550.bin"
	.align 2, 0
	.global gUnk_0832C5BC
gUnk_0832C5BC:
	.incbin "build/assets/graphics/rl_0832C5BC.bin"
	.align 2, 0
	.global gUnk_0832C628
gUnk_0832C628:
	.incbin "build/assets/graphics/rl_0832C628.bin"
	.global gUnk_0832C690
gUnk_0832C690:
	.incbin "build/assets/graphics/rl_0832C690.bin"
	.align 2, 0
	.global gUnk_0832C6F0
gUnk_0832C6F0:
	.incbin "build/assets/graphics/rl_0832C6F0.bin"
	.align 2, 0
	.global gUnk_0832C734
gUnk_0832C734:
	.incbin "build/assets/graphics/rl_0832C734.bin"
	.align 2, 0
	.global gUnk_0832C778
gUnk_0832C778:
	.incbin "build/assets/graphics/rl_0832C778.bin"
	.align 2, 0
	.global gUnk_0832C7BC
gUnk_0832C7BC:
	.incbin "build/assets/graphics/rl_0832C7BC.bin"
	.global gUnk_0832C7FC
gUnk_0832C7FC:
	.incbin "build/assets/graphics/rl_0832C7FC.bin"
	.align 2, 0
	.global gUnk_0832C83C
gUnk_0832C83C:
	.incbin "build/assets/graphics/rl_0832C83C.bin"
	.align 2, 0
	.global gUnk_0832C890
gUnk_0832C890:
	.incbin "build/assets/graphics/rl_0832C890.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_0832C8D4.pal.bin"
	.global gUnk_0832C8F4
gUnk_0832C8F4:
	.incbin "build/assets/graphics/rl_0832C8F4.bin"
	.align 2, 0
	.global gUnk_0832CA28
gUnk_0832CA28:
	.incbin "build/assets/graphics/rl_0832CA28.bin"
	.align 2, 0
	.global gUnk_0832CB54
gUnk_0832CB54:
	.incbin "build/assets/graphics/rl_0832CB54.bin"
	.align 2, 0
	.global gUnk_0832CC88
gUnk_0832CC88:
	.incbin "build/assets/graphics/rl_0832CC88.bin"
	.align 2, 0
	.global gUnk_0832CDBC
gUnk_0832CDBC:
	.incbin "build/assets/graphics/rl_0832CDBC.bin"
	.align 2, 0
	.global gUnk_0832CEE0
gUnk_0832CEE0:
	.incbin "build/assets/graphics/rl_0832CEE0.bin"
	.align 2, 0
	.global gUnk_0832D000
gUnk_0832D000:
	.incbin "build/assets/graphics/rl_0832D000.bin"
	.align 2, 0
	.global gUnk_0832D10C
gUnk_0832D10C:
	.incbin "build/assets/graphics/rl_0832D10C.bin"
	.align 2, 0
	.global gUnk_0832D218
gUnk_0832D218:
	.incbin "build/assets/graphics/rl_0832D218.bin"
	.align 2, 0
	.global gUnk_0832D32C
gUnk_0832D32C:
	.incbin "build/assets/graphics/rl_0832D32C.bin"
	.align 2, 0
	.global gUnk_0832D43C
gUnk_0832D43C:
	.incbin "build/assets/graphics/rl_0832D43C.bin"
	.align 2, 0
	.global gUnk_0832D54C
gUnk_0832D54C:
	.incbin "build/assets/graphics/rl_0832D54C.bin"
	.global gUnk_0832D654
gUnk_0832D654:
	.incbin "build/assets/graphics/rl_0832D654.bin"
	.align 2, 0
	.global gUnk_0832D760
gUnk_0832D760:
	.incbin "build/assets/graphics/rl_0832D760.bin"
	.align 2, 0
	.global gUnk_0832D868
gUnk_0832D868:
	.incbin "build/assets/graphics/rl_0832D868.bin"
	.align 2, 0
	.global gUnk_0832D970
gUnk_0832D970:
	.incbin "build/assets/graphics/rl_0832D970.bin"
	.align 2, 0
	.global gUnk_0832DA78
gUnk_0832DA78:
	.incbin "build/assets/graphics/rl_0832DA78.bin"
	.align 2, 0
	.global gUnk_0832DB7C
gUnk_0832DB7C:
	.incbin "build/assets/graphics/rl_0832DB7C.bin"
	.align 2, 0
	.global gUnk_0832DC84
gUnk_0832DC84:
	.incbin "build/assets/graphics/rl_0832DC84.bin"
	.global gUnk_0832DD88
gUnk_0832DD88:
	.incbin "build/assets/graphics/rl_0832DD88.bin"
	.align 2, 0
	.global gUnk_0832DE98
gUnk_0832DE98:
	.incbin "build/assets/graphics/rl_0832DE98.bin"
	.align 2, 0
	.global gUnk_0832DFAC
gUnk_0832DFAC:
	.incbin "build/assets/graphics/rl_0832DFAC.bin"
	.global gUnk_0832E0BC
gUnk_0832E0BC:
	.incbin "build/assets/graphics/rl_0832E0BC.bin"
	.align 2, 0
	.global gUnk_0832E1CC
gUnk_0832E1CC:
	.incbin "build/assets/graphics/rl_0832E1CC.bin"
	.global gUnk_0832E2E4
gUnk_0832E2E4:
	.incbin "build/assets/graphics/rl_0832E2E4.bin"
	.global gUnk_0832E3F4
gUnk_0832E3F4:
	.incbin "build/assets/graphics/rl_0832E3F4.bin"
	.global gUnk_0832E508
gUnk_0832E508:
	.incbin "build/assets/graphics/rl_0832E508.bin"
	.align 2, 0
	.global gUnk_0832E618
gUnk_0832E618:
	.incbin "build/assets/graphics/rl_0832E618.bin"
	.align 2, 0
	.global gUnk_0832E71C
gUnk_0832E71C:
	.incbin "build/assets/graphics/rl_0832E71C.bin"
	.align 2, 0
	.global gUnk_0832E81C
gUnk_0832E81C:
	.incbin "build/assets/graphics/rl_0832E81C.bin"
	.global gUnk_0832E918
gUnk_0832E918:
	.incbin "build/assets/graphics/rl_0832E918.bin"
	.global gUnk_0832EA10
gUnk_0832EA10:
	.incbin "build/assets/graphics/rl_0832EA10.bin"
	.align 2, 0
	.global gUnk_0832EB08
gUnk_0832EB08:
	.incbin "build/assets/graphics/rl_0832EB08.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_0832EBF8.pal.bin"
	.global gUnk_0832EC18
gUnk_0832EC18:
	.incbin "build/assets/graphics/rl_0832EC18.bin"
	.align 2, 0
	.global gUnk_0832EC74
gUnk_0832EC74:
	.incbin "build/assets/graphics/rl_0832EC74.bin"
	.align 2, 0
	.global gUnk_0832ECC0
gUnk_0832ECC0:
	.incbin "build/assets/graphics/rl_0832ECC0.bin"
	.align 2, 0
	.global gUnk_0832ED10
gUnk_0832ED10:
	.incbin "build/assets/graphics/rl_0832ED10.bin"
	.align 2, 0
	.global gUnk_0832ED64
gUnk_0832ED64:
	.incbin "build/assets/graphics/rl_0832ED64.bin"
	.align 2, 0
	.global gUnk_0832EDC8
gUnk_0832EDC8:
	.incbin "build/assets/graphics/rl_0832EDC8.bin"
	.align 2, 0
	.global gUnk_0832EE50
gUnk_0832EE50:
	.incbin "build/assets/graphics/rl_0832EE50.bin"
	.align 2, 0
	.global gUnk_0832EEE4
gUnk_0832EEE4:
	.incbin "build/assets/graphics/rl_0832EEE4.bin"
	.align 2, 0
	.global gUnk_0832EF78
gUnk_0832EF78:
	.incbin "build/assets/graphics/rl_0832EF78.bin"
	.align 2, 0
	.global gUnk_0832F00C
gUnk_0832F00C:
	.incbin "build/assets/graphics/rl_0832F00C.bin"
	.align 2, 0
	.global gUnk_0832F0A0
gUnk_0832F0A0:
	.incbin "build/assets/graphics/rl_0832F0A0.bin"
	.align 2, 0
	.global gUnk_0832F134
gUnk_0832F134:
	.incbin "build/assets/graphics/rl_0832F134.bin"
	.align 2, 0
	.global gUnk_0832F1C4
gUnk_0832F1C4:
	.incbin "build/assets/graphics/rl_0832F1C4.bin"
	.global gUnk_0832F250
gUnk_0832F250:
	.incbin "build/assets/graphics/rl_0832F250.bin"
	.align 2, 0
	.global gUnk_0832F2D8
gUnk_0832F2D8:
	.incbin "build/assets/graphics/rl_0832F2D8.bin"
	.align 2, 0
	.global gUnk_0832F35C
gUnk_0832F35C:
	.incbin "build/assets/graphics/rl_0832F35C.bin"
	.align 2, 0
	.global gUnk_0832F3E0
gUnk_0832F3E0:
	.incbin "build/assets/graphics/rl_0832F3E0.bin"
	.align 2, 0
	.global gUnk_0832F460
gUnk_0832F460:
	.incbin "build/assets/graphics/rl_0832F460.bin"
	.align 2, 0
	.global gUnk_0832F4E0
gUnk_0832F4E0:
	.incbin "build/assets/graphics/rl_0832F4E0.bin"
	.align 2, 0
	.global gUnk_0832F560
gUnk_0832F560:
	.incbin "build/assets/graphics/rl_0832F560.bin"
	.global gUnk_0832F5D8
gUnk_0832F5D8:
	.incbin "build/assets/graphics/rl_0832F5D8.bin"
	.align 2, 0
	.global gUnk_0832F650
gUnk_0832F650:
	.incbin "build/assets/graphics/rl_0832F650.bin"
	.align 2, 0
	.global gUnk_0832F6C4
gUnk_0832F6C4:
	.incbin "build/assets/graphics/rl_0832F6C4.bin"
	.align 2, 0
	.global gUnk_0832F730
gUnk_0832F730:
	.incbin "build/assets/graphics/rl_0832F730.bin"
	.align 2, 0
	.global gUnk_0832F79C
gUnk_0832F79C:
	.incbin "build/assets/graphics/rl_0832F79C.bin"
	.global gUnk_0832F804
gUnk_0832F804:
	.incbin "build/assets/graphics/rl_0832F804.bin"
	.align 2, 0
	.global gUnk_0832F864
gUnk_0832F864:
	.incbin "build/assets/graphics/rl_0832F864.bin"
	.align 2, 0
	.global gUnk_0832F8A8
gUnk_0832F8A8:
	.incbin "build/assets/graphics/rl_0832F8A8.bin"
	.align 2, 0
	.global gUnk_0832F8EC
gUnk_0832F8EC:
	.incbin "build/assets/graphics/rl_0832F8EC.bin"
	.align 2, 0
	.global gUnk_0832F930
gUnk_0832F930:
	.incbin "build/assets/graphics/rl_0832F930.bin"
	.global gUnk_0832F970
gUnk_0832F970:
	.incbin "build/assets/graphics/rl_0832F970.bin"
	.align 2, 0
	.global gUnk_0832F9B0
gUnk_0832F9B0:
	.incbin "build/assets/graphics/rl_0832F9B0.bin"
	.align 2, 0
	.global gUnk_0832FA04
gUnk_0832FA04:
	.incbin "build/assets/graphics/rl_0832FA04.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_0832FA48.pal.bin"
	.global gUnk_0832FA68
gUnk_0832FA68:
	.incbin "build/assets/graphics/rl_0832FA68.bin"
	.align 2, 0
	.global gUnk_0832FB20
gUnk_0832FB20:
	.incbin "build/assets/graphics/rl_0832FB20.bin"
	.align 2, 0
	.global gUnk_0832FBD8
gUnk_0832FBD8:
	.incbin "build/assets/graphics/rl_0832FBD8.bin"
	.global gUnk_0832FC88
gUnk_0832FC88:
	.incbin "build/assets/graphics/rl_0832FC88.bin"
	.align 2, 0
	.global gUnk_0832FD24
gUnk_0832FD24:
	.incbin "build/assets/graphics/rl_0832FD24.bin"
	.align 2, 0
	.global gUnk_0832FDBC
gUnk_0832FDBC:
	.incbin "build/assets/graphics/rl_0832FDBC.bin"
	.align 2, 0
	.global gUnk_0832FE58
gUnk_0832FE58:
	.incbin "build/assets/graphics/rl_0832FE58.bin"
	.align 2, 0
	.global gUnk_0832FF34
gUnk_0832FF34:
	.incbin "build/assets/graphics/rl_0832FF34.bin"
	.align 2, 0
	.global gUnk_0832FFFC
gUnk_0832FFFC:
	.incbin "build/assets/graphics/rl_0832FFFC.bin"
	.align 2, 0
	.global gUnk_083300C8
gUnk_083300C8:
	.incbin "build/assets/graphics/rl_083300C8.bin"
	.global gUnk_0833018C
gUnk_0833018C:
	.incbin "build/assets/graphics/rl_0833018C.bin"
	.align 2, 0
	.global gUnk_08330240
gUnk_08330240:
	.incbin "build/assets/graphics/rl_08330240.bin"
	.align 2, 0
	.global gUnk_083302FC
gUnk_083302FC:
	.incbin "build/assets/graphics/rl_083302FC.bin"
	.global gUnk_083303BC
gUnk_083303BC:
	.incbin "build/assets/graphics/rl_083303BC.bin"
	.global gUnk_08330468
gUnk_08330468:
	.incbin "build/assets/graphics/rl_08330468.bin"
	.align 2, 0
	.global gUnk_08330504
gUnk_08330504:
	.incbin "build/assets/graphics/rl_08330504.bin"
	.align 2, 0
	.global gUnk_0833059C
gUnk_0833059C:
	.incbin "build/assets/graphics/rl_0833059C.bin"
	.align 2, 0
	.global gUnk_08330628
gUnk_08330628:
	.incbin "build/assets/graphics/rl_08330628.bin"
	.align 2, 0
	.global gUnk_083306FC
gUnk_083306FC:
	.incbin "build/assets/graphics/rl_083306FC.bin"
	.global gUnk_083307BC
gUnk_083307BC:
	.incbin "build/assets/graphics/rl_083307BC.bin"
	.align 2, 0
	.global gUnk_08330880
gUnk_08330880:
	.incbin "build/assets/graphics/rl_08330880.bin"
	.align 2, 0
	.global gUnk_0833095C
gUnk_0833095C:
	.incbin "build/assets/graphics/rl_0833095C.bin"
	.align 2, 0
	.global gUnk_08330A1C
gUnk_08330A1C:
	.incbin "build/assets/graphics/rl_08330A1C.bin"
