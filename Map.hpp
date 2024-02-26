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
    void generer();


    static const int T_LARGEUR = 22;
    static const int T_HAUTEUR = 22;
    static const int TailleTuile = 32;
    static const int TilesetTilesNbrX = 8;
    static const int TilesetTilesNbrY = 4;
    static const int TilesetTilesSIZE = 32;
    TypeTuile grille[T_LARGEUR][T_HAUTEUR];
    int grilleRNG[T_LARGEUR][T_HAUTEUR];

    sf::Texture textureSol;
    sf::IntRect rectSol;
    sf::Texture textureMur;
    void chargerTextures();
};

#endif