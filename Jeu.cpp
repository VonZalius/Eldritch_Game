#include "Jeu.hpp"

Jeu::Jeu() : fenetre(sf::VideoMode(F_Largeur, F_Hauteur), "Titre du Jeu")
{
    initialiserJeu();
}

void Jeu::initialiserJeu()
{
    if (textureJoueur.loadFromFile("sprites/joueur.png"))
    {
        joueur.sprite.setTexture(textureJoueur);
        joueur.position = sf::Vector2f(joueur.X_Initial - (joueur.TailleSprite / 2), joueur.Y_Initial - (joueur.TailleSprite / 2)); // Position initiale au milieu de l'écran
    }


    if (ecranTitre.textureEcranTitre.loadFromFile("sprites/Titre.png"))
    {
        ecranTitre.spriteEcranTitre.setTexture(ecranTitre.textureEcranTitre);  
    }

    if (ecranTitre.font.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteTitre.setFont(ecranTitre.font); 
        ecranTitre.texteTitre.setString("Appuyez sur une touche pour commencer");
        ecranTitre.texteTitre.setCharacterSize(20); // en pixels
        ecranTitre.texteTitre.setFillColor(sf::Color::White);
        ecranTitre.texteTitre.setPosition(50, 50); // Ajustez selon vos besoins
    }

    if (ecranTitre.fontDemarrage.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteDemarrage3.setFont(ecranTitre.fontDemarrage); 
        ecranTitre.texteDemarrage3.setString("3...");
        ecranTitre.texteDemarrage3.setCharacterSize(100); // en pixels
        ecranTitre.texteDemarrage3.setFillColor(sf::Color::White);
        ecranTitre.texteDemarrage3.setPosition(50, 50); // Ajustez selon vos besoins
    }
    if (ecranTitre.fontDemarrage.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteDemarrage2.setFont(ecranTitre.fontDemarrage); 
        ecranTitre.texteDemarrage2.setString("2...");
        ecranTitre.texteDemarrage2.setCharacterSize(100); // en pixels
        ecranTitre.texteDemarrage2.setFillColor(sf::Color::Yellow);
        ecranTitre.texteDemarrage2.setPosition(50, 50); // Ajustez selon vos besoins
    }
    if (ecranTitre.fontDemarrage.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteDemarrage1.setFont(ecranTitre.fontDemarrage); 
        ecranTitre.texteDemarrage1.setString("1...");
        ecranTitre.texteDemarrage1.setCharacterSize(100); // en pixels
        ecranTitre.texteDemarrage1.setFillColor(sf::Color::Red);
        ecranTitre.texteDemarrage1.setPosition(50, 50); // Ajustez selon vos besoins
    }
    if (ecranTitre.fontKilled.loadFromFile("sprites/police.ttf"))
    {
        ecranTitre.texteKilled.setFont(ecranTitre.fontKilled); 
        ecranTitre.texteKilled.setString("Vous etes mort...\nFin de partie !");
        ecranTitre.texteKilled.setCharacterSize(30); // en pixels
        ecranTitre.texteKilled.setFillColor(sf::Color::Red);
        ecranTitre.texteKilled.setPosition(50, 50); // Ajustez selon vos besoins
    }
}

void Jeu::reinitialiser()
{
    attaques.A.status = Inactif;
    killedStatus = false;
    joueur.position = sf::Vector2f(joueur.X_Initial, joueur.Y_Initial);
}

void Jeu::executer()
{
    while (fenetre.isOpen())
    {
        ecranTitre.afficherEcranTitre(fenetre);
        ecranTitre.demarrage(fenetre);

        sf::Clock horloge;
        attaques.attaqueTimer.restart();

        while (fenetre.isOpen())
        {
            sf::Time deltaTime = horloge.restart();
            traiterEvenements();
            mettreAJour(deltaTime);
            attaques.attaques_rng(this);
            if(killedStatus == true)
            {
                ecranTitre.killed(fenetre);
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
    // Détermination de la direction du déplacement
    float deplacementX = 0.0f;
    float deplacementY = 0.0f;

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && collision(1, deltaTime, joueur.vitesse))
    {
        deplacementX -= 1.0f;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && collision(2, deltaTime, joueur.vitesse))
    {
        deplacementX += 1.0f;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && collision(3, deltaTime, joueur.vitesse))
    {
        deplacementY -= 1.0f;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && collision(4, deltaTime, joueur.vitesse))
    {
        deplacementY += 1.0f;
    }

    // Normalisation du vecteur de déplacement si nécessaire
    float magnitude = sqrt(deplacementX * deplacementX + deplacementY * deplacementY);
    if (magnitude > 0.0f) // Pour éviter la division par zéro
    {
        deplacementX /= magnitude;
        deplacementY /= magnitude;
    }

    // Application de la vitesse
    float vitesseActuelle = sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ? joueur.vitesseAugmentee : joueur.vitesse;
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


    if (map.grille[jpx / map.TailleTuile][jpy / map.TailleTuile] == Mur ||
        map.grille[(jpx + joueur.TailleSprite - 1) / map.TailleTuile][jpy / map.TailleTuile] == Mur ||
        map.grille[jpx / map.TailleTuile][(jpy + joueur.TailleSprite - 1) / map.TailleTuile] == Mur ||
        map.grille[(jpx + joueur.TailleSprite - 1) / map.TailleTuile][(jpy + joueur.TailleSprite - 1) / map.TailleTuile] == Mur)
        return false;
    return true;
}

void Jeu::dessiner()
{
    fenetre.clear();
    fenetre.draw(ecranTitre.spriteEcranTitre);
    map.dessiner(fenetre, F_Hauteur, F_Largeur); // Dessiner la carte
    fenetre.draw(joueur.sprite); // Dessiner le joueur

    if (attaques.A.status == Charge)
        fenetre.draw(attaques.A.sprite_A);
    else if (attaques.A.status == Actif)
        fenetre.draw(attaques.A.sprite_B);

    fenetre.display();
}