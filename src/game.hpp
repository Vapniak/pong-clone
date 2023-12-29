#pragma once

#include <SDL2/SDL_ttf.h>

#include "entity/paddle.hpp"
#include "entity/text.hpp"
#include "gfx/renderer.hpp"
#include "gfx/window.hpp"
#include "util/types.hpp"

class Game {
 private:
  bool m_running;

  Renderer m_renderer;
  Window m_window;

  TTF_Font* m_pScoreFont;
  text m_score_left_text, m_score_right_text;
  uint32_t m_score_left, m_score_right;

  Paddle m_paddle_left;

  bool init();
  void clean_up();

  void input();
  void update();
  void render();

  void loop();

 public:
  void run();
};