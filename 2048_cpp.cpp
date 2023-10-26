#include"cstdlib"
//#include"hpp/grille.hpp"
//#include <grille.cpp>
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "Tuiles.h"
#include<conio.h>

using namespace std;


bool peutEtreDeplacee(int grille[4][4], int ligne, int colonne, int direction) {
	// Si la tuile est vide, elle peut être déplacée.
	if (grille[ligne][colonne] == 0) {
		return false;
	}

	//Si la tuile est à la première ligne, elle ne peut pas être déplacée vers le haut.
	if (ligne == 0 && direction == 1) {
		return false;
	}

	// Si la tuile est à la dernière ligne, elle ne peut pas être déplacée vers le bas.
	if (ligne == 3 && direction == -1) {
		return false;
	}

	// Si la tuile est à la première colonne, elle ne peut pas être déplacée vers la gauche.
	if (colonne == 0 && direction == -2) {
		return false;
	}

	// Si la tuile est à la dernière colonne, elle ne peut pas être déplacée vers la droite.
	if (colonne == 3 && direction == 2) {
		return false;
	}

	// Si la tuile est adjacente à une tuile vide, elle peut être déplacée.
	if (direction == 1)
	{
		if (grille[ligne - 1][colonne] == 0 || grille[ligne - 1][colonne] == grille[ligne][colonne])
		{
			return true;
		}
	}
	else if (direction == -1)
	{
		int ligneAdjacente = ligne - 1;
		int colonneAdjacente = colonne;
		if (ligneAdjacente >= 0 && ligneAdjacente < 4) {
			if (grille[ligneAdjacente][colonneAdjacente] == 0) {
				return true;
			}
		}
	}
	else if (direction == 2)
	{
		int ligneAdjacente = ligne - 1;
		int colonneAdjacente = colonne;
		if (ligneAdjacente >= 0 && ligneAdjacente < 4) {
			if (grille[ligneAdjacente][colonneAdjacente] == 0) {
				return true;
			}
		}
	}
	else if (direction == -2)
	{
		int ligneAdjacente = ligne + 1;
		int colonneAdjacente = colonne;
		if (ligneAdjacente >= 0 && ligneAdjacente < 4) {
			if (grille[ligneAdjacente][colonneAdjacente] == 0) {
				return true;
			}
		}
	}



	// Sinon, la tuile ne peut pas être déplacée.
	return false;
}


void deplacementTuiles(int grille[4][4] = {}, int direction = 0)
{
	int _grille[4][4] = {};
	memcpy(_grille, grille, sizeof(int) * 4 * 4); //copie des données de grille dans grille
	int _direction = 0;
	_direction = direction;




	int z = 0;
	int x = 0;
	if (_direction == 1)
	{

		for (int i = 3; i > 0; i--)
		{

			for (int y = 3; y > 0; y--)
			{
				if (_direction == 1) //haut
				{
					// avant dernière ligne ne monte pas
					if (peutEtreDeplacee(_grille, i, y, _direction))
					{
						for (int v = i - 1; v > 0; v--)
						{
							if (_grille[v - 1][y] == 0)
							{
								_grille[v - 1][y] = _grille[i][y];
								_grille[i][y] = 0;
							}
							else if (_grille[v - 1][y] == _grille[i][y])
							{
								_grille[v - 1][y] = _grille[v - 1][y] + _grille[i][y];
								_grille[i][y] = 0;
							}
						}

					}

				}



			}

		}
	}
	else if (_direction == 2)//droite
	{
		for (int y = 0; y < 4; y++)
		{

			for (int i = 0; i < 4; i++)
			{
				if (peutEtreDeplacee(_grille, i, y, _direction))
				{

					for (int w = y - 1; w > 3; w--)

					{
						if (_grille[i][w - 1] == 0)
						{

							_grille[i][w - 1] = _grille[i][y];
							_grille[i][y] = 0;

						}

						else if (_grille[i][w - 1] == _grille[i][y])
						{

							_grille[x][z] = _grille[i][w - 1] + _grille[i][y];
							_grille[i][y] = 0;

						}
					}
				}
			}
		}

	}
	else if (_direction == -1)//bas
	{

		for (int i = 3; i > 0; i--)
		{
			for (int y = 3; y > 0; y--)
			{
				if (peutEtreDeplacee(_grille, i, y, _direction))
				{

					for (int v = i; v < 3; v++)
					{


						if (_grille[v + 1][y] == 0)
						{
							_grille[v + 1][y] = _grille[i][y];
							_grille[i][y] = 0;


						}
						else if (_grille[v + 1][y] == _grille[i][y])
						{

							_grille[i][y] = _grille[v + 1][y] + _grille[i][y];
							cout << _grille[i][y];
							_grille[i][y] = 0;


						}
					}
				}


			}
		}
	}
	else if (direction == -2)
	{
		for (int y = 3; y > 0; y--)
		{
			for (int i = 3; i > 0; i--)
			{
				if (peutEtreDeplacee(_grille, i, y, _direction))
				{

					for (int w = y - 1; w < 3; w++)
					{

						if (_grille[i][w - 1] == 0)
						{
							_grille[i][w - 1] = _grille[i][y];
							_grille[i][y] = 0;
						}
						else if (_grille[i][w - 1] == _grille[i][y])
						{

							_grille[x][z] = _grille[i][w - 1] + _grille[i][y];
							_grille[i][y] = 0;

						}
					}
				}
			}
		}
	}



	Tuiles tuiles(0, 0, 0);
	bool ajoutVerif = false;
	srand(time(0));

	while (!ajoutVerif)
	{
		int value1 = tuiles.randomPos();
		int value2 = tuiles.randomPos();
		int i = tuiles.randomPos();
		int y = tuiles.randomPos();
		//cout << "Test+ " << i << endl;

		if (_grille[i][y] == 0) {
			_grille[value1][value2] = tuiles.randomvaleur();
			ajoutVerif = true;
		}

	}


	for (int i = 0; i < 4; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			cout << setw(4) << _grille[i][y] << " ";
		}
		cout << endl;
	}

}


