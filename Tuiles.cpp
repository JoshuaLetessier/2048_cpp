#include "Tuiles.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

Tuiles::Tuiles(SDL_Renderer* renderer, int x, int y, int value) : renderer(renderer), x(x), y(y), value(value) {
	this->x = x;
	this->y = y;
	this->value = value;
}

Tuiles::~Tuiles() {
	SDL_DestroyTexture(texture); // Libérer la texture lorsque l'objet est détruit
}


void Tuiles::dessiner() {
	if (texture) {
		// Définis la position et les dimensions de la tuile
		SDL_Rect rect{};
		rect.x = x;
		rect.y = y;
		rect.w = 100;  // Largeur de la tuile
		rect.h = 100;  // Hauteur de la tuile

		// Dessine la tuile en utilisant la texture chargée
		SDL_RenderCopy(renderer, texture, NULL, &rect);
	}
}
void Tuiles::render() {
	// Affichez la tuile en utilisant sa texture
	SDL_Texture* texture = nullptr;
	if (texture) {
		SDL_Rect rect{};
		SDL_RenderCopy(renderer, texture, NULL, &rect);
	}
}

int Tuiles::addTuile(int value1, int value2)

{
	int nouvValue = value1 + value2;

	return nouvValue;
}

int Tuiles::randomvaleur()
{
	int x = rand() % 20 + 0;
	if (x < 10)
	{
		return 2;
	}
	else
	{
		return 4;
	}
}


int Tuiles::randomPos()
{
	int x = rand() % 3 + 0;
	return x;
}

