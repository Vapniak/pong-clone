#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

#include <cstdint>
#include <string>

struct vec2i {
  int32_t x, y;

  vec2i() = default;
  vec2i(int32_t x, int32_t y) : x(x), y(y) {}
};