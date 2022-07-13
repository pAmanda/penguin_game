#include <iostream>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "SDL_include.h"
#include "Game.h"

using namespace std;

Game* Game::instance = nullptr;

Game::Game(string title, int width, int height) {
    //Singleton
    if (instance != nullptr) {
        return instance;
    }

   if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        cout << "Error whiling init SDL. Cause: " << SDL_GetError() << endl;
        exit(1);
    }

    //Image libraries
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) != 
        IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) {
        cout << "Error whiling init SDL_IMAGE. Cause: " << SDL_GetError() << endl;
        exit(1);
    }

    int flags = (MIX_INIT_OGG);
    int mixInit = Mix_Init(flags)
    if (minInit != flags) {
        cout << "Error whiling init Mix_Init. Cause:  " << SDL_GetError() << endl;
        exit(1);
    }
    
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
        cout << "Error whiling init Mix_OpenAudio. Cause:  " << SDL_GetError() << endl;
        exit(1);
    }
    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == nullptr) {
        cout << "Error whiling init SDL_CreateWindow. Cause:  " << SDL_GetError() << endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        cout << "Error whiling init SDL_CreateRenderer. Cause:  " << SDL_GetError() << endl;
        exit(1);
    }


}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}
