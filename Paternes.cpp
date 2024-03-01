#include "Jeu.hpp"

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
        if (jeu->attaques.grille_degat[tileX][tileY] == Explosé)
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
            if (jeu->attaques.grille_degat[x][y] == Explosé)
            jeu->attaques.grille_degat[x][y] = Normal;
        }
    }
}


//Moitiée de map ouest
void strike_1(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(2);

    jeu->attaques.Time_to[0] = 1;
    jeu->attaques.Time_to[1] = 2;

    int E_rng;

    //Phases Ombrée
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 6;
                    if (x < jeu->map.T_LARGEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal && E_rng != 0)
                        jeu->attaques.grille_degat[x][y] = Ombré;
                }
            }
            jeu->attaques.paterne_phases++;
        }
    }

    //Phase de Dégats
    else if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[1])
    {
        if (jeu->attaques.paterne_phases == 1)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    //Explosion
                    if (jeu->attaques.grille_degat[x][y] == Ombré)
                        jeu->attaques.grille_degat[x][y] = Explosé;
                }
            }
            jeu->sound.sound3.play();
            jeu->attaques.paterne_phases++;
        }

        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }

    //Phase de fin
    else
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Moitiée de map est
void strike_2(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(2);

    jeu->attaques.Time_to[0] = 1;
    jeu->attaques.Time_to[1] = 2;

    int E_rng;

    //Phases Ombrée
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 6;
                    if (x >= jeu->map.T_LARGEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal && E_rng != 0)
                        jeu->attaques.grille_degat[x][y] = Ombré;
                }
            }
            jeu->attaques.paterne_phases++;
        }
    }

    //Phase de Dégats
    else if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[1])
    {
        if (jeu->attaques.paterne_phases == 1)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    //Explosion
                    if (jeu->attaques.grille_degat[x][y] == Ombré)
                        jeu->attaques.grille_degat[x][y] = Explosé;
                }
            }
            jeu->sound.sound3.play();
            jeu->attaques.paterne_phases++;
        }

        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }

    //Phase de fin
    else
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Moitiée de map nord
void strike_3(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(2);

    jeu->attaques.Time_to[0] = 1;
    jeu->attaques.Time_to[1] = 2;

    int E_rng;

    //Phases Ombrée
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 6;
                    if (y < jeu->map.T_HAUTEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal && E_rng != 0)
                        jeu->attaques.grille_degat[x][y] = Ombré;
                }
            }
            jeu->attaques.paterne_phases++;
        }
    }

    //Phase de Dégats
    else if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[1])
    {
        if (jeu->attaques.paterne_phases == 1)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    //Explosion
                    if (jeu->attaques.grille_degat[x][y] == Ombré)
                        jeu->attaques.grille_degat[x][y] = Explosé;
                }
            }
            jeu->sound.sound3.play();
            jeu->attaques.paterne_phases++;
        }

        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }

    //Phase de fin
    else
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Moitiée de map sud
void strike_4(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(2);

    jeu->attaques.Time_to[0] = 1;
    jeu->attaques.Time_to[1] = 2;

    int E_rng;

    //Phases Ombrée
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 6;
                    if (y >= jeu->map.T_HAUTEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal && E_rng != 0)
                        jeu->attaques.grille_degat[x][y] = Ombré;
                }
            }
            jeu->attaques.paterne_phases++;
        }
    }

    //Phase de Dégats
    else if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[1])
    {
        if (jeu->attaques.paterne_phases == 1)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    //Explosion
                    if (jeu->attaques.grille_degat[x][y] == Ombré)
                        jeu->attaques.grille_degat[x][y] = Explosé;
                }
            }
            jeu->sound.sound3.play();
            jeu->attaques.paterne_phases++;
        }

        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }

    //Phase de fin
    else
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Case aléatoire 1/3
void strike_5(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(2);

    jeu->attaques.Time_to[0] = 1;
    jeu->attaques.Time_to[1] = 2;

    int E_rng;


    //Phases Ombrée
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 3;
                    if (E_rng == 0 && jeu->attaques.grille_degat[x][y] == Normal)
                        jeu->attaques.grille_degat[x][y] = Ombré;
                }
            }
            jeu->attaques.paterne_phases++;
        }
    }

    //Phase de Dégats
    else if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[1])
    {
        if (jeu->attaques.paterne_phases == 1)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    //Explosion
                    if (jeu->attaques.grille_degat[x][y] == Ombré)
                        jeu->attaques.grille_degat[x][y] = Explosé;
                }
            }
            jeu->sound.sound3.play();
            jeu->attaques.paterne_phases++;
        }

        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }

    //Phase de fin
    else
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

// NE PAS OUBLIER D'AJOUTER DANS :: Jeu.cpp -> Reinitialiser, Attaques.hpp -> Paterne ET Fonction au fond, Attaques.cpp -> attaques_rng !!!!!
