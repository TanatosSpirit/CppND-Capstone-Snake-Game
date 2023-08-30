#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <memory>
#include "SDL.h"

class StartScreen {
public:
    StartScreen();
    ~StartScreen();

    void Play(SDL_Texture *);
    SDL_Texture* Play();

    void Exit(SDL_Texture *);
    SDL_Texture* Exit();

    void Score(SDL_Texture *);
    SDL_Texture* Score();
private:
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> _sdl_texture_play;
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> _sdl_texture_exit;
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> _sdl_texture_score;
};


#endif
