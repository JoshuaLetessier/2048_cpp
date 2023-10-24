#pragma once
class Grille
{
public:
	int longeur;
	int largeur;

	Grille(int longeur, int largeur)
	{
		this->largeur = largeur;
		this->longeur = longeur;
	}

	void createGrille();
};

