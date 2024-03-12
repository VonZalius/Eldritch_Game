#include "Map.hpp"
#include "Jeu.hpp"

//Hub
void hub_1(Map *map)
{
    map->T_LARGEUR = 20;
    map->T_HAUTEUR = 20;
    
    // Ajuster le nombre de lignes
    map->grille.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grille) {
        ligne.resize(map->T_HAUTEUR);
    }

    // Ajuster le nombre de lignes
    map->grilleRNG.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grilleRNG) {
        ligne.resize(map->T_HAUTEUR);
    }

    map->textureSol.loadFromFile(map->TilesetSol);
    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureItem.loadFromFile(map->TilesetItem);
    map->textureBridge.loadFromFile(map->TilesetBridge);
    map->textureFontaine.loadFromFile(map->TilesetFontaine);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur



    map->grille[0]  = {XXX,F22,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F21,XXX};
    map->grille[1]  = {F22,F16,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F15,F21};
    map->grille[2]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[3]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[4]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,PLA,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[5]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[6]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[7]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R08,F30};
    map->grille[8]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,F09};
    map->grille[9]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R08,R02,F09};
    map->grille[10] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R08,R10,R10,R02,EAU,F09};
    map->grille[11] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R08,R10,R10,R02,EAU,EAU,EAU,EAU,F09};
    map->grille[12] = {F29,R07,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,F09};
    map->grille[13] = {F11,R01,R10,R07,Sol,Sol,R08,R10,R10,R10,R10,R02,EAU,EAU,R04,R12,R12,R03,EAU,F09};
    map->grille[14] = {F11,EAU,EAU,R01,R10,R10,R02,EAU,EAU,EAU,EAU,EAU,R04,R12,R06,Sol,Sol,R11,EAU,F09};
    map->grille[15] = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,R09,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[16] = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,R01,R07,Sol,Sol,R08,R02,EAU,F09};
    map->grille[17] = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,R09,Sol,R08,R02,EAU,EAU,F09};
    map->grille[18] = {F05,F03,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,R01,R10,R02,EAU,EAU,F04,F06};
    map->grille[19] = {XXX,F05,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F06,XXX};
}

