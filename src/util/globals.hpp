#pragma once

#include <cstdint>
namespace globals {
constexpr uint32_t RENDERER_WIDTH = 384;
constexpr uint32_t RENDERER_HEIGHT = 224;

constexpr uint32_t SIZE_MULTI = 3;
constexpr uint32_t WINDOW_WIDTH = RENDERER_WIDTH * SIZE_MULTI;
constexpr uint32_t WINDOW_HEIGHT = RENDERER_HEIGHT * SIZE_MULTI;
}  // namespace globals