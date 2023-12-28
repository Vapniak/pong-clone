#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

#include <cstdint>
#include <string>

struct vec2i {
  int32_t x, y;

  vec2i() = default;
  vec2i(int32_t x, int32_t y) : x(x), y(y) {}

  static vec2i zero() { return vec2i(0, 0); }
};

class text {
 private:
  std::string m_str;
  vec2i m_size;

  SDL_Color m_color;
  SDL_Texture* m_pTexture;
  TTF_Font* m_pFont;

 public:
  vec2i pos;

  inline std::string get_str() { return m_str; }
  void set_str(std::string str);

  inline vec2i get_size() { return m_size; }
  inline SDL_Color get_color() { return m_color; }
  inline SDL_Texture* get_texture() { return m_pTexture; }
  inline TTF_Font* get_font() { return m_pFont; }

  bool init(TTF_Font* font, std::string str, vec2i pos, SDL_Color color);
  void clean_up();
};