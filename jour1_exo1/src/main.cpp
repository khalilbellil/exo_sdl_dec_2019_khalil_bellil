#include <iostream>
#include "SDL2/SDL.h"
#include "GameObject.h"
#include "vector"
#include <fstream>
#include <time.h>

using namespace std;

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
    ofstream fichier1Input("save.khalil", ios::app);
    //
    srand(time(NULL));
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
                    //ECRIRE DANS LE FICHIER
                    for (int i = 0; i < 10; ++i) {
                        GameObject* go = new GameObject();
                        go->setX(rand()%100);
                        go->setY(rand()%100);
                        fichier1Input << "$" +  to_string(go->getY()) + "," + to_string(go->getY());
                    }
                }

            }
        }
    }

    //

    //SDL QUIT:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    //
    return 0;
}