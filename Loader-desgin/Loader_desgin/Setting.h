#pragma once

#include "Includes.h"
#include"imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"

namespace weapon {


	extern ImVec4 m16;
	extern ImVec4 AKM;
	extern ImVec4 AWM;
	extern ImVec4 AWMimmo;
	extern ImVec4 scarl;
	extern ImVec4 m762;
	extern ImVec4 M24;
	extern ImVec4  GROZZA;
	extern ImVec4 scope8x;
	extern ImVec4 kar98;
	extern ImVec4  Airdrop;
	extern ImVec4 Flare;
	extern ImVec4 Flaregun;
	extern ImVec4 QuickDraw;
}

namespace Colors {

	extern ImVec4  dp;
	extern ImVec4  enemyLineofSight;
	extern ImVec4  Granadeswarn;
	extern ImVec4  mg3;
	extern ImVec4  scope4x;
	extern ImVec4  scope3x;
	extern	ImVec4  bag;
	extern	ImVec4  armer;
	extern	ImVec4  helmat;
	extern	ImVec4  mosin;
	extern ImVec4  aug;
	extern ImVec4  g36;
	extern ImVec4  assm;
	extern	ImVec4  Grandes;
	extern	ImVec4  ammo7;
	extern	ImVec4  ammo5;
	extern ImVec4  madkit;

	/////////////////////////
	extern ImVec4 itemcolors;
	// ARGB playr
	extern	ImVec4  playerline;
	extern	ImVec4  playercorner;
	extern	ImVec4  playerbox;
	extern	ImVec4  lotbox;
	// ARGB
	extern ImVec4  helthbar;
	extern ImVec4  boxColor;
	extern ImVec4  cornerColor;
	extern ImVec4  crosshairColor;
	extern	ImVec4  bot;
	extern	ImVec4  botbone;
	extern	ImVec4  skelec;
	extern	ImVec4  playerbone;
	extern	ImVec4  player;
	extern ImVec4  vehicle;
	//RGB
	extern ImVec4  botcorner;
	extern ImVec4  botline;
	extern	ImVec4 circle;
	extern	ImVec4  enemy;
	extern	ImVec4  botbox;
	extern	ImVec4  bone;
	extern	 ImVec4  fillrect;
	extern	 ImVec4  nam;
	extern	 ImVec4  nambar;
	extern	 ImVec4  bothealth;
	extern	ImVec4  botname;
	extern	ImVec4  playerhealth;
	extern	ImVec4  textcolor;
	extern	ImVec4  plyerdistance;
	extern	ImVec4  plyrweapon;
	extern	ImVec4  targetenemybone;
	extern	ImVec4 Granades;
	extern	ImVec4 health;
	extern	ImVec4 deadbox;
	extern	ImVec4 deadboxitem;
	extern	ImVec4 airdrop;
	extern	ImVec4 airdropitem;
	extern	ImVec4 scopetextcolor;
	extern	ImVec4  allitem;
	extern	ImVec4  scope6x;
	extern	ImVec4  magicline;
	extern	ImVec4  magiclinevvisile;
	extern	ImVec4  bgcorner;
	extern	ImVec4  fovcirclecolor;
	extern	ImVec4 M249;
	extern	ImVec4 MK12;
	extern	ImVec4 hpt;
	extern  ImVec4 plinecolor;
	extern ImVec4 itemcolors;
	// ARGB playr
	extern ImVec4 playername;


	extern ImVec4 pnameBack;
	extern ImVec4 pnameBackColor;
}

