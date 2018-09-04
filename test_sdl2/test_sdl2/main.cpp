#include <iostream>
using namespace std;

#include "myWindow.h"
#include "myRect.h"
#include "SDL.h"
#include "SDL_image.h"

void printString(string s) {
    printf("%s\n", s.c_str());
}


void runEvents() {

}

// creates new SDL_Window object using given parameters
// format: (char*) title of window, (int) x-position of window, (int) y-position of window
// (int) width of window, (int) height of window, (int32) flags
SDL_Window *makeScreenWindow(char* title, int x, int y, int w, int h, Uint32 flags) {
    return SDL_CreateWindow(title, x, y, w, h, flags);
}

// creates new SDL_Renderer object using given parameters
// format: (SDL_Window) window, (int) index of window passed in, (Uint32 flags
SDL_Renderer *makeRenderer(SDL_Window* window, int index, Uint32 flags) {
    return SDL_CreateRenderer(window, index, flags);
}

void loadPNG(SDL_Window* window, SDL_Renderer* renderer, string filePath) {
    SDL_Surface *image;
    image = IMG_Load(filePath.c_str());
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

    bool quit = false;
    SDL_Event event;

    if (!image) {
        printf("%s Image failed to load, error: %s\n", "p1_stand.png", IMG_GetError());
    }
    else {
        while (!quit)
        {
            SDL_WaitEvent(&event);

            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            }

            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
        }

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(image);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

        SDL_Quit();
    }
}

void runSDL() {
    myWindow mainWindow(
        "title_pacman",
        1080,
        640
    );


    myRect rect(mainWindow, 120, 120, 100, 100, "Assets/Player/p1_stand.png");

    // while window is not closed, keep rendering
    while (!mainWindow.isClosed()) {
        rect.draw();
        mainWindow.clear();

        rect.pollEvents();
        mainWindow.pollEvents();
    }

    //SDL_Init(SDL_INIT_EVERYTHING);  // sets init state above all subsystems

    //SDL_Window *mainWindow = makeScreenWindow(
    //    "title_pacman",
    //    SDL_WINDOWPOS_CENTERED,
    //    SDL_WINDOWPOS_CENTERED,
    //    1080,
    //    640,
    //    SDL_WINDOW_SHOWN
    //);

    // window mainWindow, index (-1 is first supported window), flags 0 (default)
    //SDL_Renderer *mainRenderer = SDL_CreateRenderer(mainWindow._window, -1, 0);

    //SDL_SetRenderDrawColor(mainRenderer, 0, 255, 0, 255);
    //SDL_RenderClear(mainRenderer);
    //SDL_RenderPresent(mainRenderer);
    //SDL_Delay(3000);
    //loadPNG(mainWindow._window, mainRenderer, "Assets/Player/p1_stand.png");
}


int main(int argc, char *argv[]) {
    printString("Hello PacMan!!");
    runSDL();
    return 0;
}
