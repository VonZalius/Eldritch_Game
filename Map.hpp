#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_set>

class Jeu;

enum TypeTuile
{
    XXX,

    PLA,            //Player,
    Sol,            //Sol
    MP1,            //map 1
    MP2,            //map 2
    MP3,            //map 3

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

    M24,            //Mur grand 1
    M25,            //Mur grand 2

    BA0,            //BarriereNS,
    BA1,            //BarriereEO,
    BA2,            //BarriereNE,
    BA3,            //BarriereSE,
    BA4,            //BarriereSO,
    BA5,            //BarriereNO,

    BA6,            //Barriere fin N,
    BA7,            //Barriere fin E,
    BA8,            //Barriere fin S,
    BA9,            //Barriere fin O,

    PO1,            //Portique 1
    PO2,            //Portique 2


    POT,            //pot


    AR1,            //Arbre1,
    AR2,            //Arbre2,
    AR3,            //Arbre3,
    AR4,            //Arbre4,
    BU1,            //Buisson1,
    BU2,            //Buisson2,
    RO1,            //Rocher1,
    RO2,            //Rocher2,
    RO3,            //RocherGrand,
    RO4,            //RocherGrand,

    CO1,            //Coffre
    PAN,            //Panneau
    TO1,            //Tombe 1
    TO2,            //Tombe 1
    TO3,            //Tombe 1
    FEU,            //Feu de camp éteind

    CH1,            //Champignon Brun NE
    CH2,            //Champignon Brun SE
    CH3,            //Champignon Brun SO
    CH4,            //Champignon Brun NO
    CH5,            //Champignon Rouge NE
    CH6,            //Champignon Rouge SE
    CH7,            //Champignon Rouge SO
    CH8,            //Champignon Rouge NO

    FL1,            //Fleur Rose NE
    FL2,            //Fleur Rose SE
    FL3,            //Fleur Rose SO
    FL4,            //Fleur Rose NO
    FL5,            //Fleur Bleu clair NE
    FL6,            //Fleur Bleu clair SE
    FL7,            //Fleur Bleu clair SO
    FL8,            //Fleur Bleu clair NO



    P01,            //Pont ligne 1 - 1
    P02,            //Pont ligne 1 - 2
    P03,            //Pont ligne 1 - 3
    P04,            //Pont ligne 2 - 1
    P05,            //Pont ligne 2 - 2
    P06,            //Pont ligne 2 - 3
    P07,            //Pont ligne 3 - 1
    P08,            //Pont ligne 3 - 2
    P09,            //Pont ligne 3 - 3
    P10,            //Pont ligne 4 - 1
    P11,            //Pont ligne 4 - 2
    P12,            //Pont ligne 4 - 3
    P13,            //Pont ligne 5 - 1
    P14,            //Pont ligne 5 - 2
    P15,            //Pont ligne 5 - 3
    P16,            //Pont support O
    P17,            //Pont support E

    F29,            //Fin eau/terre NE
    F30,            //Fin eau/terre SE
    F31,            //Fin eau/terre SO
    F32,            //Fin eau/terre NO

    FON            // Fontaine
};

class Map
{
public:
    Map();
    void implementer_Sol(double x_co, double y_co, double x_taille, double y_taille, double x, double y, sf::RenderWindow& fenetre);
    void implementer_Mures(double x_co, double y_co, double x_taille, double y_taille, double x, double y, sf::RenderWindow& fenetre);
    void implementer_Item(double x_co, double y_co, double x_taille, double y_taille, double x, double y, sf::RenderWindow& fenetre);
    void implementer_Bridge(double x_co, double y_co, double x_taille, double y_taille, double x, double y, sf::RenderWindow& fenetre);
    void implementer_Fontaine(double x_co, double y_co, double x_taille, double y_taille, double x, double y, sf::RenderWindow& fenetre);
    void dessiner_bottom(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur);
    void dessiner_top(Jeu *jeu);
    void hub(Jeu *jeu);
    void generer(Jeu *jeu);

    std::string TilesetSol = "sprites/fantasy_/forest_/forest_.png";
    std::string TilesetMur = "sprites/fantasy_/forest_/forest_ [fencesAndWalls].png";
    std::string TilesetItem = "sprites/fantasy_/forest_/forest_ [resources].png";
    std::string TilesetBridge = "sprites/fantasy_/forest_/forest_ [bridgeHorizontal].png";
    std::string TilesetFontaine = "sprites/fantasy_/forest_/forest_ [fountain].png";

    std::unordered_set<TypeTuile> is_Sol = {Sol, MP1, MP2, MP3, CH1, CH2, CH3, CH4, CH5, CH6, CH7, CH8, FL1, FL2, FL3, FL4, FL5, FL6, FL7, FL8, P02, P05, P08, P11, P14};

    int map_select;

    //Zone de jeu
    int T_LARGEUR;
    int T_HAUTEUR;
    std::vector<std::vector<TypeTuile>> grille;
    int TailleTuile;
    float Taille_modifier = 1;
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

    //Tileset Fontaine
    static const int TilesetTilesFontaineSIZE = 16;
    sf::Texture textureFontaine;
    sf::IntRect rectFontaine;


    std::vector<std::vector<int>> grilleRNG;

};

void hub_1(Map *map);
void map_1(Map *map);
void map_2(Map *map);
void map_3(Map *map);

#endif