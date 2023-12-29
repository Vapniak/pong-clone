#include "renderer.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

#include "../util/debug.hpp"
#include "../util/globals.hpp"

SDL_Renderer* Renderer::m_pRenderer;

bool Renderer::init(SDL_Window* window, uint32_t flags) {
  m_pRenderer = SDL_CreateRenderer(window, -1, flags);

  if (m_pRenderer == nullptr) {
    debug::error("Could not create renderer. Error: ", SDL_GetError());
    return false;
  }

  SDL_RenderSetLogicalSize(m_pRenderer, globals::RENDERER_WIDTH,
                           globals::RENDERER_HEIGHT);

  return true;
}

void Renderer::clean_up() { SDL_DestroyRenderer(m_pRenderer); }

void Renderer::set_render_color(SDL_Color color) {
  SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, color.a);
}