#pragma once

class GameObject {
public:
    virtual void dessiner() = 0; // M�thode virtuelle pure pour le dessin
    virtual void mettreAJour() = 0; // M�thode virtuelle pure pour la mise � jour
};
