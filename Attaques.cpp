#include "Jeu.hpp"

//950
Attaques::Attaques() :
    E(strike_5),
    F(strike_6),
    G(strike_7)
{
    if (textureImpact.loadFromFile(impactSprite))
    {
        sprite.setTexture(textureImpact);
        float goodsize = static_cast<float>(TailleSprite) / static_cast<float>(Width);
        sprite.setScale(goodsize, goodsize);
        //sprite.setOrigin(Width / 2, Height / 2);
        for (int ligne = TileStartY; ligne <= TileEndY; ++ligne)
        {
            for (int col = TileStartX; col <= TileEndX; ++col)
            {
                framesImpact.push_back(sf::IntRect(
                    col * Width, // Position X ajustée pour la colonne
                    ligne * Height, // Position Y ajustée pour la ligne
                    Width, // Largeur de la Tile
                    Height // Hauteur de la Tile
                ));
            }
        }
    }

    if (textureImpact2.loadFromFile(impactSprite2))
    {
        sprite2.setTexture(textureImpact2);
        float goodsize2 = static_cast<float>(TailleSprite2) / static_cast<float>(Width2);
        sprite2.setScale(goodsize2, goodsize2);
        //sprite.setOrigin(Width2 / 2, Height2 / 2);
        for (int ligne = TileStartY2; ligne <= TileEndY2; ++ligne)
        {
            for (int col = TileStartX2; col <= TileEndX2; ++col)
            {
                framesImpact2.push_back(sf::IntRect(
                    col * Width2, // Position X ajustée pour la colonne
                    ligne * Height2, // Position Y ajustée pour la ligne
                    Width2, // Largeur de la Tile
                    Height2 // Hauteur de la Tile
                ));
            }
        }
    }
}

Paterne::Paterne(FonctionPtr ptr) : degatZone(ptr)
{}

void Attaques::generer(int T_LARGEUR, int T_HAUTEUR)
{
    // Ajuster le nombre de lignes
    grille_degat.resize(T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : grille_degat)
        ligne.resize(T_HAUTEUR);
    
    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {
            grille_degat[x][y] = Normal;
        }
    }
}

void Attaques::attaques_rng(Jeu *jeu)
{
    if (status == true)
    {
        void (*tableauDeFonctions[])(Jeu *jeu) =
            {E.degatZone, F.degatZone, G.degatZone};
        (*tableauDeFonctions[rng])(jeu);
    }
    else if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        rng = rand() % 3;
        status = true;
        attaqueTimer.restart();
        currentFrame = 0;
        currentFrame2 = 0;
        paterne_phases = 0;
    }
}

void Attaques::dessiner_zone(Jeu *jeu)
{
    // Placement des Tuiles au centre de la fenetre
    jeu->map.y_initial = (jeu->F_Hauteur / 2) - ((jeu->map.T_HAUTEUR * jeu->map.TailleTuile) / 2);
    jeu->map.x_initial = (jeu->F_Largeur / 2) - ((jeu->map.T_LARGEUR * jeu->map.TailleTuile) / 2);

    for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
    {
        for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
        {
            // Sol partout !
            if (grille_degat[x][y] == Ombre && jeu->map.is_Sol.find(jeu->map.grille[x][y]) != jeu->map.is_Sol.end())
            {
                if (animationTimer.getElapsedTime().asSeconds() > ((Time_to[paterne_phases - 1] - Time_to[paterne_phases - 2]) / framesImpact.size()))
                {
                    sprite.setTextureRect(framesImpact[currentFrame]);
                    currentFrame = (currentFrame + 1) % framesImpact.size() ;
                    animationTimer.restart();
                }
                sprite.setPosition((x * jeu->map.TailleTuile) + jeu->map.x_initial, (y * jeu->map.TailleTuile) + jeu->map.y_initial);
                jeu->fenetre.draw(sprite);
            }
            else if (grille_degat[x][y] == Explose && jeu->map.is_Sol.find(jeu->map.grille[x][y]) != jeu->map.is_Sol.end())
            {
                if (animationTimer.getElapsedTime().asSeconds() > ((Time_to[paterne_phases - 1] - Time_to[paterne_phases - 2]) / framesImpact2.size()) )
                {
                    sprite2.setTextureRect(framesImpact2[currentFrame2]);
                    currentFrame2 = (currentFrame2 + 1) % framesImpact2.size() ;
                    animationTimer.restart();
                }
                sprite2.setPosition((x * jeu->map.TailleTuile) + jeu->map.x_initial - (jeu->attaques.Width2 / 2), (y * jeu->map.TailleTuile) + jeu->map.y_initial - (jeu->attaques.Height2 / 2));
                jeu->fenetre.draw(sprite2);
            }
        }
    }
}




//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX




