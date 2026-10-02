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
	.global gDriverSteveParkNumberFrames
gDriverSteveParkNumberFrames:
	cSym gDriverSteveParkNumberFrames
	mPtr gUnk_0831C898
	.global gDriverDaleEarnhardtJRNumberFrames
gDriverDaleEarnhardtJRNumberFrames:
	cSym gDriverDaleEarnhardtJRNumberFrames
	mPtr gUnk_0831C8D4
	.global gDriverKevinHarvickNumberFrames
gDriverKevinHarvickNumberFrames:
	cSym gDriverKevinHarvickNumberFrames
	mPtr gUnk_0831C918
	.global gDriverDaleJarrettNumberFrames
gDriverDaleJarrettNumberFrames:
	cSym gDriverDaleJarrettNumberFrames
	mPtr gUnk_0831C960
	.global gDriverRickyRuddNumberFrames
gDriverRickyRuddNumberFrames:
	cSym gDriverRickyRuddNumberFrames
	mPtr gUnk_0831C9A8
	.global gDriverJeffGordonNumberFrames
gDriverJeffGordonNumberFrames:
	cSym gDriverJeffGordonNumberFrames
	mPtr gUnk_0831C9F0
	.global gDriverJasonPopeNumberFrames
gDriverJasonPopeNumberFrames:
	cSym gDriverJasonPopeNumberFrames
	mPtr gUnk_0831CA38
	.global gDriverJoeFriedNumberFrames
gDriverJoeFriedNumberFrames:
	cSym gDriverJoeFriedNumberFrames
	mPtr gUnk_0831CA80
	.global gDriverRustyWallaceNumberFrames
gDriverRustyWallaceNumberFrames:
	cSym gDriverRustyWallaceNumberFrames
	mPtr gUnk_0831CAC8
	.global gDriverSterlingMarlinNumberFrames
gDriverSterlingMarlinNumberFrames:
	cSym gDriverSterlingMarlinNumberFrames
	mPtr gUnk_0831CB04
	.global gDriverBrianLockeNumberFrames
gDriverBrianLockeNumberFrames:
	cSym gDriverBrianLockeNumberFrames
	mPtr gUnk_0831CB4C
	.global gDriverJayMcgeeNumberFrames
gDriverJayMcgeeNumberFrames:
	cSym gDriverJayMcgeeNumberFrames
	mPtr gUnk_0831CB94
	.global gDriverMitchellSlaterNumberFrames
gDriverMitchellSlaterNumberFrames:
	cSym gDriverMitchellSlaterNumberFrames
	mPtr gUnk_0831CBDC
	.global gDriverJamesBrownNumberFrames
gDriverJamesBrownNumberFrames:
	cSym gDriverJamesBrownNumberFrames
	mPtr gUnk_0831CC24
	.global gDriverNeilWilsonNumberFrames
gDriverNeilWilsonNumberFrames:
	cSym gDriverNeilWilsonNumberFrames
	mPtr gUnk_0831CC6C
	.global gDriverTimMunsonNumberFrames
gDriverTimMunsonNumberFrames:
	cSym gDriverTimMunsonNumberFrames
	mPtr gUnk_0831CCB4
	.global gDriverAndrewBishopNumberFrames
gDriverAndrewBishopNumberFrames:
	cSym gDriverAndrewBishopNumberFrames
	mPtr gUnk_0831CCFC
	.global gDriverDanielEvansNumberFrames
gDriverDanielEvansNumberFrames:
	cSym gDriverDanielEvansNumberFrames
	mPtr gUnk_0831CD44
	.global gDriverSeanKendrickNumberFrames
gDriverSeanKendrickNumberFrames:
	cSym gDriverSeanKendrickNumberFrames
	mPtr gUnk_0831CD8C
	.global gDriverJakeMayNumberFrames
gDriverJakeMayNumberFrames:
	cSym gDriverJakeMayNumberFrames
	mPtr gUnk_0831CDD4
	.global gDriverChrisWalshNumberFrames
gDriverChrisWalshNumberFrames:
	cSym gDriverChrisWalshNumberFrames
	mPtr gUnk_0831CE1C
	.global gDriverJamesDalyNumberFrames
gDriverJamesDalyNumberFrames:
	cSym gDriverJamesDalyNumberFrames
	mPtr gUnk_0831CE64
	.global gDriverAdamBouskillNumberFrames
gDriverAdamBouskillNumberFrames:
	cSym gDriverAdamBouskillNumberFrames
	mPtr gUnk_0831CEAC
	.global gDriverTimCoodeNumberFrames