namespace Setting
{
	extern int BackgroundTransparency;
	extern bool puid;
	extern bool Modskin;
	extern bool pflag; 
	extern bool knocked;
	extern bool gameinfo;
	extern bool enemyoffscreen;
	extern DWORD CurrentTargetAddress;
	extern bool SkipBots;
	extern bool SkipKnocked;
	extern bool AimLineCross;
	extern bool IsimingAtYou;
	extern bool AimLineBottm;
	extern bool MyLineOfSight;
	extern bool EnemyLineOfSight;
	extern int EnableKey;
	extern int AimbotKey;
	extern int FastCarKeys;
	extern int CamerAimbotKey;
	extern int fastrunkey;
	extern int GodViewKey;
	extern int PositionKey;
	extern	bool radar;
	extern	bool dots;
	extern	bool bg;
	extern int  redioption;
	extern int  RadarLength;
	extern int  RadarWidth;
	extern bool  redioption2;
	extern	bool IsMagicInitialize;
	extern FLOAT Aimspeed;
	extern float fovcircleredus;
	extern float enemyLineofSightSize;
	extern float CurrentBulletFireSpeed;
	extern bool aimbotposition;
	extern int Tab;
	extern bool fovcircle;
	extern bool PREDICTION;

	extern ImVec4 colorcode;
	extern bool Magntic;
	extern int	curraim;
	extern int autocurraim;
	extern bool	engine;
	extern bool	skele;
	extern bool watermark;
	extern bool MAgicline;
	extern char filename[];
	extern float Normalfontsize;
	extern float fontsize;
	extern float plinesize;
	extern float pfullboxsize;
	extern float pcornersize;
	extern float pbonesize;
	//======================
	extern bool plinecolor;
	extern bool playerBonecolor;
	extern bool playerCornercolor;
	//======================
	extern bool ResetGuest;
	extern bool xeffect;
	extern bool DamageController;
	extern bool isLoadDriver;
	extern bool SkipUpdates;
	extern bool ShowDamage;
	extern bool FasterLoot;
	extern bool FasterChangeWeapon;
	extern bool LootBehindWall;
	extern bool NINEFPS;
	extern bool BatteryPercentage;
	extern bool GraphicsSetting;
	extern bool AimAssist;
	extern bool ForceTTP;
	extern bool FakeKillMessage;
	//======================

	extern bool Watermark;
	extern float PlayerMaxDistance;
	/////////////////////////
	extern float pnameCurve;

	extern float pnameBackTrans;
	extern bool pnameBackCol;
	extern bool pnameBack;
	//======================
	extern bool antitaskbar;
	extern bool antitaskmanager;
	//======================
	extern int AimbotKey;
	extern int AimbotSmoothValue;
	extern int AimbotPredictValue;
	extern float HeadPos;
	extern bool AimbotPredict;
	extern bool AimbotSmooth;

	extern bool FastSwitch;
	extern int SelectedTheme;
	extern bool MagicRangeCheck;

	extern bool RefreshESP;
	extern int RefreshMagic;

	extern bool FastLoot;
	extern FLOAT XEffectBodyColor[3];
	extern FLOAT XEffectHeadColor[3];
	extern float XeffectLineSize;
	extern float blinesize;
	extern float bfullboxsize;
	extern float bcornersize;
	extern float bbonesize;
	extern bool silent;
	extern bool bortext;
	extern bool pcorner;
	extern bool plyrdistance;
	extern bool botdistance;
	extern bool botweapon;
	extern bool playerweapon;
	extern bool Nextzone;
	extern bool Enenmyaim;
	extern float PlayerMAxDistance;
	extern float VehicalMexDistance;
	extern float ItemMaxDistance;
	extern int UpdateThreadDelay;
	extern int AdreessGetterDelay;
	extern int EspThreadDelay;
	extern int dotsize;
	extern bool style1;
	extern bool style2;
	extern bool style3;
	extern bool ShowMenu5;
	extern bool ShowMenu;
	extern bool ShowSideMenu;
	extern bool AntiScreenShot;
	extern bool CRPTPressed;
	extern bool enemyIdd;
	extern bool profree;
	extern	bool botname, bothealth, botline, botfullbox, botblood, botcorner;
	//playr
	extern float pnameBackTrans;
	extern	bool pline, phealth, pfullbox, pname, pblood, plyrbox, plyrwep, boxitems;
	extern int gametime;
	extern bool fightmode;
	extern bool wwcd22 ;
	//======================
	extern int pnamepos;
	//======================
	extern bool Name;
	extern bool Distance;
	extern bool Distancee;
	extern bool TotalEnemy;
	extern bool Line;
	extern bool Box;
	extern bool botBone;
	extern bool playerBone;
	extern bool  Bone;
	extern bool Health;
	extern bool BombAlert;
	extern bool Item;
	extern bool PlayerESP;
	extern bool Vehicle;
	extern bool UselessShow;
	extern bool hp;
	extern bool feul;

