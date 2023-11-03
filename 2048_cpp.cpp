#include"cstdlib"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "Tuiles.h"
#include "Grille.h"
#include<conio.h>
#include<SDL.h>
#include <SDL.h>
#include "Window.h"


using namespace std;

int main(int argc, char* argv[])
{
	srand(time(0));
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "PROJECT SDL JL", "Projet 2048", NULL);

	Window window(500, 500);

	SDL_Event event{};
	while (!window.isClosed()) //boucle de la fenetre
	{
		
		window.pollEvents();
		window.clear();
		//window.drawFilledRectangle(400, 400);
		window.drawTilesRectangles(90, 90);
		SDL_RenderPresent(window.getRenderer());

		Grille grille;
		window.drawTilesPictures(window.hauteur, window.largeur, grille);

		//tuiles de départ
		grille.genererTuileAleatoire(grille.matricegrille);
		window.drawTilesPictures(500, 500, grille);
		grille.genererTuileAleatoire(grille.matricegrille);
		window.drawTilesPictures(500, 500, grille);

		//grille.afficherGrille(grille.matricegrille);

		int direction = 0;
		//bool badkey = true;
		int c = 0;
		bool inGame = true;

		//boucle de jeux
		//la boucle tourne à l'infinie sans attendre d'entrée clavier comprend pas
		while (inGame) {
			//cout << "Appuyez sur une touche de déplacement : z (haut), q (gauche), d (droite), s (bas)" << endl;
			//badkey = false;
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					//cout << "Vers le haut" << endl;
					direction = 1;
					grille.deplacementTuiles(grille.matricegrille, direction);
					window.drawTilesPictures(500, 500, grille);
					break;
				case SDLK_LEFT:
					//cout << "Vers la gauche" << endl;
					direction = -2;
					grille.deplacementTuiles(grille.matricegrille, direction);
					window.drawTilesPictures(500, 500, grille);
					break;
				case SDLK_RIGHT:
					//cout << "Vers la droite" << endl;
					direction = 2;
					grille.deplacementTuiles(grille.matricegrille, direction);
					window.drawTilesPictures(500, 500, grille);
					break;
				case SDLK_DOWN:
					//cout << "Vers le bas" << endl;
					direction = -1;
					grille.deplacementTuiles(grille.matricegrille, direction);
					window.drawTilesPictures(500, 500, grille);
					break;
					/*case 27: // Code ASCII pour la touche Échap
						cout << "Quitter le jeu" << endl;

						break;*/
				default:
					inGame = false;
					cout << "Touche non valide" << endl;
					break;
				}
			}
		}

	}

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Quit();


/*
	Grille grille;
	bool inGame = true;
	SDL_Renderer* renderer = nullptr;

	//int const& valeur = grille.returnValue(grille.matricegrille, 0, 0);
	//cout << valeur << endl;
	Tuiles tuiles(renderer, 0, 0, 0);

	//cr�ation deux premi�res tuiles
	grille.genererTuileAleatoire(grille.matricegrille);
	grille.genererTuileAleatoire(grille.matricegrille);



	while (inGame)
	{
		// Affichage de la grille
		grille.afficherGrille(grille.matricegrille);
		int direction = 0;
		bool badkey = true;
		int c = 0;

		while (badkey) {
			cout << "Appuyez sur une touche de déplacement : z (haut), q (gauche), d (droite), s (bas)" << endl;
			badkey = false;
			switch ((c = _getch()))
			{
			case 'z':
				cout << "Vers le haut" << endl;
				direction = 1;
				grille.deplacementTuiles(grille.matricegrille, direction);
				break;
			case 'q':
				cout << "Vers la gauche" << endl;
				direction = -2;
				grille.deplacementTuiles(grille.matricegrille, direction);
				break;
			case 'd':
				cout << "Vers la droite" << endl;
				direction = 2;
				grille.deplacementTuiles(grille.matricegrille, direction);
				break;
			case 's':
				cout << "Vers le bas" << endl;
				direction = -1;
				grille.deplacementTuiles(grille.matricegrille, direction);
				break;
			/*case 27: // Code ASCII pour la touche Échap
				cout << "Quitter le jeu" << endl;

				break;
			default:
				badkey = true;
				cout << "Touche non valide" << endl;
				break;
}
		}
		/*if (!grille.mouvementsPossibles()) {
			cout << "Le jeu est terminé ! Aucun mouvement possible." << endl;
			inGame = false;
			break;
		}*/
	

	//}
	return 0;
}
