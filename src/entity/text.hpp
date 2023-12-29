#pragma once

#include "entity.hpp"

class text : public Entity {
 private:
  std::string m_str;

  vec2i m_size;

  TTF_Font* m_pFont;
  SDL_Color m_color;
  SDL_Texture* m_pTexture;

 public:
  inline std::string get_str() { return m_str; }
  void set_str(std::string str);

  inline vec2i get_size() { return m_size; }

  inline TTF_Font* get_font() { return m_pFont; }
  inline SDL_Color get_color() { return m_color; }
  inline SDL_Texture* get_texture() { return m_pTexture; }

  bool init(TTF_Font* font, std::string str, vec2i pos, SDL_Color color);
  void clean_up() override;

  void render_centered();
};