#pragma once
class Grille
{
public:
	int matricegrille[4][4] = {};

	Grille(int _matricegrille[4][4] = {})
	{
		if (_matricegrille != nullptr)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int y = 0; y < 4; y++)
				{
					matricegrille[i][y] = _matricegrille[i][y];
				}
			}
		}
	}

	int returnValue(int grille[4][4], int i, int y);

	void deplacementTuiles(int grille[4][4], int direction);

	bool estDansLimites(int i, int j);
	bool estDeplacementPossible(int grille[4][4], int direction);
	bool mouvementsPossibles();
	bool peutFusionner(int tuileActuelle, int tuileSuivante);
	void genererTuileAleatoire(int grille[4][4]);
	bool estFinJeu(int grille[4][4]);
	void mettreAJourScore(int valeur);
	void afficherGrille(int grille[4][4]);
	void deplacerHaut(int grille[4][4]);
	void deplacerBas(int grille[4][4]);
	void deplacerGauche(int grille[4][4]);
	void deplacerDroite(int grille[4][4]);
};
