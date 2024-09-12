#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"
#pragma warning(disable : 4996)
#include "api/KeyAuth.hpp"
#include"SimpleIni.h"
#include<D3DX11tex.h>
#define LOADER_BRAND "Loader base"
#include "Esp.h"
#include <iostream>
#include <fstream>
#include "imguipp.h"
#include "Unicode.h"
#include "utf.h"
#include "Main.h"
#include "api/xor.h"
#include "Discord.h"
#include "api/KeyAuth.hpp"
//#include "SNOW/Snowflake.hpp"
#include <tchar.h>

#include "bp.h"
//#include "E:\hok\VN_SORUCE_WITH_LOGIN.rar\imgui-docking\imgui_notify.h"

#define TITLE "Snowflake.cpp"
#define TITLEW TEXT(TITLE)
#define WINDOW_WIDTH  1680
#define WINDOW_HEIGHT 1050
#define SNOW_LIMIT 300
//std::vector<Snowflake::Snowflake> snow;

using namespace std;
using namespace zipe;
bool fight = true;
// Declare the frame rates
const int FPS_40 = 25;
const int FPS_60 = 16;
const int FPS_90 = 11;
const int FPS_120 = 8;

template <typename T>
static T get_value(uintptr_t address)
{
	return *(T*)address;
}

template <typename T>
static void set_value(uintptr_t address, const T& value)
{
	*(T*)address = value;
}

// Declare the selected frame rate variable
int selectedFPS = FPS_40;
//char key[60] = "";
std::string str = "HACK_TAXI";
bool login = false;
bool server = false;
bool server1 = false;
bool loginn = true;
bool SaveUsers = true;
bool savekey = true;
bool loader_active = true;
D3DMATRIX Esp::ViewMatrix;
static bool Bot = true;
static bool Player = true;
std::string tim;
char str1[60] = "";
float overlaycolor = 0.0f;
bool unload = false;
int teamids;
//dfgs
ImVec4 linescolors;// = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 bonescolors = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 fullboxcolor;// = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 cornerboxcolor;// = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 whitecolr = { 1.0f,1.0f,1.0f,1.0f };

ImVec4 blinescolors;
ImVec4 bbonescolors;
ImVec4 bfullboxcolor;
ImVec4 bcornerboxcolor;
bool driving = true;
ImColor col;

static auto Flags2 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
static auto Flags21 = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
static auto Flags22 = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
namespace Settings
{
	static int Tab = 5;
}
bool watermark = true;
int currIndex;
float popcorn = 0.5f;
float popcorn2 = 0.450f;
ImVec4 colorr;
int Emu_Int = 0;
int item_current_Emu = 0;
int currentengine = 0;
int item_current_Aim = 0;
int skelesec = 0;
//  (DX11::pDevice, &logo, sizeof(logo), 462, 462, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &logggo);
ImVec4 to_vec4(float r, float g, float b, float a)
{
	return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
	

}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
std::string GetCurrentDirectory()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}
inline bool FileExist(const std::string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}
std::string readFromFile(const std::string& filename) {
	std::ifstream file(filename);
	std::string content;
	if (file.is_open()) {
		std::getline(file, content);
		file.close();
	}
	return content;
}

void Esp::LoadConfig(std::string Path) {
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	//	if (rc < 0) { std::cout << "File not found"; };
	if (FileExist(Path))
	{
		bool State = ini.GetBoolValue("Key", "UserKeyState");
		if (State == true)
		{
			std::string Key = ini.GetValue("Key", "UserKey");
			if (Key != "")
			{
				strcpy(str1, Key.c_str());
				SaveUsers = true;
			}

		}

	}
	/* if (ini.GetValue("Key", "UserKey")=="123")
	 {

	 }*/
}
float nam[] = { 1.000f, 1.000f, 0.000f, 1.000f };
bool testtt = true;
string hptext = "";
string Textt2 = "";
string Textt3 = "";
string Textt4 = "";
string Textt5 = "";
string Textt6 = "";
string hptext1 = "";
void WriteUE4Float(DWORD offset, float replace)
{
	//MM->init();
	DWORD ue4Header = Utility::ReadMemoryEx<int>(0xE0C36E8);
	DWORD oldprotect;
	VirtualProtectEx(Game::hProcess, (LPVOID)(ue4Header + offset), sizeof(float), PAGE_EXECUTE_READWRITE, &oldprotect);
	WriteProcessMemory(Game::hProcess, (LPVOID)(ue4Header + offset), &replace, sizeof(float), NULL);
	VirtualProtectEx(Game::hProcess, (LPVOID)(ue4Header + offset), sizeof(float), PAGE_READONLY, &oldprotect);
}
std::string ws2s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}

void WriteConfig(std::string Path, std::string Key, bool State) {
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) {
		//	std::cout << "File not found";
	};
	if (State == true)
	{
		ini.SetBoolValue("Key", "UserKeyState", true);
	}
	else
	{
		ini.SetBoolValue("Key", "UserKeyState", false);
	}
	ini.SetValue("Key", "UserKey", Key.c_str());

	ini.SaveFile(Path.c_str());
}

bool dirExists(const std::string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}


void WriteResToDisk(std::string PathFile, LPWSTR File_WITHARG)
{
	HRSRC myResource = ::FindResource(NULL, File_WITHARG, RT_RCDATA);
	unsigned int myResourceSize = ::SizeofResource(NULL, myResource);
	HGLOBAL myResourceData = ::LoadResource(NULL, myResource);
	void* pMyExecutable = ::LockResource(myResourceData);
	std::ofstream f(PathFile, std::ios::out | std::ios::binary);
	f.write((char*)pMyExecutable, myResourceSize);
	f.close();
}
static void HelpMarkerQuestionMark(const char* desc)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

std::string wideToMultiByte(std::wstring const& wideString)
{
	std::string ret;
	std::string buff(MB_CUR_MAX, '\0');

	for (wchar_t const& wc : wideString)
	{
		int mbCharLen = std::wctomb(&buff[0], wc);

		if (mbCharLen < 1) { break; }

		for (int i = 0; i < mbCharLen; ++i)
		{
			ret += buff[i];
		}
	}

	return ret;
}

bool ProcessInlineHexColor(const char* start, const char* end, ImVec4& color)
{
	const int hexCount = (int)(end - start);
	if (hexCount == 6 || hexCount == 8)
	{
		char hex[9];
		strncpy(hex, start, hexCount);
		hex[hexCount] = 0;

		unsigned int hexColor = 0;
		if (sscanf(hex, "%x", &hexColor) > 0)
		{
			color.x = static_cast<float>((hexColor & 0x00FF0000) >> 16) / 255.0f;
			color.y = static_cast<float>((hexColor & 0x0000FF00) >> 8) / 255.0f;
			color.z = static_cast<float>((hexColor & 0x000000FF)) / 255.0f;
			color.w = 1.0f;

			if (hexCount == 8)
			{
				color.w = static_cast<float>((hexColor & 0xFF000000) >> 24) / 255.0f;
			}

			return true;
		}
	}

	return false;
}

const char ColorMarkerStart = '{';
const char ColorMarkerEnd = '}';
#define IMGUI_DEFINE_MATH_OPERATORS // Access to math operators

#define V2 ImVec2
#define min(x,y) ((x)<(y)?x:y)
#define wh(a) ImColor(1.f,1.f,1.f,a)
#define F float


///////////
F k;
int i{};
F r() { return F(rand() / 32768.f) * 2.f - 1.f; };

void FXThunder(ImDrawList* d, ImVec2 a, ImVec2 b, ImVec2 sz, ImVec4 mouse, float t)
{
	static float fl;
	if ((rand() % 500) == 0) fl = t;
	if ((t - fl) > 0)
	{
		auto ft = 0.25f;
		d->AddRectFilled(a, b, wh((ft - (t - fl)) / ft));
	}

	for (int i = 0; i < 2000; ++i) {
		unsigned h = ImGui::GetID(d + i + int(t / 4));
		auto f = fmodf(t + fmodf(h / 777.f, 99), 99);
		auto tx = h % (int)sz.x;
		auto ty = h % (int)sz.y;
		if (f < 1) {
			auto py = ty - 1000 * (1 - f);
			d->AddLine({ a.x + tx, a.y + py }, { a.x + tx, a.y + min(py + 10,ty) }, (ImU32)-1);
		}
		else if (f < 1.2f)
			d->AddCircle({ a.x + tx, a.y + ty }, (f - 1) * 10 + h % 5, wh(1 - (f - 1) * 5.f));
	}
}
struct P {
	F x, y, z, a, b, c; void A() {
		x += a * k; y += b * k; z += c * k;
		F ng{ 0.008f }; z -= 5.f; F xp = x * cosf(ng) - z * sinf(ng); F zp = x * sinf(ng) + z * cosf(ng);
		x = xp; z = zp + 5.f; a -= x * k + r() * k; b -= y * k + r() * k; c -= (z - 5.0f) * k + r() * k;
	}
};
P p[64];
////////void FXLights(ImDrawList* d, V2 o, V2 b, V2 sz, ImVec4, F t)
////////{
////////	int j{};
////////	if (!i) { i = 1; for (P& a : p) { a = { r(),r(),r() + 5.f,r(),r(),r() }; } }
////////	for (P& a : p) {
////////		if (a.z < 0.001) continue;
////////		V2 s((a.x / a.z) * sz.x * 2.f + sz.x * 0.5f + o.x, (a.y / a.z) * sz.y * 2.f + sz.y * 0.5f + o.y);
////////		int x = (j++) % 16;
////////		k = cosf((j / 64.f) * 3.14592f) * 0.002f + 0.002f;
////////		F dist = fabsf(a.z - 5.f) / 2.5f, sc = (10.f + dist * 100.f) / a.z;
////////		int tr = int(ImMin(dist * 128.f, 128.f) + 127) << 24;
////////		ImColor col = ImColor::HSV(k * 9.f + 0.06f, 0.8f, 1.f, 1.f - sqrtf(dist));
////////		d->AddCircleFilled(s, sc, col, 12); a.A();
////////	}
////////}

////////void FXLights(ImDrawList* d, V2 o, V2 b, V2 sz, ImVec4, F t)
////////{
////////	int j{};
////////	if (!i) { i = 1; for (P& a : p) { a = { r(),r(),r() + 5.f,r(),r(),r() }; } }
////////	for (P& a : p) {
////////		if (a.z < 0.001) continue;
////////		V2 s((a.x / a.z) * sz.x * 2.f + sz.x * 0.5f + o.x, (a.y / a.z) * sz.y * 2.f + sz.y * 0.5f + o.y);
////////		int x = (j++) % 16;
////////		k = cosf((j / 64.f) * 3.14592f) * 0.002f + 0.002f;
////////		F dist = fabsf(a.z - 5.f) / 2.5f, sc = (10.f + dist * 100.f) / a.z;
////////		int tr = int(ImMin(dist * 128.f, 128.f) + 127) << 24;
////////
////////		// تغيير اللون إلى لون أحمر
////////		ImColor col = ImColor::HSV(0.0f, 0.8f, 1.f, 1.f - sqrtf(dist)); // قيمة Hue 0.0 تعني الأحمر
////////		d->AddCircleFilled(s, sc, col, 12); a.A();
////////	}
////////}


void FXLights(ImDrawList* d, V2 o, V2 b, V2 sz, ImVec4, F t)
{
	int j{};
	if (!i) { i = 1; for (P& a : p) { a = { r(),r(),r() + 5.f,r(),r(),r() }; } }
	for (P& a : p) {
		if (a.z < 0.001) continue;
		V2 s((a.x / a.z) * sz.x * 2.f + sz.x * 0.5f + o.x, (a.y / a.z) * sz.y * 2.f + sz.y * 0.5f + o.y);
		int x = (j++) % 16;
		k = cosf((j / 64.f) * 3.14592f) * 0.002f + 0.002f;
		F dist = fabsf(a.z - 5.f) / 2.5f, sc = (10.f + dist * 100.f) / a.z;

		// زيادة الحجم بنسبة 1%
		sc *= 1.22f;  // زيادة الحجم بنسبة 1%

		int tr = int(ImMin(dist * 128.f, 128.f) + 127) << 24;

		// تغيير اللون إلى لون أحمر
		ImColor col = ImColor::HSV(0.0f, 0.8f, 1.f, 1.f - sqrtf(dist)); // قيمة Hue 0.0 تعني الأحمر
		d->AddCircleFilled(s, sc, col, 12); a.A();
	}
}



void FXOrangeBlinds(ImDrawList* d, V2 a, V2 b, V2 s, ImVec4 m, float t)
{
	int N = 25;
	float sp = s.y / N, y, st = sin(t) * 0.5 + 0.5,
		r[3] = { 1500, 1087 + 200 * st, 1650 },
		ctr[3][2] = { { 150, 140 }, { s.x * m.x, s.y * m.y },
			{ 40 + 200 * st, 73 + 20 * sin(st * 5) } };
	for (int i = 0; i < N; i++) {
		y = a.y + sp * (i + .5);
		for (int x = a.x; x <= b.x; x += 2) {
			float D = 0, o = 255;
			for (int k = 0; k < 3; k++)
				D += r[k] / (pow(x - a.x - ctr[k][0], 2) + pow(y - a.y - ctr[k][1], 2));
			if (D < 1) continue;
			if (D > 2.5) D = 2.5;
			if (D < 1.15) o /= 2;
			d->AddLine(V2(x, y), V2(x + 2, y), IM_COL32(239, 129, 19, o), D + sin(2.3 * t + 0.3 * i));
		}
	}
}
void FXSquares(ImDrawList* d, V2 a, V2 b, V2 sz, ImVec4, float t0)
{
	for (float t = t0; t < t0 + 1.0f; t += 1.0f / 100.0f)
	{
		V2 cp0(a.x, b.y);
		V2 cp1(b);
		float ts = t - t0;
		cp0.x += (0.4f + sin(t) * 0.3f) * sz.x;
		cp0.y -= (0.5f + cos(ts * ts) * 0.4f) * sz.y;
		cp1.x -= (0.4f + cos(t) * 0.4f) * sz.x;
		cp1.y -= (0.5f + sin(ts * t) * 0.3f) * sz.y;
		d->AddBezierCurve(V2(a.x, b.y), cp0, cp1, b, IM_COL32(100 + ts * 150, 255 - ts * 150, 60, ts * 200), 5.0f);
	}
}
#define IM_COL32(R,G,B,A)    (((ImU32)(A)<<IM_COL32_A_SHIFT) | ((ImU32)(B)<<IM_COL32_B_SHIFT) | ((ImU32)(G)<<IM_COL32_G_SHIFT) | ((ImU32)(R)<<IM_COL32_R_SHIFT))

void BackgroundThemes()
{
	//window size is now OK
	ImGuiIO& io = ImGui::GetIO();
	ImGui::Begin("FX", NULL, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoMouseInputs);//Now we need to make a rectangle inside this menu;
	//ImVec2 size(320.0f, 180.0f);
	ImVec2 size(DX11Window::Width, DX11Window::Height);
	ImGui::InvisibleButton("canvas", size);//this is invisible thing on which the effects are drawn.

	ImVec2 p0 = ImGui::GetItemRectMin();
	ImVec2 p1 = ImGui::GetItemRectMax();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	draw_list->PushClipRect(ImVec2(p0.x - 80, p0.y - 110), p1);
	//77,77 difference
	ImVec4 mouse_data;
	mouse_data.x = (io.MousePos.x - p0.x) / size.x;
	mouse_data.y = (io.MousePos.y - p0.y) / size.y;
	mouse_data.z = io.MouseDownDuration[0];
	mouse_data.w = io.MouseDownDuration[1];


	//draw_list->AddRectFilled(p0, p1, ImU32(0));//rectangle is drawn inside, now we need to remove the debug window
	draw_list->AddRectFilled(ImVec2(p0.x - 80, p0.y - 110), p1, IM_COL32(0, 0, 0, Setting::BackgroundTransparency));//rectangle is drawn inside, now we need to remove the debug window
	////switch (Setting::SelectedTheme)
	////{
	////case 0:
	////	FXThunder(draw_list, p0, p1, size, mouse_data, (float)ImGui::GetTime());
	////	break;
	////case 1:
	////	FXLights(draw_list, p0, p1, size, mouse_data, (float)ImGui::GetTime());
	////	break;
	////case 2:
	////	FXOrangeBlinds(draw_list, p0, p1, size, mouse_data, (float)ImGui::GetTime());
	////	break;
	////case 3:
	////	FXSquares(draw_list, p0, p1, size, mouse_data, (float)ImGui::GetTime());
	////	break;
	////default:
	////	FXThunder(draw_list, p0, p1, size, mouse_data, (float)ImGui::GetTime());

	////	//FXCircles(draw_list, p0, p1, size, mouse_data, (float)ImGui::GetTime());//not pleasing, remove is better
	////}
	FXLights(draw_list, p0, p1, size, mouse_data, (float)ImGui::GetTime());

	draw_list->PopClipRect();
	ImGui::End();

}


void TextWithColors(const char* fmt, ...)
{
	char tempStr[4096];

	va_list argPtr;
	va_start(argPtr, fmt);
	_vsnprintf(tempStr, sizeof(tempStr), fmt, argPtr);
	va_end(argPtr);
	tempStr[sizeof(tempStr) - 1] = '\0';

	bool pushedColorStyle = false;
	const char* textStart = tempStr;
	const char* textCur = tempStr;
	while (textCur < (tempStr + sizeof(tempStr)) && *textCur != '\0')
	{
		if (*textCur == ColorMarkerStart)
		{
			// Print accumulated text
			if (textCur != textStart)
			{
				ImGui::TextUnformatted(textStart, textCur);
				ImGui::SameLine(0.0f, 0.0f);
			}

			// Process color code
			const char* colorStart = textCur + 1;
			do
			{
				++textCur;
			} while (*textCur != '\0' && *textCur != ColorMarkerEnd);

			// Change color
			if (pushedColorStyle)
			{
				ImGui::PopStyleColor();
				pushedColorStyle = false;
			}

			ImVec4 textColor;
			if (ProcessInlineHexColor(colorStart, textCur, textColor))
			{
				ImGui::PushStyleColor(ImGuiCol_Text, textColor);
				pushedColorStyle = true;
			}

			textStart = textCur + 1;
		}
		else if (*textCur == '\n')
		{
			// Print accumulated text an go to next line
			ImGui::TextUnformatted(textStart, textCur);
			textStart = textCur + 1;
		}

		++textCur;
	}

	if (textCur != textStart)
	{
		ImGui::TextUnformatted(textStart, textCur);
	}
	else
	{
		ImGui::NewLine();
	}

	if (pushedColorStyle)
	{
		ImGui::PopStyleColor();
	}
}
int ipadView = 360; // متغير شريط السحب
bool showSlider = false; // حالة عرض شريط السحب

#include "Discord.h"
Discord* g_Discord;
void WriteConfigurate(std::string Path)
{
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) { std::cout << "File not found"; }

	// Writing selected settings to INI file
	ini.SetBoolValue("ESP", "pname", Setting::pname);
	ini.SetBoolValue("ESP", "playerBone", Setting::playerBone);
	ini.SetBoolValue("ESP", "pline", Setting::pline);
	ini.SetBoolValue("ESP", "pcorner", Setting::pcorner);
	ini.SetBoolValue("ESP", "Vehicle", Setting::Vehicle);
	ini.SetBoolValue("ESP", "Flags", Setting::pflag);
	ini.SetBoolValue("ESP", "TotalEnemy", Setting::TotalEnemy);


	ini.SetBoolValue("ESP", "radar", Setting::radar);
	ini.SetBoolValue("ESP", "gameinfo", Setting::gameinfo);
	ini.SetBoolValue("ESP", "Distancee", Setting::plyrdistance);
	ini.SetBoolValue("ESP", "phealth", Setting::phealth);
	ini.SetBoolValue("ESP", "playerweapon", Setting::playerweapon);
	ini.SetLongValue("ESP", "dotsize", Setting::dotsize);

	ini.SetBoolValue("Items", "Esp_Item_M416", Setting::Esp_Item_M416);
	ini.SetBoolValue("Items", "Esp_Item_AKM", Setting::Esp_Item_AKM);
	ini.SetBoolValue("Items", "Esp_Item_SCARL", Setting::Esp_Item_SCARL);
	ini.SetBoolValue("Items", "Esp_Item_FAMAS", Setting::Esp_Item_FAMAS);
	ini.SetBoolValue("Items", "Esp_Item_M762", Setting::Esp_Item_M762);
	ini.SetBoolValue("Items", "Esp_Item_Mk14", Setting::Esp_Item_Mk14);
	ini.SetBoolValue("Items", "Esp_Item_DP28", Setting::Esp_Item_DP28);
	ini.SetBoolValue("Items", "Esp_Item_Awm", Setting::Esp_Item_Awm);
	ini.SetBoolValue("Items", "Esp_Item_SniperAMR", Setting::Esp_Item_SniperAMR);
	ini.SetBoolValue("Items", "Esp_Item_BulletAMR", Setting::Esp_Item_BulletAMR);
	ini.SetBoolValue("Items", "Esp_Item_M24", Setting::Esp_Item_M24);
	ini.SetBoolValue("Items", "Esp_Item_Kar98k", Setting::Esp_Item_Kar98k);
	ini.SetBoolValue("Items", "Esp_Item_FlareGun", Setting::Esp_Item_FlareGun);
	ini.SetBoolValue("Items", "Esp_Item_Flare", Setting::Esp_Item_Flare);
	ini.SetBoolValue("Items", "airdrop", Setting::airdrop);
	ini.SetBoolValue("Items", "Esp_Item_Armor3", Setting::Esp_Item_Armor3);
	ini.SetBoolValue("Items", "Esp_Item_Bag3", Setting::Esp_Item_Bag3);
	ini.SetBoolValue("Items", "Esp_Item_Helmet3", Setting::Esp_Item_Helmet3);
	ini.SetBoolValue("Items", "Esp_Item_Awmimo", Setting::Esp_Item_Awmimo);
	ini.SetBoolValue("Items", "deadbox", Setting::deadbox);
	ini.SetBoolValue("Items", "playerdeadbox", Setting::playerdeadbox);
	ini.SetBoolValue("Items", "airdropitem", Setting::airdropitem);
	ini.SetBoolValue("Items", "Esp_Item_exquic", Setting::Esp_Item_exquic);
	ini.SetBoolValue("Items", "Esp_Item_Helmet1", Setting::Esp_Item_Helmet1);
	ini.SetBoolValue("Items", "Esp_Item_Helmet2", Setting::Esp_Item_Helmet2);
	ini.SetBoolValue("Items", "Esp_Item_Bag1", Setting::Esp_Item_Bag1);
	ini.SetBoolValue("Items", "Esp_Item_Bag2", Setting::Esp_Item_Bag2);
	ini.SetBoolValue("Items", "Esp_Item_Armor1", Setting::Esp_Item_Armor1);
	ini.SetBoolValue("Items", "Esp_Item_Armor2", Setting::Esp_Item_Armor2);
	ini.SetBoolValue("Items", "Esp_Item_G36C", Setting::Esp_Item_G36C);
	ini.SetBoolValue("Items", "Esp_Item_QBZ", Setting::Esp_Item_QBZ);
	ini.SetBoolValue("Items", "Esp_Item_QBU", Setting::Esp_Item_QBU);
	ini.SetBoolValue("Items", "Esp_Item_SLR", Setting::Esp_Item_SLR);
	ini.SetBoolValue("Items", "Esp_Item_SKS", Setting::Esp_Item_SKS);
	ini.SetBoolValue("Items", "Esp_Item_Mini14", Setting::Esp_Item_Mini14);
	ini.SetBoolValue("Items", "Esp_Item_PP19", Setting::Esp_Item_PP19);
	ini.SetBoolValue("Items", "Esp_Item_TommyGun", Setting::Esp_Item_TommyGun);
	ini.SetBoolValue("Items", "Esp_Item_MP5K", Setting::Esp_Item_MP5K);
	ini.SetBoolValue("Items", "Esp_Item_UMP9", Setting::Esp_Item_UMP9);
	ini.SetBoolValue("Items", "Esp_Item_Vector", Setting::Esp_Item_Vector);
	ini.SetBoolValue("Items", "Esp_Item_Uzi", Setting::Esp_Item_Uzi);
	ini.SetBoolValue("Items", "Esp_Item_762mm", Setting::Esp_Item_762mm);
	ini.SetBoolValue("Items", "Esp_Item_556mm", Setting::Esp_Item_556mm);
	ini.SetBoolValue("Items", "Esp_Item_9mm", Setting::Esp_Item_9mm);
	ini.SetBoolValue("Items", "Esp_Item_45ACP", Setting::Esp_Item_45ACP);
	ini.SetBoolValue("Items", "Esp_Item_Holo", Setting::Esp_Item_Holo);
	ini.SetBoolValue("Items", "Esp_Item_Mk47Mutant", Setting::Esp_Item_Mk47Mutant);
	ini.SetBoolValue("Items", "Esp_Item_Frag", Setting::Esp_Item_Frag);
	ini.SetBoolValue("Items", "Esp_Item_Smoke", Setting::Esp_Item_Smoke);
	ini.SetBoolValue("Items", "Esp_Item_Molotof", Setting::Esp_Item_Molotof);
	ini.SetBoolValue("Items", "Esp_Item_MedKit", Setting::Esp_Item_MedKit);
	ini.SetBoolValue("Items", "Esp_Item_FirstAidKit", Setting::Esp_Item_FirstAidKit);
	ini.SetBoolValue("Items", "Esp_Item_Bandage", Setting::Esp_Item_Bandage);
	ini.SetBoolValue("Items", "Esp_Item_Painkiller", Setting::Esp_Item_Painkiller);
	ini.SetBoolValue("Items", "Esp_Item_EnergyDrink", Setting::Esp_Item_EnergyDrink);
	ini.SetBoolValue("Items", "Esp_Item_AdrenalineSyringe", Setting::Esp_Item_AdrenalineSyringe);

	ini.SetDoubleValue("Memory", "fovcircleredus", static_cast<double>(Setting::fovcircleredus));
	ini.SetLongValue("Misc", "magicrange", Setting::magicrange);
	ini.SetLongValue("Memory", "ipad123", ipadView);
	ini.SetLongValue("Memory", "ipadv1", showSlider);

	//ini.SetFloatValue("Memory", "fovcircleredus", Setting::fovcircleredus);

	ini.SetBoolValue("Memory", "MagicBulletticked", Setting::MagicBulletticked);
	ini.SetBoolValue("Memory", "MagicRangeCheck", Setting::MagicRangeCheck);
	ini.SetBoolValue("Memory", "SkipBots", Setting::SkipBots);
	ini.SetBoolValue("Memory", "SkipKnocked", Setting::SkipKnocked);
	ini.SetBoolValue("Memory", "fovcircle", Setting::fovcircle);
	ini.SetBoolValue("Memory", "aimbotposition", Setting::aimbotposition);
	ini.SetBoolValue("Memory", "XXXX", Setting::XXXX);
	ini.SetBoolValue("Memory", "smalll", Setting::smalll);
	ini.SetBoolValue("Memory", "ShowDaamge", Setting::ShowDaamge);

	ini.SaveFile(Path.c_str());
}



void LoadConfiggg(std::string Path)
{
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) { std::cout << "File not found"; return; }

	try
	{
		showSlider = ini.GetBoolValue("Memory", "ipadv1");
		ipadView = ini.GetLongValue("Memory", "ipad123");
		//ini.SetLongValue("Memory", "ipad123", ipadView);
		Setting::magicrange = ini.GetLongValue("Misc", "magicrange");
		Setting::fovcircleredus = static_cast<float>(ini.GetDoubleValue("Memory", "fovcircleredus", 30.0));
		// Loading selected settings from INI file
		Setting::pname = ini.GetBoolValue("ESP", "pname");
		Setting::playerBone = ini.GetBoolValue("ESP", "playerBone");
		Setting::pline = ini.GetBoolValue("ESP", "pline");
		Setting::pcorner = ini.GetBoolValue("ESP", "pcorner");
		Setting::Vehicle = ini.GetBoolValue("ESP", "Vehicle");
		Setting::pflag = ini.GetBoolValue("ESP", "Flags");
		Setting::TotalEnemy = ini.GetBoolValue("ESP", "TotalEnemy");
		Setting::dots = ini.GetBoolValue("ESP", "dots");
		Setting::radar = ini.GetBoolValue("ESP", "radar");
		Setting::gameinfo = ini.GetBoolValue("ESP", "gameinfo");
		Setting::plyrdistance = ini.GetBoolValue("ESP", "Distancee");
		Setting::phealth = ini.GetBoolValue("ESP", "phealth");
		Setting::playerweapon = ini.GetBoolValue("ESP", "playerweapon");
		Setting::dotsize = ini.GetLongValue("ESP", "dotsize");

		Setting::Esp_Item_M416 = ini.GetBoolValue("Items", "Esp_Item_M416");
		Setting::Esp_Item_AKM = ini.GetBoolValue("Items", "Esp_Item_AKM");
		Setting::Esp_Item_SCARL = ini.GetBoolValue("Items", "Esp_Item_SCARL");
		Setting::Esp_Item_FAMAS = ini.GetBoolValue("Items", "Esp_Item_FAMAS");
		Setting::Esp_Item_M762 = ini.GetBoolValue("Items", "Esp_Item_M762");
		Setting::Esp_Item_Mk14 = ini.GetBoolValue("Items", "Esp_Item_Mk14");
		Setting::Esp_Item_DP28 = ini.GetBoolValue("Items", "Esp_Item_DP28");
		Setting::Esp_Item_Awm = ini.GetBoolValue("Items", "Esp_Item_Awm");
		Setting::Esp_Item_SniperAMR = ini.GetBoolValue("Items", "Esp_Item_SniperAMR");
		Setting::Esp_Item_BulletAMR = ini.GetBoolValue("Items", "Esp_Item_BulletAMR");
		Setting::Esp_Item_M24 = ini.GetBoolValue("Items", "Esp_Item_M24");
		Setting::Esp_Item_Kar98k = ini.GetBoolValue("Items", "Esp_Item_Kar98k");
		Setting::Esp_Item_FlareGun = ini.GetBoolValue("Items", "Esp_Item_FlareGun");
		Setting::Esp_Item_Flare = ini.GetBoolValue("Items", "Esp_Item_Flare");
		Setting::airdrop = ini.GetBoolValue("Items", "airdrop");
		Setting::Esp_Item_Armor3 = ini.GetBoolValue("Items", "Esp_Item_Armor3");
		Setting::Esp_Item_Bag3 = ini.GetBoolValue("Items", "Esp_Item_Bag3");
		Setting::Esp_Item_Helmet3 = ini.GetBoolValue("Items", "Esp_Item_Helmet3");
		Setting::Esp_Item_Awmimo = ini.GetBoolValue("Items", "Esp_Item_Awmimo");
		Setting::deadbox = ini.GetBoolValue("Items", "deadbox");
		Setting::playerdeadbox = ini.GetBoolValue("Items", "playerdeadbox");
		Setting::airdropitem = ini.GetBoolValue("Items", "airdropitem");
		Setting::Esp_Item_exquic = ini.GetBoolValue("Items", "Esp_Item_exquic");
		Setting::Esp_Item_Helmet1 = ini.GetBoolValue("Items", "Esp_Item_Helmet1");
		Setting::Esp_Item_Helmet2 = ini.GetBoolValue("Items", "Esp_Item_Helmet2");
		Setting::Esp_Item_Bag1 = ini.GetBoolValue("Items", "Esp_Item_Bag1");
		Setting::Esp_Item_Bag2 = ini.GetBoolValue("Items", "Esp_Item_Bag2");
		Setting::Esp_Item_Armor1 = ini.GetBoolValue("Items", "Esp_Item_Armor1");
		Setting::Esp_Item_Armor2 = ini.GetBoolValue("Items", "Esp_Item_Armor2");
		Setting::Esp_Item_G36C = ini.GetBoolValue("Items", "Esp_Item_G36C");
		Setting::Esp_Item_QBZ = ini.GetBoolValue("Items", "Esp_Item_QBZ");
		Setting::Esp_Item_QBU = ini.GetBoolValue("Items", "Esp_Item_QBU");
		Setting::Esp_Item_SLR = ini.GetBoolValue("Items", "Esp_Item_SLR");
		Setting::Esp_Item_SKS = ini.GetBoolValue("Items", "Esp_Item_SKS");
		Setting::Esp_Item_Mini14 = ini.GetBoolValue("Items", "Esp_Item_Mini14");
		Setting::Esp_Item_PP19 = ini.GetBoolValue("Items", "Esp_Item_PP19");
		Setting::Esp_Item_TommyGun = ini.GetBoolValue("Items", "Esp_Item_TommyGun");
		Setting::Esp_Item_MP5K = ini.GetBoolValue("Items", "Esp_Item_MP5K");
		Setting::Esp_Item_UMP9 = ini.GetBoolValue("Items", "Esp_Item_UMP9");
		Setting::Esp_Item_Vector = ini.GetBoolValue("Items", "Esp_Item_Vector");
		Setting::Esp_Item_Uzi = ini.GetBoolValue("Items", "Esp_Item_Uzi");
		Setting::Esp_Item_762mm = ini.GetBoolValue("Items", "Esp_Item_762mm");
		Setting::Esp_Item_556mm = ini.GetBoolValue("Items", "Esp_Item_556mm");
		Setting::Esp_Item_9mm = ini.GetBoolValue("Items", "Esp_Item_9mm");
		Setting::Esp_Item_45ACP = ini.GetBoolValue("Items", "Esp_Item_45ACP");
		Setting::Esp_Item_Holo = ini.GetBoolValue("Items", "Esp_Item_Holo");
		Setting::Esp_Item_Mk47Mutant = ini.GetBoolValue("Items", "Esp_Item_Mk47Mutant");
		Setting::Esp_Item_Frag = ini.GetBoolValue("Items", "Esp_Item_Frag");
		Setting::Esp_Item_Smoke = ini.GetBoolValue("Items", "Esp_Item_Smoke");
		Setting::Esp_Item_Molotof = ini.GetBoolValue("Items", "Esp_Item_Molotof");
		Setting::Esp_Item_MedKit = ini.GetBoolValue("Items", "Esp_Item_MedKit");
		Setting::Esp_Item_FirstAidKit = ini.GetBoolValue("Items", "Esp_Item_FirstAidKit");
		Setting::Esp_Item_Bandage = ini.GetBoolValue("Items", "Esp_Item_Bandage");
		Setting::Esp_Item_Painkiller = ini.GetBoolValue("Items", "Esp_Item_Painkiller");
		Setting::Esp_Item_EnergyDrink = ini.GetBoolValue("Items", "Esp_Item_EnergyDrink");
		Setting::Esp_Item_AdrenalineSyringe = ini.GetBoolValue("Items", "Esp_Item_AdrenalineSyringe");

		Setting::MagicBulletticked = ini.GetBoolValue("Memory", "MagicBulletticked");
		Setting::MagicRangeCheck = ini.GetBoolValue("Memory", "MagicRangeCheck");
		Setting::SkipBots = ini.GetBoolValue("Memory", "SkipBots");
		Setting::SkipKnocked = ini.GetBoolValue("Memory", "SkipKnocked");
		Setting::fovcircle = ini.GetBoolValue("Memory", "fovcircle");
		Setting::aimbotposition = ini.GetBoolValue("Memory", "aimbotposition");
		Setting::XXXX = ini.GetBoolValue("Memory", "XXXX");
		Setting::smalll = ini.GetBoolValue("Memory", "smalll");
		Setting::ShowDaamge = ini.GetBoolValue("Memory", "ShowDaamge");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error loading configuration: " << e.what() << std::endl;
	}
}



