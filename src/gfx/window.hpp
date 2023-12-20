#pragma once

#include <SDL2/SDL_video.h>

#include <cstdint>

class Window {
 private:
  static SDL_Window* m_pWindow;

 public:
  bool init(const char* title, uint32_t width, uint32_t height, uint32_t flags);
  void clean_up();

  static SDL_Window* get_window();
};