#include "Jeu.hpp"

Jeu::Jeu() : fenetre(sf::VideoMode(F_Largeur, F_Hauteur), "Eldritch", sf::Style::None | sf::Style::Fullscreen)
{
    initialiserJeu();
}

void Jeu::initialiserJeu()
{
    srand(time(0));


    //SAUVEGARDE CHARGE
    std::ifstream fichierIn("data/Score.txt"); // Crée un objet ifstream et ouvre le fichier
    std::string ligne;

    if (fichierIn.is_open())
    {
        getline(fichierIn, ligne);
        TotalScore = atoi(ligne.c_str());
        getline(fichierIn, ligne);
        HighScore1 = atoi(ligne.c_str());
        getline(fichierIn, ligne);
        HighScore2 = atoi(ligne.c_str());
        getline(fichierIn, ligne);
        HighScore3 = atoi(ligne.c_str());
        getline(fichierIn, ligne);
        sprite_reminder = atoi(ligne.c_str());
        fichierIn.close(); // Ferme le fichier
    }
    if (sprite_reminder == 0)
        sprite_reminder_str = joueur.joueurSprite;
    if (sprite_reminder == 1)
        sprite_reminder_str = joueur.joueurSprite2;
    if (sprite_reminder == 2)
        sprite_reminder_str = joueur.joueurSprite3;
    if (sprite_reminder == 3)
        sprite_reminder_str = joueur.joueurSprite4;
    if (sprite_reminder == 4)
        sprite_reminder_str = joueur.joueurSprite5;
    if (sprite_reminder == 5)
        sprite_reminder_str = joueur.joueurSprite6;
    if (sprite_reminder == 6)
        sprite_reminder_str = joueur.joueurSprite7;
    if (sprite_reminder == 7)
        sprite_reminder_str = joueur.joueurSprite8;
    if (sprite_reminder == 8)
        sprite_reminder_str = joueur.joueurSprite9;
    if (sprite_reminder == 9)
        sprite_reminder_str = joueur.joueurSprite0;

    //JOUEUR
    if (joueur.textureJoueur.loadFromFile(sprite_reminder_str))
    {
        joueur.sprite.setTexture(joueur.textureJoueur);
        float goodsize = static_cast<float>(joueur.TailleSprite) / static_cast<float>(joueur.frameWidth);
        joueur.sprite.setScale(goodsize, goodsize);
        joueur.sprite.setOrigin(joueur.frameWidth / 2, (joueur.frameHeight / 2) + 6);

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
        sound.musique1.setVolume(sound.volume1);
    }

    if (sound.musique2.openFromFile(sound.musiqueFile2))
    {
        sound.musique2.setLoop(true);
        sound.musique2.setVolume(sound.volume2);
    }   

    if (sound.buffer1.loadFromFile(sound.SoundFile1))
    {
        sound.sound1.setBuffer(sound.buffer1);
        sound.sound1.setVolume(sound.soundVolume1);
    }

    if (sound.buffer2.loadFromFile(sound.SoundFile2))
    {
        sound.sound2.setBuffer(sound.buffer2);
        sound.sound2.setVolume(sound.soundVolume2);
    }

    if (sound.buffer3.loadFromFile(sound.SoundFile3))
    {
        sound.sound3.setBuffer(sound.buffer3);
        sound.sound3.setVolume(sound.soundVolume3);
    }

    if (sound.buffer4.loadFromFile(sound.SoundFile4))
    {
        sound.sound4.setBuffer(sound.buffer4);
        sound.sound4.setVolume(sound.soundVolume4);
    }

    if (sound.buffer5.loadFromFile(sound.SoundFile5))
    {
        sound.sound5.setBuffer(sound.buffer5);
        sound.sound5.setVolume(sound.soundVolume5);
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

    /*if (ecranTitre.font.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteTitre.setFont(ecranTitre.font); 
        ecranTitre.texteTitre.setString("Appuyez sur une touche pour commencer");
        ecranTitre.texteTitre.setCharacterSize(50); // en pixels
        ecranTitre.texteTitre.setFillColor(sf::Color::White);
        float largeurTexte = ecranTitre.texteTitre.getLocalBounds().width;
        ecranTitre.texteTitre.setPosition((F_Largeur / 2) - (largeurTexte / 2), 700); // Ajustez selon vos besoins
    }*/


    if (ecranTitre.fontVersion.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteVersion.setFont(ecranTitre.font); 
        ecranTitre.texteVersion.setString(ecranTitre.Version);
        ecranTitre.texteVersion.setCharacterSize(50); // en pixels
        ecranTitre.texteVersion.setFillColor(sf::Color::White);
        //float largeurTexte = ecranTitre.texteVersion.getLocalBounds().width;
        //float hauteurTexte = ecranTitre.texteVersion.getLocalBounds().height;
        ecranTitre.texteVersion.setPosition(50, F_Hauteur - 100); // Ajustez selon vos besoins
    }

    if (ecranTitre.fontDemarrage.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteDemarrage3.setFont(ecranTitre.fontDemarrage); 
        ecranTitre.texteDemarrage3.setString("3");
        ecranTitre.texteDemarrage3.setCharacterSize(100); // en pixels
        ecranTitre.texteDemarrage3.setFillColor(sf::Color::White);
        float largeurTexte = ecranTitre.texteDemarrage3.getLocalBounds().width;
        float hauteurTexte = ecranTitre.texteDemarrage3.getLocalBounds().height;
        ecranTitre.texteDemarrage3.setPosition((F_Largeur / 2) - (largeurTexte / 2), (F_Hauteur / 2) - (hauteurTexte));
    }
    if (ecranTitre.fontDemarrage.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteDemarrage2.setFont(ecranTitre.fontDemarrage); 
        ecranTitre.texteDemarrage2.setString("2");
        ecranTitre.texteDemarrage2.setCharacterSize(100); // en pixels
        ecranTitre.texteDemarrage2.setFillColor(sf::Color::White);
        float largeurTexte = ecranTitre.texteDemarrage2.getLocalBounds().width;
        float hauteurTexte = ecranTitre.texteDemarrage2.getLocalBounds().height;
        ecranTitre.texteDemarrage2.setPosition((F_Largeur / 2) - (largeurTexte / 2), (F_Hauteur / 2) - (hauteurTexte));
    }
    if (ecranTitre.fontDemarrage.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteDemarrage1.setFont(ecranTitre.fontDemarrage); 
        ecranTitre.texteDemarrage1.setString("1");
        ecranTitre.texteDemarrage1.setCharacterSize(100); // en pixels
        ecranTitre.texteDemarrage1.setFillColor(sf::Color::White);
        float largeurTexte = ecranTitre.texteDemarrage1.getLocalBounds().width;
        float hauteurTexte = ecranTitre.texteDemarrage1.getLocalBounds().height;
        ecranTitre.texteDemarrage1.setPosition((F_Largeur / 2) - (largeurTexte / 2), (F_Hauteur / 2) - (hauteurTexte));
    }
    if (ecranTitre.fontPaused.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.textePaused.setFont(ecranTitre.fontPaused); 
        ecranTitre.textePaused.setCharacterSize(100); // en pixels
        ecranTitre.textePaused.setFillColor(sf::Color::White);
    }
    if (ecranTitre.fontPaused2.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.textePaused2.setFont(ecranTitre.fontPaused2); 
        ecranTitre.textePaused2.setCharacterSize(100); // en pixels
        ecranTitre.textePaused2.setFillColor(sf::Color::White);
    }
    if (ecranTitre.fontKilled.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteKilled.setFont(ecranTitre.fontKilled); 
        ecranTitre.texteKilled.setCharacterSize(100); // en pixels
        ecranTitre.texteKilled.setFillColor(sf::Color::White);

        ecranTitre.texteKilled2.setFont(ecranTitre.fontKilled); 
        ecranTitre.texteKilled2.setCharacterSize(100); // en pixels
        ecranTitre.texteKilled2.setFillColor(sf::Color::White);
    }

    if (ecranTitre.fontScore.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteScore.setFont(ecranTitre.fontScore); 
        ecranTitre.texteScore.setString("Meilleur score :");
        ecranTitre.texteScore.setCharacterSize(70); // en pixels
        ecranTitre.texteScore.setFillColor(sf::Color::White);
        ecranTitre.texteScore.setPosition(50, 50);
    }

    if (ecranTitre.fontMap1.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteMap1.setFont(ecranTitre.fontMap1); 
        ecranTitre.texteMap1.setString("Sanctuaire");
        ecranTitre.texteMap1.setCharacterSize(120); // en pixels
        ecranTitre.texteMap1.setFillColor(sf::Color::White);
        ecranTitre.texteMap1.setPosition(50, 50);
    }
    if (ecranTitre.fontMap2.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteMap2.setFont(ecranTitre.fontMap2); 
        ecranTitre.texteMap2.setString("Ruines");
        ecranTitre.texteMap2.setCharacterSize(120); // en pixels
        ecranTitre.texteMap2.setFillColor(sf::Color::White);
        ecranTitre.texteMap2.setPosition(50, 50);
    }
    if (ecranTitre.fontMap3.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteMap3.setFont(ecranTitre.fontMap3); 
        ecranTitre.texteMap3.setString("Canal");
        ecranTitre.texteMap3.setCharacterSize(120); // en pixels
        ecranTitre.texteMap3.setFillColor(sf::Color::White);
        ecranTitre.texteMap3.setPosition(50, 50);
    }

    if (font_wtp.loadFromFile("sprites/police.ttf"))
    {
        texte_wtp.setFont(font_wtp); 
        texte_wtp.setString("Le jeu sera mis en pause a la fin de l'attaque.");
        texte_wtp.setCharacterSize(100); // en pixels
        texte_wtp.setFillColor(sf::Color::White);
        float largeurTexte = texte_wtp.getLocalBounds().width;
        float hauteurTexte = texte_wtp.getLocalBounds().height;
        texte_wtp.setPosition((F_Largeur / 2) - (largeurTexte / 2), (F_Hauteur) - (hauteurTexte * 2));
    }
}

void Jeu::reinitialiser()
{
    /*attaques.A.status = Inactif;
    attaques.B.status = Inactif;
    attaques.C.status = Inactif;
    attaques.D.status = Inactif;
    attaques.E.status = Inactif;*/
    //attaques.global_status = Inactif;
    attaques.status = false;

    killedStatus = false;
    gold.status = false;

    want_to_pause = false;
    //joueur.position = sf::Vector2f(joueur.X_Initial, joueur.Y_Initial);
}

void Jeu::executer()
{

    //Home
    if (sound.musique1.getStatus() != sf::SoundSource::Playing)
        sound.musique1.play();
    ecranTitre.afficherEcranTitre(this);
    sound.sound5.play();
    backStatus = false;
    while (fenetre.isOpen())
    {

        //HUb
        sf::Clock horloge;
        map.hub(this);
        attaques.generer(map.T_LARGEUR, map.T_HAUTEUR);
        gold.generer(map.T_LARGEUR, map.T_HAUTEUR);
        float goodsize = static_cast<float>(joueur.TailleSprite) / static_cast<float>(joueur.frameWidth);
        joueur.sprite.setScale(goodsize, goodsize);
        joueur.position = sf::Vector2f((F_Largeur / 2) - ((map.TailleTuile * map.T_LARGEUR) / 2) + map.player_x + map.TailleTuile / 2,
                                        (F_Hauteur / 2) - ((map.TailleTuile * map.T_HAUTEUR) / 2) + map.player_y + map.TailleTuile / 2);
        if (!ecranTitre.font.loadFromFile("sprites/police.ttf"))
            return;
        shop.btn_create(50, 600, 300, 100, 60, ecranTitre.font, "Personnages");
        while (fenetre.isOpen())
        {
            //std::cout << joueur.position.x << " , " << joueur.position.y << std::endl;
            sf::Time deltaTime = horloge.restart();
            traiterEvenements();
            mettreAJour_hub(deltaTime);
            if(killedStatus == true || backStatus == true)
                break;
            dessiner_hub();
        }
        reinitialiser();
        if(backStatus == true)
            break;

        //Transition
        sound.sound1.play();
        sound.musique1.stop();
        ecranTitre.demarrage(this);
        sound.musique2.play();

        //Jeu
        attaques.attaqueTimer.restart();
        map.generer(this);
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
            if(backStatus == true)
            {
                sound.musique2.stop();
                break;
            }
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
        if(backStatus == true)
            break;
        sound.musique1.play();
        sound.sound1.play();
    }
}

void Jeu::traiterEvenements()
{
    sf::Event evenement;
    while (fenetre.pollEvent(evenement))
    {
        if (evenement.type == sf::Event::Closed)
            fenetre.close();
        if (evenement.type == sf::Event::MouseButtonPressed)
        {
            if (evenement.mouseButton.button == sf::Mouse::Left)
            {
                if (shop.isMouseOver(fenetre))
                {             
                    sound.sound5.play();
                    ecranTitre.shop(this);
                }
            }
        }
    }
}

void Jeu::mettreAJour_hub(sf::Time deltaTime)
{
    // Mise à jour de l'animation
    bool mouvement = false;

    // Détermination de la direction du déplacement
    float deplacementX = 0.0f;
    float deplacementY = 0.0f;

    // Ajout de la prise en charge de la manette
    float joystickThreshold = 15.0f; // Seuil pour ignorer les faibles mouvements du joystick
    float joystickX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    float joystickY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

    // Déplacement gauche/droite avec le clavier ou le stick
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || joystickX < -joystickThreshold) && collision(1, deltaTime, joueur.vitesse))
    {
        float goodsize = static_cast<float>(joueur.TailleSprite) / static_cast<float>(joueur.frameWidth);
        joueur.sprite.setScale(-goodsize, goodsize); // Inverse horizontalement
        deplacementX -= 1.0f;
        mouvement = true;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || joystickX > joystickThreshold) && collision(2, deltaTime, joueur.vitesse))
    {
        float goodsize = static_cast<float>(joueur.TailleSprite) / static_cast<float>(joueur.frameWidth);
        joueur.sprite.setScale(goodsize, goodsize);
        deplacementX += 1.0f;
        mouvement = true;
    }

    // Déplacement haut/bas avec le clavier ou le stick
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || joystickY < -joystickThreshold) && collision(3, deltaTime, joueur.vitesse))
    {
        deplacementY -= 1.0f;
        mouvement = true;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || joystickY > joystickThreshold) && collision(4, deltaTime, joueur.vitesse))
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
    {
        ecranTitre.paused(this);
    }
}

