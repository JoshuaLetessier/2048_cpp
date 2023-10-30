#include "GameObject.h"

class Tile : public GameObject {
public:
    Tile(int x, int y, int width, int height, int value) : GameObject(x, y, width, height), value(value) {}

    void render(SDL_Renderer* renderer) override {
        // Ici, vous devez utiliser les fonctions SDL pour dessiner la tuile en fonction de ses coordonnées x, y et de sa valeur.
        // Par exemple, vous pouvez dessiner un rectangle rempli avec la couleur appropriée et afficher la valeur à l'intérieur.
    }

private:
    int value;
};
