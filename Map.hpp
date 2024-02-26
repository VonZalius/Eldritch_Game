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

    std::string TilesetSol = "sprites/fantasy/forest_/forest_.png";
    //Zone de jeu
    static const int T_LARGEUR = 22;
    static const int T_HAUTEUR = 22;
    static const int TailleTuile = 32;
    TypeTuile grille[T_LARGEUR][T_HAUTEUR];

    //Tileset, on compte a partir de 0 !
    static const int TilesetTilesX = 22;

    static const int TilesetTilesStartX = 8;
    static const int TilesetTilesEndX = 11;
    static const int TilesetTilesStartY = 1;
    static const int TilesetTilesEndY = 4;

    static const int TilesetTilesSIZE = 16;


    int grilleRNG[T_LARGEUR][T_HAUTEUR];

    sf::Texture textureSol;
    sf::IntRect rectSol;
    sf::Texture textureMur;
    void chargerTextures();
};

#endif