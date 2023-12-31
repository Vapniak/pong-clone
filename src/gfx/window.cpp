#include "window.hpp"

#include <SDL2/SDL_video.h>

#include "../util/debug.hpp"

SDL_Window *Window::m_pWindow;

bool Window::init(const char *title, uint32_t width, uint32_t height,
                  uint32_t flags) {
  m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, width, height, flags);
  if (m_pWindow == nullptr) {
    debug::error("Could not create window. Error: ", SDL_GetError());
    return false;
  }

  return true;
}

void Window::clean_up() { SDL_DestroyWindow(m_pWindow); }
