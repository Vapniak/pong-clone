#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <cstdint>

#include "../util/types.hpp"

class Renderer {
 private:
  static SDL_Renderer *m_pRenderer;

 public:
  inline static SDL_Renderer *get_renderer() { return m_pRenderer; }

  bool init(SDL_Window *window, uint32_t flags);
  void clean_up();

  void set_render_color(SDL_Color color);
};