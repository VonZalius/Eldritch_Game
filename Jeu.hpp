#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Map.hpp"
#include "Attaques.hpp"

struct Joueur
{
    sf::Vector2f position;
    sf::Sprite sprite;
    float vitesse = 200.0f; // pixels par seconde
    float vitesseAugmentee = 400.0f;
    static const int TailleSprite = 48;
    static const int collision_div = 5;

    std::string joueurSprite = "sprites/player/dinoCharactersVersion1.1/sheets/DinoSprites - doux.png";
    sf::Texture textureJoueur; // Ajout pour gérer la texture du sprite du joueur
    std::vector<sf::IntRect> framesJoueur;

    // Taille originelle du Sprite
    static const int frameWidth = 24;
    static const int frameHeight = 24;
    // Position des différent sprite pour l'animation, compter a partir de 0 !!
    static const int frameStartX = 4;
    static const int frameEndX = 9;

    sf::Clock animationClock;
    int currentFrame = 0;
};

struct EcranTitre
{
    void afficherEcranTitre(sf::RenderWindow& fenetre);
    void demarrage(sf::RenderWindow& fenetre);
    void killed(sf::RenderWindow& fenetre);

    sf::Texture textureEcranTitre;
    sf::Sprite spriteEcranTitre;

    sf::Texture textureEldritch;
    sf::Sprite spriteEldritch;

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

    sf::RenderWindow fenetre;
    static const int F_Hauteur = 900;
    static const int F_Largeur = 1600;
    bool killedStatus = false;

    Joueur joueur;

    EcranTitre ecranTitre;

    Attaques attaques;

    Map map;

    void initialiserJeu();
    void traiterEvenements();
    void mettreAJour(sf::Time deltaTime);
    bool collision(int p, sf::Time deltaTime, float vitesseActuelle);
    void dessiner();
    void reinitialiser();
};

#endif
