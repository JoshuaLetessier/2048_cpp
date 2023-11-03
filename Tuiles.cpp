//création des Tuiles

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <SDL.h>
#include <SDL_image.h>

#include "Tuiles.h"

using namespace std;

Tuiles::Tuiles(SDL_Renderer* renderer, int x, int y, int value) : renderer(renderer), x(x), y(y), value(value) {
	this->x = x;
	this->y = y;
	this->value = value;
}

Tuiles::~Tuiles() {
	SDL_DestroyTexture(texture); // Libérer la texture lorsque l'objet est détruit
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

