#include "Map.hpp"

Map::Map()
{
}

void Map::generer()
{
    //Choix aléatoire de la map
    int rng = 4;//rand() % 5;
    void (*tableAUEAUDeFonctions[])(Map *map) =
        {map_1, map_2, map_3, map_4, map_5};
    (*tableAUEAUDeFonctions[rng])(this);

    // Limites du rectangle spécifié (en termes de ligne et colonne)
    int debutColonne = TilesetTilesStartX, finColonne = TilesetTilesEndX;
    int debutLigne = TilesetTilesStartY, finLigne = TilesetTilesEndY;
    // Calcul des indices linéaires du sous-rectangle
    std::vector<int> indicesRectangle;
    for (int ligne = debutLigne; ligne <= finLigne; ++ligne)
    {
        for (int colonne = debutColonne; colonne <= finColonne; ++colonne)
        {
            int indiceLineaire = ligne * (TilesetTilesX + 1) + colonne;
            indicesRectangle.push_back(indiceLineaire);
        }
    }
    // Assignation aléatoire
    for (int y = 0; y < (T_HAUTEUR + 0); ++y)
    {
        for (int x = 0 ; x < (T_LARGEUR + 0); ++x)
        {

            // Générer un indice aléatoire parmi les indices du rectangle
            grilleRNG[x][y] = indicesRectangle[rand() % indicesRectangle.size()];
            //std::cout << grilleRNG[x][y] << " , ";
            //EXEPTIONS
            if (grilleRNG[x][y] == 77 || grilleRNG[x][y] == 78 || grilleRNG[x][y] == 100 || grilleRNG[x][y] == 101)
                x--;
        }
    }

    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {
            if (grille[x][y] == PLA)
            {
                player_x = (x * TailleTuile);
                player_y = (y * TailleTuile);
                grille[x][y] = Sol;
            }
        }
    }
}

void Map::dessiner_bottom(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur)
{
    // Placement des Tuiles au centre de la fenetre
    y_initial = (F_Hauteur / 2) - ((T_HAUTEUR * TailleTuile) / 2);
    x_initial = (F_Largeur / 2) - ((T_LARGEUR * TailleTuile) / 2);

    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {
            // Sol partout !
            sf::Sprite sprite;
            rectSol.left = (grilleRNG[x][y] % (TilesetTilesX + 1)) * TilesetTilesSolSIZE; // Nouvelle position X
            rectSol.top = (grilleRNG[x][y] / (TilesetTilesX + 1)) * TilesetTilesSolSIZE; // Nouvelle position Y
            rectSol.width = TilesetTilesSolSIZE; // Nouvelle largeur
            rectSol.height = TilesetTilesSolSIZE; // Nouvelle hauteur
            sprite.setTexture(textureSol);
            sprite.setTextureRect(rectSol);
            float goodsize = static_cast<float>(TailleTuile) / static_cast<float>(TilesetTilesSolSIZE);
            sprite.setScale(goodsize, goodsize);
            sprite.setPosition((x * TailleTuile) + x_initial, (y * TailleTuile) + y_initial);
            fenetre.draw(sprite);
        }
    }
}

void Map::implementer_Mures(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre)
{
    sf::Sprite sprite;

    rectMur.left = x_co * TilesetTilesMurSIZE; // Nouvelle position X
    rectMur.top = y_co * TilesetTilesMurSIZE; // Nouvelle position Y
    rectMur.width = x_taille * TilesetTilesMurSIZE; // Nouvelle largeur
    rectMur.height = y_taille * TilesetTilesMurSIZE; // Nouvelle hauteur
    sprite.setTexture(textureMur);
    sprite.setTextureRect(rectMur);
    float goodsize = static_cast<float>(TailleTuile) / static_cast<float>(TilesetTilesMurSIZE);
    sprite.setScale(goodsize, goodsize);

    sprite.setPosition((x * TailleTuile) + x_initial - (TailleTuile * (x_taille - 1)), (y * TailleTuile) + y_initial - (TailleTuile * (y_taille - 1)));
    fenetre.draw(sprite);
}

