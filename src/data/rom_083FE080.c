#include "global.h"
#include "data.h"

extern const u8 gText_MarinaCerra[];
extern const u8 gText_CherylSlater[];
extern const u8 gText_DanielWalsh[];
extern const u8 gText_MichelleLamb[];
extern const u8 gText_ExtraSpecialThanks[];
extern const u8 gText_BillHudson[];
extern const u8 gText_MikeCartabianoAtSennari[];
extern const u8 gText_JonTrafford[];
extern const u8 gText_JohnTaylor[];
extern const u8 gText_RobWalkley[];
extern const u8 gText_LynneBradstock[];
extern const u8 gText_SpecialThanks[];
extern const u8 gText_LoriDrazen[];
extern const u8 gText_WorldWideMarketing[];
extern const u8 gText_LeezaMariaElkhazen[];
extern const u8 gText_ElieSamaha[];
extern const u8 gText_FranchisePictures[];
extern const u8 gText_CatChannon[];
extern const u8 gText_EuropeanPrManager[];
extern const u8 gText_SusanKramer[];
extern const u8 gText_DirectorOfAmericanPr[];
extern const u8 gText_DavidBlundell[];
extern const u8 gText_ProductManager[];
extern const u8 gText_ScottSmith[];
extern const u8 gText_DirectorOfAmericanMarketing[];
extern const u8 gText_LisaCheneyBolcato[];
extern const u8 gText_DirectorOfEuropeanMarketing[];
extern const u8 gText_AaronEndo[];
extern const u8 gText_JoeBooth[];
extern const u8 gText_ExecutiveProducer[];
extern const u8 gText_AndrewWilliams[];
extern const u8 gText_Producer[];
extern const u8 gText_BamEntertainment[];
extern const u8 gText_JonathanShearn[];
extern const u8 gText_QualityAssurance[];
extern const u8 gText_DevelopmentAssistant[];
extern const u8 gText_ColinKendrick[];
extern const u8 gText_TechnicalManager[];
extern const u8 gText_DirectorOfDevelopment[];
extern const u8 gText_ProducerDesigner[];
extern const u8 gText_RockettMusic[];
extern const u8 gText_MusicSfx[];
extern const u8 gText_JoStearn[];
extern const u8 gText_AdditionalArt[];
extern const u8 gText_TerryFord[];
extern const u8 gText_GraphicArtist[];
extern const u8 gText_GianlucaCancelmi[];
extern const u8 gText_AssistantProgrammer[];
extern const u8 gText_LeadProgrammer[];
extern const u8 gText_CrawfishInteractive[];
extern const u8 gText_EmptyCreditLine[];
extern const u8 gText_HardcoreChallenges[];
extern const u8 gText_HardChallenges[];
extern const u8 gText_MediumChallenges[];
extern const u8 gText_EasyChallenges[];
extern const u8 gText_YouHaveBeatenAllThe[];
extern const u8 gUnk_082B581C[];
extern const u8 gUnk_082B582C[];
extern const u8 gUnk_082B5830[];
extern const u8 gUnk_082B5834[];
extern const u8 gUnk_082B5838[];
extern const u8 gUnk_082B583C[];
extern const u8 gUnk_082B5850[];
extern const u8 gUnk_082B586C[];
extern const u8 gUnk_082B5878[];
extern const u8 gUnk_082B587C[];
extern const u8 gUnk_082B5880[];
extern const u8 gUnk_082B589C[];
extern const u8 gUnk_082B58B0[];
extern const u8 gUnk_082B58D0[];
extern const u8 gUnk_082B58E4[];
extern const u8 gUnk_082B5900[];
extern const u8 gUnk_082B5918[];
extern const u8 gUnk_082B5934[];
extern const u8 gUnk_082B594C[];
extern const u8 gUnk_082B596C[];
extern const u8 gUnk_082B5988[];
extern const u8 gUnk_082B59A4[];
extern const u8 gUnk_082B59B8[];
extern const u8 gUnk_082B59CC[];
extern const u8 gUnk_082B59D8[];
extern const u8 gUnk_082B59E0[];
extern const u8 gUnk_082B59E8[];
extern const u8 gUnk_082B59F0[];
extern const u8 gUnk_082B59FC[];
extern const u8 gUnk_082B5A08[];
extern const u8 gUnk_082B5A18[];
extern const u8 gUnk_082B5A24[];
extern const u8 gUnk_082B5A34[];
extern const u8 gUnk_082B5A40[];
extern const u8 gUnk_082B5A50[];
extern const u8 gUnk_082B5A5C[];
extern const u8 gUnk_082B5A6C[];
extern const u8 gUnk_082B5A78[];
extern const u8 gUnk_082B5A84[];
extern const u8 gUnk_082B5A8C[];
extern const u8 gUnk_082B5AA8[];
extern const u8 gUnk_082B5ABC[];
extern const u8 gUnk_082B5AD0[];
extern const u8 gUnk_082B5AEC[];
extern const u8 gUnk_082B5AFC[];
extern const u8 gUnk_082B5B18[];
extern const u8 gUnk_082B5B2C[];
extern const u8 gUnk_082B5B38[];
extern const u8 gUnk_082B5B40[];
extern const u8 gUnk_082B5B48[];
extern const u8 gUnk_082B5B50[];
extern const u8 gUnk_082B5B58[];
extern const u8 gUnk_082B5B5C[];
extern const u8 gUnk_082B5B64[];
extern const u8 gUnk_082B5B74[];
extern const u8 gUnk_082B5B80[];
extern const u8 gUnk_082B5B84[];
extern const u8 gUnk_082B5B90[];
extern const u8 gUnk_082B5B9C[];
extern const u8 gUnk_082B5BA4[];
extern const u8 gUnk_082B5BAC[];
extern const u8 gUnk_082B5BB4[];
extern const u8 gUnk_082B5BB8[];
extern const u8 gUnk_082B5BC0[];
extern const u8 gUnk_082B5BC4[];
extern const u8 gUnk_082B5BEC[];
extern const u8 gUnk_082B5BF4[];
extern const u8 gUnk_082B5C00[];
extern const u8 gUnk_082B5C0C[];
extern const u8 gUnk_082B5C14[];
extern const u8 gUnk_082B5C20[];
extern const u8 gUnk_082B5C2C[];
extern const u8 gUnk_082B5C3C[];
extern const u8 gUnk_082B5C4C[];
extern const u8 gUnk_082B5C5C[];
extern const u8 gUnk_082B5C70[];
extern const u8 gUnk_082B5C84[];
extern const u8 gUnk_082B5C94[];
extern const u8 gUnk_082B5CA8[];
extern const u8 gUnk_082B5CBC[];
extern const u8 gUnk_082B5CC0[];
extern const u8 gUnk_082B5CC4[];
extern const u8 gUnk_082B5CD4[];
extern const u8 gUnk_082B5CDC[];
extern const u8 gUnk_082B5CE8[];
extern const u8 gUnk_082B5CF0[];
extern const u8 gUnk_082B5CFC[];
extern const u8 gUnk_082B5D04[];
extern const u8 gUnk_082B5D10[];
extern const u8 gUnk_082B5D1C[];
extern const u8 gUnk_082B5D28[];
extern const u8 gUnk_082B5D38[];
extern const u8 gUnk_082B5D48[];
extern const u8 gUnk_082B5D5C[];
extern const u8 gUnk_082B5D68[];
extern const u8 gUnk_082B5D74[];
extern const u8 gUnk_082B5D78[];
extern const u8 gUnk_082B5D84[];
extern const u8 gUnk_082B5D90[];
extern const u8 gUnk_082B5D9C[];
extern const u8 gUnk_082B5DA8[];
extern const u8 gUnk_082B5DB8[];
extern const u8 gUnk_082B5DC8[];
extern const u8 gUnk_082B5DD8[];
extern const u8 gUnk_082B5DE4[];
extern const u8 gUnk_082B5DF0[];
extern const u8 gUnk_082B5DFC[];
extern const u8 gUnk_082B5E0C[];
extern const u8 gUnk_082B5E18[];
extern const u8 gUnk_082B5E24[];
extern const u8 gUnk_082B5E28[];
extern const u8 gUnk_082B5E2C[];
extern const u8 gUnk_082B5E30[];
extern const u8 gUnk_082B5E34[];
extern const u8 gUnk_082B5E38[];
extern const u8 gUnk_082B5E3C[];
extern const u8 gUnk_082B5E40[];
extern const u8 gUnk_082B5E4C[];
extern const u8 gUnk_082B5E58[];
extern const u8 gUnk_082B5E64[];
extern const u8 gUnk_082B5E70[];
extern const u8 gUnk_082B5E7C[];
extern const u8 gUnk_082B5E80[];
extern const u8 gUnk_082B5E88[];
extern const u8 gUnk_082B5E98[];
extern const u8 gUnk_082B5EA0[];
extern const u8 gUnk_082B5EAC[];
extern const u8 gUnk_082B5EB8[];
extern const u8 gUnk_082B5EC8[];
extern const u8 gUnk_082B5ED0[];
extern const u8 gUnk_082B5EE8[];
extern const u8 gUnk_082B5EF8[];
extern const u8 gUnk_082B5F08[];
extern const u8 gUnk_082B5F20[];
extern const u8 gUnk_082B5F30[];
extern const u8 gUnk_082B5F48[];
extern const u8 gUnk_082B5F60[];
extern const u8 gUnk_082B5F78[];
extern const u8 gUnk_082B5F90[];
extern const u8 gUnk_082B5FA8[];
extern const u8 gUnk_082B5FBC[];
extern const u8 gUnk_082B5FCC[];
extern const u8 gUnk_082B5FDC[];
extern const u8 gUnk_082B5FEC[];
extern const u8 gUnk_082B5FFC[];
extern const u8 gUnk_082B6010[];
extern const u8 gUnk_082B6024[];
extern const u8 gUnk_082B603C[];
extern const u8 gUnk_082B6054[];
extern const u8 gUnk_082B606C[];
extern const u8 gUnk_082B6084[];
extern const u8 gUnk_082B6094[];
extern const u8 gUnk_082B60AC[];
extern const u8 gUnk_082B60C4[];
extern const u8 gUnk_082B60DC[];
extern const u8 gUnk_082B60F4[];
extern const u8 gUnk_082B6110[];
extern const u8 gUnk_082B6130[];
extern const u8 gUnk_082B613C[];
extern const u8 gUnk_082B6158[];
extern const u8 gUnk_082B6170[];
extern const u8 gUnk_082B6184[];
extern const u8 gUnk_082B6198[];
extern const u8 gUnk_082B61B8[];
extern const u8 gUnk_082B61CC[];
extern const u8 gUnk_082B61D8[];
extern const u8 gUnk_082B61EC[];
extern const u8 gUnk_082B6200[];
extern const u8 gUnk_082B6214[];
extern const u8 gUnk_082B6220[];
extern const u8 gUnk_082B6230[];
extern const u8 gUnk_082B6244[];
extern const u8 gUnk_082B624C[];
extern const u8 gUnk_082B6258[];
extern const u8 gUnk_082B6268[];
extern const u8 gUnk_082B6270[];
extern const u8 gUnk_082B627C[];
extern const u8 gUnk_082B6284[];
extern const u8 gUnk_082B628C[];
extern const u8 gUnk_082B6298[];
extern const u8 gUnk_082B62A8[];
extern const u8 gUnk_082B62B8[];
extern const u8 gUnk_082B62C8[];
extern const u8 gUnk_082B62D8[];
extern const u8 gUnk_082B62E8[];
extern const u8 gUnk_082B62F8[];
extern const u8 gUnk_082B6308[];
extern const u8 gUnk_082B6318[];
extern const u8 gUnk_082B6324[];
extern const u8 gUnk_082B6330[];
extern const u8 gUnk_082B633C[];
extern const u8 gUnk_082B6348[];
extern const u8 gUnk_082B6354[];
extern const u8 gUnk_082B6360[];
extern const u8 gUnk_082B636C[];
extern const u8 gUnk_082B6378[];
extern const u8 gUnk_082B6384[];
extern const u8 gUnk_082B63A4[];
extern const u8 gUnk_082B63C4[];
extern const u8 gUnk_082B63E4[];
extern const u8 gUnk_082B6404[];
extern const u8 gUnk_082B6424[];
extern const u8 gUnk_082B6444[];
extern const u8 gUnk_082B6464[];
extern const u8 gUnk_082B6484[];
extern const u8 gUnk_082B64A4[];
extern const u8 gUnk_082B64C4[];
extern const u8 gUnk_082B64E4[];
extern const u8 gUnk_082B6504[];
extern const u8 gUnk_082B6524[];
extern const u8 gUnk_082B6544[];
extern const u8 gUnk_082B6564[];
extern const u8 gUnk_082B6584[];
extern const u8 gUnk_082B65A4[];
extern const u8 gUnk_082B65C4[];
extern const u8 gUnk_082B65E4[];
extern const u8 gUnk_082B6604[];
extern const u8 gUnk_082B6624[];
extern const u8 gUnk_082B6644[];
extern const u8 gUnk_082B6664[];
extern const u8 gUnk_082B6684[];
extern const u8 gUnk_082B66A4[];
extern const u8 gUnk_082B66C4[];
extern const u8 gUnk_082B66E4[];
extern const u8 gUnk_082B6704[];
extern const u8 gUnk_082B6724[];
extern const u8 gUnk_082B6744[];
extern const u8 gUnk_082B6764[];
extern const u8 gUnk_082B6784[];
extern const u8 gUnk_082B67A4[];
extern const u8 gUnk_082B67C4[];
extern const u8 gUnk_082B67E4[];
extern const u8 gUnk_082B6804[];
extern const u8 gUnk_082B6824[];
extern const u8 gUnk_082B6844[];
extern const u8 gUnk_082B6864[];
extern const u8 gUnk_082B6884[];
extern const u8 gUnk_082B68A4[];
extern const u8 gUnk_082B68C4[];
extern const u8 gUnk_082B68E4[];
extern const u8 gUnk_082B6904[];
extern const u8 gUnk_082B6924[];
extern const u8 gUnk_082B6944[];
extern const u8 gUnk_082B6964[];
extern const u8 gUnk_082B6984[];
extern const u8 gUnk_082B69A4[];
extern const u8 gUnk_082B69C4[];
extern const u8 gUnk_082B69E4[];
extern const u8 gUnk_082B6A04[];
extern const u8 gUnk_082B6A24[];
extern const u8 gUnk_082B6A44[];
extern const u8 gUnk_082B6A64[];
extern const u8 gUnk_082B6A84[];
extern const u8 gUnk_082B6AA4[];
extern const u8 gUnk_082B6AC4[];
extern const u8 gUnk_082B6AE4[];
extern const u8 gUnk_082B6B04[];
extern const u8 gUnk_082B6B24[];
extern const u8 gUnk_082B6B44[];
extern const u8 gUnk_082B6B64[];
extern const u8 gUnk_082B6B84[];
extern const u8 gUnk_082B6BA4[];
extern const u8 gUnk_082B6BC4[];
extern const u8 gUnk_082B6BE4[];
extern const u8 gUnk_082B6C04[];
extern const u8 gUnk_082B6C24[];
extern const u8 gUnk_082B6C44[];
extern const u8 gUnk_082B6C64[];
extern const u8 gUnk_082B6C84[];
extern const u8 gUnk_082B6CA4[];
extern const u8 gUnk_082B6CC4[];
extern const u8 gUnk_082B6CE4[];
extern const u8 gUnk_082B6D04[];
extern const u8 gUnk_082B6D24[];
extern const u8 gUnk_082B6D44[];
extern const u8 gUnk_082B6D64[];
extern const u8 gUnk_082B6D84[];
extern const u8 gUnk_082B6DA4[];
extern const u8 gUnk_082B6DC4[];
extern const u8 gUnk_082B6DE4[];
extern const u8 gUnk_082B6E04[];
extern const u8 gUnk_082B6E24[];
extern const u8 gUnk_082B6E44[];
extern const u8 gUnk_082B6E64[];
extern const u8 gUnk_082B6E84[];
extern const u8 gUnk_082B6EA4[];
extern const u8 gUnk_082B6EC4[];
extern const u8 gUnk_082B6EE4[];
extern const u8 gUnk_082B6F04[];
extern const u8 gUnk_082B6F24[];
extern const u8 gUnk_082B6F44[];
extern const u8 gUnk_082B6F64[];
extern const u8 gUnk_082B6F84[];
extern const u8 gUnk_082B6FA4[];
extern const u8 gUnk_082B6FC4[];
extern const u8 gUnk_082B6FE4[];
extern const u8 gUnk_082B7004[];
extern const u8 gUnk_082B7024[];
extern const u8 gUnk_082B7044[];
extern const u8 gUnk_082B7064[];
extern const u8 gUnk_082B7084[];
extern const u8 gUnk_082B70A4[];
extern const u8 gUnk_082B70C4[];
extern const u8 gUnk_082B70E4[];
extern const u8 gUnk_082B7104[];
extern const u8 gUnk_082B7124[];
extern const u8 gUnk_082B7144[];
extern const u8 gUnk_082B7164[];
extern const u8 gUnk_082B7184[];
extern const u8 gUnk_082B71A4[];
extern const u8 gUnk_082B71C4[];
extern const u8 gUnk_082B71E4[];
extern const u8 gUnk_082B7204[];
extern const u8 gUnk_082B7224[];
extern const u8 gUnk_082B7244[];
extern const u8 gText_BlankRowChallengeGoal[];
extern const u8 gUnk_082B7284[];
extern const u8 gUnk_082B72A4[];
extern const u8 gUnk_082B72C4[];
extern const u8 gUnk_082B72E4[];
extern const u8 gUnk_082B7304[];

