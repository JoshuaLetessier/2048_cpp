#pragma once

class GameObject {
public:
    virtual void dessiner() = 0; // Méthode virtuelle pure pour le dessin
    virtual void mettreAJour() = 0; // Méthode virtuelle pure pour la mise à jour
};
