#include <iostream>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "SDL_include.h"
#include "../include/Game.h"

using namespace std;

Game* Game::instance = nullptr;

Game::Game(std::string title, int width, int height) {
    //Singleton
    if (instance != nullptr) {
      throw "Game already initialize";
    }

    frameStart = 0;
    dt = 0;
    instance = this;

   if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        cout << "Error whiling init SDL. Cause: " << SDL_GetError() << endl;
        exit(1);
    }

    //Image libraries
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

    int flags = (MIX_INIT_OGG);
    int mixInit = Mix_Init(flags);
    if (mixInit != flags) {
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

    state = new State();


}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}


void Game::run() {
    while (!state->getQuitRequested()) {
        calculateDeltaTime();
        state->update(dt);
        state->render();
        state->play();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}

void Game::calculateDeltaTime() {
    auto actualFrame = SDL_GetTicks();
    actualFrame *= 100;
    dt = actualFrame - frameStart;
    frameStart = actualFrame;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

Game &Game::getInstance() {
    if (instance != nullptr) {
        return *instance;
    } else {
        instance = new Game("Amanda - 150004796", 1024, 600);
    }
    return *instance;
}


State &Game::getState() {
    return *state;
}

