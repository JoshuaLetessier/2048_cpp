#include "GrilleGameObject.h"
#include "Tuiles.h" 
/*
GrilleGameObject::GrilleGameObject(SDL_Renderer* renderer, Grille& grill)
    : GameObject(0, 0, 0, 0, grille.matricegrille), renderer(renderer), grille(grille){
    // Initialisation des objets Tuiles
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tuiles[i][j] = Tuiles(renderer, j * 100, i * 100, grille.matricegrille[i][j]);
        }
    }
}

void GrilleGameObject::render() {
    // Dessinez chaque tuile
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tuiles[i][j].render();
        }
    }
}*/