gDriverTimCoodeNumberFrames:
	cSym gDriverTimCoodeNumberFrames
	mPtr gUnk_0831CEF4
	.global gDriverWillGreenoughNumberFrames
gDriverWillGreenoughNumberFrames:
	cSym gDriverWillGreenoughNumberFrames
	mPtr gUnk_0831CF3C
	.global gDriverJonnieShearnNumberFrames
gDriverJonnieShearnNumberFrames:
	cSym gDriverJonnieShearnNumberFrames
	mPtr gUnk_0831CF84
	.global gDriverDaveMurphyNumberFrames
gDriverDaveMurphyNumberFrames:
	cSym gDriverDaveMurphyNumberFrames
	mPtr gUnk_0831CFCC
	.global gDriverDarrenJacksonNumberFrames
gDriverDarrenJacksonNumberFrames:
	cSym gDriverDarrenJacksonNumberFrames
	mPtr gUnk_0831D014
	.global gDriverMikeMerrenNumberFrames
gDriverMikeMerrenNumberFrames:
	cSym gDriverMikeMerrenNumberFrames
	mPtr gUnk_0831D05C
	.global gDriverCameronSheppardNumberFrames
gDriverCameronSheppardNumberFrames:
	cSym gDriverCameronSheppardNumberFrames
	mPtr gUnk_0831D0A4
	.global gUnk_083FEF80
gUnk_083FEF80:
	cSym gUnk_083FEF80
	mPtr gUnk_0831D10C
	mPtr gUnk_0831D240
	mPtr gUnk_0831D36C
	mPtr gUnk_0831D4A4
	mPtr gUnk_0831D5D8
	mPtr gUnk_0831D6FC
	mPtr gUnk_0831D81C
	mPtr gUnk_0831D928
	mPtr gUnk_0831DA34
	mPtr gUnk_0831DB48
	mPtr gUnk_0831DC5C
	mPtr gUnk_0831DD68
	mPtr gUnk_0831DE74
	mPtr gUnk_0831DF80
	mPtr gUnk_0831E08C
	mPtr gUnk_0831E198
	mPtr gUnk_0831E2A8
	mPtr gUnk_0831E3B0
	mPtr gUnk_0831E4C0
	mPtr gUnk_0831E5C8
	mPtr gUnk_0831E6D8
	mPtr gUnk_0831E7F0
	mPtr gUnk_0831E900
	mPtr gUnk_0831EA10
	mPtr gUnk_0831EB28
	mPtr gUnk_0831EC3C
	mPtr gUnk_0831ED50
	mPtr gUnk_0831EE60
	mPtr gUnk_0831EF64
	mPtr gUnk_0831F064
	mPtr gUnk_0831F164
	mPtr gUnk_0831F260
	mPtr gUnk_0831F354
	.global gUnk_083FF004
gUnk_083FF004:
	cSym gUnk_083FF004
	mPtr gUnk_0831F468
	mPtr gUnk_0831F4C4
	mPtr gUnk_0831F510
	mPtr gUnk_0831F560
	mPtr gUnk_0831F5B4
	mPtr gUnk_0831F618
	mPtr gUnk_0831F6A0
	mPtr gUnk_0831F734
	mPtr gUnk_0831F7C8
	mPtr gUnk_0831F85C
	mPtr gUnk_0831F8F0
	mPtr gUnk_0831F984
	mPtr gUnk_0831FA14
	mPtr gUnk_0831FAA0
	mPtr gUnk_0831FB28
	mPtr gUnk_0831FBAC
	mPtr gUnk_0831FC30
	mPtr gUnk_0831FCB0
	mPtr gUnk_0831FD30
	mPtr gUnk_0831FDB0
	mPtr gUnk_0831FE28
	mPtr gUnk_0831FE9C
	mPtr gUnk_0831FF10
	mPtr gUnk_0831FF7C
	mPtr gUnk_0831FFE8
	mPtr gUnk_08320050
	mPtr gUnk_083200B0
	mPtr gUnk_083200F4
	mPtr gUnk_08320138
	mPtr gUnk_0832017C
	mPtr gUnk_083201BC
	mPtr gUnk_083201FC
	mPtr gUnk_08320250
	.global gUnk_083FF088
