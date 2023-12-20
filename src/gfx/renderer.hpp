#pragma once

#include <SDL2/SDL.h>

#include <cstdint>

#include "../util/debug.hpp"

class Renderer {
 private:
  static SDL_Renderer* m_pRenderer;

 public:
  bool init(SDL_Window* window, uint32_t flags);
  void clean_up();

  void set_render_color(SDL_Color color);

  static SDL_Renderer* get_renderer();
};