#pragma once
class Tuiles
{
public:
	int x;
	int y;
	int value;

	Tuiles(int x, int y, int value)
	{
		this->x = x;
		this->y = y;
		this->value = value;
	}

	int ajoutTuile(int grille);
	static int addTuile(int value1, int value2);
	int randomvaleur();
	int randomPos();
};