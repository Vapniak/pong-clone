#pragma once

#include "SDL2/SDL_ttf.h"
#include "gfx/renderer.hpp"
#include "gfx/window.hpp"
#include "util/types.hpp"

class Game {
 private:
  bool m_running;

  Renderer m_renderer;
  Window m_window;

  bool init();
  void clean_up();

  void input();
  void update();
  void render();

  void loop();

 public:
  void run();
};