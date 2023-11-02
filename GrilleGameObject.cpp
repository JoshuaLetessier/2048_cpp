#include "GrilleGameObject.h"
#include "Tuiles.h"  // Inclure la classe Tuiles

/*GrilleGameObject::GrilleGameObject(SDL_Renderer* renderer, Grille& grille)
    : renderer(renderer), grille(grille) {
    // Initialisation des objets Tuiles
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tuiles[i][j] = Tuiles(renderer, j * 64, i * 64, grille.matricegrille[i][j]);
        }
    }
}*/

void GrilleGameObject::render() {
    // Dessinez chaque tuile
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
           // tuiles[i][j].render();
        }
    }
}