bool estFini(int grille[4][4] = {})
{
	for (int i = 0; i < 4; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (grille[i][y] == 0) {
				return false;
			}
		}
	}
	return true;
}

bool scoreMaxAtteint(int grille[4][4] = {})
{
	for (int i = 0; i < 4; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (grille[i][y] == 2048) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand(time(0));
	int grille[4][4] = {};
	bool inGame = true;

	Tuiles tuiles(0, 0, 0);
	//cr�ation grille vide
	for (int i = 0; i < 4; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			grille[i][y] = 0;
		}
	}


	//cr�ation deux premi�res tuiles
	for (int i = 0; i < 2; i++)
	{


		grille[tuiles.randomPos()][tuiles.randomPos()] = tuiles.randomvaleur();

	}

	bool test = true;
	//boucle de jeux
	while (inGame)
	{
		//affichage de la grille


		if (test) {
			for (int i = 0; i < 4; i++)
			{
				for (int y = 0; y < 4; y++)
				{
					cout << setw(4) << grille[i][y] << " ";
				}
				cout << endl;
			}
			test = false;
		}








		cout << "appuie touche deplacement" << endl;
		//char entreClavier;
		//std::cin >> entreClavier;
		//std::cout << "touche:" << entreClavier << std::endl;

		int direction = 0;
		bool badkey = true;
		int c = 0;

		while (badkey) {
			badkey = false;
			switch ((c = _getch()))
			{
			case 'z':
				std::cout << "Vers le haut" << endl;
				direction = 1;
				deplacementTuiles(grille, direction);
				//déplacements tuiles
				//actualistaions tuiles
				//affichage new grilles
				break;
			case 'q':
				std::cout << "Vers la gauche" << endl;
				direction = -2;
				deplacementTuiles(grille, direction);
				break;
			case 'd':
				std::cout << "Vers la droite" << endl;
				direction = 2;
				deplacementTuiles(grille, direction);
				break;
			case 's':
				std::cout << "Vers le bas" << endl;
				direction = -1;
				deplacementTuiles(grille, direction);
				break;
			default:
				badkey = true;
				cout << "Touche non valide" << endl;
				break;
			}
		}


		for (int x = 0; x < 4; x++) {
			for (int w = 0; w < 4; w++) {
				if (peutEtreDeplacee(grille, x, w, direction) == false) {
					inGame = false;
				}
			}
		}

		if (estFini(grille)) {
			inGame = false;
		}

		if (scoreMaxAtteint(grille)) {
			inGame = false;
		}

	}


	return 0;
}
