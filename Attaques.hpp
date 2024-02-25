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
    void attaques_rng(Jeu *jeu);

    sf::Clock attaqueTimer;
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