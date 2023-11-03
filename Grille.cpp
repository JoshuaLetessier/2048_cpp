#include "Grille.h"
#include "Tuiles.h"

#include <vcruntime_string.h>
#include <iostream>
#include <iomanip>
#include "Window.h"

using namespace std;

int Grille::returnValue(int grille[4][4], int i, int y)
{
	if (grille == nullptr)
	{
		return 0;
	}
	else
	{
		return grille[i][y];
	}
}
void Grille::deplacementTuiles(int grille[4][4], int direction)
{
	if (direction == 1)
	{
		deplacerHaut(grille);
	}
	else if (direction == -1)
	{
		deplacerBas(grille);
	}
	else if (direction == 2)
	{
		deplacerDroite(grille);
	}
	else if (direction == -2)
	{
		deplacerGauche(grille);
	}
	genererTuileAleatoire(grille);
	system("cls");

}

bool Grille::estDansLimites(int i, int j)
{
	if (i < 4 && j < 4)
	{
		return true;
	}
	return false;
}

bool Grille::estDeplacementPossible(int grille[4][4], int direction)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grille[i][j] != 0) {
				// En fonction de la direction choisie
				if (direction == 1) { // Vers le haut
					for (int v = i - 1; v >= 0; v--) {
						// Conditions sp�cifiques au d�placement vers le haut
						if (grille[v][j] == 0) {
							// La case est vide, continuez � v�rifier les autres cases
						}
						else if (peutFusionner(grille[i][j], grille[v][j])) {
							// Les tuiles peuvent fusionner, continuez � v�rifier les autres cases
						}
						else {
							// Si la case est occup�e par une tuile diff�rente, arr�tez de v�rifier
							break;
						}
					}
				}
				else if (direction == -1) { // Vers le bas
					for (int v = i + 1; v < 4; v++) {
						// Conditions sp�cifiques au d�placement vers le bas
						if (grille[v][j] == 0) {
							// La case est vide, continuez � v�rifier les autres cases
						}
						else if (peutFusionner(grille[i][j], grille[v][j])) {
							// Les tuiles peuvent fusionner, continuez � v�rifier les autres cases
						}
						else {
							// Si la case est occup�e par une tuile diff�rente, arr�tez de v�rifier
							break;
						}
					}
				}
				else if (direction == -2) { // Vers la gauche
					for (int v = j - 1; v >= 0; v--) {
						// Conditions sp�cifiques au d�placement vers la gauche
						if (grille[i][v] == 0) {
							// La case est vide, continuez � v�rifier les autres cases
						}
						else if (peutFusionner(grille[i][j], grille[i][v])) {
							// Les tuiles peuvent fusionner, continuez � v�rifier les autres cases
						}
						else {
							// Si la case est occup�e par une tuile diff�rente, arr�tez de v�rifier
							break;
						}
					}
				}
				else if (direction == 2) { // Vers la droite
					for (int v = j + 1; v < 4; v++) {
						// Conditions sp�cifiques au d�placement vers la droite
						if (grille[i][v] == 0) {
							// La case est vide, continuez � v�rifier les autres cases
						}
						else if (peutFusionner(grille[i][j], grille[i][v])) {
							// Les tuiles peuvent fusionner, continuez � v�rifier les autres cases
						}
						else {
							// Si la case est occup�e par une tuile diff�rente, arr�tez de v�rifier
							break;
						}
					}
				}
			}
		}
	}
	return false; // Aucun d�placement possible
}

bool Grille::mouvementsPossibles()
{
	for (int direction = 1; direction <= 2; direction++) {
		if (estDeplacementPossible(matricegrille, direction)) {
			return true;
		}
	}
	return false;
}



bool Grille::peutFusionner(int tuileActuelle, int tuileSuivante)
{
	// V�rifiez si les deux tuiles peuvent fusionner
	return (tuileActuelle == tuileSuivante);
}

