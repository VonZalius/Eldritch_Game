#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

enum TypeTuile
{
    PLA,            //Player,
    Sol,            //Sol

    EAU,            //Eau

    M00,            //Mur_seul

    M01,            //MurNS_finN1,
    M02,            //MurNS_finS1,
    M03,            //MurNS_suite1,
    M04,            //MurNS_finN2,
    M05,            //M5MurNS_finS2,
    M06,            //MurNS_suite2,

    M07,            //MurEO_finE1,
    M08,            //MurEO_finO1,
    M09,            //MurEO_suite1,
    M10,            //MurEO_finE2,
    M11,            //MurEO_finO2,
    M12,            //MurEO_suite2,

    M13,            //MurNE,
    M14,            //MurSE,
    M15,            //MurSO,
    M16,            //MurNO,

    BA1,            //BarriereNS,
    BA2,            //BarriereEO,
    BA3,            //BarriereNE,
    BA4,            //BarriereSE,
    BA5,            //BarriereSO,
    BA6,            //BarriereNO,


    AR1,            //Arbre1,
    AR2,            //Arbre2,
    AR3,            //Arbre3,
    BU1,            //Buisson1,
    BU2,            //Buisson2,
    ROG,            //RocherGrand,
    RO1,            //Rocher1,
    RO2,            //Rocher2,


    P11,            //Pont1_1,
    P12,            //Pont1_2,
    P13,            //Pont1_3,
    P21,            //Pont2_1,
    P22,            //Pont2_2,
    P23             //Pont2_3 

};

class Map
{
public:
    Map();
    void implementer_Mures(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre);
    void implementer_Item(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre);
    void implementer_Bridge(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre);
    void dessiner_bottom(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur);
    void dessiner_top(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur);
    void generer();

    std::string TilesetSol = "sprites/fantasy_/forest_/forest_.png";
    std::string TilesetMur = "sprites/fantasy_/forest_/forest_ [fencesAndWalls].png";
    std::string TilesetItem = "sprites/fantasy_/forest_/forest_ [resources].png";
    std::string TilesetBridge = "sprites/fantasy_/forest_/forest_ [bridgeVertical].png";
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
    sf::Texture textureSol;
    sf::IntRect rectSol;

    //Tileset MUR
    static const int TilesetTilesMurSIZE = 16;
    sf::Texture textureMur;
    sf::IntRect rectMur;

    //Tileset MUR
    static const int TilesetTilesItemSIZE = 16;
    sf::Texture textureItem;
    sf::IntRect rectItem;

    //Tileset MUR
    static const int TilesetTilesBridgeSIZE = 16;
    sf::Texture textureBridge;
    sf::IntRect rectBridge;


    std::vector<std::vector<int>> grilleRNG;

};

void map_1(Map *map);
void map_2(Map *map);
void map_3(Map *map);
void map_4(Map *map);
void map_5(Map *map);

#endif