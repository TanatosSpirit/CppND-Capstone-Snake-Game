#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>
#include "SDL_ttf.h"
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height, const int max_result);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);
  void RenderStartMenu(bool const &running);
  void UpdateWindowTitle(int score, int fps);

 private:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _sdl_window;
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _sdl_renderer;
  TTF_Font *_font;
  std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> _sdl_texture_1;
  std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> _sdl_texture_2;
  std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> _sdl_texture_3;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif