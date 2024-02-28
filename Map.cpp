#include "Map.hpp"

Map::Map()
{
}

void Map::generer()
{
    //Choix aléatoire de la map
    int rng = rand() % 4;
    void (*tableauDeFonctions[])(Map *map) =
        {map_1, map_2, map_3, map_4};
    (*tableauDeFonctions[rng])(this);

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
            if (grille[x][y] == Player)
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
            if (grille[x][y] == Mur)
            {
                implementer_Mures(1, 5.5, 1, 1.5, x, y, fenetre);
            }
            if (grille[x][y] == MurNS)
            {
                implementer_Mures(1, 7.5, 1, 1.5, x, y, fenetre);
            }
            else if (grille[x][y] == MurEO)
            {
                implementer_Mures(3, 5.5, 1, 1.5, x, y, fenetre);
            }
            else if (grille[x][y] == MurNE)
            {
                implementer_Mures(5, 9.5, 1, 1.5, x, y, fenetre);
            }
            else if (grille[x][y] == MurSE)
            {
                implementer_Mures(5, 5.5, 1, 1.5, x, y, fenetre);
            }
            else if (grille[x][y] == MurSO)
            {
                implementer_Mures(7, 5.5, 1, 1.5, x, y, fenetre);
            }
            else if (grille[x][y] == MurNO)
            {
                implementer_Mures(7, 9.5, 1, 1.5, x, y, fenetre);
            }
            if (grille[x][y] == BarriereNS)
            {
                implementer_Mures(4, 2, 1, 1, x, y, fenetre);
            }
            else if (grille[x][y] == BarriereEO)
            {
                implementer_Mures(2, 4, 1, 1, x, y, fenetre);
            }
            else if (grille[x][y] == BarriereNE)
            {
                implementer_Mures(1, 3, 1, 1, x, y, fenetre);
            }
            else if (grille[x][y] == BarriereSE)
            {
                implementer_Mures(1, 1, 1, 1, x, y, fenetre);
            }
            else if (grille[x][y] == BarriereSO)
            {
                implementer_Mures(3, 1, 1, 1, x, y, fenetre);
            }
            else if (grille[x][y] == BarriereNO)
            {
                implementer_Mures(3, 3, 1, 1, x, y, fenetre);
            }
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
                map->grille[x][y] = MurSE;
            } else if (x == map->T_LARGEUR - 1 && y == 0) { // Coin nord-est
                map->grille[x][y] = MurSO;
            } else if (x == 0 && y == map->T_HAUTEUR - 1) { // Coin sud-ouest
                map->grille[x][y] = MurNE;
            } else if (x == map->T_LARGEUR - 1 && y == map->T_HAUTEUR - 1) { // Coin sud-est
                map->grille[x][y] = MurNO;
            // Bords spécifiques
            } else if (y == 0 || y == map->T_HAUTEUR - 1) { // Haut et bas
                map->grille[x][y] = MurEO;
            } else if (x == 0 || x == map->T_LARGEUR - 1) { // Gauche et droite
                map->grille[x][y] = MurNS;
            } else {
                map->grille[x][y] = Sol; // Intérieur
            }
        }
    }

    map->grille[5][5] = Player;

    map->grille[3][3] = Mur;
    map->grille[3][4] = Mur;
    map->grille[4][3] = Mur;
    map->grille[18][3] = Mur;
    map->grille[17][3] = Mur;
    map->grille[18][4] = Mur;
    map->grille[3][18] = Mur;
    map->grille[3][17] = Mur;
    map->grille[4][18] = Mur;
    map->grille[18][18] = Mur;
    map->grille[18][17] = Mur;
    map->grille[17][18] = Mur;
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
                map->grille[x][y] = MurSE;
            } else if (x == map->T_LARGEUR - 1 && y == 0) { // Coin nord-est
                map->grille[x][y] = MurSO;
            } else if (x == 0 && y == map->T_HAUTEUR - 1) { // Coin sud-ouest
                map->grille[x][y] = MurNE;
            } else if (x == map->T_LARGEUR - 1 && y == map->T_HAUTEUR - 1) { // Coin sud-est
                map->grille[x][y] = MurNO;
            // Bords spécifiques
            } else if (y == 0 || y == map->T_HAUTEUR - 1) { // Haut et bas
                map->grille[x][y] = MurEO;
            } else if (x == 0 || x == map->T_LARGEUR - 1) { // Gauche et droite
                map->grille[x][y] = MurNS;
            } else {
                map->grille[x][y] = Sol; // Intérieur
            }
        }
    }

    map->grille[5][3] = Player;

    for (int x = 5; x < 15; ++x)
        map->grille[5][x] = Mur;

    /*map->grille[3][3] = MurSE;
    map->grille[3][4] = MurNS;
    map->grille[4][3] = MurEO;
    map->grille[18][3] = MurSO;
    map->grille[17][3] = MurEO;
    map->grille[18][4] = MurNS;
    map->grille[3][18] = MurNE;
    map->grille[3][17] = MurNS;
    map->grille[4][18] = MurEO;
    map->grille[18][18] = MurNO;
    map->grille[18][17] = MurNS;
    map->grille[17][18] = MurEO;*/
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
                map->grille[x][y] = MurSE;
            } else if (x == map->T_LARGEUR - 1 && y == 0) { // Coin nord-est
                map->grille[x][y] = MurSO;
            } else if (x == 0 && y == map->T_HAUTEUR - 1) { // Coin sud-ouest
                map->grille[x][y] = MurNE;
            } else if (x == map->T_LARGEUR - 1 && y == map->T_HAUTEUR - 1) { // Coin sud-est
                map->grille[x][y] = MurNO;
            // Bords spécifiques
            } else if (y == 0 || y == map->T_HAUTEUR - 1) { // Haut et bas
                map->grille[x][y] = MurEO;
            } else if (x == 0 || x == map->T_LARGEUR - 1) { // Gauche et droite
                map->grille[x][y] = MurNS;
            } else {
                map->grille[x][y] = Sol; // Intérieur
            }
        }
    }
    
    map->grille[3][5] = Player;

    for (int x = 5; x < 15; ++x)
        map->grille[x][5] = Mur;
    /*map->grille[3][3] = MurSE;
    map->grille[3][4] = MurNS;
    map->grille[4][3] = MurEO;
    map->grille[18][3] = MurSO;
    map->grille[17][3] = MurEO;
    map->grille[18][4] = MurNS;
    map->grille[3][18] = MurNE;
    map->grille[3][17] = MurNS;
    map->grille[4][18] = MurEO;
    map->grille[18][18] = MurNO;
    map->grille[18][17] = MurNS;
    map->grille[17][18] = MurEO;*/
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
                map->grille[x][y] = MurSE;
            } else if (x == map->T_LARGEUR - 1 && y == 0) { // Coin nord-est
                map->grille[x][y] = MurSO;
            } else if (x == 0 && y == map->T_HAUTEUR - 1) { // Coin sud-ouest
                map->grille[x][y] = MurNE;
            } else if (x == map->T_LARGEUR - 1 && y == map->T_HAUTEUR - 1) { // Coin sud-est
                map->grille[x][y] = MurNO;
            // Bords spécifiques
            } else if (y == 0 || y == map->T_HAUTEUR - 1) { // Haut et bas
                map->grille[x][y] = MurEO;
            } else if (x == 0 || x == map->T_LARGEUR - 1) { // Gauche et droite
                map->grille[x][y] = MurNS;
            } else {
                map->grille[x][y] = Sol; // Intérieur
            }
        }
    }

    map->grille[5][5] = Player;

    for (int y = 7; y <= 14; ++y)
    {
        for (int x = 7; x <= 14; ++x)
        {
            // Coins spécifiques
            if (x == 7 && y == 7) { // Coin nord-ouest
                map->grille[x][y] = BarriereSE;
            } else if (x == 14 && y == 7) { // Coin nord-est
                map->grille[x][y] = BarriereSO;
            } else if (x == 7 && y == 14) { // Coin sud-ouest
                map->grille[x][y] = BarriereNE;
            } else if (x == 14 && y == 14) { // Coin sud-est
                map->grille[x][y] = BarriereNO;
            // Bords spécifiques
            } else if (y == 7 || y == 14) { // Haut et bas
                map->grille[x][y] = BarriereEO;
            } else if (x == 7 || x == 14) { // Gauche et droite
                map->grille[x][y] = BarriereNS;
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

// NE PAS OUBLIER D'AJOUTER DANS :: Map.hpp -> Fonction au fond, Map.cpp -> generer !!!!!