#include "mrboot.h"

std::string readFromFile22(const std::string& filename) {
	std::ifstream file(filename);
	std::string content;
	if (file.is_open()) {
		std::getline(file, content);
		file.close();
	}
	return content;
}
void Watermark::Show()
{
	char timebuff[80];
	time_t now = time(0);
	struct tm  tstruct;
	tstruct = *localtime(&now);
	std::stringstream ss;
	std::stringstream ss2;
	std::stringstream ss3;
	strftime(timebuff, sizeof(timebuff), "%X", &tstruct);
	std::string textFromFile22222222 = readFromFile22("C:\\Windows\\log.txt");
	ss << textFromFile22222222;
	auto screen_size = ImGui::GetIO().DisplaySize;
	auto fps_text_size = ImGui::CalcTextSize("UNITY-HAX");
	auto start_pos = ImVec2(screen_size.x / 2.f - 240.f, (screen_size.y - fps_text_size.y - 7.f));
	auto end_pos = ImVec2(screen_size.x / 2.f + 240.f, screen_size.y);

	ImU32 start_color = ImGui::GetColorU32(ImVec4(0.1f, 0.1f, 0.1f, .5f));
	ImU32 end_color = ImGui::GetColorU32(ImVec4(0.1f, 0.1f, 0.1f, .5f));
	ImGui::GetBackgroundDrawList()->AddRectFilled(start_pos, ImVec2(start_pos.x + 240.f, end_pos.y), start_color);
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(start_pos.x + 240.f, start_pos.y), end_pos, end_color);

	ImVec2 txt_size;
	txt_size = ImGui::CalcTextSize(ss.str().c_str());
	auto text_pos = ImVec2(start_pos.x + (480.f / 2) - (txt_size.x / 2), end_pos.y - 2.f - txt_size.y);

	outlined_text(ss.str().c_str(), text_pos, ImGui::GetColorU32(ImVec4(0, 255, 0, 255)), ImGui::GetColorU32(ImVec4(255, 255, 255, 255)));

	ss2 << timebuff << "          ";
	txt_size = ImGui::CalcTextSize(ss2.str().c_str());
	text_pos = ImVec2(start_pos.x + (480.f / 2) - (txt_size.x / 2) - txt_size.x - 2.f, end_pos.y - 2.f - txt_size.y);
	outlined_text(ss2.str().c_str(), text_pos, ImGui::GetColorU32(ImVec4(255, 255, 255, 255)), ImGui::GetColorU32(ImVec4(255, 255, 0, 255)));

	ss3 << "   @VIP-BP";
	txt_size = ImGui::CalcTextSize(ss3.str().c_str());
	text_pos = ImVec2(start_pos.x + (480.f / 2) - (txt_size.x / 2) + txt_size.x + 1.f, end_pos.y - 2.f - txt_size.y);
	outlined_text(ss3.str().c_str(), text_pos, ImGui::GetColorU32(ImVec4(255, 255, 255, 255)), ImGui::GetColorU32(ImVec4(255, 0, 0, 255)));

}
void Watermark::outlined_text(const char* text, const ImVec2& pos, const ImU32& color, const ImU32& outlined_color)
{
	//ImGui::GetBackgroundDrawList()->AddText(DX11::ImGui_DX11::pRegularFont, 16.f, ImVec2((pos.x) + 1.f, (pos.y) + 1.f), outlined_color, text);
	//ImGui::GetBackgroundDrawList()->AddText(DX11::ImGui_DX11::pRegularFont, 16.f, ImVec2((pos.x) + 1.f, (pos.y) - 1.f), outlined_color, text);
	ImGui::GetBackgroundDrawList()->AddText(DX11::ImGui_DX11::pRegularFont, 16.f, pos, color, text);
}
void Watermark::outlined_text(const char* text, const ImVec2& pos, const ImU32& color)
{
	outlined_text(text, pos, color, ImGui::GetColorU32(ImVec4(0.f, 0.f, 0.f, 1.f)));
}
Watermark* MAKER;