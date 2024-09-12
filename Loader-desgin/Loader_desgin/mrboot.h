#pragma once

#include "DX11.h"
#include "DX11Window.h"
#include"icon.h"
#include"iconcpp.h"
#include"font.h"
#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"
#include "imgui_notify.h"
#include <sstream> 
class Watermark
{
public:
    void Show();
private:
    void outlined_text(const char* text, const ImVec2& pos, const ImU32& color);
    void outlined_text(const char* text, const ImVec2& pos, const ImU32& color, const ImU32& outlined_color);

};
extern Watermark* MAKER;