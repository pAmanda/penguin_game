#ifndef MUSIC_H
#define MUSIC_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include "SDL_include.h"
#include "iostream"

class Music {
private:
    Mix_Music *music;

public:
    Music();

    Music(std::string file);

    ~Music();

    void play(int times = -1);

    void stop(int msTopStop = 1500);

    void open(std::string file);

    bool isOpen();

};


#endif //MUSIC_H