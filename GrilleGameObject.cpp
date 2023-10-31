#include "GrilleGameObject.h"

#include <SDL.h>
#include <SDL_ttf.h>


GrilleGameObject::GrilleGameObject(int x, int y, int width, int height, int** grid, int rows, int columns)
    : GameObject(x, y, width, height), grid(grid), rows(rows), columns(columns) {

    TTF_Init();
}

       
void afficheValue(int value, SDL_Renderer* renderer, SDL_Rect rectangleGrille)
{
    TTF_Font* font = TTF_OpenFont("chemin_vers_votre_police.ttf", 24);
    char valueStr[10];
    SDL_snprintf(valueStr, sizeof(valueStr), "%d", value);
    SDL_Color color = { 255, 255, 255 };

    SDL_Surface* surface = TTF_RenderText_Solid(font, valueStr, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    int textWidth = surface->w;
    int textHeight = surface->h;
    int centerX = rectangleGrille.x + (rectangleGrille.w - textWidth) / 2;
    int centerY = rectangleGrille.y + (rectangleGrille.h - textHeight) / 2;

    SDL_Rect textRect = { centerX, centerY, textWidth, textHeight };

    // Dessinez le texte au centre du rectangle
    SDL_RenderCopy(renderer, texture, NULL, &textRect);

    // Libérez les ressources de texte et texture
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

    TTF_CloseFont(font);
    TTF_Quit();

    
}
void GrilleGameObject::render(SDL_Renderer* renderer) {
    // Dessinez la grille en utilisant SDL en fonction des données dans "grid".
    // Parcourez la grille et dessinez chaque tuile en utilisant des rectangles ou d'autres formes géométriques.

    SDL_Rect rectangleGrille;

    for (int i = 0; i < 3; i++)
    {
        for (int y = 0; y < 3; y++)
        {
            rectangleGrille.x = 0 + i * 32;
            rectangleGrille.y = 0 + y * 32;
            rectangleGrille.w = 32;
            rectangleGrille.h = 32;
        }
    }

    

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            int value = grid[row][col];
            afficheValue(value, renderer, rectangleGrille);

            // Dessinez la tuile en fonction de "value" à l'emplacement (x, y).
            // Vous pouvez utiliser SDL_RenderFillRect pour dessiner un rectangle, par exemple.
            // Assurez-vous de calculer les coordonnées correctes pour chaque tuile.
            /// Vous pouvez également afficher le contenu de chaque tuile (valeur) au centre du rectangle.
        }
    }

}


