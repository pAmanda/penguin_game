#include "../include/Sprite.h"

#include <utility>
#include "../include/Game.h"


Sprite::Sprite(std::string file) {
    texture = nullptr;
    open(std::move(file));
}

Sprite::~Sprite() {
   if (texture != nullptr) {
       SDL_DestroyTexture(texture);
       texture = nullptr;
   }
}

void Sprite::open(std::string file) {

    // Handler already loaded texture
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    texture = IMG_LoadTexture(Game::getInstance().getRenderer(), file.c_str());

    if (texture == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        exit(1);
    }
        
    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height)) {
        std::cout << SDL_GetError() << std::endl;
        exit(1);
    }

    setClip(0, 0, width, height);
}

void Sprite::setClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::render(int x, int y) {
    SDL_Rect dstrect = {.x = x, .y = y, .w = clipRect.w, .h = clipRect.h};
  if (SDL_RenderCopyEx(Game::getInstance().getRenderer(), texture, &clipRect, &dstrect, 0, nullptr,
                         SDL_FLIP_NONE)) {
        std::cout << SDL_GetError() << std::endl;
    }
}


int Sprite::getHeight() {
    return height;
}

int Sprite::getWidth() {
    return width;
}

bool Sprite::isOpen() {
    return texture != nullptr;
}