void Map::implementer_Item(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre)
{
    sf::Sprite sprite;

    rectItem.left = x_co * TilesetTilesItemSIZE; // Nouvelle position X
    rectItem.top = y_co * TilesetTilesItemSIZE; // Nouvelle position Y
    rectItem.width = x_taille * TilesetTilesItemSIZE; // Nouvelle largeur
    rectItem.height = y_taille * TilesetTilesItemSIZE; // Nouvelle hauteur
    sprite.setTexture(textureItem);
    sprite.setTextureRect(rectItem);
    float goodsize = static_cast<float>(TailleTuile) / static_cast<float>(TilesetTilesItemSIZE);
    sprite.setScale(goodsize, goodsize);

    sprite.setPosition((x * TailleTuile) + x_initial - (TailleTuile * (x_taille - 1)), (y * TailleTuile) + y_initial - (TailleTuile * (y_taille - 1)));
    fenetre.draw(sprite);
}

void Map::implementer_Bridge(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre)
{
    sf::Sprite sprite;

    rectBridge.left = x_co * TilesetTilesBridgeSIZE; // Nouvelle position X
    rectBridge.top = y_co * TilesetTilesBridgeSIZE; // Nouvelle position Y
    rectBridge.width = x_taille * TilesetTilesBridgeSIZE; // Nouvelle largeur
    rectBridge.height = y_taille * TilesetTilesBridgeSIZE; // Nouvelle hauteur
    sprite.setTexture(textureBridge);
    sprite.setTextureRect(rectBridge);
    float goodsize = static_cast<float>(TailleTuile) / static_cast<float>(TilesetTilesBridgeSIZE);
    sprite.setScale(goodsize, goodsize);

    sprite.setPosition((x * TailleTuile) + x_initial - (TailleTuile * (x_taille - 1)), (y * TailleTuile) + y_initial - (TailleTuile * (y_taille - 1)));
    fenetre.draw(sprite);
}

void Map::dessiner_top(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur)
{
    // Placement des Tuiles au centre de la fenetre
    y_initial = (F_Hauteur / 2) - ((T_HAUTEUR * TailleTuile) / 2);
    x_initial = (F_Largeur / 2) - ((T_LARGEUR * TailleTuile) / 2);

    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {
            // Le reste
            if (grille[x][y] == M00)
                implementer_Mures(1, 5.5, 1, 1.5, x, y, fenetre);
            else if (grille[x][y] == M01)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == M02)
                implementer_Mures(1, 7.5, 1, 1.5, x, y, fenetre);
            else if (grille[x][y] == M03)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == M04)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == M05)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == M06)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == M07)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == M08)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == M09)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre); 
            else if (grille[x][y] == M10)
                implementer_Mures(3, 5.5, 1, 1.5, x, y, fenetre);
            else if (grille[x][y] == M11)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == M12)
                implementer_Mures(0, 0, 0, 0, x, y, fenetre);

            else if (grille[x][y] == M13)
                implementer_Mures(5, 9.5, 1, 1.5, x, y, fenetre);
            else if (grille[x][y] == M14)
                implementer_Mures(5, 5.5, 1, 1.5, x, y, fenetre);
            else if (grille[x][y] == M15)
                implementer_Mures(7, 5.5, 1, 1.5, x, y, fenetre);
            else if (grille[x][y] == M16)
                implementer_Mures(7, 9.5, 1, 1.5, x, y, fenetre);
            
            else if (grille[x][y] == BA1)
                implementer_Mures(4, 2, 1, 1, x, y, fenetre);
            else if (grille[x][y] == BA2)
                implementer_Mures(2, 4, 1, 1, x, y, fenetre);
            else if (grille[x][y] == BA3)
                implementer_Mures(1, 3, 1, 1, x, y, fenetre);
            else if (grille[x][y] == BA4)
                implementer_Mures(1, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == BA5)
                implementer_Mures(3, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == BA6)
                implementer_Mures(3, 3, 1, 1, x, y, fenetre);

            else if (grille[x][y] == AR1)
                implementer_Item(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == AR2)
                implementer_Item(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == AR3)
                implementer_Item(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == BU1)
                implementer_Item(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == BU2)
                implementer_Item(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == ROG)
                implementer_Item(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == RO1)
                implementer_Item(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == RO2)
                implementer_Item(0, 0, 0, 0, x, y, fenetre);

            else if (grille[x][y] == P11)
                implementer_Bridge(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == P12)
                implementer_Bridge(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == P13)
                implementer_Bridge(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == P21)
                implementer_Bridge(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == P22)
                implementer_Bridge(0, 0, 0, 0, x, y, fenetre);
            else if (grille[x][y] == P23)
                implementer_Bridge(0, 0, 0, 0, x, y, fenetre);
        }
    }
}