	extern bool impitems;
	extern bool granedwarn;
	extern bool healthitem;
	extern bool scope;
	extern bool allitemss;

	extern bool instanthit;
	extern bool XEffect;
	extern bool XEffectRandomBody;
	extern bool XEffectRandomHead;
	extern bool fastrun;
	extern bool ScopeZoom;
	extern bool FastWeponSwith;
	extern bool fastShoot;
	extern bool ShowDaamge;
	extern bool GodView;
	extern bool IpadView;
	extern bool fly;
	extern bool carfly;
	extern bool speedcar;
	extern bool recoil;
	extern bool ForceTPP;
	extern bool deadboxloot;

	extern bool airdrop;
	extern bool airdropitem;
	extern bool deadbox;
	extern bool playerdeadbox;
	extern bool itemrect;
	extern bool Bags;
	extern bool Helmat;
	extern bool Armer;

	extern	bool Esp_Item_M249;

	extern	bool Esp_Item_Mk12;

	extern bool MagicX;
	extern bool plan;
	extern ImVec4 plancolor;
	extern ImVec4 dotss;
	extern bool vahicle_item;
	extern bool Esp_Item_AKM_Icon;
	extern bool Esp_Item_AKM;
	extern float Esp_Item_AKM_Color[4];
	extern float Esp_Item_AKM_TextSize;


		extern float fovcirclecolor[4];
	extern bool Esp_Item_M762_Icon;
	extern bool Esp_Item_M762;
	extern float Esp_Item_M762_Color[4];
	extern float Esp_Item_M762_TextSize;

	extern bool Esp_Item_FAMAS;
	extern float Esp_Item_FAMAS_Color[4];
	extern float Esp_Item_FAMAS_TextSize;

	extern bool Esp_Item_Mk47Mutant;
	extern float Esp_Item_Mk47Mutant_Color[4];
	extern float Esp_Item_Mk47Mutant_TextSize;

	extern bool Esp_Item_DP28;
	extern float Esp_Item_DP28_Color[4];
	extern float Esp_Item_DP28_TextSize;

	extern bool Esp_Item_SCARL;
	extern float Esp_Item_SCARL_Color[4];
	extern float Esp_Item_SCARL_TextSize;

	extern bool Esp_Item_M416_Icon;
	extern bool Esp_Item_M416;
	extern float Esp_Item_M416_Color[4];
	extern float Esp_Item_M416_TextSize;

	extern bool Esp_Item_M16A4;
	extern float Esp_Item_M16A4_Color[4];
	extern float Esp_Item_M16A4_TextSize;

	extern bool Esp_Item_G36C;
	extern float Esp_Item_G36C_Color[4];
	extern float Esp_Item_G36C_TextSize;

	extern bool Esp_Item_Mk14;
	extern float Esp_Item_Mk14_Color[4];
	extern float Esp_Item_Mk14_TextSize;

	extern bool Esp_Item_QBZ;
	extern float Esp_Item_QBZ_Color[4];
	extern float Esp_Item_QBZ_TextSize;

	extern bool Esp_Item_QBU;
	extern float Esp_Item_QBU_Color[4];
	extern float Esp_Item_QBU_TextSize;

	extern bool Esp_Item_SLR;
	extern float Esp_Item_SLR_Color[4];
	extern float Esp_Item_SLR_TextSize;

	extern bool Esp_Item_SniperAMR;
	extern float Esp_Item_SniperAMR_Color[4];
	extern float Esp_Item_SniperAMR_TextSize;

	extern bool Esp_Item_BulletAMR;
	extern float Esp_Item_BulletAMR_Color[4];
	extern float Esp_Item_BulletAMR_TextSize;


