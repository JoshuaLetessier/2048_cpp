#pragma once
class SDL_Renderer;

class Tuiles
{
public:
	int x;
	int y;
	int value;

	Tuiles(SDL_Renderer* renderer, int x, int y, int value)
	{
		this->x = x;
		this->y = y;
		this->value = value;
	}
	//void render();
	int ajoutTuile(int grille);
	static int addTuile(int value1, int value2);
	int randomvaleur();
	int randomPos();
};