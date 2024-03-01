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






// PROTOTIPE FONCTIONNEL !!!
/*void map_5(Map *map)
{
    map->T_LARGEUR = 26;
    map->T_HAUTEUR = 26;
    
    // Ajuster le nombre de lignes
    map->grille.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grille) {
        ligne.resize(map->T_HAUTEUR);
    }

    // Ajuster le nombre de lignes
    map->grilleRNG.resize(map->T_LARGEUR);
    // Ajuster le nombre de colonnes pour chaque ligne
    for (auto& ligne : map->grilleRNG) {
        ligne.resize(map->T_HAUTEUR);
    }

    map->textureSol.loadFromFile(map->TilesetSol);
    map->textureMur.loadFromFile(map->TilesetMur);
    map->textureItem.loadFromFile(map->TilesetItem);
    map->textureBridge.loadFromFile(map->TilesetBridge);
    // Initialisation simple de la grille avec des murs autour et du sol à l'intérieur



    map->grille[0]  = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
    map->grille[1]  = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
    map->grille[2]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[3]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[4]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[5]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[6]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[7]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[8]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[9]  = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[10] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[11] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[12] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[13] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[14] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,PLA,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[15] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[16] = {EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[17] = {EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[18] = {EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[19] = {EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[20] = {EAU,EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[21] = {EAU,EAU,EAU,EAU,EAU,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[22] = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,AR1,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,Sol,EAU,EAU};
    map->grille[23] = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
    map->grille[24] = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
    map->grille[25] = {EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU,EAU};
    
}*/