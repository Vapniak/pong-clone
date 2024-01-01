#include "paddle.hpp"

#include <SDL2/SDL_stdinc.h>
#include <math.h>

#include <algorithm>

#include "../util/globals.hpp"

bool Paddle::init(vec2 pos, vec2i size, SDL_Color color) {
  this->pos = pos;
  this->size = size;
  this->color = color;

  return true;
}

void Paddle::update(float delta_time) {
  pos += vel * delta_time;
  pos.y =
      SDL_clamp(pos.y, 0, globals::RENDERER_HEIGHT - globals::PADDLE_HEIGHT);
}

void Paddle::render() {
  SDL_Rect rect = {(int32_t)pos.x, (int32_t)pos.y, size.x, size.y};
  SDL_RenderFillRect(Renderer::get_renderer(), &rect);
}