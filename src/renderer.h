#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
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
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  TTF_Font *font;
  SDL_Surface *surface;
  SDL_Texture *texture_1;
  SDL_Texture *texture_2;
  SDL_Texture *texture_3;
  int max_result;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif