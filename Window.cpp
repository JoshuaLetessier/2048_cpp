#include "Window.h"
#include <SDL.h>


Window::Window(int hauteur, int largeur) {
	win = SDL_CreateWindow("Fenêtre de jeu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, hauteur, largeur, SDL_WINDOW_RESIZABLE);
	rend = SDL_CreateRenderer(win, -1, SDL_WINDOW_RESIZABLE);
	SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
}

