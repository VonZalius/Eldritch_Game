#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

enum TypeTuile
{
    Sol,
    Mur,
    MurNS,
    MurEO,
    MurNE,
    MurSE,
    MurSO,
    MurNO
};

class Map
{
public:
    Map();
    void implementer_Mures(int xs, int ys, int x, int y, sf::RenderWindow& fenetre);
    void dessiner(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur);
    void generer();

    std::string TilesetSol = "sprites/fantasy/forest_/forest_.png";
    std::string TilesetMur = "sprites/fantasy/forest_/forest_ [fencesAndWalls].png";
    //Zone de jeu
    static const int T_LARGEUR = 22;
    static const int T_HAUTEUR = 22;
    static const int TailleTuile = 35;
    TypeTuile grille[T_LARGEUR][T_HAUTEUR];
    int y_initial;
    int x_initial;

    //Tileset SOL, on compte a partir de 0 !
    static const int TilesetTilesX = 22;
    static const int TilesetTilesStartX = 8;
    static const int TilesetTilesEndX = 11;
    static const int TilesetTilesStartY = 1;
    static const int TilesetTilesEndY = 4;

    static const int TilesetTilesSolSIZE = 16;

    //Tileset MUR
    static const int TilesetTilesMurSIZE = 16;


    int grilleRNG[T_LARGEUR][T_HAUTEUR];

    sf::Texture textureSol;
    sf::IntRect rectSol;
    sf::Texture textureMur;
    sf::IntRect rectMur;
    void chargerTextures();
};

#endif