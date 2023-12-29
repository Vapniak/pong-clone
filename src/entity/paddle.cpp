#include "paddle.hpp"

bool Paddle::init(vec2i pos, vec2i size, SDL_Color color) {
  this->pos = pos;
  this->size = size;
  this->color = color;

  return true;
}

void Paddle::update(float delta_time) { pos += (vec2i)(vel * delta_time); }

void Paddle::render() {
  SDL_Rect rect = {pos.x, pos.y, size.x, size.y};
  SDL_RenderFillRect(Renderer::get_renderer(), &rect);
}