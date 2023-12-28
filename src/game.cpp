#include "game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

#include <string>

#include "util/colors.hpp"
#include "util/debug.hpp"
#include "util/globals.hpp"
#include "util/types.hpp"

bool Game::init() {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  if (!m_window.init("Pong", globals::WINDOW_WIDTH, globals::WINDOW_HEIGHT,
                     0)) {
    return false;
  }

  if (!m_renderer.init(m_window.get_window(), SDL_RENDERER_PRESENTVSYNC)) {
    return false;
  }

  m_pScoreFont = TTF_OpenFont(globals::FONT_PATH, 21);
  if (m_pScoreFont == nullptr) {
    debug::error("Could not open ", globals::FONT_PATH,
                 " font. Error: ", TTF_GetError());
    return false;
  }

  if (!m_score_left_text.init(m_pScoreFont, "0", vec2i::zero(),
                              colors::WHITE)) {
    return false;
  }
  m_score_left_text.pos =
      vec2i(globals::RENDERER_WIDTH / 4, globals::RENDERER_HEIGHT / 4);

  if (!m_score_right_text.init(m_pScoreFont, "0", vec2i::zero(),
                               colors::WHITE)) {
    return false;
  }
  m_score_right_text.pos =
      vec2i(3 * globals::RENDERER_WIDTH / 4, globals::RENDERER_HEIGHT / 4);

  m_score_left = m_score_right = 0;

  m_running = true;

  return true;
}

SDL_Event event;
void Game::input() {
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        m_running = false;
        break;
    }
  }
}

void Game::clean_up() {
  m_renderer.clean_up();
  m_window.clean_up();

  m_score_left_text.clean_up();
  m_score_right_text.clean_up();

  TTF_CloseFont(m_pScoreFont);

  TTF_Quit();
  SDL_Quit();
}
void Game::update() {
  m_score_left_text.set_str(std::to_string(m_score_left));
  m_score_right_text.set_str(std::to_string(m_score_right));
}

void Game::render() {
  m_renderer.set_render_color(colors::BLACK);
  SDL_RenderClear(m_renderer.get_renderer());

  m_renderer.set_render_color(colors::WHITE);

  for (uint32_t y = 0; y < globals::RENDERER_HEIGHT; y++) {
    if (y % 5 != 0) {
      SDL_RenderDrawPoint(m_renderer.get_renderer(),
                          globals::RENDERER_WIDTH / 2, y);
    }
  }

  m_renderer.render_text_centered(m_score_left_text, 2);
  m_renderer.render_text_centered(m_score_right_text, 2);

  SDL_RenderPresent(m_renderer.get_renderer());
}

void Game::loop() {
  while (m_running) {
    input();
    update();
    render();
  }
}

void Game::run() {
  if (!init()) {
    return;
  }
  loop();
  clean_up();
}
