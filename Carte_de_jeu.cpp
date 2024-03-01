#include "Map.hpp"
#include "Jeu.hpp"

// Petite île
void map_1(Map *map)
{
    map->T_LARGEUR = 14;
    map->T_HAUTEUR = 14;
    
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



    map->grille[0]  = {F08,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F07};
    map->grille[1]  = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,F09};
    map->grille[2]  = {F11,EAU,R04,R12,R12,R12,R12,R12,R12,R12,R12,R03,EAU,F09};
    map->grille[3]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[4]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,M07,Sol,Sol,R11,EAU,F09};
    map->grille[5]  = {F11,EAU,R09,Sol,Sol,RO2,Sol,Sol,M17,M02,Sol,R11,EAU,F09};
    map->grille[6]  = {F11,EAU,R09,Sol,AR1,Sol,Sol,PLA,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[7]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[8]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,BU1,Sol,Sol,R11,EAU,F09};
    map->grille[9]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,AR1,Sol,R11,EAU,F09};
    map->grille[10] = {F11,EAU,R09,Sol,BU2,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[11] = {F11,EAU,R01,R10,R10,R10,R10,R10,R10,R10,R10,R02,EAU,F09};
    map->grille[12] = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,F09};
    map->grille[13] = {F05,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F06};
}


//Château
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
    map->grille[1]  = {F22,F16,Sol,Sol,M16,M02,Sol,Sol,RO1,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,BU1,F15,F21};
    map->grille[2]  = {F25,Sol,Sol,Sol,M08,Sol,Sol,Sol,Sol,Sol,Sol,RO2,Sol,Sol,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[3]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,RO1,Sol,Sol,Sol,R08,R07,Sol,Sol,Sol,F23};
    map->grille[4]  = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R08,R02,R01,R07,Sol,Sol,F23};
    map->grille[5]  = {F25,Sol,Sol,Sol,M07,Sol,Sol,AR1,Sol,Sol,Sol,Sol,Sol,R11,EAU,EAU,R01,R07,Sol,F23};
    map->grille[6]  = {F25,Sol,Sol,Sol,M19,M03,M02,Sol,Sol,M07,Sol,Sol,Sol,R05,R03,EAU,EAU,R09,Sol,F23};
    map->grille[7]  = {F25,Sol,Sol,Sol,M09,RO2,Sol,Sol,Sol,M08,Sol,Sol,Sol,BU2,R11,EAU,EAU,R09,Sol,F23};
    map->grille[8]  = {F25,Sol,Sol,Sol,M09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R05,R03,R04,R06,Sol,F23};
    map->grille[9]  = {F25,Sol,Sol,Sol,M09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R05,R06,BU2,Sol,F23};
    map->grille[10] = {F25,Sol,Sol,M16,M20,M02,PLA,Sol,Sol,Sol,Sol,Sol,M07,Sol,Sol,Sol,AR1,Sol,Sol,F23};
    map->grille[11] = {F25,Sol,Sol,M09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,M09,BU1,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[12] = {F25,Sol,Sol,M09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,M09,AR1,Sol,Sol,Sol,Sol,Sol,F23};
    map->grille[13] = {F25,Sol,Sol,M09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,M09,Sol,Sol,Sol,Sol,AR1,Sol,F23};
    map->grille[14] = {F25,Sol,Sol,M09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,M09,Sol,AR1,Sol,Sol,Sol,Sol,F23};
    map->grille[15] = {F25,Sol,Sol,M09,Sol,Sol,Sol,M07,Sol,M16,M03,M03,M18,Sol,Sol,Sol,Sol,Sol,AR1,F23};
    map->grille[16] = {F25,Sol,Sol,M17,M03,M02,Sol,M17,M03,M18,Sol,Sol,AR1,Sol,Sol,Sol,BU1,Sol,Sol,F23};
    map->grille[17] = {F25,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,AR1,Sol,Sol,F23};
    map->grille[18] = {F19,F17,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,BU2,Sol,Sol,Sol,Sol,AR1,Sol,Sol,F18,F20};
    map->grille[19] = {XXX,F19,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F26,F20,XXX};
}

