#pragma once

#include <cstdint>
namespace globals {
constexpr uint32_t RENDERER_WIDTH = 384;
constexpr uint32_t RENDERER_HEIGHT = 224;

constexpr uint32_t UP_SCALE = 3;
constexpr uint32_t WINDOW_WIDTH = RENDERER_WIDTH * UP_SCALE;
constexpr uint32_t WINDOW_HEIGHT = RENDERER_HEIGHT * UP_SCALE;

constexpr int32_t PADDLE_SPEED = 200;
constexpr uint32_t PADDLE_WIDTH = 5, PADDLE_HEIGHT = 30;

constexpr const char* FONT_PATH = "res/fonts/VCR_OSD_MONO.ttf";
}  // namespace globals