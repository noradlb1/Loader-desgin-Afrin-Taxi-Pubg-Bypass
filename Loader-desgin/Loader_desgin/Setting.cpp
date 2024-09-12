#include "Setting.h"




ImVec4 weapon::m16 = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::AKM = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::AWM = { 1.000f, 0.089f, 0.089f, 1.000f };
ImVec4  weapon::AWMimmo = { 0.942f, 0.300f, 0.073f, 1.000f };

ImVec4  weapon::scarl = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::m762 = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::M24 = { 1.000f, 0.760f, 0.150f, 1.000f };
ImVec4  weapon::GROZZA = { 0.279f, 0.990f, 0.812f, 1.000f };
ImVec4  weapon::scope8x = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::kar98 = { 1.0f, 0.60f,0.05f, 1.0f };
ImVec4  weapon::Airdrop = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::Flare = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::Flaregun = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4 weapon::QuickDraw = { 0.866f, 0.128f, 0.081f, 1.000f };
//=============================================================
ImVec4 Colors::playerline = { 255, 0, 0, 255 };
ImVec4 Colors::playercorner = { 1.0f, 0.70f,0.30f, 1.0f };
ImVec4 Colors::playername = { 1.0f, 1.0f, 1.0f, 1.0f };
ImVec4 Colors::playerbone = { 0.986f, 0.952f, 0.209f, 1.000f };
ImVec4 Colors::playerbox = { 1.0f, 1.0f,0.0f, 1.0f };
ImVec4 Colors::pnameBackColor = { 0, 0, 0, 255 };
/////////////////////////drop//////////////////////////
ImVec4   Colors::dp = { 1.000f, 0.760f, 0.150f, 1.000f };
ImVec4   Colors::enemyLineofSight = { 1.000f, 0.760f, 0.150f, 1.000f };
ImVec4   Colors::Granadeswarn = { 1.000f, 0.760f, 0.150f, 1.000f };
ImVec4   Colors::mg3 = { 0.373f, 0.966f, 0.391f, 1.000f };
ImVec4   Colors::scope4x = { 0.937f, 0.063f, 0.937f, 1.000f };
ImVec4   Colors::scope3x = { 0.874f, 0.484f, 0.106f, 1.000f };
ImVec4  Colors::bag = { 0.529f, 0.127f, 0.903f, 1.000f };
ImVec4  Colors::armer = { 0.591f, 1.000f, 0.237f, 1.000f };
ImVec4  Colors::helmat = { 0.726f, 0.070f, 0.908f, 1.000f };
ImVec4  Colors::mosin = { 0.258f, 0.971f, 0.775f, 1.000f };
ImVec4   Colors::aug = { 0.442f, 0.971f, 0.122f, 1.000f };

ImVec4   Colors::g36 = { 0.671f, 0.217f, 1.000f, 1.000f };
ImVec4   Colors::assm = { 1.000f, 0.217f, 0.762f, 1.000f };
extern	ImVec4 Colors::Grandes = { 1.000f, 0.396f, 0.357f, 1.000f };
extern	ImVec4 Colors::ammo7 = { 0.957f, 0.353f, 0.226f, 1.000f };
extern	ImVec4 Colors::ammo5 = { 0.000f, 1.000f, 0.000f, 1.000f };
extern ImVec4 Colors::madkit = { 0.952f, 0.558f, 0.129f, 1.000f };

// ARGB
ImVec4  Colors::helthbar = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors::boxColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors::cornerColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors::crosshairColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors::bot = { 255.0f, 255.0f, 255.0f, 255.0f };
ImVec4  Colors::player = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors::vehicle = { 0.996f, 0.859f, 0.226f, 1.100f };
//RGB
ImVec4  Colors::botcorner = { 0.050f, 0.125f, 0.925f, 1.0f };
ImVec4  Colors::botline = { 1.0f, 1.0f, 1.0f, 1.0f };
ImVec4  Colors::circle = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors::enemy = { 255, 255, 255, 255 };
ImVec4  Colors::botbox = { 0.950f, 0.125f, 0.925f, 1.0f };
ImVec4  Colors::bone = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors::fillrect = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4  Colors::nam = { 0, 255, 251.304, 255 };
ImVec4  Colors::nambar = { 0.880f, 0.185f, 0.25f, 1.0f };
ImVec4  Colors::bothealth = { 0.95f, 0.125f, 0.825f, 1.0f };
ImVec4  Colors::botname = { 0.050f, 0.825f, 0.185f, 1.0f };
ImVec4  Colors::playerhealth = { 0.50f, 0.725f, 0.105f, 1.0f };
ImVec4  Colors::textcolor = { 0.500f, 0.150f, 0.125f, 1.0f };

