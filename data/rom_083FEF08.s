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
	.global gUnk_083FEF08
gUnk_083FEF08:
	.4byte gUnk_0831C898
	.global gUnk_083FEF0C
gUnk_083FEF0C:
	.4byte gUnk_0831C8D4
	.global gUnk_083FEF10
gUnk_083FEF10:
	.4byte gUnk_0831C918
	.global gUnk_083FEF14
gUnk_083FEF14:
	.4byte gUnk_0831C960
	.global gUnk_083FEF18
gUnk_083FEF18:
	.4byte gUnk_0831C9A8
	.global gUnk_083FEF1C
gUnk_083FEF1C:
	.4byte gUnk_0831C9F0
	.global gUnk_083FEF20
gUnk_083FEF20:
	.4byte gUnk_0831CA38
	.global gUnk_083FEF24
gUnk_083FEF24:
	.4byte gUnk_0831CA80
	.global gUnk_083FEF28
gUnk_083FEF28:
	.4byte gUnk_0831CAC8
	.global gUnk_083FEF2C
gUnk_083FEF2C:
	.4byte gUnk_0831CB04
	.global gUnk_083FEF30
gUnk_083FEF30:
	.4byte gUnk_0831CB4C
	.global gUnk_083FEF34
gUnk_083FEF34:
	.4byte gUnk_0831CB94
	.global gUnk_083FEF38
gUnk_083FEF38:
	.4byte gUnk_0831CBDC
	.global gUnk_083FEF3C
gUnk_083FEF3C:
	.4byte gUnk_0831CC24
	.global gUnk_083FEF40
gUnk_083FEF40:
	.4byte gUnk_0831CC6C
	.global gUnk_083FEF44
gUnk_083FEF44:
	.4byte gUnk_0831CCB4
	.global gUnk_083FEF48
gUnk_083FEF48:
	.4byte gUnk_0831CCFC
	.global gUnk_083FEF4C
gUnk_083FEF4C:
	.4byte gUnk_0831CD44
	.global gUnk_083FEF50
gUnk_083FEF50:
	.4byte gUnk_0831CD8C
	.global gUnk_083FEF54
gUnk_083FEF54:
	.4byte gUnk_0831CDD4
	.global gUnk_083FEF58
gUnk_083FEF58:
	.4byte gUnk_0831CE1C
	.global gUnk_083FEF5C
gUnk_083FEF5C:
	.4byte gUnk_0831CE64
	.global gUnk_083FEF60
gUnk_083FEF60:
	.4byte gUnk_0831CEAC
	.global gUnk_083FEF64
gUnk_083FEF64:
	.4byte gUnk_0831CEF4
	.global gUnk_083FEF68
gUnk_083FEF68:
	.4byte gUnk_0831CF3C
	.global gUnk_083FEF6C
gUnk_083FEF6C:
	.4byte gUnk_0831CF84
	.global gUnk_083FEF70
gUnk_083FEF70:
	.4byte gUnk_0831CFCC
	.global gUnk_083FEF74
gUnk_083FEF74:
	.4byte gUnk_0831D014
	.global gUnk_083FEF78
gUnk_083FEF78:
	.4byte gUnk_0831D05C
	.global gUnk_083FEF7C
gUnk_083FEF7C:
	.4byte gUnk_0831D0A4
	.global gUnk_083FEF80
