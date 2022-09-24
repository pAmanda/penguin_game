#include "../include/Music.h"

#include <utility>

Music::Music() {
    music = nullptr;
}

Music::Music(std::string file) {
    music = nullptr;
    open(std::move(file));
}

void Music::play(int times) {
    if (isOpen()) {
        if (Mix_PlayMusic(music, times)) {
            std::cout << SDL_GetError() << std::endl;
        }
    }
}


void Music::stop(int msToStop) {
    Mix_FadeOutMusic(msToStop);
}

void Music::open(std::string file) {

    auto *music = Mix_LoadMUS(file.c_str());

    if (music == nullptr) {
        std::cout << "Error music: " << SDL_GetError() << std::endl;

    } 
}

bool Music::isOpen() {
    return music != nullptr;
}

Music::~Music() {
   if (isOpen()) {
       Mix_FreeMusic(music);
   }
}
