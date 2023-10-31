#include "Window.h"
#include <SDL.h>



Window::Window(int hauteur, int largeur) {
	win = SDL_CreateWindow("Fenêtre de jeu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, hauteur, largeur, SDL_WINDOW_RESIZABLE);
	rend = SDL_CreateRenderer(win, -1, SDL_WINDOW_RESIZABLE);

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    // Créer un rectangle
    SDL_Rect rectangle{ 0, 0, 400, 400 };

    SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);

    // Remplir le rectangle avec la couleur actuelle
    SDL_RenderFillRect(rend, &rectangle);

    // Mettre à jour l'affichage
    SDL_RenderPresent(rend);

}

void Window::pollEvents()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            _closed = true;
            break;
        default:
            break;
        }
    }
}

void Window::clear() const
{
    
}



