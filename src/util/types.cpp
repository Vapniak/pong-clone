#include "types.hpp"

#include <SDL2/SDL_render.h>

#include "../gfx/renderer.hpp"
#include "../util/debug.hpp"

text* create_text(TTF_Font* font, std::string str, int32_t x, int32_t y,
                  SDL_Color color) {
  text* text = new struct text();

  text->font = font;
  text->x = x;
  text->y = y;
  text->color = color;
  TTF_SizeText(text->font, str.c_str(), &text->w, &text->h);

  SDL_Surface* surface =
      TTF_RenderText_Blended(text->font, str.c_str(), text->color);

  text->texture =
      SDL_CreateTextureFromSurface(Renderer::get_renderer(), surface);

  if (text->texture == nullptr) {
    debug::log("Could not create text texture. Error: ", SDL_GetError());
  }
  SDL_FreeSurface(surface);
  return text;
}

void set_text(text* self, std::string str) {
  TTF_SizeText(self->font, str.c_str(), &self->w, &self->h);

  SDL_Surface* surface =
      TTF_RenderText_Blended(self->font, str.c_str(), self->color);

  self->texture =
      SDL_CreateTextureFromSurface(Renderer::get_renderer(), surface);

  if (self->texture == nullptr) {
    debug::log("Could not create text texture. Error: ", SDL_GetError());
  }
  SDL_FreeSurface(surface);
}

void destroy_text(text* self) {
  SDL_DestroyTexture(self->texture);
  TTF_CloseFont(self->font);
  delete self;
}