//Sanctuaire
void map_1(Map *map)
{
    map->T_LARGEUR = 20;
    map->T_HAUTEUR = 20;
    
    // Ajuster le nombre de lignes
    map->grille.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grille) {
        ligne.resize(map->T_HAUTEUR);
    }

    // Ajuster le nombre de lignes
    map->grilleRNG.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grilleRNG) {
        ligne.resize(map->T_HAUTEUR);
    }

    map->textureSol.loadFromFile(map->TilesetSol);
    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureItem.loadFromFile(map->TilesetItem);
    map->textureBridge.loadFromFile(map->TilesetBridge);
    map->textureFontaine.loadFromFile(map->TilesetFontaine);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur



    map->grille[0]  = {XXX,F08,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F07,XXX};
    map->grille[1]  = {F08,F02,EAU,EAU,EAU,EAU,EAU,EAU,R04,R12,R12,R12,R12,R12,R03,EAU,EAU,EAU,F01,F07};
    map->grille[2]  = {F11,EAU,R04,R12,R03,EAU,R04,R12,R06,Sol,Sol,RO1,Sol,Sol,R05,R12,R03,EAU,EAU,F09};
    map->grille[3]  = {F11,EAU,R09,Sol,R05,R03,R09,AR3,Sol,Sol,Sol,Sol,RO2,Sol,Sol,POT,R11,EAU,EAU,F09};
    map->grille[4]  = {F11,EAU,R09,Sol,FL3,R11,R09,Sol,Sol,FL2,Sol,Sol,Sol,Sol,FL2,Sol,R05,R03,EAU,F09};
    map->grille[5]  = {F11,R04,R06,FL1,Sol,R11,R09,RO2,Sol,Sol,POT,Sol,Sol,Sol,AR3,Sol,Sol,R11,EAU,F09};
    map->grille[6]  = {F11,R09,AR3,Sol,Sol,R05,R06,Sol,Sol,M16,M03,M02,Sol,Sol,Sol,Sol,Sol,R05,R03,F09};
    map->grille[7]  = {F11,R09,FL2,Sol,Sol,AR3,RO1,Sol,Sol,M09,FL3,Sol,Sol,Sol,Sol,FL6,Sol,Sol,R11,F09};
    map->grille[8]  = {F11,R09,Sol,Sol,Sol,Sol,Sol,Sol,AR3,M09,Sol,Sol,BU2,Sol,POT,Sol,Sol,Sol,R11,F09};
    map->grille[9]  = {F11,R09,Sol,Sol,Sol,FL2,Sol,Sol,Sol,M08,Sol,FON,XXX,XXX,XXX,Sol,Sol,RO2,R11,F09};
    map->grille[10] = {F11,R09,Sol,AR3,FL1,Sol,Sol,Sol,Sol,Sol,Sol,XXX,XXX,XXX,XXX,PAN,Sol,Sol,R11,F09};
    map->grille[11] = {F11,R09,FL4,Sol,PLA,Sol,Sol,AR3,Sol,Sol,Sol,XXX,XXX,XXX,XXX,BU2,FL6,Sol,R11,F09};
    map->grille[12] = {F11,R09,Sol,Sol,Sol,FL3,Sol,Sol,FL1,M07,Sol,XXX,XXX,XXX,XXX,Sol,Sol,Sol,R11,F09};
    map->grille[13] = {F11,R09,BU1,Sol,Sol,AR3,Sol,Sol,Sol,M09,Sol,Sol,Sol,BU1,Sol,Sol,BU2,FL6,R11,F09};
    map->grille[14] = {F11,R01,R07,AR3,Sol,Sol,Sol,Sol,Sol,M09,BU1,FL7,Sol,Sol,Sol,Sol,Sol,R08,R02,F09};
    map->grille[15] = {F11,EAU,R09,Sol,FL4,Sol,Sol,FL4,Sol,M17,M03,M02,BU2,Sol,Sol,FL5,Sol,R11,EAU,F09};
    map->grille[16] = {F11,EAU,R01,R07,Sol,Sol,AR3,Sol,FL1,Sol,Sol,Sol,FL8,Sol,Sol,BU2,Sol,R11,EAU,F09};
    map->grille[17] = {F11,EAU,EAU,R01,R10,R10,R07,BU2,Sol,Sol,R08,R10,R07,Sol,BU1,R08,R10,R02,EAU,F09};
    map->grille[18] = {F05,F03,EAU,EAU,EAU,EAU,R01,R10,R10,R10,R02,EAU,R01,R10,R10,R02,EAU,EAU,F04,F06};
    map->grille[19] = {XXX,F05,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F06,XXX};
}


