#include "game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_scancode.h>
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

  if (!m_renderer.init(Window::get_window(), SDL_RENDERER_PRESENTVSYNC)) {
    return false;
  }

  m_pScoreFont = TTF_OpenFont(globals::FONT_PATH, 21);
  if (m_pScoreFont == nullptr) {
    debug::error("Could not open ", globals::FONT_PATH,
                 " font. Error: ", TTF_GetError());
    return false;
  }

  if (!m_score_left_text.init(m_pScoreFont, "0", vec2::zero(), colors::WHITE)) {
    return false;
  }

  if (!m_score_right_text.init(m_pScoreFont, "0", vec2::zero(),
                               colors::WHITE)) {
    return false;
  }

  m_score_left_text.pos =
      vec2(globals::RENDERER_WIDTH / 4.0, globals::RENDERER_HEIGHT / 4.0);
  m_score_right_text.pos =
      vec2(3 * globals::RENDERER_WIDTH / 4.0, globals::RENDERER_HEIGHT / 4.0);

  m_score_left = m_score_right = 0;

  m_paddle_left = new Paddle();
  if (!m_paddle_left->init(
          vec2(0, (globals::RENDERER_HEIGHT - globals::PADDLE_HEIGHT) / 2.0),
          vec2i(globals::PADDLE_WIDTH, globals::PADDLE_HEIGHT),
          colors::WHITE)) {
    return false;
  }

  m_paddle_right = new Paddle();
  if (!m_paddle_right->init(
          vec2(globals::RENDERER_WIDTH - globals::PADDLE_WIDTH,
               (globals::RENDERER_HEIGHT - globals::PADDLE_HEIGHT) / 2.0),
          vec2i(globals::PADDLE_WIDTH, globals::PADDLE_HEIGHT),
          colors::WHITE)) {
    return false;
  }

  m_input_left = m_input_right = 0;

  m_delta_time = 0;
  m_running = true;

  return true;
}

const uint8_t* keyboard;
SDL_Event e;
void Game::input() {
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        m_running = false;
        break;
    }
  }

  SDL_PumpEvents();
  keyboard = SDL_GetKeyboardState(NULL);

  m_input_left = keyboard[SDL_SCANCODE_S] - keyboard[SDL_SCANCODE_W];
  m_input_right = keyboard[SDL_SCANCODE_DOWN] - keyboard[SDL_SCANCODE_UP];
}

void Game::clean_up() {
  m_renderer.clean_up();
  m_window.clean_up();

  m_score_left_text.clean_up();
  m_score_right_text.clean_up();

  m_paddle_left->clean_up();
  m_paddle_right->clean_up();

  TTF_CloseFont(m_pScoreFont);

  TTF_Quit();
  SDL_Quit();
}
void Game::update() {
  m_score_left_text.set_str(std::to_string(m_score_left));
  m_score_right_text.set_str(std::to_string(m_score_right));

  m_paddle_left->vel.y = m_input_left * globals::PADDLE_SPEED;
  m_paddle_right->vel.y = m_input_right * globals::PADDLE_SPEED;

  m_paddle_left->update(m_delta_time);
  m_paddle_right->update(m_delta_time);
}

void Game::render() {
  m_renderer.set_render_color(colors::BLACK);
  SDL_RenderClear(Renderer::get_renderer());

  m_renderer.set_render_color(colors::WHITE);

  for (uint32_t y = 0; y < globals::RENDERER_HEIGHT; y++) {
    if (y % 5 != 0) {
      SDL_RenderDrawPoint(Renderer::get_renderer(), globals::RENDERER_WIDTH / 2,
                          y);
    }
  }

  m_score_left_text.render_centered();
  m_score_right_text.render_centered();

  m_paddle_left->render();
  m_paddle_right->render();

  SDL_RenderPresent(Renderer::get_renderer());
}

void Game::loop() {
  uint32_t frame_start = 0;
  while (m_running) {
    m_delta_time = (SDL_GetTicks() - frame_start) / 1000.0;
    frame_start = SDL_GetTicks();
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
