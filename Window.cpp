#include "Window.h"
#include <SDL.h>
#include <string>
#include "Tuiles.h"
#include <SDL_image.h>
#include <iostream>


using namespace std;

Window::Window(int hauteur, int largeur) {
	win = SDL_CreateWindow("Projet 2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, hauteur, largeur, SDL_WINDOW_RESIZABLE);
	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	//creation fenetre 

	//couleur et actualisation
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
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255); // Effacez avec la couleur de fond souhait�e
	SDL_RenderClear(rend);
}

void Window::drawFilledRectangle(int width, int height) {
	// Obtenir la taille de la fen�tre
	int windowWidth, windowHeight;
	SDL_GetWindowSize(win, &windowWidth, &windowHeight);

	// Calculer les coordonn�es du coin sup�rieur gauche du rectangle pour le centrer
	int x = (windowWidth - width) / 2;
	int y = (windowHeight - height) / 2;

	SDL_Rect rect{ x, y, width, height };
	SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
	SDL_RenderFillRect(rend, &rect);

}

void Window::drawTilesRectangles(int width, int height)
{
	int windowWidth, windowHeight;
	SDL_GetWindowSize(win, &windowWidth, &windowHeight);

	// Calculer les coordonn�es du coin sup�rieur gauche du rectangle pour le centrer
	int x = (windowWidth - width) / 2;
	int y = (windowHeight - height) / 2;
	int j = 150;
	int w = 150;
	for (int i = 0; i < 4; i++)
	{
		
		for (int z = 0; z < 4; z++)
		{
			
			SDL_Rect rect{ x-w, y - j, width, height };
			SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
			SDL_RenderDrawRect(rend, &rect);
			j =j- 98;
		}
		w = w - 98;
		j = 150;
	}


}

void Window::drawTilesPictures(int windowWidth, int windowHeight, Grille grille)
{
	int gridSize = 4;  
	int tileSize = 90; 

	int gridX = (windowWidth - gridSize * tileSize) / 2;
	int gridY = (windowHeight - gridSize * tileSize) / 2;

	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			int tileValue = grille.matricegrille[i][j];
			int tileX = gridX + 0 * tileSize;
			int tileY = gridY + 0 * tileSize;

			tileValue = 2;
			// Charge l'image de la tuile en fonction de sa valeur
			std::string imagePath = "images/" + std::to_string(tileValue) + ".bmp";  // Assure-toi que les images BMP sont dans le répertoire "images"
			SDL_Surface* imageSurface = SDL_LoadBMP(imagePath.c_str());
			

			if (imageSurface == nullptr) {
				cout << "Erreur lors du chargement de l'image : " << IMG_GetError() << endl;
				continue;
			}

			// Crée une texture à partir de la surface de l'image
			SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(rend, imageSurface);
			SDL_FreeSurface(imageSurface);  // Libère la surface de l'image

			if (imageTexture == nullptr) {
				cout << "Erreur lors de la création de la texture : " << SDL_GetError() << endl;
				continue;
			}

			cout << "coucou" << endl;
			// Définit le rectangle pour la position et la taille de la tuile
			SDL_Rect destRect = { tileX, tileY, tileSize, tileSize };

			// Rend l'image de la tuile sur la fenêtre
			SDL_RenderCopy(rend, imageTexture, nullptr, &destRect);
			SDL_DestroyTexture(imageTexture);  // Libère la texture de l'image
		}
	}
}



SDL_Renderer* Window::getRenderer() const {
	return rend;
}
