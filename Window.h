#pragma once

struct SDL_Window;
struct SDL_Renderer;

class Window
{
public:
    int hauteur;
    int largeur;
    SDL_Window* win;
    SDL_Renderer* rend;

    Window(int hauteur, int largeur);

    void fenetre(int hauteur, int largeur) {
        this->hauteur = hauteur;
        this->largeur = largeur;
    }

};

