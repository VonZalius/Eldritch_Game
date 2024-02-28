#include "Jeu.hpp"

Jeu::Jeu() : fenetre(sf::VideoMode(F_Largeur, F_Hauteur), "Eldritch", sf::Style::None | sf::Style::Fullscreen)
{
    initialiserJeu();
}

void Jeu::initialiserJeu()
{
    srand(time(0));

    //JOUEUR
    if (joueur.textureJoueur.loadFromFile(joueur.joueurSprite))
    {
        joueur.sprite.setTexture(joueur.textureJoueur);
        float goodsize = static_cast<float>(joueur.TailleSprite) / static_cast<float>(joueur.frameWidth);
        joueur.sprite.setScale(goodsize, goodsize);
        joueur.sprite.setOrigin(joueur.frameWidth / 2, joueur.frameHeight / 2);

        for (int ligne = joueur.frameStartY; ligne <= joueur.frameEndY; ++ligne)
        {
            for (int col = joueur.frameStartX; col <= joueur.frameEndX; ++col)
            {
                joueur.framesJoueur.push_back(sf::IntRect(
                    col * joueur.frameWidth, // Position X ajustée pour la colonne
                    ligne * joueur.frameHeight, // Position Y ajustée pour la ligne
                    joueur.frameWidth, // Largeur de la frame
                    joueur.frameHeight // Hauteur de la frame
                ));
            }
        }

        for (int ligne = joueur.frameStartY_2; ligne <= joueur.frameEndY_2; ++ligne)
        {
            for (int col = joueur.frameStartX_2; col <= joueur.frameEndX_2; ++col)
            {
                joueur.framesJoueur_2.push_back(sf::IntRect(
                    col * joueur.frameWidth, // Position X ajustée pour la colonne
                    ligne * joueur.frameHeight, // Position Y ajustée pour la ligne
                    joueur.frameWidth, // Largeur de la frame
                    joueur.frameHeight // Hauteur de la frame
                ));
            }
        }
    }

    //MUSIC
    if (sound.musique1.openFromFile(sound.musiqueFile1))
    {
        sound.musique1.setLoop(true);
        //sound.musique1.setVolume(sound.volume1);
    }

    if (sound.musique2.openFromFile(sound.musiqueFile2))
    {
        sound.musique2.setLoop(true);
        //sound.musique2.setVolume(sound.volume2);
    }   

    if (sound.buffer1.loadFromFile(sound.SoundFile1))
    {
        sound.sound1.setBuffer(sound.buffer1);
        //sound.sound1.setVolume(sound.soundVolume1);
    }

    if (sound.buffer2.loadFromFile(sound.SoundFile2))
    {
        sound.sound2.setBuffer(sound.buffer2);
        //sound.sound2.setVolume(sound.soundVolume2);
    }

    if (sound.buffer3.loadFromFile(sound.SoundFile3))
    {
        sound.sound3.setBuffer(sound.buffer3);
        //sound.sound3.setVolume(sound.soundVolume3);
    }

    if (sound.buffer4.loadFromFile(sound.SoundFile4))
    {
        sound.sound4.setBuffer(sound.buffer4);
        //sound.sound4.setVolume(sound.soundVolume4);
    }


    //TITRES
    if (ecranTitre.textureEcranTitre.loadFromFile("sprites/planches.png"))
    {
        ecranTitre.spriteEcranTitre.setTexture(ecranTitre.textureEcranTitre);
        float largeurTitre = ecranTitre.spriteEcranTitre.getLocalBounds().width;
        float hauteurTitre = ecranTitre.spriteEcranTitre.getLocalBounds().height;
        float goodsize = static_cast<float>(F_Largeur) / static_cast<float>(largeurTitre);
        float goodsize2 = static_cast<float>(F_Hauteur) / static_cast<float>(hauteurTitre);
        ecranTitre.spriteEcranTitre.setScale(goodsize, goodsize2);
    }

    if (ecranTitre.textureEldritch.loadFromFile("sprites/Eldritch.png"))
    {
        ecranTitre.spriteEldritch.setTexture(ecranTitre.textureEldritch);  
        //ecranTitre.spriteEldritch.setScale(0.5f, 0.5f);
        float largeurEldritch = ecranTitre.spriteEldritch.getLocalBounds().width;
        ecranTitre.spriteEldritch.setPosition((F_Largeur / 2) - (largeurEldritch / 2), 200);
    }

    if (ecranTitre.font.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteTitre.setFont(ecranTitre.font); 
        ecranTitre.texteTitre.setString("Appuyez sur une touche pour commencer");
        ecranTitre.texteTitre.setCharacterSize(50); // en pixels
        ecranTitre.texteTitre.setFillColor(sf::Color::White);
        float largeurTexte = ecranTitre.texteTitre.getLocalBounds().width;
        ecranTitre.texteTitre.setPosition((F_Largeur / 2) - (largeurTexte / 2), 550); // Ajustez selon vos besoins
    }

    if (ecranTitre.fontDemarrage.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteDemarrage3.setFont(ecranTitre.fontDemarrage); 
        ecranTitre.texteDemarrage3.setString("3...");
        ecranTitre.texteDemarrage3.setCharacterSize(100); // en pixels
        ecranTitre.texteDemarrage3.setFillColor(sf::Color::White);
        float largeurTexte = ecranTitre.texteDemarrage3.getLocalBounds().width;
        float hauteurTexte = ecranTitre.texteDemarrage3.getLocalBounds().height;
        ecranTitre.texteDemarrage3.setPosition((F_Largeur / 2) - (largeurTexte / 2), (F_Hauteur / 2) - (hauteurTexte));
    }
    if (ecranTitre.fontDemarrage.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteDemarrage2.setFont(ecranTitre.fontDemarrage); 
        ecranTitre.texteDemarrage2.setString("2...");
        ecranTitre.texteDemarrage2.setCharacterSize(100); // en pixels
        ecranTitre.texteDemarrage2.setFillColor(sf::Color::White);
        float largeurTexte = ecranTitre.texteDemarrage2.getLocalBounds().width;
        float hauteurTexte = ecranTitre.texteDemarrage2.getLocalBounds().height;
        ecranTitre.texteDemarrage2.setPosition((F_Largeur / 2) - (largeurTexte / 2), (F_Hauteur / 2) - (hauteurTexte));
    }
    if (ecranTitre.fontDemarrage.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteDemarrage1.setFont(ecranTitre.fontDemarrage); 
        ecranTitre.texteDemarrage1.setString("1...");
        ecranTitre.texteDemarrage1.setCharacterSize(100); // en pixels
        ecranTitre.texteDemarrage1.setFillColor(sf::Color::White);
        float largeurTexte = ecranTitre.texteDemarrage1.getLocalBounds().width;
        float hauteurTexte = ecranTitre.texteDemarrage1.getLocalBounds().height;
        ecranTitre.texteDemarrage1.setPosition((F_Largeur / 2) - (largeurTexte / 2), (F_Hauteur / 2) - (hauteurTexte));
    }
    if (ecranTitre.fontKilled.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteKilled.setFont(ecranTitre.fontKilled); 
        //ecranTitre.texteKilled.setString("Vous etes mort...\nFin de partie !");
        ecranTitre.texteKilled.setCharacterSize(100); // en pixels
        ecranTitre.texteKilled.setFillColor(sf::Color::White);
        /*float largeurTexte = ecranTitre.texteKilled.getLocalBounds().width;
        float hauteurTexte = ecranTitre.texteKilled.getLocalBounds().height;
        ecranTitre.texteKilled.setPosition((F_Largeur / 2) - (largeurTexte / 2), (F_Hauteur / 2) - (hauteurTexte));*/
    }
}

