#include"cstdlib"
#include <iostream>
#include <iomanip>
#include "Tuiles.h"
#include "Grille.h"
#include<conio.h>
#include <SDL.h>
#include "Window.h"
#include "GrilleGameObject.h"


using namespace std;

int main(int argc, char* argv[])
{

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Quit();
	
	srand(time(0));

	Grille grille;
	bool inGame = true;
	Window window(500, 500);

	//int const& valeur = grille.returnValue(grille.matricegrille, 0, 0);
	//cout << valeur << endl;
	Tuiles tuiles(0, 0, 0);
	
	//cr�ation deux premi�res tuiles
	grille.genererTuileAleatoire(grille.matricegrille);
	grille.genererTuileAleatoire(grille.matricegrille);
	
	GrilleGameObject grilleGO(0,0,0,0, grille);

	while (inGame)
	{
		// Affichage de la grille
		
		grille.afficherGrille(grille.matricegrille);
		
		grilleGO.render(window.rend);
		/*if (!grille.mouvementsPossibles()) {
			cout << "Le jeu est terminé ! Aucun mouvement possible." << endl;
			inGame = false;
			break;
		}*/

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
			case 27: // Code ASCII pour la touche Échap
				cout << "Quitter le jeu" << endl;
				inGame = false;
				break;
			default:
				badkey = true;
				cout << "Touche non valide" << endl;
				break;
			}
		}
	}




	


	return 0;
}
