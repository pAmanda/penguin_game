#include "../include/State.h"
#include "../include/Assets.h"

State::State() {
    quitRequested = false;

    bg = new Sprite(Assets::getImg("ocean.jpg"));

    music = new Music(Assets::getAudio("stageState.ogg"));
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
    bg->render(0, 0);
}

void State::play() {
    music->play();
}

