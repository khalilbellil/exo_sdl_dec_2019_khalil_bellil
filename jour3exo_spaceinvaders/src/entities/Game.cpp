//
// Created by ASUS_BELLIL on 2019-04-15.
//
#include "Game.h"
#include "../Managers/TextureManager.h"
#include "GameObject.h"
#include "../utils/Utils.h"
#include <vector>
#include "Laser.h"
using namespace std;

GameObject* player;
vector<GameObject*> enemies;
vector<Laser*> lasers;

int playerSpeed = 4;

SDL_Renderer* Game::ren = nullptr;

Game::Game() {}

Game::~Game() {}

void Game::Init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "INFO: SDL initialized ..." << endl;

        Game::win = SDL_CreateWindow(title,xPos,yPos,width,height, flags);
        if (Game::win){
            cout << "INFO: WINDOW created..." << endl;
        }

        Game::ren = SDL_CreateRenderer(Game::win,-1,0);
        if (Game::ren){
            SDL_SetRenderDrawColor(Game::ren,0,0,0,255);
            cout << "INFO: RENDERER created..." << endl;
        }
        Game::isRunning = true;
    } else{
        Game::isRunning = false;
        cout << "! ERROR ! : INITIALISATION failed !" << endl;
    }

    player = new GameObject("assets/player.png", (Utils::WIDTH / 2) - 32, Utils::HEIGHT - 80, false, true);

    int enemyX = (Utils::WIDTH / 6) - 128 + 48;
    int enemyY = (Utils::HEIGHT/8) - 32;
    for (int i = 0; i < 6; ++i) {
        enemies.push_back(new GameObject("assets/enemy.png", enemyX, enemyY, true, true));
        enemyX += 64 + 64;
    }


}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
        Game::isRunning = false;
        break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
            case SDLK_q:
                Game::isRunning = false;
                break;
            case SDLK_a:
                //LEFT
                player->setXPos(player->getXPos() - playerSpeed);

                break;
            case SDLK_d:
                //RIGHT
                player->setXPos(player->getXPos() + playerSpeed);
                break;
            case SDLK_w:
                //LASER
                lasers.push_back(new Laser(player));
                break;

            default:
            break;
            }

    }

}

void Game::Update() {

    player->Update();
    for (int i = 0; i < 6; ++i) {
        enemies[i]->Update();
    }


    if (lasers.size() != 0){
        for (int i = 0; i < lasers.size(); ++i) {
            lasers[i]->Update();
            for (int j = 0; j < enemies.size(); ++j) {
                
            }
            if  (Utils::Collision(lasers[i]->getLaserRect(), enemies[i]->getDstRect())){
                cout << "COLLISION" << endl;
                enemies[0]->setIsActive(false);
            }
        }
    }

}

void Game::Render() {
    SDL_RenderClear(Game::ren);

    //region STUFF TO RENDER

    player->Render();
    for (int i = 0; i < 6; ++i) {
        enemies[i]->Render();
    }

    //COLLISIONS:
    if (lasers.size() != 0){
        for (int i = 0; i < lasers.size(); ++i) {
            lasers[i]->Render();
            for (int j = 0; j < enemies.size(); ++j) {
                if  (lasers[i]->isIsActive() && enemies[j]->isIsActive()){
                    if (Utils::Collision(lasers[i]->getLaserRect(), enemies[j]->getDstRect())){
                        cout << "ENNEMY KILLED" << endl;
                        enemies[j]->setIsActive(false);
                    }
                }
            }
        }
    }
    for (int k = 0; k < enemies.size(); ++k) {
        if  (enemies[k]->isIsActive()) {
            if (Utils::Collision(player->getDstRect(), enemies[k]->getDstRect())) {
                Game::isRunning = false;
            }
        }
    }

    //endregion

    SDL_RenderPresent(Game::ren);

}

void Game::Clean() {

    SDL_DestroyWindow(Game::win);
    SDL_DestroyRenderer(Game::ren);
    SDL_Quit();
}