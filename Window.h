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
    bool _closed = false;

    Window(int hauteur, int largeur);

    void pollEvents();

    void fenetre(int hauteur, int largeur) {
        this->hauteur = hauteur;
        this->largeur = largeur;
    }

    void clear() const;

    
    inline bool isClosed() const {
        return _closed; 
    }

};