//Ruines
void map_2(Map *map)
{
    map->T_LARGEUR = 20;
    map->T_HAUTEUR = 20;
    
    // Ajuster le nombre de lignes
    map->grille.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grille) {
        ligne.resize(map->T_HAUTEUR);
    }

    // Ajuster le nombre de lignes
    map->grilleRNG.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grilleRNG) {
        ligne.resize(map->T_HAUTEUR);
    }

    map->textureSol.loadFromFile(map->TilesetSol);
    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureItem.loadFromFile(map->TilesetItem);
    map->textureBridge.loadFromFile(map->TilesetBridge);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur



    map->grille[0]  = {XXX,F22,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F21,XXX};
    map->grille[1]  = {F22,F16,Sol,AR2,M16,M02,Sol,Sol,RO1,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,BU1,F15,F21};
    map->grille[2]  = {F25,BU2,CH3,Sol,M24,Sol,AR2,Sol,Sol,Sol,Sol,RO2,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[3]  = {F25,AR2,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,RO1,Sol,Sol,Sol,R08,R07,Sol,Sol,Sol,F23};
    map->grille[4]  = {F25,TO1,Sol,Sol,CH3,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R08,R02,R01,R07,Sol,Sol,F23};
    map->grille[5]  = {F25,Sol,Sol,AR2,M07,BU1,Sol,AR1,Sol,Sol,Sol,Sol,Sol,R11,EAU,EAU,R01,R07,Sol,F23};
    map->grille[6]  = {F25,TO2,Sol,Sol,M19,M03,M02,Sol,Sol,M25,PAN,Sol,Sol,R05,R03,EAU,EAU,R09,CH5,F23};
    map->grille[7]  = {F25,CH1,Sol,Sol,M09,RO2,Sol,Sol,Sol,M08,Sol,Sol,Sol,BU2,R11,EAU,EAU,R09,Sol,F23};
    map->grille[8]  = {F25,Sol,TO3,Sol,M13,Sol,Sol,Sol,Sol,RO2,Sol,Sol,Sol,Sol,R05,R03,R04,R06,Sol,F23};
    map->grille[9]  = {F25,Sol,Sol,Sol,M14,AR2,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R05,R06,BU2,Sol,F23};
    map->grille[10] = {F25,Sol,CH4,M16,M20,M02,PLA,Sol,CH6,Sol,Sol,Sol,M25,Sol,Sol,Sol,AR1,Sol,Sol,F23};
    map->grille[11] = {F25,Sol,AR2,M12,BU2,Sol,Sol,Sol,Sol,Sol,Sol,RO1,M12,BU1,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[12] = {F25,Sol,Sol,M09,BU1,Sol,Sol,Sol,Sol,CH6,Sol,Sol,M09,AR1,Sol,Sol,Sol,CH6,Sol,F23};
    map->grille[13] = {F25,CH5,Sol,M13,Sol,Sol,Sol,Sol,Sol,BU2,Sol,Sol,M13,CH8,Sol,Sol,Sol,AR1,Sol,F23};
    map->grille[14] = {F25,Sol,Sol,M14,CO1,Sol,Sol,M07,Sol,Sol,Sol,AR1,M14,Sol,AR1,Sol,Sol,Sol,Sol,F23};
    map->grille[15] = {F25,Sol,Sol,M12,Sol,Sol,Sol,M12,Sol,M16,M03,M03,M18,Sol,Sol,Sol,Sol,Sol,AR1,F23};
    map->grille[16] = {F25,BU2,Sol,M17,M03,M02,Sol,M17,M03,M18,CH6,Sol,AR1,Sol,Sol,Sol,BU1,Sol,Sol,F23};
    map->grille[17] = {F25,Sol,Sol,Sol,CH8,BU1,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,AR1,Sol,CH5,F23};
    map->grille[18] = {F19,F17,AR1,Sol,Sol,Sol,Sol,Sol,Sol,Sol,BU2,Sol,Sol,Sol,Sol,AR1,CH7,Sol,F18,F20};
    map->grille[19] = {XXX,F19,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F20,XXX};
}

//Canal
void map_3(Map *map)
{
    map->T_LARGEUR = 20;
    map->T_HAUTEUR = 20;
    
    // Ajuster le nombre de lignes
    map->grille.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grille) {
        ligne.resize(map->T_HAUTEUR);
    }

    // Ajuster le nombre de lignes
    map->grilleRNG.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grilleRNG) {
        ligne.resize(map->T_HAUTEUR);
    }

    map->textureSol.loadFromFile(map->TilesetSol);
    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureItem.loadFromFile(map->TilesetItem);
    map->textureBridge.loadFromFile(map->TilesetBridge);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur



    map->grille[0]  = {XXX,F22,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F21,XXX};
    map->grille[1]  = {F22,F16,Sol,CH4,Sol,Sol,Sol,RO2,Sol,Sol,Sol,AR4,M07,Sol,AR4,Sol,Sol,Sol,F15,F21};
    map->grille[2]  = {F25,Sol,AR4,RO2,Sol,Sol,RO1,Sol,Sol,Sol,Sol,Sol,M09,CH1,Sol,Sol,Sol,CH2,Sol,F23};
    map->grille[3]  = {F25,Sol,Sol,Sol,Sol,Sol,CH3,Sol,M07,CH1,Sol,Sol,M08,AR4,Sol,Sol,AR4,Sol,Sol,F23};
    map->grille[4]  = {F25,AR4,Sol,Sol,AR4,Sol,Sol,Sol,M17,M03,M02,Sol,Sol,Sol,Sol,Sol,Sol,AR4,Sol,F23};
    map->grille[5]  = {F25,CH1,Sol,Sol,Sol,AR4,Sol,Sol,Sol,AR4,CH3,Sol,Sol,Sol,CH4,Sol,Sol,Sol,Sol,F23};
    map->grille[6]  = {F29,R10,R10,R07,Sol,P01,P02,P03,Sol,Sol,Sol,Sol,Sol,AR4,Sol,Sol,Sol,Sol,RO2,F23};
    map->grille[7]  = {F11,EAU,EAU,R01,R10,P04,P05,P06,P16,R10,R10,R07,AR4,P01,P02,P03,CH4,R08,R10,F30};
    map->grille[8]  = {F11,EAU,EAU,EAU,EAU,P07,P08,P09,EAU,EAU,EAU,R01,R10,P04,P05,P06,P16,R02,EAU,F09};
    map->grille[9]  = {F32,R12,R03,EAU,EAU,P07,P08,P09,EAU,EAU,EAU,EAU,EAU,P07,P08,P09,EAU,EAU,EAU,F09};
    map->grille[10] = {F25,Sol,R05,R12,R12,P10,P11,P12,P17,R12,R03,EAU,EAU,P07,P08,P09,EAU,EAU,R04,F31};
    map->grille[11] = {F25,FL6,Sol,Sol,BU2,P13,P14,P15,AR4,CH2,R05,R12,R12,P10,P11,P12,P17,R12,R06,F23};
    map->grille[12] = {F25,Sol,FL7,Sol,Sol,Sol,Sol,BU1,FL5,Sol,Sol,Sol,RO2,P13,P14,P15,Sol,CH1,RO1,F23};
    map->grille[13] = {F25,Sol,BU1,Sol,Sol,Sol,Sol,Sol,Sol,Sol,AR4,Sol,Sol,Sol,Sol,Sol,AR4,Sol,Sol,F23};
    map->grille[14] = {F25,BA6,BA0,BA0,BA2,FL7,Sol,Sol,Sol,Sol,Sol,PO1,CH4,Sol,Sol,Sol,Sol,RO1,Sol,F23};
    map->grille[15] = {F25,BU2,Sol,Sol,BA7,PAN,Sol,Sol,Sol,Sol,Sol,Sol,Sol,PLA,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[16] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,FL7,Sol,Sol,PO2,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[17] = {F25,Sol,FL5,Sol,BA9,Sol,Sol,FL6,BU2,Sol,Sol,AR4,Sol,Sol,RO2,Sol,CH2,Sol,Sol,F23};
    map->grille[18] = {F19,F17,BU1,Sol,BA7,BU2,Sol,Sol,Sol,BU1,FL8,Sol,Sol,RO1,Sol,Sol,Sol,AR4,F18,F20};
    map->grille[19] = {XXX,F19,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F20,XXX};
}

// NE PAS OUBLIER D'AJOUTER DANS :: Map.hpp -> Fonction au fond, Map.cpp -> generer !!!!!
/*
    map->grille[0]  = {F22,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F24,F21};
    map->grille[1]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[2]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[3]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[4]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[5]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[6]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[7]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[8]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[9]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[10] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[11] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[12] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[13] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[14] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[15] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[16] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[17] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[18] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[19] = {F19,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F20};
*/