ImVec4  Colors::Granades = { 0.990f, 0.995f, 0.995f, 1.0f };
ImVec4  Colors::health = { 0.108f, 1.000f, 1.000f, 1.000f };
ImVec4  Colors::deadbox = { 0.000f, 1.0f, 0.0f, 1.000f };
ImVec4  Colors::deadboxitem = { 1.000f, 0.100f, 0.401f, 1.000f };
ImVec4  Colors::airdrop = { 1.000f, 0.695f, 0.323f, 1.000f };
ImVec4  Colors::airdropitem = { 0.300f, 0.695f, 0.323f, 1.000f };
ImVec4  Colors::scopetextcolor = { 0.000f, 0.995f, 0.995f, 1.000f };
ImVec4  Colors::allitem = { 0.034f, 1.000f, 0.040f, 1.000f };
ImVec4  Colors::scope6x = { 0.120f, 0.955f, 0.125f, 1.0f };
ImVec4 Colors::botbone = { 0.050f, 0.025f, 0.925f, 1.0f };
ImVec4 Colors::magicline = { 255, 255, 0, 255 };
ImVec4 Colors::magiclinevvisile = { 255, 255, 0, 255 };
ImVec4 Colors::bgcorner = { 0.000f, 1.000f, 0.964f, 1.000f };
ImVec4 Colors::targetenemybone = { 1.000f, 0.695f, 0.323f, 1.000f };

ImVec4 Colors::fovcirclecolor = { 255, 255, 255, 255 };

ImVec4 Colors::plyerdistance = { 1.0, 1.0,1.0, 255 };
ImVec4 Colors::plyrweapon = { 255, 0, 0, 255 };

ImVec4 Colors::skelec = { 255, 255, 255, 255 };
ImVec4  Colors::hpt = { 255, 255, 255, 255 };
bool Setting::VisCheck = false;

int Setting::AimbotKey = 0;
int Setting::FastCarKeys = 0x10;
int Setting::CamerAimbotKey = 0x01;
int Setting::fastrunkey = 16;
int Setting::GodViewKey = 0x14;
int Setting::PositionKey = 0;
int Setting::EnableKey = 0;
bool  Setting::plan = true;
ImVec4  Setting::plancolor = { 0.737f, 1.000f, 0.000f, 1.000f };
ImVec4  Setting::dotss = { 0.950f, 0.125f, 0.925f, 1.0f };

bool Setting::radar = false;
bool Setting::dots = true;
int Setting::redioption = 1;
bool Setting::redioption2 = false;
bool Setting::SkipBots = false;
bool Setting::SkipKnocked = false;
bool Setting::AimLineCross = true;
bool Setting::IsimingAtYou = true;
bool Setting::AimLineBottm = false;
bool Setting::IsMagicInitialize = false;
bool Setting::Magntic = false;
float Setting::Aimspeed = 11;
int	Setting::curraim = 0;
int	Setting::autocurraim = 0;
int	Setting::RadarLength = 200;
int	Setting::RadarWidth = 200;
char  Setting::filename[] = "C:\\VENIX.ini";
float Setting::fontsize = 15;
float Setting::Normalfontsize = 15;


extern float  Setting::plinesize = 0.05f;
extern float  Setting::pfullboxsize = 0.7f;
extern float  Setting::pcornersize = 0.7f;
extern float Setting::pbonesize = 0.7f;

