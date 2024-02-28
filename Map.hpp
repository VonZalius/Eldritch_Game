#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

enum TypeTuile
{
    Player,
    Sol,
    Mur,
    MurNS,
    MurEO,
    MurNE,
    MurSE,
    MurSO,
    MurNO,
    BarriereNS,
    BarriereEO,
    BarriereNE,
    BarriereSE,
    BarriereSO,
    BarriereNO
};

class Map
{
public:
    Map();
    void implementer_Mures(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre);
    void dessiner_bottom(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur);
    void dessiner_top(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur);
    void generer();

    std::string TilesetSol = "sprites/fantasy/forest_/forest_.png";
    std::string TilesetMur = "sprites/fantasy/forest_/forest_ [fencesAndWalls].png";
    //Zone de jeu
    int T_LARGEUR;
    int T_HAUTEUR;
    std::vector<std::vector<TypeTuile>> grille;
    static const int TailleTuile = 32;
    int y_initial;
    int x_initial;
    int player_x;
    int player_y;

    //Tileset SOL, on compte a partir de 0 !
    static const int TilesetTilesX = 22;
    static const int TilesetTilesStartX = 8;
    static const int TilesetTilesEndX = 11;
    static const int TilesetTilesStartY = 1;
    static const int TilesetTilesEndY = 4;

    static const int TilesetTilesSolSIZE = 16;

    //Tileset MUR
    static const int TilesetTilesMurSIZE = 16;


    std::vector<std::vector<int>> grilleRNG;

    sf::Texture textureSol;
    sf::IntRect rectSol;
    sf::Texture textureMur;
    sf::IntRect rectMur;
};

void map_1(Map *map);
void map_2(Map *map);
void map_3(Map *map);
void map_4(Map *map);

#endif