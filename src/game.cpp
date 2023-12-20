#include "game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

#include "util/colors.hpp"
#include "util/debug.hpp"
#include "util/globals.hpp"

bool Game::init() {
  SDL_Init(SDL_INIT_VIDEO);

  if (!m_window.init("Pong", globals::WINDOW_WIDTH, globals::WINDOW_HEIGHT,
                     SDL_WINDOW_SHOWN)) {
    return false;
  }

  if (!m_renderer.init(m_window.get_window(), SDL_RENDERER_PRESENTVSYNC)) {
    return false;
  }

  m_running = true;

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
  SDL_Quit();
}

void Game::update() {}

void Game::render() {
  m_renderer.set_render_color(colors::BLACK);
  SDL_RenderClear(m_renderer.get_renderer());

  // render here
  m_renderer.set_render_color(colors::WHITE);

  // draw net
  for (uint32_t y = 0; y < globals::RENDERER_HEIGHT; y++) {
    if (y % 5 != 0) {
      SDL_RenderDrawPoint(m_renderer.get_renderer(),
                          globals::RENDERER_WIDTH / 2, y);
    }
  }

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