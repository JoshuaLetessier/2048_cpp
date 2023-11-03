#pragma once
#include<SDL.h>
//class SDL_Renderer;
#include <SDL_image.h>


class Tuiles
{
public:
	int x;
	int y;
	int value;
	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;
	
	
	Tuiles(SDL_Renderer* renderer, int x, int y, int value);

	~Tuiles();
	void dessiner();

	void render();

	static int addTuile(int value1, int value2);
	int randomvaleur();
	int randomPos();
};