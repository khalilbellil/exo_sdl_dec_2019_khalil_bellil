#include <iostream>
#include "SDL2/SDL.h"
#include "GameObject.h"
#include "vector"
#include <fstream>
#include <time.h>

int main(int argc, char **argv) {
    //VARIABLES:
    const int WIDTH = 800;
    const int HEIGHT = 600;
    bool end = false;

    //

    //SDL INITIALISATION :
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }
    SDL_Window* window;
    SDL_Renderer* renderer;
    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0) {
        SDL_Log("Unable to create window and renderer SDL: %s", SDL_GetError());
        return 2;
    }
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    //VARIABLES:
    vector<GameObject*> gameObjects;


    //GAME LOOP:
    while (!end)
    {
        SDL_Event evt;
        if (SDL_PollEvent(&evt) == 1)
        {
            if (evt.type == SDL_KEYDOWN)
            {
                if (evt.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    end = true;
                }
                if (evt.key.keysym.scancode == SDL_SCANCODE_E){
                    //LIRE DANS LE FICHIER
                    std::ifstream fichierIn("save.khalil");
                    if (fichierIn) {
                        char c;
                        while (fichierIn.get(c))
                            if(c == '$')
                                cout << " ";
                            else
                                cout << c;
                    }
                }

            }
        }
    }

    //SDL QUIT:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    //
    return 0;
}