#pragma once

#include <string>

#include "SDL.h"
#include "SDL_image.h"
using namespace std;

class myWindow {
public:

    myWindow(const string &title, int width, int height);
    ~myWindow();    // destructor
    inline bool isClosed()const{ return _closed; };

    void pollEvents();
    void clear() const;

private:
    bool init();

private:
    string _title;
    int _width;
    int _height;
    SDL_Window *_window = nullptr;
    bool _closed = false;

protected:
    SDL_Renderer *_renderer = nullptr;
    SDL_Event event;

};