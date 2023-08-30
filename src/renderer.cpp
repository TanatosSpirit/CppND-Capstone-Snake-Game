#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height,
                   const int max_result)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height),
      _sdl_window(nullptr, SDL_DestroyWindow){

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  if (TTF_Init() < 0)
  {
    std::cerr << "SDL_TTF could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  _sdl_window.reset(SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 screen_width, screen_height, SDL_WINDOW_SHOWN));

  if (_sdl_window == nullptr) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(_sdl_window.get(), -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  font = TTF_OpenFont("../font/arial.ttf", 25);
  if(font == nullptr){
    std::cerr << "Font was not found.\n";
    exit(EXIT_FAILURE);
  }

  // Render text
  SDL_Color color = { 255, 255, 255 };
  texture_1 = SDL_CreateTextureFromSurface(sdl_renderer, TTF_RenderText_Solid(font,"PLAY", color));
  texture_2 = SDL_CreateTextureFromSurface(sdl_renderer, TTF_RenderText_Solid(font,"EXIT", color));
  std::string top_result = std::string{"HI-SCORE "} + std::to_string(max_result);
  texture_3 = SDL_CreateTextureFromSurface(sdl_renderer, TTF_RenderText_Solid(font, top_result.c_str(), color));
}

Renderer::~Renderer() {
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_DestroyTexture(texture_1);
  SDL_DestroyTexture(texture_2);
  SDL_FreeSurface(surface);
  SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::RenderStartMenu(bool const &running){
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  SDL_Rect message_rect_1;
  SDL_Rect message_rect_2;
  SDL_Rect message_rect_3;

  message_rect_1.x = 180;
  message_rect_1.y = 370;
  message_rect_1.w = 300;
  message_rect_1.h = 70;

  message_rect_2.x = 180;
  message_rect_2.y = 435;
  message_rect_2.w = 300;
  message_rect_2.h = 70;

  message_rect_3.x = 180;
  message_rect_3.y = 30;
  message_rect_3.w = 300;
  message_rect_3.h = 90;

  // Update Screen
  if(SDL_RenderCopy(sdl_renderer, texture_1, NULL, &message_rect_1) < 0)
    std::cerr << "SDL_RenderCopy ERROR.\n";

  if(SDL_RenderCopy(sdl_renderer, texture_2, NULL, &message_rect_2) < 0)
    std::cerr << "SDL_RenderCopy ERROR.\n";

  if(SDL_RenderCopy(sdl_renderer, texture_3, NULL, &message_rect_3) < 0)
    std::cerr << "SDL_RenderCopy ERROR.\n";

  SDL_Rect block_1;
  block_1.w = 50;
  block_1.h = 50;

  block_1.x = 110;
  block_1.y = 380;

  SDL_Rect block_2;
  block_2.w = 50;
  block_2.h = 50;

  block_2.x = 110;
  block_2.y = 445;

  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  if(running)
    SDL_RenderFillRect(sdl_renderer, &block_1);
  else
    SDL_RenderFillRect(sdl_renderer, &block_2);

  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(_sdl_window.get(), title.c_str());
}
