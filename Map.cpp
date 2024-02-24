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
}

void Map::chargerTextures()
{
    // Chargez ici les textures pour le sol et le mur
    textureSol.loadFromFile("sprites/cobblestone.png");
    textureMur.loadFromFile("sprites/bricks.png");
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
                sprite.setTexture(textureSol);
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