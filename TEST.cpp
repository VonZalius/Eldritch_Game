// CE CODE TEST PLUSIEURS ZONE DE DEGAT SIMULTANEMENT ( COMME UNE SERIE DE FRAPPE ).
// LES ZONE DE COLLISION DES ATTAQUES FONCTIONNE.
// LE SEUL PROBLÈME EST CELUI DE L'AFFICHAGE.
// MAIS CELA EST EN RAISON DE L'AFFICHAGE ACTUELLE.
// EN GROS, IL LUI FAUDRAIT UNE ANIMATION D'ATTAQUE SPÉCIALEMENT CONCU.

/*void strike_1(Jeu *jeu)
{
    jeu->attaques.Time_to.resize(3);

    jeu->attaques.Time_to[0] = 2;
    jeu->attaques.Time_to[1] = 4;
    jeu->attaques.Time_to[2] = 6;


    //Phases Ombrée
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[0])
    {
        if (jeu->attaques.paterne_phases == 0)
        {
            for (int y = 0; y < jeu->map.T_HAUTEUR; ++y)
            {
                for (int x = 0; x < jeu->map.T_LARGEUR; ++x)
                { 
                    if (x < jeu->map.T_LARGEUR / 2 && y < jeu->map.T_HAUTEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal)
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
                    //Initialisation de la zone de KO
                    if (x >= jeu->map.T_LARGEUR / 2 && y < jeu->map.T_HAUTEUR / 2 && jeu->attaques.grille_degat[x][y] == Normal)
                        jeu->attaques.grille_degat[x][y] = Ombré;
                    //Explosion
                    else if (jeu->attaques.grille_degat[x][y] == Ombré)
                        jeu->attaques.grille_degat[x][y] = Explosé;
                }
            }
            jeu->sound.sound3.play();
            jeu->attaques.paterne_phases++;
        }

        if (KO_checker(jeu))
            jeu->killedStatus = true;   
    }

    //Phase de Dégats 2
    else if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() < jeu->attaques.Time_to[2])
    {
        if (jeu->attaques.paterne_phases == 2)
        {
            OK_reset(jeu);
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
    else //if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= jeu->attaques.Time_to[jeu->attaques.paterne_phases - 1])
    {
        //Reset OK
        OK_reset(jeu);
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}*/