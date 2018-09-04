#pragma once

#include <string>
#include "myWindow.h"

using namespace std;

class myRect : public myWindow {
public:
    myRect(const myWindow &window, int w, int h, int x, int y, const string &img_path);
    ~myRect();

    void draw() const;
    void pollEvents();

private:
    int _w, _h;
    int _x, _y;
    string _img_path;
    SDL_Texture *_texture = nullptr;
};