gUnk_083FF088:
	cSym gUnk_083FF088
	mPtr gUnk_083202B4
	mPtr gUnk_083203E8
	mPtr gUnk_08320510
	mPtr gUnk_08320648
	mPtr gUnk_0832077C
	mPtr gUnk_083208A0
	mPtr gUnk_083209C0
	mPtr gUnk_08320ACC
	mPtr gUnk_08320BD8
	mPtr gUnk_08320CEC
	mPtr gUnk_08320E00
	mPtr gUnk_08320F10
	mPtr gUnk_0832101C
	mPtr gUnk_08321128
	mPtr gUnk_0832122C
	mPtr gUnk_08321338
	mPtr gUnk_08321440
	mPtr gUnk_08321544
	mPtr gUnk_08321648
	mPtr gUnk_08321744
	mPtr gUnk_0832184C
	mPtr gUnk_08321958
	mPtr gUnk_08321A68
	mPtr gUnk_08321B78
	mPtr gUnk_08321C90
	mPtr gUnk_08321DA4
	mPtr gUnk_08321EB8
	mPtr gUnk_08321FC8
	mPtr gUnk_083220CC
	mPtr gUnk_083221CC
	mPtr gUnk_083222CC
	mPtr gUnk_083223C4
	mPtr gUnk_083224BC
	.global gUnk_083FF10C
gUnk_083FF10C:
	cSym gUnk_083FF10C
	mPtr gUnk_083225CC
	mPtr gUnk_08322628
	mPtr gUnk_08322674
	mPtr gUnk_083226C4
	mPtr gUnk_08322718
	mPtr gUnk_0832277C
	mPtr gUnk_08322804
	mPtr gUnk_08322898
	mPtr gUnk_0832292C
	mPtr gUnk_083229C0
	mPtr gUnk_08322A54
	mPtr gUnk_08322AE8
	mPtr gUnk_08322B78
	mPtr gUnk_08322C04
	mPtr gUnk_08322C8C
	mPtr gUnk_08322D10
	mPtr gUnk_08322D94
	mPtr gUnk_08322E14
	mPtr gUnk_08322E94
	mPtr gUnk_08322F14
	mPtr gUnk_08322F8C
	mPtr gUnk_08323004
	mPtr gUnk_08323078
	mPtr gUnk_083230E4
	mPtr gUnk_08323150
	mPtr gUnk_083231B8
	mPtr gUnk_08323218
	mPtr gUnk_0832325C
	mPtr gUnk_083232A0
	mPtr gUnk_083232E4
	mPtr gUnk_08323324
	mPtr gUnk_08323364
	mPtr gUnk_083233B8
	.global gUnk_083FF190
gUnk_083FF190:
	cSym gUnk_083FF190
	mPtr gUnk_0832341C
	mPtr gUnk_0832354C
	mPtr gUnk_08323674
	mPtr gUnk_083237A8
	mPtr gUnk_083238D8
	mPtr gUnk_083239FC
	mPtr gUnk_08323B1C
	mPtr gUnk_08323C24
	mPtr gUnk_08323D30
	mPtr gUnk_08323E3C
	mPtr gUnk_08323F50
	mPtr gUnk_0832405C
	mPtr gUnk_08324168
	mPtr gUnk_08324274
	mPtr gUnk_0832437C
	mPtr gUnk_08324484
	mPtr gUnk_08324594
	mPtr gUnk_0832469C
	mPtr gUnk_083247A8
	mPtr gUnk_083248AC
	mPtr gUnk_083249BC
	mPtr gUnk_08324AD4
	mPtr gUnk_08324BE4
	mPtr gUnk_08324CF0
	mPtr gUnk_08324E08
	mPtr gUnk_08324F1C
	mPtr gUnk_08325030
	mPtr gUnk_08325140
	mPtr gUnk_08325244
	mPtr gUnk_08325344
	mPtr gUnk_08325444
	mPtr gUnk_08325538
	mPtr gUnk_08325630
	.global gUnk_083FF214
gUnk_083FF214:
	cSym gUnk_083FF214
	mPtr gUnk_0832573C
	mPtr gUnk_08325798
	mPtr gUnk_083257E4
	mPtr gUnk_08325834
	mPtr gUnk_08325888
	mPtr gUnk_083258EC
	mPtr gUnk_08325970
	mPtr gUnk_08325A04
	mPtr gUnk_08325A94
	mPtr gUnk_08325B28
	mPtr gUnk_08325BBC
	mPtr gUnk_08325C50
	mPtr gUnk_08325CE0
	mPtr gUnk_08325D6C
	mPtr gUnk_08325DF0
	mPtr gUnk_08325E6C
	mPtr gUnk_08325EEC
	mPtr gUnk_08325F64
	mPtr gUnk_08325FDC
	mPtr gUnk_0832605C
	mPtr gUnk_083260D4
	mPtr gUnk_0832614C
	mPtr gUnk_083261C0
	mPtr gUnk_0832622C
	mPtr gUnk_08326298
	mPtr gUnk_08326300
	mPtr gUnk_08326360
	mPtr gUnk_083263A4
	mPtr gUnk_083263E8
	mPtr gUnk_0832642C
	mPtr gUnk_0832646C
	mPtr gUnk_083264AC
	mPtr gUnk_08326500
	.global gUnk_083FF298
