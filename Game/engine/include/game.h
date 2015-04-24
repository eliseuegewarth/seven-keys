/*
 * Classe que representa um jogo.
 *
 * Autor: Edson Alves
 * Data: 26/03/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL/SDL.h>
#include "menu.h"
#include "map.h"
#include "imageManagement.h"

void FillRect(int x, int y, int w, int h, int color, SDL_Surface *screen);

class Game
{
public:
    Game();
    ~Game();
	void fontInit();
    void printF(char*, int, int);

    int run();

private:
	Menu menu;
    Map map;
	ImageManagement imageManagement;
    void update_timestep();
    bool process_input(Map:: room*, Map::room **, SDL_Surface *screen);
    void runIA();
    void runPhysics();
    bool update();
    //void draw(SDL_Surface *screen);
};

#endif