	extern bool Esp_Item_SKS;
	extern float Esp_Item_SKS_Color[4];
	extern float Esp_Item_SKS_TextSize;

	extern bool Esp_Item_Mini14;
	extern float Esp_Item_Mini14_Color[4];
	extern float Esp_Item_Mini14_TextSize;

	extern bool Esp_Item_M24_Icon;
	extern bool Esp_Item_M24;
	extern float Esp_Item_M24_Color[4];
	extern float Esp_Item_M24_TextSize;
	extern bool Esp_Item_Awm;
	extern bool Esp_Item_Awmimo;
	extern bool Esp_Item_Kar98k;
	extern float Esp_Item_Kar98k_Color[4];
	extern float Esp_Item_Kar98k_TextSize;

	extern bool Esp_Item_PP19;
	extern float Esp_Item_PP19_Color[4];
	extern float Esp_Item_PP19_TextSize;

	extern bool Esp_Item_TommyGun;
	extern float Esp_Item_TommyGun_Color[4];
	extern float Esp_Item_TommyGun_TextSize;

	extern bool Esp_Item_MP5K;
	extern float Esp_Item_MP5K_Color[4];
	extern float Esp_Item_MP5K_TextSize;

	extern bool Esp_Item_UMP9;
	extern float Esp_Item_UMP9_Color[4];
	extern float Esp_Item_UMP9_TextSize;

	extern bool Esp_Item_Vector;
	extern float Esp_Item_Vector_Color[4];
	extern float Esp_Item_Vector_TextSize;

	extern bool Esp_Item_Uzi;
	extern float Esp_Item_Uzi_Color[4];
	extern float Esp_Item_Uzi_TextSize;

	extern bool Esp_Item_762mm;
	extern float Esp_Item_762mm_Color[4];
	extern float Esp_Item_762mm_TextSize;

	extern bool Esp_Item_556mm;
	extern float Esp_Item_556mm_Color[4];
	extern float Esp_Item_556mm_TextSize;

	extern bool Esp_Item_9mm;
	extern float Esp_Item_9mm_Color[4];
	extern float Esp_Item_9mm_TextSize;

	extern bool Esp_Item_45ACP;
	extern float Esp_Item_45ACP_Color[4];
	extern float Esp_Item_45ACP_TextSize;

	extern bool Esp_Item_Holo;
	extern float Esp_Item_Holo_Color[4];
	extern float Esp_Item_Holo_TextSize;

	extern bool Esp_Item_x2;
	extern float Esp_Item_x2_Color[4];
	extern float CrossHairColor[4];
	extern float XeffectColor[4];
	extern float XeffectColorHead[4];
	extern float Esp_Item_x2_TextSize;

	extern bool Esp_Item_x3;
	extern float Esp_Item_x3_Color[4];
	extern float Esp_Item_x3_TextSize;

	extern bool Esp_Item_x4;
	extern float Esp_Item_x4_Color[4];
	extern float Esp_Item_x4_TextSize;

	extern bool Esp_Item_x6;
	extern float Esp_Item_x6_Color[4];
	extern float Esp_Item_x6_TextSize;

	extern bool Esp_Item_x8;
	extern float Esp_Item_x8_Color[4];
	extern float Esp_Item_x8_TextSize;

	extern bool Esp_Item_Bag1;
	extern float Esp_Item_Bag1_Color[4];
	extern float Esp_Item_Bag1_TextSize;

	extern bool Esp_Item_Bag2;
	extern float Esp_Item_Bag2_Color[4];
	extern float Esp_Item_Bag2_TextSize;

	extern bool Esp_Item_Bag3;
	extern float Esp_Item_Bag3_Color[4];
	extern float Esp_Item_Bag3_TextSize;

	extern bool Esp_Item_Armor1;
	extern float Esp_Item_Armor1_Color[4];
	extern float Esp_Item_Armor1_TextSize;

	extern bool Esp_Item_Armor2;
	extern float Esp_Item_Armor2_Color[4];
	extern float Esp_Item_Armor2_TextSize;

