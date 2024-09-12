// GradientEffect.hpp

#ifndef GRADIENT_EFFECT_HPP
#define GRADIENT_EFFECT_HPP

#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include <vector>

namespace Gradient {

    struct vec3 {
        float x, y, z;
        vec3() : x(0), y(0), z(0) {}
        vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    };

    class GradientEffect {
    public:
        vec3 position;
        float width, height;
        float speed;
        ImU32 startColor, endColor;
        float offset;

        GradientEffect(float _width, float _height, float _speed, ImU32 _startColor, ImU32 _endColor)
            : width(_width), height(_height), speed(_speed), startColor(_startColor), endColor(_endColor), offset(0.f) {}

        void Update();
        void Render();
    };

    void CreateGradientEffects(std::vector<GradientEffect>& gradients, uint64_t limit, float _width, float _height, float _speed, ImU32 _startColor, ImU32 _endColor);

}

#endif // GRADIENT_EFFECT_HPP
