#ifndef STATE_H
#define STATE_H

#include "../include/Sprite.h"

class State {
private:

    Sprite *bg;
    // Music music;
    bool quitRequested;

public:
    State();

    ~State();

    bool getQuitRequested();

    void loadAssets();

    void update(float dt);

    void render();

};


#endif //STATE_H