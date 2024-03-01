#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Jeu;

enum TypeTuile
{
    XXX,

    PLA,            //Player,
    Sol,            //Sol

    EAU,            //Eau

    F01,            //Fin eau NE
    F02,            //Fin eau SE
    F03,            //Fin eau SO
    F04,            //Fin eau NO

    F05,            //Fin eau interieur NE
    F06,            //Fin eau interieur SE     
    F07,            //Fin eau interieur SO
    F08,            //Fin eau interieur NO

    F09,            //Fin eau N
    F10,            //Fin eau E
    F11,            //Fin eau S
    F12,            //Fin eau O

    F13,            //Fin eau inter NO-SE
    F14,            //Fin eau inter NE-SO

    F15,            //Fin sol NE
    F16,            //Fin sol SE
    F17,            //Fin sol SO
    F18,            //Fin sol NO

    F19,            //Fin sol interieur NE
    F20,            //Fin sol interieur SE     
    F21,            //Fin sol interieur SO
    F22,            //Fin sol interieur NO

    F23,            //Fin sol N
    F24,            //Fin sol E
    F25,            //Fin sol S
    F26,            //Fin sol O

    F27,            //Fin sol inter NO-SE
    F28,            //Fin sol inter NE-SO


    R01,            //Bord de l'eau NE
    R02,            //Bord de l'eau SE
    R03,            //Bord de l'eau SO
    R04,            //Bord de l'eau NO

    R05,            //Bord de l'eau interieur NE
    R06,            //Bord de l'eau interieur SE
    R07,            //Bord de l'eau interieur SO
    R08,            //Bord de l'eau interieur NO

    R09,            //Bord de l'eau N
    R10,            //Bord de l'eau E
    R11,            //Bord de l'eau S
    R12,            //Bord de l'eau O

    M00,            //Mur_seul

    M01,            //MurNS_finN1,
    M02,            //MurNS_finS1,
    M03,            //MurNS_suite1,
    M04,            //MurNS_finN2,
    M05,            //MurNS_finS2,  inexistant
    M06,            //MurNS_suite2,

    M07,            //MurEO_finE1,
    M08,            //MurEO_finO1,
    M09,            //MurEO_suite1,
    M10,            //MurEO_finE2,
    M11,            //MurEO_finO2,
    M12,            //MurEO_suite2_1,
    M13,            //MurEO_suite2_2,
    M14,            //MurEO_suite2_3,

    M15,            //MurNE,
    M16,            //MurSE,
    M17,            //MurSO,
    M18,            //MurNO,

    M19,            //Mur croisement xN,
    M20,            //Mur croisement xE,
    M21,            //Mur croisement xS,
    M22,            //Mur croisement xO,
    M23,            //Mur croisement tout,

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
    P23,            //Pont2_3 
    P31,            //Pont3_1,
    P32,            //Pont3_2,
    P33,            //Pont3_3,
    P41,            //Pont4_1,
    P42,            //Pont4_2,
    P43             //Pont4_3 

};

class Map
{
public:
    Map();
    void implementer_Sol(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre);
    void implementer_Mures(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre);
    void implementer_Item(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre);
    void implementer_Bridge(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre);
    void dessiner_bottom(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur);
    void dessiner_top(Jeu *jeu);
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
    static const int TilesetTilesStartY = 0;
    static const int TilesetTilesEndY = 4;


    //Tileset Sol
    static const int TilesetTilesSolSIZE = 16;
    sf::Texture textureSol;
    sf::IntRect rectSol;

    //Tileset MUR
    static const int TilesetTilesMurSIZE = 16;
    sf::Texture textureMur;
    sf::IntRect rectMur;

    //Tileset Item
    static const int TilesetTilesItemSIZE = 16;
    sf::Texture textureItem;
    sf::IntRect rectItem;

    //Tileset Bridge
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