#pragma once

#include "gfx/renderer.hpp"
#include "gfx/window.hpp"

class Game {
 private:
  bool m_running;

  Renderer m_renderer;
  Window m_window;

 private:
  bool init();
  void clean_up();

  void input();
  void update();
  void render();

  void loop();

 public:
  void run();
};