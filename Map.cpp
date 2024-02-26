#include "Map.hpp"

Map::Map()
{
    chargerTextures();

    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur
    for (int y = 0; y < (T_HAUTEUR + 0); ++y)
    {
        for (int x = 0 ; x < (T_LARGEUR + 0); ++x)
        {
            if (x == 0 || y == 0 || x == T_LARGEUR - 1 || y == T_HAUTEUR - 1)
            {
                grille[x][y] = Mur;
            }
            else
            {
                grille[x][y] = Sol;
            }
        }
    }
    grille[3][3] = Mur;
    grille[3][4] = Mur;
    grille[4][3] = Mur;
    grille[18][3] = Mur;
    grille[17][3] = Mur;
    grille[18][4] = Mur;
    grille[3][18] = Mur;
    grille[3][17] = Mur;
    grille[4][18] = Mur;
    grille[18][18] = Mur;
    grille[18][17] = Mur;
    grille[17][18] = Mur;
}

void Map::generer()
{
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
}

void Map::chargerTextures()
{
    // Chargez ici les textures pour le sol et le mur
    //textureSol.loadFromFile("sprites/cobblestone.png");
    textureMur.loadFromFile("sprites/bricks.png");
    textureSol.loadFromFile(TilesetSol);
}

void Map::dessiner(sf::RenderWindow& fenetre, const int F_Hauteur, const int F_Largeur)
{
    // Placement des Tuiles au centre de la fenetre
    int y_initial = (F_Hauteur / 2) - ((T_HAUTEUR * TailleTuile) / 2);
    int x_initial = (F_Largeur / 2) - ((T_LARGEUR * TailleTuile) / 2);

    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {
            sf::Sprite sprite;
            if (grille[x][y] == Sol)
            {
                rectSol.left = (grilleRNG[x][y] % (TilesetTilesX + 1)) * TilesetTilesSIZE; // Nouvelle position X
                rectSol.top = (grilleRNG[x][y] / (TilesetTilesX + 1)) * TilesetTilesSIZE; // Nouvelle position Y
                rectSol.width = TilesetTilesSIZE; // Nouvelle largeur
                rectSol.height = TilesetTilesSIZE; // Nouvelle hauteur
                sprite.setTexture(textureSol);
                sprite.setTextureRect(rectSol);
                float goodsize = TailleTuile / TilesetTilesSIZE;
                sprite.setScale(goodsize, goodsize);
            }
            else if (grille[x][y] == Mur)
            {
                sprite.setTexture(textureMur);
            }
            sprite.setPosition((x * TailleTuile) + x_initial, (y * TailleTuile) + y_initial);
            fenetre.draw(sprite);
        }
    }
}