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

struct text {
  int32_t x, y, w, h;

  std::string str;

  TTF_Font* font;
  SDL_Texture* texture;
  SDL_Color color;
};

text* create_text(TTF_Font* font, std::string str, int32_t x, int32_t y,
                  SDL_Color color);
void set_text(text* self, std::string str);
void destroy_text(text* self);