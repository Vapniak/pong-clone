#include "entity.hpp"

bool Entity::init() {
  pos = vec2i::zero();
  return true;
}

void Entity::clean_up() {}

void Entity::update(float delta_time) {}
void Entity::render() {}