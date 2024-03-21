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
        if (jeu->attaques.grille_degat[tileX][tileY] == Explose)
        {
            //jeu->TotalScore += jeu->gold.GoldCount;
            if(jeu->map.map_select == 0 && jeu->gold.GoldCount > jeu->HighScore1)
                jeu->HighScore1 = jeu->gold.GoldCount;
            if(jeu->map.map_select == 1 && jeu->gold.GoldCount > jeu->HighScore2)
                jeu->HighScore2 = jeu->gold.GoldCount;
            if(jeu->map.map_select == 2 && jeu->gold.GoldCount > jeu->HighScore3)
                jeu->HighScore3 = jeu->gold.GoldCount;

            std::ofstream fichierOut("data/Score.txt"); // Crée un objet ofstream et ouvre le fichier
            if (fichierOut.is_open())
            {
                fichierOut << jeu->TotalScore << std::endl << jeu->HighScore1 << std::endl << jeu->HighScore2 << std::endl << jeu->HighScore3 << std::endl << jeu->sprite_reminder << std::endl; // Écrit dans le fichier
                fichierOut.close(); // Ferme le fichier
            }
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
            if (jeu->attaques.grille_degat[x][y] == Explose)
            jeu->attaques.grille_degat[x][y] = Normal;
        }
    }
}


//Moitiée de map ouest
/*void strike_1(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(2);

    jeu->attaques.Time_to[0] = 1;
    jeu->attaques.Time_to[1] = 1.8;

    int E_rng;

    //Phases Ombree
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 8;
                    if (x < jeu->map.T_LARGEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal && E_rng != 0)
                        jeu->attaques.grille_degat[x][y] = Ombre;
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
                    if (jeu->attaques.grille_degat[x][y] == Ombre)
                        jeu->attaques.grille_degat[x][y] = Explose;
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
    jeu->attaques.Time_to[1] = 1.8;

    int E_rng;

    //Phases Ombree
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 8;
                    if (x >= jeu->map.T_LARGEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal && E_rng != 0)
                        jeu->attaques.grille_degat[x][y] = Ombre;
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
                    if (jeu->attaques.grille_degat[x][y] == Ombre)
                        jeu->attaques.grille_degat[x][y] = Explose;
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
    jeu->attaques.Time_to[1] = 1.8;

    int E_rng;

    //Phases Ombree
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 8;
                    if (y < jeu->map.T_HAUTEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal && E_rng != 0)
                        jeu->attaques.grille_degat[x][y] = Ombre;
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
                    if (jeu->attaques.grille_degat[x][y] == Ombre)
                        jeu->attaques.grille_degat[x][y] = Explose;
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
    jeu->attaques.Time_to[1] = 1.8;

    int E_rng;

    //Phases Ombree
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 8;
                    if (y >= jeu->map.T_HAUTEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal && E_rng != 0)
                        jeu->attaques.grille_degat[x][y] = Ombre;
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
                    if (jeu->attaques.grille_degat[x][y] == Ombre)
                        jeu->attaques.grille_degat[x][y] = Explose;
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
}*/

//Case aléatoire 1/2
void strike_5(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(3);

    jeu->attaques.Time_to[0] = 1;
    jeu->attaques.Time_to[1] = 1.8;
    jeu->attaques.Time_to[2] = 1.2;

    int E_rng;


    //Phases Ombree
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    E_rng = rand() % 2;
                    if (E_rng == 0 && jeu->gold.grille[x][y] == false && jeu->attaques.grille_degat[x][y] == Normal)
                        jeu->attaques.grille_degat[x][y] = Ombre;
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
                    if (jeu->attaques.grille_degat[x][y] == Ombre)
                        jeu->attaques.grille_degat[x][y] = Explose;
                }
            }
            jeu->sound.sound3.play();
            jeu->attaques.paterne_phases++;
        }

        if (KO_checker(jeu) && jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[2])
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

