#include "game.hpp"

#include <SDL2/SDL.h>
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
//test
  if (!m_window.init("Pong", globals::WINDOW_WIDTH, globals::WINDOW_HEIGHT,
                     SDL_WINDOW_SHOWN)) {
    return false;
  }

  if (!m_renderer.init(m_window.get_window(), SDL_RENDERER_PRESENTVSYNC)) {
    return false;
  }

  m_running = true;

  TTF_Font* font = TTF_OpenFont(globals::FONT_PATH, 16);
  m_pScore_left = create_text(font, "0", 0, 0, colors::WHITE);
  m_pScore_left->x = globals::RENDERER_WIDTH / 4 - m_pScore_left->w / 2;
  m_pScore_left->y = globals::RENDERER_HEIGHT / 4 - m_pScore_left->h / 2;

  m_pScore_right = create_text(font, "0", 0, 0, colors::WHITE);
  m_pScore_right->x = 3 * globals::RENDERER_WIDTH / 4 - m_pScore_right->w / 2;
  m_pScore_right->y = globals::RENDERER_HEIGHT / 4 - m_pScore_right->h / 2;

  return true;
}

SDL_Event event;
void Game::input() {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      m_running = false;
    }
  }
}

void Game::clean_up() {
  m_renderer.clean_up();
  m_window.clean_up();

  destroy_text(m_pScore_left);
  destroy_text(m_pScore_right);

  TTF_Quit();
  SDL_Quit();
}
void Game::update() {}

void Game::render() {
  m_renderer.set_render_color(colors::BLACK);
  SDL_RenderClear(m_renderer.get_renderer());

  // render here
  m_renderer.set_render_color(colors::WHITE);

  m_renderer.draw_net();

  m_renderer.render_text(m_pScore_left);
  m_renderer.render_text(m_pScore_right);

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
