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

typedef void (*FonctionPtr)(Jeu*);

struct Paterne
{
    AttaqueStatus status = Inactif;
    sf::Texture texture_A;
    sf::Sprite sprite_A;
    sf::Texture texture_B;
    sf::Sprite sprite_B;
    TypeTuile **grille;
    FonctionPtr degatZone;

    Paterne(int X, int Y, std::string TA, std::string TB, FonctionPtr ptr);
};

struct Attaques
{
    Attaques();
    void generer(int T_LARGEUR, int T_HAUTEUR);
    void attaques_rng(Jeu *jeu);
    void dessiner_zone(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur, Jeu *jeu);

    sf::Clock attaqueTimer;
    bool status = false;
    int rng;
    std::vector<std::vector<ZoneDegats>> grille;
    AttaqueStatus global_status = Inactif;
    Paterne A;
    Paterne B;
    Paterne C;
    Paterne D;
};

void strike_1(Jeu *jeu);
void strike_2(Jeu *jeu);
void strike_3(Jeu *jeu);
void strike_4(Jeu *jeu);

#endif