void Jeu::reinitialiser()
{
    attaques.A.status = Inactif;
    attaques.B.status = Inactif;
    attaques.C.status = Inactif;
    attaques.D.status = Inactif;
    attaques.E.status = Inactif;
    attaques.global_status = Inactif;
    attaques.status = false;

    killedStatus = false;

    gold.status = false;
    //joueur.position = sf::Vector2f(joueur.X_Initial, joueur.Y_Initial);
}

void Jeu::executer()
{
    while (fenetre.isOpen())
    {
        sound.musique1.play();
        ecranTitre.afficherEcranTitre(fenetre);
        sound.musique1.stop();
        sound.sound1.play();
        ecranTitre.demarrage(fenetre);
        sound.musique2.play();

        sf::Clock horloge;
        attaques.attaqueTimer.restart();
        gold.goldTimer.restart();
        map.generer();
        attaques.generer(map.T_LARGEUR, map.T_HAUTEUR);
        gold.generer(map.T_LARGEUR, map.T_HAUTEUR);
        joueur.position = sf::Vector2f((F_Largeur / 2) - ((map.TailleTuile * map.T_LARGEUR) / 2) + map.player_x + map.TailleTuile / 2,
                                        (F_Hauteur / 2) - ((map.TailleTuile * map.T_HAUTEUR) / 2) + map.player_y + map.TailleTuile / 2);

        while (fenetre.isOpen())
        {
            //std::cout << joueur.position.x << " , " << joueur.position.y << std::endl;
            sf::Time deltaTime = horloge.restart();
            traiterEvenements();
            mettreAJour(deltaTime);
            gold.gold_rng(this);
            attaques.attaques_rng(this);
            if(killedStatus == true)
            {
                sound.musique2.stop();
                sound.sound2.play();
                ecranTitre.killed(this);
                break;
            }
            dessiner();
        }
        reinitialiser();
    }
}

