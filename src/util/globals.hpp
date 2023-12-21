#pragma once

#include <cstdint>
namespace globals {
constexpr uint32_t RENDERER_WIDTH = 384;
constexpr uint32_t RENDERER_HEIGHT = 224;

constexpr uint32_t UP_SCALE = 3;
constexpr uint32_t WINDOW_WIDTH = RENDERER_WIDTH * UP_SCALE;
constexpr uint32_t WINDOW_HEIGHT = RENDERER_HEIGHT * UP_SCALE;

constexpr const char* FONT_PATH = "res/fonts/Hack-Regular.ttf";
}  // namespace globals