gUnk_083FF298:
	cSym gUnk_083FF298
	mPtr gUnk_08326564
	mPtr gUnk_08326694
	mPtr gUnk_083267B0
	mPtr gUnk_083268E4
	mPtr gUnk_08326A18
	mPtr gUnk_08326B44
	mPtr gUnk_08326C60
	mPtr gUnk_08326D70
	mPtr gUnk_08326E78
	mPtr gUnk_08326F84
	mPtr gUnk_0832709C
	mPtr gUnk_083271A8
	mPtr gUnk_083272B8
	mPtr gUnk_083273C4
	mPtr gUnk_083274D0
	mPtr gUnk_083275E0
	mPtr gUnk_083276EC
	mPtr gUnk_083277F8
	mPtr gUnk_08327908
	mPtr gUnk_08327A10
	mPtr gUnk_08327B20
	mPtr gUnk_08327C2C
	mPtr gUnk_08327D3C
	mPtr gUnk_08327E50
	mPtr gUnk_08327F64
	mPtr gUnk_0832807C
	mPtr gUnk_08328190
	mPtr gUnk_083282A0
	mPtr gUnk_083283A4
	mPtr gUnk_083284A0
	mPtr gUnk_0832859C
	mPtr gUnk_08328698
	mPtr gUnk_08328790
	.global gUnk_083FF31C
gUnk_083FF31C:
	cSym gUnk_083FF31C
	mPtr gUnk_083288A0
	mPtr gUnk_08328900
	mPtr gUnk_08328950
	mPtr gUnk_083289A4
	mPtr gUnk_083289F8
	mPtr gUnk_08328A70
	mPtr gUnk_08328AF8
	mPtr gUnk_08328B88
	mPtr gUnk_08328C1C
	mPtr gUnk_08328CB4
	mPtr gUnk_08328D4C
	mPtr gUnk_08328DE0
	mPtr gUnk_08328E70
	mPtr gUnk_08328F00
	mPtr gUnk_08328F88
	mPtr gUnk_08329010
	mPtr gUnk_08329094
	mPtr gUnk_08329118
	mPtr gUnk_08329198
	mPtr gUnk_08329214
	mPtr gUnk_08329290
	mPtr gUnk_08329308
	mPtr gUnk_08329380
	mPtr gUnk_083293F4
	mPtr gUnk_08329464
	mPtr gUnk_083294CC
	mPtr gUnk_08329530
	mPtr gUnk_08329584
	mPtr gUnk_083295CC
	mPtr gUnk_08329610
	mPtr gUnk_08329654
	mPtr gUnk_08329698
	mPtr gUnk_083296F0
	.global gUnk_083FF3A0
gUnk_083FF3A0:
	cSym gUnk_083FF3A0
	mPtr gUnk_0832975C
	mPtr gUnk_08329890
	mPtr gUnk_083299BC
	mPtr gUnk_08329AF4
	mPtr gUnk_08329C28
	mPtr gUnk_08329D4C
	mPtr gUnk_08329E6C
	mPtr gUnk_08329F78
	mPtr gUnk_0832A084
	mPtr gUnk_0832A198
	mPtr gUnk_0832A2AC
	mPtr gUnk_0832A3BC
	mPtr gUnk_0832A4C8
	mPtr gUnk_0832A5D4
	mPtr gUnk_0832A6E0
	mPtr gUnk_0832A7E8
	mPtr gUnk_0832A8F0
	mPtr gUnk_0832A9F8
	mPtr gUnk_0832AAFC
	mPtr gUnk_0832AC04
	mPtr gUnk_0832AD18
	mPtr gUnk_0832AE30
	mPtr gUnk_0832AF40
	mPtr gUnk_0832B050
	mPtr gUnk_0832B168
	mPtr gUnk_0832B27C
	mPtr gUnk_0832B390
	mPtr gUnk_0832B4A0
	mPtr gUnk_0832B5A4
	mPtr gUnk_0832B6A4
	mPtr gUnk_0832B7A4
	mPtr gUnk_0832B89C
	mPtr gUnk_0832B994
	.global gUnk_083FF424