gUnk_083FEF80:
	.4byte gUnk_0831D10C
	.4byte gUnk_0831D240
	.4byte gUnk_0831D36C
	.4byte gUnk_0831D4A4
	.4byte gUnk_0831D5D8
	.4byte gUnk_0831D6FC
	.4byte gUnk_0831D81C
	.4byte gUnk_0831D928
	.4byte gUnk_0831DA34
	.4byte gUnk_0831DB48
	.4byte gUnk_0831DC5C
	.4byte gUnk_0831DD68
	.4byte gUnk_0831DE74
	.4byte gUnk_0831DF80
	.4byte gUnk_0831E08C
	.4byte gUnk_0831E198
	.4byte gUnk_0831E2A8
	.4byte gUnk_0831E3B0
	.4byte gUnk_0831E4C0
	.4byte gUnk_0831E5C8
	.4byte gUnk_0831E6D8
	.4byte gUnk_0831E7F0
	.4byte gUnk_0831E900
	.4byte gUnk_0831EA10
	.4byte gUnk_0831EB28
	.4byte gUnk_0831EC3C
	.4byte gUnk_0831ED50
	.4byte gUnk_0831EE60
	.4byte gUnk_0831EF64
	.4byte gUnk_0831F064
	.4byte gUnk_0831F164
	.4byte gUnk_0831F260
	.4byte gUnk_0831F354
	.global gUnk_083FF004
gUnk_083FF004:
	.4byte gUnk_0831F468
	.4byte gUnk_0831F4C4
	.4byte gUnk_0831F510
	.4byte gUnk_0831F560
	.4byte gUnk_0831F5B4
	.4byte gUnk_0831F618
	.4byte gUnk_0831F6A0
	.4byte gUnk_0831F734
	.4byte gUnk_0831F7C8
	.4byte gUnk_0831F85C
	.4byte gUnk_0831F8F0
	.4byte gUnk_0831F984
	.4byte gUnk_0831FA14
	.4byte gUnk_0831FAA0
	.4byte gUnk_0831FB28
	.4byte gUnk_0831FBAC
	.4byte gUnk_0831FC30
	.4byte gUnk_0831FCB0
	.4byte gUnk_0831FD30
	.4byte gUnk_0831FDB0
	.4byte gUnk_0831FE28
	.4byte gUnk_0831FE9C
	.4byte gUnk_0831FF10
	.4byte gUnk_0831FF7C
	.4byte gUnk_0831FFE8
	.4byte gUnk_08320050
	.4byte gUnk_083200B0
	.4byte gUnk_083200F4
	.4byte gUnk_08320138
	.4byte gUnk_0832017C
	.4byte gUnk_083201BC
	.4byte gUnk_083201FC
	.4byte gUnk_08320250
	.global gUnk_083FF088
gUnk_083FF088:
	.4byte gUnk_083202B4
	.4byte gUnk_083203E8
	.4byte gUnk_08320510
	.4byte gUnk_08320648
	.4byte gUnk_0832077C
	.4byte gUnk_083208A0
	.4byte gUnk_083209C0
	.4byte gUnk_08320ACC
	.4byte gUnk_08320BD8
	.4byte gUnk_08320CEC
	.4byte gUnk_08320E00
	.4byte gUnk_08320F10
	.4byte gUnk_0832101C
	.4byte gUnk_08321128
	.4byte gUnk_0832122C
	.4byte gUnk_08321338
	.4byte gUnk_08321440
	.4byte gUnk_08321544
	.4byte gUnk_08321648
	.4byte gUnk_08321744
	.4byte gUnk_0832184C
	.4byte gUnk_08321958
	.4byte gUnk_08321A68
	.4byte gUnk_08321B78
	.4byte gUnk_08321C90
	.4byte gUnk_08321DA4
	.4byte gUnk_08321EB8
	.4byte gUnk_08321FC8
	.4byte gUnk_083220CC
	.4byte gUnk_083221CC
	.4byte gUnk_083222CC
	.4byte gUnk_083223C4
	.4byte gUnk_083224BC
	.global gUnk_083FF10C
