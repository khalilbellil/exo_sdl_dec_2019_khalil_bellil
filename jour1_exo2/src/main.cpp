#include <iostream>
#include "SDL2/SDL.h"
#include "vector"
#include <fstream>
#include <time.h>
#include "Image.h"
#include <stdio.h>
#include <stdlib.h>

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
    //

    //VARIABLES:
    vector<Image*> images(5);
    images[0] = new Image(0, "image1");
    images[1] = new Image(1, "image2");
    images[2] = new Image(2, "image3");
    images[3] = new Image(3, "image4");
    images[4] = new Image(4, "image5");

    vector<int> imagesNb(5, 0);

    int image1Nb = 0;
    int image21Nb = 0;
    int image3Nb = 0;
    int image4Nb = 0;
    int image5Nb = 0;

    int menu = 0;
    string input;
    //

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
            }
        }

        if(menu == 0){
            cout << "\n|| MENU PRINCIPAL || \n";
            cout << "1- Ajouter une image \n";
            cout << "2- Supprimer une image \n";
            cin >> input;

            if(stoi(input) == 1){
                menu = 1;
            }
            else if(stoi(input) == 2){
                menu = 2;
            }
        }
        else if(menu == 1){//Ajouter une image
            cout << "|| AJOUTER UNE IMAGE || \n";
            cout << "Entrez l'id de l'image a ajouter: \n";
            cin >> input;
            imagesNb[stoi(input)] += 1;
            cout << "L'image n_" + input + " est utilisée " + to_string(imagesNb[stoi(input)]) + " fois.";
            menu = 0;
        }
        else if(menu == 2){//Supprimer une image
            cout << "|| SUPPRIMER UNE IMAGE || \n";
            cout << "Entrez l'id de l'image a supprimer: \n";
            cin >> input;
            if(imagesNb[stoi(input)] > 0){
                imagesNb[stoi(input)] -= 1;
                cout << "L'image n_" + input + " est utilisée " + to_string(imagesNb[stoi(input)]) + " fois.";
            }
            else{
                cout << "Il n'y a aucune image n_" + input + " dans la base de donnees." ;
            }

            menu = 0;
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