void map_1(Map *map)
{
    map->T_LARGEUR = 22;
    map->T_HAUTEUR = 22;
    
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

    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureSol.loadFromFile(map->TilesetSol);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur

    //Pourtour
    for (int y = 0; y < map->T_HAUTEUR; ++y)
    {
        for (int x = 0; x < map->T_LARGEUR; ++x)
        {
            // Coins spécifiques
            if (x == 0 && y == 0) { // Coin nord-ouest
                map->grille[x][y] = M14;
            } else if (x == map->T_LARGEUR - 1 && y == 0) { // Coin nord-est
                map->grille[x][y] = M15;
            } else if (x == 0 && y == map->T_HAUTEUR - 1) { // Coin sud-ouest
                map->grille[x][y] = M13;
            } else if (x == map->T_LARGEUR - 1 && y == map->T_HAUTEUR - 1) { // Coin sud-est
                map->grille[x][y] = M16;
            // Bords spécifiques
            } else if (y == 0 || y == map->T_HAUTEUR - 1) { // Haut et bas
                map->grille[x][y] = M10;
            } else if (x == 0 || x == map->T_LARGEUR - 1) { // Gauche et droite
                map->grille[x][y] = M02;
            } else {
                map->grille[x][y] = Sol; // Intérieur
            }
        }
    }

    map->grille[5][5] = PLA;

    map->grille[3][3] = M00;
    map->grille[3][4] = M00;
    map->grille[4][3] = M00;
    map->grille[18][3] = M00;
    map->grille[17][3] = M00;
    map->grille[18][4] = M00;
    map->grille[3][18] = M00;
    map->grille[3][17] = M00;
    map->grille[4][18] = M00;
    map->grille[18][18] = M00;
    map->grille[18][17] = M00;
    map->grille[17][18] = M00;
}

void map_2(Map *map)
{
    map->T_LARGEUR = 11;
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

    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureSol.loadFromFile(map->TilesetSol);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur

    //Pourtour
    for (int y = 0; y < map->T_HAUTEUR; ++y)
    {
        for (int x = 0; x < map->T_LARGEUR; ++x)
        {
            // Coins spécifiques
            if (x == 0 && y == 0) { // Coin nord-ouest
                map->grille[x][y] = M14;
            } else if (x == map->T_LARGEUR - 1 && y == 0) { // Coin nord-est
                map->grille[x][y] = M15;
            } else if (x == 0 && y == map->T_HAUTEUR - 1) { // Coin sud-ouest
                map->grille[x][y] = M13;
            } else if (x == map->T_LARGEUR - 1 && y == map->T_HAUTEUR - 1) { // Coin sud-est
                map->grille[x][y] = M16;
            // Bords spécifiques
            } else if (y == 0 || y == map->T_HAUTEUR - 1) { // Haut et bas
                map->grille[x][y] = M10;
            } else if (x == 0 || x == map->T_LARGEUR - 1) { // Gauche et droite
                map->grille[x][y] = M02;
            } else {
                map->grille[x][y] = Sol; // Intérieur
            }
        }
    }

    map->grille[5][3] = PLA;

    for (int x = 5; x < 15; ++x)
        map->grille[5][x] = M00;

    /*map->grille[3][3] = M15;
    map->grille[3][4] = M02;
    map->grille[4][3] = M10;
    map->grille[18][3] = M16;
    map->grille[17][3] = M10;
    map->grille[18][4] = M02;
    map->grille[3][18] = M14;
    map->grille[3][17] = M02;
    map->grille[4][18] = M10;
    map->grille[18][18] = M17;
    map->grille[18][17] = M02;
    map->grille[17][18] = M10;*/
}

