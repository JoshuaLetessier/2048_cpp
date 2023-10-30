#include "GameObject.h"

class Tile : public GameObject {
public:
    Tile(int x, int y, int width, int height, int value) : GameObject(x, y, width, height), value(value) {}

    void render(SDL_Renderer* renderer) override {
        // Ici, vous devez utiliser les fonctions SDL pour dessiner la tuile en fonction de ses coordonn�es x, y et de sa valeur.
        // Par exemple, vous pouvez dessiner un rectangle rempli avec la couleur appropri�e et afficher la valeur � l'int�rieur.
    }

private:
    int value;
};