void Grille::genererTuileAleatoire(int grille[4][4])
{
	SDL_Renderer* renderer = nullptr;
	Tuiles tuiles{renderer, 0,0,0 };
	int x, y;
	int value = tuiles.randomvaleur(); // G�n�rer une valeur al�atoire en utilisant la fonction de la classe Tuiles

	do {
		x = tuiles.randomPos(); // G�n�rer une position al�atoire en utilisant la fonction de la classe Tuiles
		y = tuiles.randomPos(); // G�n�rer une position al�atoire en utilisant la fonction de la classe Tuiles
	} while (grille[x][y] != 0);

	// Vous avez maintenant (x, y) comme position de tuile vide
	grille[x][y] = value;
	
}


bool Grille::estFinJeu(int grille[4][4])
{
	// V�rifiez si une case a la valeur 2048
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grille[i][j] == 2048) {
				return true;
			}
		}
	}

	// V�rifiez s'il n'y a plus de d�placements possibles
	for (int direction = -2; direction <= 2; direction++) {
		if (estDeplacementPossible(grille, direction)) {
			// S'il y a au moins un d�placement possible, le jeu n'est pas termin�
			return false;
		}
	}

	// Si aucune des conditions ci-dessus n'est remplie, le jeu est termin�
	return true;
}


void Grille::mettreAJourScore(int valeurFusion)
{
	// Vous pouvez ajouter la valeur de la fusion � votre score actuel
	int score{};
	score = score + valeurFusion;
}

void Grille::afficherGrille(int grille[4][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw(4) << grille[i][j] << " "; // Utilisez setw pour aligner les valeurs
		}
		cout << endl;
	}
}

void Grille::deplacerHaut(int grille[4][4])
{
	for (int j = 0; j < 4; j++) {
		for (int i = 1; i < 4; i++) {
			if (grille[i][j] != 0) {
				int k = i - 1;
				while (k >= 0 && (grille[k][j] == 0 || grille[k][j] == grille[i][j])) {
					if (grille[k][j] == grille[i][j]) {
						// Fusion de deux tuiles identiques
						grille[k][j] *= 2;
						mettreAJourScore(grille[k][j]);  // Mettez � jour le score
						grille[i][j] = 0;
						break;  // Sortir de la boucle de fusion
					}
					else if (grille[k][j] == 0) {
						grille[k][j] = grille[i][j];
						grille[i][j] = 0;
						i = k;  // D�placer i vers la position actuelle de k
					}
					k--;
				}
			}
		}
	}
}

void Grille::deplacerBas(int grille[4][4])
{
	for (int j = 0; j < 4; j++) {
		for (int i = 2; i >= 0; i--) {
			if (grille[i][j] != 0) {
				int k = i + 1;
				while (k < 4 && (grille[k][j] == 0 || grille[k][j] == grille[i][j])) {
					if (grille[k][j] == grille[i][j]) {
						grille[k][j] *= 2;
						mettreAJourScore(grille[k][j]);
						grille[i][j] = 0;
						break;
					}
					else if (grille[k][j] == 0) {
						grille[k][j] = grille[i][j];
						grille[i][j] = 0;
						i = k;
					}
					k++;
				}
			}
		}
	}
}

void Grille::deplacerGauche(int grille[4][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (grille[i][j] != 0) {
				int k = j - 1;
				while (k >= 0 && (grille[i][k] == 0 || grille[i][k] == grille[i][j])) {
					if (grille[i][k] == grille[i][j]) {
						grille[i][k] *= 2;
						mettreAJourScore(grille[i][k]);
						grille[i][j] = 0;
						break;
					}
					else if (grille[i][k] == 0) {
						grille[i][k] = grille[i][j];
						grille[i][j] = 0;
						j = k;
					}
					k--;
				}
			}
		}
	}
}

void Grille::deplacerDroite(int grille[4][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j >= 0; j--) {
			if (grille[i][j] != 0) {
				int k = j + 1;
				while (k < 4 && (grille[i][k] == 0 || grille[i][k] == grille[i][j])) {
					if (grille[i][k] == grille[i][j]) {
						grille[i][k] *= 2;
						mettreAJourScore(grille[i][k]);
						grille[i][j] = 0;
						break;
					}
					else if (grille[i][k] == 0) {
						grille[i][k] = grille[i][j];
						grille[i][j] = 0;
						j = k;
					}
					k++;
				}
			}
		}
	}
}
