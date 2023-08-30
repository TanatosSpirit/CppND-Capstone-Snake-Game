#include "startscreen.h"

StartScreen::StartScreen() :  _sdl_texture_play(nullptr, SDL_DestroyTexture),
                _sdl_texture_exit(nullptr, SDL_DestroyTexture),
                _sdl_texture_score(nullptr, SDL_DestroyTexture) {
}

void StartScreen::Play(SDL_Texture *ptr) {
  _sdl_texture_play.reset(ptr);
}

SDL_Texture* StartScreen::Play() {
  return _sdl_texture_play.get();
}

void StartScreen::Exit(SDL_Texture *ptr) {
  _sdl_texture_exit.reset(ptr);
}

SDL_Texture *StartScreen::Exit() {
  return _sdl_texture_exit.get();
}

void StartScreen::Score(SDL_Texture *ptr) {
  _sdl_texture_score.reset(ptr);
}

SDL_Texture *StartScreen::Score() {
  return _sdl_texture_score.get();
}

StartScreen::~StartScreen() = default;