void NationFlag(VECTOR3 Screen, AActor& AActor, int PosX, int PosY, int X, int Y)
{

	if (AActor.Nation == "JM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::JMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "G1")
	{
		DX11::ImGui_DX11::DrawImage(DX11::G1FLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ALFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ASFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ADFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ARFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ATFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BB")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BBFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CX")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CXFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::COFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "EC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ECFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "EG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::EGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ER")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ERFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "EE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::EEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ET")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ETFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "DE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::DEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "HU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::HUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "JP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::JPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "JE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::JEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "JO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::JOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LB")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LBFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ML")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "YT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::YTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MX")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MXFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "FM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::FMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ME")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MP")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NPFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "NO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::NOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "OM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::OMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "QA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::QAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ROFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::RUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::RWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::REFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "BL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::BLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "KN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::KNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "MF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::MFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "PM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::PMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "WS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::WSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ST")
	{
		DX11::ImGui_DX11::DrawImage(DX11::STFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "RS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::RSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SX")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SXFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SB")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SBFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ZA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ZAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SSFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ES")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ESFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "LK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::LKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SD")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "CH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::CHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "SY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::SYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TJ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TJFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::THFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TLFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TK")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TKFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TO")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TOFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TTFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TC")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TCFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "TV")
	{
		DX11::ImGui_DX11::DrawImage(DX11::TVFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "UG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::UGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "UA")
	{
		DX11::ImGui_DX11::DrawImage(DX11::UAFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "GB")
	{
		DX11::ImGui_DX11::DrawImage(DX11::GBFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "US")
	{
		DX11::ImGui_DX11::DrawImage(DX11::USFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "UY")
	{
		DX11::ImGui_DX11::DrawImage(DX11::UYFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "UZ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::UZFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VU")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VUFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VNFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VG")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VGFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "VI")
	{
		DX11::ImGui_DX11::DrawImage(DX11::VIFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "WF")
	{
		DX11::ImGui_DX11::DrawImage(DX11::WFFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "EH")
	{
		DX11::ImGui_DX11::DrawImage(DX11::EHFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "YE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::YEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ZM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ZMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ZW")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ZWFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "AX")
	{
		DX11::ImGui_DX11::DrawImage(DX11::AXFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IS")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ISFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IN")
	{
		DX11::ImGui_DX11::DrawImage(DX11::INFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "ID")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IDFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IR")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IRFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IQ")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IQFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IE")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IEFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IM")
	{
		DX11::ImGui_DX11::DrawImage(DX11::IMFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IL")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ILFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
	if (AActor.Nation == "IT")
	{
		DX11::ImGui_DX11::DrawImage(DX11::ITFLAG, Screen.X - PosX, Screen.Y - PosY, X, Y);
	}
}

///Settings
int nsize = 14;
static int skelee = 0;
static int xsuit = 0;
static int back1 = 0;
static int helmet1 = 0;
static int hoho = 0;
static int glidersk = 0;
static int Parachuteskin = 0;
static int m41622 = 0;
static int daciaskin = 0;
static int akm22 = 0;
static int UAZSK = 0;
static int copu33 = 0;
static int scal_1 = 0;
static int m7777 = 0;
static int AUGSKIN = 0;


static int AMRSKIN = 0;
static int HoneySKIN = 0;
static int MG3SKIN = 0;
static int MK14SKIN = 0;
static int MINI14SKIN = 0;
static int M16A4SKIN = 0;
static int P90SKIN = 0;



static int GROZASKIN = 0;
static int ACE32SKIN = 0;
static int AWMS = 0;
static int UMPSKIN = 0;
static int VectorF = 0;
static int UZISKIN = 0;
static int panskin = 0;
//static int xsuit = 0;
static int linne = 0;
static int hpbt = 0;
static int boxe = 0;
static int lage = 0;
static int aimbp = 0;
int dissize = 14;
int hp = 14;
int vehisize = 15;
bool marco1 = false;
bool nothingm = true;
bool nothinga = false;




void RotateTriangle(std::array<VECTOR3, 3>& points, float rotation)
{
	const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
	for (auto& point : points)
	{
		point = point - points_center;

		const auto temp_x = point.X;
		const auto temp_y = point.Y;

		const auto theta = DEG2RAD(rotation);
		const auto c = cosf(theta);
		const auto s = sinf(theta);

		point.X = temp_x * c - temp_y * s;
		point.Y = temp_x * s + temp_y * c;

		point = point + points_center;
	}
}
///by omar
bool showkey = false;

///by omar

LinearColor RandomColor(float Rate) {

	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;

	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	}
	else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	}
	else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	}
	else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	}
	else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	}
	else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}

	x += Rate; //increase this value to switch colors faster
	if (x >= 255.0f)
		x = 0.0f;

	y += Rate; //increase this value to switch colors faster
	if (y > 1530.0f)
		y = 0.0f;


	return { (float)r, (float)g, (float)b, 255 };
}
enum Language {
	English,
	Arabic
};

enum Graphics {
	Smooth,
	Balanced,
	HD,
	HDR,
	UltraHD
};

enum Loot {
	Txt,
	Images
};

auto MainPointer = 1;

bool checkaiming = false;
LONG GetStringRegKey(HKEY hKey, const std::wstring& strValueName, std::wstring& strValue, const std::wstring& strDefaultValue)
{
	strValue = strDefaultValue;
	WCHAR szBuffer[512];
	DWORD dwBufferSize = sizeof(szBuffer);
	ULONG nError;
	nError = RegQueryValueExW(hKey, strValueName.c_str(), 0, NULL, (LPBYTE)szBuffer, &dwBufferSize);
	if (ERROR_SUCCESS == nError)
	{
		strValue = szBuffer;
	}
	return nError;
}
std::string GetAOWPath()
{
	HKEY hKey;
	LONG lRes = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Tencent\\MobileGamePC", 0, KEY_READ, &hKey);
	bool bExistsAndSuccess(lRes == ERROR_SUCCESS);
	bool bDoesNotExistsSpecifically(lRes == ERROR_FILE_NOT_FOUND);
	std::wstring strValueOfBinDir;
	GetStringRegKey(hKey, L"sf", strValueOfBinDir, L"bad");
	std::string returnday(strValueOfBinDir.begin(), strValueOfBinDir.end());;
	return returnday;
}

//void writeFile(const std::string& filePath, const std::string& content, int lineNumber) {
//	// قراءة محتوى الملف الحالي
//	std::ifstream inputFile(filePath);
//	if (!inputFile.is_open()) {
//		std::cerr << "Unable to open file for reading: " << filePath << std::endl;
//		return;
//	}
//
//	std::vector<std::string> lines;
//	std::string line;
//	while (getline(inputFile, line)) {
//		lines.push_back(line);
//	}
//	inputFile.close();
//
//	// تعديل السطر المحدد (إذا كان السطر موجودا)
//	if (lineNumber > 0 && lineNumber <= lines.size()) {
//		lines[lineNumber - 1] = content;
//	}
//	else {
//		std::cerr << "Line number out of range: " << lineNumber << std::endl;
//		return;
//	}
//
//	// كتابة المحتوى المعدل إلى الملف
//	std::ofstream outputFile(filePath);
//	if (outputFile.is_open()) {
//		for (const auto& l : lines) {
//			outputFile << l << "\n";
//		}
//		outputFile.close();
//	}
//	else {
//		std::cerr << "Unable to open file for writing: " << filePath << std::endl;
//	}
//}
//void writeFile(const std::string& filePath, const std::string& content, int lineNumber) {
//	// فتح الملف للقراءة والكتابة
//	std::fstream file(filePath, std::ios::in | std::ios::out);
//	if (!file.is_open()) {
//		std::cerr << "Unable to open file: " << filePath << std::endl;
//		return;
//	}
//
//	// الانتقال إلى السطر المحدد
//	std::string line;
//	int currentLine = 1;
//	while (std::getline(file, line)) {
//		if (currentLine == lineNumber) {
//			// الانتقال إلى بداية السطر المحدد
//			file.seekp(file.tellg());
//			file << content << std::endl;
//			return;
//		}
//		currentLine++;
//	}
//
//	// إذا كان رقم السطر خارج النطاق
//	std::cerr << "Line number out of range: " << lineNumber << std::endl;
//}

//void writeFile(const std::string& filePath, const std::string& content, int lineNumber) {
//	// فتح الملف للقراءة والكتابة
//	std::fstream file(filePath, std::ios::in | std::ios::out);
//	if (!file.is_open()) {
//		std::cerr << "Unable to open file: " << filePath << std::endl;
//		return;
//	}
//
//	// الانتقال إلى السطر المحدد
//	std::string line;
//	int currentLine = 1;
//	while (std::getline(file, line) && currentLine < lineNumber) {
//		currentLine++;
//	}
//
//	if (currentLine == lineNumber) {
//		file.seekp(file.tellg());
//		file << content << std::endl;
//	}
//	else {
//		std::cerr << "Line number out of range: " << lineNumber << std::endl;
//	}
//}
//////////////////////////////////////////////////////void writeFile(const std::string& filePath, const std::string& newText, int lineNumber) {
//////////////////////////////////////////////////////	std::fstream file(filePath, std::ios::in | std::ios::out);
//////////////////////////////////////////////////////	if (!file.is_open()) {
//////////////////////////////////////////////////////		std::cerr << "Unable to open file: " << filePath << std::endl;
//////////////////////////////////////////////////////		return;
//////////////////////////////////////////////////////	}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////	std::string line;
//////////////////////////////////////////////////////	int currentLine = 1;
//////////////////////////////////////////////////////	std::streampos lineStartPos = file.tellg();
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////	// البحث عن السطر المطلوب
//////////////////////////////////////////////////////	while (std::getline(file, line)) {
//////////////////////////////////////////////////////		if (currentLine == lineNumber) {
//////////////////////////////////////////////////////			break;
//////////////////////////////////////////////////////		}
//////////////////////////////////////////////////////		lineStartPos = file.tellg();
//////////////////////////////////////////////////////		currentLine++;
//////////////////////////////////////////////////////	}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////	if (currentLine == lineNumber) {
//////////////////////////////////////////////////////		// تعويض السطر الجديد إذا كان طوله أقل من السطر الأصلي
//////////////////////////////////////////////////////		if (newText.size() < line.size()) {
//////////////////////////////////////////////////////			file.seekp(lineStartPos);
//////////////////////////////////////////////////////			file << newText;
//////////////////////////////////////////////////////			file << std::string(line.size() - newText.size(), ' ');
//////////////////////////////////////////////////////		}
//////////////////////////////////////////////////////		else {
//////////////////////////////////////////////////////			// السطر الجديد يطابق أو يتجاوز السطر الأصلي
//////////////////////////////////////////////////////			file.seekp(lineStartPos);
//////////////////////////////////////////////////////			file << newText;
//////////////////////////////////////////////////////		}
//////////////////////////////////////////////////////	}
//////////////////////////////////////////////////////	else {
//////////////////////////////////////////////////////		std::cerr << "Line number out of range: " << lineNumber << std::endl;
//////////////////////////////////////////////////////	}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////	file.close();
//////////////////////////////////////////////////////}
//void writeFile(const std::string& filePath, const std::string& content, int lineNumber) {
//	std::ifstream inputFile(filePath);
//	if (!inputFile) {
//		std::cerr << "Unable to open file for reading: " << filePath << std::endl;
//		return;
//	}
//
//	std::vector<std::string> lines;
//	std::string line;
//	while (std::getline(inputFile, line)) {
//		lines.push_back(line);
//	}
//	inputFile.close();
//
//	if (lineNumber > 0 && lineNumber <= lines.size()) {
//		lines[lineNumber - 1] = content;
//	}
//	else {
//		std::cerr << "Line number out of range: " << lineNumber << std::endl;
//		return;
//	}
//
//	std::ofstream outputFile(filePath);
//	if (!outputFile) {
//		std::cerr << "Unable to open file for writing: " << filePath << std::endl;
//		return;
//	}
//
//	for (const auto& l : lines) {
//		outputFile << l << std::endl;
//	}
//	outputFile.close();
//}
//void writeFile(const std::string& filePath, const std::string& content, int lineNumber) {
//	std::fstream file(filePath, std::ios::in | std::ios::out);
//	if (!file) {
//		std::cerr << "Unable to open file: " << filePath << std::endl;
//		return;
//	}
//
//	std::string line;
//	int currentLine;
//	std::streampos position;
//
//	// قراءة الأسطر حتى السطر المطلوب
//	while (std::getline(file, line)) 
//	{
//		//if (currentLine == lineNumber) {
//		//	position = file.tellg();  // حفظ الموضع الحالي بعد قراءة السطر
//		//	file.clear();            // مسح أي أخطاء
//		//	file.seekp(position - std::streamoff(line.length() + 1));  // العودة إلى بداية السطر
//		//	file << content << std::endl;
//		//	return;
//		//}
//		currentLine++;
//	}
//
//	std::cerr << "Line number out of range: " << lineNumber << std::endl;
//}






//
//void writeFile(const std::string& filePath, const std::string& content, int lineNumber) {
//	std::fstream file(filePath, std::ios::in | std::ios::out);
//
//	std::string line;
//	int currentLine;
//	std::streampos position;
//
//	if (m41622 == 1) 
//	{
//		currentLine = lineNumber;
//	}
//	while (getline(file,line))
//	{
//		if (currentLine = lineNumber) {
//			//position = file.tellg();  // حفظ الموضع الحالي بعد قراءة السطر
//			//file.clear();            // مسح أي أخطاء
//			//file.seekp(position - std::streamoff(line.length() + 1));  // العودة إلى بداية السطر
//			file << content << std::endl;
//		}
//
//		break;
//	}
//
//
//
//	//std::cerr << "Put Line Number  " << currentLine << std::endl;
//
//}




void writeFile(const std::string& filePath, const std::string& newText, int lineNumber) {
	std::fstream file(filePath, std::ios::in | std::ios::out);
	if (!file.is_open()) {
		std::cerr << "Unable to open file: " << filePath << std::endl;
		return;
	}

	std::string line;
	int currentLine = 1;
	std::streampos lineStartPos = file.tellg();

	// البحث عن السطر المطلوب
	while (std::getline(file, line)) {
		if (currentLine == lineNumber) {
			break;
		}
		lineStartPos = file.tellg();
		currentLine++;
	}

	// معالجة الكتابة في السطر الأخير دون إضافة سطر جديد
	if (file.eof()) {
		if (currentLine == lineNumber) {
			file.clear(); // مسح حالة نهاية الملف
			file.seekp(lineStartPos); // العودة إلى بداية السطر المطلوب
			file << newText;
			if (newText.size() < line.size()) {
				file << std::string(line.size() - newText.size(), ' ');
			}
		}
		else {
			std::cerr << "Line number out of range: " << lineNumber << std::endl;
		}
	}
	else if (currentLine == lineNumber) {
		// تعويض السطر الجديد إذا كان طوله أقل من السطر الأصلي
		if (newText.size() < line.size()) {
			file.seekp(lineStartPos);
			file << newText;
			file << std::string(line.size() - newText.size(), ' ');
		}
		else {
			// السطر الجديد يطابق أو يتجاوز السطر الأصلي
			file.seekp(lineStartPos);
			file << newText;
		}
	}
	else {
		std::cerr << "Line number out of range: " << lineNumber << std::endl;
	}

	file.close();
}












void modspiii() {


	std::string kglaed = GetAOWPath();
	std::string filePath = kglaed + "\\inter\\skin.txt";


	if (Setting::Modskin) {

















		if (Parachuteskin == 1) {
			writeFile(filePath, "1401401", 35);
		}
		if (Parachuteskin == 2) {
			writeFile(filePath, "1401383", 35);
		}
		if (Parachuteskin == 3) {
			writeFile(filePath, "1401399", 35);
		}
		if (Parachuteskin == 4) {
			writeFile(filePath, "1401397", 35);
		}
		if (Parachuteskin == 5) {
			writeFile(filePath, "1401396", 35);
		}
		if (Parachuteskin == 6) {
			writeFile(filePath, "1401394", 35);
		}



























		
		if (glidersk == 1) {
			writeFile(filePath, "4151056", 4);
		}
		if (glidersk == 2) {
			writeFile(filePath, "4151057", 4);
		}
		if (glidersk == 3) {
			writeFile(filePath, "4151058", 4);
		}
		if (glidersk == 4) {
			writeFile(filePath, "4151059", 4);
		}
		if (glidersk == 5) {
			writeFile(filePath, "4151060", 4);
		}
		if (glidersk == 6) {
			writeFile(filePath, "4151062", 4);
		}
		if (glidersk == 7) {
			writeFile(filePath, "4151063", 4);
		}
		if (glidersk == 8) {
			writeFile(filePath, "4151064", 4);
		}
		if (glidersk == 9) {
			writeFile(filePath, "4151079", 4);
		}



		//

		if (AMRSKIN == 1) {
			writeFile(filePath, "1103012010", 30);
		}
		if (AMRSKIN == 2) {
			writeFile(filePath, "1103012019", 30);
		}

		if (HoneySKIN == 1) {
			writeFile(filePath, "1101012009", 27);
		}
		if (HoneySKIN == 2) {
			writeFile(filePath, "1101012010", 27);
		}
		if (HoneySKIN == 3) {
			writeFile(filePath, "1101012012", 27);
		}
		///
		if (MG3SKIN == 1) {
			writeFile(filePath, "1105010008", 29);
		}
		if (MG3SKIN == 2) {
			writeFile(filePath, "1105010019", 29);
		}
		if (MG3SKIN == 3) {
			writeFile(filePath, "1105010012", 29);
		}
		///
		if (MK14SKIN == 1) {
			writeFile(filePath, "1103007020", 28);
		}
		if (MK14SKIN == 2) {
			writeFile(filePath, "1103007028", 28);
		}
		if (MK14SKIN == 3) {
			writeFile(filePath, "1103007029", 28);
		}
		///
		if (M16A4SKIN == 1) {
			writeFile(filePath, "1101002081", 14);
		}
		if (M16A4SKIN == 2) {
			writeFile(filePath, "1101002117", 14);
		}
		if (M16A4SKIN == 3) {
			writeFile(filePath, "1101002110", 14);
		}
		if (M16A4SKIN == 4) {
			writeFile(filePath, "1101002056", 14);
		}

		///
		if (MINI14SKIN == 1) {
			writeFile(filePath, "1103006030", 31);
		}
		if (MINI14SKIN == 2) {
			writeFile(filePath, "1103006046", 31);
		}
		if (MINI14SKIN == 3) {
			writeFile(filePath, "1103006058", 31);
		}
		if (MINI14SKIN == 4) {
			writeFile(filePath, "1103006063", 31);
		}





		///
		if (P90SKIN == 1) {
			writeFile(filePath, "1102105001", 34);
		}
		if (P90SKIN == 2) {
			writeFile(filePath, "1102105003", 34);
		}
		if (P90SKIN == 3) {
			writeFile(filePath, "1102105004", 34);
		}
		if (P90SKIN == 4) {
			writeFile(filePath, "1102105012", 34);
		}
















		if (UZISKIN == 1) {
			writeFile(filePath, "1102001024", 13);
		}
		if (UZISKIN == 2) {
			writeFile(filePath, "1102001036", 13);
		}
		if (UZISKIN == 3) {
			writeFile(filePath, "1102001069", 13);
		}
		if (UZISKIN == 4) {
			writeFile(filePath, "1102001058", 13);
		}






		if (AUGSKIN == 1) {
			writeFile(filePath, "1101006062", 16);
		}
		if (AUGSKIN == 2) {
			writeFile(filePath, "1101006067", 16);
		}
		if (AUGSKIN == 3) {
			writeFile(filePath, "1101006044", 16);
		}
		if (AUGSKIN == 4) {
			writeFile(filePath, "1101006033", 16);
		}














		if (ACE32SKIN == 1) {
			writeFile(filePath, "1101102017", 9);
		}
		if (ACE32SKIN == 2) {
			writeFile(filePath, "1101102025", 9);
		}
		if (ACE32SKIN == 3) {
			writeFile(filePath, "1101102007", 9);
		}










		if (GROZASKIN == 1) {
			writeFile(filePath, "1101005090", 17);
		}
		if (GROZASKIN == 2) {
			writeFile(filePath, "1101005082", 17);
		}
		if (GROZASKIN == 3) {
			writeFile(filePath, "1101005052", 17);
		}
		if (GROZASKIN == 4) {
			writeFile(filePath, "1101005038", 17);
		}














		if (panskin == 1) {
			writeFile(filePath, "1108004283", 15);
		}
		if (panskin == 2) {
			writeFile(filePath, "1108004332", 15);
		}
		if (panskin == 3) {
			writeFile(filePath, "1108004356", 15);
		}
		if (panskin == 4) {
			writeFile(filePath, "1108004365", 15);
		}




		if (VectorF == 1) {
			writeFile(filePath, "1102003080", 11);
		}
		if (VectorF == 2) {
			writeFile(filePath, "1102003031", 11);
		}
		if (VectorF == 3) {
			writeFile(filePath, "1102003039", 11);
		}
		if (VectorF == 4) {
			writeFile(filePath, "1102003065", 11);
		}



















		if (UMPSKIN == 1) {
			writeFile(filePath, "1102002129", 12);
		}
		if (UMPSKIN == 2) {
			writeFile(filePath, "1102002136", 12);
		}
		if (UMPSKIN == 3) {
			writeFile(filePath, "1102002124", 12);
		}
		if (UMPSKIN == 4) {
			writeFile(filePath, "1102002117", 12);
		}







		if (copu33 == 1) {
			writeFile(filePath, "1961047", 26);
		}
		if (copu33 == 2) {
			writeFile(filePath, "1961039", 26);
		}
		if (copu33 == 3) {
			writeFile(filePath, "1961014", 26);
		}
		if (copu33 == 4) {
			writeFile(filePath, "1961015", 26);
		}
		if (copu33 == 5) {
			writeFile(filePath, "1961016", 26);
		}
		if (copu33 == 6) {
			writeFile(filePath, "1961055", 26);
		}
		if (copu33 == 7) {
			writeFile(filePath, "1961054", 26);
		}
		if (copu33 == 8) {
			writeFile(filePath, "1961150", 26);
		}













		if (UAZSK == 1) {
			writeFile(filePath, "1908075", 25);
		}
		if (UAZSK == 2) {
			writeFile(filePath, "1908078", 25);
		}
		if (UAZSK == 3) {
			writeFile(filePath, "1908084", 25);
		}
		if (UAZSK == 4) {
			writeFile(filePath, "1908019", 25);
		}
		if (UAZSK == 5) {
			writeFile(filePath, "1908094", 25);
		}
		if (UAZSK == 6) {
			writeFile(filePath, "1908086", 25);
		}



		if (daciaskin == 1) {
			writeFile(filePath, "1903197", 24);
		}
		if (daciaskin == 2) {
			writeFile(filePath, "1903193", 24);
		}
		if (daciaskin == 3) {
			writeFile(filePath, "1903191", 24);
		}
		if (daciaskin == 4) {
			writeFile(filePath, "1903079", 24);
		}
		if (daciaskin == 5) {
			writeFile(filePath, "1903067", 24);
		}
		if (daciaskin == 6) {
			writeFile(filePath, "1903063", 24);
		}







		if (hoho == 1) {
			writeFile(filePath, "1502003014", 23);
		}

		if (hoho == 2) {
			writeFile(filePath, "1502003023", 23);
		}
		if (hoho == 3) {
			writeFile(filePath, "1502003009", 23);
		}
		if (hoho == 4) {
			writeFile(filePath, "1502003012", 23);
		}
		if (hoho == 5) {
			writeFile(filePath, "1502003069", 23);
		}
		if (hoho == 6) {
			writeFile(filePath, "1502003327", 23);
		}
		if (hoho == 7) {
			writeFile(filePath, "1502003229", 23);
		}
		if (hoho == 8) {
			writeFile(filePath, "1502003183", 23);
		}
		if (hoho == 9) {
			writeFile(filePath, "1502003173", 23);
		}
		if (hoho == 10) {
			writeFile(filePath, "1502003143", 23);
		}
		if (hoho == 11) {
			writeFile(filePath, "1502003065", 23);
		}


		//back1


		if (back1 == 1) {
			writeFile(filePath, "1501003220", 22);
		}
		if (back1 == 2) {
			writeFile(filePath, "1501003174", 22);
		}
		if (back1 == 3) {
			writeFile(filePath, "1501003051", 22);
		}
		if (back1 == 4) {
			writeFile(filePath, "1501003143", 22);
		}
		if (back1 == 5) {
			writeFile(filePath, "1501003058", 22);
		}


		
		if (back1 == 6) {
			writeFile(filePath, "1501003591", 22);
		}








		if (xsuit == 1) {
			writeFile(filePath, "1405870", 1);
		}
		if (xsuit == 2) {
			writeFile(filePath, "1405628", 1);
		}
		if (xsuit == 3) {
			writeFile(filePath, "1407141", 1);
		}if (xsuit == 4) {
			writeFile(filePath, "1406475", 1);
		}if (xsuit == 5) {
			writeFile(filePath, "1405983", 1);
		}if (xsuit == 6) {
			writeFile(filePath, "1406638", 1);
		}if (xsuit == 7) {
			writeFile(filePath, "1407142", 1);
		}if (xsuit == 8) {
			writeFile(filePath, "1407103", 1);
		}if (xsuit == 9) {
			writeFile(filePath, "1406971", 1);
		}if (xsuit == 10) {
			writeFile(filePath, "1405133", 1);
		}if (xsuit == 11) {
			writeFile(filePath, "1405482", 1);
		}if (xsuit == 12) {
			writeFile(filePath, "1407106", 1);
		}if (xsuit == 13) {
			writeFile(filePath, "1405426", 1);
		}if (xsuit == 14) {
			writeFile(filePath, "1406385", 1);
		}if (xsuit == 15) {
			writeFile(filePath, "1406386", 1);
		}if (xsuit == 16) {
			writeFile(filePath, "1406387", 1);
		}if (xsuit == 17) {
			writeFile(filePath, "1406388", 1);
		}if (xsuit == 18) {
			writeFile(filePath, "1406389", 1);
		}if (xsuit == 19) {
			writeFile(filePath, "1406398", 1);
		}if (xsuit == 20) {
			writeFile(filePath, "1407219", 1);
		}if (xsuit == 21) {
			writeFile(filePath, "1407277", 1);
		}

		if (xsuit == 22) {
			writeFile(filePath, "1407329", 1);
		}
		if (xsuit == 23) {
			writeFile(filePath, "1407321", 1);
		}
		if (xsuit == 24) {
			writeFile(filePath, "1407107", 1);
		}
		if (xsuit == 25) {
			writeFile(filePath, "1406891", 1);
		}
		if (xsuit == 26) {
			writeFile(filePath, "1407278", 1);
		}
		if (xsuit == 27) {
			writeFile(filePath, "1407279", 1);
		}
		if (xsuit == 28) {
			writeFile(filePath, "1407268", 1);
		}
		if (xsuit == 29) {
			writeFile(filePath, "1405623", 1);
		}
		if (xsuit == 30) {
			writeFile(filePath, "1405447", 1);
		}
		if (xsuit == 31) {
			writeFile(filePath, "1405121", 1);
		}
		if (xsuit == 32) {
			writeFile(filePath, "1400782", 1);
		}
		if (xsuit == 33) {
			writeFile(filePath, "1400778", 1);
		}
		if (xsuit == 34) {
			writeFile(filePath, "1405092", 1);
		}
		if (xsuit == 35) {
			writeFile(filePath, "1400381", 1);
		}
		if (xsuit == 36) {
			writeFile(filePath, "1400117", 1);
		}














		if (m41622 == 1) {
			writeFile(filePath, "1101004046", 3);
		}
		if (m41622 == 2) {
			writeFile(filePath, "1101004062", 3);
		}
		if (m41622 == 3) {
			writeFile(filePath, "1101004078", 3);
		}
		if (m41622 == 4) {
			writeFile(filePath, "1101004201", 3);
		}
		if (m41622 == 5) {
			writeFile(filePath, "1101004218", 3);
		}
		if (m41622 == 6) {
			writeFile(filePath, "1101004226", 3);
		}
		if (akm22 == 1) {
			writeFile(filePath, "1101001089", 2);
		}
		if (akm22 == 2) {
			writeFile(filePath, "1101001213", 2);
		}
		if (akm22 == 3) {
			writeFile(filePath, "1101001172", 2);
		}



		if (scal_1 == 1) {
			writeFile(filePath, "1101003099", 20);
		}

		if (scal_1 == 2) {
			writeFile(filePath, "1101003146", 20);
		}

		if (scal_1 == 3) {
			writeFile(filePath, "1101003167", 20);
		}
		if (scal_1 == 4) {
			writeFile(filePath, "1101003195", 20);
		}

		if (m7777 == 1) {
			writeFile(filePath, "1101008136", 21);
		}

		if (m7777 == 2) {
			writeFile(filePath, "1101008104", 21);
		}

		if (m7777 == 3) {
			writeFile(filePath, "1101008079", 21);
		}

		if (AWMS == 1) {
			writeFile(filePath, "1103003062", 7);
		}

		if (AWMS == 2) {
			writeFile(filePath, "1103003087", 7);
		}

		if (AWMS == 3) {
			writeFile(filePath, "1103003042", 7);
		}



	}
	

}



///by omar
void ImGuiTextRGB(const char* fmt)
{


	static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;


	auto isFrames = ImGui::GetFrameCount();

	if (isFrames % 1 == 0) {

		if (isGreen == 0.01f && isBlue == 0.0f) {
			isRed += 0.01f;
		}

		if (isRed > 0.99f && isBlue == 0.0f) {
			isRed = 1.0f;
			isGreen += 0.01f;
		}

		if (isGreen > 0.99f && isBlue == 0.0f) {
			isGreen = 1.0f;
			isRed -= 0.01f;
		}

		if (isRed < 0.01f && isGreen == 1.0f) {
			isRed = 0.0f;
			isBlue += 0.01f;
		}

		if (isBlue > 0.99f && isRed == 0.0f) {
			isBlue = 1.0f;
			isGreen -= 0.01f;
		}
		if (isGreen < 0.01f && isBlue == 1.0f) {
			isGreen = 0.0f;
			isRed += 0.01f;
		}
		if (isRed > 0.99f && isGreen == 0.0f) {
			isRed = 1.0f;
			isBlue -= 0.01f;
		}
		if (isBlue < 0.01f && isGreen == 0.0f) {
			isBlue = 0.0f;
			isRed -= 0.01f;
			if (isRed < 0.01f)
				isGreen = 0.01f;
		}
		ImGui::PushFont(DX11::ImGui_DX11::pic);
		ImGui::PushStyleColor(ImGuiCol_Text, ImColor(isRed, isBlue, isGreen, 8.0f).Value);
		ImGui::Text(fmt);

		ImGui::PopFont();
		ImGui::PopStyleColor();

	}


}
///by omar
string ShowMenuTwo = "";

////void DrawSideMenu()
////{
////	// إعداد نمط ImGui
////	ImGuiStyle& style = ImGui::GetStyle();
////	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
////	ImGuiIO& Io = ImGui::GetIO();
////
////	// تخصيص الألوان والحواف
////	//ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.00f, 0.00f, 0.00f, 0.75f));
////	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.5f)); // خلفية شفافة بنسبة 50%
////
////	ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.8f, 0.8f, 0.8f, 1.0f));  // لون الحواف
////	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.0f);
////
////	// ضبط حجم النافذة (مثلاً بنسبة 30% من عرض الشاشة و auto للارتفاع)
////	ImVec2 windowSize = ImVec2(Io.DisplaySize.x * 0.06f, 0.0f); // 3% من عرض الشاشة
////	ImGui::SetNextWindowSize(windowSize);
////
////
////	// فتح النافذة
////	bool pOpen = true;
////	ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.0f, Io.DisplaySize.y * 0.5f), 0, ImVec2(0.0f, 0.5f));
////	//ImGui::Begin("Side Menu", &pOpen, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
////
////	// قراءة النص من الملف
////	
////	ShowMenuTwo = "MRBOOT_VIP";
////
////	// استخدم مؤقتًا لتغيير اللون بمرور الوقت
////	static float time = 0.0f;
////	time += ImGui::GetIO().DeltaTime;
////
////	// حساب قيم RGB ديناميكيًا باستخدام دالة sin
////	float red = (sin(time * 2.0f) * 0.5f) + 0.5f;
////	float green = (sin(time * 2.0f + 2.0f) * 0.5f) + 0.5f;
////	float blue = (sin(time * 2.0f + 4.0f) * 0.5f) + 0.5f;
////
////	// عرض النص المتغير اللون
////	ImGui::TextColored(ImVec4(red, green, blue, 1.0f), ShowMenuTwo.c_str());
////
////	// عرض خيارات القائمة
////	ImGui::Separator();
////	if (Setting::MagicBulletticked)
////	{
////		std::string dis = "[" + std::to_string(Setting::magicrange) + "]M";
////		ShowMenuTwo = "Safe Aim " + dis;
////		ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), ShowMenuTwo.c_str());
////	}
////	else
////	{
////		ShowMenuTwo = "Safe Aim ";
////		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), ShowMenuTwo.c_str());
////	}
////	ImGui::Separator();
////	if (Setting::fightmode)
////	{
////		ShowMenuTwo = "Fight Mode ";
////		ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), ShowMenuTwo.c_str());
////	}
////
////	else
////	{
////		ShowMenuTwo = "Fight Mode ";
////		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), ShowMenuTwo.c_str());
////	}
////	ImGui::Separator();
////	// إنهاء النافذة وإعادة تعيين الألوان والحواف
////	//ImGui::End();
////	ImGui::PopStyleColor(2);
////	ImGui::PopStyleVar(1);
////}
void DrawSideMenu()
{
	////////////اسم الهاك

	ShowMenuTwo = "HACK TAXI";
	// استخدم مؤقتًا لتغيير اللون بمرور الوقت
	static float time = 0.0f;
	time += ImGui::GetIO().DeltaTime;

	// حساب قيم RGB ديناميكيًا باستخدام دالة sin
	float red = (sin(time * 2.0f) * 0.5f) + 0.5f;
	float green = (sin(time * 2.0f + 2.0f) * 0.5f) + 0.5f;
	float blue = (sin(time * 2.0f + 4.0f) * 0.5f) + 0.5f;

	// تحويل القيم من [0,1] إلى [0,255]
	int r = static_cast<int>(red * 255);
	int g = static_cast<int>(green * 255);
	int b = static_cast<int>(blue * 255);

	// استبدال اللون الأبيض باللون الديناميكي المتغير
	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, ShowMenuTwo, 32, DX11Window::Height / 2 - 108, ImColor(r, g, b), true);

	//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, ShowMenuTwo, 80, DX11Window::Height / 2 - 108, DX11::ImGui_DX11::Color::White, true);

	if (Setting::MagicBulletticked)
	{
		std::string dis = "[" + std::to_string(Setting::magicrange) + "]M";
		ShowMenuTwo = "F2 > Safe Aim " + dis;
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, ShowMenuTwo, 32, DX11Window::Height / 2 - 90, DX11::ImGui_DX11::Color::Green, true);
	}
	else
	{
		ShowMenuTwo = "F2 > Safe Aim ";
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, ShowMenuTwo, 32, DX11Window::Height / 2 - 90, DX11::ImGui_DX11::Color::Red, true);

	}

	if (Setting::fightmode)
	{
		ShowMenuTwo = "F3 > Fight Mode ";
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, ShowMenuTwo, 32, DX11Window::Height / 2 - 72, DX11::ImGui_DX11::Color::Green, true);
	}
	else
	{
		ShowMenuTwo = "F3 > Fight Mode  ";
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, ShowMenuTwo, 32, DX11Window::Height / 2 - 72, DX11::ImGui_DX11::Color::Red, true);

	}
	if (Setting::fightmode)
	{
		ShowMenuTwo = "F5 > All Items ";
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, ShowMenuTwo, 32, DX11Window::Height / 2 - 52, DX11::ImGui_DX11::Color::Green, true);
	}
	else
	{
		ShowMenuTwo = "F5 > All Items  ";
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, ShowMenuTwo, 32, DX11Window::Height / 2 - 52, DX11::ImGui_DX11::Color::Red, true);

	}
	if (Setting::fightmode)
	{
		ShowMenuTwo = "F6 > Vehicles ";
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, ShowMenuTwo, 32, DX11Window::Height / 2 - 32, DX11::ImGui_DX11::Color::Green, true);
	}
	else
	{
		ShowMenuTwo = "F6 > Vehicles  ";
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, ShowMenuTwo, 32, DX11Window::Height / 2 - 32, DX11::ImGui_DX11::Color::Red, true);

	}
}