gUnk_083FF10C:
	.4byte gUnk_083225CC
	.4byte gUnk_08322628
	.4byte gUnk_08322674
	.4byte gUnk_083226C4
	.4byte gUnk_08322718
	.4byte gUnk_0832277C
	.4byte gUnk_08322804
	.4byte gUnk_08322898
	.4byte gUnk_0832292C
	.4byte gUnk_083229C0
	.4byte gUnk_08322A54
	.4byte gUnk_08322AE8
	.4byte gUnk_08322B78
	.4byte gUnk_08322C04
	.4byte gUnk_08322C8C
	.4byte gUnk_08322D10
	.4byte gUnk_08322D94
	.4byte gUnk_08322E14
	.4byte gUnk_08322E94
	.4byte gUnk_08322F14
	.4byte gUnk_08322F8C
	.4byte gUnk_08323004
	.4byte gUnk_08323078
	.4byte gUnk_083230E4
	.4byte gUnk_08323150
	.4byte gUnk_083231B8
	.4byte gUnk_08323218
	.4byte gUnk_0832325C
	.4byte gUnk_083232A0
	.4byte gUnk_083232E4
	.4byte gUnk_08323324
	.4byte gUnk_08323364
	.4byte gUnk_083233B8
	.global gUnk_083FF190
gUnk_083FF190:
	.4byte gUnk_0832341C
	.4byte gUnk_0832354C
	.4byte gUnk_08323674
	.4byte gUnk_083237A8
	.4byte gUnk_083238D8
	.4byte gUnk_083239FC
	.4byte gUnk_08323B1C
	.4byte gUnk_08323C24
	.4byte gUnk_08323D30
	.4byte gUnk_08323E3C
	.4byte gUnk_08323F50
	.4byte gUnk_0832405C
	.4byte gUnk_08324168
	.4byte gUnk_08324274
	.4byte gUnk_0832437C
	.4byte gUnk_08324484
	.4byte gUnk_08324594
	.4byte gUnk_0832469C
	.4byte gUnk_083247A8
	.4byte gUnk_083248AC
	.4byte gUnk_083249BC
	.4byte gUnk_08324AD4
	.4byte gUnk_08324BE4
	.4byte gUnk_08324CF0
	.4byte gUnk_08324E08
	.4byte gUnk_08324F1C
	.4byte gUnk_08325030
	.4byte gUnk_08325140
	.4byte gUnk_08325244
	.4byte gUnk_08325344
	.4byte gUnk_08325444
	.4byte gUnk_08325538
	.4byte gUnk_08325630
	.global gUnk_083FF214
gUnk_083FF214:
	.4byte gUnk_0832573C
	.4byte gUnk_08325798
	.4byte gUnk_083257E4
	.4byte gUnk_08325834
	.4byte gUnk_08325888
	.4byte gUnk_083258EC
	.4byte gUnk_08325970
	.4byte gUnk_08325A04
	.4byte gUnk_08325A94
	.4byte gUnk_08325B28
	.4byte gUnk_08325BBC
	.4byte gUnk_08325C50
	.4byte gUnk_08325CE0
	.4byte gUnk_08325D6C
	.4byte gUnk_08325DF0
	.4byte gUnk_08325E6C
	.4byte gUnk_08325EEC
	.4byte gUnk_08325F64
	.4byte gUnk_08325FDC
	.4byte gUnk_0832605C
	.4byte gUnk_083260D4
	.4byte gUnk_0832614C
	.4byte gUnk_083261C0
	.4byte gUnk_0832622C
	.4byte gUnk_08326298
	.4byte gUnk_08326300
	.4byte gUnk_08326360
	.4byte gUnk_083263A4
	.4byte gUnk_083263E8
	.4byte gUnk_0832642C
	.4byte gUnk_0832646C
	.4byte gUnk_083264AC
	.4byte gUnk_08326500
	.global gUnk_083FF298
