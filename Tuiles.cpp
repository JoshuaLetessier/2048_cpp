#include "Tuiles.h"
#include"cstdlib"
#include <iostream>
#include <iomanip>
#include <SDL.h>
using namespace std;


/*Tuiles::Tuiles(SDL_Renderer* renderer, int x, int y, int value)
	: renderer(renderer) {
	// Chargez la texture en fonction de la valeur
	switch (value) {
	case 2:
		texture = IMG_LoadTexture(renderer, "images/2.png");
		break;
	case 4:
		texture = IMG_LoadTexture(renderer, "images/4.png");
		break;
	case 8:
		texture = IMG_LoadTexture(renderer, "images/8.png");
		break;
		// Ajoutez des cas pour les autres valeurs si nécessaire
	default:
		texture = nullptr;
		break;
	}

	rect.x = x;
	rect.y = y;
	rect.w = 64;  // Largeur de la tuile
	rect.h = 64;  // Hauteur de la tuile
}*/



int Tuiles::ajoutTuile(int grille)
{
	/*
	bool ajoutVerif = false;
	srand(time(0));

	while (!ajoutVerif)
	{
		int value1 = rand() % 3 + 0;
		int value2 = rand() % 3 + 0;
		int i = rand() % 3 + 0;
		int y = rand() % 3 + 0;
		cout << "Test+ " << i << endl;

		if (grille[i][y] == 0) {
			grille[value1][value2] = randomvaleur();
			ajoutVerif = true;
		}

	}
	return grille;*/
	return 0;
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

/*void Tuiles::render() {
	// Affichez la tuile en utilisant sa texture
	if (texture) {
		SDL_RenderCopy(renderer, texture, NULL, &rect);
	}
}*/