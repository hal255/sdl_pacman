
#include <string>
#include <iostream>
#include "myWindow.h"
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

// constructor
myWindow::myWindow(const string &title, int width, int height):
    // initialize variables
    _title(title), _width(width), _height(height)
{
    _closed = !init();
}

// creates SDL window
bool myWindow::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "failed to create SDL window\n";
        return false;
    }

    // verify PNG file support
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        cerr << "failed to read PNG files\n";
        return false;
    }

    _window = SDL_CreateWindow(
        _title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _width, _height,
        0
    );

    if (_window == nullptr) {
        cerr << "failed to create SDL window\n";
        return false;
    }

    // window mainWindow, index (-1 is first supported window), flags 0 (default)
    _renderer = SDL_CreateRenderer(_window, -1, 0);

    if (_renderer == nullptr) {
        cerr << "failed to create SDL renderer\n";
        return false;
    }

    return true;
}

// close all SDL windows
myWindow::~myWindow() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();     // quit out of SDL image
    SDL_Quit();
}

void myWindow::clear() const {
    SDL_RenderPresent(_renderer);                       // puts everything onto screen
    SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);  // set color of renderer
    SDL_RenderClear(_renderer);                         // get color onto renderer

    //SDL_Rect rect;
    //rect.w = 120;
    //rect.h = 120;
    //rect.x = _width / 2;
    //rect.y = _height / 2;

    //SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);
    //SDL_RenderFillRect(_renderer, &rect);

}

void myWindow::pollEvents() {
    if (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            _closed = true;
            break;
        case SDL_KEYDOWN:
            cout << "You Pressed a key\n";
            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                _closed = true;
                break;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
            cout << "You clicked your mouse\n";
            break;
        default:
            break;
        }
    }

}