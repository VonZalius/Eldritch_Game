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
    }

    joueur.position = sf::Vector2f(joueur.X_Initial, joueur.Y_Initial); // Position initiale au milieu de l'écran
}

void Jeu::executer()
{
    sf::Clock horloge;

    while (fenetre.isOpen())
    {
        sf::Time deltaTime = horloge.restart();
        traiterEvenements();
        mettreAJour(deltaTime);
        dessiner();
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
    // Déplacement du joueur
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && collision(1, deltaTime))
    {
        joueur.position.x -= this->joueur.vitesse * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && collision(2, deltaTime))
    {
        joueur.position.x += this->joueur.vitesse * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && collision(3, deltaTime))
    {
        joueur.position.y -= this->joueur.vitesse * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && collision(4, deltaTime))
    {
        joueur.position.y += this->joueur.vitesse * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
    {
        this->fenetre.close();
    }

    // Mise à jour de la position du sprite du joueur
    joueur.sprite.setPosition(joueur.position);
}

bool Jeu::collision(int p, sf::Time deltaTime)
{
    int jpx = joueur.position.x - ((F_Largeur / 2) - ((map.T_LARGEUR * map.TailleTuile) / 2));
    int jpy = joueur.position.y - ((F_Hauteur / 2) - ((map.T_HAUTEUR * map.TailleTuile) / 2));
    if(p == 1)
        jpx -= this->joueur.vitesse * deltaTime.asSeconds();
    else if(p == 2)
        jpx += this->joueur.vitesse * deltaTime.asSeconds() + 1;
    else if(p == 3)
        jpy -= this->joueur.vitesse * deltaTime.asSeconds();
    else if(p == 4)
        jpy += this->joueur.vitesse * deltaTime.asSeconds() + 1;


    if (map.grille[jpx / map.TailleTuile][jpy / map.TailleTuile] == Mur ||
        map.grille[(jpx + joueur.TailleSprite) / map.TailleTuile][jpy / map.TailleTuile] == Mur ||
        map.grille[jpx / map.TailleTuile][(jpy + joueur.TailleSprite) / map.TailleTuile] == Mur ||
        map.grille[(jpx + joueur.TailleSprite) / map.TailleTuile][(jpy + joueur.TailleSprite) / map.TailleTuile] == Mur)
        return false;
    return true;
}

void Jeu::dessiner()
{
    fenetre.clear();
    map.dessiner(fenetre, F_Hauteur, F_Largeur); // Dessiner la carte
    fenetre.draw(joueur.sprite); // Dessiner le joueur
    fenetre.display();
}