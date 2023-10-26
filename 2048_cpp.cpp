#include"cstdlib"
//#include"hpp/grille.hpp"
//#include <grille.cpp>
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "Tuiles.h"

using namespace std;



int* deplacementTuiles(int grille[4][4] = {}, int direction = 0)
{
	int _grille[4][4] = {};
	memcpy(_grille, grille, sizeof(int) * 4 * 4); //copie des données de grille dans grille
	int _direction = 0;
	_direction = direction;

	
	

	int z = 0;
	int x = 0;
	if (_direction == 1 || _direction == 2)
	{

		for (int i = 0; i < 4; i++)
		{

			for (int y = 0; y < 4; y++)
			{
				if (_direction == 1) //haut
				{

					if (_grille[i][y] > 0)
					{


						for (int v = i-1; v >= 0; v--)
						{
							cout << _grille[v - 1][y] << endl;
							cout << _grille[i][y] << endl;
							if (_grille[v - 1][y] == 0)
							{
								_grille[v - 1][y] = _grille[i][y];
								_grille[i][y] = 0;
						
							}
							else if (_grille[v-1][y] == _grille[i][y])
							{
								_grille[v-1][y] = _grille[v - 1][y] + _grille[i][y];
								

								_grille[i][y] = 0;
							}
						}
					}

				}

				else if (_direction == 2)//droite
				{
					if (_grille[i][y] > 0)
					{

						for(int w = i; w > 3; w++)

						{
							if (_grille[i][w-1] == 0)
							{

								_grille[i][w-1] = _grille[i][y];
								_grille[i][y] = 0;

							}
							else if (_grille[i][w-1] == _grille[i][y])
							{

								_grille[x][z] = _grille[i][w-1] + _grille[i][y];
								_grille[i][y] = 0;

							}
						}
					}
				}

			}

		}
	}
	else if (_direction == -1 || _direction == -2)
	{

		for (int i = 3; i >= 0; i--)
		{
			for (int y = 3; y >= 0; y--)
			{

				if (_direction == -1)//bas
				{

					if (_grille[i][y] > 0 and i != 3)
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

								_grille[i][y] = _grille[v][y] + _grille[i][y];
								cout << _grille[i][y];
								_grille[i][y] = 0;

								
							}
						}
					}
				}
				else if (_direction == -2)//gauche 
				{
					if (_grille[i][y] > 0)
					{

						for (int w = i-1; w < 3; w++)
						{
							cout << w << endl;
							if (_grille[i][w - 1] == 0)
							{
								_grille[i][w - 1] = _grille[i][y];
								_grille[i][y] = 0;
							}
							else if (_grille[i][w + 1] == _grille[i][y])
							{


								



								_grille[x][z] = _grille[i][w - 1] + _grille[i][y];
								_grille[i][y] = 0;

							}
						}
					}
				}
			}
		}
	}


	Tuiles tuiles(0, 0, 0);
	//tuiles.ajoutTuile(_grille);

	bool ajoutVerif = false;
	srand(time(0));

	while (!ajoutVerif)
	{
		int value1 = rand() % 3 + 0;
		int value2 = rand() % 3 + 0;
		int i = rand() % 3 + 0;
		int y = rand() % 3 + 0;
		cout << "Test+ " << i << endl;

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



	return *_grille;
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


	//boucle de jeux
	while (inGame)
	{
		//affichage de la grille
		for (int i = 0; i < 4; i++)
		{
			for (int y = 0; y < 4; y++)
			{
				cout << setw(4) << grille[i][y] << " ";
			}
			cout << endl;
		}



		cout << "appuie touche deplacement" << endl;
		char entreClavier = std::cin.get();
		int direction = 0;
		switch (entreClavier)
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
			cout << "Touche non valide" << endl;
			break;
		}



		inGame = false;

	}


	return 0;
}