// Function to get the number of active game users
int getActiveUserCount()
{
	static std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);

	// Read the user count from a file
	std::ifstream file("user_count.txt");
	int count = 0;
	if (file.good())
	{
		file >> count;
	}
	file.close();

	return count;
}



// Function to increment the number of active game users
void incrementActiveUserCount()
{
	static std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);

	// Read the user count from a file
	std::ifstream file("user_count.txt");
	int count = 0;
	if (file.good())
	{
		file >> count;
	}
	file.close();

	// Increment the count and write it back to the file
	count++;
	std::ofstream outfile("user_count.txt");
	outfile << count;
	outfile.close();
}
// Function to decrement the number of active game users
void decrementActiveUserCount()
{
	static std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);

	// Read the user count from a file
	std::ifstream file("user_count.txt");
	int count = 0;
	if (file.good())
	{
		file >> count;
	}
	file.close();

	// Decrement the count and write it back to the file
	if (count > 0)
	{
		count--;
	}
	std::ofstream outfile("user_count.txt");
	outfile << count;
	outfile.close();
}



static int64_t eptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
///by omar
void DrawTotalEnemies() {


	//	ImGui::SetNextWindowSize(ImVec2(155.0f, 35.0f));
	ImGuiIO& Io = ImGui::GetIO();
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
	if (Data::NetDriver > 0)
	{
		if (Data::AActorList.size() > 0)
		{

			ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 255));
			ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.92f, 0.92f, 0.92f, 1.0f));
			ImGuiStyle* style = &ImGui::GetStyle();
			style->WindowBorderSize = 2.0f;
			ImGui::SetNextWindowPos(ImVec2({ (DX11Window::Width / 2.0f) }, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
			if (ImGui::Begin("ene", 0, Flags21))
			{
				std::string Text1 = " ";
				std::string Text2 = " ";
				std::string Text3 = " ";
				ImGui::PushFont(DX11::ImGui_DX11::pRegularFont);
				if (Data::AActorList.size() > 0)
				{
					if ((Data::AActorList.size() - Data::ABotList.size()) > 0)
					{

						Text1.append(ICON_FA_USER"  PLAYERS: ");
						Text1.append(std::to_string((Data::AActorList.size() - Data::ABotList.size())));
						if (Data::ABotList.size() == 0)
						{
							Text3.append("      ");

						}
						else
						{
							Text2.append(" ");
							Text2.append(ICON_FA_USER"  BOTS: ");
							Text2.append(std::to_string(Data::ABotList.size()));
							Text2.append(" ");
						}
						Text3.append(ICON_FA_USER ICON_FA_USER"  TEAMS: ");
						Text3.append(std::to_string(Data::AliveTeamNum));


					}

					else if (Data::ABotList.size() > 0)
					{


						Text2.append(ICON_FA_USER"  BOTS: ");
						Text2.append(std::to_string(Data::ABotList.size()));
					}


				}

				ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 0, 0, 255));
				ImGui::Text(Text1.c_str());

				if (Data::ABotList.size() > 0)
				{

					ImGui::SameLine();
					ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(0, 255, 0, 255));
					ImGui::Text(Text2.c_str());
					ImGui::PopStyleColor();
				}

				ImGui::SameLine();
				ImGui::Text(Text3.c_str());
				ImGui::PopStyleColor();


				ImGui::PopFont();
				ImGui::End();
			}
		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 255));
			ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.92f, 0.92f, 0.92f, 1.0f));

			ImGui::SetNextWindowPos(ImVec2({ (DX11Window::Width / 2.0f) }, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
			if (ImGui::Begin("ene", 0, Flags21))
			{
				
				std::string Text1 = "";



				TextWithColors("  {FF0000}NO ONE IS     {00FFE1}NEAR YOU ");

			}
			ImGui::PushStyleColor(ImGuiCol_Text, to_vec4(255, 0, 0, 255));

			
			ImGui::PopStyleColor();
			ImGui::End();

		}

	}
	else
	{






		ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 255));
		ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.92f, 0.92f, 0.92f, 1.0f));
		ImGui::SetNextWindowPos(ImVec2({ (DX11Window::Width / 2.0f) }, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
		if (ImGui::Begin("ene", 0, Flags21))
		{
			ImGui::PushFont(DX11::ImGui_DX11::pRegularFont);
			/*	std::string Text1 = "";

					Text1 = ICON_FA_HOME" [You Are in]";
					TextWithColors(ICON_FA_HOME" {#cccccc} [You Are in] : {00FF0F}   Lobby    {#cccccc}" ICON_FA_CLOCK "  [Since] : " );
					ImGui::SameLine();*/

					/* std::string Text = ICON_FA_HOME"  (You Are in): {00FF0F} Lobby";
				Memory::RestoreHook();

				std::string Alive1 = ICON_FA_CLOCK"  (Since): {00FF0F} ";


				TextWithColors(Text.c_str());
				ImGui::SameLine();
				Alive1.append(std::to_string(10));
				TextWithColors(Alive1.c_str());*/
				//	int time = //time2();

			TextWithColors(ICON_FA_HOME" {cccccc} [You Are in] : {00FF0F}  Lobby    {cccccc}" ICON_FA_CLOCK "  [Since] : ");

			int minutes = Data::TimeRemind / 60;
			int hours = minutes / 60;
			string LobbyTime = "{00FF0F}" + (to_string(hours) + ":").append(to_string(minutes % 60) + ":").append(to_string(Data::TimeRemind % 60));
			ImGui::SameLine();
			TextWithColors(LobbyTime.c_str());
			//ImGui::Text(LobbyTime.c_str());
			ImGui::PopFont();
			ImGui::End();
		}
	}
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
	ImGui::PopStyleColor();
}
///by omar
Graphics selectedGraphic = Smooth; // Define and initialize the selectedLanguage variable
bool isGraphicSelected = false; // Flag to indicate if a language is selected

Language selectedLanguage = English; // Define and initialize the selectedLanguage variable
bool isLanguageSelected = false; // Flag to indicate if a language is selected
void Drawgameinfo()
{
	/*if (!Data::AlivePlayerNum == 1)
	{
		ImGui::SetNextWindowSize(ImVec2(160.0f, 185.0f));
	}*/
	ImGuiIO& Io = ImGui::GetIO();

	ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 150));
	ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
	ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));

	if (ImGui::Begin(" GAME STATISTICS ", 0, Flags22))
	{

		if (Data::NetDriver > 0)
		{

			if (Data::AliveTeamNum == 1)
			{
				ImGui::Text("Winner Winner Chicken Dinner");

			}
			else

			{
				//ImGui::SetNextWindowSize(ImVec2(160.0f, 185.0f));
				std::string Text1 = "";
				std::string Text2 = "";
				std::string Text3 = "";
				std::string Text4 = "";
				std::string Text5 = "";
				std::string Text6 = "";
				std::string Text7 = "";
				std::string Text8 = "";
				std::string Text9 = "";
				std::string Text10 = "";



				Text1 = " PLAYERS: ";

				//	std::string Text1 = "";

				Text1.append(std::to_string((Data::AActorList.size() - Data::ABotList.size())));


				Text2.append(" BOTS:  ");
				Text2.append(std::to_string(Data::ABotList.size()));

				Text3.append(" ALIVE PLAYERS:  ");
				Text3.append(std::to_string(Data::AlivePlayerNum));

				Text4.append(" Teams:  ");
				Text4.append(std::to_string(Data::AliveTeamNum));

				Text5.append(" ZoneID:  ");
				if (Data::CurCircleWave == -1)
				{
					Data::CurCircleWave = 0;
				}
				Text5.append(std::to_string(Data::CurCircleWave));

				Text6.append(" GameID:  ");
				Text6.append(std::to_string(Data::GameModeID));

				Text7.append(" ELAPSED TIME:  ");

				int minutes = Data::TimeRemind / 60;

				string GameTime = (to_string(minutes % 60) + "m ").append(to_string(Data::TimeRemind % 60) + "s");
				Text7.append(GameTime);


				Text8.append(" GAME TYPE:  ");

				Text8.append(Data::GameType);
				Text9.append(" MAP TYPE:  ");
				Text9.append(Data::LocalPawn);
				Text10.append(" YOUR KILLS :  ");
				Text10.append(std::to_string(Data::Kills));

				//:Text1.append(std::to_string(Data::PlayerNumPerTeam));
				ImGui::Spacing;
				ImGui::Spacing;
				ImGui::Text(Text1.c_str());
				ImGui::Text(Text2.c_str());
				ImGui::Text(Text3.c_str());
				ImGui::Text(Text4.c_str());
				ImGui::Text(Text5.c_str());
				ImGui::Text(Text6.c_str());
				ImGui::Text(Text7.c_str());
				ImGui::Text(Text8.c_str());
				ImGui::Text(Text9.c_str());
				ImGui::Text(Text10.c_str());
				//ImGui::Text(Text9.c_str());
				ImGui::Spacing;
			}
		}
		else
		{
			time_t t; // t passed as argument in function time()
			struct tm* tt; // decalring variable for localtime()
			std::time(&t); //passing argument to time()
			tt = localtime(&t);
			//cout << "Current Day, Date and Time is = " << asctime(tt);
			std::string tim;
			tim = asctime(tt);
			////////اسم اهلاك 
			string Lobby = "HACK TAXI";
			ImGui::Text(Lobby.c_str());
			string GAMELOOP = " GAMELOOP";

			string TIME = " TIME:" + tim;

			ImGui::Text(GAMELOOP.c_str());
			ImGui::Text(TIME.c_str());

		}

		ImGui::End();
	}

	ImGui::PopStyleColor();
	ImGui::PopStyleColor();
}
///by omar
void DrawRadarHUD(MinimalViewInfo Camera, AActor Player, int Distance, int xAxis, int yAxis, int width, int height, ImVec4 color)
{

	ImGui::SetNextWindowSize(ImVec2(Setting::RadarLength, Setting::RadarWidth));
	ImGuiIO& Io = ImGui::GetIO();

	ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 108));
	ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 200));
	ImGui::SetNextWindowPos(ImVec2(50, (Io.DisplaySize.y / 2) + 100), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
	if (ImGui::Begin("     ", 0, Flags21))
	{


		{

			ImVec2 wind = ImGui::GetWindowSize();
			ImVec2 wind2 = ImGui::GetWindowPos();



			bool out = false;
			VECTOR3 siz;
			siz.X = wind.x;
			siz.Y = wind.y;
			VECTOR3 pos;
			pos.X = wind2.x;
			pos.Y = wind2.y;
			float RadarCenterX = pos.X + (siz.X / 2);
			float RadarCenterY = pos.Y + (siz.Y / 2);
			//DX11::ImGui_DX11::DrawOutlineBox(pos.X, pos.Y, siz.X, siz.Y, ImVec4(0, 0, 0, 1.f), 1.0f);
			//DX11::ImGui_DX11::DrawBox(pos.X, pos.Y, siz.X, siz.Y, .1, 0, 0, 0, .1, true);


			/*DX11::ImGui_DX11::IMGUIDRAWLINE(RadarCenterX, RadarCenterY, pos.X, pos.Y, ImVec4(255, 0, 0, 255), 1.0f);
			DX11::ImGui_DX11::IMGUIDRAWLINE(RadarCenterX, RadarCenterY, pos.X + siz.X, pos.Y, ImVec4(255, 0, 0, 255), 1.0f);
			DX11::ImGui_DX11::IMGUIDRAWLINE(pos.X, RadarCenterY, pos.X + siz.X, RadarCenterY, ImVec4(color), 1.0f);
			DX11::ImGui_DX11::IMGUIDRAWLINE(RadarCenterX, RadarCenterY, RadarCenterX, pos.Y + siz.Y, ImVec4(color), 1.0f);*/
			DX11::ImGui_DX11::IMGUIDRAWCIRCLE(RadarCenterX, RadarCenterY, 3, ImVec4(color), 2.0f);
			VECTOR3 ddddd;
			ddddd.X = siz.X;
			ddddd.Y = siz.Y;
			ddddd.Z = 0;
			VECTOR3 single = WorldToRadar(Camera.Rotation.Yaw, Player.Position, Data::CameraCache.POV.Location, pos.X, pos.Y, ddddd, out);

			if (Distance < Setting::PlayerMAxDistance)
			{
				DX11::ImGui_DX11::IMGUIDRAWCIRCLE(single.X, single.Y, 3, ImVec4(color), 2.0f);
			}



		}
		ImGui::End();
	}
	ImGui::PopStyleColor();
	ImGui::PopStyleColor();



}
int aimcalled = 0;
bool aimisyellow = false;
void CallEnemyAimWarning()
{
	string aimingtext = "ENEMY IS AIMING AT YOU";
	if (!aimisyellow)
	{
		if (aimcalled >= 50)
		{
			aimcalled = 0;
			aimisyellow = true;
		}
		string excl = "";
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 45, excl, DX11Window::Width / 2 - 270, DX11Window::Height / 270 * 20.0f, DX11::ImGui_DX11::Color::Red, true);
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 45, aimingtext, DX11Window::Width / 2, DX11Window::Height / 270 * 20.0f, DX11::ImGui_DX11::Color::Red, true);
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 45, excl, DX11Window::Width / 2 + 270, DX11Window::Height / 270 * 20.0f, DX11::ImGui_DX11::Color::Red, true);
	}
	else
	{
		if (aimcalled >= 50)
		{
			aimcalled = 0;
			aimisyellow = false;
		}
		string excl = "";
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 45, excl, DX11Window::Width / 2 - 270, DX11Window::Height / 270 * 20.0f, DX11::ImGui_DX11::Color::Yellow, true);
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 45, aimingtext, DX11Window::Width / 2, DX11Window::Height / 270 * 20.0f, DX11::ImGui_DX11::Color::Yellow, true);
		DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 45, excl, DX11Window::Width / 2 + 270, DX11Window::Height / 270 * 20.0f, DX11::ImGui_DX11::Color::Yellow, true);
	}
	aimcalled++;
}

static const std::string webhook_url = "https://discord.com/api/webhooks/1276451604102512660/-vA9o9aEtlJ4n74eBfJ6hOd66IZ-ESjZKkrpM6m6-VGQI0KHWyt3BrzaTR17EBHF5TQB";
static std::string message = "";
static bool show_popup = false;
static bool message_sent = false;
static bool message_failed = false;
static std::string error_message = "";

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

static bool SendDiscordMessage(const std::string& message)
{
	CURL* curl;
	CURLcode res;
	std::string response;
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (curl)
	{
		std::string json_data = "{\"content\":\"" + message + "\"}";
		struct curl_slist* headers = NULL;
		headers = curl_slist_append(headers, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_URL, webhook_url.c_str());
		curl_easy_setopt(curl, CURLOPT_POST, 1L);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		res = curl_easy_perform(curl);
		if (res == CURLE_OK)
		{
			long http_code = 0;
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
			if (http_code == 204)
			{
				curl_slist_free_all(headers);
				curl_easy_cleanup(curl);
				return true;
			}
		}
		curl_slist_free_all(headers);
		curl_easy_cleanup(curl);
	}
	return false;
}

std::string formatElapsedTime(long long elapsed_seconds)
{
	if (elapsed_seconds < 60)
	{
		return std::to_string(elapsed_seconds) + " seconds";
	}
	else if (elapsed_seconds < 3600)
	{
		int minutes = elapsed_seconds / 60;
		int seconds = elapsed_seconds % 60;
		return std::to_string(minutes) + " minutes, " + std::to_string(seconds) + " seconds";
	}
	else if (elapsed_seconds < 86400)
	{
		int hours = elapsed_seconds / 3600;
		int minutes = (elapsed_seconds % 3600) / 60;
		return std::to_string(hours) + " hours, " + std::to_string(minutes) + " minutes";
	}
	else if (elapsed_seconds < 604800)
	{
		int days = elapsed_seconds / 86400;
		int hours = (elapsed_seconds % 86400) / 3600;
		return std::to_string(days) + " days, " + std::to_string(hours) + " hours";
	}
	else if (elapsed_seconds < 2592000)
	{
		int weeks = elapsed_seconds / 604800;
		int days = (elapsed_seconds % 604800) / 86400;
		return std::to_string(weeks) + " weeks, " + std::to_string(days) + " days";
	}
	else
	{
		int months = elapsed_seconds / 2592000;
		int days = (elapsed_seconds % 2592000) / 86400;
		return std::to_string(months) + " months, " + std::to_string(days) + " days";
	}
}
void ErrorReporter()
{
	if (ImGui::Button("Error Reporter", ImVec2(180, 50)))
	{
		show_popup = true;
	}

	if (show_popup)
	{
		ImGui::OpenPopup("Error Reporter Popup");
	}

	if (ImGui::BeginPopupModal("Error Reporter Popup", &show_popup, ImGuiWindowFlags_AlwaysAutoResize))
	{
		if (!message_sent && !message_failed)
		{
			ImGui::InputTextMultiline("Message", &message[0], message.capacity());

			if (ImGui::Button("Send"))
			{
				if (!message.empty())
				{
					if (SendDiscordMessage(message))
					{
						message_sent = true;
						message.clear();
					}
					else
					{
						message_failed = true;
						error_message = "Failed to send message to Discord.";
					}
				}
			}
		}
		else
		{
			std::string message_text;
			if (message_sent)
			{
				message_text = "Message sent successfully!";
			}
			else if (message_failed)
			{
				message_text = error_message;
			}
			ImGui::Text(message_text.c_str());
			if (ImGui::Button("Close"))
			{
				ImGui::CloseCurrentPopup();
				if (message_sent)
				{
					message_sent = false;
				}
				else if (message_failed)
				{
					message_failed = false;
					error_message.clear();
				}
			}
		}
		ImGui::EndPopup();
	}
}



int DiffX1;
int DiffY1;
std::string string_To_UTF8111(const std::string& str)
{
    int nwLen = ::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

    wchar_t* pwBuf = new wchar_t[nwLen + 1];
    ZeroMemory(pwBuf, (nwLen + 1) * sizeof(wchar_t));

    ::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

    int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, 0, NULL, NULL);

    char* pBuf = new char[nLen + 1];
    ZeroMemory(pBuf, nLen + 1);

    ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

    std::string retStr(pBuf);

    delete[] pwBuf;
    delete[] pBuf;

    pwBuf = NULL;
    pBuf = NULL;

    return retStr;
}


VOID DrawBorderString111(ImFont* pFont, FLOAT size, std::string& Text, FLOAT x, FLOAT y, ImColor Color, bool Center)
{
	std::string utf8Text = string_To_UTF8111(Text); // تحويل النص إلى UTF-8

	ImVec2 textPosition(x + DiffX1, y + DiffY1);

	if (Center) {
		// حساب موضع النص بالوسط
		float textWidth = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, utf8Text.c_str()).x;
		textPosition.x -= textWidth * 0.5f;
	}

	ImGui::GetOverlayDrawList()->AddText(pFont, size, textPosition, Color, utf8Text.c_str());
}





///by omar
void random_color(int iTick)
{
	ImVec4(sin(5.f * iTick + 0.f) * 127 + 128 / 255.0f, sin(5.f * iTick + ((2.f * 3.14159265358979323846) / 3)) * 127 + 128 / 255.0f, sin(5.f * iTick + ((4.f * 3.14159265358979323846) / 3)) * 127 + 128 / 255.0f, 255 / 255.0f);

}
///by omar
void MenuText(const char* text)
{
	ImGui::SetCursorPosX(20.0f);
	ImGui::Text(text);
}
bool onetimemsgggg = false;
bool onetimemsg = false;
bool onetimemsg2 = false;
bool onetimemsg3 = false;

void CallMsg()
{
	if (!onetimemsgggg)
	{
		/////Sleep(5000);
		///ImGui::InsertNotification({ ImGuiToastType_Success, 3000, "Connected to the chat server." });
		/////Sleep(1000);
		///ImGui::InsertNotification({ ImGuiToastType_Info, 3000, "Connecting to the chat server..." });
		//Sleep(1000);
		
		onetimemsgggg = true;
	}
}
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

// تعريف المتغيرات لتتبع حالة اللاعب ووقت البدء
bool inMatch = false;
steady_clock::time_point matchStartTime;

void LoadSavedKey(char* keyBuffer, size_t bufferSize)
{
	std::ifstream keyFile("C:\\keyn_HACK_TAXI");
	if (keyFile.is_open())
	{
		keyFile.getline(keyBuffer, bufferSize);
		keyFile.close();
	}
}

