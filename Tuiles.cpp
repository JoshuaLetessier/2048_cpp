#include "Tuiles.h"
#include"cstdlib"
#include <iostream>
#include <iomanip>
using namespace std;

int Tuiles::ajoutTuile(int grille)
{

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
	return grille;
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

