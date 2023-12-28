#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <cstdint>

#include "../util/types.hpp"

class Renderer {
 private:
  static SDL_Renderer *m_pRenderer;

 public:
  static SDL_Renderer *get_renderer();

  bool init(SDL_Window *window, uint32_t flags);
  void clean_up();

  void set_render_color(SDL_Color color);

  void render_text(text text, int32_t scale = 1);
  void render_text_centered(text text, int32_t scale = 1);
};