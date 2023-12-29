#pragma once

#include <SDL2/SDL_render.h>

#include "entity.hpp"

class Paddle : public Entity {
 public:
  vec2 vel;
  vec2i size;

  SDL_Color color;

  bool init(vec2i pos, vec2i size, SDL_Color color);

  void update(float delta_time) override;
  void render() override;
};