#include "Jeu.hpp"

void EcranTitre::afficherEcranTitre(sf::RenderWindow& fenetre)
{
    sf::Event evenement;
    while (fenetre.isOpen())
    {
        while (fenetre.pollEvent(evenement))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
            {
                fenetre.close();
            }
            if (evenement.type == sf::Event::KeyPressed)
            {
                return; // Quitte l'écran titre lorsque n'importe quelle touche est pressée
            }
            else if (evenement.type == sf::Event::Closed)
            {
                fenetre.close();
            }
        }

        fenetre.clear();
        fenetre.draw(spriteEcranTitre);
        fenetre.draw(spriteEldritch);
        fenetre.draw(texteTitre);
        fenetre.display();
    }
}

void EcranTitre::demarrage(sf::RenderWindow& fenetre)
{
    sf::Event evenement;
    sf::Clock timer;
    timer.restart();
    while (fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 1)
    {
        while (fenetre.pollEvent(evenement))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                fenetre.close();
        fenetre.clear();
        fenetre.draw(spriteEcranTitre);
        fenetre.draw(texteDemarrage3);
        fenetre.display();
    }
    timer.restart();
    while (fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 1)
    {
        while (fenetre.pollEvent(evenement))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                fenetre.close();
        fenetre.clear();
        fenetre.draw(spriteEcranTitre);
        fenetre.draw(texteDemarrage2);
        fenetre.display();
    }
    timer.restart();
    while (fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 1)
    {
        while (fenetre.pollEvent(evenement))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                fenetre.close();
        fenetre.clear();
        fenetre.draw(spriteEcranTitre);
        fenetre.draw(texteDemarrage1);
        fenetre.display();
    }
}

void EcranTitre::killed(Jeu *jeu)
{
    sf::Event evenement;
    sf::Clock timer;
    timer.restart();
    while (jeu->fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 3)
    {
        while (jeu->fenetre.pollEvent(evenement))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                jeu->fenetre.close();
        texteKilled.setString("Vous etes mort...\nScore : " + std::to_string(jeu->gold.GoldCount));
        float largeurTexte = texteKilled.getLocalBounds().width;
        float hauteurTexte = texteKilled.getLocalBounds().height;
        texteKilled.setPosition((jeu->F_Largeur / 2) - (largeurTexte / 2), (jeu->F_Hauteur / 2) - (hauteurTexte));
        jeu->fenetre.clear();
        jeu->fenetre.draw(spriteEcranTitre);
        jeu->fenetre.draw(texteKilled);
        jeu->fenetre.display();
    }
}