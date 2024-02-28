#include "Jeu.hpp"

//950
Attaques::Attaques() :
    A(strike_1),
    B(strike_2),
    C(strike_3),
    D(strike_4),
    E(strike_5)
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
        float goodsize = static_cast<float>(TailleSprite2) / static_cast<float>(Width2);
        sprite2.setScale(goodsize, goodsize);
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
    grille.resize(T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : grille)
        ligne.resize(T_HAUTEUR);
    
    for (int y = 0; y < T_HAUTEUR; ++y)
    {
        for (int x = 0; x < T_LARGEUR; ++x)
        {
            grille[x][y] = OK;
        }
    }
}

void Attaques::attaques_rng(Jeu *jeu)
{
    if (status == true)
    {
        void (*tableauDeFonctions[])(Jeu *jeu) =
            {A.degatZone, B.degatZone, C.degatZone, D.degatZone, E.degatZone};
        (*tableauDeFonctions[rng])(jeu);
    }
    else if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        rng = rand() % 5;
        status = true;
    }
}

void Attaques::dessiner_zone(Jeu *jeu)
{
    // Placement des Tuiles au centre de la fenetre
    jeu->map.y_initial = (jeu->F_Hauteur / 2) - ((jeu->map.T_HAUTEUR * jeu->map.TailleTuile) / 2);
    jeu->map.x_initial = (jeu->F_Largeur / 2) - ((jeu->map.T_LARGEUR * jeu->map.TailleTuile) / 2);

    /*sf::Texture sprite;
    if (jeu->attaques.global_status == Charge)
        sprite.loadFromFile("sprites/attaqueA1_A.png");
    else if (jeu->attaques.global_status == Actif)
        sprite.loadFromFile("sprites/attaqueA1_B.png");
    sf::Sprite sprite2;
    sprite2.setTexture(sprite);

    float goodsize = static_cast<float>(jeu->map.TailleTuile) / static_cast<float>(950);
    sprite2.setScale(goodsize, goodsize);

    for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
    {
        for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
        {
            // Sol partout !
            if (grille[x][y] == KO)
            {
                sprite2.setPosition((x * jeu->map.TailleTuile) + jeu->map.x_initial, (y * jeu->map.TailleTuile) + jeu->map.y_initial);
                jeu->fenetre.draw(sprite2);
            }
        }
    }*/

    if(global_status == Charge)
    {
        if (animationTimer.getElapsedTime().asSeconds() > 0.20f )
        {
            sprite.setTextureRect(framesImpact[currentFrame]);
            currentFrame = (currentFrame + 1) % framesImpact.size() ;
            animationTimer.restart();
        }
        for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
        {
            for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
            {
                // Sol partout !
                if (grille[x][y] == KO && jeu->map.grille[x][y] == Sol)
                {
                    sprite.setPosition((x * jeu->map.TailleTuile) + jeu->map.x_initial, (y * jeu->map.TailleTuile) + jeu->map.y_initial);
                    jeu->fenetre.draw(sprite);
                }
            }
        }
        currentFrame2 = 0;
    }
    if(global_status == Actif)
    {
        if (animationTimer.getElapsedTime().asSeconds() > 0.20f )
        {
            sprite2.setTextureRect(framesImpact2[currentFrame2]);
            currentFrame2 = (currentFrame2 + 1) % framesImpact2.size() ;
            animationTimer.restart();
        }
        for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
        {
            for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
            {
                // Sol partout !
                if (grille[x][y] == KO && jeu->map.grille[x][y] == Sol)
                {
                    sprite2.setPosition((x * jeu->map.TailleTuile) + jeu->map.x_initial - (jeu->attaques.Width2 / 2), (y * jeu->map.TailleTuile) + jeu->map.y_initial - (jeu->attaques.Height2 / 2));
                    jeu->fenetre.draw(sprite2);
                }
            }
        }
        currentFrame = 0;
    }
}

bool KO_checker(Jeu *jeu)
{
    int jpx = jeu->joueur.position.x - ((jeu->F_Largeur / 2) - ((jeu->map.T_LARGEUR * jeu->map.TailleTuile) / 2));
    int jpy = jeu->joueur.position.y - ((jeu->F_Hauteur / 2) - ((jeu->map.T_HAUTEUR * jeu->map.TailleTuile) / 2));

    // Calcul du centre du joueur
    int rayon = jeu->joueur.TailleSprite / jeu->joueur.collision_div;

    // Points à vérifier sur le cercle
    int points[8][2] =
    {
        {jpx + rayon, jpy}, // Droite
        {jpx - rayon, jpy}, // Gauche
        {jpx, jpy - rayon}, // Haut
        {jpx, jpy + rayon}, // Bas
        {static_cast<int>(jpx + rayon / sqrt(2)), static_cast<int>(jpy + rayon / sqrt(2))}, // Bas-droite
        {static_cast<int>(jpx - rayon / sqrt(2)), static_cast<int>(jpy + rayon / sqrt(2))}, // Bas-gauche
        {static_cast<int>(jpx + rayon / sqrt(2)), static_cast<int>(jpy - rayon / sqrt(2))}, // Haut-droite
        {static_cast<int>(jpx - rayon / sqrt(2)), static_cast<int>(jpy - rayon / sqrt(2))}  // Haut-gauche
    };

    // Vérification de chaque point
    for (int i = 0; i < 8; ++i)
    {
        int x = points[i][0];
        int y = points[i][1];

        // Convertir les coordonnées du point en indices de grille
        int tileX = x / jeu->map.TailleTuile;
        int tileY = y / jeu->map.TailleTuile;

        // Vérification si le point n'est pas sur une tuile 'Sol'
        if (jeu->attaques.grille[tileX][tileY] == KO)
        {
            return true; // Collision détectée
        }
    }

    return false; // Aucune collision détectée
}

