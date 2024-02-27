#include "Map.hpp"

Map::Map()
{
    chargerTextures();

    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur

    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {
            // Coins spécifiques
            if (x == 0 && y == 0) { // Coin nord-ouest
                grille[x][y] = MurSE;
            } else if (x == T_LARGEUR - 1 && y == 0) { // Coin nord-est
                grille[x][y] = MurSO;
            } else if (x == 0 && y == T_HAUTEUR - 1) { // Coin sud-ouest
                grille[x][y] = MurNE;
            } else if (x == T_LARGEUR - 1 && y == T_HAUTEUR - 1) { // Coin sud-est
                grille[x][y] = MurNO;
            // Bords spécifiques
            } else if (y == 0 || y == T_HAUTEUR - 1) { // Haut et bas
                grille[x][y] = MurEO;
            } else if (x == 0 || x == T_LARGEUR - 1) { // Gauche et droite
                grille[x][y] = MurNS;
            } else {
                grille[x][y] = Sol; // Intérieur
            }
        }
    }

    grille[3][3] = MurSE;
    grille[3][4] = MurNS;
    grille[4][3] = MurEO;
    grille[18][3] = MurSO;
    grille[17][3] = MurEO;
    grille[18][4] = MurNS;
    grille[3][18] = MurNE;
    grille[3][17] = MurNS;
    grille[4][18] = MurEO;
    grille[18][18] = MurNO;
    grille[18][17] = MurNS;
    grille[17][18] = MurEO;
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
    //textureMur.loadFromFile("sprites/cobblestone.png");
    textureMur.loadFromFile(TilesetMur);
    textureSol.loadFromFile(TilesetSol);
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