void Jeu::mettreAJour(sf::Time deltaTime)
{
    // Mise à jour de l'animation
    bool mouvement = false;

    // Détermination de la direction du déplacement
    float deplacementX = 0.0f;
    float deplacementY = 0.0f;

    // Ajout de la prise en charge de la manette
    float joystickThreshold = 15.0f; // Seuil pour ignorer les faibles mouvements du joystick
    float joystickX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    float joystickY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

    // Déplacement gauche/droite avec le clavier ou le stick
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || joystickX < -joystickThreshold) && collision(1, deltaTime, joueur.vitesse))
    {
        float goodsize = static_cast<float>(joueur.TailleSprite) / static_cast<float>(joueur.frameWidth);
        joueur.sprite.setScale(-goodsize, goodsize); // Inverse horizontalement
        deplacementX -= 1.0f;
        mouvement = true;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || joystickX > joystickThreshold) && collision(2, deltaTime, joueur.vitesse))
    {
        float goodsize = static_cast<float>(joueur.TailleSprite) / static_cast<float>(joueur.frameWidth);
        joueur.sprite.setScale(goodsize, goodsize);
        deplacementX += 1.0f;
        mouvement = true;
    }

    // Déplacement haut/bas avec le clavier ou le stick
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || joystickY < -joystickThreshold) && collision(3, deltaTime, joueur.vitesse))
    {
        deplacementY -= 1.0f;
        mouvement = true;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || joystickY > joystickThreshold) && collision(4, deltaTime, joueur.vitesse))
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
        want_to_pause = true;
    }
    if(want_to_pause == true && attaques.status == false)
    {
        want_to_pause = false;
        ecranTitre.paused(this);
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
        {jpx + rayon, jpy + rayon}, 
        {jpx - rayon, jpy + rayon}, 
        {jpx + rayon, jpy - rayon}, 
        {jpx - rayon, jpy - rayon} 

        /*{static_cast<int>(jpx + rayon / sqrt(2)), static_cast<int>(jpy + rayon / sqrt(2))}, // Bas-droite
        {static_cast<int>(jpx - rayon / sqrt(2)), static_cast<int>(jpy + rayon / sqrt(2))}, // Bas-gauche
        {static_cast<int>(jpx + rayon / sqrt(2)), static_cast<int>(jpy - rayon / sqrt(2))}, // Haut-droite
        {static_cast<int>(jpx - rayon / sqrt(2)), static_cast<int>(jpy - rayon / sqrt(2))}  // Haut-gauche*/
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
        if (map.grille[tileX][tileY] == MP1)
        {
            map.map_select = 0;
            killedStatus = true;
        }
        if (map.grille[tileX][tileY] == MP2)
        {
            map.map_select = 1;
            killedStatus = true;
        }
        if (map.grille[tileX][tileY] == MP3)
        {
            map.map_select = 2;
            killedStatus = true;
        }
        // Vérification si le point n'est pas sur une tuile 'Sol'
        if (map.is_Sol.find(map.grille[tileX][tileY]) == map.is_Sol.end())
        {
            return false; // Collision détectée
        }
    }

    return true; // Aucune collision détectée
}

