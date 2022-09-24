#include "../include/Assets.h"

std::string Assets::getImg(std::string path) {
    return "./assets/img/" + path;
}

std::string Assets::getAudio(std::string path) {
    return "./assets/audio/" + path;
}