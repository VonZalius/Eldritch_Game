#ifndef ATTAQUES_HPP
#define ATTAQUES_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Jeu;

enum AttaqueStatus
{
    Inactif,
    Charge,
    Actif
};

enum ZoneDegats
{
    OK,
    KO
};

enum Zones
{
    Normal,
    Ombre,
    Explose
};

typedef void (*FonctionPtr)(Jeu*);

struct Paterne
{
    //AttaqueStatus status = Inactif;
    /*sf::Texture texture_A;
    sf::Sprite sprite_A;
    sf::Texture texture_B;
    sf::Sprite sprite_B;*/
    //TypeTuile **grille;
    FonctionPtr degatZone;

    Paterne(FonctionPtr ptr);
};

struct Attaques
{
    Attaques();
    void generer(int T_LARGEUR, int T_HAUTEUR);
    void attaques_rng(Jeu *jeu);
    void dessiner_zone(Jeu *jeu);

    sf::Clock attaqueTimer;
    bool status = false;
    int rng;
    //std::vector<std::vector<ZoneDegats>> grille;
    //AttaqueStatus global_status = Inactif;
    std::vector<std::vector<Zones>> grille_degat;

    int paterne_phases;
    std::vector<float> Time_to;
    
    /*Paterne A;
    Paterne B;
    Paterne C;
    Paterne D;*/

    Paterne E;
    Paterne F;
    Paterne G;

    //OMBRE
    sf::Sprite sprite;
    int TailleSprite;
    float Taille_modifier = 1;

    // Taille originelle du Sprite
    static const int Width = 16;
    static const int Height = 16;

    // Texture principale
    std::string impactSprite = "sprites/shadow.png";
    sf::Texture textureImpact; // Ajout pour gérer la texture du sprite du joueur
    std::vector<sf::IntRect> framesImpact;
    sf::Clock animationTimer;
    int currentFrame = 0;
    // Position des différent sprite pour l'animation, compter a partir de 0 !!
    static const int TileStartX = 0;
    static const int TileStartY = 0;
    static const int TileEndX = 4;
    static const int TileEndY = 0;

    //IMPACT
    sf::Sprite sprite2;
    int TailleSprite2;
    float Taille_modifier2 = 1.8;

    // Taille originelle du Sprite
    static const int Width2 = 32;
    static const int Height2 = 32;
    // Texture principale
    std::string impactSprite2 = "sprites/Impact.png";
    sf::Texture textureImpact2; // Ajout pour gérer la texture du sprite du joueur
    std::vector<sf::IntRect> framesImpact2;
    int currentFrame2 = 0;
    // Position des différent sprite pour l'animation, compter a partir de 0 !!
    static const int TileStartX2 = 0;
    static const int TileStartY2 = 10;
    static const int TileEndX2 = 4;
    static const int TileEndY2 = 10;
};

/*void strike_1(Jeu *jeu);
void strike_2(Jeu *jeu);
void strike_3(Jeu *jeu);
void strike_4(Jeu *jeu);*/

void strike_5(Jeu *jeu);
void strike_6(Jeu *jeu);
void strike_7(Jeu *jeu);

#endif