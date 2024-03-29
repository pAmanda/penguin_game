#ifndef STATE_H
#define STATE_H

#include "../include/Sprite.h"
#include "../include/Music.h"


class State {
private:

    Sprite *bg;
    Music *music;
    bool quitRequested;

public:
    State();

    ~State();

    bool getQuitRequested();

    void loadAssets();

    void update(float dt);

    void render();

    void play();

};


#endif //STATE_H