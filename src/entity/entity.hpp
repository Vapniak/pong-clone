#pragma once

#include <SDL2/SDL_render.h>

#include "../gfx/renderer.hpp"
#include "../util/types.hpp"

class Entity {
 private:
 public:
  vec2 pos;

  virtual bool init();
  virtual void clean_up();

  virtual void update(float delta_time);
  virtual void render();
};