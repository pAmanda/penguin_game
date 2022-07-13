#include "State.h"

State::State() {
    quitRequested = false;

    // new Sprite();

}

bool State::getQuitRequested() {
    return quitRequested;
}

void State::loadAssets() {

}

void State::update(float dt) {

    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
}


void State::render() {
    bg.render();
}