// Its users declare it as u8 *x[].
const u32 gCheatCodeTable[] = INCBIN_U32("build/assets/unknown/data_083FE080.bin");
// Its users declare it as struct Tbl x[].
const u32 gCreditTexts[] = {
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_CrawfishInteractive, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_LeadProgrammer, 0,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_ChrisWalsh, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_AssistantProgrammer, 0, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_GianlucaCancelmi, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_GraphicArtist, 0, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_TerryFord, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_AdditionalArt, 0,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_JoStearn, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_MusicSfx, 0, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_RockettMusic, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_ProducerDesigner, 0, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_MitchellSlater, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_DirectorOfDevelopment, 0,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_MikeMerren, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_TechnicalManager, 0, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_ColinKendrick, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_DevelopmentAssistant, 0, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_DaveMurphy, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_QualityAssurance, 0,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_TimCoode, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_WillGreenough, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_JonathanShearn, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_BamEntertainment, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_Producer, 0,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_AndrewWilliams, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_ExecutiveProducer, 0, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_JoeBooth, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_AaronEndo, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_DirectorOfEuropeanMarketing, 0,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_LisaCheneyBolcato, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_DirectorOfAmericanMarketing, 0, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_ScottSmith, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_ProductManager, 0, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_DavidBlundell, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_DirectorOfAmericanPr, 0,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_SusanKramer, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EuropeanPrManager, 0, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_CatChannon, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_FranchisePictures, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_ExecutiveProducer, 0, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_ElieSamaha, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_Producer, 0,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_LeezaMariaElkhazen, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_WorldWideMarketing, 0, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_LoriDrazen, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_SpecialThanks, 0, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_CameronSheppard, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_LynneBradstock, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_RobWalkley, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_JohnTaylor, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_JonTrafford, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_MikeCartabianoAtSennari, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_BillHudson, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_ExtraSpecialThanks, 0,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_MichelleLamb, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_DanielWalsh, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_CherylSlater, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_MarinaCerra, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1,
    (u32)gText_EmptyCreditLine, 0x1, (u32)gText_EmptyCreditLine, 0x1
};
const u32 gUnk_083FE6C4[] = {
    (u32)gUnk_082B6298, (u32)gUnk_082B628C, (u32)gUnk_082B6284,
    (u32)gUnk_082B627C, (u32)gUnk_082B6270, (u32)gUnk_082B6268,
    (u32)gUnk_082B6258, (u32)gUnk_082B624C, (u32)gUnk_082B6244,
    (u32)gUnk_082B6230, (u32)gUnk_082B6220, (u32)gUnk_082B6214,
    (u32)gUnk_082B6200, (u32)gUnk_082B61EC, (u32)gUnk_082B61D8,
    (u32)gUnk_082B61CC, (u32)gUnk_082B61B8, (u32)gUnk_082B6198,
    (u32)gUnk_082B6184, (u32)gUnk_082B6170, (u32)gUnk_082B6158,
    (u32)gUnk_082B613C, (u32)gUnk_082B6130, (u32)gUnk_082B6110,
    (u32)gUnk_082B60F4, (u32)gUnk_082B6130, (u32)gUnk_082B60DC,
    (u32)gUnk_082B60C4, (u32)gUnk_082B60AC, (u32)gUnk_082B6094,
    (u32)gUnk_082B6084, (u32)gUnk_082B606C, (u32)gUnk_082B6054,
    (u32)gUnk_082B603C, (u32)gUnk_082B6024, (u32)gUnk_082B6010,
    (u32)gUnk_082B5FFC, (u32)gUnk_082B5FEC, (u32)gUnk_082B5FDC,
    (u32)gUnk_082B5FCC, (u32)gUnk_082B5FBC, (u32)gUnk_082B5FA8,
    (u32)gUnk_082B5F90, (u32)gUnk_082B5F78, (u32)gUnk_082B5F60,
    (u32)gUnk_082B5F48, (u32)gUnk_082B5F30, (u32)gUnk_082B5F20,
    (u32)gUnk_082B5F08, (u32)gUnk_082B5EF8, (u32)gUnk_082B5EE8,
    (u32)gUnk_082B5ED0, (u32)gUnk_082B5EC8, (u32)gUnk_082B5EB8,
    (u32)gUnk_082B5EAC, (u32)gUnk_082B5EA0, (u32)gUnk_082B5E98,
    (u32)gUnk_082B5E88, (u32)gUnk_082B5E80, (u32)gUnk_082B5E7C,
    (u32)gUnk_082B5E70, (u32)gUnk_082B5E64, (u32)gUnk_082B5E58,
    (u32)gUnk_082B5E4C, (u32)gUnk_082B5E40, (u32)gUnk_082B5E3C,
    (u32)gUnk_082B5E38, (u32)gUnk_082B5E34, (u32)gUnk_082B5E30,
    (u32)gUnk_082B5E2C, (u32)gUnk_082B5E28, (u32)gUnk_082B5E24,
    (u32)gUnk_082B5E18, (u32)gUnk_082B5E0C, (u32)gUnk_082B5DFC,
    (u32)gUnk_082B5DF0, (u32)gUnk_082B5DE4, (u32)gUnk_082B5DD8,
    (u32)gUnk_082B5EC8, (u32)gUnk_082B5EC8, (u32)gUnk_082B5DC8,
    (u32)gUnk_082B5DB8, (u32)gUnk_082B5DA8, (u32)gUnk_082B5D9C,
    (u32)gUnk_082B5D90, (u32)gUnk_082B5D84, (u32)gUnk_082B5D78,
    (u32)gUnk_082B5D74, (u32)gUnk_082B5D68, (u32)gUnk_082B5D5C,
    (u32)gUnk_082B5D48, (u32)gUnk_082B5D38, (u32)gUnk_082B6284,
    (u32)gUnk_082B5D28, (u32)gUnk_082B5D1C, (u32)gUnk_082B5D10,
    (u32)gUnk_082B5D04, (u32)gUnk_082B5CFC, (u32)gUnk_082B5CF0,
    (u32)gUnk_082B5CE8, (u32)gUnk_082B5CDC, (u32)gUnk_082B5CD4,
    (u32)gUnk_082B5CC4, (u32)gUnk_082B5CC0, (u32)gUnk_082B5CBC,
    (u32)gUnk_082B5CA8, (u32)gUnk_082B5C94, (u32)gUnk_082B5C84,
    (u32)gUnk_082B5C70, (u32)gUnk_082B5C5C, (u32)gUnk_082B5C4C,
    (u32)gUnk_082B5C3C, (u32)gUnk_082B5C2C, (u32)gUnk_082B5C20,
    (u32)gUnk_082B5C14, (u32)gUnk_082B5C4C, (u32)gUnk_082B5C0C,
    (u32)gUnk_082B5C00, (u32)gUnk_082B5BF4, (u32)gUnk_082B5BEC,
    (u32)gUnk_082B5BC4, (u32)gUnk_082B5BC0, (u32)gUnk_082B5BB8,
    (u32)gUnk_082B5CD4, (u32)gUnk_082B5BB4, (u32)gUnk_082B5CDC,
    (u32)gUnk_082B5BAC, (u32)gUnk_082B5BA4, (u32)gUnk_082B5B9C,
    (u32)gUnk_082B5B90, (u32)gUnk_082B5B84, (u32)gUnk_082B5B80,
    (u32)gUnk_082B5B74, (u32)gUnk_082B5B64, (u32)gUnk_082B5C20,
    (u32)gUnk_082B5C14, (u32)gUnk_082B5B5C, (u32)gUnk_082B5B58,
    (u32)gUnk_082B5B50, (u32)gUnk_082B5B48, (u32)gUnk_082B5B40,
    (u32)gUnk_082B5B38, (u32)gUnk_082B5B2C, (u32)gUnk_082B5B18,
    (u32)gUnk_082B5AFC, (u32)gUnk_082B5AEC, (u32)gUnk_082B5AD0,
    (u32)gUnk_082B5ABC, (u32)gUnk_082B5AA8, (u32)gUnk_082B5A8C,
    (u32)gUnk_082B5A84, (u32)gUnk_082B5A78, (u32)gUnk_082B5A6C,
    (u32)gUnk_082B5B2C, (u32)gUnk_082B5A5C, (u32)gUnk_082B5A50,
    (u32)gUnk_082B5C4C, (u32)gUnk_082B5A40, (u32)gUnk_082B5A34,
    (u32)gUnk_082B5A24, (u32)gUnk_082B5A18, (u32)gUnk_082B5A08,
    (u32)gUnk_082B59FC, (u32)gUnk_082B59F0, (u32)gUnk_082B5DFC,
    (u32)gUnk_082B59E8, (u32)gUnk_082B59E0, (u32)gUnk_082B59D8,
    (u32)gUnk_082B59CC, (u32)gUnk_082B59B8, (u32)gUnk_082B59A4,
    (u32)gUnk_082B5988, (u32)gUnk_082B596C, (u32)gUnk_082B594C,
    (u32)gUnk_082B5934, (u32)gUnk_082B5918, (u32)gUnk_082B5900,
    (u32)gUnk_082B58E4, (u32)gUnk_082B58D0, (u32)gUnk_082B58B0,
    (u32)gUnk_082B589C, (u32)gUnk_082B5880, (u32)gUnk_082B587C,
    (u32)gUnk_082B5E34, (u32)gUnk_082B5E30, (u32)gUnk_082B5E2C,
    (u32)gUnk_082B5E28, (u32)gUnk_082B5878, (u32)gUnk_082B5E24,
    (u32)gUnk_082B586C, (u32)gUnk_082B5850, (u32)gUnk_082B583C,
    (u32)gUnk_082B5838, (u32)gUnk_082B5834, (u32)gUnk_082B5830,
    (u32)gUnk_082B582C, (u32)gUnk_082B581C, (u32)gText_YouHaveBeatenAllThe,
    (u32)gText_EasyChallenges, (u32)gText_MediumChallenges, (u32)gText_HardChallenges,
    (u32)gText_HardcoreChallenges
};
// Its users declare it as u8 *x[].
const u32 gChallengeNameTexts[] = {
    (u32)gUnk_082B6378, (u32)gUnk_082B636C, (u32)gUnk_082B6360,
    (u32)gUnk_082B6354, (u32)gUnk_082B6348, (u32)gUnk_082B633C,
    (u32)gUnk_082B6330, (u32)gUnk_082B6324, (u32)gUnk_082B6318,
    (u32)gUnk_082B6308, (u32)gUnk_082B62F8, (u32)gUnk_082B62E8,
    (u32)gUnk_082B62D8, (u32)gUnk_082B62C8, (u32)gUnk_082B62B8,
    (u32)gUnk_082B62A8
};
// Its users declare it as u8 *x[].
const u32 gChallengeGoalTexts[] = {
    (u32)gUnk_082B72E4, (u32)gUnk_082B72C4, (u32)gUnk_082B72A4,
    (u32)gUnk_082B7284, (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal,
    (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal,
    (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B7244, (u32)gUnk_082B7224,
    (u32)gUnk_082B7204, (u32)gUnk_082B71E4, (u32)gText_BlankRowChallengeGoal,
    (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal,
    (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B71C4,
    (u32)gUnk_082B71A4, (u32)gUnk_082B7184, (u32)gUnk_082B7164,
    (u32)gUnk_082B7144, (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal,
    (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal,
    (u32)gUnk_082B7124, (u32)gUnk_082B7104, (u32)gUnk_082B70E4,
    (u32)gUnk_082B70C4, (u32)gUnk_082B70A4, (u32)gText_BlankRowChallengeGoal,
    (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B7084, (u32)gUnk_082B7064,
    (u32)gUnk_082B7044, (u32)gUnk_082B7024, (u32)gUnk_082B7004,
    (u32)gUnk_082B6FE4, (u32)gUnk_082B6FC4, (u32)gText_BlankRowChallengeGoal,
    (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal,
    (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B6FA4,
    (u32)gUnk_082B6F84, (u32)gUnk_082B6F64, (u32)gUnk_082B6F44,
    (u32)gUnk_082B6F24, (u32)gUnk_082B6F04, (u32)gUnk_082B6EE4,
    (u32)gUnk_082B6EC4, (u32)gText_BlankRowChallengeGoal, (u32)gText_BlankRowChallengeGoal,
    (u32)gUnk_082B6EA4, (u32)gUnk_082B6E84, (u32)gUnk_082B6E64,
    (u32)gUnk_082B6E44, (u32)gUnk_082B6E24, (u32)gUnk_082B6E04,
    (u32)gUnk_082B6DE4, (u32)gUnk_082B6DC4, (u32)gUnk_082B6DA4,
    (u32)gUnk_082B6D84, (u32)gUnk_082B6D64, (u32)gUnk_082B6D44,
    (u32)gUnk_082B6D24, (u32)gUnk_082B6D04, (u32)gUnk_082B6CE4,
    (u32)gUnk_082B6CC4, (u32)gUnk_082B6CA4, (u32)gUnk_082B6C84,
    (u32)gUnk_082B6C64, (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B6C44,
    (u32)gUnk_082B6C24, (u32)gUnk_082B6C04, (u32)gUnk_082B6BE4,
    (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B6BC4, (u32)gText_BlankRowChallengeGoal,
    (u32)gUnk_082B6BA4, (u32)gUnk_082B6B84, (u32)gText_BlankRowChallengeGoal,
    (u32)gUnk_082B6B64, (u32)gUnk_082B6B44, (u32)gUnk_082B6B24,
    (u32)gUnk_082B6B04, (u32)gUnk_082B6AE4, (u32)gUnk_082B6AC4,
    (u32)gUnk_082B6AA4, (u32)gUnk_082B6A84, (u32)gUnk_082B6A64,
    (u32)gUnk_082B6A44, (u32)gUnk_082B6A24, (u32)gUnk_082B6A04,
    (u32)gUnk_082B69E4, (u32)gUnk_082B69C4, (u32)gUnk_082B69A4,
    (u32)gUnk_082B6984, (u32)gUnk_082B6964, (u32)gUnk_082B6944,
    (u32)gUnk_082B6924, (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B6904,
    (u32)gUnk_082B68E4, (u32)gUnk_082B68C4, (u32)gUnk_082B68A4,
    (u32)gUnk_082B6884, (u32)gUnk_082B6864, (u32)gUnk_082B6844,
    (u32)gUnk_082B6824, (u32)gUnk_082B6804, (u32)gUnk_082B67E4,
    (u32)gUnk_082B67C4, (u32)gUnk_082B67A4, (u32)gUnk_082B6784,
    (u32)gUnk_082B6764, (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B6744,
    (u32)gUnk_082B6724, (u32)gUnk_082B6704, (u32)gUnk_082B66E4,
    (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B66C4, (u32)gUnk_082B66A4,
    (u32)gUnk_082B6684, (u32)gUnk_082B6664, (u32)gUnk_082B6644,
    (u32)gUnk_082B6624, (u32)gUnk_082B6604, (u32)gUnk_082B65E4,
    (u32)gUnk_082B65C4, (u32)gText_BlankRowChallengeGoal, (u32)gUnk_082B65A4,
    (u32)gUnk_082B6584, (u32)gUnk_082B6564, (u32)gUnk_082B6544,
    (u32)gUnk_082B6524, (u32)gUnk_082B6504, (u32)gUnk_082B64E4,
    (u32)gUnk_082B64C4, (u32)gUnk_082B64A4, (u32)gText_BlankRowChallengeGoal,
    (u32)gUnk_082B6484, (u32)gUnk_082B6464, (u32)gUnk_082B6444,
    (u32)gUnk_082B6424, (u32)gUnk_082B6404, (u32)gUnk_082B63E4,
    (u32)gUnk_082B63C4, (u32)gUnk_082B63A4, (u32)gUnk_082B6384,
    (u32)gText_BlankRowChallengeGoal
};
const u32 gUnk_083FECAC[] = {
    (u32)gUnk_082B7304
};
const u16 gUnk_083FECB0[] = INCBIN_U16("build/assets/unknown/data_083FECB0.bin");
// Its users declare it as struct Unk083FECB8 x[].
const u32 gUnk_083FECB8[] = INCBIN_U32("build/assets/unknown/data_083FECB8.bin");
const u32 gTrackLapLengths[] = INCBIN_U32("build/assets/unknown/data_083FED18.bin");
