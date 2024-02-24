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
    map.dessiner(fenetre, F_Hauteur, F_Largeur); // Dessiner la carte
    fenetre.draw(joueur.sprite); // Dessiner le joueur
    fenetre.display();
}