gUnk_083FF298:
	.4byte gUnk_08326564
	.4byte gUnk_08326694
	.4byte gUnk_083267B0
	.4byte gUnk_083268E4
	.4byte gUnk_08326A18
	.4byte gUnk_08326B44
	.4byte gUnk_08326C60
	.4byte gUnk_08326D70
	.4byte gUnk_08326E78
	.4byte gUnk_08326F84
	.4byte gUnk_0832709C
	.4byte gUnk_083271A8
	.4byte gUnk_083272B8
	.4byte gUnk_083273C4
	.4byte gUnk_083274D0
	.4byte gUnk_083275E0
	.4byte gUnk_083276EC
	.4byte gUnk_083277F8
	.4byte gUnk_08327908
	.4byte gUnk_08327A10
	.4byte gUnk_08327B20
	.4byte gUnk_08327C2C
	.4byte gUnk_08327D3C
	.4byte gUnk_08327E50
	.4byte gUnk_08327F64
	.4byte gUnk_0832807C
	.4byte gUnk_08328190
	.4byte gUnk_083282A0
	.4byte gUnk_083283A4
	.4byte gUnk_083284A0
	.4byte gUnk_0832859C
	.4byte gUnk_08328698
	.4byte gUnk_08328790
	.global gUnk_083FF31C
gUnk_083FF31C:
	.4byte gUnk_083288A0
	.4byte gUnk_08328900
	.4byte gUnk_08328950
	.4byte gUnk_083289A4
	.4byte gUnk_083289F8
	.4byte gUnk_08328A70
	.4byte gUnk_08328AF8
	.4byte gUnk_08328B88
	.4byte gUnk_08328C1C
	.4byte gUnk_08328CB4
	.4byte gUnk_08328D4C
	.4byte gUnk_08328DE0
	.4byte gUnk_08328E70
	.4byte gUnk_08328F00
	.4byte gUnk_08328F88
	.4byte gUnk_08329010
	.4byte gUnk_08329094
	.4byte gUnk_08329118
	.4byte gUnk_08329198
	.4byte gUnk_08329214
	.4byte gUnk_08329290
	.4byte gUnk_08329308
	.4byte gUnk_08329380
	.4byte gUnk_083293F4
	.4byte gUnk_08329464
	.4byte gUnk_083294CC
	.4byte gUnk_08329530
	.4byte gUnk_08329584
	.4byte gUnk_083295CC
	.4byte gUnk_08329610
	.4byte gUnk_08329654
	.4byte gUnk_08329698
	.4byte gUnk_083296F0
	.global gUnk_083FF3A0
gUnk_083FF3A0:
	.4byte gUnk_0832975C
	.4byte gUnk_08329890
	.4byte gUnk_083299BC
	.4byte gUnk_08329AF4
	.4byte gUnk_08329C28
	.4byte gUnk_08329D4C
	.4byte gUnk_08329E6C
	.4byte gUnk_08329F78
	.4byte gUnk_0832A084
	.4byte gUnk_0832A198
	.4byte gUnk_0832A2AC
	.4byte gUnk_0832A3BC
	.4byte gUnk_0832A4C8
	.4byte gUnk_0832A5D4
	.4byte gUnk_0832A6E0
	.4byte gUnk_0832A7E8
	.4byte gUnk_0832A8F0
	.4byte gUnk_0832A9F8
	.4byte gUnk_0832AAFC
	.4byte gUnk_0832AC04
	.4byte gUnk_0832AD18
	.4byte gUnk_0832AE30
	.4byte gUnk_0832AF40
	.4byte gUnk_0832B050
	.4byte gUnk_0832B168
	.4byte gUnk_0832B27C
	.4byte gUnk_0832B390
	.4byte gUnk_0832B4A0
	.4byte gUnk_0832B5A4
	.4byte gUnk_0832B6A4
	.4byte gUnk_0832B7A4
	.4byte gUnk_0832B89C
	.4byte gUnk_0832B994
	.global gUnk_083FF424