//Patche aléatoire sur un coté
void strike_6(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(3);

    jeu->attaques.Time_to[0] = 1;
    jeu->attaques.Time_to[1] = 1.8;
    jeu->attaques.Time_to[2] = 1.2;
    int rayon = 10; // Définir le rayon d'action
    int E_rng;
    int X_rng;
    int Y_rng;

    //Phases Ombree
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            int side = rand() % 4;
            if (side == 0)
            {
                X_rng = rand() % jeu->map.T_LARGEUR;
                Y_rng = 0;
            }
            else if (side == 1)
            {
                X_rng = rand() % jeu->map.T_LARGEUR;
                Y_rng = jeu->map.T_HAUTEUR - 1;
            }
            else if (side == 2)
            {
                X_rng = 0;
                Y_rng = rand() % jeu->map.T_HAUTEUR;
            }
            else if (side == 3)
            {
                X_rng = jeu->map.T_LARGEUR - 1;
                Y_rng = rand() % jeu->map.T_HAUTEUR;
            }
            // Parcourir les cases dans le rayon autour de (X_rng, Y_rng)
            for (int x = X_rng - rayon; x <= X_rng + rayon; ++x)
            {
                for (int y = Y_rng - rayon; y <= Y_rng + rayon; ++y)
                {
                    // Vérifier si la case (x, y) est à l'intérieur des limites de la grille
                    if (x >= 0 && x < static_cast<int>(jeu->attaques.grille_degat.size()) &&
                        y >= 0 && y < static_cast<int>(jeu->attaques.grille_degat[0].size())) 
                    {
                        // Vérifier si la case est à une distance de 5 ou moins de (X_rng, Y_rng)
                        if (std::sqrt(std::pow(x - X_rng, 2) + std::pow(y - Y_rng, 2)) <= rayon)
                        {
                            E_rng = rand() % 7;
                            // Si la case est "Normal", la changer en "Ombre"
                            if (jeu->attaques.grille_degat[x][y] == Normal && E_rng != 0 && jeu->gold.grille[x][y] == false )
                                jeu->attaques.grille_degat[x][y] = Ombre;
                        }
                    }
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
                    if (jeu->attaques.grille_degat[x][y] == Ombre)
                        jeu->attaques.grille_degat[x][y] = Explose;
                }
            }
            jeu->sound.sound3.play();
            jeu->attaques.paterne_phases++;
        }

        if (KO_checker(jeu) && jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[2])
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

//3 petit patche aléatoire
void strike_7(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(3);

    jeu->attaques.Time_to[0] = 1;
    jeu->attaques.Time_to[1] = 1.8;
    jeu->attaques.Time_to[2] = 1.2;
    int rayon = 3; // Définir le rayon d'action
    int nbr_patche = 7;
    //int E_rng;

    //Phases Ombree
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int i = nbr_patche; i > 0; i--)
            {
                int X_rng = rand() % jeu->map.T_LARGEUR;
                int Y_rng = rand() % jeu->map.T_HAUTEUR;
                // Parcourir les cases dans le rayon autour de (X_rng, Y_rng)
                for (int x = X_rng - rayon; x <= X_rng + rayon; ++x)
                {
                    for (int y = Y_rng - rayon; y <= Y_rng + rayon; ++y)
                    {
                        // Vérifier si la case (x, y) est à l'intérieur des limites de la grille
                        if (x >= 0 && x < static_cast<int>(jeu->attaques.grille_degat.size()) &&
                            y >= 0 && y < static_cast<int>(jeu->attaques.grille_degat[0].size())) 
                        {
                            // Vérifier si la case est à une distance de 5 ou moins de (X_rng, Y_rng)
                            if (std::sqrt(std::pow(x - X_rng, 2) + std::pow(y - Y_rng, 2)) <= rayon)
                            {
                                //E_rng = rand() % 8;
                                // Si la case est "Normal", la changer en "Ombre"
                                if (jeu->attaques.grille_degat[x][y] == Normal && jeu->gold.grille[x][y] == false )
                                    jeu->attaques.grille_degat[x][y] = Ombre;
                            }
                        }
                    }
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
                    if (jeu->attaques.grille_degat[x][y] == Ombre)
                        jeu->attaques.grille_degat[x][y] = Explose;
                }
            }
            jeu->sound.sound3.play();
            jeu->attaques.paterne_phases++;
        }

        if (KO_checker(jeu) && jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[2])
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