extern float Setting::blinesize = 0.7f;
extern float Setting::bfullboxsize = 0.7f;
extern float Setting::bcornersize = 0.7f;
extern float Setting::bbonesize = 0.7f;
extern float Setting::PlayerMAxDistance = 350.0f;
extern float Setting::VehicalMexDistance = 700.0f;
extern float Setting::ItemMaxDistance = 50.0f;
extern int Setting::UpdateThreadDelay = 400;
extern int Setting::AdreessGetterDelay = 500;
extern int Setting::EspThreadDelay = 10;
extern int Setting::dotsize = 25;
bool Setting::MagicX = false;


bool Setting::pflag = true;
bool Setting::knocked = false;
bool Setting::gameinfo = true;
bool Setting::enemyoffscreen = false;
bool Setting::Modskin = true;
bool Setting::MyLineOfSight = false;
bool Setting::EnemyLineOfSight = false;
bool Setting::aimbotposition = true;
int Setting::Tab = 0;
DWORD Setting::CurrentTargetAddress = 0;
float Setting::fovcircleredus = 30.0f;
float Setting::enemyLineofSightSize = 200.0f;
float Setting::CurrentBulletFireSpeed = 0.0f;

bool Setting::fovcircle = false;
bool Setting::PREDICTION = false;
ImVec4 Setting::colorcode;
bool Setting::botname = true;
bool Setting::bothealth = true;
bool Setting::botfullbox = false;
bool Setting::botblood = true;
bool Setting::pcorner = false;
bool Setting::botcorner = false;
bool Setting::enemyIdd = false;
//playr
bool Setting::pline = true;
bool Setting::plyrdistance = true;
bool Setting::playerweapon = true;
bool Setting::Enenmyaim = true;
bool Setting::Nextzone = true;
bool Setting::botline = true;
bool Setting::phealth = true;
bool Setting::puid = false;
bool Setting::bg = true;

bool Setting::loginn = true;

bool Setting::pfullbox = false;
bool Setting::pname = true;
bool Setting::pblood = true;
bool Setting::plyrbox = false;
bool Setting::plyrwep = false;

bool Setting::boxitems = true;
bool Setting::MAgicline = false;
bool Setting::watermark = true;
bool Setting::fightmode = false;

bool Setting::feul = true;
bool Setting::hp = true;

bool Setting::style1 = false;
bool Setting::style2 = true;
bool Setting::botBone = true;

float Setting::pnameCurve = 1.0f;

bool Setting::LootIMG = true;

bool Setting::pnameBack = true;
bool Setting::pnameBackCol = false;
float Setting::pnameBackTrans = 1.0f;

bool Setting::Bags = true;
bool Setting::Armer = false;
bool Setting::Helmat = true;

bool Setting::playerBone = true;
bool  Setting::airdrop = false;
bool  Setting::airdropitem = true;
bool  Setting::deadbox = true;
bool  Setting::playerdeadbox = true;
bool  Setting::itemrect = true;
bool Setting::ShowMenu = true;
bool Setting::ShowSideMenu = true;
bool Setting::ShowMenu5 = true;
bool Setting::antitaskbar = false;
bool Setting::antitaskmanager = false;
bool Setting::AntiScreenShot = false;
bool Setting::CRPTPressed = false;
bool Setting::wwcd22 = true;
int Setting::gametime = 0;
bool Setting::Name = true;
bool Setting::Distance = true;
bool Setting::Distancee = true;
bool Setting::TotalEnemy = true;
bool Setting::Line = false;
bool Setting::Box = false;
bool Setting::Bone = true;
bool Setting::Health = false;
bool Setting::BombAlert = true;
bool Setting::Item = true;
bool Setting::PlayerESP = true;
bool Setting::Vehicle = true;
bool Setting::UselessShow = false;
//=============================================================
int Setting::AimbotSmoothValue = 11;
int Setting::AimbotPredictValue = 7;
float Setting::HeadPos = 10;
bool Setting::AimbotPredict = false;
bool Setting::AimbotSmooth = false;
//int Setting::AimbotKey = 0 + (VK_RBUTTON);
//int Setting::AimbotKey = 0;
//int Setting::fastrunkey = 0 + (VK_LSHIFT);