void map_3(Map *map)
{
    map->T_LARGEUR = 20;
    map->T_HAUTEUR = 11;
    
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

    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureSol.loadFromFile(map->TilesetSol);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur

    //Pourtour
    for (int y = 0; y < map->T_HAUTEUR; ++y)
    {
        for (int x = 0; x < map->T_LARGEUR; ++x)
        {
            // Coins spécifiques
            if (x == 0 && y == 0) { // Coin nord-ouest
                map->grille[x][y] = M14;
            } else if (x == map->T_LARGEUR - 1 && y == 0) { // Coin nord-est
                map->grille[x][y] = M15;
            } else if (x == 0 && y == map->T_HAUTEUR - 1) { // Coin sud-ouest
                map->grille[x][y] = M13;
            } else if (x == map->T_LARGEUR - 1 && y == map->T_HAUTEUR - 1) { // Coin sud-est
                map->grille[x][y] = M16;
            // Bords spécifiques
            } else if (y == 0 || y == map->T_HAUTEUR - 1) { // Haut et bas
                map->grille[x][y] = M10;
            } else if (x == 0 || x == map->T_LARGEUR - 1) { // Gauche et droite
                map->grille[x][y] = M02;
            } else {
                map->grille[x][y] = Sol; // Intérieur
            }
        }
    }
    
    map->grille[3][5] = PLA;

    for (int x = 5; x < 15; ++x)
        map->grille[x][5] = M00;
    /*map->grille[3][3] = M15;
    map->grille[3][4] = M02;
    map->grille[4][3] = M10;
    map->grille[18][3] = M16;
    map->grille[17][3] = M10;
    map->grille[18][4] = M02;
    map->grille[3][18] = M14;
    map->grille[3][17] = M02;
    map->grille[4][18] = M10;
    map->grille[18][18] = M17;
    map->grille[18][17] = M02;
    map->grille[17][18] = M10;*/
}

void map_4(Map *map)
{
    map->T_LARGEUR = 22;
    map->T_HAUTEUR = 22;
    
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

    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureSol.loadFromFile(map->TilesetSol);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur

    //Pourtour
    for (int y = 0; y < map->T_HAUTEUR; ++y)
    {
        for (int x = 0; x < map->T_LARGEUR; ++x)
        {
            // Coins spécifiques
            if (x == 0 && y == 0) { // Coin nord-ouest
                map->grille[x][y] = M14;
            } else if (x == map->T_LARGEUR - 1 && y == 0) { // Coin nord-est
                map->grille[x][y] = M15;
            } else if (x == 0 && y == map->T_HAUTEUR - 1) { // Coin sud-ouest
                map->grille[x][y] = M13;
            } else if (x == map->T_LARGEUR - 1 && y == map->T_HAUTEUR - 1) { // Coin sud-est
                map->grille[x][y] = M16;
            // Bords spécifiques
            } else if (y == 0 || y == map->T_HAUTEUR - 1) { // Haut et bas
                map->grille[x][y] = M10;
            } else if (x == 0 || x == map->T_LARGEUR - 1) { // Gauche et droite
                map->grille[x][y] = M02;
            } else {
                map->grille[x][y] = Sol; // Intérieur
            }
        }
    }

    map->grille[5][5] = PLA;

    for (int y = 7; y <= 14; ++y)
    {
        for (int x = 7; x <= 14; ++x)
        {
            // Coins spécifiques
            if (x == 7 && y == 7) { // Coin nord-ouest
                map->grille[x][y] = BA4;
            } else if (x == 14 && y == 7) { // Coin nord-est
                map->grille[x][y] = BA5;
            } else if (x == 7 && y == 14) { // Coin sud-ouest
                map->grille[x][y] = BA3;
            } else if (x == 14 && y == 14) { // Coin sud-est
                map->grille[x][y] = BA6;
            // Bords spécifiques
            } else if (y == 7 || y == 14) { // Haut et bas
                map->grille[x][y] = BA2;
            } else if (x == 7 || x == 14) { // Gauche et droite
                map->grille[x][y] = BA1;
            } else {
                map->grille[x][y] = Sol; // Intérieur
            }
        }
    }
    /*map->grille[17][3] = Mur;
    map->grille[18][4] = Mur;
    map->grille[3][18] = Mur;
    map->grille[3][17] = Mur;
    map->grille[4][18] = Mur;
    map->grille[18][18] = Mur;
    map->grille[18][17] = Mur;
    map->grille[17][18] = Mur;*/
}

void map_5(Map *map)
{
    map->T_LARGEUR = 26;
    map->T_HAUTEUR = 26;
    
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

    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureSol.loadFromFile(map->TilesetSol);
    map->textureSol.loadFromFile(map->TilesetItem);
    map->textureSol.loadFromFile(map->TilesetBridge);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur



    map->grille[0]  = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
    map->grille[1]  = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
    map->grille[2]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[3]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[4]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[5]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[6]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[7]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[8]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[9]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[10] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[11] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[12] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[13] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[14] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,PLA,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[15] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[16] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[17] = {EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[18] = {EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[19] = {EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[20] = {EAU,EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[21] = {EAU,EAU,EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[22] = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[23] = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
    map->grille[24] = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
    map->grille[25] = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
}

// NE PAS OUBLIER D'AJOUTER DANS :: Map.hpp -> Fonction au fond, Map.cpp -> generer !!!!!