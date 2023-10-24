#include"cstdlib"
//#include"hpp/grille.hpp"
//#include <grille.cpp>
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;


int randomPos()
{
	int x = rand() % 3 + 0;
	return x;
}

int randomvaleur()
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

int main()
{
	int grille[4][4] = {};
	bool inGame = true;
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
		int longeur = randomPos();
		int largeur = randomPos();
		int value = randomvaleur();
		grille[longeur][largeur] = value;
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

		switch (entreClavier)
		{
		case 'z':
			std::cout << "Vers le haut" << endl;
			//déplacements tuiles
			//actualistaions tuiles
			//affichage new grilles
			break;
		case 'q':
			std::cout << "Vers la gauche" << endl;
			break;
		case 's':
			std::cout << "Vers la droite" << endl;
			break;
		case 'd':
			std::cout << "Vers le bas" << endl;
			break;
		default:
			cout << "Touche non valide" << endl;
			break;
		}

		inGame = false;

	}


	return 0;
}

/*
while (0)
{
	bool startGame = false;
	Grille grille{4,4};

	if (startGame == false)
	{
		startGame = true;
		for (int i = 0;  i < 2; i++)
		{
			int x = rand() % 3 + 0;
			int y = rand() % 3 + 0;
			int z = rand() % 1 + 0;
			int value;

			if (z == 0)
			{
				value = 2;
			}
			else {
				value = 4;
			}

			if (grille.createGrille[x][y] == 0)
			{
				grille.createGrille[x][y] = value;
			}



;

			}



		}
		else
		{
			//mouvement clavier
			char entreClavier = std::cin.get();
			switch (entreClavier)
			{
			case '72':
				std::cout << "Vers le haut";
				break;
			case '75':
				std::cout << "Vers la gauche";
				break;
			case '77':
				std::cout << "Vers la droite";
				break;
			case '80':
				std::cout << "Vers le bas";
				break;


			}
		}
	}
	*/