void Jeu::traiterEvenements()
{
    sf::Event evenement;
    while (fenetre.pollEvent(evenement))
    {
        if (evenement.type == sf::Event::Closed)
            fenetre.close();
    }
}

void Jeu::mettreAJour(sf::Time deltaTime)
{
    // Mise à jour de l'animation
    bool mouvement = false;

    // Détermination de la direction du déplacement
    float deplacementX = 0.0f;
    float deplacementY = 0.0f;

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && collision(1, deltaTime, joueur.vitesse))
    {
        float goodsize = static_cast<float>(joueur.TailleSprite) / static_cast<float>(joueur.frameWidth);
        joueur.sprite.setScale(-goodsize, goodsize); // Inverse horizontalement
        deplacementX -= 1.0f;
        mouvement = true;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && collision(2, deltaTime, joueur.vitesse))
    {
        float goodsize = static_cast<float>(joueur.TailleSprite) / static_cast<float>(joueur.frameWidth);
        joueur.sprite.setScale(goodsize, goodsize); // Inverse horizontalement
        deplacementX += 1.0f;
        mouvement = true;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && collision(3, deltaTime, joueur.vitesse))
    {
        deplacementY -= 1.0f;
        mouvement = true;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && collision(4, deltaTime, joueur.vitesse))
    {
        deplacementY += 1.0f;
        mouvement = true;
    }

    // Mise à jour de l'animation partie 2
    if (joueur.animationClock.getElapsedTime().asSeconds() > 0.1f && mouvement == false)
    { // 0.1s par frame, ajustez selon le besoin
        joueur.currentFrame = (joueur.currentFrame + 1) % joueur.framesJoueur.size();
        joueur.sprite.setTextureRect(joueur.framesJoueur[joueur.currentFrame]);
        joueur.animationClock.restart();
    }
    else if (joueur.animationClock.getElapsedTime().asSeconds() > 0.1f && mouvement == true)
    { // 0.1s par frame, ajustez selon le besoin
        joueur.currentFrame = (joueur.currentFrame + 1) % joueur.framesJoueur_2.size();
        joueur.sprite.setTextureRect(joueur.framesJoueur_2[joueur.currentFrame]);
        joueur.animationClock.restart();
    }
    if (gold.animationTimer.getElapsedTime().asSeconds() > 0.1f)
    { // 0.1s par frame, ajustez selon le besoin
        gold.currentFrame = (gold.currentFrame + 1) % gold.framesGold.size();
        gold.sprite.setTextureRect(gold.framesGold[gold.currentFrame]);
        gold.animationTimer.restart();
    }

    /*if (attaques.animationTimer.getElapsedTime().asSeconds() > 0.20f && attaques.currentFrame < static_cast<int>(attaques.framesImpact.size()) && attaques.global_status == Charge)
    { // 0.1s par frame, ajustez selon le besoin
        attaques.currentFrame++ ;
        attaques.sprite.setTextureRect(attaques.framesImpact[attaques.currentFrame]);
        attaques.animationTimer.restart();
    }
    else if (attaques.animationTimer.getElapsedTime().asSeconds() > 0.25f && attaques.currentFrame2 < static_cast<int>(attaques.framesImpact2.size()) && attaques.global_status == Actif)
    { // 0.1s par frame, ajustez selon le besoin
        attaques.currentFrame2++ ;
        attaques.sprite2.setTextureRect(attaques.framesImpact2[attaques.currentFrame2]);
        attaques.animationTimer.restart();
    }*/


    // Normalisation du vecteur de déplacement si nécessaire
    float magnitude = sqrt(deplacementX * deplacementX + deplacementY * deplacementY);
    if (magnitude > 0.0f) // Pour éviter la division par zéro
    {
        deplacementX /= magnitude;
        deplacementY /= magnitude;
    }

    // Application de la vitesse
    float vitesseActuelle;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        vitesseActuelle = joueur.vitesseAugmentee;
        // Son de déplacement
        if (sound.soundClock4.getElapsedTime().asSeconds() > 0.15f && mouvement == true)
        {
            sound.sound4.play();
            sound.soundClock4.restart();
        }
    }
    else
    {
        vitesseActuelle = joueur.vitesse;

        // Son de déplacement
        if (sound.soundClock4.getElapsedTime().asSeconds() > 0.3f && mouvement == true)
        {
            sound.sound4.play();
            sound.soundClock4.restart();
        }
    }


    joueur.position.x += deplacementX * vitesseActuelle * deltaTime.asSeconds();
    joueur.position.y += deplacementY * vitesseActuelle * deltaTime.asSeconds();
    // Mise à jour de la position du sprite du joueur
    joueur.sprite.setPosition(joueur.position);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) 
    {
        killedStatus = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
    {
        this->fenetre.close();
    }

}