bool Setting::FastSwitch = false;
int Setting::BackgroundTransparency = 180;
int Setting::SelectedTheme = 0;
int Setting::RefreshMagic = 0 + ('R');
bool Setting::engine = 0;
bool Setting::skele = 0;
bool Setting::impitems = true;
bool Setting::scope = true;
bool Setting::granedwarn = true;
bool Setting::healthitem = true;
bool Setting::allitemss = true;
bool Setting::instanthit = false;
bool Setting::XEffect = false;
bool Setting::XEffectRandomBody = false;
bool Setting::XEffectRandomHead = false;
bool Setting::fastrun = false;
bool Setting::ScopeZoom = false;
bool Setting::FastWeponSwith = false;
bool Setting::fastShoot = false;
bool Setting::ShowDaamge = false;
bool Setting::GodView = false;
bool Setting::IpadView = false;
bool Setting::fly = false;
bool Setting::carfly = false;
bool Setting::speedcar = false;
bool Setting::recoil = false;
bool Setting::ForceTPP = false;
bool Setting::vahicle_item = true;
bool Setting::FastLoot = false;
//======================================
bool Setting::plinecolor = false;
bool Setting::playerBonecolor = false;
bool Setting::playerCornercolor = false;
int Setting::pnamepos = 0;
bool Setting::bortext = true;

FLOAT Setting::XEffectBodyColor[3] = { 0.976f, 0.976f, 0.976f };
FLOAT Setting::XEffectHeadColor[3] = { 0.866f, 0.128f, 0.081f };
float Setting::XeffectLineSize = 100.0f;
bool Setting::MagicRangeCheck = false;
//======================

bool Setting::ResetGuest = false;
bool Setting::SkipUpdates = false;
bool Setting::DamageController = false;
bool Setting::ShowDamage = false;
bool Setting::xeffect = false;
bool Setting::FasterLoot = false;
bool Setting::FasterChangeWeapon = false;
bool Setting::LootBehindWall = false;
bool Setting::NINEFPS = false;
bool Setting::GraphicsSetting = false;
bool Setting::AimAssist = false;


bool Setting::BatteryPercentage = false;
bool Setting::FakeKillMessage = false;


bool Setting::Radar = false;


bool Setting::Esp_Item_AKM_Icon = true;
bool Setting::Esp_Item_AKM = true;
float Setting::Esp_Item_AKM_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting::Esp_Item_AKM_TextSize = 20.0f;


bool Setting::Esp_Item_M249 = true;
ImVec4 Colors::M249 = { 1.00f, 0.76f, 0.15f, 1.0f };
 

bool Setting::Esp_Item_Mk12 = true;
ImVec4 Colors::MK12 = { 1.00f, 0.796f, 0.715f, 1.0f };

float Setting::fovcirclecolor[4] = { 1.000f, 0.695f, 0.323f, 1.000f };


bool Setting::Esp_Item_M762_Icon = true;
bool Setting::Esp_Item_M762 = true;
float Setting::Esp_Item_M762_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting::Esp_Item_M762_TextSize = 20.0f;

bool Setting::Esp_Item_FAMAS = true;
 float Setting::Esp_Item_FAMAS_Color[4] = { 0.00f, 1.00f, 0.635f, 1.0f };
 float Setting::Esp_Item_FAMAS_TextSize = 20.0f;

bool Setting::Esp_Item_Mk47Mutant = true;
float Setting::Esp_Item_Mk47Mutant_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting::Esp_Item_Mk47Mutant_TextSize = 20.0f;

bool Setting::Esp_Item_DP28 = true;
float Setting::Esp_Item_DP28_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting::Esp_Item_DP28_TextSize = 20.0f;

bool Setting::Esp_Item_SCARL = true;
float Setting::Esp_Item_SCARL_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting::Esp_Item_SCARL_TextSize = 20.0f;

bool Setting::Esp_Item_Mk14 = true;
float Setting::Esp_Item_Mk14_Color[4] = { 0.854f, 0.450f, 1.0f, 1.0f };
float Setting::Esp_Item_Mk14_TextSize = 20.0f;