#include "C:\Users\GAN\Desktop\Loader-desgin\Loader_desgin\GradientEffect.hpp"
#include "mrboot.h"
VOID Esp::EspThread()
{
	VECTOR3 Screen;
	INT Distance = 0;
	INT EnemyCount = 0;
	VECTOR3 HeadPos;
	VECTOR2 Head;
	VECTOR2 Chest;
	VECTOR2 Pelvis;
	VECTOR2 lSholder;
	VECTOR2 rSholder;
	VECTOR2 lElbow;
	VECTOR2 rElbow;
	VECTOR2 lWrist;
	VECTOR2 rWrist;
	VECTOR2 lThigh;
	VECTOR2 rThigh;
	VECTOR2 lKnee;
	VECTOR2 rKnee;
	VECTOR2 lAnkle;
	VECTOR2 rAnkle;
	std::string temp = "";
	std::string dist = "";
	string Text = "ssssssss";
	string weapon = "";

	std::string name = "Toska"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
	std::string ownerid = "KKm3reqfxt"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
	std::string secret = "9cb832d0447379d58d6e6248ec700b3e769199ccb7af4c6961b0d44d1dbae7a7"; // app secret, the blurred text on licenses tab and other tabs
	std::string version = "1.0"; // leave alone unless you've changed version on website
	api bestauthApp(name, ownerid, secret, version);
	bestauthApp.init();

	///by omar
	vector<AActor> TempAActorList = {};
	vector<Deadbox> TempBoxesList = {};
	vector<Vehicle> TempVehicalList = {};
	vector<Item> TempItemList = {};
	vector<BombAlert> TempBombAlertList = {};
	while (true)
	{
		g_Discord->Initialize();
		g_Discord->Update();
		///LoadConfig("C:\\storm_hax_Key.ini");
		try
		{
			RECT Rect;
			GetWindowRect(Game::hWindow, &Rect);
			DX11Window::Left = Rect.left;
			DX11Window::Top = Rect.top;
			DX11Window::Width = Rect.right - Rect.left;
			DX11Window::Height = Rect.bottom - Rect.top;
			MoveWindow(DX11Window::hWindow, DX11Window::Left, DX11Window::Top, DX11Window::Width, DX11Window::Height, true);
			ImGui_ImplDX9_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();
			ImVec4 yellowColor = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
			// ألوان محسنة لتظهر بشكل واضح على الخلفية
			static ImVec4 textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // أبيض نقي للنصوص ليتباين مع الخلفية الداكنة
			static ImVec4 headColor = ImVec4(1.0f, 0.6f, 0.0f, 1.0f); // برتقالي مشرق للعناوين ليتناسب مع لهب الخلفية
			static ImVec4 areaColor = ImVec4(0.15f, 0.15f, 0.15f, 0.9f); // خلفية رمادية داكنة مع شفافية بسيطة
			static ImVec4 bodyColor = ImVec4(0.1f, 0.1f, 0.1f, 0.9f); // لون الجسم رمادي داكن مع شفافية
			static ImVec4 popsColor = ImVec4(0.2f, 0.2f, 0.2f, 1.0f); // لون القوائم المنبثقة رمادي متوسط
			static ImVec4 bgColor = ImVec4(0.05f, 0.05f, 0.05f, 1.0f); // لون الخلفية رمادي داكن جداً
			static ImVec4 borderColor = ImVec4(1.0f, 0.5f, 0.0f, 1.0f); // برتقالي زاهي للحواف ليتناسب مع الخلفية
			static ImVec4 accentColor = ImVec4(0.9f, 0.3f, 0.0f, 1.0f); // برتقالي غامق للتباين
			static ImVec4 warningColor = ImVec4(1.0f, 0.85f, 0.4f, 1.0f); // أصفر مشرق للتنبيه
			static ImVec4 successColor = ImVec4(0.4f, 0.9f, 0.4f, 1.0f); // أخضر فاتح للنجاح
			static ImVec4 azazaz = ImVec4(0.3f, 0.3f, 0.3f, 1.0f); // لون الفواصل رمادي فاتح قليلاً

			static ImVec4 mrboot = ImVec4(0.15f, 0.15f, 0.15f, 0.9f); // لون الخلفية العامة رمادي داكن مع شفافية خفيفة
			static ImVec4 mrboot22 = ImVec4(0.0f, 0.8f, 0.0f, 1.0f); // لون علامات التحقق أخضر مشرق ليتباين مع الخلفية

			ImGui::StyleColorsDark();
			ImGuiStyle* style = &ImGui::GetStyle();
			style->Colors[ImGuiCol_Text] = textColor;
			style->Colors[ImGuiCol_Header] = headColor;
			style->Colors[ImGuiCol_MenuBarBg] = areaColor;
			style->Colors[ImGuiCol_WindowBg] = mrboot;
			style->Colors[ImGuiCol_PopupBg] = popsColor;
			style->Colors[ImGuiCol_TabUnfocusedActive] = headColor;
			style->Colors[ImGuiCol_Separator] = azazaz;
			style->Colors[ImGuiCol_CheckMark] = mrboot22;

			// لون متحرك للحدود
			static float time123 = 0.0f;
			time123 += ImGui::GetIO().DeltaTime;
			float red = (sin(time123 * 2.0f) * 0.5f) + 0.5f;
			float green = (sin(time123 * 2.0f + 2.0f) * 0.5f) + 0.5f;
			float blue = (sin(time123 * 2.0f + 4.0f) * 0.5f) + 0.5f;
			ImVec4 accentColor2 = ImVec4(red, green, blue, 1.0f);

			style->Colors[ImGuiCol_Border] = accentColor2;

			// تحديد ألوان إضافية
			style->Colors[ImGuiCol_Button] = accentColor;
			style->Colors[ImGuiCol_ButtonHovered] = warningColor;
			style->Colors[ImGuiCol_ButtonActive] = successColor;

			// سمك الحدود
			style->WindowBorderSize = 2.0f;



			if (!onetimemsg)
			{
				CallMsg();
				onetimemsg = true;
			}
			
			
			///by omar
				MAKER->Show();
			if (Setting::ShowMenu)
			{
				BackgroundThemes();
				
				if (!login)
				{
					// قراءة الكود المحفوظ عند بدء البرنامج
					LoadSavedKey(str1, IM_ARRAYSIZE(str1)); // تحميل المفتاح المحفوظ في str1

					POINT mouse;
					GetCursorPos(&mouse);
					//Snowflake::Update(snow, Snowflake::vec3(mouse.x, mouse.y), Snowflake::vec3(DX11Window::Width, DX11Window::Height));
					ImGuiIO& Io = ImGui::GetIO();
					ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
					static auto Flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
					////قائمة الهاك في دخول 
					if (ImGui::Begin(">>> WELCOME TO TAXI HACKER <<<", 0, Flags))
					{
						
						// إعداد الألوان الرئيسية
						ImVec4 primaryColor = ImVec4(0.0f, 0.6f, 0.8f, 1.0f);  // لون أزرق مميز
						ImVec4 secondaryColor = ImVec4(0.1f, 0.7f, 0.5f, 1.0f); // لون أخضر ناعم
						ImVec4 backgroundColor = ImVec4(0.08f, 0.08f, 0.1f, 0.95f); // لون خلفية داكن مع شفافية بسيطة
						ImVec4 borderColor = ImVec4(0.9f, 0.4f, 0.0f, 1.0f); // لون البرتقالي الزاهي للحدود
						ImVec4 textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // لون النص الأبيض

						// إعداد الألوان للواجهة
						ImGui::StyleColorsDark();
						ImGuiStyle* style = &ImGui::GetStyle();
						style->Colors[ImGuiCol_Text] = textColor;
						style->Colors[ImGuiCol_WindowBg] = backgroundColor;
						style->Colors[ImGuiCol_Button] = primaryColor;
						style->Colors[ImGuiCol_ButtonHovered] = secondaryColor;
						style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.9f, 0.3f, 0.2f, 1.0f);
						style->Colors[ImGuiCol_Border] = borderColor;

						// سمك الحدود وتدوير الحواف
						style->WindowBorderSize = 3.0f;
						style->FrameRounding = 10.0f;
						style->GrabRounding = 12.0f;

						// تأثير تلاشي اللون للأزرار
						static float time = 0.0f;
						time += ImGui::GetIO().DeltaTime;
						float fade = (sin(time * 2.0f) * 0.5f) + 0.5f;
						ImVec4 fadeColor = ImVec4(primaryColor.x * fade, primaryColor.y * fade, primaryColor.z * fade, 1.0f);
						ImGui::PushFont(DX11::ImGui_DX11::pRegularFont);
						// إعدادات الأزرار
						ImGui::SetCursorPosX(10.0f);
						ImGui::Text("Enter Your Key:");
						ImGui::SameLine();
						ImGui::SetNextItemWidth(350.0f);
						if (showkey)
						{
							ImGui::InputText("###Key", str1, IM_ARRAYSIZE(str1));
						}
						else
						{
							ImGui::InputText("###Key", str1, IM_ARRAYSIZE(str1), ImGuiInputTextFlags_Password);
						}
						ImGui::Spacing();
						ImGui::SetCursorPosX(7.f);

						// زر تسجيل الدخول مع أيقونة وتفاعل
						if (ImGui::Button(ICON_FA_LINK " Login", ImVec2(190.0f, 30.0f)))
						{
							if (bestauthApp.license(str1))
							{
								login = true;
								server = true;

								// حفظ الكود في الملف C:\keyn_vip عند تسجيل الدخول بنجاح
								std::ofstream keyFile("C:\\keyn_HACK_TAXI");
								if (keyFile.is_open())
								{
									keyFile << str1;
									keyFile.close();
								}
							}
							else
							{
								server1 = true;
								login = false;
							}
						}
						ImGui::SameLine();
						ImGui::SetCursorPosX(255.f);

						// زر التواصل مع أيقونة وتفاعل
						if (ImGui::Button(ICON_FA_LIGHTBULB" Contact Us", ImVec2(190.0f, 30.0f)))
						{
							///////////////////لينك الدعم الفني 
							ShellExecute(NULL, L"open", L"https://discord.gg/KSyhzrEzQC", NULL, NULL, SW_SHOWNORMAL);
						}
						ImGui::Spacing();

						// تفعيل أو إلغاء تفعيل حفظ المستخدمين
						ImGui::Checkbox(" Save User Key", &SaveUsers);
						if (SaveUsers)
						{
							WriteConfig("C:\\spr3.1_hex_Key.ini", str1, true);
						}
						else
						{
							WriteConfig("C:\\spr3.1_hex_Key.ini", str1, false);
						}
						ImGui::PopFont();
						ImGui::End();
					}
				}




				if (login)
				{
					POINT mouse;
					GetCursorPos(&mouse);
					//Snowflake::Update(snow, Snowflake::vec3(mouse.x, mouse.y), Snowflake::vec3(DX11Window::Width, DX11Window::Height));
					static auto Name = "Menu";
					static auto Flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
					static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
					//ImGui::InsertNotification({ ImGuiToastType_Success, 3000, "Connected to the chat server." });
					ImGui::SetNextWindowSize({ 777, 550  }); //Window Size
					static ImVec4 active = to_vec4(0, 100, 230, 255);
					static ImVec4 inactive = to_vec4(0, 80, 160, 255);

					ImGui::PushFont(DX11::ImGui_DX11::pRegularFont);
					if (lage == 0)
					{
						//logiiin
						if (ImGui::Begin("HACK TAXI", 0, Flags))
						{


							if (Setting::loginn)
							{
								if (ImGui::BeginTabBar("ON"))
								{

									if (ImGui::BeginTabItem(ICON_FA_NEWSPAPER" News"))
									{

										ImVec2 originalPos = ImGui::GetCursorPos();

										ImGui::SetCursorPosY(210);
										ImGui::SetCursorPosX(203);

										// تكبير الصورة إلى أبعاد جديدة أكبر
										ImGui::Image((PVOID)DX11::mrboot, ImVec2(366, 300)); // استخدم أبعاد أكبر هنا

										ImGui::SetCursorPos(originalPos);




										ImGui::Spacing();
										ImGui::SetCursorPosX({ 10.0f });
										ImGui::Text("OFFICIAL has been updated to 3.3");

										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SetCursorPosX({ 10.0f });

										// تعيين اللون الأزرق للنص
										ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.5f, 1.0f, 1.0f));
										// استخدام Selectable لسهولة النقر
										if (ImGui::Selectable("Click Here for More Info", false, ImGuiSelectableFlags_DontClosePopups))
										{
											//////لينك دعم فني داخل 
											ShellExecute(NULL, L"open", L"https://t.me/+UD5H--3Np0I5NmE0", NULL, NULL, SW_SHOWNORMAL);
										}
										
										// تغيير شكل الماوس إلى اليد إذا كان الماوس فوق العنصر
										if (ImGui::IsItemHovered())
										{
											ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
										}

										ImGui::PopStyleColor();

										ImGui::Spacing();
										ImGui::SetCursorPosX({ 10.0f });
										ImGui::Text("Disclaimer:");
										ImGui::SetCursorPosX({ 10.0f });
										ImGui::Text("This cheat is still under development and some features may not work.");

										ImGui::EndTabItem();
									}




									if (ImGui::BeginTabItem(ICON_FA_EYE" ESP Control"))
									{
										if (ImGui::BeginTabBar("ESP Tabs"))
										{
											if (ImGui::BeginTabItem(ICON_FA_USER " Player"))
											{
												// استخدم BeginChild لفصل العناصر وتجنب التداخل
												ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

												// عرض الصورة كخلفية
												ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
												ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
												ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

												// إعداد المسافة بين الصورة والعناصر الأخرى
												ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة

												// Player Settings (Checkboxes and other UI elements)
												ImGui::Checkbox(" Show Enemy Name", &Setting::pname);
												ImGui::Checkbox(" Draw Enemy Skeleton", &Setting::playerBone);
												ImGui::Checkbox(" Draw Enemy Line", &Setting::pline);
												ImGui::Checkbox(" Draw Player Box", &Setting::pcorner);
												ImGui::Checkbox(" Show Vehicles", &Setting::Vehicle);
												ImGui::Checkbox(" Draw Flags", &Setting::pflag);
												ImGui::Checkbox(" Show Enemy Around", &Setting::TotalEnemy);
												ImGui::Checkbox(" Draw Radar", &Setting::radar);
												ImGui::Checkbox(" Draw Game Information", &Setting::gameinfo);
												ImGui::Checkbox(" Show Enemy Distance", &Setting::plyrdistance);
												ImGui::Checkbox(" Show Enemy Health", &Setting::phealth);
												ImGui::Checkbox(" Show Enemy Weapon", &Setting::playerweapon);

												ImGui::Separator(); // خط فاصل لمزيد من الوضوح


												if (Setting::pname) {
													if (ImGui::TreeNode("NAME"))
													{
														ImGui::Indent();
														ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 50); // Adjust this value as needed
														ImGui::Text("Text color ");
														ImGui::SameLine();

														ImGui::ColorEdit4("", (float*)&Colors::playername);
														ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 50); // Adjust this value as needed
														ImGui::Text("Text size ");
														ImGui::SameLine();
														ImGui::SliderInt("###4", &nsize, 1, 50);
														ImGui::Unindent();
														ImGui::TreePop();
													}
												}

												if (Setting::pline) {

													if (ImGui::TreeNode("Line"))
													{
														ImGui::Indent();
														ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 50); // Adjust this value as needed
														ImGui::Text("Color mode");
														ImGui::SameLine();
														ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 50); // Adjust this value as needed
														const char* Emu1[] = { "Team ID", "Default" };

														const char* combo_label = Emu1[linne];
														if (ImGui::BeginCombo(" loll121212", combo_label, ImGuiComboFlags_HeightSmall))
														{
															for (int n = 0; n < IM_ARRAYSIZE(Emu1); n++)
															{
																const bool is_selected = (linne == n);
																if (ImGui::Selectable(Emu1[n], is_selected))
																	linne = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															///if (linne == 0);
															///else if (linne == 1);
															ImGui::EndCombo();
														}
														if (linne == 1)
														{
															ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 50); // Adjust this value as needed
															ImGui::Text("Line color ");
															ImGui::SameLine();
															ImGui::ColorEdit4(" color1", (float*)&Colors::playerline, ImGuiColorEditFlags_NoLabel);
														}
														ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 50); // Adjust this value as needed
														ImGui::Text("Thickness ");
														ImGui::SameLine();
														ImGui::SliderFloat("Line size", &Setting::plinesize, 0.100f, 3.00f);

														ImGui::Unindent();
														ImGui::TreePop();
													}
												}
												// Enemy Line Settings
												////if (Setting::pline)
												////{
												////	if (ImGui::TreeNodeEx(" Enemy Line"))
												////	{
												////		ImGui::Indent();
												////		ImGui::BulletText("Line Color");
												////		ImGui::BulletText("Line color ");
												////		ImGui::ColorEdit4(" color1", (float*)&Colors::playerline, ImGuiColorEditFlags_NoLabel);

												////		//const char* Emu1[] = { "Team ID", "Default" };
												////		//const char* combo_label = Emu1[linne];
												////		///if (ImGui::BeginCombo(" loll", combo_label, ImGuiComboFlags_HeightSmall))
												////		///{
												////		///	for (int n = 0; n < IM_ARRAYSIZE(Emu1); n++)
												////		///	{
												////		///		const bool is_selected = (linne == n);
												////		///		if (ImGui::Selectable(Emu1[n], is_selected))
												////		///			linne = n;
												////		///		if (is_selected)
												////		///			ImGui::SetItemDefaultFocus();
												////		///	}
												////		///	ImGui::EndCombo();
												////		///}

												////		//if (linne == 1)
												////		//{
												////		//	ImGui::BulletText("Line color ");
												////		//	ImGui::ColorEdit4(" color1", (float*)&Colors::playerline, ImGuiColorEditFlags_NoLabel);
												////		//}

												////		ImGui::BulletText("Thickness ");
												////		ImGui::SliderFloat("Line size", &Setting::plinesize, 0.100f, 3.00f);
												////		ImGui::Unindent();
												////		ImGui::TreePop();
												////	}
												////}

												// Enemy Skeleton Settings
												if (Setting::playerBone)
												{
													if (ImGui::TreeNodeEx(" Enemy Skeleton"))
													{
														ImGui::Indent();
														ImGui::BulletText("Skeleton Color");
														ImGui::ColorEdit4(" color", (float*)&Colors::playerbone, ImGuiColorEditFlags_NoLabel);

														ImGui::BulletText("Thickness ");
														ImGui::SliderFloat("Bone size", &Setting::pbonesize, 0.100f, 3.00f);
														ImGui::Unindent();
														ImGui::TreePop();
													}
												}

												// Player Box Settings
												if (Setting::pcorner)
												{
													if (ImGui::TreeNodeEx(" Player Box"))
													{
														ImGui::Indent();
														ImGui::BulletText("Display mode");

														const char* Emu3[] = { "4 edges", "Rectangle" };
														const char* combo_label = Emu3[boxe];
														if (ImGui::BeginCombo(" loll11", combo_label, ImGuiComboFlags_HeightSmall))
														{
															for (int n = 0; n < IM_ARRAYSIZE(Emu3); n++)
															{
																const bool is_selected = (boxe == n);
																if (ImGui::Selectable(Emu3[n], is_selected))
																	boxe = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															ImGui::EndCombo();
														}

														if (boxe == 0)
														{
															ImGui::BulletText("Thickness ");
															ImGui::SliderFloat("###1", &Setting::pcornersize, 0.100f, 2.00f);
														}
														else if (boxe == 1)
														{
															ImGui::BulletText("Thickness ");
															ImGui::SliderFloat("###2", &Setting::pfullboxsize, 0.100f, 2.00f);
														}

														ImGui::Unindent();
														ImGui::TreePop();
													}
												}

												ImGui::EndChild(); // إغلاق نافذة الـ Child

												ImGui::EndTabItem();
											}



											if (ImGui::BeginTabItem(ICON_FA_ADJUST" Items"))
											{
												// استخدم BeginChild لفصل العناصر وتجنب التداخل
												ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

												// عرض الصورة كخلفية
												ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
												ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
												ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

												// إعداد المسافة بين الصورة والعناصر الأخرى
												ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة

												ImGui::PushID("#0");
												ImGui::ColorEdit4("M416", (float*)&weapon::m16, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("M416", &Setting::Esp_Item_M416);
												ImGui::SameLine();


												Setting::Esp_Item_M416_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_M416_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_M416_Icon);
												ImGui::PopID();

												ImGui::PushID("#1");
												ImGui::ColorEdit4("AKM", (float*)&weapon::AKM, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("AKM", &Setting::Esp_Item_AKM);
												ImGui::SameLine();
												Setting::Esp_Item_AKM_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_AKM_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_AKM_Icon);
												ImGui::PopID();

												ImGui::ColorEdit4("SCAR", (float*)&weapon::scarl, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("SCAR-L", &Setting::Esp_Item_SCARL);

												ImGui::ColorEdit4("FAMAS", Setting::Esp_Item_FAMAS_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("FAMAS", &Setting::Esp_Item_FAMAS);
												ImGui::PushID("#2");
												ImGui::ColorEdit4("M762", Setting::Esp_Item_M762_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("M762", &Setting::Esp_Item_M762);
												ImGui::SameLine();

												Setting::Esp_Item_M762_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_M762_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_M762_Icon);

												ImGui::PopID();
												ImGui::ColorEdit4("Mk14", Setting::Esp_Item_Mk14_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Mk14", &Setting::Esp_Item_Mk14);

												ImGui::ColorEdit4("DP28", Setting::Esp_Item_DP28_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("DP28", &Setting::Esp_Item_DP28);
												ImGui::ColorEdit4("AMW", (float*)&weapon::AWM, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("AWM", &Setting::Esp_Item_Awm);

												ImGui::ColorEdit4("AMR", Setting::Esp_Item_SniperAMR_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("AMR Sniper", &Setting::Esp_Item_SniperAMR);

												ImGui::ColorEdit4("AMRb", Setting::Esp_Item_BulletAMR_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("AMR Bullet", &Setting::Esp_Item_BulletAMR);


												ImGui::PushID("#3");
												ImGui::ColorEdit4("M24", (float*)&weapon::M24, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("M24", &Setting::Esp_Item_M24);
												ImGui::SameLine();

												Setting::Esp_Item_M24_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_M24_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_M24_Icon);
												ImGui::PopID();
												ImGui::ColorEdit4("kar98", (float*)&weapon::kar98, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("KAR98", &Setting::Esp_Item_Kar98k);
												ImGui::PushID("#4");
												ImGui::ColorEdit4("Flare", (float*)&weapon::Flaregun, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Flare Gun", &Setting::Esp_Item_FlareGun);
												ImGui::SameLine();
												//	ImGui::Checkbox("ICON", &Setting::Esp_Item_M416);
												Setting::Esp_Item_FlareGun_Icon ? ImGui::Checkbox("ICON", &Setting::Esp_Item_FlareGun_Icon) : ImGui::Checkbox("Text", &Setting::Esp_Item_FlareGun_Icon);
												ImGui::PopID();
												ImGui::ColorEdit4("Flareg", (float*)&weapon::Flare, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Flare", &Setting::Esp_Item_Flare);


												ImGui::ColorEdit4("Airdrop", (float*)&weapon::Airdrop, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("AirDrop", &Setting::airdrop);

												ImGui::ColorEdit4("Armor 3", Setting::Esp_Item_Armor3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Armor 3", &Setting::Esp_Item_Armor3);

												ImGui::ColorEdit4("Bag 3", Setting::Esp_Item_Bag3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Bag 3", &Setting::Esp_Item_Bag3);

												ImGui::ColorEdit4("Helmet 3", Setting::Esp_Item_Helmet3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Helmet 3", &Setting::Esp_Item_Helmet3);


												ImGui::ColorEdit4("Helmet 3", (float*)&weapon::AWMimmo, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("AWM immo", &Setting::Esp_Item_Awmimo);

												ImGui::ColorEdit4("Dead-Box ", (float*)&Colors::deadbox, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Dead-Box", &Setting::deadbox);

												ImGui::ColorEdit4("Dead-Boxi ", (float*)&Colors::deadboxitem, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Dead-Box-list", &Setting::playerdeadbox);

												ImGui::ColorEdit4("air-Boxi ", (float*)&Colors::airdropitem, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("AirDrop-lists", &Setting::airdropitem);

												ImGui::SliderFloat("Item-Box Distance", &Setting::ItemMaxDistance, 0, 350, "%.f");

												ImGui::ColorEdit4("Extended QuickDraw", Setting::Esp_Item_exquic_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Extended QuickDraw", &Setting::Esp_Item_exquic);
												ImGui::SameLine();
												ImGui::ColorEdit4("Helmet 1", Setting::Esp_Item_Helmet1_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Helmet 1", &Setting::Esp_Item_Helmet1);

												ImGui::ColorEdit4("Helmet 2", Setting::Esp_Item_Helmet2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Helmet 2", &Setting::Esp_Item_Helmet2);

												ImGui::ColorEdit4("Bag 1", Setting::Esp_Item_Bag1_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Bag 1", &Setting::Esp_Item_Bag1);

												ImGui::ColorEdit4("Bag 2", Setting::Esp_Item_Bag2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Bag 2", &Setting::Esp_Item_Bag2);

												ImGui::ColorEdit4("Armor 1", Setting::Esp_Item_Armor1_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Armor 1", &Setting::Esp_Item_Armor1);

												ImGui::ColorEdit4("Armor 2", Setting::Esp_Item_Armor2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Armor 2", &Setting::Esp_Item_Armor2);

												ImGui::ColorEdit4("G36C", (float*)&Setting::Esp_Item_G36C_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("G36C", &Setting::Esp_Item_G36C);

												ImGui::ColorEdit4("QBZ", (float*)&Setting::Esp_Item_QBZ_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("QBZ", &Setting::Esp_Item_QBZ);

												ImGui::ColorEdit4("QBU", (float*)&Setting::Esp_Item_QBU_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("QBU", &Setting::Esp_Item_QBU);

												ImGui::ColorEdit4("SLR", (float*)&Setting::Esp_Item_SLR_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("SLR", &Setting::Esp_Item_SLR);

												ImGui::ColorEdit4("SKS", (float*)&Setting::Esp_Item_SKS_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("SKS", &Setting::Esp_Item_SKS);

												ImGui::ColorEdit4("Mini14", (float*)&Setting::Esp_Item_Mini14_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Mini14", &Setting::Esp_Item_Mini14);

												ImGui::ColorEdit4("PP19", (float*)&Setting::Esp_Item_PP19_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("PP19", &Setting::Esp_Item_PP19);

												ImGui::ColorEdit4("Tommy", (float*)&Setting::Esp_Item_TommyGun_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Tommy Gun", &Setting::Esp_Item_TommyGun);

												ImGui::ColorEdit4("MP5K", (float*)&Setting::Esp_Item_MP5K_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("MP5K", &Setting::Esp_Item_MP5K);

												ImGui::ColorEdit4("UMP9", (float*)&Setting::Esp_Item_UMP9_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("UMP9", &Setting::Esp_Item_UMP9);

												ImGui::ColorEdit4("Vector", (float*)&Setting::Esp_Item_Vector_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Vector", &Setting::Esp_Item_Vector);

												ImGui::ColorEdit4("Uzi", (float*)&Setting::Esp_Item_Uzi_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Uzi", &Setting::Esp_Item_Uzi);

												ImGui::ColorEdit4("762mm", (float*)&Setting::Esp_Item_762mm_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("7.62mm", &Setting::Esp_Item_762mm);

												ImGui::ColorEdit4("556mm", (float*)&Setting::Esp_Item_556mm_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("556mm", &Setting::Esp_Item_556mm);

												ImGui::ColorEdit4("9mm", (float*)&Setting::Esp_Item_9mm_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("9mm", &Setting::Esp_Item_9mm);

												ImGui::ColorEdit4("45ACP", (float*)&Setting::Esp_Item_45ACP_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("45ACP", &Setting::Esp_Item_45ACP);

												ImGui::ColorEdit4("Holo", (float*)&Setting::Esp_Item_Holo_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Holo", &Setting::Esp_Item_Holo);

												ImGui::ColorEdit4("RedDot", (float*)&Setting::Esp_Item_Holo_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("RedDot", &Setting::Esp_Item_Holo);


												ImGui::ColorEdit4("Mk47-Mutant", (float*)&Setting::Esp_Item_Mk47Mutant_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Mk47-Mutant", &Setting::Esp_Item_Mk47Mutant);
												ImGui::SameLine();
												ImGui::ColorEdit4("Frag", Setting::Esp_Item_Frag_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Frag", &Setting::Esp_Item_Frag);

												ImGui::ColorEdit4("Smoke", Setting::Esp_Item_Smoke_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Smoke", &Setting::Esp_Item_Smoke);

												ImGui::ColorEdit4("Molotof", Setting::Esp_Item_Molotof_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Molotof", &Setting::Esp_Item_Molotof);
												ImGui::SameLine();
												ImGui::ColorEdit4("Med Kit", Setting::Esp_Item_MedKit_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Med Kit", &Setting::Esp_Item_MedKit);

												ImGui::ColorEdit4("First Aid Kit", Setting::Esp_Item_FirstAidKit_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("First Aid Kit", &Setting::Esp_Item_FirstAidKit);

												ImGui::ColorEdit4("Bandage", Setting::Esp_Item_Bandage_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Bandage", &Setting::Esp_Item_Bandage);

												ImGui::ColorEdit4("Painkiller", Setting::Esp_Item_Painkiller_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Painkiller", &Setting::Esp_Item_Painkiller);

												ImGui::ColorEdit4("Energy Drink", Setting::Esp_Item_EnergyDrink_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Energy Drink", &Setting::Esp_Item_EnergyDrink);

												ImGui::ColorEdit4("Adrenaline Syringe", Setting::Esp_Item_AdrenalineSyringe_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Adrenaline Syringe", &Setting::Esp_Item_AdrenalineSyringe);
												ImGui::EndChild();
												ImGui::EndTabItem();
											}
											if (ImGui::BeginTabItem(ICON_FA_CAR" Vehicles"))
											{
												ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

												// عرض الصورة كخلفية
												ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
												ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
												ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

												// إعداد المسافة بين الصورة والعناصر الأخرى

												// إعداد المسافة بين الصورة والعناصر الأخرى
												ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة
												ImGui::Checkbox("Important Items", &Setting::impitems);

												ImGui::Checkbox("All Items", &Setting::allitemss);

												ImGui::Checkbox("Health items", &Setting::healthitem);

												ImGui::Checkbox("Scope items", &Setting::scope);

												ImGui::ColorEdit4("Vehiclescol", (float*)&Colors::vehicle, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Vehicles", &Setting::Vehicle);
												ImGui::SameLine();
												ImGui::Checkbox("HP", &Setting::hp);
												ImGui::SameLine();
												ImGui::Checkbox("FUEL", &Setting::feul);

												ImGui::ColorEdit4("bomb", (float*)&Colors::Granadeswarn, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("Bomb Items", &Setting::BombAlert);

												ImGui::EndChild();
												ImGui::EndTabItem();
											}
											if (ImGui::BeginTabItem(ICON_FA_LEAF" Observation"))
											{

												// استخدم BeginChild لفصل العناصر وتجنب التداخل
												ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

												// عرض الصورة كخلفية
												ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
												ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
												ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

												// إعداد المسافة بين الصورة والعناصر الأخرى
												ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة
												ImGui::ColorEdit4("2X", Setting::Esp_Item_x2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("x2", &Setting::Esp_Item_x2);

												ImGui::ColorEdit4("3X", Setting::Esp_Item_x3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("x3", &Setting::Esp_Item_x3);

												ImGui::ColorEdit4("4X", Setting::Esp_Item_x4_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("x4", &Setting::Esp_Item_x4);

												ImGui::ColorEdit4("6X", Setting::Esp_Item_x6_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("x6", &Setting::Esp_Item_x6);

												ImGui::ColorEdit4("8X", Setting::Esp_Item_x8_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox("x8", &Setting::Esp_Item_x8);
												ImGui::EndChild();
												ImGui::EndTabItem();
											}
											ImGui::EndTabBar();
										}

										ImGui::EndTabItem();
									}


								

									if (ImGui::BeginTabItem(ICON_FA_BUG " Memory")) {

										if (ImGui::BeginTabBar("Memory")) {

											if (ImGui::BeginTabItem(ICON_FA_PERCENT " Safe Memory")) {

												// استخدم BeginChild لفصل العناصر وتجنب التداخل
												ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

												// عرض الصورة كخلفية
												ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
												ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
												ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

												// إعداد المسافة بين الصورة والعناصر الأخرى
												ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة



												// عنوان القائمة مع لون جذاب
												ImGui::TextColored(ImVec4(0.85f, 0.6f, 0.3f, 1.0f), "Safe Memory Options");
												ImGui::Separator();  // يرسم الخط الفاصل
												ImGui::Spacing();

												ImGui::Checkbox("Ipad View", &showSlider);
												if (showSlider) {
													ImGui::PushItemWidth(333);
													ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.2f, 0.2f, 0.2f, 0.8f));
													ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.85f, 0.6f, 0.3f, 1.0f));
													if (ImGui::SliderInt("IPAD", &ipadView, 200, 360)) {
														WriteUE4Float(0x5BCC908, ipadView);
													}
													ImGui::PopStyleColor(2);

												}

												// خيارات التفعيل مع ألوان مختلفة للتفعيل
												if (ImGui::Checkbox("MAGIC BULLET", &Setting::MagicBulletticked)) {
													if (Setting::MagicBulletticked) {
													//	ImGui::InsertNotification({ ImGuiToastType_Success, 3000, XorStr("MAGIC BULLET Activated!!").c_str() });
													}
													else {
													//	ImGui::InsertNotification({ ImGuiToastType_Warning, 3000, XorStr("MAGIC BULLET Deactivated!").c_str() });
													}
												}

												if (Setting::MagicBulletticked) {
													ImGui::TextColored(ImVec4(0.85f, 0.6f, 0.3f, 1.0f), "Magic Bullet Configuration:");
													ImGui::PushItemWidth(250);



													//const char* combo_label = aimb[Setting::curraim];
													const char* aimb[] = { "HEAD", "BODY", "PELVIS", "AUTO" };
													const char* combo_label = aimb[Setting::curraim];
													if (ImGui::BeginCombo(" loll123", combo_label, ImGuiComboFlags_HeightSmall))
													{
														for (int n = 0; n < IM_ARRAYSIZE(aimb); n++)
														{
															const bool is_selected = (Setting::curraim == n);
															if (ImGui::Selectable(aimb[n], is_selected))
																Setting::curraim = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}




													ImGui::Checkbox("Safe Magic", &Setting::MagicRangeCheck);
													if (Setting::MagicRangeCheck) {
														ImGui::SliderInt("Magic Range", &Setting::magicrange, 40, 100);
													}

													ImGui::Checkbox("Skip Bots", &Setting::SkipBots);
													ImGui::Checkbox("Skip Knocked", &Setting::SkipKnocked);
													ImGui::Checkbox("FOV Circle", &Setting::fovcircle);
													ImGui::SliderFloat("FOV Circle Size", &Setting::fovcircleredus, 30.0f, 100.0f);

													ImGui::Separator();
													ImGui::Spacing();

													ImGui::TextColored(ImVec4(0.85f, 0.6f, 0.3f, 1.0f), "Aimbot Visuals Configuration:");
													ImGui::Checkbox("Aim Line", &Setting::pline);
													ImGui::Checkbox("Show Current Aim Position", &Setting::aimbotposition);
												}
												ImGui::EndChild();
												ImGui::EndTabItem();
											}

											if (ImGui::BeginTabItem( " Danger Memory")) {
												// استخدم BeginChild لفصل العناصر وتجنب التداخل
												ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

												// عرض الصورة كخلفية
												ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
												ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
												ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

												// إعداد المسافة بين الصورة والعناصر الأخرى
												ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة

												ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Danger Memory Options");
												ImGui::Separator();

												// هنا يمكنك إضافة محتوى قائمة "Danger Memory"
												ImGui::EndChild();
												ImGui::EndTabItem();
											}

											ImGui::EndTabBar();
										}
										ImGui::EndTabItem();
									}



									


									std::string kglaed = GetAOWPath();
									std::string filePath = kglaed + "\\inter\\modskin.ini";

									if (FileExist(filePath)) {

										if (ImGui::BeginTabItem(ICON_FA_STREET_VIEW" Fake Skin"))
										{
											ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

											// عرض الصورة كخلفية
											ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
											ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
											ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

											// إعداد المسافة بين الصورة والعناصر الأخرى
											ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة

											CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)modspiii, nullptr, NULL, nullptr);
											if (ImGui::BeginTabBar("Magic Tabs"))
											{
												// SKIN X-SUIT Tab
												if (ImGui::BeginTabItem(ICON_FA_FEMALE" SKIN X-SUIT"))
												{
													ImGui::BeginTable("SkinXSuitTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();

													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("X-Suit");
													ImGui::TableNextColumn();

													const char* xsuity[] = { "NO SKIN", "Blood Raven X-Suit", "Golden Pharaoh X-Suit", "Avalanche X-suit", "Irresidence X-suit", "Poseidon X-suit", "Arcane Jester X-suit", "Silvanus X-Suit","Fiore X-Suit","Marmoris X-Suit","Great Indian Warrior","Anniversary Unicorn","Foxy Flare","Red Bowtie","Evangelion Shinji","Evangelion Rei","Evangelion Asuka","Evangelion Mari","Evangelion Kaworu","Flamewraith","Ignis X-Suit","Inferno Fiend",
													"Serene Lumina","Rahma Riad","Winter Highness","Psychophage","Myriam Fares Festival","Myriam Fares Warrior","Super Saiyan Blue Son","Underworld Guide","Rhythm Rider","Infected Patient","Glacier Set","Dystopian Survivor","The Fool Set",
													"Bunny Swimsuit (Pink)","Fireman Suit "};
													const char* combo_label = xsuity[xsuit];
													ImGui::SetCursorPosX({ 490.0f });
													//ImGui::SetCursorPosX(ImGui::GetWindowWidth() - 300.0f);
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("X-SUIT Combo", combo_label, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(xsuity); n++)
														{
															const bool is_selected = (xsuit == n);
															if (ImGui::Selectable(xsuity[n], is_selected))
																xsuit = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
													ImGui::Separator();
												}

												// Backpack Skins Tab
												if (ImGui::BeginTabItem(ICON_FA_SUITCASE" Backpack Skins"))
												{
													ImGui::BeginTable("BackpackSkinsTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();

													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("Backpack");
													ImGui::TableNextColumn();

													const char* backpack1[] = { "NO SKIN","Blood Raven","Golden Pharaoh","The Fool","Dazzling Youth","BAPE X PUBGM CAMO","Serene Lumina" };
													const char* combo_label2 = backpack1[back1];

													ImGui::SetCursorPosX({ 490.0f });
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("Backpack Combo", combo_label2, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(backpack1); n++)
														{
															const bool is_selected = (back1 == n);
															if (ImGui::Selectable(backpack1[n], is_selected))
																back1 = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
												}
												//skincar

												if (ImGui::BeginTabItem(ICON_FA_CAR" Car Skins")) {

													if (ImGui::BeginTable("carTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable)) {
														ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
														ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
														ImGui::TableHeadersRow();
														// Add weapon and skin combos
														ImGui::TableNextRow();
														ImGui::TableNextColumn();
														ImGui::Text("Dacia");
														ImGui::TableNextColumn();
														const char* Dacia2[] = { "NO SKIN", "Midknight Dacia (Lv. 4)", "Ghost Gleam", "Ghost Rosa", "Lamborghini Estoque Oro", "Ghillie Lion", "Taiyaki" };
														const char* Dacii2 = Dacia2[daciaskin];
														ImGui::SetCursorPosX({ 490.0f });
														ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
														if (ImGui::BeginCombo("#Dacia1", Dacii2, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
														{
															for (int n = 0; n < IM_ARRAYSIZE(Dacia2); n++)
															{
																const bool is_selected = (daciaskin == n);
																if (ImGui::Selectable(Dacia2[n], is_selected))
																	daciaskin = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															ImGui::EndCombo();
														}


														ImGui::TableNextRow();
														ImGui::TableNextColumn();
														ImGui::Text("UAZ");
														ImGui::TableNextColumn();
														const char* UAZF[] = { "NO SKIN", "Maserati Levante", "Maserati Levante Firmamento", "Aston Martin DBX707","BAPE X PUBGM","Bentley Bentayga Azure","Dodge Hornet" };
														const char* UAZ3 = UAZF[UAZSK];

														ImGui::SetCursorPosX({ 490.0f });
														ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
														if (ImGui::BeginCombo("#UAZF", UAZ3, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
														{
															for (int n = 0; n < IM_ARRAYSIZE(UAZF); n++)
															{
																const bool is_selected = (UAZSK == n);
																if (ImGui::Selectable(UAZF[n], is_selected))
																	UAZSK = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															ImGui::EndCombo();
														}



														ImGui::TableNextRow();
														ImGui::TableNextColumn();
														ImGui::Text("Cope");
														ImGui::TableNextColumn();
														const char* Cope333[] = { "NO SKIN", "Bugatti La Voiture Noire", "Maserati MC20 Rosso", "McLaren 570S","McLaren 570S (Pearlescent)","Koenigsegg Jesko","Pagani Imola (Grigio Montecarlo)","Pagani Imola (Crystal Clear)","Dodge" };
														const char* Copeff = Cope333[copu33];

														ImGui::SetCursorPosX({ 490.0f });
														ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
														if (ImGui::BeginCombo("#Cope333", Copeff, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
														{
															for (int n = 0; n < IM_ARRAYSIZE(Cope333); n++)
															{
																const bool is_selected = (copu33 == n);
																if (ImGui::Selectable(Cope333[n], is_selected))
																	copu33 = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															ImGui::EndCombo();
														}














														ImGui::EndTable();

													}


													ImGui::EndTabItem();



												}


												// Helmet Skins Tab
												if (ImGui::BeginTabItem(ICON_FA_PODCAST" Helmet Skins"))
												{
													ImGui::BeginTable("HelmetSkinsTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();

													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("Helmet");
													ImGui::TableNextColumn();

													const char* helmet22[] = { "NO SKIN","Inferno Rider ","Glacier Helmet","PUBLING Helmet","Galactic Helmet","Masked Psychic","Magma Skull","Joyful Kitten","Godzilla Helmet",
													"Ghillie Lion","Dream Idol","Moon Bunny" };
													const char* cossss = helmet22[hoho];

													ImGui::SetCursorPosX({ 490.0f });
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("Helmet Combo", cossss, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(helmet22); n++)
														{
															const bool is_selected = (hoho == n);
															if (ImGui::Selectable(helmet22[n], is_selected))
																hoho = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
												}

												if (ImGui::BeginTabItem(ICON_FA_LEVEL_DOWN" Glider Skins")) {

													ImGui::BeginTable("GliderSkinsTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();
													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("Glider Skins");
													ImGui::TableNextColumn();
													const char* Glider1212[] = { "NO SKIN",  "Chilly Perch","Foxy Flare" ,"LINE FRIENDS","Cloudslash","Golden Serpent","Zanmang Loopy","SPY×FAMILY",
													"Dominion Wings","Underworld Vestige"};
													const char* cossss22 = Glider1212[glidersk];

													ImGui::SetCursorPosX({ 490.0f });
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("Glider Combo", cossss22, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(Glider1212); n++)
														{
															const bool is_selected = (glidersk == n);
															if (ImGui::Selectable(Glider1212[n], is_selected))
																glidersk = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
												}

												if (ImGui::BeginTabItem(ICON_FA_UMBRELLA" Parachute Skins")) {

													ImGui::BeginTable("ParachuteSkinsTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();
													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("Parachute Skins");
													ImGui::TableNextColumn();
													const char* Parachute1212[] = { "NO SKIN", "Bentley","KFC Royale Delight" ,"Phantom Luster","Hardik Sky","Zanmang Loopy","LINE FRIENDS"};
													const char* cossss22f = Parachute1212[Parachuteskin];

													ImGui::SetCursorPosX({ 490.0f });
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("Parachute Combo", cossss22f, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(Parachute1212); n++)
														{
															const bool is_selected = (Parachuteskin == n);
															if (ImGui::Selectable(Parachute1212[n], is_selected))
																Parachuteskin = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
												}







												if (ImGui::BeginTabItem(ICON_FA_GAVEL" Weapon Skins"))
												{
													if (ImGui::BeginTable("WeaponTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable))
													{
														// Display headers
														ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 300.0f);
														ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
														ImGui::TableHeadersRow();

														struct Weapon {
															const char* name;
															std::vector<const char*> skins;
															int* selected_skin;
														};

														// Define and initialize weapon skin selections

														Weapon weapons[] = {
															{"M416", {"NO SKIN", "Glacier - M416", "The Fool - M416", "Wanderer - M416", "Silver Guru - M416", "Shinobi Kami - M416", "Sealed Nether - M416"}, &m41622},
															{"AKM", {"NO SKIN", "Glacier - AKM", "Starsea Admiral - AKM", "Wandering Tyrant - AKM"}, &akm22},
															{"SCAR-L", {"NO SKIN", "Drop the Bass - SCAR-L", "Thorn of Malice - SCAR-L", "Bloodstained Nemesis - SCAR-L","Serene Lumina"}, &scal_1},
															{"M762", {"NO SKIN", "Luminous Muse", "Starcore", "Stray Rebellion"}, &m7777},
															{"AUG", {"NO SKIN", "Forsaken Glace", "Deep Sea Terror", "Evangelion 4th Angel", "Wandering Circus"}, &AUGSKIN},
															{"GROZA", {"NO SKIN", "Primordial Remnants", "Pumpkin Carol", "River Styx", "Ryomen Sukuna"}, &GROZASKIN},
															{"ACE32", {"NO SKIN", "Icicle Spike", "Mystic Kraken", "Beam Blast"}, &ACE32SKIN},
															{"M16A4", {"NO SKIN", "Skeletal Core", "Seraphic Beacon", "Sweetheart Surge","Aurora Pulse"}, &M16A4SKIN},
															{"P90", {"NO SKIN", "Angry Sheep", "Dancing Prints", "Fairytale Scarecrow","Devious Cybercat"}, &P90SKIN},
															{"Honey", {"NO SKIN", "Vivid Glare", "Sonic Wave", "Squeakology"}, &HoneySKIN},
															{"MG3", {"NO SKIN", "Soaring Dragon", "Sky Huntress", "Night Maiden"}, &MG3SKIN},
															{"MK14", {"NO SKIN", "Gilded Galaxy", "Drakreign", "Phoenix Song"}, &MK14SKIN},
															{"MINI14", {"NO SKIN", "Icicle", "Ethereal Beauty", "Fortune Cat","Gallant Jockey"}, &MINI14SKIN},
															{"AWM", {"NO SKIN", "Flamewave - AWM", "Serpengleam - AWM", "Godzilla - AWM"}, &AWMS},
															{"AMR", {"NO SKIN", "Crimson Ephialtes", "Scorching Blessing"}, &AMRSKIN},
															{"UMP45", {"NO SKIN", "Carnival Waves", "Cryofrost Shard", "Marine Evolution", "Rainbow Stinger"}, &UMPSKIN},
															{"Vector", {"NO SKIN", "Mecha Drake", "Midnight Rose", "Cute Baddie", "Gilded Reaper"}, &VectorF},
															{"UZI", {"NO SKIN", "Savagery", "Ethereal Emblem", "Shimmer Power", "Romantic Moments"}, &UZISKIN},
															{"Pan", {"NO SKIN", "Accolade", "Break Pad", "Chicken Hot", "Faerie Luster"}, &panskin}
														};

														for (int i = 0; i < IM_ARRAYSIZE(weapons); i++)
														{
															const Weapon& weapon = weapons[i];
															ImGui::TableNextRow();
															ImGui::TableNextColumn();
															ImGui::Text("%s", weapon.name);
															ImGui::TableNextColumn();
															ImGui::SetCursorPosX(490.0f);
															ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
															const char* combo_label = weapon.skins[*weapon.selected_skin];
															std::string combo_name = std::string("#combo_") + weapon.name + std::to_string(i); // Ensure unique combo name
															if (ImGui::BeginCombo(combo_name.c_str(), combo_label, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
															{
																for (int n = 0; n < weapon.skins.size(); n++)
																{
																	const bool is_selected = (*weapon.selected_skin == n);
																	if (ImGui::Selectable(weapon.skins[n], is_selected))
																		*weapon.selected_skin = n;
																	if (is_selected)
																		ImGui::SetItemDefaultFocus();
																}
																ImGui::EndCombo();
															}

															// Insert space between rows
															ImGui::Spacing();
															ImGui::Spacing();

															// Draw separator across the table with transparency
															ImGui::TableNextRow(ImGuiTableRowFlags_None, 5.0f); // Adjust the height of the separator row
															ImGui::TableNextColumn();
															ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));  // الأسود الكامل // Red color for the separator with transparency
															ImGui::Separator();
															ImGui::PopStyleColor();
															ImGui::TableNextColumn();
															ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));  // الأسود الكامل// Red color for the separator with transparency
															ImGui::Separator();
															ImGui::PopStyleColor();
														}

														ImGui::EndTable();
													}
													ImGui::EndTabItem();
												}






												ImGui::EndTabBar();
											}
											ImGui::EndChild();
											ImGui::EndTabItem();
										}

									
									}









								
									if (ImGui::BeginTabItem(ICON_FA_COGS" Settings"))
									{

										ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

										// عرض الصورة كخلفية
										ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
										ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
										ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

										// إعداد المسافة بين الصورة والعناصر الأخرى
										ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة



										if (ImGui::BeginTabBar("Settings Tabs"))
										{
											if (ImGui::BeginTabItem("Main Settings"))
											{
												ImGui::Spacing();

												// Centered Title
												ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.6f);
												ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Main Settings").x) * 0.5f);
												ImGui::TextColored(yellowColor, "Main Settings");
												ImGui::PopItemWidth();
												ImGui::Spacing();
												ImGui::Separator();
												ImGui::Spacing();

												// Text Size Slider
												const char* languageItems[] = { "English", u8"ﻲﺑﺮﻋ" };

												const char* combo_label = languageItems[lage];
												if (ImGui::BeginCombo(" loll11GGG", combo_label, ImGuiComboFlags_HeightSmall))
												{
													for (int n = 0; n < IM_ARRAYSIZE(languageItems); n++)
													{
														const bool is_selected = (lage == n);
														if (ImGui::Selectable(languageItems[n], is_selected))
															lage = n;
														if (is_selected)
															ImGui::SetItemDefaultFocus();
													}
													if (lage == 0);
													else if (lage == 1);


													ImGui::EndCombo();
												}


												ImGui::PushItemWidth(300);
												ImGui::Text("Text Size");
												ImGui::SliderFloat("##TextSize", &Setting::Normalfontsize, 14.0f, 20.0f, "%.1f");
												ImGui::Spacing();

												// Important Text Size Slider
												ImGui::Text("Important Text Size");
												ImGui::SliderFloat("##ImportantTextSize", &Setting::fontsize, 14.0f, 20.0f, "%.1f");
												ImGui::Spacing();

												// Update Thread Delay Slider
												ImGui::Text("Update Thread Delay");
												ImGui::SliderInt("##UpdateThreadDelay", &Setting::UpdateThreadDelay, 20, 200);
												ImGui::Spacing();

												// ESP Refresh Rate Slider
												ImGui::Text("ESP Refresh Rate");
												ImGui::SliderInt("##EspRefreshRate", &Setting::EspThreadDelay, 5, 16);
												ImGui::Spacing();

												// Address Getter Delay Slider
												ImGui::Text("Address Getter Delay");
												ImGui::SliderInt("##AddressGetterDelay", &Setting::AdreessGetterDelay, 2000, 4000);
												ImGui::Spacing();

												// Anti Stream Screenshot Checkbox
												ImGui::Checkbox("Anti Stream Screenshot", &Setting::AntiScreenShot);
												if (Setting::AntiScreenShot) {
													SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
												}
												else {
													SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
												}
												ImGui::Spacing();

												// Buttons for Save, Load, and Exit
												ImGui::PushItemWidth(200.0f);
												ImGui::SetCursorPosX((ImGui::GetWindowWidth() - 3 * 210.0f - 10.0f) * 0.5f);
												if (ImGui::Button("Save Settings")) {
												//	ImGui::InsertNotification({ ImGuiToastType_Success, 3000, "Settings saved successfully." });
													WriteConfigurate("C:\\TAXI_hax_config.ini");
												}
												ImGui::SameLine();
												if (ImGui::Button("Load Settings")) {
												//	ImGui::InsertNotification({ ImGuiToastType_Success, 3000, "Load Settings successfully." });
													LoadConfiggg("C:\\TAXI_hax_config.ini");
												}
												ImGui::SameLine();
												if (ImGui::Button("Exit Hack")) {
													if (Setting::MagicBullet && !Memory::WasBuggedHook) {
														Memory::RestoreHook();
													}
													system("sc stop aow123 & sc delete aow123");
													unload = true;
													exit(0);
												}
												ImGui::PopItemWidth();
												ImGui::Spacing();



												// Get the expiration time from KeyAuthApp.user_data.expiry
												struct tm expiration_time = bestauthApp.user_data.expiry;

												// Convert the expiration time to a time_t value and get the current time
												time_t rawtime;
												time(&rawtime);
												struct tm* current_time = localtime(&rawtime);

												// Calculate the remaining time in seconds
												double remaining_seconds = difftime(mktime(&expiration_time), mktime(current_time));

												int remaining_days = static_cast<int>(remaining_seconds / (60 * 60 * 24));
												int remaining_hours = static_cast<int>((remaining_seconds / (60 * 60)) - (remaining_days * 24));
												int remaining_minutes = static_cast<int>((remaining_seconds / 60) - (remaining_days * 24 * 60) - (remaining_hours * 60));
												int remaining_weeks = static_cast<int>(remaining_days / 7);
												remaining_days %= 7;

												char buffer[32];
												strftime(buffer, sizeof(buffer), "%b %d, %Y", &expiration_time);
												ImGui::SetCursorPosX(10.0f);
												ImGui::Text("Key Expires Date:");
												ImGui::SameLine();
												ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f)); // red color
												ImGui::Text("%s", buffer);
												ImGui::PopStyleColor();
												// Color Pickers
												///ImGui::Text("Customize Colors:");
												///ImGui::Spacing();
												///ImGui::ColorEdit4("Text Color", (float*)&textColor, ImGuiColorEditFlags_NoInputs);
												///ImGui::ColorEdit4("Head Color", (float*)&headColor, ImGuiColorEditFlags_NoInputs);
												///ImGui::ColorEdit4("Area Color", (float*)&areaColor, ImGuiColorEditFlags_NoInputs);
												///ImGui::ColorEdit4("Body Color", (float*)&bodyColor, ImGuiColorEditFlags_NoInputs);
												///ImGui::ColorEdit4("Pops Color", (float*)&popsColor, ImGuiColorEditFlags_NoInputs);
												///ImGui::ColorEdit4("Background Color", (float*)&bgColor, ImGuiColorEditFlags_NoInputs);

												ImGui::EndTabItem();
											}

											ImGui::EndTabBar();
										}
										ImGui::EndChild();
										ImGui::EndTabItem();
									}



									










									ImGui::EndTabBar();
								}

								
							}

							ImGui::End();
							
							// Render toasts on top of everything, at the end of your code!
							// You should push style vars here
							ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.f);
							ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(43.f / 255.f, 43.f / 255.f, 43.f / 255.f, 100.f / 255.f));
							
							//ImGui::RenderNotifications();
							ImGui::PopStyleVar(1); // Don't forget to Pop()
							ImGui::PopStyleColor(1);
						}
					}

					ImGui::PopFont();
					ImGui::PushFont(DX11::ImGui_DX11::Arial);
					if (lage == 1)
					{
						///
						if (ImGui::Begin("HACK TAXI", 0, Flags))
						{
							//ImGui::PushFont(DX11::ImGui_DX11::Arial);
							if (Setting::loginn)
							{
								if (ImGui::BeginTabBar(u8"NO"))
								{

									if (ImGui::BeginTabItem( u8" ﺭﺎﺒﺧﺃ"))
									{

										ImVec2 originalPos = ImGui::GetCursorPos();

										ImGui::SetCursorPosY(210);
										ImGui::SetCursorPosX(203);

										// تكبير الصورة إلى أبعاد جديدة أكبر
										ImGui::Image((PVOID)DX11::mrboot, ImVec2(366, 300)); // استخدم أبعاد أكبر هنا

										ImGui::SetCursorPos(originalPos);

										ImGui::Spacing();
										ImGui::SetCursorPosX({ 10.0f });
										ImGui::Text(u8"ﺭﺍﺪﺻﺃ ﺮﺧﺃ ﻰﻟﺍ ﻪﺘﺜﻳﺪﺤﺗ ﻢﺗ");

										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SetCursorPosX({ 10.0f });

										// تعيين اللون الأزرق للنص
										ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.5f, 1.0f, 1.0f));
										// استخدام Selectable لسهولة النقر
										if (ImGui::Selectable(u8"ﺕﺎﻣﻮﻠﻌﻤﻟﺍ ﻦﻣ ﺪﻳﺰﻤﻟ ﺎﻨﻫ ﺮﻘﻧﺍ", false, ImGuiSelectableFlags_DontClosePopups))
										{
											ShellExecute(NULL, L"open", L"https://your-link-here.com", NULL, NULL, SW_SHOWNORMAL);
										}

										// تغيير شكل الماوس إلى اليد إذا كان الماوس فوق العنصر
										if (ImGui::IsItemHovered())
										{
											ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
										}

										ImGui::PopStyleColor();

										ImGui::Spacing();
										ImGui::SetCursorPosX({ 10.0f });
										ImGui::Text(u8"ﺔﻤﻠﺧﻼﻣ:");
										ImGui::SetCursorPosX({ 10.0f });
										ImGui::Text(u8"ﺔﻣﺪﺘﻣﻻا ﺔﺤﻴﺣ ﻞﺒﻗ ﺔﻣﻮﻜﺤﻤﻟا ﺔﻤﻟﺎﻛ ﺪﻤﺘﻌﺗ ﻼﻋﻷا.");

										ImGui::EndTabItem();
									}

									if (ImGui::BeginTabItem(u8" ﻒﺸــــــﻜﻟﺍ"))
									{

										// استخدم BeginChild لفصل العناصر وتجنب التداخل
										ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

										// عرض الصورة كخلفية
										ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
										ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
										ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

										// إعداد المسافة بين الصورة والعناصر الأخرى
										ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة

										if (ImGui::BeginTabBar("ESP Tabs"))
										{
											if (ImGui::BeginTabItem(u8"ﺐﻋﻻ"))
											{
												ImGui::Checkbox(u8" ﻭﺪﻌﻟﺍ ﻢﺳﺍ ﺭﺎﻬﻇﺇ", &Setting::pname);
												ImGui::Checkbox(u8" ﻭﺪﻌﻠﻟ ﻲﻤﻈﻌﻟﺍ ﻞﻜﻴﻬﻟﺍ ﻢﺳﺭ", &Setting::playerBone);
												ImGui::Checkbox(u8"ﻭﺪﻌﻠﻟ ﻲﻤﻈﻌﻟﺍ ﻞﻜﻴﻬﻟﺍ ﻢﺳﺭ", &Setting::pline);
												ImGui::Checkbox(u8" ﺐﻋﻼﻟﺍ ﻕﻭﺪﻨﺻ ﻢﺳﺭ", &Setting::pcorner);
												ImGui::Checkbox(u8" ﺕﺎﺒﻛﺮﻤﻟﺍ ﺽﺮﻋ", &Setting::Vehicle);
												ImGui::Checkbox(u8"ﻡﻼﻋﻷﺍ ﻢﺳﺭ", &Setting::pflag);
												ImGui::Checkbox(u8" ﺎﻬﻟﻮﺣ ﻭﺪﻌﻟﺍ ﺭﺎﻬﻇﺇ", &Setting::TotalEnemy);
												ImGui::Checkbox(u8" ﺭﺍﺩﺍﺮﻟﺍ ﻢﺳﺭ", &Setting::radar);
												ImGui::Checkbox(u8" ﺔﺒﻌﻠﻟﺍ ﺕﺎﻣﻮﻠﻌﻣ ﻢﺳﺭ", &Setting::gameinfo);
												ImGui::Checkbox(u8" ﻭﺪﻌﻟﺍ ﺔﻓﺎﺴﻣ ﺭﺎﻬﻇﺇ", &Setting::plyrdistance);
												ImGui::Checkbox(u8" ﻭﺪﻌﻟﺍ ﺔﺤﺻ ﺭﺎﻬﻇﺇ", &Setting::phealth);
												ImGui::Checkbox(u8" ﻭﺪﻌﻟﺍ ﺡﻼﺳ ﺽﺮﻋ", &Setting::playerweapon);
												ImGui::Separator();



												if (Setting::pname) {
													if (ImGui::TreeNode(u8"ﻢﺳﻻﺍ"))
													{
														ImGui::Indent();
														ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 50); // Adjust this value as needed
														ImGui::Text(u8"ﺺﻨﻟﺍ ﻥﻮﻟ ");
														ImGui::SameLine();

														ImGui::ColorEdit4("", (float*)&Colors::playername);
														ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 50); // Adjust this value as needed
														ImGui::Text("Text size ");
														ImGui::SameLine();
														ImGui::SliderInt("###4", &nsize, 1, 50);
														ImGui::Unindent();
														ImGui::TreePop();
													}
												}






												if (Setting::playerBone)
												{
													if (ImGui::TreeNodeEx(u8" ﻭﺪﻌﻠﻟ ﻲﻤﻈﻌﻟﺍ ﻞﻜﻴﻬﻟﺍ"))
													{
														ImGui::Indent();
														ImGui::BulletText(u8"ﻲﻤﻈﻌﻟﺍ ﻞﻜﻴﻬﻟﺍ ﻥﻮﻟ");
														//ImGui::SameLine();
														const char* Emu[] = { u8"ﺮﻴﺼﻘﺗ" , u8"ﻖﻳﺮﻔﻟﺍ ﻑﺮﻌﻣ" };

														const char* combo_label = Emu[skelee];
														if (ImGui::BeginCombo(u8" lol", combo_label, ImGuiComboFlags_HeightSmall))
														{
															for (int n = 0; n < IM_ARRAYSIZE(Emu); n++)
															{
																const bool is_selected = (skelee == n);
																if (ImGui::Selectable(Emu[n], is_selected))
																	skelee = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															if (skelee == 0);
															//Setting::skele = true;
															else if (skelee == 1);
															//Setting::skele = false;


															ImGui::EndCombo();
														}
														if (skelee == 1)
														{
															ImGui::BulletText(u8"Color ");
															//ImGui::SameLine();
															ImGui::ColorEdit4(u8" color", (float*)&Colors::skelec, ImGuiColorEditFlags_NoLabel);
														}
														ImGui::BulletText(u8"Thickness ");
														//ImGui::SameLine();
														ImGui::SliderFloat(u8"Bone size", &Setting::pbonesize, 0.100f, 3.00f);
														ImGui::Unindent();
														ImGui::TreePop();
													}
												}

												if (Setting::pline)
												{
													if (ImGui::TreeNodeEx(u8" ﻭﺪﻌﻟﺍ ﻂﺧ"))
													{
														ImGui::Indent();
														ImGui::BulletText(u8"ﻂﺨﻟﺍ ﻥﻮﻟ");
														//ImGui::SameLine();
														const char* Emu1[] = { u8"ﻖﻳﺮﻔﻟﺍ ﻑﺮﻌﻣ", u8"ﺮﻴﺼﻘﺗ" };

														const char* combo_label = Emu1[linne];
														if (ImGui::BeginCombo(u8" loll", combo_label, ImGuiComboFlags_HeightSmall))
														{
															for (int n = 0; n < IM_ARRAYSIZE(Emu1); n++)
															{
																const bool is_selected = (linne == n);
																if (ImGui::Selectable(Emu1[n], is_selected))
																	linne = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															if (linne == 0);
															//Setting::skele = true;
															else if (linne == 1);
															//Setting::skele = false;


															ImGui::EndCombo();
														}
														if (linne == 1)
														{
															ImGui::BulletText(u8"ﻂﺨﻟﺍ ﻥﻮﻟ ");
															//ImGui::SameLine();
															ImGui::ColorEdit4(u8" 1ﻥﻮﻠﻟﺍ", (float*)&Colors::playerline, ImGuiColorEditFlags_NoLabel);
														}
														ImGui::BulletText(u8"ﺔﻛﺎﻤﺳ ");
														//ImGui::SameLine();
														ImGui::SliderFloat(u8"ﻂﺨﻟﺍ ﻢﺠﺣ", &Setting::plinesize, 0.100f, 3.00f);
														ImGui::Unindent();
														ImGui::TreePop();
													}
												}

												if (Setting::pcorner)
												{
													if (ImGui::TreeNodeEx(u8" ﺐﻋﻼﻟﺍ ﻕﻭﺪﻨﺻ"))
													{
														ImGui::Indent();
														ImGui::BulletText(u8"ﺽﺮﻌﻟﺍ ﻊﺿﻭ");
														//ImGui::SameLine();
														const char* Emu3[] = { u8"ﻑﺍﻮﺣ 4", u8"ﻞﻴﻄﺘﺴﻣ" };

														const char* combo_label = Emu3[boxe];
														if (ImGui::BeginCombo(u8" loll11", combo_label, ImGuiComboFlags_HeightSmall))
														{
															for (int n = 0; n < IM_ARRAYSIZE(Emu3); n++)
															{
																const bool is_selected = (boxe == n);
																if (ImGui::Selectable(Emu3[n], is_selected))
																	boxe = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															if (boxe == 0);
															//Setting::skele = true;
															else if (boxe == 1);
															//Setting::skele = false;


															ImGui::EndCombo();
														}
														if (boxe == 0)
														{
															ImGui::BulletText(u8"ﺔﻛﺎﻤﺳ ");
															//ImGui::SameLine();
															ImGui::SliderFloat(u8"###1", &Setting::pcornersize, 0.100f, 2.00f);
														}
														else if (boxe == 1)
														{
															ImGui::BulletText(u8"ﺔﻛﺎﻤﺳ ");
															//ImGui::SameLine();
															ImGui::SliderFloat(u8"###2", &Setting::pfullboxsize, 0.100f, 2.00f);
														}
														ImGui::Unindent();
														ImGui::TreePop();
													}

												}

												ImGui::EndTabItem();
											}
											if (ImGui::BeginTabItem(u8"ﺽﺍﺮﻏﺃ"))
											{


												ImGui::PushID(u8"#0");
												ImGui::ColorEdit4(u8"M416", (float*)&weapon::m16, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"M416", &Setting::Esp_Item_M416);
												ImGui::SameLine();


												Setting::Esp_Item_M416_Icon ? ImGui::Checkbox(u8"ICON", &Setting::Esp_Item_M416_Icon) : ImGui::Checkbox(u8"Text", &Setting::Esp_Item_M416_Icon);
												ImGui::PopID();

												ImGui::PushID(u8"#1");
												ImGui::ColorEdit4(u8"AKM", (float*)&weapon::AKM, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"AKM", &Setting::Esp_Item_AKM);
												ImGui::SameLine();
												Setting::Esp_Item_AKM_Icon ? ImGui::Checkbox(u8"ICON", &Setting::Esp_Item_AKM_Icon) : ImGui::Checkbox(u8"Text", &Setting::Esp_Item_AKM_Icon);
												ImGui::PopID();

												ImGui::ColorEdit4(u8"SCAR", (float*)&weapon::scarl, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"SCAR-L", &Setting::Esp_Item_SCARL);

												ImGui::ColorEdit4(u8"FAMAS", Setting::Esp_Item_FAMAS_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"FAMAS", &Setting::Esp_Item_FAMAS);
												ImGui::PushID(u8"#2");
												ImGui::ColorEdit4(u8"M762", Setting::Esp_Item_M762_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"M762", &Setting::Esp_Item_M762);
												ImGui::SameLine();

												Setting::Esp_Item_M762_Icon ? ImGui::Checkbox(u8"ICON", &Setting::Esp_Item_M762_Icon) : ImGui::Checkbox(u8"Text", &Setting::Esp_Item_M762_Icon);

												ImGui::PopID();
												ImGui::ColorEdit4(u8"Mk14", Setting::Esp_Item_Mk14_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Mk14", &Setting::Esp_Item_Mk14);

												ImGui::ColorEdit4(u8"DP28", Setting::Esp_Item_DP28_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"DP28", &Setting::Esp_Item_DP28);
												ImGui::ColorEdit4(u8"AMW", (float*)&weapon::AWM, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"AWM", &Setting::Esp_Item_Awm);

												ImGui::ColorEdit4(u8"AMR", Setting::Esp_Item_SniperAMR_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"AMR Sniper", &Setting::Esp_Item_SniperAMR);

												ImGui::ColorEdit4(u8"AMRb", Setting::Esp_Item_BulletAMR_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"AMR Bullet", &Setting::Esp_Item_BulletAMR);


												ImGui::PushID(u8"#3");
												ImGui::ColorEdit4(u8"M24", (float*)&weapon::M24, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"M24", &Setting::Esp_Item_M24);
												ImGui::SameLine();

												Setting::Esp_Item_M24_Icon ? ImGui::Checkbox(u8"ICON", &Setting::Esp_Item_M24_Icon) : ImGui::Checkbox(u8"Text", &Setting::Esp_Item_M24_Icon);
												ImGui::PopID();
												ImGui::ColorEdit4(u8"kar98", (float*)&weapon::kar98, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"KAR98", &Setting::Esp_Item_Kar98k);
												ImGui::PushID(u8"#4");
												ImGui::ColorEdit4(u8"Flare", (float*)&weapon::Flaregun, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Flare Gun", &Setting::Esp_Item_FlareGun);
												ImGui::SameLine();
												//	ImGui::Checkbox(u8"ICON", &Setting::Esp_Item_M416);
												Setting::Esp_Item_FlareGun_Icon ? ImGui::Checkbox(u8"ICON", &Setting::Esp_Item_FlareGun_Icon) : ImGui::Checkbox(u8"Text", &Setting::Esp_Item_FlareGun_Icon);
												ImGui::PopID();
												ImGui::ColorEdit4(u8"Flareg", (float*)&weapon::Flare, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Flare", &Setting::Esp_Item_Flare);


												ImGui::ColorEdit4(u8"Airdrop", (float*)&weapon::Airdrop, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"AirDrop", &Setting::airdrop);

												ImGui::ColorEdit4(u8"Armor 3", Setting::Esp_Item_Armor3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Armor 3", &Setting::Esp_Item_Armor3);

												ImGui::ColorEdit4(u8"Bag 3", Setting::Esp_Item_Bag3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Bag 3", &Setting::Esp_Item_Bag3);

												ImGui::ColorEdit4(u8"Helmet 3", Setting::Esp_Item_Helmet3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Helmet 3", &Setting::Esp_Item_Helmet3);


												ImGui::ColorEdit4(u8"Helmet 3", (float*)&weapon::AWMimmo, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"AWM immo", &Setting::Esp_Item_Awmimo);

												ImGui::ColorEdit4(u8"Dead-Box ", (float*)&Colors::deadbox, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Dead-Box", &Setting::deadbox);

												ImGui::ColorEdit4(u8"Dead-Boxi ", (float*)&Colors::deadboxitem, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Dead-Box-list", &Setting::playerdeadbox);

												ImGui::ColorEdit4(u8"air-Boxi ", (float*)&Colors::airdropitem, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"AirDrop-lists", &Setting::airdropitem);

												ImGui::SliderFloat(u8"Item-Box Distance", &Setting::ItemMaxDistance, 0, 350, "%.f");

												ImGui::ColorEdit4(u8"Extended QuickDraw", Setting::Esp_Item_exquic_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Extended QuickDraw", &Setting::Esp_Item_exquic);
												ImGui::SameLine();
												ImGui::ColorEdit4(u8"Helmet 1", Setting::Esp_Item_Helmet1_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Helmet 1", &Setting::Esp_Item_Helmet1);

												ImGui::ColorEdit4(u8"Helmet 2", Setting::Esp_Item_Helmet2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Helmet 2", &Setting::Esp_Item_Helmet2);

												ImGui::ColorEdit4(u8"Bag 1", Setting::Esp_Item_Bag1_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Bag 1", &Setting::Esp_Item_Bag1);

												ImGui::ColorEdit4(u8"Bag 2", Setting::Esp_Item_Bag2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Bag 2", &Setting::Esp_Item_Bag2);

												ImGui::ColorEdit4(u8"Armor 1", Setting::Esp_Item_Armor1_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Armor 1", &Setting::Esp_Item_Armor1);

												ImGui::ColorEdit4(u8"Armor 2", Setting::Esp_Item_Armor2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Armor 2", &Setting::Esp_Item_Armor2);

												ImGui::ColorEdit4(u8"G36C", (float*)&Setting::Esp_Item_G36C_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"G36C", &Setting::Esp_Item_G36C);

												ImGui::ColorEdit4(u8"QBZ", (float*)&Setting::Esp_Item_QBZ_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"QBZ", &Setting::Esp_Item_QBZ);

												ImGui::ColorEdit4(u8"QBU", (float*)&Setting::Esp_Item_QBU_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"QBU", &Setting::Esp_Item_QBU);

												ImGui::ColorEdit4(u8"SLR", (float*)&Setting::Esp_Item_SLR_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"SLR", &Setting::Esp_Item_SLR);

												ImGui::ColorEdit4(u8"SKS", (float*)&Setting::Esp_Item_SKS_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"SKS", &Setting::Esp_Item_SKS);

												ImGui::ColorEdit4(u8"Mini14", (float*)&Setting::Esp_Item_Mini14_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Mini14", &Setting::Esp_Item_Mini14);

												ImGui::ColorEdit4(u8"PP19", (float*)&Setting::Esp_Item_PP19_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"PP19", &Setting::Esp_Item_PP19);

												ImGui::ColorEdit4(u8"Tommy", (float*)&Setting::Esp_Item_TommyGun_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Tommy Gun", &Setting::Esp_Item_TommyGun);

												ImGui::ColorEdit4(u8"MP5K", (float*)&Setting::Esp_Item_MP5K_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"MP5K", &Setting::Esp_Item_MP5K);

												ImGui::ColorEdit4(u8"UMP9", (float*)&Setting::Esp_Item_UMP9_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"UMP9", &Setting::Esp_Item_UMP9);

												ImGui::ColorEdit4(u8"Vector", (float*)&Setting::Esp_Item_Vector_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Vector", &Setting::Esp_Item_Vector);

												ImGui::ColorEdit4(u8"Uzi", (float*)&Setting::Esp_Item_Uzi_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Uzi", &Setting::Esp_Item_Uzi);

												ImGui::ColorEdit4(u8"762mm", (float*)&Setting::Esp_Item_762mm_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"7.62mm", &Setting::Esp_Item_762mm);

												ImGui::ColorEdit4(u8"556mm", (float*)&Setting::Esp_Item_556mm_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"556mm", &Setting::Esp_Item_556mm);

												ImGui::ColorEdit4(u8"9mm", (float*)&Setting::Esp_Item_9mm_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"9mm", &Setting::Esp_Item_9mm);

												ImGui::ColorEdit4(u8"45ACP", (float*)&Setting::Esp_Item_45ACP_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"45ACP", &Setting::Esp_Item_45ACP);

												ImGui::ColorEdit4(u8"Holo", (float*)&Setting::Esp_Item_Holo_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Holo", &Setting::Esp_Item_Holo);

												ImGui::ColorEdit4(u8"RedDot", (float*)&Setting::Esp_Item_Holo_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"RedDot", &Setting::Esp_Item_Holo);


												ImGui::ColorEdit4(u8"Mk47-Mutant", (float*)&Setting::Esp_Item_Mk47Mutant_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Mk47-Mutant", &Setting::Esp_Item_Mk47Mutant);
												ImGui::SameLine();
												ImGui::ColorEdit4(u8"Frag", Setting::Esp_Item_Frag_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Frag", &Setting::Esp_Item_Frag);

												ImGui::ColorEdit4(u8"Smoke", Setting::Esp_Item_Smoke_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Smoke", &Setting::Esp_Item_Smoke);

												ImGui::ColorEdit4(u8"Molotof", Setting::Esp_Item_Molotof_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Molotof", &Setting::Esp_Item_Molotof);
												ImGui::SameLine();
												ImGui::ColorEdit4(u8"Med Kit", Setting::Esp_Item_MedKit_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Med Kit", &Setting::Esp_Item_MedKit);

												ImGui::ColorEdit4(u8"First Aid Kit", Setting::Esp_Item_FirstAidKit_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"First Aid Kit", &Setting::Esp_Item_FirstAidKit);

												ImGui::ColorEdit4(u8"Bandage", Setting::Esp_Item_Bandage_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Bandage", &Setting::Esp_Item_Bandage);

												ImGui::ColorEdit4(u8"Painkiller", Setting::Esp_Item_Painkiller_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Painkiller", &Setting::Esp_Item_Painkiller);

												ImGui::ColorEdit4(u8"Energy Drink", Setting::Esp_Item_EnergyDrink_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Energy Drink", &Setting::Esp_Item_EnergyDrink);

												ImGui::ColorEdit4(u8"Adrenaline Syringe", Setting::Esp_Item_AdrenalineSyringe_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Adrenaline Syringe", &Setting::Esp_Item_AdrenalineSyringe);

												ImGui::EndTabItem();
											}
											if (ImGui::BeginTabItem(u8"ﺕﺎﺒﻛﺮﻣ"))
											{
												ImGui::Checkbox(u8"Important Items", &Setting::impitems);

												ImGui::Checkbox(u8"All Items", &Setting::allitemss);

												ImGui::Checkbox(u8"Health items", &Setting::healthitem);

												ImGui::Checkbox(u8"Scope items", &Setting::scope);

												ImGui::ColorEdit4(u8"Vehiclescol", (float*)&Colors::vehicle, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Vehicles", &Setting::Vehicle);
												ImGui::SameLine();
												ImGui::Checkbox(u8"HP", &Setting::hp);
												ImGui::SameLine();
												ImGui::Checkbox(u8"FUEL", &Setting::feul);

												ImGui::ColorEdit4(u8"bomb", (float*)&Colors::Granadeswarn, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"Bomb Items", &Setting::BombAlert);


												ImGui::EndTabItem();
											}
											if (ImGui::BeginTabItem(u8"ﺔﻈﺣﻼﻣ"))
											{
												ImGui::ColorEdit4(u8"2X", Setting::Esp_Item_x2_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"x2", &Setting::Esp_Item_x2);

												ImGui::ColorEdit4(u8"3X", Setting::Esp_Item_x3_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"x3", &Setting::Esp_Item_x3);

												ImGui::ColorEdit4(u8"4X", Setting::Esp_Item_x4_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"x4", &Setting::Esp_Item_x4);

												ImGui::ColorEdit4(u8"6X", Setting::Esp_Item_x6_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"x6", &Setting::Esp_Item_x6);

												ImGui::ColorEdit4(u8"8X", Setting::Esp_Item_x8_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
												ImGui::SameLine();
												ImGui::Checkbox(u8"x8", &Setting::Esp_Item_x8);
												ImGui::EndTabItem();
											}
											ImGui::EndTabBar();
										}
										ImGui::EndChild();
										ImGui::EndTabItem();
									}

									if (ImGui::BeginTabItem(u8" ﺓﺮﻛﺍﺫ")) {
										// استخدم BeginChild لفصل العناصر وتجنب التداخل
										ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

										// عرض الصورة كخلفية
										ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
										ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
										ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

										// إعداد المسافة بين الصورة والعناصر الأخرى
										ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة
										if (ImGui::BeginTabBar(u8"ﺓﺮﻛﺍﺫ")) {

											if (ImGui::BeginTabItem( u8" ﺔﻨﻣﺁ ﺓﺮﻛﺍﺫ")) {
												// عنوان القائمة مع لون جذاب
												ImGui::TextColored(ImVec4(0.85f, 0.6f, 0.3f, 1.0f), u8"ﺔﻨﻣﺁ ﺓﺮﻛﺍﺫ");
												ImGui::Separator();  // يرسم الخط الفاصل
												ImGui::Spacing();

												// خيارات التفعيل مع ألوان مختلفة للتفعيل
												if (ImGui::Checkbox(u8"ﺔﻳﺮﺤﺳ ﺔﺻﺎﺻﺭ", &Setting::MagicBulletticked)) {
													if (Setting::MagicBulletticked) {
														//ImGui::InsertNotification({ ImGuiToastType_Success, 3000, XorStr(u8"ﺔﻳﺮﺤﺴﻟﺍ ﺔﺻﺎﺻﺮﻟﺍ ﻞﻴﻌﻔﺗ ﻢﺗ!!").c_str() });
													}
													else {
													//	ImGui::InsertNotification({ ImGuiToastType_Warning, 3000, XorStr(u8"ﺔﻳﺮﺤﺴﻟﺍ ﺔﺻﺎﺻﺮﻟﺍ ﻂﻴﺸﻨﺗ ﺀﺎﻐﻟﺇ ﻢﺗ!").c_str() });
													}
												}

												if (Setting::MagicBulletticked) {
													ImGui::TextColored(ImVec4(0.85f, 0.6f, 0.3f, 1.0f), "Magic Bullet Configuration:");
													ImGui::PushItemWidth(250);



													//const char* combo_label = aimb[Setting::curraim];
													const char* aimb[] = { u8"ﺱﺃﺭ", u8"ﻢﺴﺟ", u8"ﺽﻮﺤﻟﺍ", u8"ﻲﻟﺁ" };
													const char* combo_label = aimb[Setting::curraim];
													if (ImGui::BeginCombo(" loll123", combo_label, ImGuiComboFlags_HeightSmall))
													{
														for (int n = 0; n < IM_ARRAYSIZE(aimb); n++)
														{
															const bool is_selected = (Setting::curraim == n);
															if (ImGui::Selectable(aimb[n], is_selected))
																Setting::curraim = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}




													ImGui::Checkbox(u8"ﻦﻣﺁ ﺮﺤﺳ", &Setting::MagicRangeCheck);
													if (Setting::MagicRangeCheck) {
														ImGui::SliderInt(u8"ﺮﺤﺴﻟﺍ ﺔﻋﻮﻤﺠﻣ", &Setting::magicrange, 40, 100);
													}

													ImGui::Checkbox(u8"ﺕﺎﺗﻮﺑﻭﺮﻟﺍ ﻲﻄﺨﺗ", &Setting::SkipBots);
													ImGui::Checkbox(u8"ﺖﻗﺮﻃ ﻲﻄﺨﺗ", &Setting::SkipKnocked);
													ImGui::Checkbox(u8"ﺔﻳﺅﺮﻟﺍ ﻝﺎﺠﻣ ﺓﺮﺋﺍﺩ", &Setting::fovcircle);
													ImGui::SliderFloat(u8"ﺔﻳﺅﺮﻟﺍ ﻝﺎﺠﻣ ﺓﺮﺋﺍﺩ ﻢﺠﺣ", &Setting::fovcircleredus, 30.0f, 100.0f);

													ImGui::Separator();
													ImGui::Spacing();

													ImGui::TextColored(ImVec4(0.85f, 0.6f, 0.3f, 1.0f), u8"ﺕﻮﺑﻭﺮﻟﺍ ﻑﺪﻬﻟﺍ ﺕﺎﻴﺋﺮﻣ ﻦﻳﻮﻜﺗ:");
													ImGui::Checkbox(u8"ﻑﺪﻬﻟﺍ ﻂﺧ", &Setting::pline);
													ImGui::Checkbox(u8"ﻲﻟﺎﺤﻟﺍ ﻑﺪﻬﻟﺍ ﻊﺿﻮﻣ ﺭﺎﻬﻇﺇ", &Setting::aimbotposition);
												}

												ImGui::EndTabItem();
											}

											if (ImGui::BeginTabItem(u8" ﺮﻄﺨﻟﺍ ﺓﺮﻛﺍﺫ")) {
												ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), u8"ﺮﻄﺨﻟﺍ ﺓﺮﻛﺍﺫ ﺕﺍﺭﺎﻴﺧ");
												ImGui::Separator();

												// هنا يمكنك إضافة محتوى قائمة "Danger Memory"

												ImGui::EndTabItem();
											}

											ImGui::EndTabBar();
										}
										ImGui::EndChild();
										ImGui::EndTabItem();
									}



									std::string kglaed = GetAOWPath();
									std::string filePath = kglaed + "\\inter\\modskin.ini";

									if (FileExist(filePath)) {
									
										if (ImGui::BeginTabItem(u8" ﺕﺎﻨــــــــــــــــﻜﺳ"))
										{
											// استخدم BeginChild لفصل العناصر وتجنب التداخل
											ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

											// عرض الصورة كخلفية
											ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
											ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
											ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

											// إعداد المسافة بين الصورة والعناصر الأخرى
											ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة

											CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)modspiii, nullptr, NULL, nullptr);
											if (ImGui::BeginTabBar("Magic Tabs"))
											{
												if (ImGui::BeginTabItem(u8" ﺕﻻﺪﺑ ﻦﻜﺳ"))
												{
													ImGui::BeginTable("SkinXSuitTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();

													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("X-Suit");
													ImGui::TableNextColumn();

													const char* xsuity[] = { "NO SKIN", "Blood Raven X-Suit", "Golden Pharaoh X-Suit", "Avalanche X-suit", "Irresidence X-suit", "Poseidon X-suit", "Arcane Jester X-suit", "Silvanus X-Suit","Fiore X-Suit","Marmoris X-Suit","Great Indian Warrior","Anniversary Unicorn","Foxy Flare","Red Bowtie","Evangelion Shinji","Evangelion Rei","Evangelion Asuka","Evangelion Mari","Evangelion Kaworu","Flamewraith","Ignis X-Suit","Inferno Fiend",
													"Serene Lumina","Rahma Riad","Winter Highness","Psychophage","Myriam Fares Festival","Myriam Fares Warrior","Super Saiyan Blue Son","Underworld Guide","Rhythm Rider","Infected Patient","Glacier Set","Dystopian Survivor","The Fool Set",
													"Bunny Swimsuit (Pink)" };
													const char* combo_label = xsuity[xsuit];
													ImGui::SetCursorPosX({ 490.0f });
													//ImGui::SetCursorPosX(ImGui::GetWindowWidth() - 300.0f);
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("X-SUIT Combo", combo_label, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(xsuity); n++)
														{
															const bool is_selected = (xsuit == n);
															if (ImGui::Selectable(xsuity[n], is_selected))
																xsuit = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
													ImGui::Separator();
												}

												if (ImGui::BeginTabItem(u8" ﺔﻄﻨﺷ ﻦﻜﺳ"))
												{
													ImGui::BeginTable("BackpackSkinsTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();

													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("Backpack");
													ImGui::TableNextColumn();

													const char* backpack1[] = { "NO SKIN","Blood Raven","Golden Pharaoh","The Fool","Dazzling Youth","BAPE X PUBGM CAMO","Serene Lumina" };
													const char* combo_label2 = backpack1[back1];

													ImGui::SetCursorPosX({ 490.0f });
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("Backpack Combo", combo_label2, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(backpack1); n++)
														{
															const bool is_selected = (back1 == n);
															if (ImGui::Selectable(backpack1[n], is_selected))
																back1 = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
												}

												if (ImGui::BeginTabItem(u8" ﺕﺍﺭﺎﻴﺳ ﻦﻜﺳ")) {

													if (ImGui::BeginTable("carTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable)) {
														ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
														ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
														ImGui::TableHeadersRow();
														// Add weapon and skin combos
														ImGui::TableNextRow();
														ImGui::TableNextColumn();
														ImGui::Text("Dacia");
														ImGui::TableNextColumn();
														const char* Dacia2[] = { "NO SKIN", "Midknight Dacia (Lv. 4)", "Ghost Gleam", "Ghost Rosa", "Lamborghini Estoque Oro", "Ghillie Lion", "Taiyaki" };
														const char* Dacii2 = Dacia2[daciaskin];
														ImGui::SetCursorPosX({ 490.0f });
														ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
														if (ImGui::BeginCombo("#Dacia1", Dacii2, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
														{
															for (int n = 0; n < IM_ARRAYSIZE(Dacia2); n++)
															{
																const bool is_selected = (daciaskin == n);
																if (ImGui::Selectable(Dacia2[n], is_selected))
																	daciaskin = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															ImGui::EndCombo();
														}


														ImGui::TableNextRow();
														ImGui::TableNextColumn();
														ImGui::Text("UAZ");
														ImGui::TableNextColumn();
														const char* UAZF[] = { "NO SKIN", "Maserati Levante", "Maserati Levante Firmamento", "Aston Martin DBX707","BAPE X PUBGM","Bentley Bentayga Azure","Dodge Hornet" };
														const char* UAZ3 = UAZF[UAZSK];

														ImGui::SetCursorPosX({ 490.0f });
														ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
														if (ImGui::BeginCombo("#UAZF", UAZ3, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
														{
															for (int n = 0; n < IM_ARRAYSIZE(UAZF); n++)
															{
																const bool is_selected = (UAZSK == n);
																if (ImGui::Selectable(UAZF[n], is_selected))
																	UAZSK = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															ImGui::EndCombo();
														}



														ImGui::TableNextRow();
														ImGui::TableNextColumn();
														ImGui::Text("Cope");
														ImGui::TableNextColumn();
														const char* Cope333[] = { "NO SKIN", "Bugatti La Voiture Noire", "Maserati MC20 Rosso", "McLaren 570S","McLaren 570S (Pearlescent)","Koenigsegg Jesko","Pagani Imola (Grigio Montecarlo)","Pagani Imola (Crystal Clear)","Dodge" };
														const char* Copeff = Cope333[copu33];

														ImGui::SetCursorPosX({ 490.0f });
														ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
														if (ImGui::BeginCombo("#Cope333", Copeff, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
														{
															for (int n = 0; n < IM_ARRAYSIZE(Cope333); n++)
															{
																const bool is_selected = (copu33 == n);
																if (ImGui::Selectable(Cope333[n], is_selected))
																	copu33 = n;
																if (is_selected)
																	ImGui::SetItemDefaultFocus();
															}
															ImGui::EndCombo();
														}














														ImGui::EndTable();

													}


													ImGui::EndTabItem();



												}
												if (ImGui::BeginTabItem(u8" ﺫﻮﺧ ﻦﻜﺳ"))
												{
													ImGui::BeginTable("HelmetSkinsTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();

													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("Helmet");
													ImGui::TableNextColumn();

													const char* helmet22[] = { "NO SKIN","Inferno Rider ","Glacier Helmet","PUBLING Helmet","Galactic Helmet","Masked Psychic","Magma Skull","Joyful Kitten","Godzilla Helmet",
													"Ghillie Lion","Dream Idol","Moon Bunny" };
													const char* cossss = helmet22[hoho];

													ImGui::SetCursorPosX({ 490.0f });
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("Helmet Combo", cossss, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(helmet22); n++)
														{
															const bool is_selected = (hoho == n);
															if (ImGui::Selectable(helmet22[n], is_selected))
																hoho = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
												}

												if (ImGui::BeginTabItem(u8" ﺓﺭﺎﻴﻄﻟﺍ ﻝﻭﺰﻧ ﻦﻜﺳ")) {

													ImGui::BeginTable("GliderSkinsTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();
													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("Glider Skins");
													ImGui::TableNextColumn();
													const char* Glider1212[] = { "NO SKIN",  "Chilly Perch","Foxy Flare" ,"LINE FRIENDS","Cloudslash","Golden Serpent","Zanmang Loopy","SPY×FAMILY",
													"Dominion Wings","Underworld Vestige" };
													const char* cossss22 = Glider1212[glidersk];

													ImGui::SetCursorPosX({ 490.0f });
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("Glider Combo", cossss22, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(Glider1212); n++)
														{
															const bool is_selected = (glidersk == n);
															if (ImGui::Selectable(Glider1212[n], is_selected))
																glidersk = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
												}

												if (ImGui::BeginTabItem(u8" ﺕﻮﺷﺍﺭﺎﺑ ﻦﻜﺳ")) {

													ImGui::BeginTable("ParachuteSkinsTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable);
													ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.0f);
													ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
													ImGui::TableHeadersRow();
													ImGui::TableNextRow();
													ImGui::TableNextColumn();
													ImGui::Text("Parachute Skins");
													ImGui::TableNextColumn();
													const char* Parachute1212[] = { "NO SKIN", "Bentley","KFC Royale Delight" ,"Phantom Luster","Hardik Sky","Zanmang Loopy","LINE FRIENDS" };
													const char* cossss22f = Parachute1212[Parachuteskin];

													ImGui::SetCursorPosX({ 490.0f });
													ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
													if (ImGui::BeginCombo("Parachute Combo", cossss22f, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
													{
														for (int n = 0; n < IM_ARRAYSIZE(Parachute1212); n++)
														{
															const bool is_selected = (Parachuteskin == n);
															if (ImGui::Selectable(Parachute1212[n], is_selected))
																Parachuteskin = n;
															if (is_selected)
																ImGui::SetItemDefaultFocus();
														}
														ImGui::EndCombo();
													}

													ImGui::EndTable();
													ImGui::EndTabItem();
												}

												if (ImGui::BeginTabItem(u8" ﺔﺤﻠﺳﺃ ﻦﻜﺳ"))
												{
													if (ImGui::BeginTable("WeaponTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable))
													{
														// Display headers
														ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 300.0f);
														ImGui::TableSetupColumn("Skin", ImGuiTableColumnFlags_WidthFixed, 500.0f); // Increased column width
														ImGui::TableHeadersRow();

														struct Weapon {
															const char* name;
															std::vector<const char*> skins;
															int* selected_skin;
														};

														// Define and initialize weapon skin selections

														Weapon weapons[] = {
															{"M416", {"NO SKIN", "Glacier - M416", "The Fool - M416", "Wanderer - M416", "Silver Guru - M416", "Shinobi Kami - M416", "Sealed Nether - M416"}, &m41622},
															{"AKM", {"NO SKIN", "Glacier - AKM", "Starsea Admiral - AKM", "Wandering Tyrant - AKM"}, &akm22},
															{"SCAR-L", {"NO SKIN", "Drop the Bass - SCAR-L", "Thorn of Malice - SCAR-L", "Bloodstained Nemesis - SCAR-L","Serene Lumina"}, &scal_1},
															{"M762", {"NO SKIN", "Luminous Muse", "Starcore", "Stray Rebellion"}, &m7777},
															{"AUG", {"NO SKIN", "Forsaken Glace", "Deep Sea Terror", "Evangelion 4th Angel", "Wandering Circus"}, &AUGSKIN},
															{"GROZA", {"NO SKIN", "Primordial Remnants", "Pumpkin Carol", "River Styx", "Ryomen Sukuna"}, &GROZASKIN},
															{"ACE32", {"NO SKIN", "Icicle Spike", "Mystic Kraken", "Beam Blast"}, &ACE32SKIN},
															{"M16A4", {"NO SKIN", "Skeletal Core", "Seraphic Beacon", "Sweetheart Surge","Aurora Pulse"}, &M16A4SKIN},
															{"P90", {"NO SKIN", "Angry Sheep", "Dancing Prints", "Fairytale Scarecrow","Devious Cybercat"}, &P90SKIN},
															{"Honey", {"NO SKIN", "Vivid Glare", "Sonic Wave", "Squeakology"}, &HoneySKIN},
															{"MG3", {"NO SKIN", "Soaring Dragon", "Sky Huntress", "Night Maiden"}, &MG3SKIN},
															{"MK14", {"NO SKIN", "Gilded Galaxy", "Drakreign", "Phoenix Song"}, &MK14SKIN},
															{"MINI14", {"NO SKIN", "Icicle", "Ethereal Beauty", "Fortune Cat","Gallant Jockey"}, &MINI14SKIN},
															{"AWM", {"NO SKIN", "Flamewave - AWM", "Serpengleam - AWM", "Godzilla - AWM"}, &AWMS},
															{"AMR", {"NO SKIN", "Crimson Ephialtes", "Scorching Blessing"}, &AMRSKIN},
															{"UMP45", {"NO SKIN", "Carnival Waves", "Cryofrost Shard", "Marine Evolution", "Rainbow Stinger"}, &UMPSKIN},
															{"Vector", {"NO SKIN", "Mecha Drake", "Midnight Rose", "Cute Baddie", "Gilded Reaper"}, &VectorF},
															{"UZI", {"NO SKIN", "Savagery", "Ethereal Emblem", "Shimmer Power", "Romantic Moments"}, &UZISKIN},
															{"Pan", {"NO SKIN", "Accolade", "Break Pad", "Chicken Hot", "Faerie Luster"}, &panskin}
														};

														for (int i = 0; i < IM_ARRAYSIZE(weapons); i++)
														{
															const Weapon& weapon = weapons[i];
															ImGui::TableNextRow();
															ImGui::TableNextColumn();
															ImGui::Text("%s", weapon.name);
															ImGui::TableNextColumn();
															ImGui::SetCursorPosX(490.0f);
															ImGui::SetNextItemWidth(210.0f); // Set the width for the combo box
															const char* combo_label = weapon.skins[*weapon.selected_skin];
															std::string combo_name = std::string("#combo_") + weapon.name + std::to_string(i); // Ensure unique combo name
															if (ImGui::BeginCombo(combo_name.c_str(), combo_label, ImGuiComboFlags_HeightLarge | ImGuiComboFlags_PopupAlignLeft))
															{
																for (int n = 0; n < weapon.skins.size(); n++)
																{
																	const bool is_selected = (*weapon.selected_skin == n);
																	if (ImGui::Selectable(weapon.skins[n], is_selected))
																		*weapon.selected_skin = n;
																	if (is_selected)
																		ImGui::SetItemDefaultFocus();
																}
																ImGui::EndCombo();
															}

															// Insert space between rows
															ImGui::Spacing();
															ImGui::Spacing();

															// Draw separator across the table with transparency
															ImGui::TableNextRow(ImGuiTableRowFlags_None, 5.0f); // Adjust the height of the separator row
															ImGui::TableNextColumn();
															ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));  // الأسود الكامل // Red color for the separator with transparency
															ImGui::Separator();
															ImGui::PopStyleColor();
															ImGui::TableNextColumn();
															ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));  // الأسود الكامل// Red color for the separator with transparency
															ImGui::Separator();
															ImGui::PopStyleColor();
														}

														ImGui::EndTable();
													}
													ImGui::EndTabItem();
												}






												ImGui::EndTabBar();
											}
											ImGui::EndChild();
											ImGui::EndTabItem();
										}
									
									
									
									}

									if (ImGui::BeginTabItem(u8" ﺕﺍﺩﺍﺪﻋﺇ"))
									{
										// استخدم BeginChild لفصل العناصر وتجنب التداخل
										ImGui::BeginChild("ChildWindow", ImVec2(0, 0), true);

										// عرض الصورة كخلفية
										ImVec2 image_size = { 777, 500 }; // ضبط حجم الصورة
										ImGui::SetCursorPos(ImVec2(0, 0)); // تعيين الموضع في الأعلى اليسار
										ImGui::Image((PVOID)DX11::photo, image_size); // عرض الصورة بحجم النافذة

										// إعداد المسافة بين الصورة والعناصر الأخرى
										ImGui::SetCursorPos(ImVec2(10, 10)); // ضبط الموضع بعد الصورة

										if (ImGui::BeginTabBar(u8"ﺕﺍﺩﺍﺪﻋﻹﺍ ﺐﻳﻮﺒﺗ ﺕﺎﻣﻼﻋ"))
										{
											if (ImGui::BeginTabItem(u8"ﺔﻴﺴﻴﺋﺮﻟﺍ ﺕﺍﺩﺍﺪﻋﻹﺍ"))
											{
												ImGui::Spacing();

												// Centered Title
												ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.6f);
												ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("ﺔﻴﺴﻴﺋﺮﻟﺍ ﺕﺍﺩﺍﺪﻋﻹﺍ").x) * 0.5f);
												ImGui::TextColored(yellowColor, u8"ﺔﻴﺴﻴﺋﺮﻟﺍ ﺕﺍﺩﺍﺪﻋﻹﺍ");
												ImGui::PopItemWidth();
												ImGui::Spacing();
												ImGui::Separator();
												ImGui::Spacing();

												// Text Size Slider
												const char* languageItems[] = { "English", u8"ﻲﺑﺮﻋ" };

												const char* combo_label = languageItems[lage];
												if (ImGui::BeginCombo(" loll11GGG", combo_label, ImGuiComboFlags_HeightSmall))
												{
													for (int n = 0; n < IM_ARRAYSIZE(languageItems); n++)
													{
														const bool is_selected = (lage == n);
														if (ImGui::Selectable(languageItems[n], is_selected))
															lage = n;
														if (is_selected)
															ImGui::SetItemDefaultFocus();
													}
													if (lage == 0);
													else if (lage == 1);


													ImGui::EndCombo();
												}


												ImGui::PushItemWidth(300);
												ImGui::Text(u8"ﺺﻨﻟﺍ ﻢﺠﺣ");
												ImGui::SliderFloat(u8"##TextSize", &Setting::Normalfontsize, 14.0f, 20.0f, "%.1f");
												ImGui::Spacing();

												// Important Text Size Slider
												ImGui::Text(u8"ﺔﻤﻬﻤ ﻢﺠﺣ");
												ImGui::SliderFloat(u8"##ImportantTextSize", &Setting::fontsize, 14.0f, 20.0f, "%.1f");
												ImGui::Spacing();

												// Update Thread Delay Slider
												ImGui::Text(u8"ﺚﺤﺑﺎﻟﺍ ﺮﻳﺮﺧﺃ");
												ImGui::SliderInt(u8"##UpdateThreadDelay", &Setting::UpdateThreadDelay, 20, 200);
												ImGui::Spacing();

												// ESP Refresh Rate Slider
												ImGui::Text(u8"ﺔﺮﺠﺗﻟﺍ ﺮﺘﻣﻮﻣ");
												ImGui::SliderInt(u8"##EspRefreshRate", &Setting::EspThreadDelay, 5, 16);
												ImGui::Spacing();

												// Address Getter Delay Slider
												ImGui::Text(u8"ﺔﻴﺋﺎﺩﺗﺍ ﺮﻳﺮﺧﺃ ﺏﺍﺿﻋ ﻞﻴﺣﺘﻣ");
												ImGui::SliderInt(u8"##AddressGetterDelay", &Setting::AdreessGetterDelay, 2000, 4000);
												ImGui::Spacing();

												// Anti Stream Screenshot Checkbox
												ImGui::Checkbox(u8"ﺕﺎﻤﺷﻼﺳﻻﺍ ﻡﻨﻣ ﺕﺎﺸﻛﻟﻻﺍ", &Setting::AntiScreenShot);
												if (Setting::AntiScreenShot) {
													SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
												}
												else {
													SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
												}
												ImGui::Spacing();

												// Buttons for Save, Load, and Exit
												ImGui::PushItemWidth(200.0f);
												ImGui::SetCursorPosX((ImGui::GetWindowWidth() - 3 * 210.0f - 10.0f) * 0.5f);
												if (ImGui::Button(u8"ﺕﺍﺩﺍﺪﻋﻹﺍ ﻆﻔﺣ")) {
													//ImGui::InsertNotification({ ImGuiToastType_Success, 3000, u8"ﺭﺎﺸﺘﺨﻣ ﺕﺎﺿﺎﻌﻟﺍ ﺞﻔﺣ." });
													WriteConfigurate("C:\\TAXI_hax_config.ini");
												}
												ImGui::SameLine();
												if (ImGui::Button(u8"ﻞﻴﻤﺤﺘﻟﺍ ﺕﺍﺩﺍﺪﻋﺇ")) {
												//	ImGui::InsertNotification({ ImGuiToastType_Success, 3000, u8"ﺭﺎﺸﺘﺨﻣ ﺕﺎﺿﺎﻌﻟﺍ ﺩﻳﺪﻌﺗ." });
													LoadConfiggg("C:\\TAXI_hax_config.ini");
												}
												ImGui::SameLine();
												if (ImGui::Button(u8"ﺝﻭﺮﺨﻟﺍ ﻕﺍﺮﺘﺧﺍ")) {
													if (Setting::MagicBullet && !Memory::WasBuggedHook) {
														Memory::RestoreHook();
													}
													system("sc stop aow123 & sc delete aow123");
													unload = true;
													exit(0);
												}
												ImGui::PopItemWidth();
												ImGui::Spacing();


												struct tm expiration_time = bestauthApp.user_data.expiry;

												// Convert the expiration time to a time_t value and get the current time
												time_t rawtime;
												time(&rawtime);
												struct tm* current_time = localtime(&rawtime);

												// Calculate the remaining time in seconds
												double remaining_seconds = difftime(mktime(&expiration_time), mktime(current_time));

												int remaining_days = static_cast<int>(remaining_seconds / (60 * 60 * 24));
												int remaining_hours = static_cast<int>((remaining_seconds / (60 * 60)) - (remaining_days * 24));
												int remaining_minutes = static_cast<int>((remaining_seconds / 60) - (remaining_days * 24 * 60) - (remaining_hours * 60));
												int remaining_weeks = static_cast<int>(remaining_days / 7);
												remaining_days %= 7;

												char buffer[32];
												strftime(buffer, sizeof(buffer), "%b %d, %Y", &expiration_time);
												ImGui::SetCursorPosX(10.0f);
												ImGui::Text(u8" ﺩﻮﻜﻟﺍ ﺀﺎﻬﺘﻧﺍ ﺖﻗﻭ:");
												ImGui::SameLine();
												ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f)); // red color
												ImGui::Text("%s", buffer);
												ImGui::PopStyleColor();
												///////// Color Pickers
												///////ImGui::Text(u8"ﻩﻮﻠﻨﻟ ﺺﻴﺧﺮﺘﻣ");
												///////ImGui::Spacing();
												///////ImGui::ColorEdit4(u8"ﺺﻨﻟﺍ ﻥﻮﻧ ﻞﻴﺣﺗ", (float*)&textColor, ImGuiColorEditFlags_NoInputs);
												///////ImGui::ColorEdit4(u8"ﺱﺃﺭﻟﺍ ﻥﻮﻧ ﻞﻴﺣﺗ", (float*)&headColor, ImGuiColorEditFlags_NoInputs);
												///////ImGui::ColorEdit4(u8"ﺔﻴﻘﻁﻻﺍ ﻥﻮﻧ ﻞﻴﺣﺗ", (float*)&areaColor, ImGuiColorEditFlags_NoInputs);
												///////ImGui::ColorEdit4(u8"ﻢﺠﺳﻟﺍ ﻥﻮﻧ ﻞﻴﺣﺗ", (float*)&bodyColor, ImGuiColorEditFlags_NoInputs);
												///////ImGui::ColorEdit4(u8"ﺱﺒﻭﺑﻟﺍ ﻥﻮﻧ ﻞﻴﺣﺗ", (float*)&popsColor, ImGuiColorEditFlags_NoInputs);
												///////ImGui::ColorEdit4(u8"ﺔﻴﺒﻴﺗﺎﻓﻟﺍ ﻥﻮﻧ ﻞﻴﺣﺗ", (float*)&bgColor, ImGuiColorEditFlags_NoInputs);


												ImGui::EndTabItem();
											}

											ImGui::EndTabBar();
										}
										ImGui::EndChild();
										ImGui::EndTabItem();
									}











									ImGui::EndTabBar();
								}


								// Restore the previous font
								
							}
							

							ImGui::End();

							// Render toasts on top of everything, at the end of your code!
							// You should push style vars here
							ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.f);
							ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(43.f / 255.f, 43.f / 255.f, 43.f / 255.f, 100.f / 255.f));
							//ImGui::RenderNotifications();
							ImGui::PopStyleVar(1); // Don't forget to Pop()
							ImGui::PopStyleColor(1);
						}
						}
					ImGui::PopFont();
				}

			}

			if (login)
			{
				if (unload)
				{
					ImGuiIO& Io = ImGui::GetIO();

					//ImGui::SetNextWindowSize(ImVec2(400.0f, 115.0f));
					ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
					ImGui::SetNextWindowSize(ImVec2(250.0f, 100.0f));
					if (ImGui::Begin("####11", 0, Flags2))
					{
						imguipp::CenterText("Are you sure?", 0, 0);
						if (ImGui::Button("OK", { 115.f,25.f }))
						{
							exit(0);
						}
						ImGui::SameLine();
						if (ImGui::Button("Cancel", { 115.f,25.f }))
						{
							unload = false;
						}

						ImGui::End();
					}
				}

				ViewMatrix = Utility::ReadMemoryEx<D3DMATRIX>(Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(Data::ViewMatrixBase) + 0x20) + 0x200);
				Data::CameraCache = Utility::ReadMemoryEx<CameraCacheEntry>(Data::PlayerCameraManager + Offset::PlayerCameraManager1::CameraCache);
				TempAActorList.clear();
				TempAActorList = Data::AActorList;
				DWORD MeshAddv1 = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
				DWORD BodyAddv1 = MeshAddv1 + Offset::BodyAddv;
				DWORD BoneAddv1 = Utility::ReadMemoryEx<DWORD>(MeshAddv1 + Offset::MinLOD) + 48;


				Data::lOCALPLAYERHEAD = Algorithm::GetBoneWorldPosition(BodyAddv1, BoneAddv1 + 5 * 48);
				Data::lOCALPLAYERPosotion = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Data::LocalPlayerAddr + Offset::RootComponent) + Offset::Position);

				if (Setting::ShowSideMenu)
				{
					DrawSideMenu();
					//CallMsg();
				}
			
				
				if (Data::AActorList.size() != 0)
				{

					for (AActor& AActor : Data::AActorList)
					{
						int _dist;
						AActor.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(AActor.Address + Offset::RootComponent) + Offset::Position);

						teamids = AActor.TeamId;
						col = ImColor(teamids, teamids, teamids, 255);
						linescolors = ImVec4(sin(5.f * teamids + 0.f) * 127 + 128 / 255.0f, sin(5.f * teamids + ((2.f * 3.14159265358979323846) / 3)) * 127 + 128 / 255.0f, sin(5.f * teamids + ((4.f * 3.14159265358979323846) / 3)) * 127 + 128 / 255.0f, 255 / 255.0f);
						bonescolors = Colors::playerbone;
						fullboxcolor = Colors::playerbox;
						cornerboxcolor = Colors::playercorner;

						if (Setting::Enenmyaim)
						{
							if (AActor.isAimingAtMe)
							{
								checkaiming = true;
							}
						}
						if (Setting::Enenmyaim)
						{
							if (checkaiming)
							{
								///CallEnemyAimWarning();
							}
						}
						checkaiming = false;


					
						


						if (Setting::dots)
						{
							float S_height = DX11Window::Height;
							float S_width = DX11Window::Width;
							bool shit = false;
							VECTOR3 EntityPos = WorldToRadar(Data::CameraCache.POV.Rotation.Yaw, AActor.Position, Data::CameraCache.POV.Location, NULL, NULL, ToVECTOR3(S_width, S_height, 0), shit);
							int radar_range = 25;
							int x, y;
							x = EntityPos.X;
							y = EntityPos.Y;

							VECTOR3 angle{};
							VECTOR3 temmp = ToVECTOR3((float)(S_width / 2) - x, (float)(S_height / 2) - y, 0.f);

							VectorAnglesRadar(temmp, angle);

							const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
							const auto new_point_x = (S_width / 2) + (radar_range) / 2 * 8 * cosf(angle_yaw_rad);
							const auto new_point_y = (S_height / 2) + (radar_range) / 2 * 8 * sinf(angle_yaw_rad);

							std::array<VECTOR3, 3> points
							{
								ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((radar_range) / 4 + 3.5f) / 2, 0.f),
								ToVECTOR3(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f),
								ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((radar_range) / 4 + 3.5f) / 2, 0.f)
							};
							RotateTriangle(points, angle.Y + 180.f);
							/*if (AActor.IsBot) {
								DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 5, Colors::bot, 2.3f);
							}
							else {
								DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 6, linescolors, 3.3f);
							}*/
							if (AActor.IsBot) {
								DX11::ImGui_DX11::DrawTriangle(points.at(0).X, points.at(0).Y, points.at(1).X, points.at(1).Y, points.at(2).X, points.at(2).Y, 2, Colors::bot);
							}
							else {
								DX11::ImGui_DX11::DrawTriangle(points.at(0).X, points.at(0).Y, points.at(1).X, points.at(1).Y, points.at(2).X, points.at(2).Y, 2, linescolors);
							}
							if (Setting::radar)
							{

								float S_height = DX11Window::Height;
								float S_width = DX11Window::Width;
								DrawRadarHUD(Data::CameraCache.POV, AActor, Distance, 20, 50, 100, 200, linescolors);


								//  RotateTriangle(points, angle.Y + 180.f);

								//  DX11::ImGui_DX11::Tri(points.at(0).X, points.at(0).Y, points.at(1).X, points.at(1).Y, points.at(2).X, points.at(2).Y, 1.f, Chosencolor);
							   // DX11::ImGui_DX11::DrawTriangle(points.at(0).X, points.at(0).Y, points.at(1).X, points.at(1).Y, points.at(2).X, points.at(2).Y, 1.f, linescolors);


							}



							if (!Algorithm::WorldToScreenPlayer(Data::lOCALPLAYERPosotion, AActor.Position, Screen, &_dist, ViewMatrix)) continue;

							/*	if (Screen.Z < 0.001f)
									continue;*/
							temp = AActor.Name.c_str();
							std::string lol1;
							lol1 = to_string(_dist) + "M";
							if (Screen.X > DX11Window::Width && Screen.Y > 0 && Screen.Y < DX11Window::Height)//Right
							{
								//	DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - 20, Screen.Y + Screen.Z, 7, 10, ImColor(0.0f, 0.f, 0.f, 0.200f));
								//	DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, Screen.Y + Screen.Z, 7, linescolors, 4.0f);
								DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, 20, lol1, DX11Window::Width - 20, Screen.Y + Screen.Z, linescolors, true);
								//	DX11::ImGui_DX11::DrawFilledRectangle(DX11Window::Width - 20, Screen.Y + Screen.Z, 50, 30, ImColor(0.0f, 0.f, 0.f, 0.200f));
								if (Setting::enemyoffscreen)
								{
								/*	if (Setting::pline)
									{
										if (linne == 1) {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
										}
										else if (linne == 2) {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}*/
								}

							}
							if (Screen.X < 0 && Screen.Y  >0 && Screen.Y < DX11Window::Height)//Left
							{

								if (Setting::enemyoffscreen)
								{
									/*if (Setting::pline)
									{
										if (linne == 1) {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
										}
										else {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}*/
								}

								//DX11::ImGui_DX11::DrawCircle(20, Screen.Y + Screen.Z, 7, linescolors, 4.0f);
								DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, 20, lol1, 20, Screen.Y + Screen.Z, linescolors, true);

							}
							// std::string lol1;  
							// lol1 = "Player"; 
						  //   if (Screen.X > DX11Window::Width && Screen.Y > 0 && Screen.Y < DX11Window::Height)//Right
							 //{
								// DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - 20, Screen.Y + Screen.Z, 7, 10, ImColor(0.0f, 0.f, 0.f, 0.200f));
								// DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, Screen.Y + Screen.Z, 7, linescolors, 4.0f);
								// DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, DX11Window::Width - 20, Screen.Y + Screen.Z, Colors::nam, false);
								// DX11::ImGui_DX11::DrawFilledRectangle(DX11Window::Width - 20, Screen.Y + Screen.Z, 50, 30, ImColor(0.0f, 0.f, 0.f, 0.200f));

							 //}
							 //if (Screen.X < 0 && Screen.Y  >0 && Screen.Y < DX11Window::Height)//Left
							 //{

								// DX11::ImGui_DX11::DrawCircle(20, Screen.Y + Screen.Z, 7, linescolors, 4.0f);
								// DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, 20, Screen.Y + Screen.Z, Colors::nam, false);

							 //}
							if (Screen.Y < 0 && Screen.X>0 && Screen.X < DX11Window::Width)//Top
							{
								// DX11::ImGui_DX11::DrawCircle(Screen.X, 20, 7, linescolors, 4.0f);
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, Screen.X, 0, linescolors, true);
								if (Setting::enemyoffscreen)
								{
									/*if (Setting::pline)
									{
										if (linne == 1) {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
										}
										else {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}*/
								}

							}
							if (Screen.Y > DX11Window::Height && Screen.X > 0 && Screen.X < DX11Window::Width)//Bottom
							{
								//	 DX11::ImGui_DX11::DrawCircle(Screen.X, DX11Window::Height - 20, 7, linescolors, 4.0f);
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, Screen.X, DX11Window::Height - 20, linescolors, true);
								if (Setting::enemyoffscreen)
								{
									/*if (Setting::pline)
									{
										if (linne == 1) {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
										}
										else {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}*/
								}

							}
							if (Screen.X < 0 && Screen.Y < 0)//top left
							{
								// DX11::ImGui_DX11::DrawCircle(20, 20, 7, linescolors, 4.0f);
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, 0, 0, linescolors, true);
								if (Setting::enemyoffscreen)
								{
								/*	if (Setting::pline)
									{
										if (linne == 1) {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
										}
										else {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}*/
								}

							}
							if (Screen.X > DX11Window::Width && Screen.Y > DX11Window::Height)//bottom right
							{
								// DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, DX11Window::Height - 20, 7, linescolors, 4.0f);
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, DX11Window::Width - 40, DX11Window::Height - 20, linescolors, true);
								if (Setting::enemyoffscreen)
								{
									/*if (Setting::pline)
									{
										if (linne == 1) {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
										}
										else {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}*/
								}

							}
							if (Screen.X > DX11Window::Width && Screen.Y < 0)//top right
							{
								// DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, 20, 7, linescolors, 4.0f);
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, DX11Window::Width - 40, 0, linescolors, true);
								if (Setting::enemyoffscreen)
								{
									/*if (Setting::pline)
									{
										if (linne == 1) {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
										}
										else {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}*/
								}

							}
							if (Screen.X<0 && Screen.Y >DX11Window::Width)//bottom left
							{
								// DX11::ImGui_DX11::DrawCircle(20, DX11Window::Height - 20, 7, linescolors, 4.0f);
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, lol1, 0, DX11Window::Height - 20, linescolors, true);
								if (Setting::enemyoffscreen)
								{
									/*if (Setting::pline)
									{
										if (linne == 1) {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
										}
										else {
											DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
										}
									}*/
								}

							}
						}

						DWORD MeshAddv;
						DWORD BodyAddv;
						DWORD BoneAddv;
						if (Setting::Bone)
						{



						}
						//if (IsPlayer(EntityType) && Setting::PlayerESP)
						//{
						//	int KnockedHealth = Utility::ReadMemoryEx<FLOAT>(EntityAddress + Offset::NearDeathBreath); if (KnockedHealth <= 0) continue;
						//	bool IsDead = Utility::ReadMemoryEx<bool>(EntityAddress + Offset::IsDead); if (IsDead == true) continue;
						//	AActor AActor;
						//	AActor.TeamId = Utility::ReadMemoryEx<INT>(EntityAddress + Offset::TeamId);
						//	AActor.Address = EntityAddress;
						//}
						if (Setting::Bone)
						{

							MeshAddv = Utility::ReadMemoryEx<DWORD>(AActor.Address + Offset::Mesh);
							BodyAddv = MeshAddv + Offset::BodyAddv;
							BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
							AActor.HeadPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);


							AActor.ChestPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 4 * 48);
							//if (!ISUseFulVector(AActor.ChestPos))continue;
							AActor.PelvisPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 1 * 48);
							//if (!ISUseFulVector(AActor.PelvisPos))continue;
							AActor.lSholderPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 11 * 48);
							AActor.rSholderPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 32 * 48);
							AActor.lElbowPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 12 * 48);
							AActor.rElbowPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 33 * 48);
							AActor.lWristPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 63 * 48);
							//if (!ISUseFulVector(AActor.lWristPos))continue;
							AActor.rWristPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 62 * 48);
							AActor.lThighPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 52 * 48);
							if (AActor.rWristPos == AActor.lThighPos)continue;
							if (AActor.rElbowPos == AActor.lSholderPos)continue;
							//if (!ISUseFulVector(AActor.lThighPos))continue;
							AActor.rThighPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 56 * 48);
							AActor.lKneePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 53 * 48);
							AActor.rKneePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 57 * 48);
							AActor.lAnklePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 54 * 48);
							//if (!ISUseFulVector(AActor.lAnklePos))continue;
							AActor.rAnklePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 58 * 48);
						}

						HeadPos = AActor.HeadPos;
						HeadPos.Z += 7;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;
						//	if (Chest.X <= 0)continue;



						if (Distance < Setting::PlayerMAxDistance)
						{

							if (AActor.IsBot)
							{
								linescolors = Colors::bot;
								temp = "[BOT]";
							}
							if (!Setting::enemyoffscreen)
							{
								if (Setting::pline)
								{
									if (linne == 1) {
										DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
									}
									else {
										DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
									}

									
								}
							}
							if (Setting::EnemyLineOfSight)
							{
								VECTOR3 hed = AActor.HeadPos;
								hed.Z += 7.0f;
								VECTOR3 SightAngle = FRotatorToVector(AActor.RelativeRotation);
								VECTOR3 end = ADDVECTORS(hed, MULTIPLYVECT(SightAngle, Setting::enemyLineofSightSize));

								VECTOR3 screen_start, screen_end;
								int dis;
								if (Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, hed, screen_start, &dis, ViewMatrix) && Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, end, screen_end, &dis, ViewMatrix)) {
									DX11::ImGui_DX11::DrawLine(screen_start.X, screen_start.Y, screen_end.X, screen_end.Y, Colors::enemyLineofSight, 2);
									DX11::ImGui_DX11::DrawCircle(screen_end.X, screen_end.Y, 1.f, linescolors, 1.0f);

								}
							}
							//	string TemID = "[" + std::to_string(teamids) + "]";
							string TemID = std::to_string(teamids) + ". " + AActor.Nation;
							std::string dist = std::to_string(_dist) + "M";
							if (Setting::pname)
							{

								if (AActor.Health <= 0)
								{
									if (AActor.IsBot) {
										const char* BOT = ("%d ", ICON_FA_USER);
										DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, nsize, BOT, Screen.X - 2, Screen.Y - 29, DX11::ImGui_DX11::Color::Red, true);
										//DX11::ImGui_DX11::DrawStrokeText(DX11::ImGui_DX11::pRegularFont, Screen.X - 10, Screen.Y - 28, linescolors, temp.c_str(), nsize,  true);
									}
									else
									{
										///DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, nsize, TemID, Screen.X - 50, Screen.Y - 28, Colors::playername, false);
										//DX11::ImGui_DX11::DrawStrokeText(DX11::ImGui_DX11::pRegularFont, 17, temp, Screen.X - 10, Screen.Y - 28, DX11::ImGui_DX11::Color::Red, true);
										DX11::ImGui_DX11::DrawStrokeText(DX11::ImGui_DX11::pRegularFont, Screen.X - 10, Screen.Y - 28, DX11::ImGui_DX11::Color::Red, temp.c_str(), nsize, false);
									}

								}
								else
								{


									if (AActor.IsBot) {
										const char* BOT = ("%d ", ICON_FA_USER);
										DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 15, BOT, Screen.X - 2, Screen.Y - 29, DX11::ImGui_DX11::Color::Green, true);
										//DX11::ImGui_DX11::DrawStrokeText(DX11::ImGui_DX11::pRegularFont, Screen.X - 10, Screen.Y - 28, linescolors, temp.c_str(), nsize,  true);
									}
									else {
										///void DX11::ImGui_DX11::DrawStrokeText(ImFont* pFont, int x, int y, ImColor Color, const char* str, float fontsize, bool center)
										//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 17, temp, Screen.X - 10, Screen.Y - 28, Colors::nam, true);
										///DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, nsize, TemID, Screen.X - 50, Screen.Y - 28, Colors::playername, false);
										DX11::ImGui_DX11::DrawStrokeText(DX11::ImGui_DX11::pRegularFont, Screen.X - 10, Screen.Y - 28, Colors::playername, temp.c_str(), nsize, false);
									}


								}

							}

							if (Setting::pflag)
							{
								if (!AActor.IsBot) {
									NationFlag(Screen, AActor, 50, 40, 20, 10);
								}

							}

							if (Setting::pfullbox)
							{
								if (!Setting::plyrbox)
								{
									fullboxcolor = linescolors;
								}
								else
								{
									fullboxcolor = Colors::playerbox;
								}


								DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, fullboxcolor, Setting::pfullboxsize);

							}
							else if (Setting::pcorner)
							{
								if (!Setting::plyrbox)
								{
									cornerboxcolor = linescolors;
								}
								else
								{
									cornerboxcolor = Colors::playerbox;
								}

								DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting::pcornersize, popcorn / 2, cornerboxcolor);

							}

							if (Setting::puid)
							{

								DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize, AActor.UID, Screen.X + 17, (Screen.Y + Screen.Z) + 30, Colors::plyerdistance, true);
							}
							if (Setting::phealth)
							{

								if (hpbt == 0)
								{
									if (AActor.Health > 0)
									{
										DX11::ImGui_DX11::DrawHP(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5), DX11::ImGui_DX11::Color::Black);

										if (AActor.Health > 70.0)
										{
											DX11::ImGui_DX11::DrawHP(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Green);
										}
										if (AActor.Health > 30.0 && AActor.Health <= 70.0)
										{
											DX11::ImGui_DX11::DrawHP(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Yellow);
										}
										if (AActor.Health > 0.0 && AActor.Health <= 30.0)
										{
											DX11::ImGui_DX11::DrawHP(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Red);

										}
										DX11::ImGui_DX11::DrawUnHP(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 2, (Screen.Z + 5), DX11::ImGui_DX11::Color::Black);
									}
									else
									{
										DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5), DX11::ImGui_DX11::Color::Black);
										DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.KnockedHealth / 100, DX11::ImGui_DX11::Color::Red);

									}
								}
								else if (hpbt == 1)
								{
									std::string hp100 = "HP : 100";
									std::string hp90 = "HP : 90";
									std::string hp80 = "HP : 80";
									std::string hp60 = "HP : 60";
									std::string hp40 = "HP : 40";
									std::string hp20 = "HP : 20";
									std::string hp10 = "HP : 10";
									std::string hp0 = "HP : 0";

									if (AActor.Health > 99.0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp100, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

									}
									if (AActor.Health > 90.0 && AActor.Health <= 99.0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp90, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

									}
									if (AActor.Health > 80.0 && AActor.Health <= 90.0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp80, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

									}
									if (AActor.Health > 60.0 && AActor.Health <= 80.0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp60, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

									}
									if (AActor.Health > 40.0 && AActor.Health <= 60.0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp40, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

									}
									if (AActor.Health > 20.0 && AActor.Health <= 40.0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp20, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

									}
									if (AActor.Health > 10.0 && AActor.Health <= 20.0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp10, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

									}

									if (AActor.Health > 0.0 && AActor.Health <= 10.0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp0, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

									}
								}


							}
							
							
							if (Setting::playerBone)
							{
								if (AActor.Address == Setting::CurrentTargetAddress) {
									bonescolors = Colors::targetenemybone;
								}
								else {
									bonescolors = Colors::playerbone;
								}

								if (Setting::playerBone)
								{
									DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, DX11::ImGui_DX11::Color::Yellow, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, bonescolors, Setting::pbonesize);
									DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, bonescolors, Setting::pbonesize);
								}

							}
							
						
							if (Setting::playerweapon || Setting::plyrdistance)
							{
								string wep = AActor.Weapon;
								string dista = dist;

								if (wep == "Fist")
								{

									if (Setting::playerweapon && Setting::plyrdistance)
									{
										wep.append(" | ");
										wep.append(dista);
										//DX11::ImGui_DX11::DrawStrokeText(DX11::ImGui_DX11::pRegularFont,  Screen.X, (Screen.Y + Screen.Z) + 10, Colors::ammo5, wep.c_str(), dissize, true);
										DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize, wep, Screen.X + 4, (Screen.Y + Screen.Z), Colors::ammo5, true);

									}
								}
								else
								{


									if (Setting::plyrdistance)
									{
										DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize, dist, Screen.X + 4, (Screen.Y + Screen.Z) + 12, Colors::plyerdistance, true);
										//	DX11::ImGui_DX11::DrawStrokeText(DX11::ImGui_DX11::pRegularFont, Screen.X, (Screen.Y + Screen.Z) + 25, Colors::plyerdistance, dist.c_str(), dissize, true);
									}
									if (Setting::playerweapon)
									{

										//	printf_s(temptext, xorstr_("%s (%d/%d)"), wep, AActor.Ammo, AActor.AmmoMax);

										/*string weapon; = wep AActor.Ammo, AActor.AmmoMax
											wep.append(" | ");
										wep.append(dista);*/

										wep.append(" | ");
										wep.append(to_string(AActor.Ammo) + ":");

										wep.append(to_string(AActor.AmmoMax));
										wep.append(AActor.ScopeFov);
										if (AActor.Ammo <= 200 && AActor.AmmoMax > 0)
										{
											DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize, wep, Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
										}
										else
										{
											DX11::ImGui_DX11::DrawCharBorderText(DX11::ImGui_DX11::pRegularFont, dissize, AActor.Weapon.c_str(), Screen.X + 5, (Screen.Y + Screen.Z) - 1, Colors::plyrweapon, true);
										}



										//		DX11::ImGui_DX11::DrawCharBorderText(DX11::ImGui_DX11::pRegularFont, dissize, AActor.Weapon.c_str(), Screen.X, (Screen.Y + Screen.Z), Colors::plyrweapon, true);

										//	DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, dissize, AActor.Weapon, Screen.X, (Screen.Y + Screen.Z), Colors::plyrweapon, true);

										//	DX11::ImGui_DX11::DrawStrokeText(DX11::ImGui_DX11::pRegularFont, Screen.X, (Screen.Y + Screen.Z) + 10, Colors::plyrweapon, AActor.Weapon.c_str(), dissize, true);
									}

								}

							}



							if (Setting::AimLineBottm)
							{
								if (AActor.Address == Setting::CurrentTargetAddress)
								{

									//DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height, Screen.X, Screen.Y + 30, Colors::magicline, 0.5f);
									DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height, Screen.X + 5, (Screen.Y + 15 + Screen.Z) - 10, Colors::magicline, 0.5f);

								}


							}
							else if (Setting::AimLineCross)
							{
								if (AActor.Address == Setting::CurrentTargetAddress)
								{
									if (Setting::curraim == 0)
									{
										DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height / 2, Head.X, Head.Y, Colors::magicline, 0.7f);
									}
									else if (Setting::curraim == 1)
									{
										DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height / 2, Chest.X, Chest.Y, Colors::magicline, 0.7f);
									}
									else if (Setting::curraim == 2)
									{
										DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height / 2, Pelvis.X, Pelvis.Y, Colors::magicline, 0.7f);
									}
									else if (Setting::curraim == 3)
									{
										DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height / 2, Pelvis.X, Pelvis.Y, Colors::magicline, 0.7f);
									}
								}
							}
						}
					}
				}
				if (Setting::MyLineOfSight)
				{
					CameraCacheEntry CameraCache = Data::CameraCache;
					VECTOR3 currentViewLocation = Data::CameraCache.POV.Location;//Data::lOCALPLAYERHEAD;
					VECTOR3 currentViewRotation = FRotatorToVector(Data::CameraCache.POV.Rotation);
					VECTOR3 end = ADDVECTORS(currentViewLocation, MULTIPLYVECT(currentViewRotation, Setting::enemyLineofSightSize));

					VECTOR3 screen_start, screen_end;
					int dis;
					if (Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, currentViewLocation, screen_start, &dis, ViewMatrix) && Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, end, screen_end, &dis, ViewMatrix)) {
						DX11::ImGui_DX11::DrawLine(screen_start.X, screen_start.Y, screen_end.X, screen_end.Y, Colors::enemyLineofSight, 0.001);
						DX11::ImGui_DX11::DrawCircle(screen_end.X, screen_end.Y, 1.f, linescolors, 1.0f);

					}


				}
				if (Setting::MagicBulletticked)
				{
					if (Data::NetDriver > 0) {
						if (Setting::MagicBulletd) {
							if (Data::AActorList.size() != 0)
							{
								const char* aimb[] = { "HEAD", "BODY", "PELVIS", "AUTO" };
								const char* combo_label = aimb[Setting::curraim];
								std::string Aim = combo_label;
								Setting::MagicBullet = true;
								if (Setting::curraim == 3)
								{
									Text = "  Tracking ON [ AUTO ]";
								}
								else
								{
									Text = "  Tracking ON [ " + Aim + "] [" + to_string(Setting::magicrange) + "]M";
								}
								////////////سطر الماجيك
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, Text, DX11Window::Width / 2.2, DX11Window::Height / 2 + 400, DX11::ImGui_DX11::Color::Green, true);
							}
							else
							{
								Setting::MagicBullet = false;
								Text = "  Tracking Bullet [OFF]";
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, Text, DX11Window::Width / 2.2, DX11Window::Height / 2 + 220, DX11::ImGui_DX11::Color::Red, true);
							}
						}
					}
				}
				else if (!Setting::MagicBulletticked) {
					Setting::MagicBullet = false;
					Setting::fovcircle = false;
					Setting::MagicBulletticked = false;
					Setting::magicrange = false;
					Setting::MAgicline = false;
				}
				int botcount;
				int playercount;
				if (Setting::TotalEnemy)
				{
					DrawTotalEnemies();
				}

				if (Setting::Nextzone)
				{
					TempBombAlertList.clear();
					TempBombAlertList = Data::BombAlertList;
					for (BombAlert& bomb : TempBombAlertList) {
						bomb.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(bomb.Address + Offset::RootComponent) + Offset::Position);
						if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, bomb.Position, Screen, &Distance, ViewMatrix)) continue;
						string  Name = bomb.Name + " [" + to_string(Distance) + "m]";
						const char* Aim;
						if (bomb.Name == "NEXT ZONE")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Name, Screen.X, Screen.Y - 5, DX11::ImGui_DX11::Color::Red, true);
						}
						Algorithm::Draw3Dcircle(ViewMatrix, Data::lOCALPLAYERPosotion, bomb.Position, 32, 500.0f, 1.0f, DX11::ImGui_DX11::Color::Green);
						continue;
					}
				}

				if (Setting::gameinfo)
				{
					static bool blinkState = true;
					static float blinkTimer = 0.0f;
					blinkTimer += ImGui::GetIO().DeltaTime;
					if (blinkTimer > 0.5f)
					{
						blinkState = !blinkState;
						blinkTimer = 0.0f;
					}
					ImVec4 ballColor = blinkState ? ImVec4(1.0f, 0.0f, 0.0f, 1.0f) : ImVec4(0.0f, 0.0f, 0.0f, 0.0f); // Red color

					ImGuiStyle& style = ImGui::GetStyle();
					style.WindowRounding = 7.0f;
					style.Colors[ImGuiCol_WindowBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.784f);

					// Save current border color and size
					ImVec4 prevBorderColor = style.Colors[ImGuiCol_Border];
					float prevBorderSize = style.WindowBorderSize;

					// Dynamic RGB color change over time
					static float time = 0.0f;
					time += ImGui::GetIO().DeltaTime;

					// Generate RGB values using sin function for smooth transitions
					float red = (sin(time * 2.0f) * 0.5f) + 0.5f;
					float green = (sin(time * 2.0f + 2.0f) * 0.5f) + 0.5f;
					float blue = (sin(time * 2.0f + 4.0f) * 0.5f) + 0.5f;

					ImVec4 accentColor = ImVec4(red, green, blue, 1.0f);
					style.Colors[ImGuiCol_Border] = accentColor;
					style.WindowBorderSize = 2.0f; // Border thickness
					ImGui::PushFont(DX11::ImGui_DX11::pRegularFont);
					if (ImGui::Begin("###53", &testtt, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize))
					{
						ImGui::TextColored(ballColor, ICON_FA_CIRCLE);
						ImGui::SameLine();
						ImGui::Text("Match Statics");

						if (Data::NetDriver > 0 && Data::LocalPlayer > 0)
						{
							if (Data::MyPlayerWorld > 0)
							{
								// ثابت معلومات
								string Textt4 = "Travelled Distance: ";
								string Textt5 = "m (";
								string Textt6 = "m/s)";
								string Textt3 = " Team, Real Players: ";
								string Textt2 = " Players alive With ";
								string khaled = " map : ";
								string khaled22 = " Kils : ";

								// تنسيق المعلومات
								stringstream format2stream2;
								stringstream forma2stream;
								format2stream2 << fixed << setprecision(2) << Data::GameInfovelocity;
								string format2str2 = format2stream2.str();
								forma2stream << fixed << setprecision(0) << Data::DistanceTravelled;
								string format2str2g = forma2stream.str();
								string Textt = to_string(Data::AlivePlayerNum) + Textt2 + to_string(Data::AliveTeamNum) + Textt3 + to_string(Data::OnlinePlayer) + khaled + Data::LocalPawn + khaled22 + to_string(Data::Kills);
								string Textttt = Textt4 + forma2stream.str() + Textt5 + format2stream2.str() + Textt6;
								ImGui::Text(Textt.c_str());
								ImGui::Text(Textttt.c_str());
								ImGui::Separator();

								string Text;
								if (Data::AlivePlayerNum <= 4)
								{
									Text = "Connected to lobby, Please exit";
									inMatch = false; // تعيين حالة اللاعب إلى غير نشط
								}
								else
								{
									if (!inMatch)
									{
										inMatch = true;
										matchStartTime = steady_clock::now();
									}

									auto currentTime = steady_clock::now();
									auto matchDuration = duration_cast<seconds>(currentTime - matchStartTime).count();

									int minutes = matchDuration / 60;
									int seconds = matchDuration % 60;

									Text = "In match (" + to_string(minutes) + "m " + to_string(seconds) + "s)";
								}
								ImGui::Text(Text.c_str());
							}
						}
						else
						{
							ImGui::Text("Not in match");
							Data::DistanceTravelled = 0;
						}
						ImGui::PopFont();
						ImGui::End();
					}

					// Restore previous border color and size
					style.Colors[ImGuiCol_Border] = prevBorderColor;
					style.WindowBorderSize = prevBorderSize;

					style.WindowRounding = 5.0f;
					style.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 235);
				}

////////				if (Setting::gameinfo)
////////{
////////					static bool blinkState = true;
////////					static float blinkTimer = 0.0f;
////////					blinkTimer += ImGui::GetIO().DeltaTime;
////////					if (blinkTimer > 0.5f)
////////					{
////////						blinkState = !blinkState;
////////						blinkTimer = 0.0f;
////////					}
////////					ImVec4 ballColor = blinkState ? ImVec4(1.0f, 0.0f, 0.0f, 1.0f) : ImVec4(0.0f, 0.0f, 0.0f, 0.0f); // Red color
////////
////////
////////					ImGuiStyle& style = ImGui::GetStyle();
////////					style.WindowRounding = 7.0f;
////////					style.Colors[ImGuiCol_WindowBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.784f);
////////
////////					// Save current border color and size
////////					ImVec4 prevBorderColor = style.Colors[ImGuiCol_Border];
////////					float prevBorderSize = style.WindowBorderSize;
////////
////////					// Set new border color and size to match the accent color (coral)
////////					ImVec4 accentColor = ImVec4(0.65f, 0.65f, 0.65f, 1.0f);
////////					style.Colors[ImGuiCol_Border] = accentColor;
////////					style.WindowBorderSize = 2.0f; // Border thickness
////////
////////					if (ImGui::Begin("###53", &testtt, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize))
////////					{
////////						// تعريف ألوان الكرة
////////						static bool blinkState = true;
////////						static float blinkTimer = 0.0f;
////////						blinkTimer += ImGui::GetIO().DeltaTime;
////////						if (blinkTimer > 0.5f)
////////						{
////////							blinkState = !blinkState;
////////							blinkTimer = 0.0f;
////////						}
////////						ImVec4 ballColor = blinkState ? ImVec4(1.0f, 0.0f, 0.0f, 1.0f) : ImVec4(0.0f, 0.0f, 0.0f, 0.0f); // لون أحمر
////////
////////						ImGui::TextColored(ballColor, ICON_FA_CIRCLE);
////////						ImGui::SameLine();
////////						ImGui::Text("Match Statics");
////////
////////						if (Data::NetDriver > 0 && Data::LocalPlayer > 0)
////////						{
////////							if (Data::MyPlayerWorld > 0)
////////							{
////////								// معلومات ثابتة
////////								string Textt4 = "Travelled Distance: ";
////////								string Textt5 = "m (";
////////								string Textt6 = "m/s)";
////////								string Textt3 = " Team, Real Players: ";
////////								string Textt2 = " Players alive With ";
////////								string khaled = " map : ";
////////								string khaled22 = " Kils : ";
////////
////////								// تنسيق المعلومات
////////								stringstream format2stream2;
////////								stringstream forma2stream;
////////								format2stream2 << fixed << setprecision(2) << Data::GameInfovelocity;
////////								string format2str2 = format2stream2.str();
////////								forma2stream << fixed << setprecision(0) << Data::DistanceTravelled;
////////								string format2str2g = forma2stream.str();
////////								string Textt = to_string(Data::AlivePlayerNum) + Textt2 + to_string(Data::AliveTeamNum) + Textt3 + to_string(Data::OnlinePlayer) + khaled + Data::LocalPawn + khaled22 + to_string(Data::Kills);
////////								string Textttt = Textt4 + forma2stream.str() + Textt5 + format2stream2.str() + Textt6;
////////								ImGui::Text(Textt.c_str());
////////								ImGui::Text(Textttt.c_str());
////////								ImGui::Separator();
////////
////////								// تحديث الحالة الخاصة بالمباراة
////////								string Text;
////////								if (Data::AlivePlayerNum <= 4)
////////								{
////////									Text = "Connected to lobby, Please exit";
////////									inMatch = false; // تعيين حالة اللاعب إلى غير نشط
////////								}
////////								else
////////								{
////////									if (!inMatch)
////////									{
////////										// بدء العداد عند دخول المباراة
////////										inMatch = true;
////////										matchStartTime = steady_clock::now();
////////									}
////////
////////									// حساب وقت المباراة بناءً على وقت البدء
////////									auto currentTime = steady_clock::now();
////////									auto matchDuration = duration_cast<seconds>(currentTime - matchStartTime).count();
////////
////////									// تحويل الوقت إلى دقائق وثواني
////////									int minutes = matchDuration / 60;
////////									int seconds = matchDuration % 60;
////////
////////									Text = "In match (" + to_string(minutes) + "m " + to_string(seconds) + "s)";
////////								}
////////								ImGui::Text(Text.c_str());
////////							}
////////						}
////////						else
////////						{
////////							ImGui::Text("Not in match");
////////							Data::DistanceTravelled = 0;
////////						}
////////        ImGui::End();
////////    }
////////
////////    // Restore previous border color and size
////////    style.Colors[ImGuiCol_Border] = prevBorderColor;
////////    style.WindowBorderSize = prevBorderSize;
////////
////////    style.WindowRounding = 5.0f;
////////    style.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 235);
////////}
				if (Setting::fovcircle)
				{
					if (Data::AActorList.size() != 0)
					{
						DX11::ImGui_DX11::DrawCircle(DX11Window::Width / 2, DX11Window::Height / 2, Setting::fovcircleredus, Colors::fovcirclecolor);
					}
				}
				if (Setting::allitemss)
				{
					if (Setting::impitems || Setting::healthitem || Setting::scope || Setting::allitemss && !Setting::fightmode)
					{
						
						if (Data::ItemList.size() != 0)
						{
							TempItemList.clear();
							TempItemList = Data::ItemList;
							for (Item& Item : Data::ItemList)
							{
								if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Item.Position, Screen, &Distance, ViewMatrix)) continue;
								if (Distance > 100)continue;
								std::string	Textt = Item.Name;
								Text = Item.Name;

								if (Setting::UselessShow)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Textt, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag1_Color[0], Setting::Esp_Item_Bag1_Color[1], Setting::Esp_Item_Bag1_Color[2], Setting::Esp_Item_Bag1_Color[3]), true);

								}
								if (Setting::impitems)
								{
									std::string air = Item.Name + " " + to_string(Distance) + "M";
									if (Setting::Esp_Item_AKM && Item.Name == "AKM")
									{
										if (Setting::Esp_Item_AKM_Icon)
										{
											DX11::ImGui_DX11::DrawImage(DX11::AKM, Screen.X - 50, Screen.Y - 25, 100, 50);
											continue;
										}
										else
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::AKM, true);
											continue;
										}
									}
									if (Setting::Esp_Item_SCARL && Item.Name == "SCAR-L")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::scarl, true);
										continue;
									}
									if (Setting::Esp_Item_SCARL && Item.Name == "GoldenToken")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::scarl, true);
										continue;
									}

									if (Setting::Esp_Item_SCARL && Item.Name == "Personal_AED")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::scarl, true);
										continue;
									}

									if (Setting::Esp_Item_SCARL && Item.Name == "Magnetic_Gun")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::scarl, true);
										continue;
									}
									if (Setting::Esp_Item_SCARL && Item.Name == "Flying_Armor")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::scarl, true);
										continue;
									}



									if (Setting::Esp_Item_M416 && Item.Name == "M416")
									{
										if (Setting::Esp_Item_M416_Icon)
										{
											DX11::ImGui_DX11::DrawImage(DX11::M416, Screen.X - 50, Screen.Y - 25, 100, 50);
											continue;
										}
										else
										{

											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::m16, true);
											continue;
										}
									}
									if (Setting::Esp_Item_M24 && Item.Name == "M24")
									{
										if (Setting::Esp_Item_M24_Icon)
										{
											DX11::ImGui_DX11::DrawImage(DX11::M24, Screen.X - 50, Screen.Y - 25, 100, 50);
											continue;
										}
										else
										{

											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::M24, true);
											continue;
										}
									}

									if (Setting::Esp_Item_Kar98k && Item.Name == "Kar98k")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::kar98, true);
										continue;
									}
									if (Setting::plan && Item.Name == "[AIR-PLANE]")
									{
										string  Text = Item.Name + " " + to_string(Distance) + "M";
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, Setting::plancolor, true);
										continue;
									}
									if (Item.Name == "[MVP-STATUE]")
									{
										string  statue1 = Item.Name + " " + to_string(Distance) + "M";
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, statue1, Screen.X, Screen.Y, ImColor(255, 255, 0, 255), true);
										continue;
									}
									if (Setting::Esp_Item_DP28 && Item.Name == "DP28")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_DP28_Color[0], Setting::Esp_Item_DP28_Color[1], Setting::Esp_Item_DP28_Color[2], Setting::Esp_Item_DP28_Color[3]), true);
										continue;
									}
									if (Setting::Esp_Item_M762 && Item.Name == "M762")
									{
										if (Setting::Esp_Item_M762_Icon)
										{
											DX11::ImGui_DX11::DrawImage(DX11::M762, Screen.X - 50, Screen.Y - 25, 100, 50);
											continue;
										}
										else
										{

											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]), true);
											continue;
										}
									}
									if (Setting::Esp_Item_Awm && Item.Name == "AWM")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, air, Screen.X, Screen.Y, weapon::AWM, true);
										continue;
									}

									if (Setting::Esp_Item_FlareGun && Item.Name == "Flare Gun")
									{
										if (Setting::Esp_Item_FlareGun_Icon)
										{
											DX11::ImGui_DX11::DrawImage(DX11::FLAREGUN, Screen.X - 50, Screen.Y - 25, 100, 50);
											continue;
										}
										else
										{

											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, air, Screen.X, Screen.Y, weapon::Flaregun, true);
											continue;
										}
									}
									if (Setting::Esp_Item_Flare && Item.Name == "Flare")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, air, Screen.X, Screen.Y, weapon::Flare, true);
										continue;
									}

									if (Setting::Esp_Item_AirDrop && Item.Name == "Air Drop")
									{
										//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, air, Screen.X, Screen.Y, weapon::Airdrop, true);
										continue;
									}
									if (Setting::Esp_Item_Armor3 && Item.Name == "Armor L.3")
									{
										DX11::ImGui_DX11::DrawImage(DX11::Armor3, Screen.X - 15, Screen.Y - 15, 30, 30);
										//continue;
										//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor3_Color[0], Setting::Esp_Item_Armor3_Color[1], Setting::Esp_Item_Armor3_Color[2], Setting::Esp_Item_Armor3_Color[3]), true);
										continue;
									}
									if (Setting::Esp_Item_Bag3 && Item.Name == "Bag L.3")
									{

										DX11::ImGui_DX11::DrawImage(DX11::Bag3, Screen.X - 15, Screen.Y - 15, 30, 30);
										continue;
										//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag3_Color[0], Setting::Esp_Item_Bag3_Color[1], Setting::Esp_Item_Bag3_Color[2], Setting::Esp_Item_Bag3_Color[3]), true);
										continue;
									}
									if (Setting::Esp_Item_Helmet3 && Item.Name == "Helmet L.3")
									{


										DX11::ImGui_DX11::DrawImage(DX11::Helmet3, Screen.X - 15, Screen.Y - 15, 30, 30);
										continue;
										/*
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet3_Color[0], Setting::Esp_Item_Helmet3_Color[1], Setting::Esp_Item_Helmet3_Color[2], Setting::Esp_Item_Helmet3_Color[3]), true);
										continue;*/
									}
									if (Setting::Esp_Item_Helmet3 && Item.Name == "300Magnum")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, air, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet3_Color[0], Setting::Esp_Item_Helmet3_Color[1], Setting::Esp_Item_Helmet3_Color[2], Setting::Esp_Item_Helmet3_Color[3]), true);
										continue;
									}
									if (Setting::Esp_Item_exquic && Item.Name == "Ex QuickDraw")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::QuickDraw, true);
										//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, air, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_exquic_Color[0], Setting::Esp_Item_exquic_Color[1], Setting::Esp_Item_exquic_Color[2], Setting::Esp_Item_exquic_Color[3]), true);
										continue;
									}
								}
								if (Setting::healthitem) {
									if (Setting::Esp_Item_MedKit && Item.Name == "Med Kit")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_MedKit_Color[0], Setting::Esp_Item_MedKit_Color[1], Setting::Esp_Item_MedKit_Color[2], Setting::Esp_Item_MedKit_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_FirstAidKit && Item.Name == "First Aid Kit")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_FirstAidKit_Color[0], Setting::Esp_Item_FirstAidKit_Color[1], Setting::Esp_Item_FirstAidKit_Color[2], Setting::Esp_Item_FirstAidKit_Color[3]), true);
										continue;
									}
									if (Setting::Esp_Item_Painkiller && Item.Name == "Painkiller")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Painkiller_Color[0], Setting::Esp_Item_Painkiller_Color[1], Setting::Esp_Item_Painkiller_Color[2], Setting::Esp_Item_Painkiller_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_EnergyDrink && Item.Name == "Energy Drink")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_EnergyDrink_Color[0], Setting::Esp_Item_EnergyDrink_Color[1], Setting::Esp_Item_EnergyDrink_Color[2], Setting::Esp_Item_EnergyDrink_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_AdrenalineSyringe && Item.Name == "Adrenaline Syringe")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_AdrenalineSyringe_Color[0], Setting::Esp_Item_AdrenalineSyringe_Color[1], Setting::Esp_Item_AdrenalineSyringe_Color[2], Setting::Esp_Item_AdrenalineSyringe_Color[3]), true);
										continue;
									}
								}
								if (Setting::scope) {
									if (Setting::Esp_Item_x2 && Item.Name == "2x")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x2_Color[0], Setting::Esp_Item_x2_Color[1], Setting::Esp_Item_x2_Color[2], Setting::Esp_Item_x2_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_x3 && Item.Name == "3x")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x3_Color[0], Setting::Esp_Item_x3_Color[1], Setting::Esp_Item_x3_Color[2], Setting::Esp_Item_x3_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_x4 && Item.Name == "4x")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x4_Color[0], Setting::Esp_Item_x4_Color[1], Setting::Esp_Item_x4_Color[2], Setting::Esp_Item_x4_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_x6 && Item.Name == "6x")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x6_Color[0], Setting::Esp_Item_x6_Color[1], Setting::Esp_Item_x6_Color[2], Setting::Esp_Item_x6_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_x8 && Item.Name == "8x")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x8_Color[0], Setting::Esp_Item_x8_Color[1], Setting::Esp_Item_x8_Color[2], Setting::Esp_Item_x8_Color[3]), true);
										continue;
									}
								}
								if (Setting::allitemss) {
									if (Setting::Esp_Item_Bag1 && Item.Name == "Bag L.1")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag1_Color[0], Setting::Esp_Item_Bag1_Color[1], Setting::Esp_Item_Bag1_Color[2], Setting::Esp_Item_Bag1_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_Bag2 && Item.Name == "Bag L.2")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag2_Color[0], Setting::Esp_Item_Bag2_Color[1], Setting::Esp_Item_Bag2_Color[2], Setting::Esp_Item_Bag2_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_Helmet1 && Item.Name == "Helmet L.1")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet1_Color[0], Setting::Esp_Item_Helmet1_Color[1], Setting::Esp_Item_Helmet1_Color[2], Setting::Esp_Item_Helmet1_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_Helmet2 && Item.Name == "Helmet L.2")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet2_Color[0], Setting::Esp_Item_Helmet2_Color[1], Setting::Esp_Item_Helmet2_Color[2], Setting::Esp_Item_Helmet2_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_Armor1 && Item.Name == "Armor L.1")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor1_Color[0], Setting::Esp_Item_Armor1_Color[1], Setting::Esp_Item_Armor1_Color[2], Setting::Esp_Item_Armor1_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_Armor2 && Item.Name == "Armor L.2")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor2_Color[0], Setting::Esp_Item_Armor2_Color[1], Setting::Esp_Item_Armor2_Color[2], Setting::Esp_Item_Armor2_Color[3]), true);
										continue;
									}


									if (Setting::Esp_Item_Mk47Mutant && Item.Name == "Mk47 Mutant")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Mk47Mutant_Color[0], Setting::Esp_Item_Mk47Mutant_Color[1], Setting::Esp_Item_Mk47Mutant_Color[2], Setting::Esp_Item_Mk47Mutant_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_M16A4 && Item.Name == "M16A4")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_M16A4_Color[0], Setting::Esp_Item_M16A4_Color[1], Setting::Esp_Item_M16A4_Color[2], Setting::Esp_Item_M16A4_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_G36C && Item.Name == "G36C")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_G36C_Color[0], Setting::Esp_Item_G36C_Color[1], Setting::Esp_Item_G36C_Color[2], Setting::Esp_Item_G36C_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_QBZ && Item.Name == "QBZ")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_QBZ_Color[0], Setting::Esp_Item_QBZ_Color[1], Setting::Esp_Item_QBZ_Color[2], Setting::Esp_Item_QBZ_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_QBU && Item.Name == "QBU")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_QBU_Color[0], Setting::Esp_Item_QBU_Color[1], Setting::Esp_Item_QBU_Color[2], Setting::Esp_Item_QBU_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_SLR && Item.Name == "SLR")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_SLR_Color[0], Setting::Esp_Item_SLR_Color[1], Setting::Esp_Item_SLR_Color[2], Setting::Esp_Item_SLR_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_Mini14 && Item.Name == "Mini-14")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Mini14_Color[0], Setting::Esp_Item_Mini14_Color[1], Setting::Esp_Item_Mini14_Color[2], Setting::Esp_Item_Mini14_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_SKS && Item.Name == "SKS")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_SKS_Color[0], Setting::Esp_Item_SKS_Color[1], Setting::Esp_Item_SKS_Color[2], Setting::Esp_Item_SKS_Color[3]), true);
										continue;
									}


									if (Setting::Esp_Item_PP19 && Item.Name == "PP19")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_PP19_Color[0], Setting::Esp_Item_PP19_Color[1], Setting::Esp_Item_PP19_Color[2], Setting::Esp_Item_PP19_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_TommyGun && Item.Name == "Tommy Gun")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_TommyGun_Color[0], Setting::Esp_Item_TommyGun_Color[1], Setting::Esp_Item_TommyGun_Color[2], Setting::Esp_Item_TommyGun_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_MP5K && Item.Name == "MP5K")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_MP5K_Color[0], Setting::Esp_Item_MP5K_Color[1], Setting::Esp_Item_MP5K_Color[2], Setting::Esp_Item_MP5K_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_UMP9 && Item.Name == "UMP9")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_UMP9_Color[0], Setting::Esp_Item_UMP9_Color[1], Setting::Esp_Item_UMP9_Color[2], Setting::Esp_Item_UMP9_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_Vector && Item.Name == "Vector")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Vector_Color[0], Setting::Esp_Item_Vector_Color[1], Setting::Esp_Item_Vector_Color[2], Setting::Esp_Item_Vector_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_Uzi && Item.Name == "Uzi")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Uzi_Color[0], Setting::Esp_Item_Uzi_Color[1], Setting::Esp_Item_Uzi_Color[2], Setting::Esp_Item_Uzi_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_762mm && Item.Name == "7.62mm")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_762mm_Color[0], Setting::Esp_Item_762mm_Color[1], Setting::Esp_Item_762mm_Color[2], Setting::Esp_Item_762mm_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_556mm && Item.Name == "5.56mm")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_556mm_Color[0], Setting::Esp_Item_556mm_Color[1], Setting::Esp_Item_556mm_Color[2], Setting::Esp_Item_556mm_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_9mm && Item.Name == "9mm")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_9mm_Color[0], Setting::Esp_Item_9mm_Color[1], Setting::Esp_Item_9mm_Color[2], Setting::Esp_Item_9mm_Color[3]), true);
										continue;
									}
									if (Setting::Esp_Item_45ACP && Item.Name == "45ACP")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_45ACP_Color[0], Setting::Esp_Item_45ACP_Color[1], Setting::Esp_Item_45ACP_Color[2], Setting::Esp_Item_45ACP_Color[3]), true);
										continue;
									}

									if (Setting::Esp_Item_Holo && Item.Name == "Holo")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Holo_Color[0], Setting::Esp_Item_Holo_Color[1], Setting::Esp_Item_Holo_Color[2], Setting::Esp_Item_Holo_Color[3]), true);
										continue;
									}
									if (Setting::Esp_Item_M249 && Item.Name == "M249")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, Colors::M249, true);
										continue;
									}

									if (Setting::Esp_Item_Mk12 && Item.Name == "MK12")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, Colors::MK12, true);
										continue;
									}
									if (Setting::Esp_Item_SniperAMR && Item.Name == "Sniper-AMR")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_SniperAMR_Color[0], Setting::Esp_Item_SniperAMR_Color[1], Setting::Esp_Item_SniperAMR_Color[2], Setting::Esp_Item_SniperAMR_Color[3]), true);
										continue;
									}
									if (Setting::Esp_Item_BulletAMR && Item.Name == "Ammo-50BMG")
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_BulletAMR_Color[0], Setting::Esp_Item_BulletAMR_Color[1], Setting::Esp_Item_BulletAMR_Color[2], Setting::Esp_Item_BulletAMR_Color[3]), true);
										continue;
									}

								}
							}
						}
					}
				}
				if (Setting::deadbox)
				{

					ImColor color;

					if (Data::BoxesList.size() != 0)
					{
						TempBoxesList.clear();
						TempBoxesList = Data::BoxesList;
					}
					for (Deadbox Box : TempBoxesList)
					{

						if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Box.Position, Screen, &Distance, ViewMatrix)) continue;

						if (Distance < 8)
						{
							continue;
						}
						std::string dead = (Box.Name) + to_string(Distance) + "M";
						if (Box.IsDeadBox)
						{
							if (Distance > 100)
							{
								continue;
							}
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, dead, Screen.X, Screen.Y + 13, Colors::deadbox, false);

						}
						else if (Box.isAirDrop)
						{
							DX11::ImGui_DX11::DrawImage(DX11::AirDrop, Screen.X, Screen.Y - 20, 30, 30);
							string Dist = to_string(Distance) + "M";
							DX11::ImGui_DX11::DrawBorderText(DX11::ImGui_DX11::pRegularFont, 15, Dist, Screen.X, Screen.Y + 15, DX11::ImGui_DX11::Color::enem2, false);
							//	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, dead, Screen.X, Screen.Y + 13, Colors::airdrop, false);
						}



						if (Setting::playerdeadbox)
						{
							float yOffset{ -18.0f };
							for (int k = 0; k < Box.boxitem.size(); k++)
							{
								color = Box.boxitem[k].colorcod;
								std::string text = Box.boxitem[k].Displayname;
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, text, Screen.X + 16, Screen.Y + 15 + (yOffset), Box.boxitem[k].colorcod, false);
								yOffset -= 18.0f;

							}

						}

					}


				}
				if (Setting::BombAlert)
				{
					TempBombAlertList.clear();
					TempBombAlertList = Data::BombAlertList;
					for (BombAlert& bomb : TempBombAlertList) {
						bomb.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(bomb.Address + Offset::RootComponent) + Offset::Position);
						//bomb.Position = Utility::ReadMemoryEx<VECTOR3>(Data::RootComponent + Offset::Position);
						if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, bomb.Position, Screen, &Distance, ViewMatrix)) continue;
						if (Distance > 210)continue;
						string  Name = bomb.Name + " [" + to_string(Distance) + "m]";
						const char* Aim;
						//string time = to_string(bomb.timeLeft);
					//	DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y, 12.0f, Colors::Granadeswarn);
						if (bomb.Name == "Smoke" || bomb.Name == "[ALERT] !Flash Granade" || bomb.Name == "Air Bomb !")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::fontsize, Name, Screen.X, Screen.Y - 5, DX11::ImGui_DX11::Color::Red, true);


						}
						if (bomb.Name == "Frag")
						{
							Aim = ("\xef\x87\xa2 ");
							DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 16, Aim, Screen.X, Screen.Y - 4, DX11::ImGui_DX11::Color::Red, true);
						}
						if (bomb.Name == "Burn")
						{
							Aim = ("\xef\x81\xad ");
							DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 16, Aim, Screen.X, Screen.Y - 4, DX11::ImGui_DX11::Color::Red, true);
						}
						Algorithm::Draw3Dcircle(ViewMatrix, Data::lOCALPLAYERPosotion, bomb.Position, 32, 500.0f, 1.0f, DX11::ImGui_DX11::Color::Green);
						continue;
					}

				}

				if (Setting::Vehicle)
				{
					if (Data::VehicleList.size() != 0)
					{
						TempVehicalList.clear();
						TempVehicalList = Data::VehicleList;

						for (Vehicle& Vehicle : Data::VehicleList)
						{
							Vehicle.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Vehicle.Address + Offset::RootComponent) + Offset::Position);
							if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Vehicle.Position, Screen, &Distance, ViewMatrix)) continue;
							if (Distance < 5 || Distance > 700) {
								continue;
							}
							Text = Vehicle.Name + " | " + to_string(Distance) + "m";
							std::string hp;
							ImVec4 color;
							if (Vehicle.driving)
							{
								color = DX11::ImGui_DX11::Color::Red;
							}
							else {
								color = Colors::vehicle;
							}
							ImVec2 TextSize = DX11::ImGui_DX11::pRegularFont->CalcTextSizeA(vehisize, FLT_MAX, 0.0f, Text.c_str());

							if (Setting::hp)
							{
								const char* Fuel = ("%d ", ICON_FA_BATTERY_FULL);
								if (Vehicle.oil == 100.0) {
									Fuel = ("%d ", ICON_FA_BATTERY_FULL);
								}
								else if (Vehicle.oil > 75.0) {
									Fuel = ("%d ", ICON_FA_BATTERY_THREE_QUARTERS);
								}
								else if (Vehicle.oil > 50.0 && Vehicle.oil <= 75.0) {
									Fuel = ("%d ", ICON_FA_BATTERY_HALF);
								}
								else 	if (Vehicle.oil > 25.0 && Vehicle.oil <= 50.0)
								{
									Fuel = ("%d ", ICON_FA_BATTERY_QUARTER);

								}
								else if (Vehicle.oil <= 0) {
									Fuel = ("%d ", ICON_FA_BATTERY_EMPTY);
								}
								else {
									continue;
								}
								string OIL = std::to_string((int)(Vehicle.oil));







								// hp.append("%d :-", ICON_FA_HEART).append(std::to_string((int)(Vehicle.oil)).append(" ♡:-").append(std::to_string((int)(Vehicle.hp)).append("")));


								// DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - 5, Screen.Y + 23, Vehicle.hp, 2.0f, Colors::vehicle);
							//	 DX11::ImGui_DX11::DrawUnFilledRectangle2(Screen.X - 2, Screen.Y + 13, TextSize.x, 2.0f, DX11::ImGui_DX11::Color::Cyan);
								// DX11::ImGui_DX11::DrawUnFilledRectangle2(Screen.X - 5, Screen.Y + 23, Vehicle.oil, 2.0f, DX11::ImGui_DX11::Color::Olive);

								DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 12, Fuel, Screen.X + 48, Screen.Y + 23, DX11::ImGui_DX11::Color::Yellow, true);
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 12, OIL, Screen.X + 58, Screen.Y + 23, DX11::ImGui_DX11::Color::enem2, true);
								//	 DX11::ImGui_DX11::DrawBlood(Screen.X - 5, Screen.Y + 23, 2, 4.0f, Vehicle.hp);
									//DX11::ImGui_DX11::DrawBlood(Screen.X - 5, Screen.Y + 31, 80.0f, 4.0f, Vehicle.oil);
									// DX11::ImGui_DX11::DrawImage(DX11::Heart, Screen.X  -5, Screen.Y + 20, 15, 15);

									//DX11::ImGui_DX11::DrawLine(Screen.X - 5, Screen.Y + 23, screen_end.X, screen_end.Y, Colors::enemyLineofSight, 2);
							}

							if (Setting::feul)
							{
								const char* Heart = ("%d ", ICON_FA_HEARTBEAT);
								string HPP = std::to_string((int)(Vehicle.hp));
								DX11::ImGui_DX11::DrawStringchar(DX11::ImGui_DX11::pRegularFont, 12, Heart, Screen.X + 10, Screen.Y + 23, DX11::ImGui_DX11::Color::Green, true);
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 12, HPP, Screen.X + 18, Screen.Y + 23, DX11::ImGui_DX11::Color::enem2, true);
							}

							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, color, true);
							continue;

						}
					}
				}


			}

			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
			ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(43.f / 255.f, 43.f / 255.f, 43.f / 255.f, 100.f / 255.f));
			ImGui::RenderNotifications();
			//RenderNotifications();
			ImGui::PopStyleVar(1);
			ImGui::PopStyleColor(1);
			ImGui::EndFrame();
			
			//
			DX11::BeginDraw();
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			DX11::EndDraw();
			//ImGui::RenderNotifications();

			//DX11Window::IsDrawing = false;
			//
			//
			//DX11Window::IsDrawing = true;
		}
		catch (int e)
		{
			//std::cout << e << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(7));
	}


}