#include <string>
#include <iostream>

#include "myRect.h"
#include "SDL_image.h"

using namespace std;

myRect::myRect(const myWindow &window, int w, int h, int x, int y, const string &img_path): 
    myWindow(window), _w(w), _h(h), _x(x), _y(y), _img_path(img_path)
{
    // using auto returns the type result from IMG_Load
    auto surface = IMG_Load(img_path.c_str());

    if (!surface) {
        cerr << "error creating surface for image " << img_path << "\n.";
    }

    _texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (!_texture) {
        cerr << "error creating texture for image " << img_path << "\n.";
    }

    SDL_FreeSurface(surface);
}

myRect::~myRect() {
    SDL_DestroyTexture(_texture);
}

void myRect::pollEvents() {
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_w:
                cout << "You clicked W\n";
                _y -= 10;
                break;
            case SDLK_a:
                cout << "You clicked A\n";
                _x -= 10;
                break;
            case SDLK_s:
                cout << "You clicked S\n";
                _y += 10;
                break;
            case SDLK_d:
                cout << "You clicked D\n";
                _x += 10;
                break;
            default:
                break;
            }
        }
    }
}

void myRect::draw() const {
    SDL_Rect rect;
    rect.w = _w;
    rect.h = _h;
    rect.x = _x;
    rect.y = _y;

    SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);
    SDL_RenderFillRect(_renderer, &rect);
}
