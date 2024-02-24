#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

enum TypeTuile
{
    Sol,
    Mur
};

class Map
{
public:
    Map();
    void dessiner(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur);


    static const int T_LARGEUR = 12;
    static const int T_HAUTEUR = 12;
    static const int TailleTuile = 32;
    TypeTuile grille[T_LARGEUR][T_HAUTEUR];
    sf::Texture textureSol;
    sf::Texture textureMur;
    void chargerTextures();
};

#endif