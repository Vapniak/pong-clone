#include "types.hpp"

#include <SDL2/SDL_render.h>

#include <string>

#include "../gfx/renderer.hpp"
#include "../util/debug.hpp"

bool text::init(TTF_Font* font, std::string str, vec2i pos, SDL_Color color) {
  if (font == nullptr) {
    debug::error("Font is null.");
    return false;
  }
  m_pFont = font;
  m_str = str;
  this->pos = pos;
  m_color = color;

  TTF_SizeText(m_pFont, m_str.c_str(), &m_size.x, &m_size.y);

  SDL_Surface* surface = TTF_RenderText_Solid(m_pFont, m_str.c_str(), m_color);

  if (surface == nullptr) {
    debug::error("Could not create text surface. Error: ", TTF_GetError());
    return false;
  }

  m_pTexture = SDL_CreateTextureFromSurface(Renderer::get_renderer(), surface);

  if (m_pTexture == nullptr) {
    debug::error("Could not create text texture from surface. Error: ",
                 SDL_GetError());
    return false;
  }
  SDL_FreeSurface(surface);

  return true;
}

void text::clean_up() { SDL_DestroyTexture(m_pTexture); }

void text::set_str(std::string str) {
  m_str = str;

  TTF_SizeText(m_pFont, m_str.c_str(), &m_size.x, &m_size.y);

  SDL_Surface* surface = TTF_RenderText_Solid(m_pFont, m_str.c_str(), m_color);

  if (surface == nullptr) {
    debug::error("Could not create text surface. Error: ", TTF_GetError());
  }

  m_pTexture = SDL_CreateTextureFromSurface(Renderer::get_renderer(), surface);

  if (m_pTexture == nullptr) {
    debug::error("Could not create text texture from surface. Error: ",
                 SDL_GetError());
  }
  SDL_FreeSurface(surface);
}