void map_3(Map *map)
{
    map->T_LARGEUR = 14;
    map->T_HAUTEUR = 14;
    
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



    map->grille[0]  = {F08,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F07};
    map->grille[1]  = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,F09};
    map->grille[2]  = {F11,EAU,R04,R12,R12,R12,R12,R12,R12,R12,R12,R03,EAU,F09};
    map->grille[3]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[4]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,M07,Sol,Sol,R11,EAU,F09};
    map->grille[5]  = {F11,EAU,R09,Sol,Sol,RO2,Sol,Sol,M17,M02,Sol,R11,EAU,F09};
    map->grille[6]  = {F11,EAU,R09,Sol,AR1,Sol,Sol,PLA,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[7]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[8]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,BU1,Sol,Sol,R11,EAU,F09};
    map->grille[9]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,AR1,Sol,R11,EAU,F09};
    map->grille[10] = {F11,EAU,R09,Sol,BU2,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[11] = {F11,EAU,R01,R10,R10,R10,R10,R10,R10,R10,R10,R02,EAU,F09};
    map->grille[12] = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,F09};
    map->grille[13] = {F05,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F06};
}

void map_4(Map *map)
{
    map->T_LARGEUR = 14;
    map->T_HAUTEUR = 14;
    
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



    map->grille[0]  = {F08,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F07};
    map->grille[1]  = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,F09};
    map->grille[2]  = {F11,EAU,R04,R12,R12,R12,R12,R12,R12,R12,R12,R03,EAU,F09};
    map->grille[3]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[4]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,M07,Sol,Sol,R11,EAU,F09};
    map->grille[5]  = {F11,EAU,R09,Sol,Sol,RO2,Sol,Sol,M17,M02,Sol,R11,EAU,F09};
    map->grille[6]  = {F11,EAU,R09,Sol,AR1,Sol,Sol,PLA,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[7]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[8]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,BU1,Sol,Sol,R11,EAU,F09};
    map->grille[9]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,AR1,Sol,R11,EAU,F09};
    map->grille[10] = {F11,EAU,R09,Sol,BU2,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[11] = {F11,EAU,R01,R10,R10,R10,R10,R10,R10,R10,R10,R02,EAU,F09};
    map->grille[12] = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,F09};
    map->grille[13] = {F05,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F06};
}

void map_5(Map *map)
{
    map->T_LARGEUR = 14;
    map->T_HAUTEUR = 14;
    
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



    map->grille[0]  = {F08,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F10,F07};
    map->grille[1]  = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,F09};
    map->grille[2]  = {F11,EAU,R04,R12,R12,R12,R12,R12,R12,R12,R12,R03,EAU,F09};
    map->grille[3]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[4]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,M07,Sol,Sol,R11,EAU,F09};
    map->grille[5]  = {F11,EAU,R09,Sol,Sol,RO2,Sol,Sol,M17,M02,Sol,R11,EAU,F09};
    map->grille[6]  = {F11,EAU,R09,Sol,AR1,Sol,Sol,PLA,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[7]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[8]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,BU1,Sol,Sol,R11,EAU,F09};
    map->grille[9]  = {F11,EAU,R09,Sol,Sol,Sol,Sol,Sol,Sol,AR1,Sol,R11,EAU,F09};
    map->grille[10] = {F11,EAU,R09,Sol,BU2,Sol,Sol,Sol,Sol,Sol,Sol,R11,EAU,F09};
    map->grille[11] = {F11,EAU,R01,R10,R10,R10,R10,R10,R10,R10,R10,R02,EAU,F09};
    map->grille[12] = {F11,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,F09};
    map->grille[13] = {F05,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F12,F06};
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