gUnk_083FF424:
	cSym gUnk_083FF424
	mPtr gUnk_0832BAA8
	mPtr gUnk_0832BB04
	mPtr gUnk_0832BB50
	mPtr gUnk_0832BBA0
	mPtr gUnk_0832BBF4
	mPtr gUnk_0832BC58
	mPtr gUnk_0832BCE0
	mPtr gUnk_0832BD74
	mPtr gUnk_0832BE08
	mPtr gUnk_0832BE9C
	mPtr gUnk_0832BF30
	mPtr gUnk_0832BFC4
	mPtr gUnk_0832C054
	mPtr gUnk_0832C0E0
	mPtr gUnk_0832C168
	mPtr gUnk_0832C1EC
	mPtr gUnk_0832C270
	mPtr gUnk_0832C2F0
	mPtr gUnk_0832C36C
	mPtr gUnk_0832C3EC
	mPtr gUnk_0832C464
	mPtr gUnk_0832C4DC
	mPtr gUnk_0832C550
	mPtr gUnk_0832C5BC
	mPtr gUnk_0832C628
	mPtr gUnk_0832C690
	mPtr gUnk_0832C6F0
	mPtr gUnk_0832C734
	mPtr gUnk_0832C778
	mPtr gUnk_0832C7BC
	mPtr gUnk_0832C7FC
	mPtr gUnk_0832C83C
	mPtr gUnk_0832C890
	.global gUnk_083FF4A8
gUnk_083FF4A8:
	cSym gUnk_083FF4A8
	mPtr gUnk_0832C8F4
	mPtr gUnk_0832CA28
	mPtr gUnk_0832CB54
	mPtr gUnk_0832CC88
	mPtr gUnk_0832CDBC
	mPtr gUnk_0832CEE0
	mPtr gUnk_0832D000
	mPtr gUnk_0832D10C
	mPtr gUnk_0832D218
	mPtr gUnk_0832D32C
	mPtr gUnk_0832D43C
	mPtr gUnk_0832D54C
	mPtr gUnk_0832D654
	mPtr gUnk_0832D760
	mPtr gUnk_0832D868
	mPtr gUnk_0832D970
	mPtr gUnk_0832DA78
	mPtr gUnk_0832DB7C
	mPtr gUnk_0832DC84
	mPtr gUnk_0832DD88
	mPtr gUnk_0832DE98
	mPtr gUnk_0832DFAC
	mPtr gUnk_0832E0BC
	mPtr gUnk_0832E1CC
	mPtr gUnk_0832E2E4
	mPtr gUnk_0832E3F4
	mPtr gUnk_0832E508
	mPtr gUnk_0832E618
	mPtr gUnk_0832E71C
	mPtr gUnk_0832E81C
	mPtr gUnk_0832E918
	mPtr gUnk_0832EA10
	mPtr gUnk_0832EB08
	.global gUnk_083FF52C
gUnk_083FF52C:
	cSym gUnk_083FF52C
	mPtr gUnk_0832EC18
	mPtr gUnk_0832EC74
	mPtr gUnk_0832ECC0
	mPtr gUnk_0832ED10
	mPtr gUnk_0832ED64
	mPtr gUnk_0832EDC8
	mPtr gUnk_0832EE50
	mPtr gUnk_0832EEE4
	mPtr gUnk_0832EF78
	mPtr gUnk_0832F00C
	mPtr gUnk_0832F0A0
	mPtr gUnk_0832F134
	mPtr gUnk_0832F1C4
	mPtr gUnk_0832F250
	mPtr gUnk_0832F2D8
	mPtr gUnk_0832F35C
	mPtr gUnk_0832F3E0
	mPtr gUnk_0832F460
	mPtr gUnk_0832F4E0
	mPtr gUnk_0832F560
	mPtr gUnk_0832F5D8
	mPtr gUnk_0832F650
	mPtr gUnk_0832F6C4
	mPtr gUnk_0832F730
	mPtr gUnk_0832F79C
	mPtr gUnk_0832F804
	mPtr gUnk_0832F864
	mPtr gUnk_0832F8A8
	mPtr gUnk_0832F8EC
	mPtr gUnk_0832F930
	mPtr gUnk_0832F970
	mPtr gUnk_0832F9B0
	mPtr gUnk_0832FA04