bool Setting::Esp_Item_SniperAMR = true;
float Setting::Esp_Item_SniperAMR_Color[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
float Setting::Esp_Item_SniperAMR_TextSize = 20.0f;

bool Setting::Esp_Item_BulletAMR = true;
float Setting::Esp_Item_BulletAMR_Color[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
float Setting::Esp_Item_BulletAMR_TextSize = 20.0f;


bool Setting::Esp_Item_M416 = true;
bool Setting::Esp_Item_M416_Icon = true;
float Setting::Esp_Item_M416_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting::Esp_Item_M416_TextSize = 20.0f;

bool Setting::Esp_Item_M16A4 = true;
float Setting::Esp_Item_M16A4_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting::Esp_Item_M16A4_TextSize = 20.0f;

bool Setting::Esp_Item_G36C = true;
float Setting::Esp_Item_G36C_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting::Esp_Item_G36C_TextSize = 20.0f;

bool Setting::Esp_Item_QBZ = true;
float Setting::Esp_Item_QBZ_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting::Esp_Item_QBZ_TextSize = 20.0f;

bool Setting::Esp_Item_QBU = true;
float Setting::Esp_Item_QBU_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting::Esp_Item_QBU_TextSize = 20.0f;

bool Setting::Esp_Item_SLR = true;
float Setting::Esp_Item_SLR_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting::Esp_Item_SLR_TextSize = 20.0f;

bool Setting::Esp_Item_SKS = true;
float Setting::Esp_Item_SKS_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting::Esp_Item_SKS_TextSize = 20.0f;

bool Setting::Esp_Item_Mini14 = true;
float Setting::Esp_Item_Mini14_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting::Esp_Item_Mini14_TextSize = 20.0f;

bool Setting::Esp_Item_M24_Icon = true;
bool Setting::Esp_Item_M24 = true;
float Setting::Esp_Item_M24_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting::Esp_Item_M24_TextSize = 20.0f;

bool Setting::Esp_Item_Awm = true;
bool Setting::Esp_Item_Awmimo = true;
bool Setting::Esp_Item_Kar98k = true;
float Setting::Esp_Item_Kar98k_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting::Esp_Item_Kar98k_TextSize = 20.0f;

bool Setting::Esp_Item_PP19 = true;
float Setting::Esp_Item_PP19_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_PP19_TextSize = 20.0f;

bool Setting::Esp_Item_TommyGun = true;
float Setting::Esp_Item_TommyGun_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_TommyGun_TextSize = 20.0f;

bool Setting::Esp_Item_MP5K = true;
float Setting::Esp_Item_MP5K_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_MP5K_TextSize = 20.0f;

bool Setting::Esp_Item_UMP9 = true;
float Setting::Esp_Item_UMP9_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_UMP9_TextSize = 20.0f;

bool Setting::Esp_Item_Vector = true;
float Setting::Esp_Item_Vector_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_Vector_TextSize = 20.0f;

bool Setting::Esp_Item_Uzi = true;
float Setting::Esp_Item_Uzi_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_Uzi_TextSize = 20.0f;

bool Setting::Esp_Item_762mm = true;
float Setting::Esp_Item_762mm_Color[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting::Esp_Item_762mm_TextSize = 20.0f;

bool Setting::Esp_Item_556mm = true;
float Setting::Esp_Item_556mm_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting::Esp_Item_556mm_TextSize = 20.0f;

bool Setting::Esp_Item_9mm = true;
float Setting::Esp_Item_9mm_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting::Esp_Item_9mm_TextSize = 20.0f;

bool Setting::Esp_Item_45ACP = true;
float Setting::Esp_Item_45ACP_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_45ACP_TextSize = 20.0f;

bool Setting::Esp_Item_Holo = true;
float Setting::Esp_Item_Holo_Color[4] = { 1.00f,1.0f, 1.0f, 1.0f };
float Setting::Esp_Item_Holo_TextSize = 20.0f;

bool Setting::Esp_Item_x2 = true;
float Setting::Esp_Item_x2_Color[4] = { 0.00f, 0.976f, 1.0f, 1.0f };
float Setting::Esp_Item_x2_TextSize = 20.0f;

float Setting::CrossHairColor[4] = { 0.00f, 255.0f, 255.0f, 255.0f };
float Setting::XeffectColor[4] = { 0.976f, 0.976f, 0.976f, 1.0f };
float Setting::XeffectColorHead[4] = { 0.866f, 0.128f, 0.081f, 1.000f };


bool Setting::Esp_Item_x3 = true;
float Setting::Esp_Item_x3_Color[4] = { 1.00f, 0.596f, 0.129f, 1.00f };
float Setting::Esp_Item_x3_TextSize = 20.0f;

bool Setting::Esp_Item_x4 = true;
float Setting::Esp_Item_x4_Color[4] = { 1.00f, 0.0f, 1.0f, 1.0f };
float Setting::Esp_Item_x4_TextSize = 20.0f;

bool Setting::Esp_Item_x6 = true;
float Setting::Esp_Item_x6_Color[4] = { 0.866f, 0.128f, 0.081f, 1.000f };
float Setting::Esp_Item_x6_TextSize = 20.0f;

bool Setting::Esp_Item_x8 = true;
float Setting::Esp_Item_x8_Color[4] = { 0.866f, 0.128f, 0.081f, 1.000f };
float Setting::Esp_Item_x8_TextSize = 20.0f;

bool Setting::Esp_Item_Bag1 = true;
float Setting::Esp_Item_Bag1_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting::Esp_Item_Bag1_TextSize = 20.0f;

bool Setting::Esp_Item_Bag2 = true;
float Setting::Esp_Item_Bag2_Color[4] = { 0.329f, 0.847f, 1.00f, 1.0f };
float Setting::Esp_Item_Bag2_TextSize = 20.0f;

bool Setting::Esp_Item_Bag3 = true;
float Setting::Esp_Item_Bag3_Color[4] = { 0.866f, 0.128f, 0.081f, 1.000f };
float Setting::Esp_Item_Bag3_TextSize = 20.0f;

bool Setting::Esp_Item_Armor1 = true;
float Setting::Esp_Item_Armor1_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting::Esp_Item_Armor1_TextSize = 20.0f;

bool Setting::Esp_Item_Armor2 = true;
float Setting::Esp_Item_Armor2_Color[4] = { 0.329f, 0.847f, 1.00f, 1.0f };
float Setting::Esp_Item_Armor2_TextSize = 20.0f;

bool Setting::Esp_Item_Armor3 = true;
float Setting::Esp_Item_Armor3_Color[4] = { 0.866f, 0.128f, 0.081f, 1.000f };
float Setting::Esp_Item_Armor3_TextSize = 20.0f;

bool Setting::Esp_Item_Helmet1 = true;
float Setting::Esp_Item_Helmet1_Color[4] = { 0.61f, 0.19f, 1.00f, 1.0f };
float Setting::Esp_Item_Helmet1_TextSize = 20.0f;

bool Setting::Esp_Item_Helmet2 = true;
float Setting::Esp_Item_Helmet2_Color[4] = { 0.329f, 0.847f, 1.00f, 1.0f };
float Setting::Esp_Item_Helmet2_TextSize = 20.0f;

bool Setting::Esp_Item_Helmet3 = true;
float Setting::Esp_Item_Helmet3_Color[4] = { 0.866f, 0.128f, 0.081f, 1.000f };
float Setting::Esp_Item_Helmet3_TextSize = 20.0f;

bool Setting::Esp_Item_Frag = true;
float Setting::Esp_Item_Frag_Color[4] = { 0.945f, 0.297f, 0.117f, 1.0f };
float Setting::Esp_Item_Frag_TextSize = 20.0f;

bool Setting::Esp_Item_Smoke = true;
float Setting::Esp_Item_Smoke_Color[4] = { 0.945f, 0.297f, 0.117f, 1.0f };
float Setting::Esp_Item_Smoke_TextSize = 20.0f;

bool Setting::Esp_Item_Molotof = true;
float Setting::Esp_Item_Molotof_Color[4] = { 0.945f, 0.297f, 0.117f, 1.0f };
float Setting::Esp_Item_Molotof_TextSize = 20.0f;

bool Setting::Esp_Item_MedKit = true;
float Setting::Esp_Item_MedKit_Color[4] = { 0.074f, 0.684f, 0.439f, 1.0f };///ye bhi colors hain
float Setting::Esp_Item_MedKit_TextSize = 20.0f;//ye size , thora kam kr dain

bool Setting::Esp_Item_FirstAidKit = true;
float Setting::Esp_Item_FirstAidKit_Color[4] = { 0.869f, 0.573f, 0.349f, 1.0f };
float Setting::Esp_Item_FirstAidKit_TextSize = 20.0f;

bool Setting::Esp_Item_Painkiller = true;
float Setting::Esp_Item_Painkiller_Color[4] = { 0.705f, 0.494f, 0.301f, 1.0f };
float Setting::Esp_Item_Painkiller_TextSize = 20.0f;

bool Setting::Esp_Item_Bandage = true;
float Setting::Esp_Item_Bandage_Color[4] = { 0.074f, 0.684f, 0.439f, 1.0f };;
float Setting::Esp_Item_Bandage_TextSize = 20.0f;

bool Setting::Esp_Item_EnergyDrink = true;
float Setting::Esp_Item_EnergyDrink_Color[4] = { 0.274f, 0.197f, 0.880f, 1.0f };
float Setting::Esp_Item_EnergyDrink_TextSize = 20.0f;

bool Setting::Esp_Item_AdrenalineSyringe = true;
float Setting::Esp_Item_AdrenalineSyringe_Color[4] = { 1.0f, 0.f, 0.901f, 1.0f };
float Setting::Esp_Item_AdrenalineSyringe_TextSize = 20.0f;

bool Setting::Esp_Item_FlareGun_Icon = true;
bool Setting::Esp_Item_FlareGun = true;
float Setting::Esp_Item_FlareGun_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting::Esp_Item_FlareGun_TextSize = 20.0f;

bool Setting::Esp_Item_Flare = true;
float Setting::Esp_Item_Flare_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting::Esp_Item_Flare_TextSize = 20.0f;

bool Setting::Esp_Item_AirDrop = true;
float Setting::Esp_Item_AirDrop_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting::Esp_Item_AirDrop_TextSize = 20.0f;

bool Setting::Esp_Item_exquic = true;
float Setting::Esp_Item_exquic_Color[4] = { 0.866f, 0.128f, 0.081f, 1.000f };
float Setting::Esp_Item_exquic_TextSize = 20.0f;

bool Setting::Aimbot = false;

bool Setting::MagicBullet = false;
bool Setting::MagicBulletticked = false;
bool Setting::MagicBulletd = true;
bool Setting::silent = false;
bool Setting::XXXX = false;
bool Setting::smalll = false;

bool Setting::borderlo = true;
bool Setting::CameraCatch = false;
bool Setting::CameraAimBot = false;
bool Setting::FlyMan = false;
bool Setting::camsmooth = false;

bool Setting::grw = true;
bool Setting::modeskin = true;
bool Setting::M416Glacier = false;

bool Setting::bgmi = true;

bool Setting::sm = true;

bool Setting::molow = true;;
bool Setting::magicb = false;

int	Setting::magicv = 7;
int	Setting::magicvy = 1;
int	Setting::ttpview = 140.0f;
int	Setting::flycarv = 30000.0f;
int	Setting::instantv = 5000000.0f;
int	Setting::carsv = 180.0f;
int	Setting::corsshairvalue = 12.0f;
int	Setting::scopefov = 3.0f;
int	Setting::GodVieAndhle = 500.0f;
int	Setting::camsmoothness = 500.0f;
int	Setting::IpadViewValue = 150.0f;
int	Setting::fastrv = 5.0f;
int	Setting::FlyManHeight = 500.0f;
int	Setting::shootinterval = 0.0f;
int	Setting::magicrange = 75.0f;
//float Setting::skelec[4] = { 255, 255, 255, 255 };

bool Setting::Flags = false;


