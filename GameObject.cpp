#include "GameObject.h"

class Tile : public GameObject {
public:
    Tile(int x, int y, int width, int height, int grid[4][4]) : GameObject(x, y, width, height, grid[4][4]) {}

    void render(SDL_Renderer* renderer) override {
       
    }

private:
    int value;
};
