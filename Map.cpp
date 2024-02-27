#include "Map.hpp"

Map::Map()
{
}

void Map::generer()
{
    //Choix aléatoire de la map
    int rng = rand() % 3;
    void (*tableauDeFonctions[])(Map *map) =
        {map_1, map_2, map_3};
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

void Map::implementer_Mures(int xs, int ys, int x, int y, sf::RenderWindow& fenetre)
{
    sf::Sprite sprite;

    rectMur.left = xs * TilesetTilesMurSIZE; // Nouvelle position X
    rectMur.top = ys * TilesetTilesMurSIZE; // Nouvelle position Y
    rectMur.width = TilesetTilesMurSIZE; // Nouvelle largeur
    rectMur.height = TilesetTilesMurSIZE; // Nouvelle hauteur
    sprite.setTexture(textureMur);
    sprite.setTextureRect(rectMur);
    float goodsize = static_cast<float>(TailleTuile) / static_cast<float>(TilesetTilesMurSIZE);
    sprite.setScale(goodsize, goodsize);

    sprite.setPosition((x * TailleTuile) + x_initial, (y * TailleTuile) + y_initial);
    fenetre.draw(sprite);
}

void Map::dessiner(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur)
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
            
            // Le reste
            if (grille[x][y] == MurNS)
            {
                implementer_Mures(4, 2, x, y, fenetre);
            }
            else if (grille[x][y] == MurEO)
            {
                implementer_Mures(2, 4, x, y, fenetre);
            }
            else if (grille[x][y] == MurNE)
            {
                implementer_Mures(1, 3, x, y, fenetre);
            }
            else if (grille[x][y] == MurSE)
            {
                implementer_Mures(1, 1, x, y, fenetre);
            }
            else if (grille[x][y] == MurSO)
            {
                implementer_Mures(3, 1, x, y, fenetre);
            }
            else if (grille[x][y] == MurNO)
            {
                implementer_Mures(3, 3, x, y, fenetre);
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

    map->grille[3][3] = MurSE;
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
    map->grille[17][18] = MurEO;
}

void map_2(Map *map)
{
    map->T_LARGEUR = 10;
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

    map->grille[5][5] = Player;

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
    map->T_HAUTEUR = 10;
    
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