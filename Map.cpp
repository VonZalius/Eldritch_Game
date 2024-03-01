#include "Map.hpp"
#include "Jeu.hpp"

Map::Map()
{
}

void Map::generer()
{
    //Choix aléatoire de la map
    int rng = 1;//rand() % 5;
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

    // Assignation aléatoire du sol
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

    //Position départ du joueur
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


void Map::implementer_Sol(double x_co, double y_co, double x_taille, double y_taille, int x, int y, sf::RenderWindow& fenetre)
{
    sf::Sprite sprite;

    rectSol.left = x_co * TilesetTilesSolSIZE; // Nouvelle position X
    rectSol.top = y_co * TilesetTilesSolSIZE; // Nouvelle position Y
    rectSol.width = x_taille * TilesetTilesSolSIZE; // Nouvelle largeur
    rectSol.height = y_taille * TilesetTilesSolSIZE; // Nouvelle hauteur
    sprite.setTexture(textureSol);
    sprite.setTextureRect(rectSol);
    float goodsize = static_cast<float>(TailleTuile) / static_cast<float>(TilesetTilesSolSIZE);
    sprite.setScale(goodsize, goodsize);

    sprite.setPosition((x * TailleTuile) + x_initial - (TailleTuile * (x_taille - 1)), (y * TailleTuile) + y_initial - (TailleTuile * (y_taille - 1)));
    fenetre.draw(sprite);
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

void Map::dessiner_bottom(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur)
{
    // Placement des Tuiles au centre de la fenetre
    y_initial = (F_Hauteur / 2) - ((T_HAUTEUR * TailleTuile) / 2);
    x_initial = (F_Largeur / 2) - ((T_LARGEUR * TailleTuile) / 2);

    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {

            // Le reste
            if (grille[x][y] == XXX)
                implementer_Sol(0, 0, 1, 1, x, y, fenetre);
            else if (grille[x][y] == EAU)
                implementer_Sol(4, 7, 1, 1, x, y, fenetre);

            else if (grille[x][y] == F01)
                implementer_Sol(14, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F02)
                implementer_Sol(14, 3, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F03)
                implementer_Sol(12, 3, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F04)
                implementer_Sol(12, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F05)
                implementer_Sol(16, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F06)
                implementer_Sol(16, 2, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F07)
                implementer_Sol(15, 2, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F08)
                implementer_Sol(15, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F09)
                implementer_Sol(13, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F10)
                implementer_Sol(14, 2, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F11)
                implementer_Sol(13, 3, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F12)
                implementer_Sol(12, 2, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F13)
                implementer_Sol(15, 3, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F14)
                implementer_Sol(16, 3, 1, 1, x, y, fenetre);

            else if (grille[x][y] == F15)
                implementer_Sol(19, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F16)
                implementer_Sol(19, 3, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F17)
                implementer_Sol(17, 3, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F18)
                implementer_Sol(17, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F19)
                implementer_Sol(21, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F20)
                implementer_Sol(21, 2, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F21)
                implementer_Sol(20, 2, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F22)
                implementer_Sol(20, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F23)
                implementer_Sol(18, 1, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F24)
                implementer_Sol(19, 2, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F25)
                implementer_Sol(18, 3, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F26)
                implementer_Sol(17, 2, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F27)
                implementer_Sol(20, 3, 1, 1, x, y, fenetre);
            else if (grille[x][y] == F28)
                implementer_Sol(21, 3, 1, 1, x, y, fenetre);

            else if (grille[x][y] == R01)
                implementer_Sol(3, 5, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R02)
                implementer_Sol(3, 7, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R03)
                implementer_Sol(1, 7, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R04)
                implementer_Sol(1, 5, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R05)
                implementer_Sol(5, 5, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R06)
                implementer_Sol(5, 6, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R07)
                implementer_Sol(4, 6, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R08)
                implementer_Sol(4, 5, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R09)
                implementer_Sol(2, 5, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R10)
                implementer_Sol(3, 6, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R11)
                implementer_Sol(2, 7, 1, 1, x, y, fenetre);
            else if (grille[x][y] == R12)
                implementer_Sol(1, 6, 1, 1, x, y, fenetre);

            // Sol partout !
            else
            {
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
}

void Map::dessiner_top(Jeu *jeu)
{
    // Placement des Tuiles au centre de la fenetre
    y_initial = (jeu->F_Hauteur / 2) - ((T_HAUTEUR * TailleTuile) / 2);
    x_initial = (jeu->F_Largeur / 2) - ((T_LARGEUR * TailleTuile) / 2);

    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {
            if (jeu->joueur.position.y > (y * TailleTuile) + y_initial)
                jeu->fenetre.draw(jeu->joueur.sprite);


            if (grille[x][y] == M00)
                implementer_Mures(1, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M01)
                implementer_Mures(1, 7, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == M02)
                implementer_Mures(1, 9, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == M03)
                implementer_Mures(1, 8, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == M04)
                implementer_Mures(13, 5, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == M05) //Inexistant
                implementer_Mures(0, 0, 0, 0, x, y, jeu->fenetre);
            else if (grille[x][y] == M06)
                implementer_Mures(13, 6, 1, 1, x, y, jeu->fenetre);

            else if (grille[x][y] == M07)
                implementer_Mures(2, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M08)
                implementer_Mures(4, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M09)
                implementer_Mures(3, 5.5, 1, 1.5, x, y, jeu->fenetre); 
            else if (grille[x][y] == M10)
                implementer_Mures(12, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M11)
                implementer_Mures(8, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M12)
                implementer_Mures(9, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M13)
                implementer_Mures(10, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M14)
                implementer_Mures(11, 5.5, 1, 1.5, x, y, jeu->fenetre);

            else if (grille[x][y] == M15)
                implementer_Mures(5, 9.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M16)
                implementer_Mures(5, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M17)
                implementer_Mures(7, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M18)
                implementer_Mures(7, 9.5, 1, 1.5, x, y, jeu->fenetre);
            
            else if (grille[x][y] == M19)
                implementer_Mures(6, 5.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M20)
                implementer_Mures(7, 7.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M21)
                implementer_Mures(6, 9.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M22)
                implementer_Mures(5, 7.5, 1, 1.5, x, y, jeu->fenetre);
            else if (grille[x][y] == M23)
                implementer_Mures(6, 7.5, 1, 1.5, x, y, jeu->fenetre);
            
            else if (grille[x][y] == BA1)
                implementer_Mures(4, 2, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == BA2)
                implementer_Mures(2, 4, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == BA3)
                implementer_Mures(1, 3, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == BA4)
                implementer_Mures(1, 1, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == BA5)
                implementer_Mures(3, 1, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == BA6)
                implementer_Mures(3, 3, 1, 1, x, y, jeu->fenetre);

            else if (grille[x][y] == AR1)
                implementer_Item(1, 1, 1, 2, x, y, jeu->fenetre);
            else if (grille[x][y] == AR2)
                implementer_Item(2, 1, 1, 2, x, y, jeu->fenetre);
            else if (grille[x][y] == AR3)
                implementer_Item(3.5, 1, 2, 2, x, y, jeu->fenetre);
            else if (grille[x][y] == BU1)
                implementer_Item(1, 3, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == BU2)
                implementer_Item(1, 4, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == ROG)
                implementer_Item(2, 3, 2, 2, x, y, jeu->fenetre);
            else if (grille[x][y] == RO1)
                implementer_Item(4, 3, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == RO2)
                implementer_Item(4, 4, 1, 1, x, y, jeu->fenetre);

            else if (grille[x][y] == P11)
                implementer_Bridge(1, 1, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P12)
                implementer_Bridge(1, 2, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P13)
                implementer_Bridge(1, 3, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P21)
                implementer_Bridge(2, 1, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P22)
                implementer_Bridge(2, 2, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P23)
                implementer_Bridge(2, 3, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P31)
                implementer_Bridge(3, 1, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P32)
                implementer_Bridge(3, 2, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P33)
                implementer_Bridge(3, 3, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P41)
                implementer_Bridge(4, 1, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P42)
                implementer_Bridge(4, 2, 1, 1, x, y, jeu->fenetre);
            else if (grille[x][y] == P43)
                implementer_Bridge(4, 3, 1, 1, x, y, jeu->fenetre);
        }
    }
}