gUnk_083FF424:
	.4byte gUnk_0832BAA8
	.4byte gUnk_0832BB04
	.4byte gUnk_0832BB50
	.4byte gUnk_0832BBA0
	.4byte gUnk_0832BBF4
	.4byte gUnk_0832BC58
	.4byte gUnk_0832BCE0
	.4byte gUnk_0832BD74
	.4byte gUnk_0832BE08
	.4byte gUnk_0832BE9C
	.4byte gUnk_0832BF30
	.4byte gUnk_0832BFC4
	.4byte gUnk_0832C054
	.4byte gUnk_0832C0E0
	.4byte gUnk_0832C168
	.4byte gUnk_0832C1EC
	.4byte gUnk_0832C270
	.4byte gUnk_0832C2F0
	.4byte gUnk_0832C36C
	.4byte gUnk_0832C3EC
	.4byte gUnk_0832C464
	.4byte gUnk_0832C4DC
	.4byte gUnk_0832C550
	.4byte gUnk_0832C5BC
	.4byte gUnk_0832C628
	.4byte gUnk_0832C690
	.4byte gUnk_0832C6F0
	.4byte gUnk_0832C734
	.4byte gUnk_0832C778
	.4byte gUnk_0832C7BC
	.4byte gUnk_0832C7FC
	.4byte gUnk_0832C83C
	.4byte gUnk_0832C890
	.global gUnk_083FF4A8
gUnk_083FF4A8:
	.4byte gUnk_0832C8F4
	.4byte gUnk_0832CA28
	.4byte gUnk_0832CB54
	.4byte gUnk_0832CC88
	.4byte gUnk_0832CDBC
	.4byte gUnk_0832CEE0
	.4byte gUnk_0832D000
	.4byte gUnk_0832D10C
	.4byte gUnk_0832D218
	.4byte gUnk_0832D32C
	.4byte gUnk_0832D43C
	.4byte gUnk_0832D54C
	.4byte gUnk_0832D654
	.4byte gUnk_0832D760
	.4byte gUnk_0832D868
	.4byte gUnk_0832D970
	.4byte gUnk_0832DA78
	.4byte gUnk_0832DB7C
	.4byte gUnk_0832DC84
	.4byte gUnk_0832DD88
	.4byte gUnk_0832DE98
	.4byte gUnk_0832DFAC
	.4byte gUnk_0832E0BC
	.4byte gUnk_0832E1CC
	.4byte gUnk_0832E2E4
	.4byte gUnk_0832E3F4
	.4byte gUnk_0832E508
	.4byte gUnk_0832E618
	.4byte gUnk_0832E71C
	.4byte gUnk_0832E81C
	.4byte gUnk_0832E918
	.4byte gUnk_0832EA10
	.4byte gUnk_0832EB08
	.global gUnk_083FF52C
gUnk_083FF52C:
	.4byte gUnk_0832EC18
	.4byte gUnk_0832EC74
	.4byte gUnk_0832ECC0
	.4byte gUnk_0832ED10
	.4byte gUnk_0832ED64
	.4byte gUnk_0832EDC8
	.4byte gUnk_0832EE50
	.4byte gUnk_0832EEE4
	.4byte gUnk_0832EF78
	.4byte gUnk_0832F00C
	.4byte gUnk_0832F0A0
	.4byte gUnk_0832F134
	.4byte gUnk_0832F1C4
	.4byte gUnk_0832F250
	.4byte gUnk_0832F2D8
	.4byte gUnk_0832F35C
	.4byte gUnk_0832F3E0
	.4byte gUnk_0832F460
	.4byte gUnk_0832F4E0
	.4byte gUnk_0832F560
	.4byte gUnk_0832F5D8
	.4byte gUnk_0832F650
	.4byte gUnk_0832F6C4
	.4byte gUnk_0832F730
	.4byte gUnk_0832F79C
	.4byte gUnk_0832F804
	.4byte gUnk_0832F864
	.4byte gUnk_0832F8A8
	.4byte gUnk_0832F8EC
	.4byte gUnk_0832F930
	.4byte gUnk_0832F970
	.4byte gUnk_0832F9B0
	.4byte gUnk_0832FA04
