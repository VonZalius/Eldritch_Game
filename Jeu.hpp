#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Map.hpp"

struct Joueur
{
    sf::Vector2f position;
    sf::Sprite sprite;
    float vitesse = 200.0f; // pixels par seconde
    float vitesseAugmentee = 400.0f;
    static const int Y_Initial = 450;
    static const int X_Initial = 800;
    static const int TailleSprite = 32;
};

struct EcranTitre
{
    void afficherEcranTitre(sf::RenderWindow& fenetre);
    void demarrage(sf::RenderWindow& fenetre);
    void killed(sf::RenderWindow& fenetre);

    sf::Texture textureEcranTitre;
    sf::Sprite spriteEcranTitre;
    sf::Font font;
    sf::Text texteTitre;
    sf::Font fontDemarrage;
    sf::Text texteDemarrage3;
    sf::Text texteDemarrage2;
    sf::Text texteDemarrage1;
    sf::Font fontKilled;
    sf::Text texteKilled;
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
    bool killedStatus = false;

    Joueur joueur;
    sf::Texture textureJoueur; // Ajout pour gérer la texture du sprite du joueur

    EcranTitre ecranTitre;

    Map map;

    void initialiserJeu();
    void traiterEvenements();
    void mettreAJour(sf::Time deltaTime);
    bool collision(int p, sf::Time deltaTime, float vitesseActuelle);
    void dessiner();
    void reinitialiser();
};

#endif
