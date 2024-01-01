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

  static vec2i zero() { return vec2i(0, 0); }

  vec2i& operator+=(vec2i val) {
    x += val.x;
    y += val.y;
    return *this;
  }
};

struct vec2 {
  float x, y;

  vec2() = default;
  vec2(float x, float y) : x(x), y(y) {}

  static vec2 zero() { return vec2(0, 0); }

  vec2 operator*(float val) { return vec2(x * val, y * val); }
  vec2& operator+=(vec2 val) {
    x += val.x;
    y += val.y;
    return *this;
  }
};