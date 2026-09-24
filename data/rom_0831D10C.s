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
	.incbin "build/assets/graphics/rl_0831D10C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831D240.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831D36C.bin"
	.incbin "build/assets/graphics/rl_0831D4A4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831D5D8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831D6FC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831D81C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831D928.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831DA34.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831DB48.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831DC5C.bin"
	.incbin "build/assets/graphics/rl_0831DD68.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831DE74.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831DF80.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831E08C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831E198.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831E2A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831E3B0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831E4C0.bin"
	.incbin "build/assets/graphics/rl_0831E5C8.bin"
	.incbin "build/assets/graphics/rl_0831E6D8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831E7F0.bin"
	.incbin "build/assets/graphics/rl_0831E900.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831EA10.bin"
	.incbin "build/assets/graphics/rl_0831EB28.bin"
	.incbin "build/assets/graphics/rl_0831EC3C.bin"
	.incbin "build/assets/graphics/rl_0831ED50.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831EE60.bin"
	.incbin "build/assets/graphics/rl_0831EF64.bin"
	.incbin "build/assets/graphics/rl_0831F064.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F164.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F260.bin"
	.incbin "build/assets/graphics/rl_0831F354.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_0831F448.bin"
	.incbin "build/assets/graphics/rl_0831F468.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F4C4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F510.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F560.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F5B4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F618.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F6A0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F734.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F7C8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F85C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F8F0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831F984.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FA14.bin"
	.incbin "build/assets/graphics/rl_0831FAA0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FB28.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FBAC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FC30.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FCB0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FD30.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FDB0.bin"
	.incbin "build/assets/graphics/rl_0831FE28.bin"
	.incbin "build/assets/graphics/rl_0831FE9C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FF10.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FF7C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831FFE8.bin"
	.incbin "build/assets/graphics/rl_08320050.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083200B0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083200F4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08320138.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832017C.bin"
	.incbin "build/assets/graphics/rl_083201BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083201FC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08320250.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_08320294.bin"
	.incbin "build/assets/graphics/rl_083202B4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083203E8.bin"
	.incbin "build/assets/graphics/rl_08320510.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08320648.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832077C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083208A0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083209C0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08320ACC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08320BD8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08320CEC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08320E00.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08320F10.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832101C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08321128.bin"
	.incbin "build/assets/graphics/rl_0832122C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08321338.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08321440.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08321544.bin"
	.incbin "build/assets/graphics/rl_08321648.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08321744.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832184C.bin"
	.incbin "build/assets/graphics/rl_08321958.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08321A68.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08321B78.bin"
	.incbin "build/assets/graphics/rl_08321C90.bin"
	.incbin "build/assets/graphics/rl_08321DA4.bin"
	.incbin "build/assets/graphics/rl_08321EB8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08321FC8.bin"
	.incbin "build/assets/graphics/rl_083220CC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083221CC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083222CC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083223C4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083224BC.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_083225AC.bin"
	.incbin "build/assets/graphics/rl_083225CC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322628.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322674.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083226C4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322718.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832277C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322804.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322898.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832292C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083229C0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322A54.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322AE8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322B78.bin"
	.incbin "build/assets/graphics/rl_08322C04.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322C8C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322D10.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322D94.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322E14.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322E94.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322F14.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08322F8C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323004.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323078.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083230E4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323150.bin"
	.incbin "build/assets/graphics/rl_083231B8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323218.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832325C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083232A0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083232E4.bin"
	.incbin "build/assets/graphics/rl_08323324.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323364.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083233B8.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_083233FC.bin"
	.incbin "build/assets/graphics/rl_0832341C.bin"
	.incbin "build/assets/graphics/rl_0832354C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323674.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083237A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083238D8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083239FC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323B1C.bin"
	.incbin "build/assets/graphics/rl_08323C24.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323D30.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323E3C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08323F50.bin"
	.incbin "build/assets/graphics/rl_0832405C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08324168.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08324274.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832437C.bin"
	.incbin "build/assets/graphics/rl_08324484.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08324594.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832469C.bin"
	.incbin "build/assets/graphics/rl_083247A8.bin"
	.incbin "build/assets/graphics/rl_083248AC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083249BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08324AD4.bin"
	.incbin "build/assets/graphics/rl_08324BE4.bin"
	.incbin "build/assets/graphics/rl_08324CF0.bin"
	.incbin "build/assets/graphics/rl_08324E08.bin"
	.incbin "build/assets/graphics/rl_08324F1C.bin"
	.incbin "build/assets/graphics/rl_08325030.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325140.bin"
	.incbin "build/assets/graphics/rl_08325244.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325344.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325444.bin"
	.incbin "build/assets/graphics/rl_08325538.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325630.bin"
	.incbin "build/assets/unknown/data_0832571C.bin"
	.incbin "build/assets/graphics/rl_0832573C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325798.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083257E4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325834.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325888.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083258EC.bin"
	.incbin "build/assets/graphics/rl_08325970.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325A04.bin"
	.incbin "build/assets/graphics/rl_08325A94.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325B28.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325BBC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325C50.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325CE0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08325D6C.bin"
	.incbin "build/assets/graphics/rl_08325DF0.bin"
	.incbin "build/assets/graphics/rl_08325E6C.bin"
	.incbin "build/assets/graphics/rl_08325EEC.bin"
	.incbin "build/assets/graphics/rl_08325F64.bin"
	.incbin "build/assets/graphics/rl_08325FDC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832605C.bin"
	.incbin "build/assets/graphics/rl_083260D4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832614C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083261C0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832622C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08326298.bin"
	.incbin "build/assets/graphics/rl_08326300.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08326360.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083263A4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083263E8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832642C.bin"
	.incbin "build/assets/graphics/rl_0832646C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083264AC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08326500.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_08326544.bin"
	.incbin "build/assets/graphics/rl_08326564.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08326694.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083267B0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083268E4.bin"
	.incbin "build/assets/graphics/rl_08326A18.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08326B44.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08326C60.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08326D70.bin"
	.incbin "build/assets/graphics/rl_08326E78.bin"
	.incbin "build/assets/graphics/rl_08326F84.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832709C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083271A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083272B8.bin"
	.incbin "build/assets/graphics/rl_083273C4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083274D0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083275E0.bin"
	.incbin "build/assets/graphics/rl_083276EC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083277F8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08327908.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08327A10.bin"
	.incbin "build/assets/graphics/rl_08327B20.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08327C2C.bin"
	.incbin "build/assets/graphics/rl_08327D3C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08327E50.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08327F64.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832807C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328190.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083282A0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083283A4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083284A0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832859C.bin"
	.incbin "build/assets/graphics/rl_08328698.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328790.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_08328880.bin"
	.incbin "build/assets/graphics/rl_083288A0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328900.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328950.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083289A4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083289F8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328A70.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328AF8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328B88.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328C1C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328CB4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328D4C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08328DE0.bin"
	.incbin "build/assets/graphics/rl_08328E70.bin"
	.incbin "build/assets/graphics/rl_08328F00.bin"
	.incbin "build/assets/graphics/rl_08328F88.bin"
	.incbin "build/assets/graphics/rl_08329010.bin"
	.incbin "build/assets/graphics/rl_08329094.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329118.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329198.bin"
	.incbin "build/assets/graphics/rl_08329214.bin"
	.incbin "build/assets/graphics/rl_08329290.bin"
	.incbin "build/assets/graphics/rl_08329308.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329380.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083293F4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329464.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083294CC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329530.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329584.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083295CC.bin"
	.incbin "build/assets/graphics/rl_08329610.bin"
	.incbin "build/assets/graphics/rl_08329654.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329698.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083296F0.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_0832973C.bin"
	.incbin "build/assets/graphics/rl_0832975C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329890.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083299BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329AF4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329C28.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329D4C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329E6C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08329F78.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832A084.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832A198.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832A2AC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832A3BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832A4C8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832A5D4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832A6E0.bin"
	.incbin "build/assets/graphics/rl_0832A7E8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832A8F0.bin"
	.incbin "build/assets/graphics/rl_0832A9F8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832AAFC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832AC04.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832AD18.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832AE30.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832AF40.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832B050.bin"
	.incbin "build/assets/graphics/rl_0832B168.bin"
	.incbin "build/assets/graphics/rl_0832B27C.bin"
	.incbin "build/assets/graphics/rl_0832B390.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832B4A0.bin"
	.incbin "build/assets/graphics/rl_0832B5A4.bin"
	.incbin "build/assets/graphics/rl_0832B6A4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832B7A4.bin"
	.incbin "build/assets/graphics/rl_0832B89C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832B994.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_0832BA88.bin"
	.incbin "build/assets/graphics/rl_0832BAA8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BB04.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BB50.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BBA0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BBF4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BC58.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BCE0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BD74.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BE08.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BE9C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BF30.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832BFC4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C054.bin"
	.incbin "build/assets/graphics/rl_0832C0E0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C168.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C1EC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C270.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C2F0.bin"
	.incbin "build/assets/graphics/rl_0832C36C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C3EC.bin"
	.incbin "build/assets/graphics/rl_0832C464.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C4DC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C550.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C5BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C628.bin"
	.incbin "build/assets/graphics/rl_0832C690.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C6F0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C734.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C778.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C7BC.bin"
	.incbin "build/assets/graphics/rl_0832C7FC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C83C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832C890.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_0832C8D4.bin"
	.incbin "build/assets/graphics/rl_0832C8F4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832CA28.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832CB54.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832CC88.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832CDBC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832CEE0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832D000.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832D10C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832D218.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832D32C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832D43C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832D54C.bin"
	.incbin "build/assets/graphics/rl_0832D654.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832D760.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832D868.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832D970.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832DA78.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832DB7C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832DC84.bin"
	.incbin "build/assets/graphics/rl_0832DD88.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832DE98.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832DFAC.bin"
	.incbin "build/assets/graphics/rl_0832E0BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832E1CC.bin"
	.incbin "build/assets/graphics/rl_0832E2E4.bin"
	.incbin "build/assets/graphics/rl_0832E3F4.bin"
	.incbin "build/assets/graphics/rl_0832E508.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832E618.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832E71C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832E81C.bin"
	.incbin "build/assets/graphics/rl_0832E918.bin"
	.incbin "build/assets/graphics/rl_0832EA10.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832EB08.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_0832EBF8.bin"
	.incbin "build/assets/graphics/rl_0832EC18.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832EC74.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832ECC0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832ED10.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832ED64.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832EDC8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832EE50.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832EEE4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832EF78.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F00C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F0A0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F134.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F1C4.bin"
	.incbin "build/assets/graphics/rl_0832F250.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F2D8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F35C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F3E0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F460.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F4E0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F560.bin"
	.incbin "build/assets/graphics/rl_0832F5D8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F650.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F6C4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F730.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F79C.bin"
	.incbin "build/assets/graphics/rl_0832F804.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F864.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F8A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F8EC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F930.bin"
	.incbin "build/assets/graphics/rl_0832F970.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832F9B0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832FA04.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_0832FA48.bin"
	.incbin "build/assets/graphics/rl_0832FA68.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832FB20.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832FBD8.bin"
	.incbin "build/assets/graphics/rl_0832FC88.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832FD24.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832FDBC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832FE58.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832FF34.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0832FFFC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083300C8.bin"
	.incbin "build/assets/graphics/rl_0833018C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08330240.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083302FC.bin"
	.incbin "build/assets/graphics/rl_083303BC.bin"
	.incbin "build/assets/graphics/rl_08330468.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08330504.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0833059C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08330628.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083306FC.bin"
	.incbin "build/assets/graphics/rl_083307BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08330880.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0833095C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08330A1C.bin"
