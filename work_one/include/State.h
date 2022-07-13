#ifndef STATE_H

class State {
private:

    // Sprite bg;
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


#endif 