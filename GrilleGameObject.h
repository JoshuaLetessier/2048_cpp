#pragma once

#include "GameObject.h"


class SDL_Renderer;

class GrilleGameObject : public GameObject {
public:
    GrilleGameObject(int x, int y, int width, int height, int** grid, int rows, int columns);

    void render(SDL_Renderer* renderer) override;

private:
    int** grid;
    int rows;
    int columns;
};