void Jeu::dessiner_hub()
{
    fenetre.clear();

    fenetre.draw(ecranTitre.spriteEcranTitre);
    map.dessiner_bottom(fenetre, F_Hauteur, F_Largeur); // Dessiner la carte
    map.dessiner_top(this); // Dessiner la carte
    //fenetre.draw(gold.texteCount);
    ecranTitre.texteScore.setString("Meilleurs scores\n\nSanctuaire : " + std::to_string(HighScore1) + "\nRuines : "  + std::to_string(HighScore2) + "\nCanal : "  + std::to_string(HighScore3));
    fenetre.draw(ecranTitre.texteScore);
    shop.drawTo(fenetre);

    fenetre.display();
}

void Jeu::dessiner()
{
    fenetre.clear();

    fenetre.draw(ecranTitre.spriteEcranTitre);
    map.dessiner_bottom(fenetre, F_Hauteur, F_Largeur); // Dessiner la carte
    map.dessiner_top(this); // Dessiner la carte

    gold.texteCount.setString(std::to_string(gold.GoldCount));
    fenetre.draw(gold.texteCount);
    if(map.map_select == 0)
        fenetre.draw(ecranTitre.texteMap1);
    else if(map.map_select == 1)
        fenetre.draw(ecranTitre.texteMap2);
    else if(map.map_select == 2)
        fenetre.draw(ecranTitre.texteMap3);

    if(want_to_pause == true)
        fenetre.draw(texte_wtp);

    fenetre.display();
}