void OK_reset(Jeu *jeu)
{
    for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
    {
        for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
        { 
            jeu->attaques.grille[x][y] = OK;
        }
    }
}

//Moitiée de map ouest
void strike_1(Jeu *jeu)
{
    //Phases de Charge
    if (jeu->attaques.A.status == Inactif)
    {
        jeu->attaques.attaqueTimer.restart();
        //Initialisation de la zone de KO
        for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
        {
            for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
            { 
                if (x < jeu->map.T_LARGEUR / 2)
                    jeu->attaques.grille[x][y] = KO;
            }
        }
        jeu->attaques.A.status = Charge;
        jeu->attaques.global_status = Charge;
    }

    //Phase de Dégats
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        if (jeu->attaques.A.status == Charge)
        {
            jeu->sound.sound3.play();
            jeu->attaques.A.status = Actif;
            jeu->attaques.global_status = Actif;
        }
        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }
    
    //Phase de fin
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 2)
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.A.status = Inactif;
        jeu->attaques.global_status = Inactif;
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Moitiée de map est
void strike_2(Jeu *jeu)
{
    //Phases de Charge
    if (jeu->attaques.B.status == Inactif)
    {
        jeu->attaques.attaqueTimer.restart();
        //Initialisation de la zone de KO
        for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
        {
            for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
            { 
                if (x >= jeu->map.T_LARGEUR / 2)
                    jeu->attaques.grille[x][y] = KO;
            }
        }
        jeu->attaques.B.status = Charge;
        jeu->attaques.global_status = Charge;
    }

    //Phase de Dégats
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        if (jeu->attaques.B.status == Charge)
        {
            jeu->sound.sound3.play();
            jeu->attaques.B.status = Actif;
            jeu->attaques.global_status = Actif;
        }
        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }
    
    //Phase de fin
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 2)
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.B.status = Inactif;
        jeu->attaques.global_status = Inactif;
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Moitiée de map nord
void strike_3(Jeu *jeu)
{
    //Phases de Charge
    if (jeu->attaques.C.status == Inactif)
    {
        jeu->attaques.attaqueTimer.restart();
        //Initialisation de la zone de KO
        for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
        {
            for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
            { 
                if (y < jeu->map.T_HAUTEUR / 2)
                    jeu->attaques.grille[x][y] = KO;
            }
        }
        jeu->attaques.C.status = Charge;
        jeu->attaques.global_status = Charge;
    }

    //Phase de Dégats
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        if (jeu->attaques.C.status == Charge)
        {
            jeu->sound.sound3.play();
            jeu->attaques.C.status = Actif;
            jeu->attaques.global_status = Actif;
        }
        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }
    
    //Phase de fin
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 2)
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.C.status = Inactif;
        jeu->attaques.global_status = Inactif;
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Moitiée de map sud
void strike_4(Jeu *jeu)
{
    //Phases de Charge
    if (jeu->attaques.D.status == Inactif)
    {
        jeu->attaques.attaqueTimer.restart();
        //Initialisation de la zone de KO
        for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
        {
            for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
            { 
                if (y >= jeu->map.T_HAUTEUR / 2)
                    jeu->attaques.grille[x][y] = KO;
            }
        }
        jeu->attaques.D.status = Charge;
        jeu->attaques.global_status = Charge;
    }

    //Phase de Dégats
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        if (jeu->attaques.D.status == Charge)
        {
            jeu->sound.sound3.play();
            jeu->attaques.D.status = Actif;
            jeu->attaques.global_status = Actif;
        }
        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }
    
    //Phase de fin
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 2)
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.D.status = Inactif;
        jeu->attaques.global_status = Inactif;
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Case aléatoire 1/3
void strike_5(Jeu *jeu)
{
    //Phases de Charge
    if (jeu->attaques.E.status == Inactif)
    {
        int E_rng;
        jeu->attaques.attaqueTimer.restart();
        //Initialisation de la zone de KO
        for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
        {
            for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
            { 
                E_rng = rand() % 3;
                if (E_rng == 0)
                    jeu->attaques.grille[x][y] = KO;
            }
        }
        jeu->attaques.E.status = Charge;
        jeu->attaques.global_status = Charge;
    }

    //Phase de Dégats
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        if (jeu->attaques.E.status == Charge)
        {
            jeu->sound.sound3.play();
            jeu->attaques.E.status = Actif;
            jeu->attaques.global_status = Actif;
        }
        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }
    
    //Phase de fin
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 2)
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.E.status = Inactif;
        jeu->attaques.global_status = Inactif;
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

// NE PAS OUBLIER D'AJOUTER DANS :: Jeu.cpp -> Reinitialiser, Attaques.hpp -> Paterne ET Fonction au fond, Attaques.cpp -> attaques_rng !!!!!