#include <iostream>
using namespace std;

#include "SDL.h"

void printString(string s) {
    printf("%s\n", s.c_str());
}

// format: (char*) title of window, (int) x-position of window, (int) y-position of window
// (int) width of window, (int) height of window, (int32) flags
//SDL_Window *getScreenWindow(char* title, int x, int y, int w, int h, Uint32 flags) {
//    return SDL_CreateWindow(title, x, y, w, h, flags);
//}

void runSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);  // sets init state above all subsystems

    SDL_Window *mainWindow = SDL_CreateWindow(
        "title_pacman",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        600,
        400,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer *mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);

    SDL_SetRenderDrawColor(mainRenderer, 0, 255, 0, 255);
    SDL_RenderClear(mainRenderer);
    SDL_RenderPresent(mainRenderer);
    SDL_Delay(3000);
}


int main(int argc, char *argv[]) {
    printString("Hello PacMan!!");
    runSDL();
    return 0;
}
