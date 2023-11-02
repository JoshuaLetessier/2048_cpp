#pragma once

#include <SDL.h>

class GameObject {
public:
    GameObject(int x, int y, int width, int height, int grid[4][4]) : x(x), y(y), width(width), height(height){}

    // Méthode virtuelle pure pour dessiner l'objet
    virtual void render(SDL_Renderer* renderer) = 0;

protected:
    int x;
    int y;
    int width;
    int height;
};