bool Jeu::collision(int p, sf::Time deltaTime, float vitesseActuelle)
{
    int jpx = joueur.position.x - ((F_Largeur / 2) - ((map.T_LARGEUR * map.TailleTuile) / 2));
    int jpy = joueur.position.y - ((F_Hauteur / 2) - ((map.T_HAUTEUR * map.TailleTuile) / 2));
    if(p == 1)
        jpx -= vitesseActuelle * deltaTime.asSeconds();
    else if(p == 2)
        jpx += vitesseActuelle * deltaTime.asSeconds() + 1;
    else if(p == 3)
        jpy -= vitesseActuelle * deltaTime.asSeconds();
    else if(p == 4)
        jpy += vitesseActuelle * deltaTime.asSeconds() + 1;


    // Calcul du centre du joueur
    int rayon = joueur.TailleSprite / joueur.collision_div;

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
        int tileX = x / map.TailleTuile;
        int tileY = y / map.TailleTuile;
        // Vérification si le point est sur une tuile 'Gold'
        if (gold.grille[tileX][tileY] == true)
        {
            gold.getGold(tileX, tileY);
        }
        // Vérification si le point n'est pas sur une tuile 'Sol'
        if (map.grille[tileX][tileY] != Sol)
        {
            return false; // Collision détectée
        }
    }

    return true; // Aucune collision détectée
}

void Jeu::dessiner()
{
    fenetre.clear();
    fenetre.draw(ecranTitre.spriteEcranTitre);
    map.dessiner_bottom(fenetre, F_Hauteur, F_Largeur); // Dessiner la carte
    fenetre.draw(joueur.sprite); // Dessiner le joueur
    gold.afficherGold(this);
    attaques.dessiner_zone(this);
    map.dessiner_top(fenetre, F_Hauteur, F_Largeur); // Dessiner la carte

    /*if (attaques.A.status == Charge)
        fenetre.draw(attaques.A.sprite_A);
    else if (attaques.A.status == Actif)
        fenetre.draw(attaques.A.sprite_B);

    else if (attaques.B.status == Charge)
        fenetre.draw(attaques.B.sprite_A);
    else if (attaques.B.status == Actif)
        fenetre.draw(attaques.B.sprite_B);

    else if (attaques.C.status == Charge)
        fenetre.draw(attaques.C.sprite_A);
    else if (attaques.C.status == Actif)
        fenetre.draw(attaques.C.sprite_B);

    else if (attaques.D.status == Charge)
        fenetre.draw(attaques.D.sprite_A);
    else if (attaques.D.status == Actif)
        fenetre.draw(attaques.D.sprite_B);*/
    fenetre.display();
}