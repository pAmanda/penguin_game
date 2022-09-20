#ifndef IDJ_ENGINE_GAME_H
#define IDJ_ENGINE_GAME_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "../include/SDL_include.h"
#include "../include/State.h"
#include <iostream>

class Game {

private:
    static Game *instance;
    SDL_Window *window{};
    SDL_Renderer *renderer{};
    State *state;
    int frameStart;
    float dt;

public:
    explicit Game(std::string title, int width, int height);

    ~Game();

    void run();

    SDL_Renderer *getRenderer();

    State &getState();

    static Game &getInstance();
    
    void calculateDeltaTime();

};

#endif //IDJ_ENGINE_GAME_H