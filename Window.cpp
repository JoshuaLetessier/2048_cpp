#include "Window.h"
#include <SDL.h>
#include <string>

using namespace std;

Window::Window(int hauteur, int largeur) {
    win = SDL_CreateWindow("Projet 2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, hauteur, largeur, SDL_WINDOW_RESIZABLE);
    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
    SDL_RenderClear(rend);
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

void Window::clear() const {
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255); // Effacez avec la couleur de fond souhaitée
    SDL_RenderClear(rend);
}

void Window::drawFilledRectangle(int width, int height) {
    // Obtenir la taille de la fenêtre
    int windowWidth, windowHeight;
    SDL_GetWindowSize(win, &windowWidth, &windowHeight);

    // Calculer les coordonnées du coin supérieur gauche du rectangle pour le centrer
    int x = (windowWidth - width) / 2;
    int y = (windowHeight - height) / 2;

    SDL_Rect rect{ x, y, width, height };
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderFillRect(rend, &rect);

}

SDL_Renderer* Window::getRenderer() const {
    return rend;
}
