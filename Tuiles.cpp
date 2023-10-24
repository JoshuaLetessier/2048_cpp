#include "Tuiles.h"
#include"cstdlib"

void Tuiles::ajoutTuile()
{
	/*Tuiles::x = randomPos();
	Tuiles::y = randomPos();
	Tuiles::value = randomvaleur();*/
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

