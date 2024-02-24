#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include "Map.hpp"

struct Joueur
{
    sf::Vector2f position;
    sf::Sprite sprite;
    float vitesse = 100.0f; // pixels par seconde
    static const int Y_Initial = 450;
    static const int X_Initial = 800;
    static const int TailleSprite = 32;
};

class Jeu
{
public:
    Jeu();
    void executer();

private:
    sf::RenderWindow fenetre;
    static const int F_Hauteur = 900;
    static const int F_Largeur = 1600;

    Joueur joueur;
    sf::Texture textureJoueur; // Ajout pour gérer la texture du sprite du joueur

    Map map;

    void initialiserJeu();
    void traiterEvenements();
    void mettreAJour(sf::Time deltaTime);
    bool collision(int p, sf::Time deltaTime);
    void dessiner();
};

#endif
