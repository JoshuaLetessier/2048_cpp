#pragma once
#include "GameObject.h"
#include "Grille.h"
#include "Tuiles.h"  // N'oubliez pas d'inclure la classe Tuiles
#include <SDL.h>

class SDL_Renderer;

class GrilleGameObject : public GameObject {
public:
    GrilleGameObject(SDL_Renderer* renderer, Grille& grille);
    void render();

private:
    SDL_Renderer* renderer;
    Grille& grille;
    Tuiles tuiles[4][4];
};
