#include "Jeu.hpp"

Gold::Gold()
{
    if (textureGold.loadFromFile(goldSprite))
    {
        sprite.setTexture(textureGold);
        //sprite.setOrigin(Width / 2, Height / 2);
        for (int ligne = TileStartY; ligne <= TileEndY; ++ligne)
        {
            for (int col = TileStartX; col <= TileEndX; ++col)
            {
                framesGold.push_back(sf::IntRect(
                    col * Width, // Position X ajustée pour la colonne
                    ligne * Height, // Position Y ajustée pour la ligne
                    Width, // Largeur de la Tile
                    Height // Hauteur de la Tile
                ));
            }
        }
    }

    if (font.loadFromFile("sprites/police.ttf"))
    {
        texteCount.setFont(font); 
        //texteCount.setString(std::to_string(GoldCount));
        texteCount.setCharacterSize(200); // en pixels
        texteCount.setFillColor(sf::Color::White);
        //float largeurTexte = texteCount.getLocalBounds().width;
        texteCount.setPosition(50, 150); // Ajustez selon vos besoins
    }

    if (buffer1.loadFromFile(SoundFile1))
    {
        sound1.setBuffer(buffer1);
        sound1.setVolume(soundVolume1);
    }

    status = false;
}

void Gold::generer(int T_LARGEUR, int T_HAUTEUR)
{
    float goodsize = static_cast<float>(TailleSprite) / static_cast<float>(Width);
    sprite.setScale(goodsize, goodsize);
    // Ajuster le nombre de lignes
    grille.resize(T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : grille)
        ligne.resize(T_HAUTEUR);
    
    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {
            grille[x][y] = false;
        }
    }
    GoldCount = 0;
}

void Gold::gold_rng(Jeu *jeu)
{

    while (status == false)
    {
        rngX = rand() % jeu->map.T_LARGEUR;
        rngY = rand() % jeu->map.T_HAUTEUR;
        if (jeu->map.is_Sol.find(jeu->map.grille[rngX][rngY]) != jeu->map.is_Sol.end())
        {
            grille[rngX][rngY] = true;
            status = true;
        }
    }
}

void Gold::afficherGold(Jeu *jeu)
{
    for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
    {
        for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
        {
            // Sol partout !
            if (grille[x][y] == true)
            {
                sprite.setPosition((x * jeu->map.TailleTuile) + jeu->map.x_initial, (y * jeu->map.TailleTuile) + jeu->map.y_initial);
                jeu->fenetre.draw(sprite);
            }
        }
    }
}

void Gold::getGold(int x, int y)
{
    sound1.play();
    grille[x][y] = false;
    status = false;
    GoldCount++;
}