	extern bool Esp_Item_Armor3;
	extern float Esp_Item_Armor3_Color[4];
	extern float Esp_Item_Armor3_TextSize;

	extern bool Esp_Item_Helmet1;
	extern float Esp_Item_Helmet1_Color[4];
	extern float Esp_Item_Helmet1_TextSize;

	extern bool Esp_Item_Helmet2;
	extern float Esp_Item_Helmet2_Color[4];
	extern float Esp_Item_Helmet2_TextSize;

	extern bool Esp_Item_Helmet3;
	extern float Esp_Item_Helmet3_Color[4];
	extern float Esp_Item_Helmet3_TextSize;

	extern bool Esp_Item_Frag;
	extern float Esp_Item_Frag_Color[4];
	extern float Esp_Item_Frag_TextSize;

	extern bool Esp_Item_Smoke;
	extern float Esp_Item_Smoke_Color[4];
	extern float Esp_Item_Smoke_TextSize;

	extern bool Esp_Item_Molotof;
	extern float Esp_Item_Molotof_Color[4];
	extern float Esp_Item_Molotof_TextSize;

	extern bool Esp_Item_MedKit;
	extern float Esp_Item_MedKit_Color[4];
	extern float Esp_Item_MedKit_TextSize;

	extern bool Esp_Item_FirstAidKit;
	extern float Esp_Item_FirstAidKit_Color[4];
	extern float Esp_Item_FirstAidKit_TextSize;

	extern bool Esp_Item_Painkiller;
	extern float Esp_Item_Painkiller_Color[4];
	extern float Esp_Item_Painkiller_TextSize;

	extern bool Esp_Item_Bandage;
	extern float Esp_Item_Bandage_Color[4];
	extern float Esp_Item_Bandage_TextSize;




	extern bool Esp_Item_EnergyDrink;
	extern float Esp_Item_EnergyDrink_Color[4];
	extern float Esp_Item_EnergyDrink_TextSize;

	extern bool Esp_Item_AdrenalineSyringe;
	extern float Esp_Item_AdrenalineSyringe_Color[4];
	extern float Esp_Item_AdrenalineSyringe_TextSize;

	extern bool Esp_Item_FlareGun_Icon;
	extern bool Esp_Item_FlareGun;
	extern float Esp_Item_FlareGun_Color[4];
	extern float Esp_Item_FlareGun_TextSize;

	extern bool Esp_Item_Flare;
	extern float Esp_Item_Flare_Color[4];
	extern float Esp_Item_Flare_TextSize;

	extern bool Esp_Item_AirDrop;
	extern float Esp_Item_AirDrop_Color[4];
	extern float Esp_Item_AirDrop_TextSize;

	extern bool Esp_Item_exquic;
	extern float Esp_Item_exquic_Color[4];
	extern float Esp_Item_exquic_TextSize;

	extern bool Aimbot;

	extern bool MagicBullet;
	extern bool MagicBulletticked;
	extern bool MagicBulletd;

	extern bool borderlo;
	extern bool FlyMan;

	extern bool CameraCatch;
	extern bool CameraAimBot;
	extern bool camsmooth;

	extern bool grw;
	extern bool modeskin;
	extern bool M416Glacier;

	extern bool bgmi;

	extern bool sm;
	extern bool molow;
	//extern float hpt;
	extern int	magicv;
	extern int	magicvy;
	extern int	flycarv;
	extern int	ttpview;
	extern int	instantv;
	extern int	carsv;
	extern int	corsshairvalue;
	extern int	scopefov;
	extern int	GodVieAndhle;
	extern int	camsmoothness;
	extern int	IpadViewValue;
	extern int	fastrv;
	extern int	FlyManHeight;
	extern int	shootinterval;
	extern bool magicb;
	extern bool Exit;
	extern bool smalll;
	extern bool loginn;
	extern bool XXXX;

	extern int magicrange;
	extern bool Watermark;
	extern bool VisCheck;

	extern bool silent;
	extern bool Radar;
	extern bool WeaponsIMG;

	extern bool LootIMG;

	extern bool Flags;


}