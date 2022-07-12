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

}
